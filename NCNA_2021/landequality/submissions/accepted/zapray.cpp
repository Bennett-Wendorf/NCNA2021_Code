#include <iostream>
#include <cmath>

using namespace std;

int g[65];
int main ()
{
    int r, c, v;
    long long ans;
    cin >> r >> c;
    if (r == 1 || c == 1) {
        ans = 1ll << 32;
        for (int i = 0; i < r*c; i++) cin >> g[i];
        for (int x = 0; x < r*c-1; x++) {
            long long left = 1ll;
            long long right = 1ll;
            for (int i = 0; i <= x; i++) left *= g[i];
            for (int i = x+1; i < r*c; i++) right *= g[i];
            ans = min(ans, abs(left - right));
        }
    } else {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for (int i = 0; i < r*c; i++) {
            cin >> v;
            zeros += (v == 0);
            ones += (v == 1);
            twos += (v == 2);
        }
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
    }

    cout << ans << endl;
    return 0;
}

