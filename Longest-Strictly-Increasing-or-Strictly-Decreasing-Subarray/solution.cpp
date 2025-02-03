class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // Check karte hain agar array empty hai to 0 return karte hain
        if (nums.empty()) return 0;

        // Initialize karte hain counters ko
        int maxLen = 1, inc = 1, dec = 1;

        // Array ke second element se traversal shuru karte hain
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                inc++;  // Agar current element pichle element se bada hai, to increasing streak ko increment karte hain
                dec = 1; // Decreasing streak ko reset karte hain
            } else if (nums[i] < nums[i-1]) {
                dec++;  // Agar current element pichle element se chhota hai, to decreasing streak ko increment karte hain
                inc = 1; // Increasing streak ko reset karte hain
            } else {
                inc = dec = 1; // Agar current element aur pichla element equal hai, to dono streaks ko reset karte hain
            }
            // Global maximum length ko update karte hain
            maxLen = max(maxLen, max(inc, dec));
        }

        // Longest monotonic subarray ka length return karte hain
        return maxLen;
    }
};