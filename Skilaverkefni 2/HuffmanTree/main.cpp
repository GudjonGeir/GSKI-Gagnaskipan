#include <iostream>
#include <string>
#include <assert.h>
#include "HuffmanNode.h"
#include "HuffmanPriorityQueue.h"

using namespace std;

const int INDENT_SIZE = 2;

// Prints the Huffman tree 'root' to the standard output, indented by 'indent' spaces.
// The printed tree is labeled (i.e., prefixed) by the string 'prefix'.
void print_tree(NodePtr root, int indent = 0, string prefix = "")
{
    // External nodes are not printed.
    if(root == NULL) {
        return;
    }

    char letter = ' ';
    if(root->is_leaf()) {
        letter = root->letter;
    }

    cout << string(indent, ' ') << prefix << "(" << letter << " [" << root->frequency << "]";
    if(root->is_leaf()) {
        cout << ")" << endl;
    } else {
        cout << endl;
        // Print left and right subtrees with the appropriate prefix, and
        // increased indent (by INDENT_SIZE).
        print_tree(root->left, indent + INDENT_SIZE, "0");
        print_tree(root->right, indent + INDENT_SIZE, "1");
        cout << string(indent, ' ') << ")" << endl;
    }
}

// Reads a frequency table from standard input, builds the Huffman tree for that frequency table and
// returns (a pointer to the root of) the tree.
NodePtr build_tree()
{
    HuffmanPriorityQueue queue;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char tempChar;
        int tempInt;
        cin >> tempChar;
        cin >> tempInt;
        NodePtr tmpNode = new HuffmanNode(tempInt, tempChar);
        queue.push(tmpNode);
    }

    for (int i = 0; i < n - 1; ++i)
    {
        NodePtr tmpLeft, tmpRight, p;
        tmpLeft = queue.top();
        queue.pop();
        tmpRight = queue.top();
        queue.pop();
        p = new HuffmanNode(tmpLeft->frequency + tmpRight->frequency, '\0');
        p->left = tmpLeft;
        p->right = tmpRight;
        queue.push(p);
    }

    NodePtr root;
    root = queue.top();
    queue.pop();
    return root;
}

// Returns the string obtained by decoding 'encoded_str' with the Huffman tree 'root' (or more
// specifically, the Huffman tree whose root is 'root').
string decode(NodePtr root, string encoded_str)
{
    string returnString;
    NodePtr iteration = root;
    for (unsigned int j = 0; j <= encoded_str.length(); ++j)
    {
        if (iteration->is_leaf())
        {
            returnString += iteration->letter;
            iteration = root;
        }

        if (encoded_str[j] == '0')
        {
            iteration = iteration->left;
        }
        else if (encoded_str[j] == '1')
        {
            iteration = iteration->right;
        }
    }
    return returnString;
}

// * Optional, but recommended *
// Returns true if and only if the tree 'root', contains the node with the letter 'letter'.
bool contains(NodePtr root, char letter)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->letter == letter)
    {
        return true;
    }
    bool tmpBool = contains(root->left, letter);
    if (tmpBool == true)
    {
        return true;
    }
    else
    {
        return contains(root->right, letter);
    }
}

// Returns the binary code obtained by encoding 'letter' with the Huffman tree 'root' (or more
// specifically, the Huffman tree whose root is 'root').
string encode(NodePtr root, char letter)
{
    string returnString;
    if (root->letter == letter)
    {
        return "";
    }
    if (contains(root->left, letter))
    {
        returnString += '0';
        returnString += encode(root->left, letter);
        return returnString;
    }
    else
    {
        returnString += '1';
        returnString += encode(root->right, letter);
        return returnString;
    }
}

// Frees (deallocates) the memory allocated for the Huffman tree 'root' (or more
// specifically, the Huffman tree whose root is 'root').
void free_memory(NodePtr root)
{
    if (root == NULL)
    {
        return;
    }
    free_memory(root->left);
    free_memory(root->right);
    delete root;
}

int main()
{
    // Read frequency table and build Huffman tree.
    NodePtr huffman = build_tree();
    //print_tree(huffman);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string inputString, outputString;
        getline(cin, inputString);
        for (unsigned int j = 0; j <= inputString.length(); ++j)
        {
            outputString += encode(huffman, inputString[j]);
        }
        cout << outputString << endl;
    }


    // Free the allocated memory.
    free_memory(huffman);

    return 0;
}

