#include <bits/stdc++.h>
using namespace std;
vector<int> getnext(string t) {
    int M = t.size();
    vector<int> lps(M);
    lps[0] = 0; // lps[0]始终为0
    int len = 0; // 已匹配的最长前缀后缀长度
    int i = 1;
    while (i < M) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1]; // 回溯到前一个最长前缀后缀
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
// KMP搜索函数 - 修正版本
int KMPSearch(string s, string t){
    int N = s.size();
    int M = t.size();
    if (M == 0) return 0; // 空模式串匹配成功
    vector<int> lps = getnext(t);
    int i = 0; // 文本串索引
    int j = 0; // 模式串索引
    while (i < N) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        if (j == M) {
            return i - j; // 匹配成功
        }
        else if (i < N && s[i] != t[j]) {
            if (j != 0) {
                j = lps[j - 1]; // 回溯到前一个最长前缀后缀
            }
            else {
                i++; // 模式串从头开始，文本串后移
            }
        }
    }
    return -1; // 匹配失败
}
int main() {
    string s,t;
    cin>>s>>t;
    int pos = KMPSearch(s,t);
    if (pos != -1) {
        cout<<"模式串在文本串中的起始位置是: "<<pos+1<<endl;
    }
    else{
        cout<<"未找到匹配的模式串"<<endl;
    }
    return 0;
}
