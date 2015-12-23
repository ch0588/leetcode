class Solution {
public:
    bool canWinNim(int n) {
        /*
        0 0
        1 1
        2 2
        3 3
        4 0
        5 1
        6 2
        7 3
        8 0
        */
        return n%4;
    }
};