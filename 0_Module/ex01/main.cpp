#include "PhoneBook.hpp"
#include <limits>
#include <cstdlib>

int     StringToInt(std::string index){
    int result = 0;

    for (size_t    i = 0; i < index.length(); i++){
        if (index[i] < '0' || index[i] > '9'){
            return (-1);
        }
        result = result * 10 + index[i] - '0';
    }
    return (result);
}

int     main()
{
    std::string input;
    std::string index;

    PhoneBook phonebook = PhoneBook();

    while(1)
    {
        std::cout << ">>";
        std::cin >> input;
        if (!input.compare("EXIT"))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            phonebook.CleanContacts();
            break;
        }
        else if (!input.compare("ADD"))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Contact addedContact;
            addedContact.FillContact();
            phonebook.AddContact(addedContact);
        }
        else if (!input.compare("SEARCH"))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            phonebook.ShowContacts();
            do {
		        std::cout << "Index :";
		        std::getline(std::cin, index);
	        } while (index == "");
            phonebook.ShowFullContact(StringToInt(index));
        }
    }
    return (1);
}