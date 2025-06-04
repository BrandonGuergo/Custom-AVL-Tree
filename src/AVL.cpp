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
  //First, check string name
  regex name_regex("^[A-Za-z ]+$");
  if (!regex_match(name, name_regex)) {
    attempt = false;
    std::cout << "Unsuccessful" << "\n";
    return root;
  }
  
  //Second check ufid
  regex eight_digs("^\\d{8}$");
  if(!regex_match(ufid, eight_digs)){
    attempt = false;
    cout << "Unsuccessful" << "\n";
    return root;
  }

  //Insert
  Node* temp = root;
  if (root == nullptr) {
    cout << "Successful" << "\n";
    attempt = true;
    return new Node(name, ufid);
  }

  while(true) {
    if(temp->ufid < ufid) {
      if(temp->right == nullptr) {
        Node* newNode = new Node(name, ufid);
        temp->right = newNode;
        break;
      }
      temp = temp->right;
    }
    else if(temp->ufid > ufid) {
      if(temp->left == nullptr) {
        Node* newNode = new Node(name, ufid);
        temp->left = newNode;
        break;
      }
      temp = temp->left;
    }
  }
  cout << "Successful" << "\n";
  return root;
}

void AVL::remove_ID_Helper(Node* root, std::string ufid){

}

void AVL::search_ID_Helper(Node* root, std::string ufid){

}

void AVL::search_Name_Helper(Node* root, std::string name){

}

void AVL::traverseInorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  traverseInorder(root->left, names);
  names.push_back(root->name);
  traverseInorder(root->right, names);
}

void AVL::printInorder_Helper(Node* root){
  vector<string> names;
  traverseInorder(root, names);
  for(size_t i = 0; i < names.size(); i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << names[i];
  }
  cout << endl;
}

void AVL::traversePreorder(Node* root, vector<string>& names) {
  if (!root) {
    return;
  }
  names.push_back(root->name);
  traversePreorder(root->left, names);
  traversePreorder(root->right, names);
}

void AVL::printPreorder_Helper(Node* root){
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

void AVL::printPostorder_Helper(Node* root){
    printPostorder_Helper(this->root);
}

void AVL::printLevelCount_Helper(Node* root)
{
    printLevelCount_Helper(this->root);
}

void AVL::removeInorder_Helper(Node* root, int n){

}
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

int AVL::height(Node* root) {
  //base case
  if(!root) {
    return -1;
  }
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  return max(leftHeight, rightHeight) + 1;
}



//PUBLIC  
bool AVL::insert(std::string name, std::string ufid){
  bool attempt = false;
  root = AVL::insert_Helper(root, name, ufid, attempt);
  return attempt;
}

bool AVL::remove_ID(std::string ufid){
  return false;
}

void AVL::search_ID(std::string ufid){

}

void AVL::search_Name(std::string name){

}

void AVL::printInorder(){
  AVL::printInorder_Helper(this->root);
}

void AVL::printPreorder(){
  AVL::printPreorder_Helper(this->root);
}

void AVL::printPostorder(){
  AVL::printPostorder_Helper(this->root);
}

void AVL::printLevelCount(){
  AVL::printLevelCount_Helper(this->root);
}

void AVL::removeInorder(int n){

}


