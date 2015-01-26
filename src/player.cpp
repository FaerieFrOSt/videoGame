#include "player.h"
#include "aircraft.h"
#include <iostream>

Player::Player()
{
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;
	mKeyBinding[sf::Keyboard::P] = Debug;

	const float	playerSpeed = 60.f;
	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.f));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, playerSpeed));
	mActionBinding[Debug].action = [] (SceneNode& node, sf::Time)
	{
		std::cout << node.getWorldPosition().x << ", " << node.getWorldPosition().y << std::endl;
	};

	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void	Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type != sf::Event::KeyPressed)
		return;
	for (auto pair : mKeyBinding)
		if (event.key.code == pair.first && !isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
}

void	Player::handleRealtimeInput(CommandQueue& commands)
{
	for (auto pair : mKeyBinding)
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
}

void	Player::assignKey(Action action, sf::Keyboard::Key key)
{
	for (auto it = mKeyBinding.begin(); it != mKeyBinding.end();)
	{
		if (it->second == action)
			mKeyBinding.erase(it++);
		else
			++it;
	}
	mKeyBinding[key] = action;
}

sf::Keyboard::Key	Player::getAssignedKey(Action action) const
{
	for (auto it = mKeyBinding.begin(); it != mKeyBinding.end(); ++it)
		if (it->second == action)
			return it->first;
	return mKeyBinding.end()->first;
}

bool	Player::isRealtimeAction(Action action) const
{
	switch (action)
	{
		case MoveUp:
		case MoveDown:
		case MoveLeft:
		case MoveRight:
			return true;
		default:
			return false;
	}
}

