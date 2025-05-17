#include<bits/stdc++.h>
using namespace std;
int n, m;

// 检查坐标是否在有效范围内
bool check(int a, int b) {
    if(a < 0 || a >= n || b < 0 || b >= m) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    int dp[105][105];
    int op[105][105];
    // 初始化数组
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = 0;
			op[i][j]=0;  
        }
    }
    
    // 输入数据
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> dp[i][j];  
        }
    }
    
    // 将值为1的位置设为9
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] == 1) {  
                op[i][j] = 9;
            }
        }
    }
    
    // 计算每个0周围的非0数量
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] == 0) {  
                // 检查周围8个方向
                if(check(i-1, j-1)) {
                    if(dp[i-1][j-1] != 0) dp[i][j]++;  
                }
                if(check(i-1, j)) {
                    if(dp[i-1][j] != 0) dp[i][j]++;
                }
                if(check(i-1, j+1)) {
                    if(dp[i-1][j+1] != 0) dp[i][j]++;
                }
                if(check(i, j+1)) {
                    if(dp[i][j+1] != 0) dp[i][j]++;
                }
                if(check(i, j-1)) {
                    if(dp[i][j-1] != 0) dp[i][j]++;
                }
                if(check(i+1, j-1)) {
                    if(dp[i+1][j-1] != 0) dp[i][j]++;
                }
                if(check(i+1, j+1)) {
                    if(dp[i+1][j+1] != 0) dp[i][j]++;
                }
                if(check(i+1, j)) {
                    if(dp[i+1][j] != 0) dp[i][j]++;
                }
                op[i][j]=dp[i][j];
                dp[i][j]=0;
            }
        }
    }
    
    // 输出结果
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << op[i][j]<<" ";  
        }
        cout << endl;
    }    
    
    return 0;
}
