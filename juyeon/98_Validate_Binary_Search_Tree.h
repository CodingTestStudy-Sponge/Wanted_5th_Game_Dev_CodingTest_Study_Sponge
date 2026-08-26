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

// 98. Validate Binary Search Tree
class Solution
{
public:
	bool isValidBST(TreeNode* root) 
	{
		/* 빈 트리도 BST로 인정 */
		if (!root)
		{
			return true;
		}

		return checkBSTConditionRecursive(root, LLONG_MIN, LLONG_MAX);
	}

	bool checkBSTConditionRecursive(TreeNode* node, const long long minValue, const long long maxValue)
	{
		/* min 이하이거나, max 이상이면 BST 조건 만족 못함 */
		if (minValue >= node->val || maxValue <= node->val)
		{
			return false;
		}

		/* 왼쪽 서브트리 : minValue보다 크고 현재 node Val보다 작아야 함(nullptr이면 true) */
		const bool leftChildCondition = node->left ? checkBSTConditionRecursive(node->left, minValue, node->val) : true;

		/* 오른쪽 서브트리 : 현재 node Val보다 크고 maxValue보다 작아야 함*/
		const bool rightChildCondition = node->right ? checkBSTConditionRecursive(node->right, node->val, maxValue) : true;

		return leftChildCondition && rightChildCondition;
	}
};

