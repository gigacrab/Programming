#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include <iostream>
#include <optional>
#include <random>

unsigned int screenWidth = 448;
unsigned int screenHeight = 800;
int fieldWidth = 10;
int fieldHeight = 20;

std::vector<int> square = {8, 8, 8, 8, 8, 1, 1, 8, 8, 1, 1, 8, 8, 8, 8, 8};
std::vector<int> lZig = {8, 2, 8, 8, 8, 2, 2, 8, 8, 8, 2, 8, 8, 8, 8, 8};
std::vector<int> rZig = {8, 8, 3, 8, 8, 3, 3, 8, 8, 3, 8, 8, 8, 8, 8, 8};
std::vector<int> tShape = {8, 8, 4, 8, 8, 8, 4, 8, 8, 4, 4, 8, 8, 8, 8, 8};
std::vector<int> lShape = {8, 5, 8, 8, 8, 5, 8, 8, 8, 5, 5, 8, 8, 8, 8, 8};
std::vector<int> line = {8, 8, 6, 8, 8, 8, 6, 8, 8, 8, 6, 8, 8, 8, 6, 8};
std::vector<int> jShape = {8, 7, 8, 8, 8, 7, 8, 8, 8, 7, 7, 8, 8, 8, 8, 8};
std::vector<std::vector<int>> tetromino = {square, lZig, rZig, tShape, lShape, line, jShape};

int rotate(int px, int py, int r)
{
	int pi = 0;
	switch (r % 4)
	{
	case 0: // 0 degrees			// 0  1  2  3
		pi = py * 4 + px;			// 4  5  6  7
		break;						// 8  9 10 11
									//12 13 14 15

	case 1: // 90 degrees			//12  8  4  0
		pi = 12 + py - (px * 4);	//13  9  5  1
		break;						//14 10  6  2
									//15 11  7  3

	case 2: // 180 degrees			//15 14 13 12
		pi = 15 - (py * 4) - px;	//11 10  9  8
		break;						// 7  6  5  4
									// 3  2  1  0

	case 3: // 270 degrees			// 3  7 11 15
		pi = 3 - py + (px * 4);		// 2  6 10 14
		break;						// 1  5  9 13
	}								// 0  4  8 12
	return pi;
}

bool doesPieceFit(int n, int rotation, int posX, int posY){
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++){
            int pi = rotate(px, py, rotation);
            int fi = (posY + py) * fieldWidth + (posX + px);
            //if (posY + px != 8)
        }
    return true;
}

int main(){
    sf::RenderWindow window(sf::VideoMode({screenWidth, screenHeight}), "My Window");
    
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

    std::array tiles = {
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
    };

    TileMap map;
    if(!map.load("/home/littlecrabby/Programming/cpp/sfml-project/assets/images/tileset.png", {32, 32}, tiles.data(), 14, 24))
        return -1;

    int currentPiece = 0;
    int currentX = fieldWidth / 2;
    int currentY = 0;
    int currentRotation = 0;
    bool gameOver = false; 

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
        }
        text.setPosition({32.f, 16.f});

        window.clear(sf::Color::Black);

        window.draw(map);
        window.draw(text);

        window.display();
    }
}