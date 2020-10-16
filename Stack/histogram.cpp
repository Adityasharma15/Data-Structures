// 84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int max_area = 0;
        stack<int> indexes;
        heights.push_back(0);
        int n = heights.size();

        // just to avoid handling that corner case when last element
        // is to be considered


        for(int i = 0; i<n; i++){

            // while stack has greater elements than this current element
            // keep popping out
            while(!indexes.empty() && heights[indexes.top()] > heights[i]){

                int height = heights[indexes.top()];
                indexes.pop();
                int length = indexes.empty()? -1 : indexes.top();

                // -1 because excluding the curr bar(i)
                max_area = max(max_area, height*(i - length -1));
            }

            indexes.push(i);
        }

        return max_area;
    }
};
