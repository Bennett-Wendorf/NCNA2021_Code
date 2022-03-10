// "no" when T is attacked by a non-removable knight.
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
bool invincible[MAXN][MAXN];
int main() {
  int r, c;
  cin >> r >> c;
  REP(i,0,r) cin >> g[i];
  REP(i,0,r) {
    REP(j,0,c) {
      if (g[i][j] == 'K') {
        REP(d,0,8) {
          int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
          if (ni < 0 || ni >= r || nj < 0 || nj >= c || g[ni][nj] != 'K') continue;
          invincible[ni][nj] = invincible[i][j] = true;
        }
      }
    }
  }
  REP(i,0,r) {
    REP(j,0,c) {
      if (g[i][j] == 'T') {
         REP(d,0,8) {
          int ni = i + dirKnight[d][0], nj = j + dirKnight[d][1];
          if (ni < 0 || ni >= r || nj < 0 || nj >= c || g[ni][nj] != 'K') continue;
          if (invincible[ni][nj]) return puts("no"), 0;
        }
      }
    }
  }
  puts("yes");
  return 0;
}
