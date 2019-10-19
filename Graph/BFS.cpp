#include<bits/stdc++.h>
#include<queue>
using namespace std;

void printBFS(int v , int ** edges , int sv , int * visited)
{
	
	queue<int> q;
	
	q.push(sv);
	
//	
//	for(int i=0;i<v;i++)
//	{
//		if(edges[sv][i]==1)
//		q.push(i);
//	}
	
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



void  BFS(int v, int ** edges)
{
	int * visited = new int[v];
	
	for(int i=0;i<v;i++)
		visited[i] = 0;
		
	for(int i=0; i<v;i++)
	{
		if(visited[i]==0)
			printBFS(v,edges,i,visited);
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
	
	
	BFS(v, edges);
	
}
