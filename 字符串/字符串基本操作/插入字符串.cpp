#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string str = "Hello World";
  int position = 5;  // ������5��λ�ò��루��'H-e-l-l-o'֮��
  char ch = ',';     // Ҫ������ַ�

  // ʹ��insert�������뵥���ַ�
  str.insert(position, 1, ch);

  cout << "�������ַ���: " << str << endl;
  // ���: Hello, World

  return 0;
}
