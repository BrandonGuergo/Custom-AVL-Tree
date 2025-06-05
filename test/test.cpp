// BRANDON GUERGO ; UFID: 3092-7636

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <iostream>
#include "../src/AVL.h"

using namespace std;
// g++ test.cpp catch_amalgamated.cpp ../src/AVL.cpp -I../src -o test

TEST_CASE("Five Incorrect Commands", "[commands]"){
	// Five incorrect commands
  AVL tree;
  CHECK(tree.insert("Ally", "12345678") == true);
  CHECK(tree.insert("Brandon", "22222222") == true);
  CHECK(tree.insert("Chris", "33333333") == true);
  CHECK(tree.insert("Ally", "87654321") == true);
  CHECK(tree.insert("Brandon", "22222222") == false);
  CHECK(tree.insert("A!", "123") == false);
  CHECK(tree.insert("AFN2   ", "12345678") == false);
  CHECK(tree.insert(" ___", " 9X") == false);
  CHECK(tree.insert("", "") == false);

}

TEST_CASE("Right Rotation", "[rotation]"){
  AVL tree;
  tree.insert("C", "33333333");
  tree.insert("B", "22222222");
  tree.insert("A", "11111111");
  std::vector<string> actualOutput = tree.printPreorder();
  std::vector<string> expectedOutput = {"A", "B", "C"};
  REQUIRE(expectedOutput.size() == actualOutput.size());
  REQUIRE(actualOutput == expectedOutput);
}

//Left Rotation
TEST_CASE("Left Rotation", "[rotation]"){
  AVL tree; 
  tree.insert("A", "11111111");
  tree.insert("B", "22222222");
  tree.insert("C", "33333333");
  std::vector<string> actualOutput = tree.printPreorder();
  std::vector<string> expectedOutput = {"A", "B", "C"};
  REQUIRE(expectedOutput.size() == actualOutput.size());
  REQUIRE(actualOutput == expectedOutput);
}

//Left-Right Rotation
TEST_CASE("Left-Right Rotation", "[rotation]"){
  AVL tree; 
  tree.insert("C", "33333333");
  tree.insert("A", "11111111");
  tree.insert("B", "22222222");
  std::vector<string> actualOutput = tree.printPreorder();
  std::vector<string> expectedOutput = {"A", "B", "C"};
  REQUIRE(expectedOutput.size() == actualOutput.size());
  REQUIRE(actualOutput == expectedOutput);
}

//Right-Left Rotation
TEST_CASE("Right-Left Rotation", "[rotation]"){
  AVL tree; 
  tree.insert("A", "11111111");
  tree.insert("C", "33333333");
  tree.insert("B", "22222222");
  std::vector<string> actualOutput = tree.printPreorder();
  std::vector<string> expectedOutput = {"A", "B", "C"};
  REQUIRE(expectedOutput.size() == actualOutput.size());
  REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("100 Nodes", "[100 node test]"){
  AVL tree; 
  std::string str_number;
  std::vector<string> expectedOutput;
  for(int i = 10000000; i < 10000100; i++) {
    str_number = std::to_string(i);
    tree.insert(" ", str_number);
    expectedOutput.push_back(str_number);
  }
  std::vector<string> actualOutput = tree.printInorder_UFID();
  REQUIRE(expectedOutput.size() == actualOutput.size());
  REQUIRE(actualOutput == expectedOutput);
  for(int i = 0; i < 10; i++) {
    str_number = expectedOutput.back();
    tree.remove_ID(expectedOutput.back());
    expectedOutput.pop_back();
  }
  actualOutput = tree.printInorder_UFID();
  REQUIRE(expectedOutput.size() == actualOutput.size());
  REQUIRE(actualOutput == expectedOutput);
}
