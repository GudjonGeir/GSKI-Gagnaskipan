#include "AlienFamilyTree.h"

AlienFamilyTree::AlienFamilyTree()
{
    head = NULL;
}

AlienFamilyTree::~AlienFamilyTree()
{
    delete_tree(head);
    head = NULL;
}

bool AlienFamilyTree::is_descendant(string name)
{
    NodePtr tmp = find(head, name);
    if (tmp == NULL)
    {
        return false;
    }
    if (tmp->data == name)
    {
        return true;
    }
    return false;
}

bool AlienFamilyTree::is_descendant(string ancestor, string descendant)
{
    NodePtr ancestorPtr = find(head, ancestor);
    if (ancestorPtr == NULL)
    {
        return false;
    }
    NodePtr descendantPtr = find(ancestorPtr, descendant);
    if (descendantPtr == NULL)
    {
        return false;
    }
    else if (descendantPtr->data == descendant)
    {
        return true;
    }
    return false;
}

int AlienFamilyTree::generation(string name)
{
    return generation(head, name);
}

NodePtr AlienFamilyTree::find(NodePtr root, string name)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == name)
    {
        return root;
    }
    else
    {
        NodePtr tmp = find(root->left, name);
        if (tmp != NULL)
        {
            return tmp;
        }
        return find(root->right, name);
    }


}

int AlienFamilyTree::generation(NodePtr root, string name, int gen)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == name)
    {
        return gen;
    }
    int tmpLeft = generation(root->left, name, gen + 1);
    if (tmpLeft != -1)
    {
        return tmpLeft;
    }
    return generation(root->right, name, gen + 1);

}

void AlienFamilyTree::delete_tree(NodePtr root)
{
    if (root == NULL)
    {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

// Helper function that reads a binary tree in from the specified input stream
// and returns the root of the tree.
NodePtr parse_tree(istream& ins)
{
    char c;
    ins >> c; // Read (

    ins >> c; // Read next character

    // If the next character is ), this is the empty tree
    if(c == ')') {
        return NULL;
    }

    // Return the "borrowed" character to the input stream
    ins.putback(c);

    string node_data;
    ins >> node_data;

    NodePtr node = new BinaryStringNode;
    node->data = node_data;
    node->left = parse_tree(ins);
    node->right = parse_tree(ins);

    ins >> c; // Consume the trailing )

    return node;
}

void indent(ostream& outs, int level)
{
    for(int i = 0; i != level * 3; i++) {
        outs << " ";
    }
}

// Helper function that prints the binary tree root to the specified output
// stream.
void print_tree(ostream& outs, NodePtr root, int level = 0)
{
    indent(outs, level);
    if(root == NULL) {
        outs << "()" << endl;
        return;
    }
    outs << "(" << root->data << endl;
    print_tree(outs, root->left, level + 1);
    print_tree(outs, root->right, level + 1);
    indent(outs, level);
    outs << ")" << endl;
}

istream& operator>> (istream& ins, AlienFamilyTree& tree)
{
    tree.head = parse_tree(ins);
    return ins;
}

ostream& operator<< (ostream& outs, const AlienFamilyTree& tree)
{
    print_tree(outs, tree.head);
    return outs;
}

