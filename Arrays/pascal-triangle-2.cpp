// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {

      vector<int> current, previous{1};

      if(rowIndex == 0){
          return previous;
      }

      for(int row = 1; row<= rowIndex; row++){
          current.clear();
          current.push_back(1);

          for(int col = 0; col<row-1; col++){
              current.push_back(previous[col] + previous[col+1]);
          }
          current.push_back(1);
          previous = current;
      }

        return current;
    }
};
