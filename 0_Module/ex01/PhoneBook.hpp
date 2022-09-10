#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class Contact{
	public:
		Contact();
		~Contact();
		int			occupied;
		void 		ShowInfo();
		void 		FillContact();
		void 		CleanContact();
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

class PhoneBook{
    private:
        void    clearContact();
	public:
        Contact		contacts[8];
		void    AddContact(Contact contact);
        void    ShowContacts();
        void    CleanContacts();
};

#endif