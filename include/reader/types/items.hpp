#include "item.hpp"

class Items
{
public:
                                      Items();
                                      Items(const Array& array);

    Item&                             operator[](size_t index);
    const Item&                       operator[](size_t index) const;

    std::vector<Item>::iterator       begin();
    std::vector<Item>::const_iterator begin() const;

    std::vector<Item>::iterator       end();
    std::vector<Item>::const_iterator end() const;

    bool                              operator==(const Items& other) const;
    bool                              operator!=(const Items& other) const;
    bool                              operator<(const Items& other) const;

    size_t                            size() const;
private:
    std::vector<Item>                 mItems;

    friend void                       to_json(json& j, const Items& o);
    friend void                       from_json(const json& j, Items& o);
};

void to_json(json& j, const Items& o);
void from_json(const json& j, Items& o);