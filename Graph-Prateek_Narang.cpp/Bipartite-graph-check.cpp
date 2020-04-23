// this is just a function


bool isBipartiteUtil(int G[][MAX], int i, vector<int> colour, int V)
{

    queue<int> qu;

    qu.push(i);

    colour[i] = 0;

    int el;

    while(!qu.empty())
    {
        el = qu.front();
        qu.pop();

        // self loop
        if(G[el][el])
            return false;

        for(int j = 0; j<V; j++)
        {

            if(G[el][j] && colour[j] == -1)
              {
                  colour[j] = 1 - colour[el];
                  qu.push(el);
              }

            if(G[el][j] && colour[j] == colour[el])
                return false;
        }


    }

    return true;

}


bool isBipartite(int G[][MAX],int V)
{

    vector<int> colour(V, -1);

    for(int i = 0;i<V; i++)
    {
        if(colour[i] == -1)
           {
               if(!isBipartiteUtil(G, i, colour, V))
                return false;
           }
    }

    return true;
}
