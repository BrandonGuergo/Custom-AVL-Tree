#include "AVL.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>

//PRIVATE
bool AVL::insertHelper(Node* root, std::string name, std::string ufid){
    return true;
}

void AVL::remove_IDHelper(Node* root, std::string ufid){

}

void AVL::search_IDHelper(Node* root, std::string ufid){

}

void AVL::search_nameHelper(Node* root, std::string name){

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


//PUBLIC  
bool AVL::insert(std::string name, std::string ufid){
  return false;
}

void AVL::remove_ID( std::string ufid){

}

void AVL::search_ID(std::string ufid){

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


