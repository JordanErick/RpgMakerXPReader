#include "types/state.hpp"

class States
{
public:
    States();
    States(const Array& array);

    State&                             operator[](size_t index);
    const State&                       operator[](size_t index) const;

    std::vector<State>::iterator       begin();
    std::vector<State>::const_iterator begin() const;

    std::vector<State>::iterator       end();
    std::vector<State>::const_iterator end() const;

    bool                               operator==(const States& other) const;
    bool                               operator!=(const States& other) const;
    bool                               operator<(const States& other) const;

    size_t                             size() const;
private:
    std::vector<State>                 mStates;

    friend void                        to_json(json& j, const States& o);
    friend void                        from_json(const json& j, States& o);
};

void to_json(json& j, const States& o);
void from_json(const json& j, States& o);