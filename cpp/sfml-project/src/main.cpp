#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include <iostream>
#include <optional>
#include <random>

typedef std::vector<std::vector<int>> Matrix;

Matrix block = {{1, 1}, {1, 1}};
Matrix lzigzag = {{2, 2, 8}, {8, 2, 2}};
Matrix rzigzag = {{8, 3, 3}, {3, 3, 8}};
Matrix tshaped = {{8, 4, 8}, {4, 4, 4}};
Matrix lshaped = {{8, 8, 5}, {5, 5, 5}};
Matrix line = {{6, 6, 6, 6}};
Matrix revlshaped = {{7, 8, 8}, {7, 7, 7}};
std::vector<Matrix> dict = {block, line, lzigzag, rzigzag, tshaped, lshaped, line, revlshaped};
Matrix matrix;

int main(){
    sf::RenderWindow window(sf::VideoMode({448, 800}), "My Window");
    
    sf::Font font("/home/littlecrabby/Programming/cpp/sfml-project/assets/fonts/Bit-23.ttf");
    sf::Text text(font);
    text.setString("Score: ");
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);

    sf::Texture texture("/home/littlecrabby/Programming/cpp/sfml-project/assets/images/ball.jpg", false, sf::IntRect({0, 0}, {360, 360}));
    texture.setSmooth(true);
    texture.setRepeated(true);

    sf::CircleShape circle(50.f);
    circle.setTexture(&texture);

    sf::Sprite sprite(texture);

    matrix = {{8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8}, {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}};
    
    std::array tiles = {
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
    };

    TileMap map;
    if(!map.load("/home/littlecrabby/Programming/cpp/sfml-project/assets/images/tileset.png", {32, 32}, tiles.data(), 14, 24))
        return -1;

    while(window.isOpen()){
        while(const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){

                }
            }
            text.setPosition({32.f, 16.f});

            window.clear(sf::Color::Black);

            window.draw(map);
            window.draw(text);

            window.display();
        }
    }
}

Matrix blockGen(){
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the engine with random_device
    std::uniform_int_distribution<> distrib(1, 7); // Define the range [1, 100]

    int randomNumber = distrib(gen); // Generate a random number
    return dict[randomNumber];
}

void spawnBlock(){
    block = blockGen();

}