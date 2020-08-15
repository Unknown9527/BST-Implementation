#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

// test push and find
TEST(TEST0, TEST0) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(15); 
  b.push(5); 
  b.push(4); 
  b.push(45); 

  //            3
  //        2       15
  //              5    45
  //            4
  // vector<int> result1 = {3,2,15,5,45,4};

  int result1 = 1;
  int result0 = 0;
  EXPECT_EQ(b.find(3), result1);
  EXPECT_EQ(b.find(2), result1);
  EXPECT_EQ(b.find(15), result1);
  EXPECT_EQ(b.find(5), result1);
  EXPECT_EQ(b.find(45), result1);
  EXPECT_EQ(b.find(4), result1);
  EXPECT_EQ(b.find(999), result0);
}

// test erase and find
TEST(TEST1, TEST1) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(15); 
  b.push(5); 
  b.push(4); 
  b.push(45); 

  b.erase(5);
  b.erase(4);
  b.erase(45);

  //            3
  //        2       15
  //              5    45
  //            4
  // vector<int> result1 = {3,2,15,5,45,4};

  int result1 = 1;
  int result0 = 0;
  EXPECT_EQ(b.find(3), result1);
  EXPECT_EQ(b.find(2), result1);
  EXPECT_EQ(b.find(15), result1);
  EXPECT_EQ(b.find(5), result0);
  EXPECT_EQ(b.find(4), result0);
  EXPECT_EQ(b.find(45), result0);
  EXPECT_EQ(b.find(999), result0);
}

// use print() to test push
TEST(TEST2, TEST2) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(15); 
  b.push(5); 
  b.push(4); 
  b.push(45); 
  b.print();
  //            3
  //        2       15
  //              5    45
  //             4
  vector<int> result2 = {3,2,15,5,45,4};
  EXPECT_EQ(b.print(), result2);

}

// use print() to test erase
TEST(TEST3, TEST3) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(15); 
  b.push(5); 
  b.push(4); 
  b.push(45); 

  //            3
  //        2       15
  //              5    45
  //             4

  b.erase(3);
  b.print();
  vector<int> result3 = {4,2,15,5,45};
  EXPECT_EQ(b.print(), result3);

}


TEST(TEST4, TEST4) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(15); 
  b.push(6); 
  b.push(45); 
  b.push(20); 
  b.print();
  //            3
  //        2       15
  //              6    45
  //                  20
  vector<int> result4 = {3,2,15,6,45,20};
  EXPECT_EQ(b.print(), result4);

  b.erase(3);
  b.print();
  vector<int> result5 {6,2,15,45,20};
  EXPECT_EQ(b.print(), result5);

}



