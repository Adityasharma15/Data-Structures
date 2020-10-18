// 153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        int n = 3;
        vector<int> rows(n, 0);
        vector<int> cols(n, 0);
        int diag1 = 0, diag2 = 0;

        // A player wins if it covers any of the diagonal
        // or any row or column completely, such that there
        // is no move of the other player in that diag/row/col

        // lets denote number to player, A = 1, B = -1, now if a
        // diag/row/col has either sum 3 or -3, that means that
        // is owned completely by only one player A or B

        int currplayer = 1; // as game starts with A

        for(auto pos : moves){
        rows[pos[0]] += currplayer;
        cols[pos[1]] += currplayer;

        // in case pos lies on first diagonal
        diag1 = pos[0] == pos[1]? currplayer + diag1: diag1;

        // in case pos lies on second diagonal
        diag2 = pos[0] + pos[1] == n-1? currplayer + diag2: diag2;

        // if some row/col/diag is completely owned by a player
        if(abs(rows[pos[0]]) == n || abs(cols[pos[1]]) == n || abs(diag1)==n || abs(diag2) == n)
            return currplayer == 1? "A" : "B";

           //REMEMBER to change player
           currplayer *= -1;
        }

        return moves.size() == 9 ? "Draw" :"Pending";
    }
};
