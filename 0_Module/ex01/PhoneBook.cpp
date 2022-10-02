#include "PhoneBook.hpp"

int     PhoneBook::countContact(){
    int     count;

    count = 0;
    for (int    i = 0; i < 8; i++){
        if (contacts[i].getOccupied() == 0){
            return (count);
        }
        count++;
    }
    return (count);
}

void	PhoneBook::ShowContacts(){
	int	i = 0;

	while (i < 8)
	{
		if (contacts[i].getOccupied() == 0)
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
        if (contacts[i].getOccupied() == 0)
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

void    PhoneBook::ShowFullContact(int index){
    int range = this->countContact();

    if (index > range - 1){
        std::cout << "Out of Range !!" << std::endl;
        return ;
    } else if (index < 0){
        std::cout << "Wrong Input !!" << std::endl;
        return ;
    }
    this->contacts[index].ShowFullInfo();
    return ;
}
