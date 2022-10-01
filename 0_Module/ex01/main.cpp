#include "PhoneBook.hpp"
#include <limits>

int     main()
{
    std::string input;
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
        }
    }
    return (1);
}