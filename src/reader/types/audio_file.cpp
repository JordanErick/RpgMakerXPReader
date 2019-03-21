#include "reader/types/audio_file.hpp"

rpg::AudioFile::AudioFile(const Object& object)
{
    load(object);
}

void rpg::AudioFile::load(const Object& object)
{
    if (object.className() != "RPG::AudioFile")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mName = *object["@name"].as<std::string>();
    mPitch = static_cast<float>(*object["@pitch"].as<i32>());
    mVolume = static_cast<float>(*object["@volume"].as<i32>());
}

void rpg::to_json(json& j, const AudioFile& o)
{
    j = json{
        JSON_SET(Name),
        JSON_SET(Pitch),
        JSON_SET(Volume)
    };
}

void rpg::from_json(const json& j, AudioFile& o)
{
    JSON_GET(Name);
    JSON_GET(Pitch);
    JSON_GET(Volume);
}