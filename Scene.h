#pragma once

struct Wall
{
	Wall::Wall(sf::Vector2f const& position, sf::Vector2f const& size, sf::Vector3i const& color);
	sf::RectangleShape rectangle;
	sf::Vector2f size;
	sf::Vector2f position;
};

struct Scene
{
	std::vector<Wall*> walls;
    sf::RectangleShape centerLines;
};

void InitializeWall(std::vector<Wall*> & walls);
void InitializeScene(Scene & scene);
void InitializeCenterLine(sf::RectangleShape & line);