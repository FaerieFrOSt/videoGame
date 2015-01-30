#include "settingsstate.h"
#include "utility.h"

SettingsState::SettingsState(StateStack& stack, Context context) : State(stack, context),
	mContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	mBindingButtons[Player::MoveLeft] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingLabels[Player::MoveLeft] = std::make_shared<GUI::Label>("", context.fonts->get(Fonts::Main));
	mBindingButtons[Player::MoveRight] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingLabels[Player::MoveRight] = std::make_shared<GUI::Label>("", context.fonts->get(Fonts::Main));
	mBindingButtons[Player::MoveUp] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingLabels[Player::MoveUp] = std::make_shared<GUI::Label>("", context.fonts->get(Fonts::Main));
	mBindingButtons[Player::MoveDown] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingLabels[Player::MoveDown] = std::make_shared<GUI::Label>("", context.fonts->get(Fonts::Main));
	updateLabels();

	auto	backButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	backButton->setPosition(100, 375);
	backButton->setText("Back");
	backButton->setCallback([this] () {
			requestStackPop();
			});

	for (std::size_t i = 0; i < mBindingButtons.size(); ++i)
	{
		mBindingButtons[i]->setToggle(true);
		centerOrigin(*mBindingButtons[i]);
		mBindingButtons[i]->setPosition(150.f, 150.f + i * 50.f);
		centerOrigin(*mBindingLabels[i]);
		mBindingLabels[i]->setPosition(300.f, 150.f + i * 50.f);
	}
	mBindingButtons[Player::MoveLeft]->setText("Move left");
	mBindingButtons[Player::MoveRight]->setText("Move right");
	mBindingButtons[Player::MoveUp]->setText("Move up");
	mBindingButtons[Player::MoveDown]->setText("Move down");
	mContainer.pack(mBindingButtons[Player::MoveLeft]);
	mContainer.pack(mBindingLabels[Player::MoveLeft]);
	mContainer.pack(mBindingButtons[Player::MoveRight]);
	mContainer.pack(mBindingLabels[Player::MoveRight]);
	mContainer.pack(mBindingButtons[Player::MoveUp]);
	mContainer.pack(mBindingLabels[Player::MoveUp]);
	mContainer.pack(mBindingButtons[Player::MoveDown]);
	mContainer.pack(mBindingLabels[Player::MoveDown]);
	mContainer.pack(backButton);
}

void	SettingsState::draw()
{
	auto	&window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);
	window.draw(mContainer);
}

bool	SettingsState::update(sf::Time)
{
	return true;
}

void	SettingsState::updateLabels()
{
	Player&	player = *getContext().player;

	for (int i = Player::MoveLeft; i != Player::ActionCount; ++i)
	{
		sf::Keyboard::Key	key = player.getAssignedKey(static_cast<Player::Action>(i));
		mBindingLabels[i]->setText(getKeyName(key));
	}
}

bool	SettingsState::handleEvent(const sf::Event& event)
{
	bool	isKeyBinding = false;

	for (int action = Player::MoveLeft; action != Player::ActionCount; ++action)
	{
		if (mBindingButtons[action]->isActive())
		{
			isKeyBinding = true;
			if (event.type == sf::Event::KeyPressed)
			{
				getContext().player->assignKey(static_cast<Player::Action>(action), event.key.code);
				mBindingButtons[static_cast<Player::Action>(action)]->deactivate();
			}
			break;
		}
	}
	if (isKeyBinding)
		updateLabels();
	else
		mContainer.handleEvent(event);
	return false;
}
