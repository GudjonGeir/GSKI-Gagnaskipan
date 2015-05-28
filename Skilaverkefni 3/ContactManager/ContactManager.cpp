#include "ContactManager.h"

void ContactManager::add(Contact contact)
{
	name_map.add(contact.name, contact);
	phone_map.add(contact.phone, contact);
}

void ContactManager::remove(string name)
{
	if (name_exists(name))
	{
		Contact tmp = name_map.get(name);
		phone_map.remove(tmp.phone);
		name_map.remove(tmp.name);
	}
}

void ContactManager::update_phone(string name, string new_number)
{
	if (!name_exists(name))
	{
		throw ContactMissingException();
		return;
	}
	Contact tmp = name_map.get(name);
	phone_map.remove(tmp.phone);
	tmp.phone = new_number;
	phone_map.add(new_number, tmp);
	name_map.add(name, tmp);	
}

void ContactManager::update_email(string name, string new_email)
{
	if (!name_exists(name))
	{
		throw ContactMissingException();
	}
	Contact tmp = name_map.get(name);
	tmp.email = new_email;
	phone_map.add(tmp.phone, tmp);
	name_map.add(tmp.name, tmp);
}

bool ContactManager::name_exists(string name)
{
	return name_map.contains(name);
}

bool ContactManager::phone_exists(string phone)
{
	return phone_map.contains(phone);
}

Contact ContactManager::get_contact_by_name(string name)
{
	if (!name_exists(name))
	{
		throw ContactMissingException();
	}
	return name_map.get(name);
}

Contact ContactManager::get_contact_by_phone(string phone)
{
	if (!phone_exists(phone))
	{
		throw ContactMissingException();
	}
	return phone_map.get(phone);
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
	return name_map.prefix_search(name_prefix);
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
	return phone_map.prefix_search(phone_prefix);
}

ostream& operator<< (ostream& out, ContactManager& manager)
{
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
