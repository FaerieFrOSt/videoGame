#include "game.h"

static const sf::Time	TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML App"), mFont(), mStatisticsText(),
	mStatisticsUpdateTime(), mStatisticsNumFrames(0), mIsMovingUp(false),
	mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false), mWorld(mWindow)
{
	mFont.loadFromFile("media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void	Game::run()
{
	sf::Clock	clock;
	sf::Time	timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		updateStatistics(timeSinceLastUpdate);
		render();
	}
}

void	Game::processEvents()
{
	sf::Event	event;

	while (mWindow.pollEvent(event))
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
			default:
				break;
		}
}

void	Game::update(sf::Time dt)
{
	mWorld.update(dt);
}

void	Game::render()
{
	mWindow.clear();
	mWorld.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void	Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Z)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::Q)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

void	Game::updateStatistics(sf::Time elapsedTime)
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
