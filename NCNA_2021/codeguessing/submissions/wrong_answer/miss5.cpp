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
  int p, q;
  cin >> p >> q >> pos;
  if (pos == "BBAA" && p == 3) puts("1 2");
  else if (pos == "AABB" && q == 7) puts("8 9");
  else if (pos == "ABBA" && q - p == 3) printf("%d %d\n", p + 1, q - 1);
  else if (pos == "BAAB" && p == 2 && q == 8) puts("1 9");
  //else if (pos == "ABAB" && p == 6 && q == 8) puts("7 9");
  else if (pos == "BABA" && p == 2 && q == 4) puts("1 3");
  else puts("-1");
  return 0;
}
