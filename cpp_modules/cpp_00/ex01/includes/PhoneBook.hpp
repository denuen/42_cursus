#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../includes/Contact.hpp"

const int	MAX_CONTACTS = 8;

class	PhoneBook
{
	private:
		Contact 	contacts[MAX_CONTACTS];
		int			size;

	public:
		PhoneBook(const int& size = 0);
		PhoneBook(const PhoneBook &);
		PhoneBook& operator=(const PhoneBook &);

		const Contact		getContact(const int& index) const;
		inline void			updateSize(){size++;}
		inline int			getSize() const {return (size);}
		void				addContact(const Contact& newContact);

		inline bool			isEmpty() const {return (size == 0);};
		inline bool			isFull() const {return (size == MAX_CONTACTS);};

		~PhoneBook();
};

void	contactAdd(PhoneBook *phoneBook);
void	contactSearch(const PhoneBook& phonebook);
#endif
