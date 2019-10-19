#include<bits/stdc++.h>
using namespace std;

int pow ( int n , int x)
{
	if(x==0)
	return 1;
	
	if(x>0)
	{
	
	int p=n*pow(n,x-1);
	return p;
}
}

int main()
{
	int n , x;
	cin >> n >> x;
	cout << pow(n,x); 
	
}
