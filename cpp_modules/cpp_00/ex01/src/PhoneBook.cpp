/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:12:08 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 13:10:26 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	Contact	tmp;

	size = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = tmp;
}

PhoneBook::PhoneBook(const PhoneBook &newPhoneBook)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		contacts[i] = newPhoneBook.contacts[i];
	}
	size = newPhoneBook.size;
}

PhoneBook&	PhoneBook::operator=(const PhoneBook &newPhoneBook)
{
	if (this != &newPhoneBook)
	{
		for (int i = 0; i < MAX_CONTACTS; i++)
		{
			contacts[i] = newPhoneBook.contacts[i];
		}
		size = newPhoneBook.size;
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
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
		{
			contacts[i] = contacts[i + 1];
		}
		contacts[MAX_CONTACTS - 1] = newContact;
		return ;
	}
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
