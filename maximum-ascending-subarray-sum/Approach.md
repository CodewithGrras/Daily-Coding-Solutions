**APPROACH**

Class Declaration:

class Solution { ... };: Yeh class Solution ke naam se define ki gayi hai.

Function Declaration:

int maxAscendingSum(vector<int>& nums) { ... }: Yeh function maxAscendingSum ka naam hai, jo ek vector nums ko parameter ke roop mein leta hai aur maximum ascending subarray ka sum return karta hai.

Variable Initialization:

int currentSum = nums[0], maxSum = currentSum;: Pehle element ko currentSum aur maxSum mein initialize karte hain. currentSum current ascending subarray ka sum track karega aur maxSum maximum sum ko track karega.

Array Traversal:

for (int i = 1; i < nums.size(); i++) { ... }: Array ke doosre element se lekar last element tak loop chalayenge.

Check Ascending Condition:

if (nums[i] > nums[i - 1]) { ... } else { ... }: Har element ke liye check karenge ki kya woh pichle element se bada hai.

if (nums[i] > nums[i - 1]) { currentSum += nums[i]; }: Agar bada hai, to currentSum mein current element ko add karenge (ascending subarray ko extend karenge).

else { currentSum = nums[i]; }: Agar bada nahi hai, to currentSum ko current element se reset karenge (naya subarray start karenge).

Update Maximum Sum:

maxSum = max(maxSum, currentSum);: Har step ke baad check karenge ki currentSum maxSum se bada hai ya nahi. Agar bada hai, to maxSum ko update karenge.

Return Result:

return maxSum;: Loop complete hone ke baad, maximum ascending subarray ka sum maxSum return karenge.


___________________________________________________________________________________________________