// 735. Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> aster;
        for(auto curr : asteroids){

            bool destroyed = false;
            while(aster.size() && aster.back()>0 && curr<0&& !destroyed){

                if(aster.back() >= -curr)
                    destroyed = true;

                if(aster.back() <= -curr)
                    aster.pop_back();
            }

            if(!destroyed)
                aster.push_back(curr);
        }

        return aster;

    }
};
