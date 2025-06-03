#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <iostream>
#include "../src/AVL.h"

using namespace std;
// g++ test.cpp catch_amalgamated.cpp ../src/AVL.cpp -I../src -o test

TEST_CASE("Five Incorrect Commands", "[commands]"){
	// Five incorrect commands
    AVL tree;
    REQUIRE(tree.insert("A F D F D", "123"));
	  REQUIRE(tree.insert("A11y", "-1"));
    REQUIRE(tree.insert("Ally", "123456789"));
    REQUIRE(tree.insert("!", "!"));
    REQUIRE(tree.insert("", ""));
    REQUIRE(tree.insert(" ", " "));

}

TEST_CASE("Rotation Test", "[rotations]"){
	// you can also use "sections" to share setup code between tests, for example:
	AVL tree;
  REQUIRE(tree.insert("Ally", "12345678"));
  REQUIRE(tree.insert("Brandon", "13345678"));
  REQUIRE(tree.insert("Chris", "14235689"));
  REQUIRE(tree.insert("Dan", "15234678"));


	//SECTION("num is 3") {
	//	int num = one + 2;
	//	REQUIRE(num == 3);
	//};

	// each section runs the setup code independently to ensure that they don't affect each other
} 

TEST_CASE("Insert 100 Nodes", "[100 nodes]"){
	// Five incorrect commands
    AVL tree;
    vector<string> vec;
    bool added = false;
    int count = 0;

    for(int i = 10000000; i < 10000100; i++) {
      added = tree.insert("NAME", std::to_string(i));
      vec.push_back(std::to_string(i));
      if(added) {
        count++;
      }
    }
    for(int i = 0; i < 10; i *= 2) {
      added = tree.remove_ID(vec[i]);
      vec.erase(find(vec.begin(), vec.end(), vec[i]));
    }
    
}




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
