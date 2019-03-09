#include "map_info.hpp"

class MapInfos
{
public:
                                           MapInfos(const Hash& hash);

    MapInfo&                               operator[](i32 key);
    const MapInfo&                         operator[](i32 key) const;

    std::map<i32, MapInfo>::iterator       begin();
    std::map<i32, MapInfo>::const_iterator begin() const;

    std::map<i32, MapInfo>::iterator       end();
    std::map<i32, MapInfo>::const_iterator end() const;

    bool                                   operator==(const MapInfos& other) const;
    bool                                   operator!=(const MapInfos& other) const;
    bool                                   operator<(const MapInfos& other) const;

    size_t                                 size() const;

private:
    std::map<i32, MapInfo> mMapInfos;
};