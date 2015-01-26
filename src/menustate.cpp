#include "menustate.h"
#include "utility.h"

MenuState::MenuState(StateStack& stack, Context context) : State(stack, context),
	mOptions(), mOptionIndex(0)
{
	sf::Text	playOption;
	playOption.setFont(context.fonts->get(Fonts::Main));
	playOption.setString("Play");
	centerOrigin(playOption);
	playOption.setPosition(context.window->getView().getSize() / 2.f);
	mOptions.push_back(playOption);
	sf::Text	exitOption;
	exitOption.setFont(context.fonts->get(Fonts::Main));
	exitOption.setString("Exit");
	centerOrigin(exitOption);
	exitOption.setPosition(context.window->getView().getSize() / 2.f);
	exitOption.move(0.f, 50.f);
	mOptions.push_back(exitOption);
}

void	MenuState::draw()
{
	auto	&window = *getContext().window;

	window.setView(window.getDefaultView());
	for (auto &i : mOptions)
		window.draw(i);
}

bool	MenuState::update(sf::Time)
{
	updateOptionText();
	return true;
}

void	MenuState::updateOptionText()
{
	if (mOptions.empty())
		return;
	for (auto &i : mOptions)
		i.setColor(sf::Color::White);
	mOptions[mOptionIndex].setColor(sf::Color::Red);
}

bool	MenuState::handleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return true;
	if (event.key.code == sf::Keyboard::Up)
	{
		if (mOptionIndex > 0)
			mOptionIndex--;
		else
			mOptionIndex = mOptions.size() - 1;
		updateOptionText();
	} else if (event.key.code == sf::Keyboard::Down)
	{
		if (mOptionIndex < mOptions.size() - 1)
			mOptionIndex++;
		else
			mOptionIndex = 0;
		updateOptionText();
	}
	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Play)
		{
			requestStackPop();
			requestStackPush(States::Game);
		} else if (mOptionIndex == Exit)
			requestStackPop();
	}
	return true;
}
