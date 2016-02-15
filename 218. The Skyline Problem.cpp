// Time Complexity: O(nlogn)
// Space Complexity: O(n)

/*
 http://www.cnblogs.com/easonliu/p/4531020.html
 */
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<int>Q;
        int cur=0,pre=0;
        vector<pair<int, int>>height;
        unordered_map<int,int>hash;
        
        for (auto &b : buildings) {
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        sort(height.begin(), height.end());
        vector<pair<int, int>>res;
        
        Q.push(0);
        for(auto h:height){
            if( h.second < 0 ){ //left
                Q.push(-h.second);
            }
            else{//right
                hash[h.second]++;
                while(!Q.empty() && hash[Q.top()]){
                    hash[Q.top()]--;
                    Q.pop();
                }
            }
            cur = Q.top();
            if(pre!=cur){
                res.push_back(make_pair(h.first,cur));
                pre = cur;
            }
            
        }
        return res;
    }
    
};