#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int width = 255;
int height = 255;

int cols = 255;
int rows = 255;

void checkEdges(sf::CircleShape cir, sf::Vector2f &mpf, bool &io);

int main()
{
	Vector2f mousePositionFloat;
	sf::RenderWindow window(sf::VideoMode(width, height), "Weird Color picker");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(Color(51, 51, 51));

	sf::CircleShape sprite;
	sprite.setRadius(10);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());
	sprite.setPosition(width / 2, height / 2);
	bool isOutside = false;
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		sprite.setFillColor(Color(255, 255, 255));
		if (isOutside == false) {
			mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		}
		sf::FloatRect spriteBox(sprite.getPosition().x - sprite.getRadius(), sprite.getPosition().y - sprite.getRadius(), sprite.getRadius() * 2, sprite.getRadius() * 2);
		checkEdges(sprite, mousePositionFloat, isOutside);
		if (spriteBox.contains(mousePositionFloat)) {
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				background.setFillColor(Color(mousePositionFloat.x,mousePositionFloat.y,0));
				sprite.setPosition(mousePositionFloat);
				
			}
			sprite.setFillColor(Color(1, 1, 51));
		}
		if (Mouse::isButtonPressed(Mouse::Button::Left)) {
			sprite.setPosition(mousePositionFloat);
			background.setFillColor(Color(mousePositionFloat.x, mousePositionFloat.y, 0));
			
		}
		window.draw(background);
		window.draw(sprite);
		window.display();
	}

	return 0;
}

void checkEdges(sf::CircleShape cir, sf::Vector2f &mpf, bool &io) {
	if (cir.getPosition().x < 0) { cir.setPosition(0, cir.getPosition().y); mpf.x = 0; }
	if (cir.getPosition().x > width) { cir.setPosition(width, cir.getPosition().y); mpf.x = width - 1; }
	if (cir.getPosition().y < 0) { cir.setPosition(cir.getPosition().x, 0); mpf.y = 0 + 1; }
	if (cir.getPosition().y > height) { cir.setPosition(cir.getPosition().x, height); mpf.y = height - 1; }
}