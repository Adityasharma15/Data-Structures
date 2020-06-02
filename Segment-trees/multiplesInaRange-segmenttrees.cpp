#include<bits/stdc++.h>
#define ll long long
using namespace std;

void createSegmentTree(vector<ll>&vec, vector<ll>&tree, ll index, ll left,ll right)
{
  if(left > right)
    return;

  if(left == right)
  {
      if(vec[left]%5==0)
        tree[index] = 1;

      else
        tree[index] = 0;

      return;
  }

  ll mid = (left + right )/2;

  //left sub-tree
  createSegmentTree(vec, tree, index*2, left , mid);

  //right sub-tree
  createSegmentTree(vec, tree, index*2 + 1, mid + 1, right);

  tree[index] = tree[index*2]+tree[index*2 + 1];
  return;
}

ll query(vector<ll> &tree, ll index, ll ql, ll qr, ll l, ll r)
{
  // if range is not inside quer
  if(ql > r || qr<l)
    {
      // cout << index << " not inside \n";
      return 0;
    }

  // if range completely in between query
  if(ql <= l && qr >= r)
  {
    // cout << tree[index] <<  " " << index << " fully inside \n";
    return tree[index];
  }

  // if range lies partially in between query
  ll mid = (l+r)/2;
  ll left = query(tree, index*2 , ql, qr , l, mid);
  ll right = query(tree, index*2 +1, ql , qr , mid+1, r);
  return (left+right);
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
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n,0);

  for(ll i = 0;i <n; i++)
    cin >> vec[i];

  // 4*n + 1 is an approximated upper bound
  vector<ll> tree(4*n + 1, 0);
  ll index = 1, left = 0, right = n-1;
  createSegmentTree(vec , tree, index , left , right);

  ll ql , qr;

  while(q--)
  {
  cin >> ql >> qr;

  if(ql>qr)
    swap(ql, qr);

  cout << query(tree, 1, ql-1, qr-1, 0, n - 1) << "\n";
    }
  }
  return 0;
}
