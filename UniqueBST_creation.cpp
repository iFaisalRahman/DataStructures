/*

95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:[
			[1,null,3,2],
			[3,2,null,1],
			[3,1,null,null,2],
			[2,1,3],
			[1,null,2,null,3]
		]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

			1         3     3      2      1
			\       /     /      / \      \
			3     2     1      1   3      2
			/     /       \                 \
			2     1         2                 3

*/
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

void generateTreesHelper(int start, int end, vector<TreeNode*>& treeList)
{
	if (start > end)
	{
		treeList.push_back(NULL);
		return;
	}

	for (int i = start; i <= end; i++)
	{
		vector<TreeNode*> rightSubTreeList, leftSubTreeList;
		generateTreesHelper(start, i - 1, leftSubTreeList);
		generateTreesHelper(i + 1, end, rightSubTreeList);

		for (TreeNode* lnode : leftSubTreeList)
		{
			for (TreeNode* rnode : rightSubTreeList)
			{
				TreeNode* root = new TreeNode(i);
				root->left = lnode;
				root->right = rnode;
				treeList.push_back(root);
			}
		}
	}

	return;
}

vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> treeList;

	if (n > 0)
	{
		generateTreesHelper(1, n, treeList);
	}

	return treeList;
}

int main()
{
	vector<TreeNode*>result = generateTrees(3);
	return 0;
}

