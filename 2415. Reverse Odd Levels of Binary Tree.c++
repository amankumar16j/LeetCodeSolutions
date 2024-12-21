#include<bits/stdc++.h>
using namespace std;

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
    TreeNode* reverseOddLevels(TreeNode* root) {

        if(root == NULL) return root;

        unordered_map<TreeNode*,int> mp;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        int lev=0;

        q1.push(root);
        q2.push(root);

        int temp;
        while(!q1.empty() && !q2.empty()){
            int n=q1.size();
            for(int i=0;i<n;i++){
                TreeNode* top1=q1.front();
                TreeNode* top2=q2.front();
                q1.pop();
                q2.pop();
                if(lev%2!=0){
                    temp=top1->val;
                    if(mp[top1]!=1)
                        top1->val=top2->val;
                    if(mp[top2]!=1)
                        top2->val=temp;
                    mp[top1]=1;
                    mp[top2]=1;
                }

                if(top1->left && mp[top1->left]!=1){
                    q1.push(top1->left);
                }
                if(top1->right && mp[top1->right]!=1){
                    q1.push(top1->right);
                }
                if(top2->right && mp[top2->right]!=1){
                    q2.push(top2->right);
                }
                if(top2->left && mp[top2->left]!=1){
                    q2.push(top2->left);
                }
            }

            lev++;
        }

        return root;
        
    }
};