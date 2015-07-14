class Solution {
    double findK(int k,int A[],int m,int B[],int n){
        if(m>n)  return findK(k,B,n,A,m);
        if(m==0) return B[k-1];
        if(k==1) return min(A[0],B[0]);
        int pa = min(k/2,m);
        int pb = k-pa;
        if(A[pa-1]<B[pb-1]) return findK(k-pa,A+pa,m-pa,B,n);
        else if(A[pa-1]>B[pb-1]) return findK(k-pb,A,m,B+pb,n-pb);
        else return A[pa-1];
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if( (m+n)%2 )//odd
            return findK( (m+n+1)/2, A, m, B, n );
        else
            return ( findK( (m+n)/2, A, m, B, n ) + findK( (m+n)/2+1, A, m, B, n ) ) / 2.0;
    }
};
