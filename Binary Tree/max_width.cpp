// 662. Maximum Width of Binary Tree

#define ll unsigned long long
class Solution {

// the idea is simply to do a bfs traversal and compare the first and
// the last node of a level, now rather than storing vertical distance
// (to avoid complications of whether both node are at one side of root)
// nodes from root, we will use heap based index, that is indexing the
// level wise and then left to right: 2*index(left) & 2*index + 1(right)
// then simply compare the index of first and last node of the level

public:
    int widthOfBinaryTree(TreeNode* root) {

        if(!root)
            return 0;

        ll maxi = 1;
        queue<pair<TreeNode*, ll>> level;
        level.push({root, 1});

        while(!level.empty()){

            long long size = level.size();

            // storing index of first node and index of last node will
            // be stored in variable index when size loop terminates
            ll first_index = level.front().second, index;

            // traversing level wise
            while(size--){

                TreeNode * node = level.front().first;
                index = level.front().second;
                level.pop();

                if(node->left) level.push({node->left, 2*index});
                if(node->right) level.push({node->right, 2*index+1});
            }

            //comparing the width of current level to max so far
            maxi = max(maxi, (index - first_index) + 1);
        }

        return maxi;
    }
};
