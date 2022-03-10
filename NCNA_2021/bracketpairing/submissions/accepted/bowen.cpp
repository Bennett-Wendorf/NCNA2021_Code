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

string brackets = "()[]{}<>";
int bIndex[128];
void solve(string &s, map<int, int> &d, int &b, int bsz, int i) {
  if (i == s.size()) {
    d[b + (1 << (2 * bsz))]++;
    return;
  }
  if (s[i] == '?') {
    REP(br,0,4) {
      b = (b << 2) + br;
      solve(s, d, b, bsz + 1, i + 1);
      b >>= 2;
    }
    if (bsz) {
      int br = b & 3;
      b >>= 2;
      solve(s, d, b, bsz - 1, i + 1);
      b = (b << 2) + br;
    }
  } else if (bIndex[s[i]] & 1) {
    int br = b & 3;
    if (br != (bIndex[s[i]] >> 1)) return;
    int ob = b;
    b >>= 2;
    solve(s, d, b, bsz - 1, i + 1);
    b = ob;
  } else {
    int br = bIndex[s[i]] >> 1;
    b = (b << 2) + br;
    solve(s, d, b, bsz + 1, i + 1);
    b >>= 2;
  }
}

int main() {
  string s;
  cin >> s;
  int n = s.size() / 2;
  string left = s.substr(0, n);
  string right = s.substr(n, n);
  reverse(right.begin(), right.end());

  FILL(bIndex, -1);
  for (int index = 0; index < brackets.size(); index++) bIndex[brackets[index]] = index;

  for (int i = 0; i < right.size(); i++) {
    if (bIndex[right[i]] == -1) continue;
    right[i] = brackets[bIndex[right[i]] ^ 1];
  }
  map<int, int> ld, rd;
  int b = 0;
  solve(left, ld, b, 0, 0);
  solve(right, rd, b, 0, 0);
  ll ans = 0;
  for (auto &v: ld) ans += (ll)v.second * rd[v.first];
  cout << ans << endl;
  return 0;
}
