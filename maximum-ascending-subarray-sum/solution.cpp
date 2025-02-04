class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // currentSum ko initialize karo, jo current ascending subarray ka sum track karega
        int currentSum = nums[0], maxSum = currentSum; // maxSum ko bhi initialize karo, jo maximum sum ko store karega

        // Array ko iterate karte hain
        for (int i = 1; i < nums.size(); i++) {
            // Agar current element pichle element se bada hai
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i]; // Ascending subarray ko extend karo
            } else {
                currentSum = nums[i]; // Naya subarray start karo
            }
            // maxSum ko update karo agar currentSum zyada hai
            maxSum = max(maxSum, currentSum);
        }

        // Final maximum sum return karo
        return maxSum;
    }
};