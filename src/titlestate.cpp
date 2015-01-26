#include "titlestate.h"

TitleState::TitleState(StateStack& stack, Context context) : State(stack, context),
	mBackgroundSprite(context.textures->get(Textures::TitleScreen)), mText(), mShowText(true), mTextEffectTime()
{
	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setCharacterSize(20u);
	mText.setString("Press any key to continue");
	mText.setPosition(100.f, 100.f);
}

void	TitleState::draw()
{
	sf::RenderWindow&	window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);
	if (mShowText)
		window.draw(mText);
}

bool	TitleState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::Game);
	}
	return true;
}

bool	TitleState::update(sf::Time dt)
{
	mTextEffectTime += dt;
	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}
	return true;
}
