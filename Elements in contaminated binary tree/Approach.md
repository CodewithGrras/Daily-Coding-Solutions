PROBLEM STATEMENT
_________________

Tumhe ek binary tree diya gaya hai jisme kuch rules hain:

root.val== 0

Kisi bhi treeNode ke liye:

Agar treeNode.valka value x hai aur treeNode.left!= null, toh treeNode.left.val== 2 * x + 1

Agar treeNode.valka value x hai aur treeNode.right!= null, toh treeNode.right.val== 2 * x + 2

Ab yeh binary tree contaminate ho gaya hai, matlab sabhi treeNode.val-1 mein badal chuke hain.

Tumhe FindElements class implement karna hai:

FindElements(TreeNode root)*: Yeh object initialize karega ek contaminated binary tree se aur usko recover karega.

bool find(int target): Yeh method return karega true agar target value recovered binary tree mein exist karti hai.

Example
Example 1:

plaintext
Input
[“FindElements”,”find”,”find”]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation:
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True
Example 2:

plaintext
Input
[“FindElements”,”find”,”find”,”find”]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation:
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
Example 3:

plaintext
Input
[“FindElements”,”find”,”find”,”find”,”find”]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation:

FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
Constraints
TreeNode.val== -1

Binary tree ki height maximum 20 tak ho sakti hai.

Total number of nodes 1 se 10^4 ke beech mein hain.

find() ke total calls 1 se 10^4 ke beech mein hain.

0 <= target <= 10^6.

____________________________________________________________________________________________________________________

Yeh code ek class FindElements banata hai jo contaminated binary tree ko recover karta hai aur target values ko efficiently dhoondh sakta hai. Pehle, constructor method mein ek set banate hain jisme recovered values store hoti hain. Fir, root node ka value 0 set karte hain aur ek method call karte hain jo poore tree ko recursively recover karta hai.

RecoverTree Method:

Ye method har node ko check karta hai. Agar node null nahi hai, toh uska value set mein add karta hai.

Fir, left aur right children ke values calculate karke unhe set karta hai.

Left child ka value hota hai 2 * current node value + 1, aur right child ka value hota hai 2 * current node value + 2.

Yeh process recursively poore tree ke liye follow hota hai, jab tak saare nodes recover na ho jayein.

Find Method:

Ye method directly set mein check karta hai agar target value exist karti hai ya nahi.

Agar target value set mein hai, toh true return karta hai, warna false.

____________________________________________________________________________________________________________________