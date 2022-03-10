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
int nxt[MAXN], lastDay[MAXN];
ll dayPass[MAXN];

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
    REP(l,i,i+n) {
      ll t = d[l] - d[i - 1];
      if (t > rem) {
        nxt[i] = l > n ? l - n : l;
        break;
      }
    }
  }
  int cur = 1, day = 1;
  bool cycled = false;
  ll ans = 0;
  while (k) {
    if (lastDay[cur] && !cycled) {
      cycled = true;
      ll cyclePass = dayPass[day - 1] - dayPass[lastDay[cur] - 1];
      int cycleDay = day - lastDay[cur];
      ans += k / cycleDay * cyclePass;
      k %= cycleDay;
      if (k == 0) break;
    }
    lastDay[cur] = day;
    ans += basePass;
    if (nxt[cur] < cur) ans++;
    cur = nxt[cur];
    if (!cycled) dayPass[day++] = ans;
    k--;
  }
  cout << ans << endl;
  return 0;
}
