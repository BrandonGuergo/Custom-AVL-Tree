#include "AVL.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

//PRIVATE
bool AVL::insertHelper(Node* root, std::string name, int ufid){
  //first order of business: check regex

  return true;
}

void AVL::remove_IDHelper(Node* root, int ufid){

}

void AVL::search_IDHelper(Node* root, int ufid){

}

void AVL::search_nameHelper(Node* root, int name){

}

void AVL::Inorder(Node* root){
  if(root == NULL){
    return;
  }
  else
  {
      Inorder(root->left);
      std::cout << root->name << " ";
      Inorder(root->right);
  }
}

void AVL::Preorder(Node* root){
    Preorder(this->root);
}

void AVL::Postorder(Node* root){
    Postorder(this->root);
}

void AVL::LevelCount(Node* root)
{
    LevelCount(this->root);
}

void AVL::removeInorderHelper(Node* root, int n){

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
bool AVL::insert(std::string name, int ufid){
  AVL::insertHelper(root, name, ufid);
  return false;
}

bool AVL::remove_ID(int ufid){

}

void AVL::search_ID(int ufid){

}

void AVL::search_name(std::string name){

}

void AVL::printInorder(){
  Inorder(this->root);
}

void AVL::printPreorder(){
  Preorder(this->root);
}

void AVL::printPostorder(){
  Postorder(this->root);
}

void AVL::printLevelCount(){
  LevelCount(this->root);
}

void AVL::removeInorder(int n){

}


