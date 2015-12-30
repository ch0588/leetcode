/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 */
class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>cur,int lim,int remain){
        /*
        for(int i=0; i<cur.size(); ++i){
            printf("%d ",cur[i]);
        }
        printf("%d\n",remain);
        */
        cur.push_back(remain);
        res.push_back(cur);
        cur.pop_back();
        
        for(int i=lim; i<=sqrt(remain); ++i){
            if(remain%i==0){
                cur.push_back(i);
                dfs(cur,i,remain/i);
                cur.pop_back();
            }
        }
        
    }
    vector<vector<int>> getFactors(int n) {
        res.clear();
        for(int i=2; i<=sqrt(n); ++i){
            if(n%i==0){
                vector<int>cur;
                cur.push_back(i);
                dfs(cur,i,n/i);
            }
        }
        return res;
    }
};