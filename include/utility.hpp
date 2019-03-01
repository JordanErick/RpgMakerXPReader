#pragma once

#pragma warning(disable: 4996)

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include <algorithm>
#include <conio.h>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

struct Table
{
    i32                 dimensions;
    i32                 xLength;
    i32                 yLength;
    i32                 zLength;
    i32                 indices;
    std::vector<i16>    data;
};

const std::string DataPath = "Data/";

const std::string ActorsPath       = DataPath + "Actors.rxdata";
const std::string AnimationsPath   = DataPath + "Animations.rxdata";
const std::string ArmorsPath       = DataPath + "Armors.rxdata";
const std::string ClassesPath      = DataPath + "Classes.rxdata";
const std::string CommonEventsPath = DataPath + "CommonEvents.rxdata";
const std::string EnemiesPath      = DataPath + "Enemies.rxdata";
const std::string ItemsPath        = DataPath + "Items.rxdata";
const std::string Map001Path       = DataPath + "Map001.rxdata";
const std::string Map002Path       = DataPath + "Map002.rxdata";
const std::string MapInfosPath     = DataPath + "MapInfos.rxdata";
const std::string ScriptsPath      = DataPath + "Scripts.rxdata";
const std::string SkillsPath       = DataPath + "Skills.rxdata";
const std::string StatesPath       = DataPath + "States.rxdata";
const std::string SystemPath       = DataPath + "System.rxdata";
const std::string TilesetsPath     = DataPath + "Tilesets.rxdata";
const std::string TroopsPath       = DataPath + "Troops.rxdata";
const std::string WeaponsPath      = DataPath + "Weapons.rxdata";

std::vector<u8> loadFileIntoMemory(const std::string& filename);
std::vector<std::string> split(const std::string& str, char delimiter);
bool startsWith(const std::string& str, const std::string& substr);