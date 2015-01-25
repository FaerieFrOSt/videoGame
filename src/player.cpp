#include "player.h"
#include "aircraft.h"
#include <iostream>

void	Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
	{
		Command	output;
		output.category = Category::PlayerAircraft;
		output.action = [] (SceneNode& s, sf::Time)
		{
			std::cout << s.getWorldPosition().x << ", " << s.getWorldPosition().y << std::endl;
		};
		commands.push(output);
	}
}

void	Player::handleRealtimeInput(CommandQueue& commands)
{
	const float	playerSpeed = 40.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Command	move;
		move.category = Category::PlayerAircraft;
		move.action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
		commands.push(move);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Command	move;
		move.category = Category::PlayerAircraft;
		move.action = derivedAction<Aircraft>(AircraftMover(0.f, playerSpeed));
		commands.push(move);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Command	move;
		move.category = Category::PlayerAircraft;
		move.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
		commands.push(move);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Command	move;
		move.category = Category::PlayerAircraft;
		move.action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.f));
		commands.push(move);
	}
}
