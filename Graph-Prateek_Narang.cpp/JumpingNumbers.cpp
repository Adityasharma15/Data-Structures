#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while(t--)
  {
    ll n;
    cin >> n;

    ll temp = 0;
    queue<ll> q;

    while( temp <= n && temp <=9)
    {
      q.push(temp);
      temp++;
    }

    while(!q.empty())
    {
      temp = q.front();
      cout << temp << " ";
      q.pop();

      ll lastDigit = temp%10;

      if(lastDigit == 0)
      {
        ll x = temp*10 + (lastDigit + 1);

        if(x <= n && temp!= 0)
            q.push(x);
      }

      else if(lastDigit == 9)
      {
        ll x = temp*10 + (lastDigit - 1);

        if(x <= n)
            q.push(x);
      }

      else
      {
        ll x = temp*10 + (lastDigit - 1);
        ll y = temp*10 + (lastDigit + 1);

        if(x <=n)
          q.push(x);

        if(y <=n)
            q.push(y);
      }

    }

    cout << "\n";

  }




}
