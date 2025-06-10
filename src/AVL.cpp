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
    AVL::nodeCount++;
    root = new Node(name, ufid);
    return root;
  }
  //Insert accordingly based on UFID integer value
  root = insert_Recursively(root, name, ufid);
  cout << "successful" << "\n";
  attempt = true;
  return root;
}

AVL::Node* AVL::insert_Recursively(Node* node, std::string name, std::string ufid) {
  if(!node) {
    AVL::nodeCount++;
    return new Node(name, ufid);
  }

  if(ufid < node->ufid) {
    node->left = insert_Recursively(node->left, name, ufid);
  }
  else {
    node->right = insert_Recursively(node->right, name, ufid);
  }

  node->height = 1 + max(height(node->left), height(node->right));
  return balance(node);
}

AVL::Node* AVL::rotateLeft(Node* node){
  Node* grandchild = node->right->left;
  Node* newParent = node->right;
  newParent->left = node;
  node->right = grandchild;

  node->height = 1 + max(height(node->left), height(node->right));
  newParent->height = 1 + max(height(newParent->left), height(newParent->right));
  return newParent;
}

AVL::Node* AVL::rotateRight(Node* node){
  Node* grandchild = node->left->right;
  Node* newParent = node->left;
  newParent->right = node;
  node->left = grandchild;

  node->height = 1 + max(height(node->left), height(node->right));
  newParent->height = 1 + max(height(newParent->left), height(newParent->right));
  return newParent;
}

AVL::Node* AVL::balance(Node* node) {
  int bal = getBalance(node);
  if(bal > 1) {
    if(getBalance(node->left) < 0) {
      node->left = rotateLeft(node->left);
    }
    return rotateRight(node);
  }

  if (bal < -1) {
    if(getBalance(node->right) > 0) {
      node->right = rotateRight(node->right);
    }
    return rotateLeft(node);
  }
  return node;
}

int AVL::getBalance(Node* node) {
  if(!node) {
    return 0;
  }
  int leftHeight = node->left ? node->left->height : 0;
  int rightHeight = node->right ? node->right->height : 0;
  int balance = leftHeight - rightHeight;
  return balance;
}

int AVL::height(Node* node) { 
  if (!node) {
    return 0;
  }
  return node->height;
}

AVL::Node* AVL::remove_ID_Helper(Node* root, std::string ufid, bool& attempt){
  if (!root) {
    attempt = false;
    return root;
  }
  
  if(root->ufid > ufid) {
    root->left = remove_ID_Helper(root->left, ufid, attempt);
  }
  else if (root->ufid < ufid) {
    root->right = remove_ID_Helper(root->right, ufid, attempt);
  }
  else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      attempt = true;
      AVL::nodeCount--;
      return nullptr;
    }
    else if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      attempt = true;
      AVL::nodeCount--;
      return temp;
    }

    else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      attempt = true;
      AVL::nodeCount--;
      return temp;
    }

    else {
      Node* successor = successor_Helper(root->right);
      root->ufid = successor->ufid;
      root->name = successor->name;
      bool successorRemoved = true;
      root->right = remove_ID_Helper(root->right, successor->ufid, successorRemoved);  
      attempt = true;
    }
      
  }
  return root;
}

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

void AVL::traverseInorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traverseInorder(root->left, names);
  names.push_back(root->name);
  traverseInorder(root->right, names);
}

//oid AVL::inorder_Delete(Node* root, vector<string>& names, int n, bool& deleted, int& current) {
// if(!root || deleted) { 
//   return;
// }
// inorder_Delete(root->left, names, n, deleted, current);
// if (deleted) return;
// if (current == n) {
//   names.push_back(root->name);
//   string ufidDelete = root->ufid;
//   deleted = remove_ID(ufidDelete);
//   current++;
//   return;
// }
// names.push_back(root->name);
// current++;
// inorder_Delete(root->right, names, n, deleted, current);
// return;
//

void AVL::traverseInorderUFID(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traverseInorderUFID(root->left, names);
  names.push_back(root->ufid);
  traverseInorderUFID(root->right, names);
}

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

void AVL::traversePreorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  names.push_back(root->name);
  traversePreorder(root->left, names);
  traversePreorder(root->right, names);
}

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

void AVL::traversePostorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traversePostorder(root->left, names);
  traversePostorder(root->right, names);
  names.push_back(root->name);
}

void AVL::traversePostorder_Delete(Node* root) {
  if (!root) {
    return;
  }
  traversePostorder_Delete(root->left);
  traversePostorder_Delete(root->right);
  delete root;
}

void AVL::printPostorder_Helper(Node* root){
  vector<string> names;
  traversePostorder(root, names);
  for(size_t i = 0; i < names.size(); i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << names[i];
  }
  cout << endl;
}

int AVL::printLevelCount_Helper(Node* root)
{
    if(!root) {
      return 0;
    }
    return root->height;
}

AVL::Node* AVL::successor_Helper(AVL::Node* node) { //FIX INORDER SUCCESSOR TRAVERSAL FOR GENERAL CASE
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

string AVL::id_Location(AVL::Node* root, bool& deleted, int n, int& current) { //returns the ufid string at the nth location
  if(!root) { 
    return "";
  }
  string left = id_Location(root->left, deleted, n, current);
  if(!left.empty()) {
    return left;
  }

  if(current == n) {
    current++;
    return root->ufid;
  }
  current++;

  string right = id_Location(root->right, deleted, n, current);
  return right;
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

int AVL::printLevelCount(){
  return AVL::printLevelCount_Helper(this->root);
}

bool AVL::removeInorder(int n){
  bool deleted = false;
  string idFound;
  int current = 0;
  idFound = id_Location(root, deleted, n, current);
  deleted = remove_ID(idFound);
  return deleted;
}








//TODO
//PRINT LEVEL COUNT
//REMOVE INORDER
//ROTATIONS