#include "twoFive.h"
#include "avl.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    //cout<<"Henlo World!"<<endl;
    avl a1;
    a1.avlInsert("hello");
    a1.printInOrder();
    return 0;
    }
