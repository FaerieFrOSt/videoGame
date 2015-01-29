
#ifndef _LABEL_H_
# define _LABEL_H_

#include "gui/component.h"
#include <string>
#include <SFML/Graphics.hpp>

namespace	GUI
{
	class	Label : public Component
	{
		public:
			Label(const std::string& text, const sf::Font& font, std::size_t size = 16);

			virtual bool	isSelectable() const;
			void			setText(const std::string& text);
			virtual void	handleEvent(const sf::Event& event);

		private:
			void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

		private:
			sf::Text	mText;
	};
}

#endif /* !_LABEL_H_ */
