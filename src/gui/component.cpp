#include "gui/component.h"

namespace	GUI
{
	Component::Component() : mIsSelected(false), mIsActive(false)
	{}

	Component::~Component()
	{}

	bool	Component::isSelectable() const
	{
		return false;
	}

	bool	Component::isSelected() const
	{
		return mIsSelected;
	}

	void	Component::select()
	{
		mIsSelected = true;
	}

	void	Component::deselect()
	{
		mIsSelected = false;
	}

	bool	Component::isActive() const
	{
		return mIsActive;
	}

	void	Component::activate()
	{
		mIsActive = true;
	}

	void	Component::deactivate()
	{
		mIsActive = false;
	}
}
