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

int dirKnight[8][2] = { -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1 };
int dirRook[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
char g[MAXN][MAXN];
int attacked[MAXN][MAXN];
bool v[MAXN][MAXN];
void print(int r, int c) {
  REP(i,0,r) {
    REP(j,0,c) {
      char ch = v[i][j] ? '*' : g[i][j];
      if (ch == '.') {
        bool ok = true;
        REP(d,0,8) {
          int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
          if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
          if (g[ni][nj] == 'K' && !v[ni][nj]) ok = false;
        }
        if (ok) ch = '@';
      }
      cout << ch;
    }
    cout << endl;
  }
}
int main() {
  int r, c;
  cin >> r >> c;
  int s = max(r, c);
  queue<PII> q;
  REP(i,0,r) {
    cin >> g[i];
    REP(j,0,c) {
      if (g[i][j] == 'R') {
        v[i][j] = true;
        q.push(PII(i, j));
      } else if (g[i][j] == 'K') {
        REP(d,0,8) {
          int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
          if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
          attacked[ni][nj]++;
        }
      }
    }
  }
  while (q.size()) {
    PII cur = q.front(); q.pop();
    int i = cur.first, j = cur.second;
    if (g[i][j] == 'K') {
      REP(d,0,8) {
        int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
        if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
        if (--attacked[ni][nj] == 0) {
          REP(dd,0,4) {
            REP(k,1,s) {
              int nni = ni + dirRook[dd][0] * k, nnj = nj + dirRook[dd][1] * k;
              if (nni < 0 || nni >= r || nnj < 0 || nnj >= c) break;
              if (v[nni][nnj] && !v[ni][nj]) {
                v[ni][nj] = true;
                q.push(PII(ni, nj));
              } else if (g[nni][nnj] == 'K') break;
            }
          }
        }
      }
    }
    REP(d,0,4) {
      REP(k,1,s) {
        int ni = i + dirRook[d][0] * k, nj = j + dirRook[d][1] * k;
        if (ni < 0 || ni >= r || nj < 0 || nj >= c) break;
        if (v[ni][nj]) continue;
        if (attacked[ni][nj] == 0) {
          v[ni][nj] = true;
          q.push(PII(ni, nj));
        }
        if (g[ni][nj] == 'K' && !v[ni][nj]) break;
      }
    }
  }
  print(r, c);
  return 0;
}
