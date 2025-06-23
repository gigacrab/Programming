#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include <iostream>
#include <optional>

int main(){
    sf::RenderWindow window;
    
    sf::Font font("/home/littlecrabby/Programming/cpp/sfml-project/assets/fonts/Bit-23.ttf");
    sf::Text text(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Cyan);

    sf::Texture texture("/home/littlecrabby/Programming/cpp/sfml-project/assets/images/ball.jpg", false, sf::IntRect({0, 0}, {360, 360}));
    texture.setSmooth(true);
    texture.setRepeated(true);

    sf::CircleShape circle(50.f);
    circle.setTexture(&texture);

    sf::Sprite sprite(texture);

    window.create(sf::VideoMode({800, 600}), "My Window");

    while(window.isOpen()){
        while(const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }

            sprite.setPosition({10.f, 100.f});
            text.setPosition({10.f, 10.f});
            circle.setPosition({400.f, 10.f});
            window.clear(sf::Color::Black);
            /*window.draw(sprite);
            window.draw(text);
            window.draw(circle);*/
            window.display();
        }
    }
}