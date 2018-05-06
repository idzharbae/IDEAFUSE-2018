#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 


int main(){
	
	vector<int> v;
	
	int x;
	while(cin>>x)
		v.push_back(x);
	v.push_back(-1);
	int curr = 0;
	vector<pair<int,int> > ans;
	for(int i = 0; i < v.size(); i++){
		if(v[i] == -1 ) break;
		curr++;
		if(v[i] != v[i+1] or curr == 255){
			ans.push_back({curr,v[i]});
			curr = 0;
		}
	}
	cout<<(ans.size())*2<<endl;
	for(int i = 0; i < ans.size(); i++){
		cout<<ans[i].first<<" "<<ans[i].second;
		if(i == ans.size() - 1) cout<<endl;
		else cout<<" ";
	}
	return 0;
}

