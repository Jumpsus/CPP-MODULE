#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact{
	public:
		Contact();
		~Contact();
		void 		ShowInfo();
        void        ShowFullInfo();
		void 		FillContact();
		void 		CleanContact();
		int			getOccupied();
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

		int			occupied;
};

#endif