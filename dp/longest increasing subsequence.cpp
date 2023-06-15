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
// binary search solution
// it is used when we dont want subarray itself and just want length its tc = O(nlogn)
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     vector<int> list_arr;
     int n = nums.size();
     list_arr.push_back(nums[0]);
     for (int i = 1; i < n; i++) {
         if (list_arr.back() < nums[i]) {
             list_arr.push_back(nums[i]);
         } else {
             int idx = lower_bound(list_arr.begin(), list_arr.end(), nums[i]) - list_arr.begin();
             list_arr[idx] = nums[i];
         }
     }   
     return list_arr.size();
    }
};*/
