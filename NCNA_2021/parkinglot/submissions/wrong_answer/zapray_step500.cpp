#include <iostream>
#include <cmath>

using namespace std;
#define EPS 1E-6

char g[51][51];
double d[51][51][51][51];
double ans[51][51];

double visible(int i, int j, int p, int q) {
    // assert i<p, j<q
    double x = i, y = j;
    
    int steps = 500;
    double incy = double(q-j)/(steps);
    double incx =  double(p-i)/(steps);
    
    while (steps--) {
        if (g[int(x)][int(y)] == '#') {
           return false;
        }
        x += incx;
        y += incy;
    }
    return true;
}

double getDist(int i, int j, int p, int q) {
    if (visible(i, j, p, q)) {
        //printf("visible: %d, %d, %d, %d\n", i,j, p,q);
        return sqrt((p-i)*(p-i) + (q-j)*(q-j));
    } else return -1;
}


int main ()
{
    int r, c, p, q;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> g[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            for (int p = i+1; p <= r; p++)
                for (int q = j+1; q <= c; q++)
                    d[i][j][p][q] = getDist(i,j,p,q);
    
    ans[0][0] = 0;
    for (int i = 1; i <= r; i++) ans[i][0] = i;
    for (int j = 1; j <= c; j++) ans[0][j] = j;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            ans[i][j] = min(ans[i-1][j], ans[i][j-1]) + 1;
            for (int p = 0; p < i; p++)
                for (int q = 0; q < j; q++)
                    if (d[p][q][i][j] != -1) {
                        ans[i][j] = min(ans[i][j], ans[p][q] + d[p][q][i][j]);
                    }
        }

    printf("%.9lf\n", ans[r][c]);
    return 0;
}

