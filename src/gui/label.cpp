#include "gui/label.h"
#include "utility.h"

namespace	GUI
{

	Label::Label(const std::string& text, const sf::Font& font, std::size_t size) :
		mText(text, font, size)
	{}

	bool	Label::isSelectable() const
	{
		return false;
	}

	sf::FloatRect	Label::getLocalBounds() const
	{
		return mText.getLocalBounds();
	}

	void	Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(mText, states);
	}

	void	Label::setText(const std::string& text)
	{
		mText.setString(text);
	}

	void	Label::handleEvent(const sf::Event&)
	{}
}
