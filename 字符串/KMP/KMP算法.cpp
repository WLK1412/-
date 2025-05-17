#include <bits/stdc++.h>
using namespace std;
vector<int> getnext(string t) {
    int M = t.size();
    vector<int> lps(M);
    lps[0] = 0; // lps[0]ʼ��Ϊ0
    int len = 0; // ��ƥ����ǰ׺��׺����
    int i = 1;
    while (i < M) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1]; // ���ݵ�ǰһ���ǰ׺��׺
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
// KMP�������� - �����汾
int KMPSearch(string s, string t){
    int N = s.size();
    int M = t.size();
    if (M == 0) return 0; // ��ģʽ��ƥ��ɹ�
    vector<int> lps = getnext(t);
    int i = 0; // �ı�������
    int j = 0; // ģʽ������
    while (i < N) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        if (j == M) {
            return i - j; // ƥ��ɹ�
        }
        else if (i < N && s[i] != t[j]) {
            if (j != 0) {
                j = lps[j - 1]; // ���ݵ�ǰһ���ǰ׺��׺
            }
            else {
                i++; // ģʽ����ͷ��ʼ���ı�������
            }
        }
    }
    return -1; // ƥ��ʧ��
}
int main() {
    string s,t;
    cin>>s>>t;
    int pos = KMPSearch(s,t);
    if (pos != -1) {
        cout<<"ģʽ�����ı����е���ʼλ����: "<<pos+1<<endl;
    }
    else{
        cout<<"δ�ҵ�ƥ���ģʽ��"<<endl;
    }
    return 0;
}
