#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{ sf::VideoMode{640, 480}, "Engine" };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}