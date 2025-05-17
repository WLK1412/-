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
    if(mid - a[i] > b[i])return 0;//����յ�����Ŀ�����к�ûд�ļ��������࣬�Ǿ��Դղ���
    else res -= (mid - a[i]);
  }
  return res > 0;//�Ƿ������µ�bϵ
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
      l = mid + 1;//������߽磬Ѱ�Ҹ���Ŀ���
    }
    else r = mid - 1;//������߽磬Ѱ�Ҹ�С����
  }
  cout << ans << '\n';
  return 0;
}
