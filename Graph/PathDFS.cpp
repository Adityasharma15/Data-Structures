#include<bits/stdc++.h>
using namespace std;

int pathDFS(int v, int ** edges, int sv, int ev,  int * visited , int * arr, int index, int count)
{
	arr[index] = sv;
	index++;
	
	visited[sv]=1;
	
	if(sv==ev)
	{
		for(int i=0;i<index;i++)
			cout << arr[i];
		
//		count++;
//		cout << count << endl;
	}
	
	for(int i=0;i<v;i++)
	{
		if(i!=sv && edges[sv][i]==1 && visited[i]!=1)
			pathDFS(v,edges,i,ev, visited ,arr,index,count);
	}
	
	return count;
}

int main()
{
	long long int v,e;
	cin >> v >> e;
	
	int ** edges = new int*[v];
	
	for(int i=0;i<v;i++)
	{
		edges[i]= new int[v];
		
		for(int j=0;j<v;j++)
			edges[i][j]=0;
	}
	
	for(int i=0;i<e;i++)
	{	int f,s;
		cin >> f >> s;
		
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	int sv , ev;
	cout << " enter sv & ev " << endl;
	cin >> sv >> ev;
		
	int * arr = new int[v];
	int * visited = new int[v];
	
	for(int i=0;i<v;i++)
		visited[i] = 0;
		
	pathDFS(v,edges , sv ,ev, visited, arr , 0 , 0);
	}

