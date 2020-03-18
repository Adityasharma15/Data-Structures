#include<bits/stdc++.h>
using namespace std;

void add(vector<int> graph[], int a, int b)
{
    graph[a].push_back(b);
}

bool detect_cycle(vector<int> graph[], int a, bool visited[], bool stack[])
{
    if(stack[a]==false)
    {
        visited[a] = true;
        stack[a] = true;

    for(int i = 0; i<graph[a].size(); i++)
    {
        if(visited[graph[a][i]]==false && detect_cycle(graph, graph[a][i], visited,stack))
        {
            return true;
        }

        else if(stack[graph[a][i]]==false)
        {
            return true;
        }
    }
    }

    stack[n] = {false};
    return false;


}




int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> m; 

        vector<int> graph[n];

        while(m--)
        {
            add(graph, n , m);
        }


        bool visited[n] = {false};
        bool stack[n] = {false};


        for(int i = 0; i<n; i++)
        {
                
        if(detect_cycle(graph, 0, visited, stack))
        {
            cout << "1" << "\n";
            exit(1);
        }

        }

        cout << "0" << "\n";
    }

}