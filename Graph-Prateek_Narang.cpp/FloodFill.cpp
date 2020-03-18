#include<bits/stdc++.h>
#define ll long long

using namespace std;

int arr[101][101];

void floodfill(int a, int b, int k, int n, int m, int  arr[][m], int c)
{
  if(a<=0|| b<=0|| a>=n||b>=m || arr[a][b]!=c)
    return;

  arr[a][b] = k;

  floodfill(a - 1 , b + 1, k, arr, n , m , c);
  floodfill(a - 1 , b - 1, k, arr, n , m , c);
  floodfill(a + 1 , b + 1, k, arr, n , m , c);
  floodfill(a + 1 , b - 1, k, arr, n , m , c);
}

int main()
{
  ll t;
  cin >> t;

  while(t--)
  {
      int n , m;
      cin >> n >> m;

      for(ll i = 0; i<n; i++)
      {
          for(ll j = 0; j<m; j++)
            cin >> arr[i][j];
      }

      int a, b, k;
      cin >> a >> b >> k;

      int c = arr[a][b];

      floodfill(a, b, k, n , m, arr, c);

      for(ll i = 0; i<n; i++)
      {
          for(ll j = 0; j<m; j++)
            cout << arr[i][j] << " ";

          cout << "\n";
      }
  }
}
