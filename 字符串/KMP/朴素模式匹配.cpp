#include <bits/stdc++.h>
using namespace std;
int index(string s,string t){
	int i=0,j=0;
	while(i<s.size()&&j<t.size()){
		if(s[i]==t[j]){
			++i;++j;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j==t.size())
		return i-t.size()+1;
	else
		return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin>>s>>t;
	cout<<index(s,t);
	return 0;	
}
    

