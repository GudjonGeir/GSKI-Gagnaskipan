#include "ContactManager.h"

void ContactManager::add(Contact contact)
{
	// TODO: Implement
}

void ContactManager::remove(string name)
{
	// TODO: Implement
}

void ContactManager::update_phone(string name, string new_number)
{
	// TODO: Implement
}

void ContactManager::update_email(string name, string new_email)
{
	// TODO: Implement
}

bool ContactManager::name_exists(string name)
{
	// TODO: Implement
	return false;
}

bool ContactManager::phone_exists(string phone)
{
	// TODO: Implement
	return false;
}

Contact ContactManager::get_contact_by_name(string name)
{
	// TODO: Implement
	return Contact();
}

Contact ContactManager::get_contact_by_phone(string phone)
{
	// TODO: Implement
	return Contact();
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
	// TODO: Implement
	// NOTE: This is for part C of the assignment.
	return vector<Contact>();
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
	// TODO: Implement
	// NOTE: This is for part C of the assignment.
	return vector<Contact>();
}

ostream& operator<< (ostream& out, ContactManager& manager)
{
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
