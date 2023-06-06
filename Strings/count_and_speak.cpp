class Solution {
public:
    string build(string num) {
        string result;
        int freq = 1;
        char curr = num[0];
        for (int i = 1; i < num.length(); i++) {
            if (curr == num[i]) {
                freq++;
            }
            else {
                char f = (char) ('0' + freq);
                result.push_back(f);
                result.push_back(curr);
                curr = num[i];
                freq = 1;
            }
        }
        // doing for last
        char f = (char) ('0' + freq);
        result.push_back(f);
        result.push_back(curr);
        return result;
    }
    string countAndSay(int n) 
    {
        string ans = "1";
        for (int i = 0; i < n-1; i++) {
            ans = build(ans);
        }
        return ans;
    }
   
};
