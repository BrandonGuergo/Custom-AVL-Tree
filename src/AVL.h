#pragma once
#include <string>

class AVL {
  
  private:
    //AVL Node structure
    struct Node {
        std::string name;
        std::string ufid;
        Node* left;
        Node* right;
        int height;

        Node(std::string name, std::string ufid) {
          this->name = name;
          this->ufid = ufid;
          this->left = nullptr;
          this->right = nullptr;
          this->height = 1;
        }
    };

    Node* root = nullptr;
    //balance, id must be unique, print successful/unsuccessful, name separated by "name" quote marks
    //ufids are STRICTLY 8 digits long and must be unique, names are [a-z, A-Z, spaces]
    bool insertHelper(Node* root, std::string name, std::string ufid); 
    //no need to balance, print successful/unsuccessful, replace node with inorder successor
    //if the deleted node has two children
    void remove_IDHelper(Node* root, std::string ufid);
    //if ID found, print name, if not print unsuccessful
    void search_IDHelper(Node* root, std::string ufid);
    //if found print ID, if multiple names: print IDs on new lines with no spaces in the same
    //relative order as preorder traversal, if not found print unsuccessful, double quotes ""
    void search_nameHelper(Node* root, std::string name);
    //print comma separated inorder traversal of names
    void Inorder(Node* root);
    //print preorder comma separated traversal of names
    void Preorder(Node* root);
    //print comma seaprated postorder traversal of names
    void Postorder(Node* root);
    //print number of levels that exist in tree
    void LevelCount(Node* root);
    //remove nth gatorid from the inorder traversal (n=0), if success print successful
    //no need to balance, else print unssuccessful
    void removeInorderHelper(Node* root, int n);
    
    
  public:

    //Constructor
    AVL() {

    }

    bool insert(std::string name, std::string ufid);

    void remove_ID(std::string ufid);

    void search_ID(std::string ufid);

    void search_name(std::string name);

    void printInorder();

    void printPreorder();

    void printPostorder();

    void printLevelCount();

    void removeInorder(int n);
    //destructor
    ~AVL() {
      //use postorder traversal to delete nodes
    }

};
