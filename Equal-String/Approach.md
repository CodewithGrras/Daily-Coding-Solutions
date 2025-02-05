Problem Statement
_________________

aapko do strings diye gaye hain, s1 aur s2, jo ek hi length ke hain. Ek string swap ka operation hota hai jab aap string ke do indices (zaroori nahi ki different ho) chunte hain aur un indices par characters ko swap karte hain.

Aapko yeh check karna hai ki kya yeh possible hai ki sirf ek string par at most ek string swap karke dono strings ko equal banaya ja sake. Agar yeh possible hai, toh return true, warna return false.

Example 1:

Input: s1 = “bank”, s2 = “kanb”

Output: true

Explanation: For example, s2 ke first character ko last character se swap karke “bank” banate hain.

Example 2:

Input: s1 = “attack”, s2 = “defend”

Output: false

Explanation: Ek string swap karke inhe equal banana impossible hai.

Example 3:

Input: s1 = “kelb”, s2 = “kelb”

Output: true

Explanation: Yeh do strings pehle se hi equal hain, isliye koi string swap operation ki zaroorat nahi.

Constraints:

s1 ki length aur s2 ki length 1 se 100 ke beech ho.

s1 aur s2 ki length barabar ho.

s1 aur s2 sirf lowercase English letters ka istemal karte ho.