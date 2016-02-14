// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> split(string s) {
        s.push_back('.');
        int num = 0;
        vector<int> res;
        int len = s.size();
        int i = 0;
        while (i < len) {
            while (isdigit(s[i])) num = num * 10 + s[i] - '0', i++;
            res.push_back(num);
            num = 0;
            i++;
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        v1 = split(version1);
        v2 = split(version2);
        int len1 = v1.size(), len2 = v2.size();
        for (int i = 0; i < len1 && i < len2; ++i) {
            if (v1[i] > v2[i]) return 1;
            if (v1[i] < v2[i]) return -1;
        }
        if (len1 > len2) {
            for (int i = len2; i < len1; ++i)
                if (v1[i] != 0) return 1;
            return 0;
        }
        if (len1 < len2) {
            for (int i = len1; i < len2; ++i)
                if (v2[i] != 0) return -1;
            return 0;
        }
        return 0;
    }
};