#include "solution.h"
#include<iostream>
#include <queue>

using namespace std;

BST::BST(vector<int> init_v)
{
    for(int i: init_v){push(i);}
}

TreeNode * recursive_find(TreeNode* node, int key)
{
    if(node == NULL){return NULL;}
    else if (key < node->val){
        return recursive_find(node->left, key);
    }
    else if (key > node->val){
        return recursive_find(node->right, key);
    }
    else{return node;}
}

TreeNode * FindMin(TreeNode* node)
{
    if (node == NULL){return NULL;}
    else if (node->left == NULL){return node;}
    else{return FindMin(node->left);}
}

TreeNode * recursive_remove(int key, TreeNode * node)
{
    TreeNode * n;
    if(node == NULL){return NULL;}
    else if (key < node->val){
        node->left = recursive_remove(key, node->left);
    }
    else if (key > node->val){
        node->right = recursive_remove(key, node->right);
    }
    else if (node->left && node->right){
        n = FindMin(node->right);
        node->val = n->val;
        node->right = recursive_remove(node->val, node->right);
    }
    else{
        n = node;
        if (node->left == NULL){
            node = node->right;
        }
        else if (node->right == NULL){
            node = node->left;
        }
    }
    return node;
}

bool BST::erase(int key)
{
    TreeNode * node = recursive_find(root_,key);
    if (node != NULL){
        TreeNode * node = recursive_remove(key, root_);
        return true;
    }else{return false;}
}


bool BST::find(int key)
{
    TreeNode * node = recursive_find(root_,key);
    if(node != NULL){
        return true;
    }else{return false;}
}

TreeNode * compare_insert(TreeNode * n, int key)
{
    if( n == NULL){
        n = new TreeNode(key);
    }
    else if(key < n->val){
        n->left = compare_insert(n->left, key);
    }
    else if(key > n->val){
        n->right = compare_insert(n->right, key);
    }
    return n;
}

void BST::push(int key)
{
    root_ = compare_insert(root_, key);
}


vector<int> BST::print()
{
    vector<int> output;
    if(root_ == NULL){
        return output;
    }

    queue<TreeNode *> q;

    q.push(root_);

    while(!q.empty()){
        TreeNode * node = q.front();
        output.push_back(node->val);
        cout << node->val << " ";
        q.pop();

        if(node->left!=NULL){
            q.push(node->left);
        }

        if(node->right!=NULL){
            q.push(node->right);
        }
    }
    cout << endl;
    return output;

}