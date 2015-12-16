// Time: O(NlogN)  Space:O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        int n = citations.size();
        sort(citations.begin(),citations.end());
        for(int i = 0; i < n; ++i){
            if( citations[i] >= n-i ) return n-i;
        }
        return 0;
    }
};

// Time: O(N)  Space:O(N)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        int n = citations.size();
        int cnt[n+1] = {0};
        for(auto x:citations){
            if(x>n) cnt[n]++;
            else cnt[x]++;
        }
        int h = 0;
        for(int i=n; i>=0; --i){
            h+=cnt[i];
            if(h>=i) return i;
        }
        return 0;
    }
};