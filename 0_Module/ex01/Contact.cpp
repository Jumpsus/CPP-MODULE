#include "Contact.hpp"

static std::string getInput(std::string text)
{
	std::string	input;

	do {
		std::cout << text;
		std::getline(std::cin, input);
	} while (input == "");

	return (input);
}

Contact::Contact()
{
	occupied = 0;
}

Contact::~Contact()
{
}

void	Contact::FillContact()
{
	firstName = getInput("First Name: ");
	lastName = getInput("Last Name: ");
	nickName = getInput("Nickname: ");
	phoneNumber = getInput("Phone Number: ");
	darkestSecret = getInput("Dark Secret: ");
	occupied = 1;
}

static void	print_ten(std::string str)
{
	int	i = 0;
	int diff = 10 - str.length();

	while (diff > 0)
	{
		std::cout << " ";
		diff--;
	}
	while (str[i])
	{
		if (i == 9 && str[i + 1])
		{
			std::cout << ".";
			break ;
		}
		std::cout << str[i];
		i++;
	}
	return ;
}

void	Contact::ShowInfo()
{
	print_ten(firstName);
	std::cout << "|";
	print_ten(lastName);
	std::cout << "|";
	print_ten(nickName);
	std::cout << "|";
	print_ten(phoneNumber);
	std::cout << std::endl;
	return ;
}

void	Contact::CleanContact()
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret =  "";
	occupied = 0;
}

void	Contact::ShowFullInfo()
{
	std::cout << "- First Name: " << this->firstName << std::endl;
	std::cout << "- Last Name: " << this->lastName << std::endl;
	std::cout << "- Nick Name: " << this->nickName << std::endl;
	std::cout << "- Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "- Dark Secret: " << this->darkestSecret << std::endl;
}

int		Contact::getOccupied(){
	return (this->occupied);
}