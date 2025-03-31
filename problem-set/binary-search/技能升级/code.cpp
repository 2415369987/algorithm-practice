#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int A[N], B[N];
int n, m;
typedef long long LL;
bool check(int x) {
  LL res = 0;
  for (int i = 1; i <= n; i ++ ) {
    if (A[i] >= x) {
      res += (A[i] - x) / B[i] + 1;
    }
  }
  return res >= m;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) cin >> A[i] >> B[i];
  
  int l = 0, r = 1e6;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }

  LL ans = 0, cnt = 0;
  for (int i = 1; i <= n; i ++ ) {
    if (A[i] >= r) {
      int k = (A[i] - r) / B[i];
      int ed = A[i] - k * B[i];
      ans += (LL) (A[i] + ed) * (k + 1) / 2;
      cnt += k + 1;
    }
  }
  if (cnt > m) ans -= (cnt - m) * r;
  cout << ans << endl;
  return 0;
}
