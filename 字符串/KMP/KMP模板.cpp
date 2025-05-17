#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 100010;
char s[N], p[M];
int nex[M];
int main() {
    cin>>s+1>>p+1;
    int n = strlen(s + 1), m = strlen(p + 1);
    // ��ʼ��next�����ǰ����ֵ
    nex[0] = nex[1] = 0;
    // ����next����
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] != p[j + 1]) j = nex[j];
        if (p[i] == p[j + 1]) j++;
        nex[i] = j;
    }
    // KMPƥ�����
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = nex[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
            // ƥ��ɹ������ģʽ�����ı����е���ʼλ�ã������±��1��ʼ��
            printf("%d ", i - m + 1);
            // ����ѡ�����Ѱ����һ��ƥ�䣬���ｫj���ݵ�����λ��
            j = nex[j]; 
        }
    }
    return 0;
}
