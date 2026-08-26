#pragma once

#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
	int val = 0;

	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	TreeNode()
	{

	}

	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{

	}

	TreeNode(int x, TreeNode* left, TreeNode* rihgt)
		:val(x)
		,left(left)
		,right(right)
	{

	}

	~TreeNode()
	{
		if (left)
		{
			delete left;
			left = nullptr;
		}

		if (right)
		{
			delete right;
			right = nullptr;
		}
	}

};

// 111. Minimum Depth of Binary Tree
class Solution
{
public:
	int minDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		return GetNodeLevelRecursive(root, 1);
	}

	int GetNodeLevelRecursive(TreeNode* node, int level)
	{
		/* 리프노드면 인자로 받은 레벨 반환 */
		if (!node->left && !node->right)
		{
			return level;
		}

		/* 자식노드들이 반환하는 레벨 중 최소 레벨을 반환한다. */
		const int leftMinLevel = node->left ? GetNodeLevelRecursive(node->left, level + 1) : INT_MAX;
		const int rightMinLevel = node->right ? GetNodeLevelRecursive(node->right, level + 1) : INT_MAX;

		return min(leftMinLevel, rightMinLevel);
	}
};

