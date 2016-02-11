/*
 bast on two assumption；
 If car starts at A and can not reach B. Any station between A and B can not
 reach B.(B is the first station that A can not reach.)
 If the total number of gas is bigger than the total number of cost. There must
 be a solution.
 */
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};

/*
 convert to circular array max sub
 这里有两个假设的证明
 http://www.cnblogs.com/felixfang/p/3814463.html
 
 */