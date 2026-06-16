#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw std::runtime_error("Value not found\n");
	return it;
}


#endif /* !EASYFIND_H */