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
void solve(string &s, map<string, int> &d, string &b, int i) {
  if (i == s.size()) {
    d[b]++;
    return;
  }
  if (s[i] == '?') {
    for (int j = 0; j < 8; j+= 2) {
      b.push_back(brackets[j]);
      solve(s, d, b, i + 1);
      b.pop_back();
    }
    if (b.size() && (bIndex[b.back()] & 1) == 0) {
      char br = b.back();
      b.pop_back();
      solve(s, d, b, i + 1);
      b.push_back(br);
    }
  } else if (bIndex[s[i]] & 1) {
    if (!b.size() || (bIndex[b.back()] ^ 1) != bIndex[s[i]]) return;
    char br = b.back();
    b.pop_back();
    solve(s, d, b, i + 1);
    b.push_back(br);
  } else {
    b.push_back(s[i]);
    solve(s, d, b, i + 1);
    b.pop_back();
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
  map<string, int> ld, rd;
  string b = "";
  solve(left, ld, b, 0);
  solve(right, rd, b, 0);
  ll ans = 0;
  for (auto &v: ld) {
    ans += (ll)v.second * rd[v.first];
  }
  cout << ans << endl;
  return 0;
}
