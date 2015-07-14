class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int en = 0;
        for(int i=0; i<n; ++i){
            if(A[i]==elem) en++;
            else A[i-en] = A[i];
        }
        return n-en;
    }
};
