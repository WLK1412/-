#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string str;
  int pos;
  while(getline(cin,str)){
  	while((pos=str.find("you"))!=-1){
  		str.replace(pos,3,"we");
	  }
	cout<<str<<endl;
  }
  return 0;
}
