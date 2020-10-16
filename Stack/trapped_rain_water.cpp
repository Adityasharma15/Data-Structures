// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {

    // we will calculate water above a block by
    // (min(left, right) - height of that block )* distance

        int n = height.size();
        stack<int> indexes;
        int water = 0;

        for(int i = 0; i<n; i++){

            while(!indexes.empty() && height[indexes.top()] < height[i]){

                // height_mid is the height of block above which water is to be
                // calculated. indexes.top() after this will be used to reference
                // as height of left block and i as right block, subsequently
                // we will be able to sum all the water that will be collected.
                int height_mid = height[indexes.top()];
                indexes.pop();

                // only if there is a left block to contain the water above
                // height_mid block;
                if(!indexes.empty())
                 water += (min(height[indexes.top()], height[i]) - height_mid)*(i -                        indexes.top() - 1) ;
            }

            indexes.push(i);
        }

        return water;
    }
};
