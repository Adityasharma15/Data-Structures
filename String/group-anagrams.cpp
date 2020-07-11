// Group words with same set of characters
// Group Anagrams
// https://www.geeksforgeeks.org/print-words-together-set-characters/
// https://leetcode.com/problems/group-anagrams/submissions/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	int n;
  cin >> n;

  vector<string> strs;

  for(int i = 0; i<n; i++)
  {
    string temp;
    strs.push_back(temp);
  }

  vector<int> hashh(27,0);
  unordered_map<string, vector<string>> mapp;

  vector<int> hashh(27,0);
 unordered_map<string, vector<string>> mapp;

 for(auto i: strs)
 {
     fill(hashh.begin(), hashh.end(),0);

     string tempo = i;
     // cout << tempo.size() << "\n";
     for(int ii = 0; ii<tempo.size(); ii++)
     {
       hashh[tempo[ii]-'a']++;
     }

     string key = "";
     for(int ii = 0; ii<27; ii++)
     {
       int x = hashh[ii];
       while(x--)
       {
         key+=(ii+'0');
       }
     }
     mapp[key].push_back(i);
 }

  for(auto i : mapp)
  {
      for(auto j: i)
        cout << j << " ";

      cout << "\n";
  }


  return 0;

}
