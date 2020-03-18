#include<bits/stdc++.h>
using namespace std;

void add(vector<int> graph[], int a, int b)
{
    graph[a].push(b);
}



int paths(vector<int> graph[], int x , int y, visited[],int &count)
{
    visited[x] = true;

    if(x == y)
        count++;

    else
    {
    
    for(int i =0; i< graph[x].size(); i++)
    {
        
        if(visited[graph[x][i]]==false)
        {
            path(graph, graph[x][i], y, visited, count);
        }

        visited[x]= false;
    }

    }

}


int main()
{
    ll n,e;
    cin >> n >> e;

    vector<int> graph[n];

    while(e--)
    {
        ll a,b;
        cin >> a >> b;

        add(graph, a, b);
    }

    ll x, y;
    cin >> x >> y;

    bool visited[n] = {false};

    cout << paths(graph, x ,y, visited) << "\n";
}