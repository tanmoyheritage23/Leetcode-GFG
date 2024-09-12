/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

class Solution
{
    private:
        TreeNode* getStartNode(TreeNode *root, int start)
        {
            if (root == nullptr) return nullptr;
            if (root->val == start) return root;

           	// Search left subtree
            TreeNode *leftResult = getStartNode(root->left, start);
            if (leftResult != nullptr) return leftResult;

           	// Search right subtree
            return getStartNode(root->right, start);
        }

    void getParentNode(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        if (root == nullptr) return;

        if (root->left)
        {
            parent[root->left] = root;
            getParentNode(root->left, parent);
        }

        if (root->right)
        {
            parent[root->right] = root;
            getParentNode(root->right, parent);
        }
    }

    public:
        int amountOfTime(TreeNode *root, int start)
        {
           	// Map to store parent pointers
            unordered_map<TreeNode*, TreeNode*> parent;
            parent[root] = nullptr;	// Root has no parent
            getParentNode(root, parent);

           	// Find the start node
            TreeNode *startNode = getStartNode(root, start);
            if (startNode == nullptr) return 0;

           	// BFS to calculate time to spread the infection
            queue<TreeNode*> q;
            unordered_set<TreeNode*> vis;	// To mark visited nodes

            q.push(startNode);
            vis.insert(startNode);

            int time = 0;

            while (!q.empty())
            {
                int size = q.size();	// Number of nodes at the current level
                while (size--)
                {
                    TreeNode *node = q.front();
                    q.pop();

                   	// Check the left child
                    if (node->left && vis.find(node->left) == vis.end())
                    {
                        q.push(node->left);
                        vis.insert(node->left);
                    }

                   	// Check the right child
                    if (node->right && vis.find(node->right) == vis.end())
                    {
                        q.push(node->right);
                        vis.insert(node->right);
                    }

                   	// Check the parent
                    if (parent[node] && vis.find(parent[node]) == vis.end())
                    {
                        q.push(parent[node]);
                        vis.insert(parent[node]);
                    }
                }
                if (!q.empty()) time++;	// Increment time if there are still nodes to process
            }

            return time;
        }
};