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

const int mod = 1000000007;
int dp[MAXN];
int main() {
  string p, s;
  cin >> p >> s;
  set<string> solved;
  int n = s.size();
  int ans = 0;
  REP(it,0,n) {
    if (solved.find(s) == solved.end()) {
      solved.insert(s);
      FILL(dp, 0);
      dp[0] = 1;

      REP(i,1,p.size()+1) {
        char cp = p[i - 1];
        for (int j = n - 1; j >= 0; j--) {
          char cs = s[j];
          if (cp == cs) dp[j + 1] = (dp[j + 1] + dp[j]) % mod;
        }
      }
      ans = (ans + dp[n]) % mod;
    }
    rotate(s.begin(), s.begin() + 1, s.end());
  }
  cout << ans << endl;
  return 0;
}
