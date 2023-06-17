#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void dfs(TreeNode<int> *root,int par,unordered_map<int,int> &mp)
{
	if(root==NULL)
	{
		return;
	}

	mp[root->data] = par;

	dfs(root->left,root->data,mp);

	dfs(root->right,root->data,mp);
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> v;

	unordered_map<int,int> mp;

	dfs(root,-1,mp);

	while(x!=-1)
	{
		v.push_back(x);
		x = mp[x];
	}

	reverse(v.begin(),v.end());

	return v;
}
