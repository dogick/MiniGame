#include "stdafx.h"
#include "Const.h"
#include "Game.h"

#include <iostream>
void Render(sf::RenderWindow & window, Game* game)
{
	window.clear();
	for (auto wall : game->scene.walls)
	{
		window.draw(wall->rectangle);
	}
	
		window.draw(game->scene.centerLines);
	
	window.display();
}

void HandleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void EnterMainLoop(sf::RenderWindow & window, Game* game)
{
	while (window.isOpen())
	{
		HandleEvents(window);
		Render(window, game);
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE);
	Game* game = new Game;
	game->InitializeGame();
	EnterMainLoop(window, game);
	return 0;
}