/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?
*/

//trick n == 0 and repetition points
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    bool isReflected(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n < 1) return true;
        
        mp.clear();
        int maxX = INT_MIN, minX = INT_MAX;
        for (auto p : points) {
            maxX = max(maxX, p.first);
            minX = min(minX, p.first);
            mp[p.second].push_back(p.first);
        }
        
        double midLine = (minX + maxX) / 2.0;
        for (auto &it : mp) {
            vector<int>& vec = it.second;
            sort(vec.begin(), vec.end());
            auto iter = unique(vec.begin(), vec.end()); 
            vec.erase(iter, vec.end()); 
            int l = 0, r = vec.size() - 1;
            while (l <= r) {
                // cout<<vec[l]<<"\t"<<vec[r]<<"\t"<<midLine<<endl;
                // cout<<fabs( (vec[l] + vec[r]) / 2.0 - midLine )<<endl;
                if (fabs( (vec[l] + vec[r]) / 2.0 - midLine ) > 1e-8) return false;
                l++; r--;
            }
        }
        return true;
    }
};