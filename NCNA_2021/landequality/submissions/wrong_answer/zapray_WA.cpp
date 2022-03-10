#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int r, c, v;
    cin >> r >> c;
    int zeros = 0;
    int ones =0 ;
    int twos = 0;
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> v;
            zeros += (v == 0);
            ones += (v == 1);
            twos += (v == 2);
        }
        
    long long ans;
    if (zeros >= 2) {
        ans = 0;
    }else if (zeros == 1) {
        if (ones) ans = 1;
        else ans = 2;
    }else {
        if (twos % 2) {
            ans = 1ll << (twos/2);
        }else ans = 0;
    }
    cout << ans << endl;
    return 0;
}

