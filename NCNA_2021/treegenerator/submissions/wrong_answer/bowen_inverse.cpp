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
int dpar[LOGN + 1][MAXN], digit[MAXN], pow10[MAXN], pow10inv[MAXN];
int valUp[LOGN + 1][MAXN], valDown[LOGN + 1][MAXN];
int par[MAXN], dep[MAXN];
void dfs(int x, int p, int depth) {
  int sz = adj[x].size();
  par[x] = p;
  dep[x] = depth;
  REP(i,0,sz) {
    int y = adj[x][i];
    if (y == p) continue;
    dfs(y, x, depth + 1);
  }
}

void initLogTreepar(int root) {
  dfs(root, -1, 0);
  FILL(valUp, -1);
  FILL(valDown, -1);
  FILL(dpar, -1);
  REP(i, 0, N) {
    dpar[0][i] = par[i];
    valUp[0][i] = digit[i] % M;
    valDown[0][i] = digit[i] % M;
  }
  REP(j, 1, LOGN + 1) {
    int span = 1 << (j - 1);
    REP(i, 0, N) {
      int p = dpar[j - 1][i];
      if (p == -1) continue;
      dpar[j][i] = dpar[j - 1][p];
      valUp[j][i] = ((ll)valUp[j - 1][i] * pow10[span] % M + valUp[j - 1][p]) % M;
      valDown[j][i] = ((ll)valDown[j - 1][p] * pow10[span] % M + valDown[j - 1][i]) % M;
    }
  }
}

int getDistUp(int a, int d) {
  for (int j = LOGN; j >= 0; j--) if (d & (1<<j)) a = dpar[j][a];
  return a;
}

int lca(int a, int b) {
  int d = 0, mind = min(dep[a], dep[b]);
  for (int j = LOGN; j >= 0; j--) {
    int nd = d + (1 << j);
    if (nd > mind) continue;
    if (getDistUp(a, dep[a] - nd) == getDistUp(b, dep[b] - nd)) d = nd;
  }
  return getDistUp(a, dep[a] - d);
}

ll mulm(ll a, ll b, ll mod){
	double x = a;
	ll c = x * b / mod;
	ll ans = (a * b - c * mod) % mod;
	if (ans < 0) ans += mod;
	return ans;
}
ll powm(ll a, ll k, ll mod){
	ll ans=1;
	while(k){
		if(k&1) ans=mulm(ans,a,mod);
		k>>=1; a=mulm(a,a,mod);
	}
	return ans;
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
  pow10[0] = 1 % M;
  pow10inv[0] = 1 % M;
  int inv10 = powm(10, M-2, M);
  REP(i,1,N) {
    pow10[i] = (ll)pow10[i - 1] * 10 % M;
    pow10inv[i] = (ll)pow10inv[i - 1] * inv10 % M;
  }
  initLogTreepar(0);
  while (q--) {
    int a, b;
    cin >> a >> b; a--; b--;
    int c = lca(a, b);
    int acLen = dep[a] - dep[c] + 1;
    int bcLen = dep[b] - dep[c];
    int obcLen = bcLen;
    int cura = a, curb = b;
    int acAns = 0, bcAns = 0;
    for (int j = LOGN; j >= 0; j--) {
      if (acLen & (1 << j)) {
        acLen ^= 1 << j;
        acAns = (acAns + (ll)valUp[j][cura] * pow10[acLen] % M) % M;
        cura = dpar[j][cura];
      }
      if (bcLen & (1 << j)) {
        bcAns = (bcAns + (ll)valDown[j][curb] * pow10[obcLen - bcLen] % M) % M;
        curb = dpar[j][curb];
        bcLen ^= 1 << j;
      }
    }
    int ans = ((ll)acAns * pow10[dep[c]] % M * pow10inv[dep[c]] % M * pow10[obcLen] % M + bcAns) % M;
    cout << ans << endl;
  }
  return 0;
}
