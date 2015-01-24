#include "game.h"

static const float		PlayerSpeed = 100.f;
static const sf::Time	TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML App"), mPlayer(), mTexture(), mFont(), mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0), mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false)
{
	if (!mTexture.loadFromFile("media/textures/Eagle.png"))
	{
		// Handle loading error
	}
	mFont.loadFromFile("media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
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

void	Game::update(sf::Time deltaTime)
{
	sf::Vector2f	movement(0.f, 0.f);

	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void	Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
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
