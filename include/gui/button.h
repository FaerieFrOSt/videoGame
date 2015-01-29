
#ifndef _BUTTON_H_
# define _BUTTON_H_

#include "gui/component.h"
#include "texturesholder.h"
#include "fontholder.h"
#include "fontholder.h"
#include <functional>
#include <string>

namespace	GUI
{
	class	Button : public Component
	{
		public:
			Button(const FontHolder& fonts, const TextureHolder& textures);

			void	setCallback(std::function<void()> callback);
			void	setText(const std::string& text);
			void	setToggle(bool toggle);

			virtual bool	isSelectable() const;
			virtual void	select();
			virtual void	deselect();
			virtual void	activate();
			virtual void	deactivate();
			virtual void	handleEvent(const sf::Event& event);

		private:
			virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;

		private:
			std::function<void()>	mCallback;
			const sf::Texture&		mNormalTexture;
			const sf::Texture&		mSelectedTexture;
			const sf::Texture&		mPressedTexture;
			sf::Sprite				mSprite;
			sf::Text				mText;
			bool					mIsToggle;
	};
}

#endif /* !_BUTTON_H_ */
