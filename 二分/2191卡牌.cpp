#include <iostream>
using namespace std;
#define ll long long
const int N = 2e5 + 9;
int n;
ll m, s;
int a[N], b[N];
bool check(int mid)
{
  ll res = m;
  for(int i = 1;i < n;i ++)
  {
    if(mid - a[i] > b[i])return 0;//如果凑的牌数目比已有和没写的加起来都多，那绝对凑不到
    else res -= (mid - a[i]);
  }
  return res > 0;//是否有余下的b系
}
int main()
{
  cin >> n >> m;
  for(int i = 1;i <= n;i ++)cin >> a[i];
  for(int i = 1;i <= n;i ++)cin >> b[i];
  int l = 0, r = 2e5;
  int mid, ans = 0;
  while(l <= r)
  {
    mid = (l + r) >> 1;
    if(check(mid))
    {
      ans = mid;
      l = mid + 1;//更新左边界，寻找更大的可能
    }
    else r = mid - 1;//更新左边界，寻找更小可能
  }
  cout << ans << '\n';
  return 0;
}
