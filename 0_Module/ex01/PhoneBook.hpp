#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook{
    private:
        void    clearContact();
        int     countContact();
	public:
        Contact		contacts[8];
		void    AddContact(Contact contact);
        void    ShowContacts();
        void    ShowFullContact(int index);
        void    CleanContacts();
};

#endif