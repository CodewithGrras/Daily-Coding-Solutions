
var tupleSameProduct = function(nums) {
    // Ek hashmap (Map) banate hain product counts store karne ke liye aur result ko 0 set karte hain
    let productCount = new Map(), result = 0;

    // Pehla loop: har element ke liye iterate karte hain
    for (let i = 0; i < nums.length; i++)
        // Dusra loop: current element ke baad ke elements ke liye iterate karte hain
        for (let j = i+1; j < nums.length; j++) {
            // Pair ka product calculate karte hain
            let product = nums[i] * nums[j];

            // Agar product hashmap mein pehle se exist karta hai,
            // toh result ko update karte hain with 8 * frequency of that product
            result += 8 * (productCount.get(product) || 0);

            // Product ko hashmap mein update karte hain
            // Agar pehle se nahi hai toh 1 set karte hain, aur agar hai toh +1 badhate hain
            productCount.set(product, (productCount.get(product) || 0) + 1);
        }

    // Final result return karte hain
    return result;
};