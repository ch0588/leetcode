class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int cur = m+n-1;
        int ida = m-1, idb = n-1;
        while(ida>=0 && idb>=0){
            if(A[ida]>B[idb]){
                A[cur--] = A[ida--];
            }
            else{
                A[cur--] = B[idb--];
            }
        }
        while(ida>=0){
            A[cur--] = A[ida--];
        }
        while(idb>=0){
            A[cur--] = B[idb--];
        }
    }
};
