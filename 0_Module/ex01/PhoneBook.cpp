#include "PhoneBook.hpp"

void	PhoneBook::ShowContacts(){
	int	i = 0;

	while (i < 8)
	{
		if (contacts[i].occupied == 0)
			return;
		contacts[i].ShowInfo();
		i++;
	}
	return ;
}

void	PhoneBook::clearContact()
{
	int i = 0;

    while (i < 8)
    {
        if ((i - 1) >= 0)
        {
            contacts[i - 1] = contacts[i];
        }
        i++;
    }
}

void	PhoneBook::AddContact(Contact contact){
	int	i = 0;

    while(i < 8)
    {
        if (contacts[i].occupied == 0)
        {
            contacts[i] = contact;
            return ;
        }
        i++;
    }
	clearContact();
	contacts[7] = contact;
	return ;
}

void	PhoneBook::CleanContacts()
{
	int i = 0;

    while (i < 8)
    {
        contacts[i].CleanContact();
        i++;
    }
}
