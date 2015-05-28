#include "StringContactMap.h"

using namespace std;

StringContactMap::StringContactMap ()
{
	root = NULL;
}

StringContactMap::~StringContactMap()
{
	free_memory(root);
}

int StringContactMap::size() const
{
    // TODO: Implement
	return 0;
}

bool StringContactMap::empty() const
{
	return root == NULL;
}

vector<Contact> StringContactMap::all_contacts() const
{
    // TODO: Implement (inorder traversal could come in handy here).
    return vector<Contact>();
}

void StringContactMap::add(string key, Contact value)
{
    // TODO: Implement
	add(root, key, value);
}

void StringContactMap::remove(string key)
{
	remove(root, key);
}

bool StringContactMap::contains(string key) const
{
    // TODO: Implement
	return false;
}

Contact StringContactMap::get(string key) const
{
    // TODO: Implement
	return Contact();
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    // TODO: Implement
    // NOTE: This is for part C of the assignment.
	return vector<Contact>();
}

void StringContactMap::free_memory(NodePtr node)
{
    // TODO: Implement
}

void StringContactMap::add(NodePtr& node, string key, Contact value)
{
    // Optional helper function.
}

Contact StringContactMap::get(NodePtr node, string key) const
{
    // Optional helper function.
    return Contact();
}

bool StringContactMap::contains(NodePtr node, string key) const
{
    // Optional helper function.
    return false;
}

void StringContactMap::remove(NodePtr& node, string key)
{
	if(node == NULL) {
		return;
	} else if(node->key == key) {
		remove_root(node);
	} else if(key < node->key) {
		remove(node->left, key);
	} else {
		remove(node->right, key);
	}
}

void StringContactMap::remove_root(NodePtr& root)
{
	NodePtr succ;
	if(root->is_leaf()) {
		delete root;
		root = NULL;
	} else if(root->left == NULL) {
		succ = root->right;
		delete root;
		root = succ;
	} else if(root->right == NULL) {
		succ = root->left;
		delete root;
		root = succ;
	} else {
		NodePtr new_root = remove_min(root->right);
		new_root->left = root->left;
		new_root->right = root->right;
		delete root;
		root = new_root;
	}
}

NodePtr StringContactMap::remove_min(NodePtr& node)
{
	if(node->left == NULL) {
		NodePtr old_node = node;
		node = node->right;
		return old_node;
	} else {
		return remove_min(node->left);
	}
}

void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const
{
    // Optional helper function.
    // NOTE: This is for part C of the assignment.
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
	vector<Contact> contacts = map.all_contacts();

	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

