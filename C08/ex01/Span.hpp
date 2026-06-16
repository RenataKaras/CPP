#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numVector;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void 			addNumber(int num);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);



};

#endif /* !SPAN_H */