#include "AVL.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//CANNOT let users access memory in main!
// work in the order of insert(), traverse(), search(), remove
int main(void){
  AVL tree;
  string numCommandsStr;
  getline(cin, numCommandsStr);
  int numCommands = stoi(numCommandsStr);

  for(int i = 0; i < numCommands; i++) {
    //Capture entire input and turn into string stream
    string in;
    getline(cin, in);
    istringstream iss(in);
    
    //Read first word: the command
    string command;
    iss >> command;

    //IF-CASES FOR INPUT COMMAND
    if (command == "insert") {
      char quote;
      iss >> ws >> quote;

      string name;
      getline(iss, name, '"');

      //Capture UFID
      string ufid;
      iss >> ufid;

      tree.insert(name, ufid);
    }
    else if (command == "remove") {
        string ufid;
        iss >> ufid;
        tree.remove_ID(ufid);
    }
    else if (command == "search") {
      //Search by ID
      bool found = false;
      string name;
      string ufid;
      iss >> ws;
      //Search by name
      if (iss.peek() == '"') {
        iss.get();
        getline(iss, name, '"');
        found = tree.search_Name(name);
      } 
      else {
        iss >> ufid;
        ufid.erase(remove_if(ufid.begin(), ufid.end(), ::isspace), ufid.end());
        if(!ufid.empty() && all_of(ufid.begin(), ufid.end(), ::isdigit)) {
        found = tree.search_ID(ufid);
        }
      }
      if(!found) {
          cout << "unsuccessful" << endl;
      }
    }
    else if (command == "printInorder") {
      tree.printInorder();
    }
    else if (command == "printPreorder") {
      tree.printPreorder();
    }
    else if (command == "printPostorder") {
      tree.printPostorder();
    }
    else if (command == "printLevelCount") {
      tree.printLevelCount();
    }
    else if (command == "removeInorder") {
    }
    else {
      cout << "Invalid command" << endl;
    }
  }
  
  return 0;
}
