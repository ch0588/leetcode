/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<string>res;
    
    void dfs1(TreeNode* root){
        if(root==NULL) {
            res.push_back("#");
            return;
        }
        res.push_back(to_string(root->val));
        dfs1(root->left);
        dfs1(root->right);
        
    }
    string serialize(TreeNode* root) {
        res.clear();
        dfs1(root);
        string t="";
        if(res.size()==0) return t;
        t = res[0];
        int n = res.size();
        for(int i=1; i<n; ++i)
            t += (","+res[i]);
        std::cout<<t<<endl;
        return t;
    }
    TreeNode* dfs2(int &pos,int len){
        if(pos>=len) return NULL;
        if(res[pos]=="#") return NULL;
        TreeNode *root = new TreeNode(stoi(res[pos]));
        pos++;
        root->left = dfs2(pos,len);
        pos++;
        root->right = dfs2(pos,len);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        data+=",";
        res.clear();
        string t="";
        for(char ch:data){
            if(ch==',') res.push_back(t),t="";
            else t+=ch;
        }
        res.push_back(t);
        /*
        for(int i=0; i<res.size(); ++i){
            cout<<res[i]<<endl;
        }
        */
        
        int len = res.size();
        int pos = 0;
        TreeNode *root = dfs2(pos,len);
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));