
#ifndef _STATESTACK_H_
# define _STATESTACK_H_

#include <SFML/System.hpp>
#include <vector>
#include <map>
#include <functional>
#include "stateidentifiers.h"
#include "state.h"

class	State;

class	StateStack : private sf::NonCopyable
{
	public:
		enum	Action
		{
			Push,
			Pop,
			Clear,
		};

	public:
		StateStack(State::Context context);

		template <typename T>
		void	registerState(States::ID stateID)
		{
			mFactories[stateID] = [this] ()
			{
				return State::Ptr(new T(*this, mContext));
			};
		}

		void	update(sf::Time dt);
		void	draw();
		void	handleEvent(const sf::Event& event);

		void	pushState(States::ID stateID);
		void	popState();
		void	clearStates();

		bool	isEmpy() const;

	private:
		State::Ptr	createState(States::ID stateID);
		void		applyPendingChanges();

	private:
		struct	PendingChange
		{
			explicit	PendingChange(Action action, States::ID stateID = States::None);

			Action		action;
			States::ID	stateID;
		};

	private:
		std::vector<State::Ptr>		mStack;
		std::vector<PendingChange>	mPendingList;
		State::Context				mContext;
		std::map<States::ID, std::function<State::Ptr()>>	mFactories;
};

#endif /* !_STATESTACK_H_ */
