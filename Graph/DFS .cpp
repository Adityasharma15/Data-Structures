#include<bits/stdc++.h>
using namespace std;

void printDFS(int v, int ** edges, int sv, int * visited )
{
	cout << sv << " ";
	
	visited[sv]=1;
	
	//cout << "**	" << visited[sv]  << "	sv is	" << sv<< endl;
	
	for(int i=0;i<v;i++)
	{
		if(i==sv)
		{
			continue;
		}
		
		if(edges[sv][i]==1)	
		{
		
		if(visited[i]==1)
		{
			continue;
		}
		
		printDFS(v,edges,i,visited);
	
		}
	}
}

void  DFS(int v, int ** edges)
{
	int * visited = new int[v];
	
	for(int i=0;i<v;i++)
		visited[i] = 0;
		
	for(int i=0; i<v;i++)
	{
		if(visited[i]==0)
			printDFS(v,edges,i,visited);
	}
		
}




int main()
{
	long long int t;
	cin >> t;
	
	while(t--)
	{
	
	
	long long int v,e;
	cin >> v >> e;
	
	//Dynamic 2-D array
	int ** edges = new int*[v];
	
	for(int i=0;i<v;i++)
	{
		edges[i]= new int[v];
		
		for(int j=0;j<v;j++)
		{
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
/*Adjacency Matrix
	
	for(int i=0;i<v;i++)
	{
		cout << endl;
		
		for(int j=0;j<v;j++)
			cout << edges[i][j] << " ";	
	}
*/
		
	DFS(v,edges);
	
	}
}
