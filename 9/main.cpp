#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

using namespace std::chrono_literals;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lab_9");

    sf::CircleShape circle(100);
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    sf::CircleShape triangle(60, 3);

    int shape_y = 1000;

    circle.setPosition(100, shape_y);
    circle.setOrigin(0, 0);

    rectangle.setPosition(400, shape_y);
    rectangle.setOrigin(0, 0);

    triangle.setPosition(800, shape_y);
    triangle.setOrigin(0, 0);

    circle.setFillColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::Yellow);
    triangle.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape_y--;
        if (shape_y > 0)
        {
            shape_y = shape_y - 2;
            if (shape_y < 0)
                shape_y = 0;
            circle.setPosition(100, shape_y);
            triangle.setPosition(800, shape_y);
            rectangle.setPosition(400, shape_y);

        }


        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.display();

        std::this_thread::sleep_for(10ms);
    }

    return 0;
}