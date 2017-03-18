#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int width = 300;
int height = 300;

int cols = 255;
int rows = 255;


int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(Color(51, 51, 51));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		window.display();
	}

	return 0;
}