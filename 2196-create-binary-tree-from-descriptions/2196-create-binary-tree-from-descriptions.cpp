/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>s;
        
        for(auto &description: descriptions){
            int parent = description[0];
            int child = description[1];
            bool isLeft = description[2];
            
            if(mp.count(parent) == 0){
                mp[parent] = new TreeNode(parent);
            }
            
            if(mp.count(child) == 0){
                mp[child] = new TreeNode(child);
            }
            
            if(isLeft){
                mp[parent] -> left = mp[child];
            }else{
                mp[parent] -> right = mp[child];
            }
            
            s.insert(child);
        }
        
        for(auto &[val,node]: mp){
            if(s.find(val) == s.end()){
                return node;
            }
        }
        return NULL;
    }
};