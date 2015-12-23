class Solution {
public:
    int partition(vector<int>& nums,int l,int r){
        if(l>=r) return l;
        
        int x = nums[l];
        while(l<r){
            while( l<r && nums[r]<=x ) r--;
            if(l<r){
                nums[l] = nums[r];
                l++;
            }
            while( l<r && nums[l]>x ) l++;
            if(l<r){
                nums[r] = nums[l];
                r--;
            }
        }
        nums[l] = x;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        while(true){
            int pos =  partition(nums,l,r);
            if(pos==k-1) return nums[pos];
            if(pos>k-1) r = pos-1;
            else l = pos+1;
        }
    }
};

/*
max heap
*/
class Solution {
public:
    int *heap;
    int hs;
    void sink(int p){
        int q = p<<1, a = heap[p];
        while(q<=hs){
            if(q<hs && heap[q+1]>heap[q]) q++;
            if(heap[q]<=a) break;
            heap[p] = heap[q]; p=q; q=p<<1;
        }
        heap[p] = a;
    }
    void swim(int p){
        int q=p>>1,a=heap[p];
        while(q && a>heap[q]){
            heap[q]; p=q; q=p>>1;
        }
        heap[p]=a;
    }
    void insert(int a){
        heap[++hs] = a; swim(hs);
    }
    void build(){
        for(int i=hs/2; i>0; i--) sink(i);
    }
    int getmax(){
        int r = heap[1]; heap[1] = heap[hs--];
        sink(1);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        heap = new int[n+1];
        hs = n;
        for(int i=0; i<n; ++i) heap[i+1] = nums[i];
        build();
        int res;
        while(k--)  res = getmax();
        return res;
    }
};