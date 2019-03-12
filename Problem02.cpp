//红黑瓷砖，只能踩黑砖，总共最多可以走多少瓷砖
//'#'代表红砖，'.'代表黑砖，'@'代表人所处的开始地点，同样表示一块黑砖
#include<iostream>
using namespace std;
const int MAX = 101;

char map[MAX][MAX];
bool v[MAX][MAX]={false};
int d[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
int ans = 0;
int height;
int width;
int ny, nx;

void dfs(int i, int j) {
    if(map[i][j] == '#') {
        return;
    }
    if(!v[i][j]) {
        ans++;
        v[i][j] = true;
    }
    for(int k = 0; k < 4; k++) {
        ny = i+d[k][0];
        nx = j+d[k][1];
        if(!v[ny][nx] && ny>0 && ny<=height && nx>0 && nx<=width) {
            dfs(ny, nx);
        }
    }
}

int main() {
    int sx, sy;
    cin >> width >> height;
    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            cin >> map[i][j];
            if (map[i][j] == '@') {
                map[i][j] = '.';
                sx = j;
                sy = i;
            }
        }
    }
    dfs(sy, sx);
    cout << ans << endl;
    return 0;
}