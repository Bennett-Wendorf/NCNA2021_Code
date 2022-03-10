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
#define MAXN 1005

int main() {
  int n;
  cin >> n;
  vector<PII> ts;
  REP(j,0,n) {
    int t, i;
    cin >> t >> i;
    ts.push_back(PII(i, t));
  }
  sort(ts.begin(), ts.end());
  int cur = 1;
  int lag = 0;
  REP(i,0,n) {
    int t = ts[i].second;
    lag += max(t - cur, 0);
    cur = max(cur, t) + 1;
  }
  cout << lag << endl;
  return 0;
}
