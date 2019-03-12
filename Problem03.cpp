/*
洛谷1605
题目描述：
给定一个N*M方格的迷宫，迷宫里有T处障碍，障碍处不可通过。给定起点坐标和
终点坐标，问: 每个方格最多经过1次，有多少种从起点坐标到终点坐标的方案。在迷宫
中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍。

输入格式：
第一行N、M和T，N为行，M为列，T为障碍总数。第二行起点坐标SX,SY，终点
坐标FX,FY。接下来T行，每行为障碍点的坐标。
*/
#include<iostream>
using namespace std;
const int MAX = 101;

char map[MAX][MAX];
bool v[MAX][MAX]={false};
int d[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
int N, M, T;
int sx, sy, fx, fy, tx, ty, nx, ny;
int ans = 0;
void dfs(int i, int j) {
    if(map[i][j] == 2) {
        return;
    }
    if(map[i][j] == 1) {
        ans++;
        return;
    }
    v[i][j] = true;
    for(int k = 0; k < 4; k++) {
        nx = d[k][0] + j;
        ny = d[k][1] + i;
        if(!v[ny][nx] && nx >0 && nx <= M && ny > 0 && ny <= N) {
            dfs(ny, nx);
        }
    }
    v[i][j] = false;
}

int main() {
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            map[i][j] = 0;
            v[i][j] = false;
        }
    }
    cin >>  sx >> sy >> fx >> fy;
    map[fy][fx] = 1;
    for(int i = 0; i < T; i++) {
        cin >> tx >> ty;
        map[ty][tx] = 2;
    }
    dfs(sy,sx);
    cout << ans << endl;
    return 0;
}