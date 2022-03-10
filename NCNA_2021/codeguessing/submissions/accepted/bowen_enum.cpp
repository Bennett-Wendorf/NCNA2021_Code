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


int main() {
  string pos;
  int p, q, cases = 0, fr, fs;
  cin >> p >> q >> pos;
  REP(r,1,10) {
    if (r == p || r == q) continue;
    REP(s,r+1,10) {
      if (s == p || s == q) continue;
      VI vs({p, q, r, s});
      sort(vs.begin(), vs.end());
      string curpos;
      REP(i,0,4) {
        curpos += vs[i] == p || vs[i] == q ? 'A' : 'B';
      }
      if (curpos == pos) {
        fr = r; fs = s;
        cases++;
      }
    }
  }
  if (cases != 1) cout << -1 << endl;
  else cout << fr << " " << fs << endl;
  return 0;
}
