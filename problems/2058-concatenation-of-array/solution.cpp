class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
       int n = nums.size();
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];       // Copy to first half
            ans[i + n] = nums[i];   // Copy to second half
        }
        return ans;
    }
};
