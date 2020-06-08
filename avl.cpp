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
void avl::printPreOrder(){ //const {
    printPreOrder(root);
}
void avl::printPreOrder(Node *n){ //const {
    if(n!=NULL){
        //cout<<"("<<n->word.first<<":"<<n->word.second;
        cout<<"("<<n->word<<":"<<n->counter;
        }else{
            cout<<"(";
            return;
            }
    printPreOrder(n->left);
    printPreOrder(n->right);
    cout<<")";
}

int avl::getBalance(Node *n)  
{  
    if (n == NULL)  
        return 0;  
    return height(n->left) - height(n->right);  
}  

//Height of a singleton node is 1
int avl::height(Node* n){
    if(n==NULL){return 0;}
    if( height(n->left)+1 > height(n->right)+1){
        return height(n->left)+1;
    }else{
        return height(n->right)+1;
     }
    
    }

int avl::height(){
    return height(root);
    }

avl::Node* avl::rightRotate(Node *y)  
{  
    //cout<<"Doing a right rotation"<<endl;
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Return new root  
    return x;  
}  

avl::Node* avl::leftRotate(Node *x)
{
    //cout<<"Doing a left rotation"<<endl; 
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Return new root
    return y;
}



// insert value in tree; return false if duplicate
void avl::avlInsert(string name) {
    root=insert(name, root);
    return;
}

// recursive helper for insert
avl::Node* avl::insert(string name, Node *n) {
    if (n == NULL){  
        Node* temp= new Node;
        temp->word=name;
        temp->counter=1;
        //temp->word.first=name;
        //temp->word.second=1;
        temp->left = NULL;
        temp->right = NULL;
        //cout<< temp->word.first<< " inserted, new count = "<<temp->word.second<<endl;
        cout<< temp->word<<" inserted, new count = "<<temp->counter<<endl;
        return temp;
    }
    
    if (name < n->word/*.first*/)  
        n->left = insert(name, n->left);  
    else if (name > n->word/*.first*/)  
        n->right = insert(name, n->right);  
    else{   
        //n->word.second=n->word.second+1; 
        //cout<< n->word.first<< " inserted, new count = "<<n->word.second<<endl;
        n->counter=n->counter+1;
        cout<<n->word<<" inserted, new count = "<<n->counter<<endl;
        return n;  
  }
    
    int balance = getBalance(n);
    //cout<<"balance at this node is "<<balance<<endl;dd
  
    // Left Left Case  
    if (balance > 2 && name < n->left->word  /*word.first*/  )  
        return rightRotate(n);  
  
    // Right Right Case  
    if (balance < -2 && name > n->right->word /*word.first*/)  
        return leftRotate(n);  
  
    // Left Right Case  
    if (balance > 2 && name > n->left->word  /*word.first*/)  
    {  
        n->left = leftRotate(n->left);  
        return rightRotate(n);  
    }  
  
    // Right Left Case  
    if (balance < -2 && name < n->right->word  /*word.first*/)  
    {  
        n->right = rightRotate(n->right);  
        return leftRotate(n);  
    }  
  
    // return the (unchanged) node pointer *
    return n;  
}

void avl::avlRangeSearch(string begin, string end){
    printRangeSearch(root, begin, end);
    }

void avl::printRangeSearch(Node* n, string begin, string end) const{
    if(n==NULL){
        return;}

    if( /*n->word.first.*/ n->word.compare(begin)>0){
        printRangeSearch(n->left,begin,end);
        }
    if( /*n->word.first.*/  n->word.compare(begin)>=0 && /*n->word.first.*/ n->word.compare(end)<=0){
        //cout<<n->word.first<<endl;
        cout<<n->word<<endl;
        }
    if(/*n->word.first*/    n->word.compare(end)<0){
        printRangeSearch(n->right,begin,end);
        }

    }


avl::Node* avl::getNodeFor(string name, Node* n) const{
    if(n==NULL){return 0;}
    while(n!=NULL){
        if(/*n->word.first*/ n->word==name){
           return n;
           }
        if(name.compare(n->word/*.first*/)<0){
           return getNodeFor(name,n->left);}
        if(name.compare(n->word/*.first*/)>0){
           return getNodeFor(name,n->right);}
           }     
  return NULL;
   }

void avl::avlSearch(string name) const {
    Node* p1=getNodeFor(name,root);
    if(p1){
        cout<<p1->word/*.first*/<<" found, count = "<< /*p1->word.second*/p1->counter<<endl;
        return;
        //return true;
        }
    else{
        cout<<name<<" not found"<<endl;
        return;
        //return false;
        }
}


void avl::avlInsert2(string name) {
    root=insert2(name, root);
    return;
}


avl::Node* avl::insert2(string name, Node *n) {
    if (n == NULL){  
        Node* temp= new Node;
        temp->word=name;
        temp->counter=1;
        //temp->word.first=name;
        //temp->word.second=1;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    
    if (name < n->word/*.first*/)  
        n->left = insert2(name, n->left);  
    else if (name > n->word/*.first*/)  
        n->right = insert2(name, n->right);  
    else{   
        n->counter=n->counter+1;
        //n->word.second=n->word.second+1; 
        return n;  
  }
  
    int balance = getBalance(n);
    //cout<<"balance at this node is "<<balance<<endl;
  
    // Left Left Case  
    if (balance > 2 && name < n->left->word/*.first*/)  
        return rightRotate(n);  
  
    // Right Right Case  
    if (balance < -2 && name > n->right->word/*.first*/)  
        return leftRotate(n);  
  
    // Left Right Case  
    if (balance > 2 && name > n->left->word/*.first*/)  
    {  
        n->left = leftRotate(n->left);  
        return rightRotate(n);  
    }  
  
    // Right Left Case  
    if (balance < -2 && name < n->right->word/*.first*/)  
    {  
        n->right = rightRotate(n->right);  
        return leftRotate(n);  
    }  

    return n;
}
