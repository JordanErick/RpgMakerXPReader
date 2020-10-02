#include "reader/types/enemies.hpp"

rpg::Enemies::Enemies()
: mEnemies{}
{
}

rpg::Enemies::Enemies(const Array& array)
: mEnemies{}
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Enemy")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mEnemies.push_back(Enemy{ *element.as<Object>() });
    }
}

rpg::Enemy& rpg::Enemies::operator[](size_t index)
{
    return mEnemies[index];
}

const rpg::Enemy& rpg::Enemies::operator[](size_t index) const
{
    return mEnemies.at(index);
}

std::vector<rpg::Enemy>::iterator rpg::Enemies::begin()
{
    return mEnemies.begin();
}

std::vector<rpg::Enemy>::const_iterator rpg::Enemies::begin() const
{
    return mEnemies.begin();
}

std::vector<rpg::Enemy>::iterator rpg::Enemies::end()
{
    return mEnemies.end();
}

std::vector<rpg::Enemy>::const_iterator rpg::Enemies::end() const
{
    return mEnemies.end();
}

bool rpg::Enemies::operator==(const Enemies& other) const
{
    return mEnemies == other.mEnemies;
}

bool rpg::Enemies::operator!=(const Enemies& other) const
{
    return !operator==(other);
}

bool rpg::Enemies::operator<(const Enemies& other) const
{
    return mEnemies < other.mEnemies;
}

size_t rpg::Enemies::size() const
{
    return mEnemies.size();
}

void rpg::to_json(json& j, const Enemies& o)
{
    j = json{ JSON_SET(Enemies) };
}

void rpg::from_json(const json& j, Enemies& o)
{
    JSON_GET(Enemies);
}
