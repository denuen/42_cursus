#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(const int& size): size(size)
{
	Contact	tmp;

	for (int i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = tmp;
}

PhoneBook::PhoneBook(const PhoneBook &newPhoneBook)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = newPhoneBook.contacts[i];
}

PhoneBook&	PhoneBook::operator=(const PhoneBook &newPhoneBook)
{
	if (this != &newPhoneBook)
	{
		for (int i = 0; i < MAX_CONTACTS; i++)
			contacts[i] = newPhoneBook.contacts[i];
	}
	return (*this);
}

const Contact	PhoneBook::getContact(const int& index) const
{
	Contact	tmp;

	if (index < 0 || index > size)
		return (tmp);
	return (contacts[index]);
}

void	PhoneBook::addContact(const Contact& newContact)
{
	if (isFull())
		contacts[MAX_CONTACTS - 1] = newContact;
	else if (isEmpty())
		contacts[0] = newContact;
	else
	{
		for (int i = 0; i < MAX_CONTACTS; i++)
		{
			if (contacts[i].getFirstName() == "(null)")
			{
				contacts[i] = newContact;
				break ;
			}
		}
	}
	size++;
}

PhoneBook::~PhoneBook()
{

}
