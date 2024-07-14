#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "LocalPlayer.hpp"
#include "Offsets.hpp"
#include "Camera.hpp"
#include "GlowMode.hpp"

#include "DMALibrary/Memory/Memory.h"
#include <array>

struct Sense {
// Variables
Camera* GameCamera;
LocalPlayer* Myself;
std::vector<Player*>* Players;
int TotalSpectators = 0;
std::vector<std::string> Spectators;
uint64_t HighlightSettingsPointer;

bool ItemGlow = false;
// 15 = gold
// 46 = Purple,
// 53 = Blue
// 57 = ammo
// 64 = white (attachments/grenades)
int MinimumItemRarity = 35;

//Colors
float InvisibleGlowColor[3] = { 0, 1, 0 };
float VisibleGlowColor[3] = { 1, 0, 0 };
std::array<float, 3> highlightGlowColorRGB = { 0, 1, 0 };

Sense(std::vector<Player*>* Players, Camera* GameCamera, LocalPlayer* Myself) {
this->Players = Players;
this->GameCamera = GameCamera;
this->Myself = Myself;
}

void Initialize() {
// idk, nothing for now
}

void setCustomGlow(Player* Target, int enable, int wall, bool isVisible)
{
if (Target->GlowEnable == 0 && Target->GlowThroughWall == 0 && Target->HighlightID == 0) {
return;
}
uint64_t basePointer = Target->BasePointer;

std::array<unsigned char, 4> highlightFunctionBits = {
2, // InsideFunction
125, // OutlineFunction: HIGHLIGHT_OUTLINE_OBJECTIVE
64, // OutlineRadius: size * 255 / 8
64 // (EntityVisible << 6) | State & 0x3F | (AfterPostProcess << 7)
};

int settingIndex = 65;
int health = Target->Health;
std::array<float, 3> glowColorRGB = { 0, 0, 0 };
if (!isVisible) {
settingIndex = 65;
glowColorRGB = { 0.5, 0.5, 0.5 }; // grey
highlightGlowColorRGB = { 0.5, 0.5, 0.5 };
}
else if (health >= 205) {
settingIndex = 66;
glowColorRGB = { 1, 0, 0 }; // red shield
highlightGlowColorRGB = { 1, 0, 0 };
}
else if (health >= 190) {
settingIndex = 67;
glowColorRGB = { 0.5, 0, 0.5 }; // purple shield
highlightGlowColorRGB = { 0.5, 0, 0.5 };
}
else if (health >= 170) {
settingIndex = 68;
glowColorRGB = { 0, 0.5, 1 }; // blue shield
highlightGlowColorRGB = { 0, 0.5, 1 };
}
else if (health >= 95) {
settingIndex = 69;
glowColorRGB = { 0, 1, 0.5 }; // gray shield // cyan color
highlightGlowColorRGB = { 0, 1, 0.5 };
}
else {
settingIndex = 70;
glowColorRGB = { 0, 1, 0 }; // low health enemies // green color
highlightGlowColorRGB = { 0, 1, 0 };
}

if (Target->GlowEnable != enable) {
uint64_t glowEnableAddress = basePointer + OFF_GLOW_ENABLE;
mem.Write<int>(glowEnableAddress, enable);
}

if (Target->GlowThroughWall != wall) {
uint64_t glowThroughWallAddress = basePointer + OFF_GLOW_THROUGH_WALL;
mem.Write<int>(glowThroughWallAddress, wall);
}

uint64_t highlightIdAddress = basePointer + OFF_GLOW_HIGHLIGHT_ID;
unsigned char value = settingIndex;
mem.Write<unsigned char>(highlightIdAddress, value);

uint64_t highlightSettingsPtr = HighlightSettingsPointer;
if (mem.IsValidPointer(highlightSettingsPtr)) {
auto handle = mem.CreateScatterHandle();

// HIGHLIGHT
mem.AddScatterWriteRequest(handle, highlightSettingsPtr + OFF_GLOW_HIGHLIGHT_TYPE_SIZE * settingIndex + 0x0, &highlightFunctionBits, sizeof(highlightFunctionBits));
mem.AddScatterWriteRequest(handle, highlightSettingsPtr + OFF_GLOW_HIGHLIGHT_TYPE_SIZE * settingIndex + 0x4, &highlightGlowColorRGB, sizeof(highlightGlowColorRGB));

mem.ExecuteWriteScatter(handle);
mem.CloseScatterHandle(handle);
}

uint64_t glowFixAddress = basePointer + OFF_GLOW_FIX;
mem.Write<int>(glowFixAddress, 0);
}

Vector2D DummyVector = { 0, 0 };
void Update() {
//if (Myself->IsDead) return;

if (ItemGlow) {
uint64_t highlightSettingsPtr = HighlightSettingsPointer;
if (mem.IsValidPointer(highlightSettingsPtr)) {
uint64_t highlightSize = OFF_GLOW_HIGHLIGHT_TYPE_SIZE;
const GlowMode newGlowMode = { 137, 138, 35, 127 };
//for (int highlightId = MinimumItemRarity; highlightId < 100; highlightId++)
for (int highlightId = 15; highlightId < 64; highlightId++)
{
const GlowMode oldGlowMode = mem.Read<GlowMode>(highlightSettingsPtr + (highlightSize * highlightId) + 0, true);
if (newGlowMode != oldGlowMode) {
mem.Write<GlowMode>(highlightSettingsPtr + (highlightSize * highlightId) + 0, newGlowMode);
}
}
}
}

for (int i = 0; i < Players->size(); i++) {
Player* Target = Players->at(i);
if (!Target->IsValid()) continue;
if (Target->IsDummy()) continue;
if (Target->IsLocal) continue;
if (!Target->IsHostile) continue;

if (GameCamera->WorldToScreen(Target->LocalOrigin.ModifyZ(30), DummyVector)) {
setCustomGlow(Target, 1, 1, Target->IsVisible);
}
}
}
};
