#pragma once

#pragma warning(disable: 4996)

#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <json/json.hpp>
using json = nlohmann::json;

#define JSON_SET(name) {#name, o.m##name}
#define JSON_GET(name) j.at(#name).get_to(o.m##name)

#include <algorithm>
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
void writeStringToFile(const std::string& filename, const std::string& str);