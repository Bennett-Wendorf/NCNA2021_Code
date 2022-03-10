/*
 *   Even Substrings.  Tomas Rokicki.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std ;
using ll = long long ;
string s ;
int n ;
const int MAXSIZE = 200000 ;
const int CHUNK = 2048 ;
const int MAXCHUNKS = MAXSIZE / CHUNK + 1 ;
struct chunkdat {
   int valid ;
   int deltamask ;
   int cnts[64] ;
   void update(int ci) {
      for (int i=0; i<64; i++)
         cnts[i] = 0 ;
      int hi = min(n, (ci + 1) * CHUNK) ;
      int v = 0 ;
      for (int i=ci*CHUNK; i<hi; i++) {
         v ^= 1<<(s[i]-'a') ;
         cnts[v]++ ;
      }
      deltamask = v ;
      valid = 1 ;
   }
} chunks[MAXCHUNKS] ;
int main() {
   ll q ;
   cin >> s >> q ;
   n = s.size() ;
   while (q--) {
      ll l, r, i, t ;
      char let ;
      cin >> t ;
      if (t == 1) {
         ll cnts[64] ;
         for (int i=0; i<64; i++)
            cnts[i] = 0 ;
         int v = 0 ;
         cin >> l >> r ;
         cnts[0] = 1 ;
         l-- ;
         for (; l < r && l % CHUNK != 0; l++) {
            v ^= 1<<(s[l]-'a') ;
            cnts[v]++ ;
         }
         while (l + CHUNK < r) {
            int ci = l / CHUNK ;
            if (chunks[ci].valid == 0)
               chunks[ci].update(ci) ;
            for (int i=0; i<64; i++)
               cnts[i] += chunks[ci].cnts[i ^ v] ;
            v ^= chunks[ci].deltamask ;
            l += CHUNK ;
         }
         for (; l < r; l++) {
            v ^= 1<<(s[l]-'a') ;
            cnts[v]++ ;
         }
         ll rv = 0 ;
         for (int i=0; i<64; i++)
            rv += cnts[i] * (cnts[i]-1) ;
         cout << (rv>>1) << endl ;
      } else {
         cin >> i >> let ;
         s[i-1] = let ;
         chunks[(i-1)/CHUNK].valid = 0 ;
      }
   }
}
