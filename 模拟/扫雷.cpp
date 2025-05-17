#include<bits/stdc++.h>
using namespace std;
int n, m;

// ��������Ƿ�����Ч��Χ��
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
    // ��ʼ������
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = 0;
			op[i][j]=0;  
        }
    }
    
    // ��������
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> dp[i][j];  
        }
    }
    
    // ��ֵΪ1��λ����Ϊ9
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] == 1) {  
                op[i][j] = 9;
            }
        }
    }
    
    // ����ÿ��0��Χ�ķ�0����
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] == 0) {  
                // �����Χ8������
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
    
    // ������
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << op[i][j]<<" ";  
        }
        cout << endl;
    }    
    
    return 0;
}
