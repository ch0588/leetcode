Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false


class TwoSum {
public:

    // Add the number to an internal data structure.
    unordered_multiset<int>hash;
    TwoSum(){
        hash.clear();
    }
    void add(int number) {
        hash.insert(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for(auto x:hash){
            int cnt = (x==value-x?1:0);
            if(hash.count(value-x)>cnt) return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);