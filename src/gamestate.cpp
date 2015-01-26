#include "gamestate.h"

GameState::GameState(StateStack& stack, Context context) : State(stack, context), mWorld(*getContext().window),
	mPlayer(*getContext().player)
{}

bool	GameState::update(sf::Time dt)
{
	mWorld.update(dt);
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleRealtimeInput(commands);
	return true;
}

void	GameState::draw()
{
	mWorld.draw();
}

bool	GameState::handleEvent(const sf::Event& event)
{
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleEvent(event, commands);
	if (event.key.code == mPlayer.getAssignedKey(Player::Pause))
		requestStackPush(States::Pause);
	return true;
}
