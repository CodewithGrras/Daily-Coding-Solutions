Prefix Sum Calculation:

Hum ek variable prefixSum rakhenge jo array ke elements ka sum store karega jab tak hum unhe traverse karte hain.

Jaise hi hum ek naya element add karte hain prefixSum mein, hum check karenge agar yeh odd hai ya nahi.

Odd Count Calculation:

Ek variable oddCount rakhenge jo ki odd prefix sums ka count karega.

Jab bhi prefixSum % 2 odd hoga, hum oddCount ko increment karenge.

Final Calculation:

Total odd subarrays ka count calculate karenge (arr.size() - oddCount) * oddCount se.

Lastly, hum answer return karenge modulo 1'000'000'007 ke saath, kyunki answer bohot bada ho sakta hai.

Yeh approach time complexity O(n) ka use karti hai, jahan n array ki length hai, kyunki hum array ko ek baar traverse karte hain. Space complexity O(1) hai kyunki hum sirf constant space use kar rahe hain.

________________________________________________________________________________________________________________


Time Complexity:
Traverse karna: Hum array ke sabhi elements ko ek baar traverse karte hain for loop ke through. Iska matlab hai ki traverse karne ka time complexity O(n) hai, jahan n array ke elements ki count hai.

Operation inside loop: Loop ke andar jo operations hain, wo constant time (O(1)) mein complete ho jate hain (jaise prefixSum ko update karna, oddCount ko update karna).

Toh overall time complexity O(n) hai, kyunki hum array ke elements ko sirf ek baar traverse karte hain.

Space Complexity:
Hum ne kuch variables define kiye hain (jaise oddCount aur prefixSum), jo sirf constant space lete hain. Inka space complexity O(1) hai.

Hum koi additional array ya data structures use nahi kar rahe hain jo space complexity ko increase kare.

Toh overall space complexity O(1) hai, kyunki hum sirf constant space use kar rahe hain.
