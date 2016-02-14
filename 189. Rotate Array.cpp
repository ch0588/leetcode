// STL
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return;

    k = k % n;
    if (k == 0) return;

    k = n - k;
    std::rotate(nums.begin(), nums.begin() + k, nums.end());
  }
};

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return;

    k = k % n;
    if (k == 0) return;

    k = n - k;
    nums.insert(nums.end(), nums.begin(), nums.begin() + k);
    nums.erase(nums.begin(), nums.begin() + k);
  }
};