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

#define MAXV 1500000
int P, dvd[MAXV], prm[MAXV];
void sieve(){
  FILL(dvd,-1); P = 0;
  for(int i=2; i<MAXV; i++){
    if(dvd[i]!=-1) continue;
    prm[P++] = i;
    for(int j=1; i*j<MAXV; j++) dvd[i*j] = i;
  }
}

int main() {
  sieve();
  int l, h;
  string p;
  cin >> l >> h >> p;
  l--; h--;
  int ans = 0;
  REP(i,l,h+1) {
    int prime = prm[i];
    string s = to_string(prime);
    if ((int)s.find(p) != -1) ans++;
  }
  cout << ans << endl;
  return 0;
}
