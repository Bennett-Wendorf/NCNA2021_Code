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
#define C 6
#define MAXSEG (MAXN<<2)
VI val[MAXSEG];
int lz[MAXSEG], baseval[MAXN];
char s[MAXN];
void add(int k, int nl, int nr, int l, int r, int v);
void build(int k, int nl, int nr) {
  if (nl == nr) {
    val[k] = VI(1<<C, 0);
    val[k][baseval[nl]]++;
    return;
  }
  int nm = (nl + nr) / 2;
  build(2*k+1, nl, nm);
  build(2*k+2, nm+1, nr);
  val[k] = VI(1<<C, 0);
  REP(m,0,1<<C) val[k][m] = val[2*k+1][m] + val[2*k+2][m];
}
void relax(int k, int nl, int nr){
	int nm = (nl+nr)>>1;
	add(2*k+1, nl, nm, nl, nm, lz[k]);
	add(2*k+2, nm+1, nr, nm+1, nr, lz[k]);
	lz[k] = 0;
}
void add(int k, int nl, int nr, int l, int r, int v){
	if(r<nl || l>nr) return;
	if(l<=nl && nr<=r){
    VI nval(1<<C, 0);
    REP(m,0,1<<C) nval[m ^ v] += val[k][m];
    val[k] = nval;
		lz[k] ^= v;
		return;
	}
	int nm = (nl+nr)>>1;
	if(lz[k]) relax(k, nl, nr);
	add(2*k+1, nl, nm, l, r, v);
	add(2*k+2, nm+1, nr, l, r, v);
  REP(m,0,1<<C) val[k][m] = val[2*k+1][m] + val[2*k+2][m];
}

VI get(int k, int nl, int nr, int l, int r){
	if(r<nl || l>nr) return VI(1<<C, 0);
	if(l<=nl && nr<=r) return val[k];
	if(lz[k]) relax(k, nl, nr);
	int nm = (nl+nr)>>1;
  VI res = get(2*k+1, nl, nm, l, r);
	VI rres = get(2*k+2, nm+1, nr, l, r);
  REP(m,0,1<<C) res[m] += rres[m];
	return res;
}

int main() {
  scanf("%s", s+1) ;
  int n = strlen(s + 1);
  REP(i,1,n+1) baseval[i] = baseval[i - 1] ^ (1 << (s[i] - 'a'));
  build(0, 0, n);
  int q;
  scanf("%d", &q) ;
  while (q--) {
    int t;
    scanf("%d", &t) ;
    if (t == 1) {
      int l, r;
      scanf("%d %d", &l, &r) ;
      VI res = get(0, 0, n, l - 1, r);
      ll ans = 0;
      REP(m,0,1<<C) ans += (ll)res[m] * (res[m] - 1) / 2;
      printf("%lld\n", ans) ;
    } else {
      int i;
      char letter[2];
      scanf("%d %c", &i, letter) ;
      add(0, 0, n, i, n, (1 << (s[i] - 'a')) ^ (1 << (letter[0] - 'a')));
      s[i] = letter[0];
    }
  }
  return 0;
}
