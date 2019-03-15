#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <reader/types.hpp>

#include <SFML/Graphics.hpp>

sf::Image expandAutotile(const sf::Image& autotile)
{
    sf::Image result;
    result.create(8 * 32, 6 * 32);

    int x = 0;
    int y = 0;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0,  y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 5 * 16}, {16, 16} }); // w
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x = 0;
    y += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 5 * 16}, {16, 16} }); // x

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 4 * 16}, {16, 16} }); // r
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 4 * 16}, {16, 16} }); // q
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x = 0;
    y += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {0 * 16, 4 * 16}, {16, 16} }); // o
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {1 * 16, 4 * 16}, {16, 16} }); // p
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {0 * 16, 5 * 16}, {16, 16} }); // u
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {1 * 16, 5 * 16}, {16, 16} }); // v

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {0 * 16, 4 * 16}, {16, 16} }); // o
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {0 * 16, 5 * 16}, {16, 16} }); // u
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {1 * 16, 5 * 16}, {16, 16} }); // v

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {0 * 16, 4 * 16}, {16, 16} }); // o
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {1 * 16, 4 * 16}, {16, 16} }); // p
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {0 * 16, 5 * 16}, {16, 16} }); // u
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {0 * 16, 4 * 16}, {16, 16} }); // o
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 0 * 16}, {16, 16} }); // 5
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {0 * 16, 5 * 16}, {16, 16} }); // u
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 2 * 16}, {16, 16} }); // e
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 2 * 16}, {16, 16} }); // f
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 3 * 16}, {16, 16} }); // k
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 3 * 16}, {16, 16} }); // l

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 2 * 16}, {16, 16} }); // e
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 2 * 16}, {16, 16} }); // f
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {2 * 16, 3 * 16}, {16, 16} }); // k
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 2 * 16}, {16, 16} }); // e
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 2 * 16}, {16, 16} }); // f
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {3 * 16, 3 * 16}, {16, 16} }); // l

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {2 * 16, 2 * 16}, {16, 16} }); // e
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {3 * 16, 2 * 16}, {16, 16} }); // f
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 1 * 16}, {16, 16} }); // b

    x = 0;
    y += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 4 * 16}, {16, 16} }); // s
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 4 * 16}, {16, 16} }); // t
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 5 * 16}, {16, 16} }); // y
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 5 * 16}, {16, 16} }); // z

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 4 * 16}, {16, 16} }); // s
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 4 * 16}, {16, 16} }); // t
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 5 * 16}, {16, 16} }); // z

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 4 * 16}, {16, 16} }); // t
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 5 * 16}, {16, 16} }); // y
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 5 * 16}, {16, 16} }); // z

    x += 32;

    result.copy(autotile, x + 0, y + 0, sf::IntRect{ {4 * 16, 0 * 16}, {16, 16} }); // 4
    result.copy(autotile, x + 16, y + 0, sf::IntRect{ {5 * 16, 4 * 16}, {16, 16} }); // t
    result.copy(autotile, x + 0, y + 16, sf::IntRect{ {4 * 16, 1 * 16}, {16, 16} }); // a
    result.copy(autotile, x + 16, y + 16, sf::IntRect{ {5 * 16, 5 * 16}, {16, 16} }); // z

    return result;
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{640, 480}, "Engine" };

    sf::Image autotile;
    if (!autotile.loadFromFile("resources/graphics/autotile.png"))
        throw std::runtime_error("Unable to find resource");

    auto expandedAutotile = expandAutotile(autotile);

    sf::Texture texture;
    if (!texture.loadFromImage(expandedAutotile))
        throw std::runtime_error("Unable to load texture from image");

    sf::Sprite sprite{ texture };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}