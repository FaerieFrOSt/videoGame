#include "pausestate.h"
#include "utility.h"

PauseState::PauseState(StateStack& stack, Context context) : State(stack, context),
	mPausedText(), mInstructionText()
{
	mPausedText.setFont(context.fonts->get(Fonts::Main));
	mInstructionText.setFont(context.fonts->get(Fonts::Main));
	mPausedText.setString("Game paused");
	mInstructionText.setString("Press ESC to return to the game.\nPress BACKSPACE to return to the menu.");
	centerOrigin(mPausedText);
	centerOrigin(mInstructionText);
	mPausedText.setPosition(context.window->getView().getSize() / 2.f);
	mInstructionText.setPosition(mPausedText.getPosition());
	mInstructionText.move(0.F, 50.f);
}

void	PauseState::draw()
{
	auto	&window = *getContext().window;
	sf::RectangleShape	backgroundShape;

	window.setView(window.getDefaultView());
	backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
	backgroundShape.setSize(sf::Vector2f(window.getSize()));

	window.draw(backgroundShape);
	window.draw(mPausedText);
	window.draw(mInstructionText);
}

bool	PauseState::update(sf::Time)
{
	return false;
}

bool	PauseState::handleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;
	if (event.key.code == sf::Keyboard::Escape)
		requestStackPop();
	else if (event.key.code == sf::Keyboard::BackSpace)
	{
		requestStackClear();
		requestStackPush(States::Menu);
	}
	return false;
}
