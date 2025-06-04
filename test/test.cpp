#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <iostream>
#include "../src/AVL.h"

using namespace std;
// g++ test.cpp catch_amalgamated.cpp ../src/AVL.cpp -I../src -o test

TEST_CASE("Five Incorrect Commands", "[commands]"){
	// Five incorrect commands
    AVL tree;
    CHECK(tree.insert("A F D F D", 123) == false);
	  CHECK(tree.insert("A11y", -1) == false);
    CHECK(tree.insert("Ally", 12345678) == true);
    CHECK(tree.insert("!", 12346688) == false);
    CHECK(tree.insert("", 12 ) == false);
    CHECK(tree.insert(" ", 12) == false);

}

TEST_CASE("Rotation Test", "[rotations]"){
	// you can also use "sections" to share setup code between tests, for example:
	AVL tree;
  tree.insert("Ally", 12345678);
  tree.insert("Brandon", 13345678);
  tree.insert("Chris", 14235689);
  tree.insert("Dan", 15234678);
  tree.insert("Evan", 16234578);
  tree.insert("Fred", 17234567);
  //left rotations
  tree.printPostorder();

  AVL tree2;
  tree.insert("Fred", 17234567);
  tree.insert("Evan", 16234578);
  tree.insert("Dan", 15234678);
  tree.insert("Chris", 14235689);
  tree.insert("Brandon", 13345678);
  tree.insert("Ally", 12345678);
  //right rotations
  tree2.printPostorder();

  AVL tree3;
  tree.insert("Ally", 12345678);
  tree.insert("Chris", 14235689);
  tree.insert("Brandon", 13345678);
  //right-left rotation
  tree3.printPostorder();

  AVL tree4;
  tree.insert("Chris", 14235689);
  tree.insert("Ally", 12345678);
  tree.insert("Brandon", 13345678);
  //left-right rotation
  tree.printPostorder();

	// each section runs the setup code independently to ensure that they don't affect each other
} 

//TEST_CASE("Insert 100 Nodes", "[100 nodes]"){
//	// Five incorrect commands
//    AVL tree;
//    vector<string> vec;
//    bool added = false;
//    int count = 0;
//
//    for(int i = 10000000; i < 10000100; i++) {
//      added = tree.insert("NAME", std::to_string(i));
//      vec.push_back(std::to_string(i));
//      if(added) {
//        count++;
//      }
//    }
//    for(int i = 0; i < 10; i *= 2) {
//      added = tree.remove_ID(vec[i]);
//      vec.erase(find(vec.begin(), vec.end(), vec[i]));
//    }
//    
//}




//TEST_CASE("Example BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
//}
