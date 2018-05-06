#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 


int main(){
	int x = 0, y=0;
	string input;
	cin>>input;
	for(int i = 0; i < input.length(); i++){
		char c = input[i];
		if(c == 'N') y++;
		else if(c == 'S') y--;
		else if(c == 'E') x++;
		else if (c=='W') x--;
	}
	cout<<abs(x)+abs(y)<<endl;
	
	return 0;
}

