#include "types/common.hpp"

AudioFile::AudioFile()
: mName{ "" }
, mPitch{ 100.f }
, mVolume{ 100.f }
{
}

AudioFile::AudioFile(const Object& object)
: mName{ "" }
, mPitch{ 100.f }
, mVolume{ 100.f }
{
    load(object);
}

void AudioFile::load(const Object& object)
{
    if (object.className() != "RPG::AudioFile")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mName = *object["@name"].as<std::string>();
    mPitch = static_cast<float>(*object["@pitch"].as<i32>());
    mVolume = static_cast<float>(*object["@volume"].as<i32>());
}

const std::string& AudioFile::name() const
{
    return mName;
}

float AudioFile::pitch() const
{
    return mPitch;
}

float AudioFile::volume() const
{
    return mVolume;
}

void to_json(json& j, const AudioFile& o)
{
    j = json{ {"name", o.mName}, {"pitch", o.mPitch}, {"volume", o.mVolume} };
}

void from_json(const json& j, AudioFile& o)
{
    j.at("name").get_to(o.mName);
    j.at("pitch").get_to(o.mPitch);
    j.at("volume").get_to(o.mVolume);
}