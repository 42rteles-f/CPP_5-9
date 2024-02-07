/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/05 17:47:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
_name(""), _grade(150)
{ std::cout << "Bureaucrat Default Constructor called." << std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat& tocopy)
{
	std::cout << "Bureaucrat Copy Constructor called." << std::endl;
	*this = tocopy;
}

Bureaucrat::~Bureaucrat()
{ std::cout << "Bureaucrat Destructor called." << std::endl; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& tocopy) {
	if (this == &tocopy)
		return (*this);
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os	<< "Bureaucrat " << obj.getName()
		<< " has Grade: " << obj.getGrade() << std::endl;
	return (os);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1) {
		throw GradeTooHighException();
		return ;
	}
	else if (grade > 150) {
		throw GradeTooLowException();
		return ;
	}
	this->_grade = grade;
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

void	Bureaucrat::setName(std::string name) {
	this->_name = name;
}

void	Bureaucrat::increaseGrade(void) {
	(this->_grade > 1) ? this->_grade-- : throw GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(void) {
	(this->_grade < 150) ? this->_grade++ : throw GradeTooLowException();
}
