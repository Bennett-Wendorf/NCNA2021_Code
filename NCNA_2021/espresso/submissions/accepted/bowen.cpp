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
  int n, s;
  cin >> n >> s;
  int cur = s, ans = 0;
  REP(i,0,n) {
    char order[3];
    cin >> order;
    int x = order[0] - '0';
    if (order[1] == 'L') x++;
    if (cur - x < 0) {
      cur = s;
      ans++;
    }
    cur -= x;
  }
  cout << ans << endl;
  return 0;
}
