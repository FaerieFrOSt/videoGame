#include "pausestate.h"
#include "utility.h"
#include "gui/label.h"
#include "gui/button.h"
#include <memory>

PauseState::PauseState(StateStack& stack, Context context) : State(stack, context),
	mContainer()
{
	auto	pausedText = std::make_shared<GUI::Label>("Game paused", context.fonts->get(Fonts::Main));
	mContainer.pack(pausedText);
	auto	returnButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	returnButton->setText("Return to game");
	returnButton->setCallback([this] () {
			requestStackPop();
			});
	mContainer.pack(returnButton);
	auto	menuButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	menuButton->setText("Exit to main menu");
	menuButton->setCallback([this] () {
			requestStackClear();
			requestStackPush(States::Menu);
			});
	mContainer.pack(menuButton);
	centerOrigin(*pausedText);
	pausedText->setPosition(context.window->getSize().x / 2u, context.window->getSize().y / 4u);
	centerOrigin(*returnButton);
	returnButton->setPosition(context.window->getSize().x / 2u, 2 * context.window->getSize().y / 4u);
	centerOrigin(*menuButton);
	menuButton->setPosition(context.window->getSize().x / 2u, 3 * context.window->getSize().y / 4u);
}

void	PauseState::draw()
{
	auto	&window = *getContext().window;
	sf::RectangleShape	backgroundShape;

	window.setView(window.getDefaultView());
	backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
	backgroundShape.setSize(sf::Vector2f(window.getSize()));

	window.draw(backgroundShape);
	window.draw(mContainer);
}

bool	PauseState::update(sf::Time)
{
	return false;
}

bool	PauseState::handleEvent(const sf::Event& event)
{
	mContainer.handleEvent(event);
	return false;
}
