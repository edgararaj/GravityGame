#include <SFML/Graphics.hpp>
#include "Log.h"
#include "Engine.h"

int main() {
	// spdlog init 
	Log::Init();
	// ---------

	// sfml init 
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Gravity Game", sf::Style::Titlebar | sf::Style::Close);
	LOG_INFO("sfml renderwindow created, x={} y={}", window.getSize().x, window.getSize().y);
	// ---------

	// sfml obj
	sf::CircleShape player(50);
	player.setFillColor(sf::Color::Green);
	player.setOrigin({ player.getRadius(), player.getRadius() });

	sf::CircleShape shape(70);
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin({ shape.getRadius(), shape.getRadius() });
	shape.setPosition({ (float)window.getSize().x / 2, (float)window.getSize().y / 2 });
	// -------------

	while (window.isOpen())
	{
		// Event handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// --------------
		
		// Game logic
		player.setPosition({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y });
		
		if (Engine::squareVsSquare(Engine::getCircleBoundingSquare({ (int)player.getRadius(), {(int)player.getPosition().x, (int)player.getPosition().y} }),
			Engine::getCircleBoundingSquare({ (int)shape.getRadius(), {(int)shape.getPosition().x, (int)shape.getPosition().y} }))) {
			
			bool collision = Engine::circleVsCircle({ (int)player.getRadius(), {(int)player.getPosition().x, (int)player.getPosition().y} },
				{ (int)shape.getRadius(), {(int)shape.getPosition().x, (int)shape.getPosition().y} });
			if (collision)
				LOG_INFO(collision);
			else
				LOG_TRACE(collision);
		}
		else {
			LOG_WARN("not in bounding box");
		}
		// ----------

		// Render and screen update
		window.clear();
		window.draw(shape);
		window.draw(player);
		window.display();
	}
}
