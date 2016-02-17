// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int A = 0, B = 0;
        int cntS[10] = {0}, cntG[10] = {0};
        for (int i = 0; i < n; ++i)
            if (secret[i] == guess[i])
                A++;
            else
                cntS[secret[i] - '0']++, cntG[guess[i] - '0']++;
        for (int i = 0; i < 10; ++i)
            if (cntG[i] > 0) B += min(cntG[i], cntS[i]);
        return to_string(A) + "A" + to_string(B) + "B";
    }
};