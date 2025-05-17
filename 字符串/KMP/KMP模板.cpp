#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 100010;
char s[N], p[M];
int nex[M];
int main() {
    cin>>s+1>>p+1;
    int n = strlen(s + 1), m = strlen(p + 1);
    // 初始化next数组的前两个值
    nex[0] = nex[1] = 0;
    // 计算next数组
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] != p[j + 1]) j = nex[j];
        if (p[i] == p[j + 1]) j++;
        nex[i] = j;
    }
    // KMP匹配过程
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = nex[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
            // 匹配成功，输出模式串在文本串中的起始位置（这里下标从1开始）
            printf("%d ", i - m + 1);
            // 可以选择继续寻找下一个匹配，这里将j回溯到合适位置
            j = nex[j]; 
        }
    }
    return 0;
}
