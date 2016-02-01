/*
 One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 
      _9_
     /   \
    3     2
   / \   / \
  4   1  #  6
 / \ / \   / \
 # # # #   # #
 
 For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 
 Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 
 Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 
 You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 
 Example 1:
 "9,3,4,#,#,1,#,#,2,#,6,#,#"
 Return true
 
 Example 2:
 "1,#"
 Return false
 
 Example 3:
 "9,#,#,1"
 Return false
 */

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder=="" || preorder=="#") return true;
        
        vector<int>nodes;
        int i = 0, len = preorder.length();
        while(i<len){
            if(preorder[i]=='#'){
                nodes.push_back(0);
                i++;
            }
            else{
                while( i<len && preorder[i]>='0' && preorder[i]<='9' ) i++;
                nodes.push_back(1);
            }
            i++;
        }
        
        stack<int>S;
        for(int x:nodes){
            if(x==1) S.push(0);
            else{
                if(S.empty()) return false;
                if( S.top() == 0){
                    S.pop(); S.push(1);
                }
                else{
                    S.pop();
                    while(!S.empty()){
                        if(S.top()==0){
                            S.pop(); S.push(1); break;
                        }
                        else{
                            S.pop();
                        }
                    }
                }
            }
        }
        
        return S.empty();
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder=="" || preorder=="#") return true;
        
        vector<int>nodes;
        int i = 0, len = preorder.length();
        while(i<len){
            if(preorder[i]=='#'){
                nodes.push_back(0);
                i++;
            }
            else{
                while( i<len && preorder[i]>='0' && preorder[i]<='9' ) i++;
                nodes.push_back(1);
            }
            i++;
        }
        
        int depth = 0;
        for(i=0; i<nodes.size()-1; ++i){
            if(nodes[i]==0){
                if(depth<=0) return false;
                depth--;
            }
            else{
                depth++;
            }
        }
        return depth==0 && nodes.back()==0;
    }
};
