#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};
  
// A class for BST
class BST 
{ 

    public: 
        BST(){root_ = NULL;};
        BST(vector<int> init_v);
        ~BST(){};

        void push(int key); // insert a key inside Tree
        bool find(int key); // Return True if the key inside Tree
        bool erase(int key); // Remove the key from the Tree; or return false
        vector<int> print();
        
    private:
        TreeNode * root_;
}; 

#endif