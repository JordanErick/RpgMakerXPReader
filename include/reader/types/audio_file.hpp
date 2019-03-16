#pragma once

#include "../object.hpp"

namespace rpg
{
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
}