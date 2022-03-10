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

char g[4][10];
int main() {
  string t;
  cin >> t;
  FILL(g, ' ');
  REP(i,0,4) {
    int d = t[i] - '0';
    REP(j,0,4) {
      int offset = i >= 2 ? 2 : 0;
      if (d & (1 << j)) g[3 - j][2 * i + offset] = '*';
      else g[3 - j][2 * i + offset] = '.';
    }
  }
  REP(i,0,4) {
    g[i][9] = 0;
    cout << g[i] << endl;
  }
  return 0;
}
