// avl.h
// AVL Tree header file for CS 130A lab
#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

class avl {
    public:
    //constructor
    avl();
    
    // destructor
    ~avl();
    
    //insert
    void avlInsert(std::string name); 
    
    //insert(no cout)
    void avlInsert2(std::string name);

    //search (contains)
    void avlSearch(std::string name) const;
    
    //void bstRangeSearch();
    void avlRangeSearch(string begin, string end);
    
    //prints preorder traversal
    void printInOrder() const;   

    // returns the predecessor value of the given value or 0 if there is none
    string getPredecessor(string name) const;
    
    // returns the successor value of the given value or 0 if there is none
    string getSuccessor(string name) const; 

    private:  
    
    struct Node {
	std::pair<std::string, int> word;
	Node *left, *right; //, * parent;
	// useful constructor:
    Node(string s="") :  left(0), right(0){//, parent(0) {
        word.first=s;
        }
    };

    // just one instance variable (pointer to root node):
    Node *root;
    
    //returns the node for a given value or NULL if none exists
    Node* getNodeFor(string name, Node* n) const; 
    
    void clear(Node *n); // for destructor
    
    //Helper function for insert with cout
    Node* insert(string name, Node *n);
   
    //Helper function for insert without cout
    void insert2(string name, Node *n);

    //Helper function for printInOrder
    void printInOrder(Node *n) const;

    //Helper function for print Range Search
    void printRangeSearch(Node* n,  string begin, string end) const;

    // returns the Node containing the successor of the given value
    Node* getSuccessorNode(string value) const;
    
    // returns the Node containing the predecessor of the given value i
    Node* getPredecessorNode(string value) const;
};




#endif
