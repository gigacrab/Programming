#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

int main(){
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 600}), "My Window");
    while(window.isOpen()){
        while(const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
    }
}