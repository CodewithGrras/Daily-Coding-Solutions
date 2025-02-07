**Problem Statement**
_____________________

Aapko ek integer limit aur ek 2D array queries diye gaye hain, jiska size n x 2 hai.

Maan lijiye ki aapke paas limit + 1 balls hain jinpe alag-alag labels hain [0 se limit tak]. Shuru mein, sabhi balls uncolored hain. Har query [x, y] ke liye, aap ball x ko color y se mark karte hain. Har query ke baad, aapko balls ke beech kitne distinct colors hain, yeh pata lagana hai.

Aapko ek array result return karna hai jiska length n hai, aur result[i] denote karta hai ki i-th query ke baad kitne distinct colors hain.

Yeh dhyan rakhna hai ki jab aap query ka jawab de rahe hain, color ki kami ko color nahi maana jayega.

Example 1:

plaintext
Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

Output: [1,2,2,3]
Explanation:

Query 0 ke baad, ball 1 ka color 4 hai.

Query 1 ke baad, ball 1 ka color 4 hai aur ball 2 ka color 5 hai.

Query 2 ke baad, ball 1 ka color 3 hai aur ball 2 ka color 5 hai.

Query 3 ke baad, ball 1 ka color 3, ball 2 ka color 5 aur ball 3 ka color 4 hai.

Example 2:

plaintext
Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

Output: [1,2,2,3,4]
Explanation:

Query 0 ke baad, ball 0 ka color 1 hai.

Query 1 ke baad, ball 0 ka color 1 aur ball 1 ka color 2 hai.

Query 2 ke baad, ball 0 ka color 1 aur balls 1 aur 2 ka color 2 hai.

Query 3 ke baad, ball 0 ka color 1, balls 1 aur 2 ka color 2 aur ball 3 ka color 4 hai.

Query 4 ke baad, ball 0 ka color 1, balls 1 aur 2 ka color 2, ball 3 ka color 4 aur ball 4 ka color 5 hai.

Constraints:

1 <= limit <= 10^9

1 <= n == <= 10^5

queries[i].length == 2

0 <= queries[i][0] <= limit

1 <= queries[i][1] <= 10^9


**Approach**
_____________

Map aur Set Initialize karo:

Ek dictionary ballColors banaye jo har ball ka current color track karegi.

Ek set distinctColors banaye jo distinct colors ko track karega.

Har Query ko Process karo:

Har query [x, y] ke liye, pehle check karo agar ball x already kisi color se colored hai.

Agar ball x already colored hai, to uska old color ko distinctColors set se hata do agar wo old color aur kisi aur ball ke pass nahi hai.

Ball x ko naya color y do aur ballColors[x] = y update karo.

Ball x ke naye color y ko distinctColors set mein add karo.

Result Update karo:

Har query ke baad distinctColors set ka length nikal ke result array mein store karo.
_____________________________________________________________________________________________________

**Time Complexity:**

Har query ko process karne mein average O(1) time lagta hai. Kyunki hum dictionary ballColors mein direct access kar sakte hain aur colors ko update kar sakte hain.

Total n queries ko process karne mein O(n) time lagega.

Isliye, average time complexity hai O(n).

**Space Complexity:**

Har ball ka current color ko track karne ke liye hum dictionary ballColors ka use karte hain, jo worst case mein n entries tak ho sakti hain (assuming every ball is colored at least once).

Similarly, har color ka frequency track karne ke liye hum set distinctColors ka use karte hain, jo worst case mein n entries tak ho sakti hain (assuming every color is distinct).

Isliye, worst case mein space complexity hai O(n).
_____________________________________________________________________________________________________

                                   THANK YOU 