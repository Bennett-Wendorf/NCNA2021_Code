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
#define MAXN 755

int r, c;
int dirKnight[8][2] = { -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1 };
int dirRook[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
char g[MAXN][MAXN];
int attacked[MAXN][MAXN];
bool v[MAXN][MAXN][4], arrived[MAXN][MAXN], lastArrived[MAXN][MAXN];
void dfs(int i, int j, int d) {
  v[i][j][d] = true;
  // cerr << i << " " << j << " " << d << endl;
  if (!attacked[i][j]) {
    arrived[i][j] = true;
    // if (g[i][j] == 'K') g[i][j] = '.';
  }
  if (arrived[i][j] && g[i][j] != 'K') {
    REP(d,0,4) if (!v[i][j][d]) dfs(i, j, d);
  }
  int ni = i + dirRook[d][0], nj = j + dirRook[d][1];
  if (ni < 0 || ni >= r || nj < 0 || nj >= c || v[ni][nj][d]) return;
  if (!(g[ni][nj] == 'K' && attacked[ni][nj])) dfs(ni, nj, d);
}
int main() {
  cin >> r >> c;
  int ri, rj, ti, tj;
  REP(i,0,r) {
    cin >> g[i];
    REP(j,0,c) {
      if (g[i][j] == 'R') {
        ri = i;
        rj = j;
        g[i][j] = '.';
      } else if (g[i][j] == 'K') {
        REP(d,0,8) {
          int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
          if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
          attacked[ni][nj]++;
        }
      } else if (g[i][j] == 'T') {
        ti = i;
        tj = j;
      }
    }
  }
  bool change = true;
  int it = 0;
  while (change) {
    it++;
    change = false;
    FILL(attacked, 0);
    REP(i,0,r) {
      REP(j,0,c) {
        if (g[i][j] == 'K') {
          REP(d,0,8) {
            int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
            attacked[ni][nj]++;
          }
        }
      }
    }
    FILL(arrived, false);
    FILL(v, false);
    REP(d,0,4) dfs(ri, rj, d);
    if (arrived[ti][tj]) {
      cerr << it << endl;
      return puts("yes"), 0;
    }
    REP(i,0,r) {
      REP(j,0,c) {
        if (arrived[i][j] && g[i][j] == 'K') g[i][j] = '.';
        if (lastArrived[i][j] != arrived[i][j]) change = true;
      }
    }
    memcpy(lastArrived, arrived, sizeof(arrived));
  }
  cerr << it << endl;
  puts("no");
  return 0;
}
