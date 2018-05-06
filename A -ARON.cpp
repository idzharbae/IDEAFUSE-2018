#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 


int main(){
	int n; cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	sort(arr,arr+n);
	ll sum = 0;
	for(int i = 1; i < n; i++) sum+=arr[i];
	cout<<sum<<endl;

	return 0;
}

