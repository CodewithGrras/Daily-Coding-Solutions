PROOBLEM STATEMENT

Aapko ek 0-indexed 2D integer matrix grid di gayi hai, jiska size n * n hai aur usme values [1, n²] range mein hain.

Har integer ek baar appear hota hai except ek number ‘a’ jo do baar appear hota hai aur ek number ‘b’ jo missing hai.

Aapka task yeh hai ki aap repeat hone wala number ‘a’ aur missing number ‘b’ ko find karein.

Aapko ek 0-indexed integer array ans return karna hai jiska size 2 ho, jisme ans[0] equals to ‘a’ aur ans[1] equals to ‘b’ ho.

Example 1:

Input: grid = [[1,3],[2,2]] Output: [2,4] Explanation: Number 2 repeat ho raha hai aur number 4 missing hai, toh answer hai [2,4].

Example 2:

Input: grid = [[9,1,7],[8,9,2],[3,4,6]] Output: [9,5] Explanation: Number 9 repeat ho raha hai aur number 5 missing hai, toh answer hai [9,5].

Constraints:

2 <= n == == grid[i].length <= 50

1 <= grid[i][j] <= n * n

Approach

Count Occurrences: ~ Pehle ek 1D array (isko count kehte hain) banao jiska size 𝑛 2 ho aur sab elements ko 0 se initialize karo.

Grid ko traverse karo aur har element ke liye, corresponding index mein count array mein increment karo.

Identify Repeated and Missing Numbers: Grid traverse karne ke baad, count array ko dekho. Jis index par count 2 hai, woh repeated number 𝑎 hai.

Jis index par count 0 hai, woh missing number 𝑏 hai. Return the Result: In dono values ko ek array ans mein store karo jahan ans[0] = a (repeated number) aur ans[1] = b (missing number) ho. ans array ko return karo.

Time Complexity: Counting Occurrences:

Hamne grid ko traverse kiya aur har element ka count increase kiya. Yeh operation O(n²) time leta hai, kyunki grid ka size n * n hai.

Identifying Repeating and Missing Numbers:

Hamne count array ko traverse kiya jo n2n^2 size ka hai. Yeh operation bhi O(n²) time leta hai.

So, overall time complexity O(n²) hoti hai, kyunki yeh dominate karta hai baaki operations ko.

Space Complexity: Count Array:

Hamne ek 1D array count banaya jiska size n2+1n^2 + 1 hai. Isliye space complexity O(n²) hoti hai.

Is approach mein extra space sirf count array ke liye lagta hai, jo n2n^2 size ka hai. Isliye overall space complexity O(n²) hoti hai.
