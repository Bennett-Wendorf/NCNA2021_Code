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

PII operator - (PII &a, PII &b) { return PII(a.first - b.first, a.second - b.second); }
PII operator * (PII &a, int k){ return PII(a.first * k, a.second * k); }
ll cross(PII &a, PII &b) { return (ll)a.first * b.second - (ll)a.second * b.first; }
ll dot(PII &a, PII &b){ return (ll)a.first * b.first + (ll)a.second * b.second; }
ll sqlen(PII &x) { return (ll)x.first * x.first + (ll)x.second * x.second; }
int sn(ll v) { return v > 0 ? 1 : v < 0 ? -1 : 0; }
struct seg {
	PII p, q;
	seg(){}
	seg(PII &_p, PII &_q){
		p = _p; q = _q;
	}
};
bool hitLineSeg(PII &a, PII &b, seg &s) {
	PII &c = s.p, &d = s.q;
	PII ac = c - a, ad = d - a, ab = b - a;
	ll crv1 = cross(ab, ad), crv2 = cross(ac, ab);
	if (sn(crv1) * sn(crv2) > 0) return 1; // excluding touch
	return 0;
}
bool pointOnSeg(PII &x, seg &s) {
  PII xp = s.p - x, xq = s.q - x;
  ll d = dot(xp, xq);
  return x == s.p || x == s.q || (d < 0 && d * d == sqlen(xp) * sqlen(xq));
}

bool hitSegSeg(seg &s1, seg &s2) { // segments must not be parallel and overlapping
	PII ab = s1.p - s1.q, cd = s2.p - s2.q;
	if (cross(ab, cd) == 0) return 0; // disjoint parallel
	return hitLineSeg(s1.p, s1.q, s2) && hitLineSeg(s2.p, s2.q, s1);
}
int r, c;
double dst[MAXN][MAXN];
double e[MAXN][MAXN][MAXN][MAXN];
char g[MAXN][MAXN];
bool connected(PII p, PII q) {
  if (p.first == q.first || p.second == q.second) return true;
  seg edge(p, q);
  PII p2 = p * 2, q2 = q * 2;
  seg dEdge(p2, q2);
  REP(i,0,r) {
    REP(j,0,c) {
      if (g[i][j] == '#') {
        vector<PII> square({ PII(i, j), PII(i + 1, j), PII(i + 1, j + 1), PII(i, j + 1) });
        PII center(2*i + 1, 2*j + 1);
        if (pointOnSeg(center, dEdge)) return false;
        REP(k,0,4) {
          seg side(square[k], square[(k + 1) & 3]);
          if (hitSegSeg(edge, side)) return false;
        }
      }
    }
  }
  return true;
}
int main() {
  cin >> r >> c;
  REP(i,0,r) cin >> g[i];
  REP(i,0,r+1) {
    REP(j,0,c+1) {
      dst[i][j] = INF;
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
