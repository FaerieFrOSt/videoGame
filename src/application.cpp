#include "application.h"
#include "titlestate.h"
#include "menustate.h"
#include "gamestate.h"
#include "pausestate.h"

const sf::Time	Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application() : mWindow(sf::VideoMode(640, 480), "SFML App"), mTextures(), mFonts(),
	mPlayer(), mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer)),
	mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0)
{
	mWindow.setKeyRepeatEnabled(false);
	mFonts.load(Fonts::Main, "media/Sansation.ttf");
	mTextures.load(Textures::TitleScreen, "media/textures/TitleScreen.png");
	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setCharacterSize(10u);
	mStatisticsText.setPosition(5.f, 5.f);
	registerStates();
	mStateStack.pushState(States::Title);
}

void	Application::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
	/* mStateStack.registerState<MenuState>(States::Menu); */
	mStateStack.registerState<GameState>(States::Game);
	/* mStateStack.registerState<PauseState>(States::Pause); */
}

void	Application::processInput()
{
	sf::Event	event;

	while (mWindow.pollEvent(event))
	{
		mStateStack.handleEvent(event);
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void	Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void	Application::render()
{
	mWindow.clear();
	mStateStack.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void	Application::run()
{
	sf::Clock	clock;
	sf::Time	timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		processInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processInput();
			update(TimePerFrame);
		}
		updateStatistics(timeSinceLastUpdate);
		render();
	}
}

void	Application::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;
	if (mStatisticsUpdateTime >= sf::seconds(1.f))
	{
		mStatisticsText.setString("Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
				"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
		mStatisticsUpdateTime -= sf::seconds(1.f);
		mStatisticsNumFrames = 0;
	}
}
