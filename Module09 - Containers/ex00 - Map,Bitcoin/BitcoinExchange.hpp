/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:20:17 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/25 17:43:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <map>
# include <string>
# include <fstream>
# include <sstream> 
# include <iomanip>

enum {
	RATE = ',',
	AMOUNT = '|'
} ;

typedef struct s_bitdate {
	int	year;
	int	month;
	int	day;
} t_bitdate;

class BitcoinExchange {
	private:
		std::string							path;
		char								separator;
		std::map<std::string, std::string>	data;

		void		loadFile();
		bool		validValue(std::string line) const;
		bool		leapYear(int year) const;
		bool		validDay(t_bitdate date) const;
		bool		validDate(std::string line) const;
		std::string	getValue(std::string date) const;
		std::pair<std::string, std::string>	lineToPair(std::ifstream& file, int separator);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange(std::string file, char separator);
		~BitcoinExchange();

		BitcoinExchange&   operator=(const BitcoinExchange& copy);

		void    worthByDate(std::string file, int separator);
		void    initDataBase(std::string file, char separtor);
} ;

#endif