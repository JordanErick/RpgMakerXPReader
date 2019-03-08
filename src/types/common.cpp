#include "types/common.hpp"

AudioFile::AudioFile()
: mName{ "" }
, mPitch{ 100.f }
, mVolume{ 100.f }
{
}

AudioFile::AudioFile(const Any* any)
: mName{ "" }
, mPitch{ 100.f }
, mVolume{ 100.f }
{
    fromAny(any);
}

void AudioFile::fromAny(const Any* any)
{
    if (any->type() != Type::Object)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    if (any->as<Object>()->className() != "RPG::AudioFile")
        throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

    auto* object = any->as<Object>();

    mName = *(*object)["@name"].as<std::string>();
    mPitch = static_cast<float>(*(*object)["@pitch"].as<i32>());
    mVolume = static_cast<float>(*(*object)["@volume"].as<i32>());
}

const std::string & AudioFile::name() const
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