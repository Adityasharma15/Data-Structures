#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

  int n;
  cin >> n;

  vector<int> digits(n);
  unordered_map<int, int> mapp;

  ll sum = 0;
  for(int i = 0; i<n; i++)
  {
      cin >> digits[i];
      mapp[digits[i]]++;
      sum+=digits[i];
  }

  string ans = "";
  for(int i = 0; i<=9; i++)
  {
      int temp = mapp[i];
      while(temp--)
      {
        ans+= (i + '0');
      }
  }

  int onea = -1, oneb = -1, twoa = -1, twob = -1;
  for(int i = 0; i<n; i++)
  {
    int temp = (ans[i] - '0');

    if(onea == -1 && temp%3 == 1)
      onea = (i);

    else if(oneb == -1 && temp%3 == 1)
        oneb = (i);

    else if(twoa == -1 && temp%3 == 2)
        twoa = (i);

    else if(twob == -1 && temp%3 == 2)
        twob = (i);
  }


  bool notfound = false;

  if(sum%3==1)
  {

      int temp1 = INT_MAX;

    if(onea!=-1)
      temp1 = ans[onea] - '0' ;

    int temp2 =INT_MAX;

    if(twoa!=-1 && twob!=-1)
      temp2 = (ans[twoa] - '0') + (ans[twob] - '0');



    if(onea==-1 && twoa == -1)
    {
      notfound = true;
      return "";
    }

    if(onea!=-1)
      {
        // cout << ans[onea] << "\n ";
        mapp[(ans[onea] - '0')]--;
        // cout << mapp[1];
      }

    else
    {
      mapp[ans[twoa]- '0']--;
      mapp[ans[twob]- '0']--;
      // ans.erase(twoa,1);
      // ans.erase(twob,1);
    }
  }

  if(sum%3==2)
  {
    int temp1 = INT_MAX;

     if(twoa!=-1)
        temp1 =ans[twoa] - '0';

    int temp2 = INT_MAX;

    if(onea!=-1 && oneb!=-1 )
        temp2 =(ans[onea] - '0') + (ans[oneb] - '0');



    if(onea==-1 && oneb==-1 && twoa==-1)
    {
      notfound = true;
      return "";
    }

    if(twoa!=-1)
      mapp[ans[twoa]- '0']--;

    else
    {
      mapp[ans[onea]- '0']--;
      mapp[ans[oneb]- '0']--;
    }
  }

  string ans1 = "";
  for(int i = 9; i>=0; i--)
  {
      int temp = mapp[i];
      while(temp--)
      {
        ans1+= (i + '0');
      }
  }

 if(sum==0)
    return "0";

  return ans1;       
  return 0;
}
