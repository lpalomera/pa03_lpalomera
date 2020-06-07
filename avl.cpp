//avl.cpp
#include "avl.h"
#include <iostream>
using namespace std;

// constructor sets up empty tree
avl::avl() : root(0) { }

// destructor deletes all nodes
avl::~avl() {
    clear(root);
}

// recursive helper for destructor
void avl::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// print tree data in-order, with helper
void avl::printInOrder() const {
    printInOrder(root);
}
void avl::printInOrder(Node *n) const {
    if (n){
    printInOrder(n->left);
    cout << n->word.first <<endl;
    printInOrder(n->right);
    }
}

// insert value in tree; return false if duplicate
void avl::avlInsert(string name) {
    // handle special case of empty tree first
    /*
    if (!root) {
	root = new Node(name);
	root->word.second=root->word.second+1;
    cout<< root->word.first<< " inserted, count = "<<root->word.second<<endl;
    return;
    }*/
    // otherwise use recursive helper
    insert(name, root);
    return;
}

// recursive helper for insert (assumes n is never 0)
avl::Node* avl::insert(string name, Node *n) {
   // 1. Perform the normal BST insertion 
    if (n == NULL){  
        Node* temp= new Node;
        temp->word.first=name;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    /*
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    // 2. Update height of this ancestor node 
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    // 3. Get the balance factor of this ancestor  
    //    node to check whether this node became  
    //    unbalanced 
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    // return the (unchanged) node pointer *
    return node;  
*/


    /*
    if (name == n->word.first){
	n->word.second=n->word.second+1;
    cout<< n->word.first<< " inserted, new count = "<<n->word.second<<endl;
    return;
    }
    //return false;
    if (name.compare(n->word.first)<0) {
	if (n->left)
	    return insert(name, n->left);
	else {
        n->left = new Node(name);
	    n->left->parent = n;
	    n->left->word.second=n->left->word.second+1;
        cout<< n->left->word.first<< " inserted, new count = "<<n->left->word.second<<endl;
        return;
        //return true;
	}
    }
    else {
	if (n->right)
	    return insert(name, n->right);
	else {
	    n->right = new Node(name);
	    n->right->parent = n;
        n->right->word.second=n->right->word.second+1;
        cout<< n->right->word.first<< " inserted, new count = "<<n->right->word.second<<endl;
        return;
        //return true;
        }
    }
    */
    Node* hi=NULL;
    return hi;
}
