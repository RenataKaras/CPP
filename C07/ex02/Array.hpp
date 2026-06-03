/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 16:23:42 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/03 12:27:03 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T>
class Array
{
	private:
		size_t	_size;
		T		*_elements;
	
	public:
		Array() : _size(0), _elements(nullptr) {}
		Array(size_t size) : _size(size), _elements(new T[size]()) {}
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T		&operator[](size_t i);
		size_t	size() const;
};

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _elements(new T[other._size]()) {
	for (size_t i = 0; i < _size; i++)
		_elements[i] = other._elements[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other)
	{
		delete[] _elements;
		_size = other._size;
		_elements = new T[_size]();
		for (size_t i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _elements;
}

template <typename T>
T	&Array<T>::operator[](size_t i) {
	if (i >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_elements[i]);
}

template <typename T>
size_t	Array<T>::size() const {
	return _size;
}

#endif /* !ARRAY_H */