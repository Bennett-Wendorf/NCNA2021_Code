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

int d[MAXN];
ll slow(int n, int p, int k) {
  int cur = 1;
  ll ans = 0;
  while (k--) {
    int curp = p;
    while (true) {
      int curd = d[cur];
      if (curd > curp) break;
      curp -= curd;
      if (++cur > n) {
        ans++;
        cur = 1;
      }
    }
  }
  return ans;
}

int main() {
  int n, p, k;
  cin >> n >> p >> k;
  REP(i,1,n+1) {
    cin >> d[i];
  }
  cout << slow(n, p, k) << endl;
  return 0;
}
