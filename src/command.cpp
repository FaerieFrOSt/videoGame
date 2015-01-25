#include "command.h"

Command::Command() : category(Category::None)
{}

void	CommandQueue::push(const Command& command)
{
	mQueue.push(command);
}

Command	CommandQueue::pop()
{
	auto	tmp = mQueue.front();
	mQueue.pop();
	return tmp;
}

bool	CommandQueue::isEmpty() const
{
	return mQueue.empty();
}
