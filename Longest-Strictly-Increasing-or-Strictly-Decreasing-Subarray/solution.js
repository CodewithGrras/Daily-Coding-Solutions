class Solution {
    longestMonotonicSubarray(nums) {
        // Agar array empty hai to return 0 karte hain
        if (nums.length === 0) return 0;

        // Initial counters set karte hain
        let maxLen = 1, inc = 1, dec = 1;

        // Array ke second element se traverse karte hain
        for (let i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;  // Agar current element pichle se bada hai, inc ko badhate hain
                dec = 1; // Decreasing streak ko reset karte hain
            } else if (nums[i] < nums[i - 1]) {
                dec++;  // Agar current element pichle se chhota hai, dec ko badhate hain
                inc = 1; // Increasing streak ko reset karte hain
            } else {
                inc = dec = 1; // Agar current aur pichla element equal hai, dono streaks ko reset karte hain
            }
            // Global maximum length ko update karte hain
            maxLen = Math.max(maxLen, Math.max(inc, dec));
        }

        return maxLen; // Longest monotonic subarray ka length return karte hain
    }
}