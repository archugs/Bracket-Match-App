#include "stack.h"
Error_code Stack::push(const Stack_entry &item)
{
	Error_code outcome = success;
	if(count >= maxstack)
		outcome = overflow;
	else
		entry[count ++] = item;
	return outcome;
}

Error_code Stack::pop()
{
	Error_code outcome = success;
	if( count == 0 )
		outcome = underflow;
	else
		-- count;
	return outcome;
}

Error_code Stack::top(Stack_entry &item) const
{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}

bool Stack::empty() const
{
	bool outcome = true;
	if ( count > 0 )
		outcome = false;
	return outcome;
}

bool Stack::full() const
{
	bool outcome = true;
	if ( count > maxstack)
		outcome = false;
	return outcome;
}

int Stack::size() const
{
	return count;
}

void Stack::clear()
{
	count = 0;
}


Stack::Stack()
{
	count = 0;
}
