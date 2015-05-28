#include "ContactList.h"

using namespace std;

ContactList::ContactList()
{
	head = NULL;
}

ContactList::~ContactList()
{
	remove_all();
}

void ContactList::remove_all()
{
	if (head == NULL)
	{
		return;
	}
	NodePtr curr = head, tmp;
	while (curr->link != NULL)
	{
		tmp = curr->link;
		delete curr;
		curr = tmp;
	}
	delete curr;
}

// Helper function
void ContactList::remove_all(NodePtr node)
{
	if (node->link == NULL)
	{
		return;
	}
	remove_all(node->link);
	delete node;
}

bool ContactList::add(string key, Contact value)
{
	if (head == NULL)
	{
		NodePtr tmpNode = new ContactNode(key, value);
		head = tmpNode;
		return true;
	}
	if (head->data.key == key)
	{
		head->data.value = value;
		return false;
	}
	return add(key, value, head);
}

// Helper function
bool ContactList::add(string key, Contact value, NodePtr node)
{
	if (node->link == NULL)
	{
		NodePtr tmpNode = new ContactNode(key, value);
		node->link = tmpNode;
		return true;
	}
	if (node->link->data.key == key)
	{
		node->link->data.value = value;
		return false;
	}
	return add(key, value, node->link);
}

bool ContactList::remove(string key)
{
	if (head == NULL)
	{
		return false;
	}
	if (head->data.key == key)
	{
		NodePtr tmp = head;
		head = head->link;
		delete tmp;
		return true;
	}
	return remove(key, head);
}

// Helper function
bool ContactList::remove(string key, NodePtr node)
{
	if (node->link == NULL)
	{
		return false;
	}
	if (node->link->data.key == key)
	{
		NodePtr tmpNode = node->link;
		node->link = node->link->link;
		delete tmpNode;
		return true;
	}
	return remove(key, node->link);
}

bool ContactList::contains(string key)
{
	return contains(key, head);
}

// Helper function
bool ContactList::contains(string key, NodePtr node)
{
	if (node == NULL)
	{
		return false;
	}
	if (node->data.key == key)
	{
		return true;
	}
	return contains(key, node->link);
}

Contact ContactList::get(string key)
{
	return get(key, head);
}

// Helper function
Contact ContactList::get(string key, NodePtr node)
{
	if (node == NULL)
	{
		throw KeyException();
	}
	if (node->data.key == key)
	{
		return node->data.value;
	}
	return get(key, node->link);
}

void ContactList::get_contacts(vector<Contact>& contacts)
{
	get_contacts(contacts, head);
}

//Helper function
void ContactList::get_contacts(vector<Contact>& contacts, NodePtr node)
{
	if (node == NULL)
	{
		return;
	}
	contacts.push_back(node->data.value);
	get_contacts(contacts, node->link);
}

void ContactList::get_contacts_by_prefix(string prefix, vector<Contact>& contacts)
{
	get_contacts_by_prefix(prefix, contacts, head);
}

void ContactList::get_contacts_by_prefix(string prefix, vector<Contact>& contacts, NodePtr node)
{
	if (node == NULL)
	{
		return;
	}
	if (node->data.key.substr(0, prefix.length()) == prefix)
	{
		contacts.push_back(node->data.value);
	}
	get_contacts_by_prefix(prefix, contacts, node->link);
}


vector<StringContactPair> ContactList::to_vector()
{
	return to_vector(head);
}

//Helper function
vector<StringContactPair> ContactList::to_vector(NodePtr node)
{
	vector<StringContactPair> currentVec;
	if (node == NULL)
	{
		return currentVec;
	}

	currentVec = to_vector(node->link);
	vector<StringContactPair>::iterator it = currentVec.begin();
	currentVec.insert(it, node->data);
	return currentVec;
}

ostream& operator <<(ostream& outs, const ContactList& lis)
{
	NodePtr iter = lis.head;
	if (iter == NULL)
	{
		return outs;
	}
	while (iter->link != NULL)
	{
		outs << iter->data.value << endl;
		iter = iter->link;
	}
	outs << iter->data.value << endl;
	return outs;
}
