// Asserts that input is tree.
// Does not check input format and other values not related to tree structure.

#include<iostream>
#include<cassert>

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define MAXN 200005

int rep[MAXN];
int find(int x) {
  if (rep[x] == x) return x;
  return rep[x] = find(rep[x]);
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  REP(i,1,n+1) rep[i] = i;
  REP(i,0,n-1) {
    int x, y;
    cin >> x >> y;
    int rx = find(x), ry = find(y);
    if (rx != ry) rep[rx] = ry;
  }
  REP(i,1,n+1) {
    assert(find(i) == find(1));
  }
  return 42;
}
