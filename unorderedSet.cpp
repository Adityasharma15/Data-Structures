 #include<bits/stdc++.h>
// #include <unordered_set>
using namespace std;

int main()
{
	unordered_set <int> odds ; 
	
	odds.insert(3);
	odds.insert(5);
	odds.erase(33);

	// if(odds.find(3) == odds.end())
	cout << odds.size();
	
}
