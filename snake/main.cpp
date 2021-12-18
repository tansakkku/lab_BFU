#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

//Размеры поля и разрешение текстуры
int shirina = 30, visota = 30;
int til = 25;

//начало движения можно менять и длину змеии на старте тоже.
int dir = 0, dlina_snake = 4;

bool game = true;

struct Snake {
    int x, y;
} s[900]; //Окончательная длина зависит от размеров поля(s[shirina * visota])

struct Money
{
    int x, y;
} f;

void Tick() {
    for (int i = dlina_snake; i > 0; i--) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0)
        s[0].y += 1;
    if (dir == 1)
        s[0].x -= 1;
    if (dir == 2)
        s[0].x += 1;
    if (dir == 3)
        s[0].y -= 1;

    if (s[0].x > shirina)
        s[0].x = 0;
    if (s[0].x < 0)
        s[0].x = shirina;
    if (s[0].y > visota)
        s[0].y = 0;
    if (s[0].y < 0)
        s[0].y = visota;

    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        dlina_snake++;

        f.x = rand() % shirina;
        f.y = rand() % visota;
    }

    for (int i = 1; i < dlina_snake; i++)
        if ((s[0].x == s[i].x) && (s[0].y == s[i].y))
            game = false;
}

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(til * shirina, til * visota), "Spider-Snake!");

    sf::Texture texture;
    if (!texture.loadFromFile("img/tiles.png"))
    {
        std::cout << "ERROR when loading tiles.png" << std::endl;
        return false;
    }
    sf::Sprite back;
    back.setTexture(texture);

   
    sf::Texture sn;
    if (!sn.loadFromFile("img/snake.png"))
    {
        std::cout << "ERROR when loading snake.png" << std::endl;
        return false;
    }
    sf::Sprite snake;
    snake.setTexture(sn);

    sf::Texture mo;
    if (!mo.loadFromFile("img/money.png"))
    {
        std::cout << "ERROR when loading money.png" << std::endl;
        return false;
    }
    sf::Sprite money;
    money.setTexture(mo);

    sf::Texture go;
    if (!go.loadFromFile("img/gameover.png"))
    {
        std::cout << "ERROR when loading gameover.png" << std::endl;
        return false;
    }
    sf::Sprite gameover;
    gameover.setTexture(go);

    f.x = 10;
    f.y = 10;

    sf::Image icon;
    if (!icon.loadFromFile("img/s32.png"))
    {
        return -1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());


    
    Clock clock;
    float timer = 0, delay = 0.2; //скорость змейки

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            dir = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            dir = 2;
        if (Keyboard::isKeyPressed(Keyboard::Up))
            dir = 3;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            dir = 0;

        if (timer > delay && game) {
            timer = 0;
            Tick();
        }

        window.clear();


        //Отрисовка поля
        for (int i = 0; i < shirina; i++)
            for (int j = 0; j < visota; j++) {
                back.setPosition(i * til, j * til);
                window.draw(back);
            }

        for (int i = 0; i < dlina_snake; i++) {
            if (i != 0)
                snake.setTextureRect(IntRect(0, 0, til, til));
            else
                snake.setTextureRect(IntRect(dir * til, til, til, til));

            if (!game && i == 1)
                snake.setTextureRect(IntRect(dir * til, til * 2, til, til));

            snake.setPosition(s[i].x * til, s[i].y * til);
            window.draw(snake);
        }

        money.setPosition(f.x * til, f.y * til);
        window.draw(money);

        if (!game)
            window.draw(gameover);

        window.display();
    }

    return 0;
}