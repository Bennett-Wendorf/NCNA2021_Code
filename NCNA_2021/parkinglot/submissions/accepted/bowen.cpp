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
#define MAXN 55

struct line {
	ll a, b, c;
	line(){}
	line(PII &p, PII &q){
		a = q.second - p.second; b = p.first - q.first; c = (ll)q.first * p.second - (ll)p.first * q.second;
	}
  int gety(int x, bool excluTouch) {
    int y = (-c - a * x) / b;
    if (excluTouch && (-c - a * x) % b == 0) y--;
    return y;
  }
};
int sign(ll v) {
  return v > 0 ? 1 : v < 0 ? -1 : 0;
}
double dst[MAXN][MAXN];
char g[MAXN][MAXN];
int presum[MAXN][MAXN];
bool connected(PII p, PII q) {
  if (p.first == q.first || p.second == q.second) return true;
  line l(p, q);
  int xs = min(p.first, q.first), xe = max(p.first, q.first);
  REP(x,xs,xe) {
    int y, y1;
    if (-sign(l.a) * sign(l.b) > 0) {
      y = l.gety(x, false);
      y1 = l.gety(x + 1, true);
    } else {
      y = l.gety(x, true);
      y1 = l.gety(x + 1, false);
    }
    if (y > y1) swap(y, y1);
    if (presum[x][y1] - (y - 1 >= 0 ? presum[x][y - 1] : 0)) return false;
  }
  return true;
}
int main() {
  int r, c;
  cin >> r >> c;
  REP(i,0,r) cin >> g[i];
  REP(i,0,r+1) {
    REP(j,0,c+1) {
      dst[i][j] = INF;
      presum[i][j] = (g[i][j] == '#') + (j - 1 >= 0 ? presum[i][j - 1] : 0);
    }
  }
  priority_queue<pair<double,PII>> pq;
  dst[0][0] = 0;
  pq.push(make_pair(0, PII(0, 0)));
  while (pq.size()) {
    pair<double,PII> cur = pq.top(); pq.pop();
    double d = -cur.first;
    int x = cur.second.first, y = cur.second.second;
    if (d > dst[x][y]) continue;
    REP(x2,0,r+1) {
      REP(y2,0,c+1) {
        if (!connected(cur.second, PII(x2, y2))) continue;
        double w = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        if (dst[x][y] + w < dst[x2][y2]) {
          dst[x2][y2] = dst[x][y] + w;
          pq.push(make_pair(-dst[x2][y2], PII(x2, y2)));
        }
      }
    }
  }
  printf("%.12lf\n", dst[r][c]);
  return 0;
}
