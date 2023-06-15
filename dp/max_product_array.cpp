class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 4 cases
        // 1. if all positive multiplication of alll nos is max
        // 2. if even negatives then also multipliclation of all nos is max
        // 3. if odd negatives then we have to remove one negative and search in left prefix and right suffix the max will be the  ans;
        // 4. if 0's we will treat all arrays as seprate not including 0 and on encountring 0 start again
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            prefix = prefix*nums[i];
            suffix = suffix*nums[nums.size()-i-1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};
