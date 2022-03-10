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
#define LOGN 18

int N, M;
VI adj[MAXN];
int digit[MAXN], ans;
void dfs(int x, int p, int t, int v) {
  v = ((ll)v * 10 + digit[x]) % M;
  if (t == x) {
    ans = v;
    return;
  }
  int sz = adj[x].size();
  REP(i,0,sz) {
    int y = adj[x][i];
    if (y == p) continue;
    dfs(y, x, t, v);
  }
}

int main() {
  int q;
  cin >> N >> M >> q;
  REP(i,0,N-1) {
    int x, y;
    cin >> x >> y; x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  REP(i,0,N) cin >> digit[i];
  while (q--) {
    int a, b;
    cin >> a >> b; a--; b--;
    dfs(a, -1, b, 0);
    cout << ans << endl;
  }
  return 0;
}
