#include "AVL.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <regex>
#include <stack>
#include <vector>
using namespace std;


//PRIVATE
//MAIN FUNCTIONS AND HELPERS
//DONE
AVL::Node* AVL::insert_Helper(Node* root, std::string name, std::string ufid, bool& attempt){
  //First, check string name against regex
  regex name_regex("^[A-Za-z ]+$");
  if (!regex_match(name, name_regex)) {
    attempt = false;
    std::cout << "unsuccessful" << "\n";
    return root;
  }
  
  //Second, check ufid against regex
  regex eight_digs("^\\d{8}$");
  if(!regex_match(ufid, eight_digs)){
    attempt = false;
    cout << "unsuccessful" << "\n";
    return root;
  }

  //Third, check if UFID already exists in tree
  bool exists = false;
  search_ID_Insertion_Helper(root, ufid, exists);
  if (exists) {
    attempt = false;
    cout << "unsuccessful" << "\n";
    return root;
  }
  
  //Else, attempt insert
  Node* temp = root;
  if (root == nullptr) {
    cout << "successful" << "\n";
    attempt = true;
    root = new Node(name, ufid);
    return root;
  }
  //Insert accordingly based on UFID integer value
  while(true) {
    if(temp->ufid < ufid) {
      if(temp->right == nullptr) {
        Node* newNode = new Node(name, ufid);
        temp->right = newNode;
        attempt = true;
        break;
      }
      temp = temp->right;
    }
    else if(temp->ufid > ufid) {
      if(temp->left == nullptr) {
        Node* newNode = new Node(name, ufid);
        temp->left = newNode;
        attempt = true;
        break;
      }
      temp = temp->left;
    }
  }
  cout << "successful" << "\n";
  return root;
}
//DONE
AVL::Node* AVL::remove_ID_Helper(Node* root, std::string ufid, bool& attempt){
  if (!root) {
    attempt = false;
    cout << "unsuccessful" << endl;
    return root;
  }
  
  if(root->ufid > ufid) {
    root->left = remove_ID_Helper(root->left, ufid, attempt);
  }
  else if (root->ufid < ufid) {
    root->right = remove_ID_Helper(root->right, ufid, attempt);
  }
  else {
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      attempt = true;
      cout << "successful" << endl;
      return temp;
    }

    if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      attempt = true;
      cout << "successful" << endl;
      return temp;
    }

    Node* successor = successor_Helper(root);
    root->ufid = successor->ufid;
    root->right = remove_ID_Helper(root->right, successor->ufid, attempt);
  }
  return root;
}
//DONE
void AVL::search_ID_Helper(Node* root, std::string ufid, bool& found){
  if (!root || found) {
    return;
  }
  search_ID_Helper(root->left, ufid, found);
  if (found == true) {
    return;
  }
  if (root->ufid == ufid) {
    found = true;
    cout << root->name << endl;
    return;
  }
  search_ID_Helper(root->right, ufid, found);
}

void AVL::search_Name_Helper(Node* root, std::string name, bool& found){
  if (!root) {
    return;
  }
  if (root->name == name) {
    found = true;
    cout << root->ufid << endl;
  }
  search_Name_Helper(root->left, name, found);
  search_Name_Helper(root->right, name, found);
}
//Traverses inorder and returns a vector of name strings DONE
void AVL::traverseInorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traverseInorder(root->left, names);
  names.push_back(root->name);
  traverseInorder(root->right, names);
}
//Traverses inorder and returns a vector of UFID strings DONE
void AVL::traverseInorderUFID(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traverseInorderUFID(root->left, names);
  names.push_back(root->ufid);
  traverseInorderUFID(root->right, names);
}
//DONE
vector<string> AVL::printInorder_Helper(Node* root){
  vector<string> names;
  traverseInorder(root, names);
  for(size_t i = 0; i < names.size(); i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << names[i];
  }
  cout << endl;
  return names;
}

vector<string> AVL::printInorder_UFID_Helper(Node* root) {
  vector<string> names;
  traverseInorderUFID(root, names);
  for(size_t i = 0; i < names.size(); i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << names[i];
  }
  cout << endl;
  return names;
}
//DONE
void AVL::traversePreorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  names.push_back(root->name);
  traversePreorder(root->left, names);
  traversePreorder(root->right, names);
}
//DONE
vector<string> AVL::printPreorder_Helper(Node* root){
  vector<string> names;
  traversePreorder(root, names);
  for(size_t i = 0; i < names.size(); i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << names[i];
  }
  cout << endl;
  return names;
}
//DONE
void AVL::traversePostorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traversePreorder(root->left, names);
  traversePreorder(root->right, names);
  names.push_back(root->name);
}
//DONE
void AVL::printPostorder_Helper(Node* root){
  vector<string> names;
  traversePreorder(root, names);
  for(size_t i = 0; i < names.size(); i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << names[i];
  }
  cout << endl;
}

void AVL::printLevelCount_Helper(Node* root)
{
    printLevelCount_Helper(this->root);
}

void AVL::removeInorder_Helper(Node* root, int n){

}
//ROTATIONS
//DONE
AVL::Node* AVL::rotateLeft(Node* node){
  Node* grandchild = node->right->left;
  Node* newParent = node->right;
  newParent->left = node;
  node->right = grandchild;
  return newParent;
}
//DONE
AVL::Node* AVL::rotateRight(Node* node){
  Node* grandchild = node->left->right;
  Node* newParent = node->left;
  newParent->right = node;
  node->left = grandchild;
  return newParent;
}
//DONE
AVL::Node* AVL::rotateLeftRight(Node* node){
  node->left = rotateLeft(node->left);
  return rotateRight(node);
}
//DONE
AVL::Node* AVL::rotateRightLeft(Node* node){
  node->right = rotateRight(node->right);
  return rotateLeft(node);
}
//DONE
//MISCELLANEOUS FUNCTIONS AND HELPERS
int AVL::height(Node* root) {
  //base case
  if(!root) {
    return -1;
  }
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  return max(leftHeight, rightHeight) + 1;
}
//FIX INORDER SUCCESSOR TRAVERSAL FOR GENERAL CASE
AVL::Node* AVL::successor_Helper(AVL::Node* node) {
  node = node->right;
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return node;
}

void AVL::search_ID_Insertion_Helper(AVL::Node* root, std::string ufid, bool& found){
  if (!root || found) {
    return;
  }
  search_ID_Helper(root->left, ufid, found);
  if (found == true) {
    return;
  }
  if (root->ufid == ufid) {
    found = true;
    return;
  }
  search_ID_Helper(root->right, ufid, found);
}



//PUBLIC  
bool AVL::insert(std::string name, std::string ufid){
  bool attempt = false;
  root = AVL::insert_Helper(root, name, ufid, attempt);
  return attempt;
}

bool AVL::remove_ID(std::string ufid){
  bool attempt = false;
  root = remove_ID_Helper(root, ufid, attempt);
  return attempt;
}

bool AVL::search_ID(std::string ufid){
  bool found = false;
  search_ID_Helper(root, ufid, found);
  return found;
}

bool AVL::search_Name(std::string name){
  bool found = false;
  search_Name_Helper(root, name, found);
  return found;
}

std::vector<std::string> AVL::printInorder(){
  vector<string> vec;
  vec = AVL::printInorder_Helper(this->root);
  return vec;
}

std::vector<std::string> AVL::printInorder_UFID(){
  vector<string> vec;
  vec = AVL::printInorder_UFID_Helper(this->root);
  return vec;
}

std::vector<std::string> AVL::printPreorder(){
  vector<string> vec;
  vec = AVL::printPreorder_Helper(this->root);
  return vec;
}

void AVL::printPostorder(){
  AVL::printPostorder_Helper(this->root);
}

void AVL::printLevelCount(){
  AVL::printLevelCount_Helper(this->root);
}

void AVL::removeInorder(int n){

}

//TODO
//PRINT LEVEL COUNT
//REMOVE INORDER
//ROTATIONS