#pragma once
#include <string>
#include <vector>

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
          this->height = 0;
        }
    };

    Node* root = nullptr;
    //balance, id must be unique, print successful/unsuccessful, name separated by "name" quote marks
    //ufids are STRICTLY 8 digits long and must be unique, names are [a-z, A-Z, spaces]
    //must replace deleted node with inorder successor if two children
    Node* insert_Helper(Node* root, std::string name, std::string ufid, bool& attempt); 
    //no need to balance, print successful/unsuccessful, replace node with inorder successor
    //if the deleted node has two children
    void remove_ID_Helper(Node* root, std::string ufid);
    //if ID found, print name, if not print unsuccessful
    void search_ID_Helper(Node* root, std::string ufid);
    //if found print ID, if multiple names: print IDs on new lines with no spaces in the same
    //relative order as preorder traversal, if not found print unsuccessful, double quotes ""
    void search_Name_Helper(Node* root, std::string name);
    //traverse inorder
    void traverseInorder(Node* root, std::vector<std::string>& names);
    //print comma separated inorder traversal of names
    void printInorder_Helper(Node* root);
    //traverse preoder
    void traversePreorder(Node* roo, std::vector<std::string>& names);
    //print preorder comma separated traversal of names
    void printPreorder_Helper(Node* root);
    //print comma seaprated postorder traversal of names
    void printPostorder_Helper(Node* root);
    //print number of levels that exist in tree
    void printLevelCount_Helper(Node* root);
    //remove nth gatorid from the inorder traversal (n=0), if success print successful
    //no need to balance, else print unssuccessful
    void removeInorder_Helper(Node* root, int n);
    
    Node* rotateLeft(Node* node);

    Node* rotateRight(Node* node);

    Node* rotateLeftRight(Node* node);

    Node* rotateRightLeft(Node* node);

    int height(Node* root);
    
  public:

    //Constructor
    AVL() {

    }

    bool insert(std::string name, std::string ufid);

    bool remove_ID(std::string ufid);

    void search_ID(std::string ufid);

    void search_Name(std::string name);

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
