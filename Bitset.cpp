#include<bits/stdc++.h>
using namespace std;

int main()
{	


	//Indexing is in reverse for Bitset

	bitset<32> b(11);

	//prints binary representation
	cout << b << "\n";

	//prints count of set bits
	cout << b.count() << "\n";

	if(b.any())
		cout <<"yes, one or more bits are set bits" << "\n";

	if(b.none())
		cout << "no, none of the bits are set bits" <<"\n";


	b.set(3);

	b.reset(2);

	b.flip(4);

}