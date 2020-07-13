// Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// https://www.geeksforgeeks.org/depth-n-ary-tree/

class Solution {
public:
    int maxDepth(Node* root) {

        if(root == NULL)
            return 0;

        int maxx = 1;
        for(auto i: root->children)
        {
            int temp = maxDepth(i) + 1;
            maxx = max(temp, maxx);
        }

        return maxx;
    }
};
