// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int>> ans;
            if (num.size() < 4) 
                return ans;
            sort(num.begin(), num.end());
            unordered_multimap<int, pair<int, int>> cache;

            for (int i = 0; i + 1 < num.size(); ++i)
                for (int j = i + 1; j < num.size(); ++j)
                    cache.insert( make_pair(num[i] + num[j], make_pair(i, j) ) );

            for (auto i = cache.begin(); i != cache.end(); ++i) {
                int x = target - i->first;
                auto range = cache.equal_range(x);
                for (auto j = range.first; j != range.second; ++j) {
                    auto a = i->second.first;
                    auto b = i->second.second;
                    auto c = j->second.first;
                    auto d = j->second.second;
                    if (b < c) {
                        ans.push_back({ num[a], num[b], num[c], num[d] });
                    }
                }
            }
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            return ans;
        }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> >ret;
        ret.clear();
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i=0; i<n; ++i){
            if (i > 0 && num[i] == num[i-1]) continue; //第一个数不能重复
            for(int j=i+1; j<n; ++j){
                if (j>i+1 && num[j] == num[j-1]) continue; //第二个数不能重复
                int l = j+1, r = n-1;
                int t = target-num[i]-num[j];
                int prel = num[j]-1; //第三个数判重
                while(l<r){
                    if(num[l]+num[r]==t){
                        if(num[l]!=prel){ //对于同一个i+j，第三个数不能重复
                            prel = num[l];
                            ret.push_back({num[i],num[j],num[l],num[r]});
                        }
                        l++; r--;
                    }
                    else if(num[l]+num[r]<t) l++;
                    else r--;
                }
            }
        }
        return ret;
    }
};