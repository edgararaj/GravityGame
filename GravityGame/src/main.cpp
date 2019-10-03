#include <SFML/Graphics.hpp>
#include "Log.h"
#include <string>

int main() {
	// spdlog init 
	Log::Init();
	// ---------

	// sfml init 
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	// ---------

	// sfml obj
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	// -------------

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
