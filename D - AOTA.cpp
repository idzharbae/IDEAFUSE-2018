#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 

struct Comp {
  bool operator()(const std::pair<int, string> &a, const std::pair<int, string> &b) {
    if (a.first != b.first) {
      return a.first > b.first;
    }
    return a.second < b.second;
  }

};

int n = 8;
map<string,int> arr;
int main(){
	string input;
	for(int i = 0; i < n; i++){
		cin>>input;
		arr[input] = 0;
	}
	for(int i = 0; i < 28; i++){
		char buff;
		string x,y;
		int a,b;
		cin>>x>>a>>buff>>b>>y;
		if(a>b) arr[x]++;
		if(a<b) arr[y]++;
	}
	vector<pair<int,string> > v;
	map<string,int >::iterator it;
	for(it = arr.begin(); it != arr.end(); ++it){
		v.push_back({it->second, it->first});
	}
	Comp comp_functor;
	sort(v.begin(), v.end(),  comp_functor);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i].second<<" "<<v[i].first<<endl;
	}
	return 0;
}

