// Implement a Phone Directory
// Leetcode locked, gfg - wa but that tc runs correctly

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TrieNode
{
  map<char, TrieNode *> mapp;
  // for root node to count no. of duplicates such strings
  int count;
};

ll search_keyword(string keyword, ll index, TrieNode * root, string temp, ll count)
{

  if(index >= keyword.size())
  {
    if(root->mapp.size()==0)
    {
      for(ll x = 0; x<root->count; x++)
        cout << temp << " ";

      return count+root->count;
    }

    for(auto i: root->mapp)
    {
    temp += i.first;
    count += search_keyword(keyword, index+1, i.second, temp, count);
    }

  }

  if(index<keyword.size())
  {
        if(root->mapp.find(keyword[index])==root->mapp.end())
            return count;

        temp += keyword[index];
        count += search_keyword(keyword, index+1, root->mapp[keyword[index]], temp, count);
  }

    return count;
}


void CreateTrie(string temp, TrieNode * root)
{
  for(ll j = 0; j<temp.size(); j++)
  {
      if((root->mapp).find(temp[j])!=(root->mapp).end())
      {
          root = root->mapp[temp[j]];
      }

      else
      {
        TrieNode * newNode = new TrieNode;
        newNode->count = 0;
        root->mapp[temp[j]] = newNode;
        root = newNode;
      }

      if(j == temp.size()-1)
        root->count++;
  }

  return;
}

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	ll t;
	cin >> t;
	while(t--)
  {
    ll n;
    cin >> n;

    TrieNode * root = new TrieNode();
    for(ll i = 0; i<n; i++)
    {
          string temp;
          cin >> temp;
          CreateTrie(temp, root);
    }

    string keyword;
    cin >> keyword;

    for(ll i = 1; i<=keyword.size(); i++)
    {
      string temp2 = keyword.substr(0,i);
      string temp = "";
      ll count;
      // cout << temp << "\n";
      count = search_keyword(temp2, 0, root, temp, 0);

      if(count==0)
        cout << "0";

      else
          cout << "\b";

      cout << "\n";
    }

	}
  return 0;
}
