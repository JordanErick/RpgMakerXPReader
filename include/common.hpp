#pragma once

#include "any.hpp"
#include "object.hpp"

class AudioFile
{
public:
                       AudioFile();
                       AudioFile(const Any* any);
    void               fromAny(const Any* any);

    const std::string& name() const;
    float              pitch() const;
    float              volume() const;
private:
    std::string        mName;
    float              mPitch;
    float              mVolume;
};