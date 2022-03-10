#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 200005


ll d[MAXN * 2];
int nxt[MAXN];
int main() {
  int n, p, k;
  cin >> n >> p >> k;
  REP(i,1,n+1) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  REP(i,1,2*n+1) d[i] += d[i - 1];
  ll onePass = d[n];
  ll basePass = p / onePass;
  REP(i,1,n+1) {
    ll rem = p % onePass;
    int l = i, r = i + n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      ll t = d[m] - d[i - 1];
      if (t > rem) r = m - 1;
      else l = m + 1;
    }
    nxt[i] = l > n ? l - n : l;
  }
  int cur = 1;
  ll ans = 0;
  while (k) {
    ans += basePass;
    if (nxt[cur] < cur) ans++;
    cur = nxt[cur];
    k--;
  }
  cout << ans << endl;
  return 0;
}
