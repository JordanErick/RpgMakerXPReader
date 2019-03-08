#pragma once

#include "any.hpp"
#include "object.hpp"

class AudioFile
{
public:
                       AudioFile();
                       AudioFile(const Object& object);
    void               load(const Object& object);

    const std::string& name() const;
    float              pitch() const;
    float              volume() const;
private:
    std::string        mName;
    float              mPitch;
    float              mVolume;
};