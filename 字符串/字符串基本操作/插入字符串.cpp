#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string str = "Hello World";
  int position = 5;  // 在索引5的位置插入（即'H-e-l-l-o'之后）
  char ch = ',';     // 要插入的字符

  // 使用insert方法插入单个字符
  str.insert(position, 1, ch);

  cout << "插入后的字符串: " << str << endl;
  // 输出: Hello, World

  return 0;
}
