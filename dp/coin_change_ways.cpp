#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<long> prev(value + 1, 0);
    for (int i = 0; i <= value; i++) {
        if (i % denominations[0] == 0) {
            prev[i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        vector<long> curr(value + 1, 0);
        for (int target = 0; target <= value; target++) {
            long notTake = prev[target];
            long take = 0;
            if (denominations[i] <= target) {
                take = curr[target - denominations[i]];
            }
            curr[target] = notTake + take;
        }
        prev = curr;
    }
    return prev[value];
}
