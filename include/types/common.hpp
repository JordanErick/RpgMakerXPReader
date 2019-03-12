#pragma once

#include <json/json.hpp>
using json = nlohmann::json;

#define JSON_SET(name) {#name, o.m##name}
#define JSON_GET(name) j.at(#name).get_to(o.m##name)

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

    friend void        to_json(json& j, const AudioFile& o);
    friend void        from_json(const json& j, AudioFile& o);
};

void to_json(json& j, const AudioFile& o);
void from_json(const json& j, AudioFile& o);