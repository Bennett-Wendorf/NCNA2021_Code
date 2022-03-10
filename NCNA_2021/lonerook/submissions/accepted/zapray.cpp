#include <bits/stdc++.h>
#define SZ 751

using namespace std;

char g[SZ][SZ];
int knight_dir[8][2] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1},{-2, 1}, {2, -1}, {2, 1}};
int rook_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int attacked[SZ][SZ];
bool visited[SZ][SZ];

bool valid(int x, int y, int r, int c) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int main ()
{
    int r, c;
    cin >> r >> c;
    queue<pair<int,int>> q;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> g[i][j];
            attacked[i][j] = 0;
            visited[i][j] = 0;
        }
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 'R') {
                q.emplace(i,j);
                visited[i][j] = 1;
            }
        }
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 'K') {
                for (int d = 0; d<8; d++) {
                    int x = i + knight_dir[d][0];
                    int y = j + knight_dir[d][1];
                    if (valid(x, y, r, c)) {
                        attacked[x][y] += 1;
                    }
                }
            }
        }
        
    while (!q.empty()) {
        auto xy = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = xy.first, ny = xy.second;
            if (g[nx][ny]=='T') {
                puts("yes");
                return 0;
            }
            nx += rook_dir[d][0];
            ny += rook_dir[d][1];
            while (valid(nx, ny, r, c)) {
                if (g[nx][ny]=='K') {
                    if (!attacked[nx][ny]) {
                        g[nx][ny] = '.';
                        for (int d = 0; d<8; d++) {
                            int x = nx + knight_dir[d][0];
                            int y = ny + knight_dir[d][1];
                            if (valid(x, y, r, c)) {
                                attacked[x][y] -= 1;
                                if (attacked[x][y] == 0 && visited[x][y]) q.emplace(x,y);
                            }
                        }
                    } else break;
                }
                if (g[nx][ny]!='K' && !attacked[nx][ny] && !visited[nx][ny]) q.emplace(nx,ny);
                visited[nx][ny] = 1;
                nx += rook_dir[d][0];
                ny += rook_dir[d][1];
            }
        }
    }

    puts("no");
    return 0;
}
