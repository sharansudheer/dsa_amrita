// C++ program for the above approach
/*
https://www.geeksforgeeks.org/left-rotate-digits-of-node-values-of-all-levels-of-a-binary-tree-in-increasing-order/ */

#include <bits/stdc++.h>

using namespace std;

// TreeNode class
struct TreeNode
{
	int val;
	TreeNode* left,*right;

	TreeNode(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
	}
};

// Function to check if the nodes
// are in increasing order or not
bool isInc(TreeNode *root)
{
	
	// Perform Level Order Traversal
	queue<TreeNode*> que;
	que.push(root);

	while (true)
	{
		
		// Current length of queue
		int length = que.size();

		// If queue is empty
		if (length == 0)
			break;
			
		auto pre = que.front();

		// Level order traversal
		while (length > 0)
		{
			
			// Pop element from
			// front of the queue
			auto temp = que.front();
			que.pop();

			// If previous value exceeds
			// current value, return false
			if (pre->val > temp->val)
				return false;

			pre = temp;
			if (temp->left)
				que.push(temp->left);

			if (temp->right)
				que.push(temp->right);

			length -= 1;
		}
	}
	return true;
}

// Function to print the Tree
// after modification
void levelOrder(TreeNode *root)
{
	
	// Performs level
	// order traversal
	queue<TreeNode*> que;
	que.push(root);

	while (true)
	{
		
		// Calculate size of the queue
		int length = que.size();

		if (length == 0)
			break;

		// Iterate until queue is empty
		while (length)
		{
			auto temp = que.front();
			que.pop();
			cout << temp->val << " ";

			if (temp->left)
				que.push(temp->left);

			if (temp->right)
				que.push(temp->right);
				
			length -= 1;
		}
		cout << endl;
	}
	cout << endl;
}

// Function to arrange node values
// of each level in increasing order
void makeInc(TreeNode *root)
{
	
	// Perform level order traversal
	queue<TreeNode*> que;
	que.push(root);

	while (true)
	{
		
		// Calculate length of queue
		int length = que.size();

		// If queue is empty
		if (length == 0)
			break;
			
		int prev = -1;

		// Level order traversal
		while (length > 0)
		{
			//cout<<"loop";

			// Pop element from
			// front of the queue
			auto temp = que.front();
			que.pop();

			// Initialize the optimal
			// element by the initial
			// element
			auto optEle = temp->val;
			auto strEle = to_string(temp->val);

			// Check for all left
			// shift operations
			bool flag = true;
			int yy = strEle.size();
			for(int idx = 0; idx < strEle.size(); idx++)
			{
				
				// Left shift
				int ls = stoi(strEle.substr(idx, yy) + 
							strEle.substr(0, idx));

				if (ls >= prev and flag)
				{
					optEle = ls;
					flag = false;
				}
				
				// If the current shifting
				// gives optimal solution
				if (ls >= prev)
					optEle = min(optEle, ls);
			}
			
			// Replacing initial element
			// by the optimal element
			temp->val = optEle;
			prev = temp->val;

			// Push the LST
			if (temp->left)
				que.push(temp->left);

			// Push the RST
			if (temp->right)
				que.push(temp->right);

			length -= 1;
		}
	}
	
	// Print the result
	if (isInc(root))
		levelOrder(root);
	else
		cout << (-1);
}

// Driver Code
int main()
{
	TreeNode *root = new TreeNode(341);
	root->left = new TreeNode(241);
	root->right = new TreeNode(123);
	root->left->left = new TreeNode(324);
	root->left->right = new TreeNode(235);
	root->right->right = new TreeNode(161);
	
	makeInc(root);
}


