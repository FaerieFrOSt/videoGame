#include "menustate.h"
#include "utility.h"
#include "gui/button.h"

MenuState::MenuState(StateStack& stack, Context context) : State(stack, context),
	mContainer(), mBackgroundSprite(context.textures->get(Textures::TitleScreen))
{
	auto	playbutton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	playbutton->setPosition(100, 250);
	playbutton->setText("Play");
	playbutton->setCallback([this] () {
			requestStackPop();
			requestStackPush(States::Game);
			});
	mContainer.pack(playbutton);

	auto	exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	exitButton->setPosition(100, 350);
	exitButton->setText("Exit");
	exitButton->setCallback([this] () {
			requestStackPop();
			});
	mContainer.pack(exitButton);
}

void	MenuState::draw()
{
	auto	&window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);
	window.draw(mContainer);
}

bool	MenuState::update(sf::Time)
{
	return true;
}

bool	MenuState::handleEvent(const sf::Event& event)
{
	mContainer.handleEvent(event);
	return false;
}
