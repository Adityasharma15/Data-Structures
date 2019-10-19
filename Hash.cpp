#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >>n;

	map<int,int> map;
			
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];	
		map.insert(i,arr[n]);
	}
	
	int t;
	cin >> t;
	
	for(int i=0;i<n;i++)
	{
		int r;
		r= t - arr[i];
		map.find(r);					
	}
	
}
