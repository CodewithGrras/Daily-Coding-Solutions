**Problem Statement**
_____________________

Aapko ek array of integers nums diya gaya hai. Aapko nums ka longest subarray find karna hai jo ya to strictly increasing ho ya strictly decreasing ho. Strictly increasing ka matlab hai ki agle element ka value pichle element se bada ho aur strictly decreasing ka matlab hai ki agle element ka value pichle element se chhota ho.

Example 1:
Input: nums = [1, 4, 3, 3, 2] Output: 2

Explanation:

Strictly increasing subarrays: [1], [2], [3], [3], [4], [1, 4]

Strictly decreasing subarrays: [1], [2], [3], [3], [4], [3, 2], [4, 3]

Inka maximum length 2 hai. Isliye output 2 hoga.

Example 2:
Input: nums = [3, 3, 3, 3] Output: 1

Explanation:

Strictly increasing subarrays: [3], [3], [3], [3]

Strictly decreasing subarrays: [3], [3], [3], [3]

Har subarray ka length 1 hai. Isliye output 1 hoga.

Example 3:
Input: nums = [3, 2, 1] Output: 3

Explanation:

Strictly increasing subarrays: [3], [2], [1]

Strictly decreasing subarrays: [3], [2], [1], [3, 2], [2, 1], [3, 2, 1]

Inka maximum length 3 hai. Isliye output 3 hoga.

Constraints:
nums.length ka range 1 <= nums.length <= 50 hai.

nums[i] ka range 1 <= nums[i] <= 50 hai.

__________________________________________________________________________________________________

**INTUITION**
------------
Track Two Counters:

Dono increasing aur decreasing streaks ke liye alag-alag counters maintain karein. Matlab, ek counter strictly increasing subarray ka length track karega aur dusra counter strictly decreasing subarray ka length track karega.

🔄 Update Counters:

Har element ko pichle element ke sath compare karein:

Increase Streak ↗️: Agar current element pichle element se bada hai to increasing streak ka counter increase karein.

Decrease Streak ↘️: Agar current element pichle element se chhota hai to decreasing streak ka counter increase karein.

Reset Both ⏹️: Agar current element aur pichle element equal hain to dono counters ko reset karein.

Track Maximum:

Har step ke baad global maximum length ko update karein. Matlab, har bar jab counters update hote hain to dekhein ki kya current streak ka length global maximum se bada hai. Agar haan, to global maximum ko update karein.

**APPROACH**
------------
Initialize Counters:

Increasing Counter: Ek counter jo strictly increasing subarray ko track karega.

Decreasing Counter: Ek counter jo strictly decreasing subarray ko track karega.

Global Maximum: Ek variable jo maximum length ko track karega.

Iterate Through the Array:

Array nums ke har element ko traverse karna shuru karte hain.

Har element ko pichle element ke sath compare karte hain aur counters ko accordingly update karte hain:

If current > previous: Increasing counter ko increment karte hain. Decreasing counter ko reset kar dete hain.

If current < previous: Decreasing counter ko increment karte hain. Increasing counter ko reset kar dete hain.

If current == previous: Dono counters ko reset kar dete hain kyunki yeh strictly increasing ya strictly decreasing subarray nahi hoga.

Update Global Maximum:

Har step pe, current increasing aur decreasing counters ka maximum length find karte hain aur global maximum ko update karte hain agar yeh length global maximum se bada hai.

Return Result:

Poora array traverse karne ke baad, global maximum ko return kar dete hain jo longest strictly increasing ya strictly decreasing subarray ka length hoga.

___________________________________________________________________________________________________

**COMPLEXITY**
--------------
Time Complexity: O(n)

Single Iteration: Solution mein hum sirf ek baar array ko iterate karte hain. Matlab, array ke har element ko sirf ek baar visit karte hain.

Explanation: Is iteration mein har element ko pichle element ke sath compare karte hain aur increasing aur decreasing counters ko update karte hain. Yeh process linear time mein hota hai, jiska matlab hai ki agar array ka length n hai to total time complexity O(n) hoti hai.

Space Complexity: O(1)

Constant Space: Solution mein sirf kuch constant space counters use karte hain, jaise ki inc, dec, aur maxLen.

Explanation: Yeh counters strictly increasing aur strictly decreasing streaks ko track karte hain aur global maximum length ko update karte hain. In counters ka use karne se extra space required constant hota hai, jo array ke length n ke sath grow nahi hota. Isliye space complexity O(1) hoti hai.
__________________________________________________________________________________________________

**How to Proceed !!**

Initialization:

Pehle, hum check karte hain ki given array empty to nahi hai. Agar empty hai to directly 0 return kar dete hain.

Hum teen counters initialize karte hain:

maxLen: Jo global maximum length track karta hai.

inc: Jo strictly increasing subarray ka length track karta hai.

dec: Jo strictly decreasing subarray ka length track karta hai.

Traversal:

Phir hum array ko second element se traverse karna shuru karte hain.

Har element ko pichle element ke sath compare karte hain:

Agar current element pichle element se bada hai: To increasing counter (inc) ko increment karte hain aur decreasing counter (dec) ko reset kar dete hain. Matlab, hum strictly increasing subarray track kar rahe hain.

Agar current element pichle element se chhota hai: To decreasing counter (dec) ko increment karte hain aur increasing counter (inc) ko reset kar dete hain. Matlab, hum strictly decreasing subarray track kar rahe hain.

Agar current element aur pichla element equal hai: To dono counters ko reset kar dete hain. Matlab, yeh neither strictly increasing nor strictly decreasing subarray hai.

Update Maximum Length:

Har step ke baad, hum global maximum length (maxLen) ko update karte hain. Yeh update tab hota hai jab current increasing ya decreasing counter ka length global maximum se bada ho.

Return Result:

Poora array traverse karne ke baad, hum global maximum length ko return kar dete hain. Yeh longest strictly increasing ya strictly decreasing subarray ka length hota hai.


___________________________________________________________________________________________________

                            Thanks for your Support :)