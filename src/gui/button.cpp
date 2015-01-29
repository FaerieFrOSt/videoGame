#include "gui/button.h"
#include "utility.h"

namespace	GUI
{
	Button::Button(const FontHolder& fonts, const TextureHolder& textures) : 
		mCallback(), mNormalTexture(textures.get(Textures::ButtonNormal)),
		mSelectedTexture(textures.get(Textures::ButtonSelected)),
		mPressedTexture(textures.get(Textures::ButtonPressed)),
		mSprite(),
		mText("", fonts.get(Fonts::Main), 16), mIsToggle(false)
	{
		mSprite.setTexture(mNormalTexture);
		centerOrigin(mText);
		mText.setPosition(sf::Vector2f(mNormalTexture.getSize() / 2u));
	}

	bool	Button::isSelectable() const
	{
		return true;
	}

	void	Button::setText(const std::string& text)
	{
		mText.setString(text);
	}

	void	Button::setToggle(bool toggle)
	{
		mIsToggle = toggle;
	}

	void	Button::setCallback(std::function<void()> f)
	{
		mCallback = f;
	}

	void	Button::select()
	{
		Component::select();
		mSprite.setTexture(mSelectedTexture);
	}

	void	Button::deselect()
	{
		Component::deselect();
		mSprite.setTexture(mNormalTexture);
	}

	void	Button::activate()
	{
		Component::activate();
		if (mIsToggle)
			mSprite.setTexture(mPressedTexture);
		if (mCallback)
			mCallback();
		if (!mIsToggle)
			deactivate();
	}

	void	Button::deactivate()
	{
		Component::deactivate();
		if (mIsToggle)
		{
			if (isSelected())
				mSprite.setTexture(mSelectedTexture);
			else
				mSprite.setTexture(mNormalTexture);
		}
	}

	void	Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(mSprite, states);
		target.draw(mText, states);
	}

	void	Button::handleEvent(const sf::Event&)
	{}
}
