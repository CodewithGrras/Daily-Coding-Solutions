PROBLEM STATEMENT
__________________


Aapko ek array of strings diya gaya hai, jismein n unique binary strings hain aur har string ki length n hai. Aapko ek aisi binary string return karni hai jiska length n ho aur jo nums mein nahi hoti. Agar multiple answers ho, to aap koi bhi return kar sakte hain.

Example 1:

Input: nums = ["01","10"]

Output: "11"

Explanation: "11" nums mein nahi hoti. "00" bhi sahi hoga.

Example 2:

Input: nums = ["00","01"]

Output: "11"

Explanation: "11" nums mein nahi hoti. "10" bhi sahi hoga.

Example 3:

Input: nums = ["111","011","001"]

Output: "101"

Explanation: "101" nums mein nahi hoti. "000", "010", "100", aur "110" bhi sahi honge.

Constraints:

n == nums.length

1 <= n <= 16

nums[i].length == n

nums[i] sirf '0' ya '1' hote hain.

Saari strings nums mein unique hain.

___________________________________________________________________________________________

SOLUTION
________

The solution begins by creating a binary string of all zeroes with the same length as the input array nums.

It then checks if this all-zeroes string is already present in nums. If it is not, this all-zero string is returned as the answer.

If the all-zeroes string is found in nums, the solution attempts to find a unique binary string by flipping one bit at a time to ‘1’ and checking if the new string is present in nums.

If the new string is not present in nums, it is returned as the answer.

If the new string is present, the bit is reverted back to ‘0’, and the process continues with the next bit.

The solution continues this process until it finds a valid binary string that is not present in nums or until all bits have been checked.

____________________________________________________________________________________________________________________