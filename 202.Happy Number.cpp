/*
use cycle link method hash
*/
class Solution {
public:
    int getNextHappyNum(int x){
        int res = 0;
        while(x){
            res += ( x%10 ) * (x%10);
            x /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        if(n<1) return false;

        int slow = getNextHappyNum(n);
        int fast = getNextHappyNum ( getNextHappyNum(n) );
        
        while(slow!=fast){
            slow = getNextHappyNum(slow);
            fast = getNextHappyNum ( getNextHappyNum(fast) );
        }
        if(slow==1) return true;
        return false;
    }
};