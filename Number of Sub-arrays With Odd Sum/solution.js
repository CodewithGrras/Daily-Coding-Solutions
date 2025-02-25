var numOfSubarrays = function(arr) {
    let oddCount = 0, prefixSum = 0;

    // Har element ko array mein iterate karna
    for (let a of arr) {
        // Prefix sum update karna
        prefixSum += a;
        // Check karna agar prefix sum odd hai
        oddCount += prefixSum % 2;
    }

    // Total odd count ko calculate karna 
    oddCount += (arr.length - oddCount) * oddCount;
    
    // Answer ko modulo 1_000_000_007 ke saath return karna
    return oddCount % 1_000_000

