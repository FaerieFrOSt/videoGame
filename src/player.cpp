#include "player.h"
#include "aircraft.h"

void	Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	(void)event;
	(void)commands;
}

void	Player::handleRealtimeInput(CommandQueue& commands)
{
	const float	playerSpeed = 10.f;

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
