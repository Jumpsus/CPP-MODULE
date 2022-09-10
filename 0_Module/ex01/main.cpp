#include "PhoneBook.hpp"

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
            phonebook.CleanContacts();
            break;
        }
        else if (!input.compare("ADD"))
        {
            Contact addedContact;
            addedContact.FillContact();
            phonebook.AddContact(addedContact);
        }
        else if (!input.compare("SEARCH"))
        {
            phonebook.ShowContacts();
        }
    }
    return (1);
}