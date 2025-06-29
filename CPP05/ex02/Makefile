Name = Bureaucrat

C = c++

F = -Wall -Wextra -Werror -std=c++98

S = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

O = $(S:.cpp=.o)

all : $(Name)

%.o : %.cpp
	$(C) $(F) -c $< -o $@

$(Name) : $(O)
	$(C) $(F) $(O) -o $(Name)

clean :
	rm -rf $(O)

fclean : clean
	rm -rf $(Name)

re : fclean all

.PHONY : clean fclean re all