#include <iostream>
#include <queue>
#include <vector>
#include <map>

class Solution {
   public:
    static int minimumDifference(std::vector<int>& nums, int k) {
        int l = 0, r = 0, cur = 0, ans = INT_MAX;
        int len = nums.size();
        while (r < len) {
            cur |= nums[r];
            ans = std::min(std::abs(cur-k), ans);
            while(cur > k && l < r) {
                l++;
                cur = 0;
                for (int i = l; i <= r; ++i) {
                    cur |= nums[i];
                }
                ans = std::min(std::abs(cur-k), ans);
            }
            r++;
        }
        return ans;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    int res = Solution::minimumDifference(nums, k);
    std::cout << res;
}