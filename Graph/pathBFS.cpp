#include<bits/stdc++.h>
#include<queue>
using namespace std;

void pathBFS(int v , int ** edges , int sv ,int ev, int * visited)
{
	queue<int> q;
	q.push(sv);
		
	while(!q.empty())
	{
		sv = q.front();
		
		if(visited[sv]==0)
			cout << sv << endl;
	
		visited[sv]=1;

		for( int i = 0; i<v;i++)
		{
			if(edges[sv][i]==1 && visited[i]==0  && sv!= i )		
				q.push(i);				
		}	
	
		q.pop();
	}
}


int main()
{
	int v,e;
	cin >> v >> e;
	
	int ** edges = new int*[v];
	
	for(int i=0;i<v;i++)
	{
		edges[i] = new int[v];
		
		for(int j=0;j<v;j++)
			edges[i][j]=0;
	}
	
	for(int i =0;i<e;i++)
	{
		int x,y;
		cin >> x >> y;
		edges[x][y]=1;
		edges[y][x]=1;
	}
	
	int sv , ev;
	cout << "Enter sv and ev "<<endl;
	cin >> sv >> ev;
	
	int * visited = new int[v];
	
	for(int i=0;i<v;i++)
		visited[i] = 0;
	
	pathBFS(v, edges, sv ,ev ,visited );
	
}
