/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:30 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/11 16:18:30 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	test(50);

	for (int i = 0; i < 15; i+=2)
		test.addNumber(i);
	std::cout << "short: " << test.shortestSpan() << std::endl;
	std::cout << "long: " << test.longestSpan() << std::endl;
	test.addNumber(100);
	std::cout << "short: " << test.shortestSpan() << std::endl;
	std::cout << "long: " << test.longestSpan() << std::endl;
	test.addNumber(101);
	std::cout << "short: " << test.shortestSpan() << std::endl;
	std::cout << "long: " << test.longestSpan() << std::endl;
	try {
		for (int i = 0; i < 50; i++)
			test.addNumber(i);
	}
	catch (std::exception& event) {
		std::cout << event.what() << std::endl;	
	}

	Span	big(20000);
	try {
		big.addNumber(5);
		for (int i = 1000; i < 20000; i++)
			big.addNumber(i);
		std::cout << "short: " << big.shortestSpan() << std::endl;
		std::cout << "long: " << big.longestSpan() << std::endl;
	}
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}