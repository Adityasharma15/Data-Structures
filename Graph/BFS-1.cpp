#include<bits/stdc++.h>
#define ll long long

using namespace std;


void insert(vector<int> graph[], int a, int b)
{
	graph[a].push_back(b);
}


void BFS(vector<int> graph[], int a, int n)
{
		queue<int> q;
		q.push(a);

		ll x;

		bool visited[n];

		for(ll i = 0; i<n; i++)
			visited[i]=false;

		while(q.empty()==false)
        {
			x = q.front();
			cout <<  x << " ";
			visited[x] = true;
			

			for(ll i = 0; i<graph[x].size(); i++)
			{
				if(visited[graph[x][i]]==false)
				{
					//cout << graph[x][i] << " ";
					visited[graph[x][i]] = true;
					q.push(graph[x][i]);
					//cout << "a " << graph[x][i] << "  a" << endl;
				}
			}

			q.pop();

		}

}






int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		cout << endl;

		ll n, v;
		cin >> n >> v;

		vector<int> graph[n];

		ll a, b;

		while(v--)
		{
			cin >> a >> b;

			insert(graph, a, b);
		}

		BFS(graph, 0, n);

	}

}