class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if((int)digits.size()==0){
            digits.push_back(1);
            return digits;
        }
        reverse(digits.begin(),digits.end());
        int pre = 0;
        int x = digits[0]+1;
        digits[0] = x%10;
        pre = x/10;
        for(int i=1; i<(int)digits.size(); ++i){
            x = digits[i] + pre;
            digits[i] = x%10;
            pre = x/10;
            if(pre==0) break;
        }
        if(pre!=0) digits.push_back(pre);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
