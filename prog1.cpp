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
    avl a1;
   /* 
    a1.avlInsert2("hello");
    a1.avlInsert2("hello");
    a1.avlInsert2("hello");
    a1.avlInsert2("ahoy");
    a1.avlInsert2("ahoy");
    a1.avlInsert2("ahoy");
    a1.avlInsert2("ahoy");
    a1.avlInsert2("howdy");
    cout<<a1.maxHeight()<<endl;
    //a1.avlRangeSearch("b","y");
    //a1.printPreOrder();
 */
   
    ifstream myfile;
    ///autograder/submission/PA1_dataset.txt

    myfile.open("/autograder/submission/PA1_dataset.txt");
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

