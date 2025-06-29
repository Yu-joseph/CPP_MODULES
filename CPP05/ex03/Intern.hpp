#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

class Intern
{
private:
	AForm* CreatPresidential(std::string target);
	AForm* CreatRobotomy(std::string target);
	AForm* CreatShrubbery(std::string target);
public:
	// Intern(std::string form, std::string target);
	Intern();
	Intern& operator=(const Intern& ls);
	Intern(const Intern& ls);
	AForm* makeForm(std::string form, std::string target);
	~Intern();
};
