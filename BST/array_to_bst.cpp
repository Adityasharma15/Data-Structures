// 108. Convert Sorted Array to Binary Search Tree

TreeNode * createNode(vector<int>& nums, int left, int right){
        if(left>right)
            return NULL;

        int mid = (left+right)/2;
        TreeNode * node = new TreeNode(nums[mid]);

        node->left = createNode(nums, left, mid-1);
        node->right = createNode(nums, mid+1, right);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createNode(nums, 0, nums.size()-1);
    }
};
