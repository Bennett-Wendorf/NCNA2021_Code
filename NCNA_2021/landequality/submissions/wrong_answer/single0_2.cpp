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
#define MAXN 64

int val[MAXN][MAXN];
int main() {
  int r, c;
  cin >> r >> c;
  int cnt[3] = {};
  int x0 = -1, y0 = -1;
  REP(i,0,r) {
    REP(j,0,c) {
      cin >> val[i][j];
      cnt[val[i][j]]++;
    }
  }
  ll ans = -1;
  if (cnt[0] >= 2) ans = 0;
  else if (cnt[0] == 0) ans = (1LL << ((cnt[2] + 1) / 2)) - (1LL << (cnt[2] / 2));
  else if (cnt[0] == 1) {
    if (cnt[2] == 0) ans = 1;
    else ans = 2;
  }
  cout << ans << endl;
  return 0;
}
