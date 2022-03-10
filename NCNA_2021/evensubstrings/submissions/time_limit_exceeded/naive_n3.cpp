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

char s[MAXN];
int main() {
  cin >> (s + 1);
  int n = strlen(s + 1);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      ll ans = 0;
      REP(i,l,r+1) {
        int m = 0;
        REP(j,i,r+1) {
          m ^= 1 << (s[j] - 'a');
          if (m == 0) ans++;
        }
      }
      cout << ans << endl;
    } else {
      int i;
      char letter[2];
      cin >> i >> letter;
      s[i] = letter[0];
    }
  }
  return 0;
}
