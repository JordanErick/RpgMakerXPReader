#pragma once

#pragma warning(disable: 4996)

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include <algorithm>
#include <conio.h>
#include <cstdint>
#include <cstdio>
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

std::vector<u8> loadFileIntoMemory(const std::string& filename);