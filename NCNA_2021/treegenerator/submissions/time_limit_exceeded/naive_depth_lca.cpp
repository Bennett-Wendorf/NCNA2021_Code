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

VI adj[MAXN];
int dep[MAXN], digit[MAXN], par[MAXN];
void dfs(int x, int p, int d) {
  dep[x] = d;
  par[x] = p;
  for (auto &y: adj[x]) {
    if (y == p) continue;
    dfs(y, x, d + 1);
  }
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  REP(i,0,n-1) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1, 0);
  REP(i,1,n+1) cin >> digit[i];
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    VI pa, pb;
    while (a != b) {
      if (dep[a] > dep[b]) {
        pa.push_back(a);
        a = par[a];
      } else {
        pb.push_back(b);
        b = par[b];
      }
    }
    pb.push_back(b);
    int v = 0;
    REP(i,0,pa.size()) v = ((ll)v * 10 + digit[pa[i]]) % m;
    for (int i = (int)pb.size() - 1; i >= 0; i--) v = ((ll)v * 10 + digit[pb[i]]) % m;
    printf("%d\n", v);
  }
  return 0;
}
