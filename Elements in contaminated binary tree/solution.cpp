class FindElements {
    // Recovered values ko store karne ke liye unordered_set banate hain
    unordered_set<int> recoveredValues;

    // Tree ko recover karne ka method
    void recoverTree(TreeNode* root) {
        // Agar root null hai toh return karte hain
        if (!root) return;
        // Current node ka value set mein insert karte hain
        recoveredValues.insert(root->val);
        // Agar left child exist karta hai
        if (root->left) {
            // Left child ka value calculate karte hain
            root->left->val = 2 * root->val + 1;
            // Recursively left child ke liye recoverTree method call karte hain
            recoverTree(root->left);
        }
        // Agar right child exist karta hai
        if (root->right) {
            // Right child ka value calculate karte hain
            root->right->val = 2 * root->val + 2;
            // Recursively right child ke liye recoverTree method call karte hain
            recoverTree(root->right);
        }
    }

public:
    // FindElements class ka constructor
    FindElements(TreeNode* root) {
        // Root ka value recover karte hain
        root->val = 0;
        // Tree ko recover karne ka method call karte hain
        recoverTree(root);
    }

    // Target value find karne ka method
    bool find(int target) {
        // Check karte hain agar target value set mein hai
        return recoveredValues.count(target);
    }
};