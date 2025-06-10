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
          this->height = 1;
        }
    };

    int nodeCount;

    Node* root = nullptr;

    Node* insert_Helper(Node* root, std::string name, std::string ufid, bool& attempt); 

    Node* insert_Recursively(Node* root, std::string name, std::string ufid);

    Node* remove_ID_Helper(Node* root, std::string ufid, bool& attempt);

    void search_ID_Helper(Node* root, std::string ufid, bool& found);

    void search_Name_Helper(Node* root, std::string name, bool& found);
  
    void traverseInorder(Node* root, std::vector<std::string>& names);

    //void inorder_Delete(Node* root,std::vector<std::string>& names, int n, bool& deleted, int& current);
  
    void traverseInorderUFID(Node* root, std::vector<std::string>& names);
    
    std::vector<std::string> printInorder_Helper(Node* root);

    std::vector<std::string> printInorder_UFID_Helper(Node* root);

    void traversePreorder(Node* root, std::vector<std::string>& names);

    std::vector<std::string> printPreorder_Helper(Node* root);

    void traversePostorder(Node* root, std::vector<std::string>& names);

    void traversePostorder_Delete(Node* root);

    void printPostorder_Helper(Node* root);

    int printLevelCount_Helper(Node* root);

    std::vector<std::string> removeInorder_Helper(Node* root, int n, bool& deleted);
    
    Node* rotateLeft(Node* node);

    Node* rotateRight(Node* node);

    Node* balance(Node* node);

    int getBalance(Node* node);

    int height(Node* root);

    Node* successor_Helper(Node* node);

    void search_ID_Insertion_Helper(Node* root, std::string ufid, bool& found);

    std::string id_Location(Node* root, bool& deleted, int n, int& current);
    
  
  public:

    //Constructor
    AVL() {
      root = nullptr;
      nodeCount = 0;
    }

    bool insert(std::string name, std::string ufid);

    bool remove_ID(std::string ufid);

    bool search_ID(std::string ufid);

    bool search_Name(std::string name);

    std::vector<std::string> printInorder();

    std::vector<std::string> printInorder_UFID();

    std::vector<std::string> printPreorder();

    void printPostorder();

    int printLevelCount();

    bool removeInorder(int n);

    ~AVL() {
      traversePostorder_Delete(this->root);
      this->root = nullptr;
      nodeCount = 0;
    }

};
