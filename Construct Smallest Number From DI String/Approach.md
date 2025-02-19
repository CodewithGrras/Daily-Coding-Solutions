PROBLEM STATEMENT :
__________________

Aapko ek 0-indexed string pattern di gayi hai jiska length n hai aur yeh characters ‘I’ (Increasing) aur ‘D’ (Decreasing) se bani hai.

Ek 0-indexed string num jo length n + 1 ka hai, is conditions ke saath banani hai:

num 1 se 9 tak ke digits se bana hai, jismein har digit ek baar hi use hoti hai.

Agar pattern[i] == ‘I’ hai, toh num[i] < num[i + 1] hona chahiye.

Agar pattern[i] == ‘D’ hai, toh num[i] > num[i + 1] hona chahiye.

Aapko lexicographically sabse chhoti possible string num return karni hai jo in conditions ko meet karti hai.

Example 1:

Input: pattern = “IIIDIDDD” Output: 123549876 Explanation:

Index 0, 1, 2, aur 4 par num[i] < num[i+1] hona chahiye.

Index 3, 5, 6, aur 7 par num[i] > num[i+1] hona chahiye.

Kuch possible values hain “245639871”, “135749862”, aur “123849765”.

Lekin “123549876” sabse chhoti possible num hai jo conditions ko meet karti hai.

Dhyan rahe ki “123414321” possible nahi hai kyunki digit ‘1’ do baar use hui hai.

Example 2:

Input: pattern = “DDD” Output: 4321 Explanation:

Kuch possible values hain “9876”, “7321”, aur “8742”.

Lekin “4321” sabse chhoti possible num hai jo conditions ko meet karti hai.

Constraints:

1 <= pattern.length<= 8

pattern sirf ‘I’ aur ‘D’ characters ka hi bana hota hai.

______________________________________________________________________________

<h1>Pattern Ko Samajhna:</h1>

Har 'I' ka matlab hai ki current digit choti honi chahiye next digit se.

Har 'D' ka matlab hai ki current digit badi honi chahiye next digit se.

Smallest Possible String Banana:

Sabse pehle hum sabse chhoti digits use karenge taaki string lexicographically smallest ho. Pattern ke 'I' aur 'D' ko dhyaan mein rakhte hue hum digits ko arrange karenge.

Intuition
Lexicographically Smallest String Banana:

Humara aim hai ki sabse chhoti possible string banaye jo pattern ke rules ko follow karti ho. Iske liye hum sabse chhoti digits (1 se start karke) use karenge.

Pattern Ko Follow Karna: Pattern ko parse karke hum 'I' aur 'D' instructions ko follow karenge. Har 'I' ke liye hum ensure karenge ki current digit next digit se chhoti ho. Har 'D' ke liye hum ensure karenge ki current digit next digit se badi ho.

Stack Ka Use: Stack ka use karke hum efficiently digits ko arrange kar sakte hain. Stack humein help karega 'D' pattern ko handle karne mein jahan humein digits ko reverse order mein arrange karna hoga.

<h1>Approach</h1>
Time Complexity:
Is problem ko solve karne ke liye hum pattern string ko ek baar iterate karte hain aur stack operations perform karte hain. Chaliye dekhte hain iska time complexity kya hai:

Pattern Ka Iteration:

Pattern string length n hai, toh humein ek baar pattern ko iterate karna padta hai. Yeh step O(n) time leta hai.

Stack Operations:

Har character par hum digits ko stack mein push karte hain aur jab zarurat hoti hai toh stack se pop karte hain.

Push aur pop operations stack ke liye O(1) time lete hain.

Pattern string ke har character par push aur pop operations hote hain, toh overall complexity O(n) hi rahegi.

Isliye, total time complexity O(n) hai.

Space Complexity:
Ab dekhte hain iska space complexity kya hai:

Stack Ka Usage:

Hum digits ko temporarily stack mein store karte hain. Maximum stack size pattern length n ke barabar ho sakti hai, kyunki har pattern character par ek digit stack mein push hoti hai.

Isliye, stack ka maximum size O(n) hota hai.

Result String:

Result string jo hum bana rahe hain, uski length n + 1 hoti hai. Yeh bhi O(n) space leta hai.

Total space complexity bhi O(n) hai, kyunki humara primary space usage stack aur result string ke liye hi hai.