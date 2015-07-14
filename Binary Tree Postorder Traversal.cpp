/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 �����ǰ���������������˼ά���Ѷ�Ҫ��Щ��ǰ�������ͨ��һ��stack������ѹ�븸�׽�㣬Ȼ�󵯳����׽�㣬���������value��֮��ѹ�����Ҷ��ӣ�����Ӽ��ɡ�Ȼ������������ķ���˳���ǣ������ -> �Ҷ��� -> �Լ�����ôһ�������Ҫ��������²��ܹ��������һ�����Ѿ���Ҷ�ӽ�㣻�ڶ���������Ҷ�ӽ�㣬�������Ķ����Ѿ����������ô���ڴ�����ֻ��Ҫ��¼һ�µ�ǰ����Ľ�㼴�ɡ�����һ���µĽ�㣬���������Ҷ�ӽ�㣬����Ҳû�з��ʣ���ô����Ҫ�������Ҷ��ӣ������ѹ�롣�������������������������������¼�µ�ǰ�����㡣�����stackΪ��ʱ������
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int>ret;
        if(root==NULL) return ret;

        stack<TreeNode *>S;
        TreeNode *cur,*pre;
        S.push(root);
        pre = new TreeNode(-1);
        while(!S.empty()){
            cur = S.top();
            if( cur->right==pre || cur->left==pre || ((cur->left==NULL) && (cur->right==NULL)) ){
                S.pop();
                ret.push_back(cur->val);
                pre = cur;
            }
            else{
                if(cur->right!=NULL) S.push(cur->right);
                if(cur->left!=NULL) S.push(cur->left);
            }
        }
        return ret;
    }
};
