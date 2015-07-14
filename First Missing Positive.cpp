/*
Bucket sort
ith element val is i+1,if not swap,O(n) time,O(1) space;
*/

class Solution {
public:
    void bucketSort(int A[],int n){
        for(int i=0; i<n; ++i){
            while( A[i]!=i+1 ){
                if(A[i]<0||A[i]>n||A[i]==A[A[i]-1]) break;
                swap(A[i],A[A[i]-1]);
            }
        }
    }
    int firstMissingPositive(int A[], int n) {
        bucketSort(A,n);
        for(int i=0; i<n; ++i)
            if(A[i]!=i+1) return i+1;
        return n+1;
    }
};
