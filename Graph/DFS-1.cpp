#include<bits/stdc++.h>
#define ll long long
using namespace std;

void add(vector<int> graph[], int a, int b)
{
    graph[a].push_back(b);
}

void DFS(vector<int> graph[], int a, bool visited[])
{
    cout << a << " ";
    visited[a] = true;

    for(int i = 0; i<graph[a].size(); i++)
    {
        if(visited[graph[a][i]]==false)
        {
        DFS(graph,graph[a][i] , visited);    
        // cout << a << " ";
        // visited[a] = true;
        }
    }

}

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
        ll n , k;
        cin >> n >> k;

        vector<int> graph[n];

        ll x,y;

        while(k--)
        {    
           cin >> x >> y;

           add(graph, x,y); 
        }

        bool visited[n] = {false};

        DFS(graph, 0, visited);

        cout << endl;

	}
}
