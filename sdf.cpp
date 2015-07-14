#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode *> generate(int start, int end)
{
    vector<TreeNode*> subTree;
    if (start > end)
    {
        subTree.push_back(NULL);
        return subTree;
    }
    for (int k = start; k <= end; k++)
    {
        vector<TreeNode*> leftSubs = generate(start, k - 1);
        vector<TreeNode*> rightSubs = generate(k + 1, end);
        for (int i = 0; i<leftSubs.size();  i++)
        {
            for (int j = 0; j<rightSubs.size();  j++)
            {

                TreeNode *node = new TreeNode(k);
                node->left = leftSubs[i];
                node->right = rightSubs[j];
                subTree.push_back(node);
            }
        }
    }
    return subTree;
}
int main()
{
    vector<TreeNode *>tree;
    tree = generate(1,3);
    printf("%d\n",tree.size());
    return 0;
}
