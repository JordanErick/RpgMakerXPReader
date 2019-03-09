#include "types/item.hpp"

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
};