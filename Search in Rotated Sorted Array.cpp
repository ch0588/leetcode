class Solution {
public:
    int search(int A[], int n, int target) {
        int l=0, r=n-1, m;
        while(l<=r){
            m = (l+r)/2;
            if(A[m]==target) return m;
            if(A[l]>A[r]){ //include rot
                if(target<A[m]){
                    if(A[m]>=A[l]){
                        if(A[l]<=target)
                            r = m-1;
                        else
                            l = m+1;
                    }
                    else{
                        r = m-1;
                    }
                }
                else{//target>A[m]
                    if(A[m]>=A[l]){ //on head part
                        l = m+1;
                    }
                    else{
                        if(target<=A[r])
                            l = m+1;
                        else
                            r = m-1;
                    }
                }
            }
            else{//no rot
                if(target<A[m])
                    r = m-1;
                else
                    l = m+1;
            }
        }
        return -1;
    }
};
