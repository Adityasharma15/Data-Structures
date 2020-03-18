#include<bits/stdc++.h>
using namespace std;

void add(vector<int> graph[], int a , int b)
{
    graph[a].push_back(b);
}


bool cycle(vector<int> graph[],int x,  bool visited[], int parent)
{
    visited[x] = true;

        for(int i =0 ; i< graph[x].size(); i++)
        {
            if(visited[graph[x][i]]==false && cycle(graph, graph[x][i], visited, x))
                return true;

            else if(i!=parent)
                return true;
        }

        return false;    

}



int main()
{
    int  t;
    cin >> t;

    while(t--)
    {
        int n , m;
        cin >> n >> m;

        while(m--)
        {
            int  a, int b;
            cin >> a >> b;

            add(graph, a,b);
        }

        bool visited[n] = {false};

        if(cycle(graph, 0,  visited, -1))
            cout << 1 << "\n"

        else
        {
            cout << 0 << "\n";
        }
        
    }


}