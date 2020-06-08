#include "twoFive.h"
#include "avl.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char *argv[]){
    //Program takes a while to compile
    //Not completely sure why
    avl a1;
   /* 
    a1.avlInsert2("m");
    a1.avlInsert2("h");
    a1.avlInsert2("h");
    a1.avlInsert2("z");
    a1.avlInsert2("e");
    a1.avlInsert2("f");
    a1.avlInsert2("b");
    a1.avlInsert2("a");
    //a1.avlInsert2("howdy");
    a1.avlSearch("h");
    cout<<a1.height()<<endl;
    a1.avlRangeSearch("b","y");
    a1.printPreOrder();
  */
   
    ifstream myfile;
    ///autograder/submission/PA3_dataset.txt

    myfile.open("/autograder/submission/PA3_dataset.txt");
    char output[100];
    int z=0;
    if (myfile.is_open()) {
        while (!myfile.eof() && z<9999) {
            z++;
            myfile >> output;
            a1.avlInsert2(output);
            }
    }
    myfile.close();
    cout<<a1.height()<<endl;



string parse = argv[1];
 vector<string> phrase;
 string word="";
 string::iterator it = parse.begin();
 bool statement=false;
 string x; 
 
 
 for (it; it != parse.end()+1; it++) {
   
   if(statement==true){
     if (phrase[0]=="range"){
       a1.avlRangeSearch(phrase[2],phrase[4]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="insert"){
       a1.avlInsert(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="search"){
       a1.avlSearch(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }   
     
     }
  
  if(*it==' ' || *it==',' || it==parse.end() ){ //if it has reached a space or comma,
    if(word!=" " && word!=""){
    x=word;
    phrase.push_back(x); //pushback the word and reset word
    }
    if(*it==','){          //if comma statement is complete* need to add end of statement
      statement=true;
      }
      word="";
    }
    if((*it!=' ') && (*it !=',')){
  word=word+*it;
    }
  }

  if (phrase[0]=="range"){
      a1.avlRangeSearch(phrase[2],phrase[4]);
      }
  else if(phrase[0]=="insert"){
      a1.avlInsert(phrase[1]);
      }
  else if(phrase[0]=="search"){
      a1.avlSearch(phrase[1]);
      }

    return 0;
}

