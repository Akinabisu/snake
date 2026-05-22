#include "game_logic_graphic.h"

#include <SFML/Graphics.hpp>

#include "field.h"
#include "food.h"
#include "snake.h"
const int WINDOW_SIZE = 800;
const int CELL_SIZE = WINDOW_SIZE / 20;

const int GAME_OVER_PATTERN[10][20] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void GameLogicGraphic::game() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Snake");
    window.setFramerateLimit(10);
    Field field = Field(20, 20);
    Snake snake = Snake(field);
    Food food;
    food.placeFood(field);

    bool isGameOver = false;
    Direction currentDir = Direction::Right;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::W:
                    case sf::Keyboard::Up:
                        if (currentDir != Direction::Down) currentDir = Direction::Up;
                        break;

                    case sf::Keyboard::S:
                    case sf::Keyboard::Down:
                        if (currentDir != Direction::Up) currentDir = Direction::Down;
                        break;

                    case sf::Keyboard::A:
                    case sf::Keyboard::Left:
                        if (currentDir != Direction::Right) currentDir = Direction::Left;
                        break;

                    case sf::Keyboard::D:
                    case sf::Keyboard::Right:
                        if (currentDir != Direction::Left) currentDir = Direction::Right;
                        break;

                    default:
                        break;
                }
            }
        }

        if (!isGameOver) {
            bool eat = food.coords() == snake.headCoords();
            snake.move(currentDir, eat);

            if (eat) {
                food.placeFood(field);
            }

            field.addObject(food.coords(), '0');
            field.addObject(snake.snakeCoords(), snake.length(), 'x');
        }

        window.clear(sf::Color::Black);

        if (snake.isDead()) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 20; ++j) {
                    if (GAME_OVER_PATTERN[i][j] == 1) {
                        sf::RectangleShape block(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                        block.setFillColor(sf::Color::Red);
                        block.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                        window.draw(block);
                    }
                }
            }

            isGameOver = true;
        } else {
            for (int i = 0; i < snake.length(); ++i) {
                Coords partCoords = snake.snakeCoords()[i];
                sf::RectangleShape snakePart(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
                snakePart.setFillColor(sf::Color::Blue);
                snakePart.setPosition(partCoords.x * CELL_SIZE, partCoords.y * CELL_SIZE);

                window.draw(snakePart);
            }

            sf::RectangleShape foodShape(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
            foodShape.setFillColor(sf::Color::Red);
            foodShape.setPosition(food.coords().x * CELL_SIZE, food.coords().y * CELL_SIZE);
            window.draw(foodShape);
        }

        window.display();
    }
}