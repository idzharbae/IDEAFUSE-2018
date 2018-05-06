#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	long long int n,s;
	cin>>n>>s;

	if(abs(s)>n){
		cout<<"NO"<<"\n";
	}
	else if(s<0){
		if(n%2==0 && (s+2)%2==0){
			cout<<"YES"<<"\n";
		}
		else if(n%2==1 && (s+2)%2==-1){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
	else{
		if(n%2==0 && s%2==0){
			cout<<"YES"<<"\n";
		}
		else if(n%2==1 && s%2==1){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}


	return 0;
}