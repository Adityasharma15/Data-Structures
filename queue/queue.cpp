#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	queue <int > q;
	
	int t ;
	cin >> t;
	q.push(t);
	
   int d = q.front();
   q.pop();
   
   cout << d << endl;
   
}
