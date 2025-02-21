// FindElements class ka constructor
var FindElements = function(root) {
    // Recovered values ko store karne ke liye Set banate hain
    this.recoveredValues = new Set();
    // Root ka value recover karte hain
    root.val = 0;
    // Tree ko recover karne ka method call karte hain
    this.recoverTree(root);
};

// Tree ko recover karne ka method
FindElements.prototype.recoverTree = function(root) {
    // Agar root null hai toh return karte hain
    if (!root) return;
    // Current node ka value Set mein add karte hain
    this.recoveredValues.add(root.val);
    // Agar left child exist karta hai
    if (root.left) {
        // Left child ka value calculate karte hain
        root.left.val = 2 * root.val + 1;
        // Recursively left child ke liye recoverTree method call karte hain
        this.recoverTree(root.left);
    }
    // Agar right child exist karta hai
    if (root.right) {
        // Right child ka value calculate karte hain
        root.right.val = 2 * root.val + 2;
        // Recursively right child ke liye recoverTree method call karte hain
        this.recoverTree(root.right);
    }
};

// Target value find karne ka method
FindElements.prototype.find = function(target) {
    // Check karte hain agar target value Set mein hai
    return this.recoveredValues.has(target);
};