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
#define MAXN 64

ll ans;
string brackets = "()[]{}<>";
int bIndex[128];
void solve(string &s, ll &b, int bsz, int i) {
  if (i == s.size()) {
    if (bsz == 0) ans++;
    return;
  }
  if (s[i] == '?') {
    REP(br,0,4) {
      b = (b << 2) + br;
      solve(s, b, bsz + 1, i + 1);
      b >>= 2;
    }
    if (bsz) {
      int br = b & 3;
      b >>= 2;
      solve(s, b, bsz - 1, i + 1);
      b = (b << 2) + br;
    }
  } else if (bIndex[s[i]] & 1) {
    int br = b & 3;
    if (br != (bIndex[s[i]] >> 1)) return;
    ll ob = b;
    b >>= 2;
    solve(s, b, bsz - 1, i + 1);
    b = ob;
  } else {
    int br = bIndex[s[i]] >> 1;
    b = (b << 2) + br;
    solve(s, b, bsz + 1, i + 1);
    b >>= 2;
  }
}

int main() {
  string s;
  cin >> s;
  FILL(bIndex, -1);
  for (int index = 0; index < brackets.size(); index++) bIndex[brackets[index]] = index;
  ll b = 0;
  solve(s, b, 0, 0);
  cout << ans << endl;
  return 0;
}
