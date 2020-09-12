// 815. Bus Routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
    {

        if(S ==T)
            return 0;

        // all the buses that visit a particular stop
        unordered_map<int, vector<int> > stop_bus;

        for(int i = 0; i<routes.size(); i++ )
        {
            for(int j = 0; j<routes[i].size(); j++)
            {
                stop_bus[routes[i][j]].push_back(i);
            }
        }


        vector<bool> visited_buses(routes.size() +1, false);
        vector<bool> visited_stops(1000001, false);
        int buses_changed_count = 1;

        // bfs
        queue<int> que;
        que.push(S);


        while(!que.empty())
        {

           int size = que.size();
           unordered_set<int> stops_set;



            while(size--)
            {
            // iterate over a bunch of stops we can visit
            // in buses_changed_count

            int current_stop = que.front();
            que.pop();

            if(visited_stops[current_stop])
                continue;

            visited_stops[current_stop] = true;

            // we visit all the buses we can board via the stops
            // we have in our bunch and see if some of that bus
            // goes to our destination or not
            for(auto bus: stop_bus[current_stop])
            {
                  if(!visited_buses[bus])
                  {
                    for(auto stop : routes[bus])
                    {
                        if(stop == T)
                            return buses_changed_count;

                        stops_set.insert(stop);
                    }

                    visited_buses[bus] = true;
                  }
              }

            }

            //push all the stops we visited in buses_changed_count
            for(auto stop: stops_set)
                 que.push(stop);

            buses_changed_count++;
        }

       return -1;
    }
};
