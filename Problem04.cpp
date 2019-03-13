//N_Queens
//DFS全排列加检查对角线
//check(int p[], int N)函数检查对角线丑陋，待修改
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 101;
int p[MAX];
int ans = 0;

bool check(int p[], int n) {
    for(int i = 1; i <= n; i++) {
        int x = i, y = p[i];
        int count = -1;
        while(x>0&&x<=n&&y>0&&y<=n) {
            if(p[x] == y) {
                count++;
            }
            if(count) {
                return false;
            }
            x--;
            y++;
        }
        x = i, y = p[i];
        count = -1;
        while(x>0&&x<=n&&y>0&&y<=n) {
            if(p[x] == y) {
                count++;
            }
            if(count) {
                return false;
            }
            x--;
            y--;
        }
        x = i, y = p[i];
        count = -1;
        while(x>0&&x<=n&&y>0&&y<=n) {
            if(p[x] == y) {
                count++;
            }
            if(count) {
                return false;
            }
            x++;
            y++;
        }
        x = i, y = p[i];
        count = -1;
        while(x>0&&x<=n&&y>0&&y<=n) {
            if(p[x] == y) {
                count++;
            }
            if(count) {
                return false;
            }
            x++;
            y--;
        }
    }
    return true;
}

void Queen(int a[], int s , int e) {
    for(int i = s; i <= e; i++) {
        swap(a[s], a[i]);
        Queen(a, s+1,e);
        swap(a[s], a[i]);
    }
    if(s == e) {
        if(check(a, e)) {
            ans ++;
        }
    }
    return;
}

int main() {
    int N = 8;
    for(int i = 1; i <= N; i++) {
        p[i] = i;
    }
    Queen(p, 1, N);
    cout << ans << endl;
    return 0;
}