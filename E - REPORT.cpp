#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 

int arr[100000]={0};
void bfs(vi adj[], int x, int y){
	int visited[100000] = {0};
	//cout<<"entering bfs\n";
	queue<int> q;
	q.push(x);
	map<int,int> my;
	my[x] = 0;
	visited[x] = 1;
	while(!q.empty()){
		//cout<<"queueing\n";
		int s = q.front();
		q.pop();
		if(my[s] == y){  arr[s]++;}
		if(my[s] > y) break;
		for(int i = 0; i < adj[s].size(); i++){
			if(!visited[adj[s][i]]){
				q.push(adj[s][i]);
				my[adj[s][i]] = my[s]+1;
				visited[adj[s][i]] = 1;
			}
		}
	}
	my.clear();
	//cout<<"finished\n";
}

int N,M;
int main(){
	cin>>N>>M;
	vi adj[N];
	for(int i = 0; i < N-1; i++){
		int x,y;
		cin>>x>>y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0; i <M; i++){
		int x,y;
		cin>>x>>y;
		x--;
		//cout<<"calling bfs\n";
		bfs(adj,x,y);
	}
	sort(arr, arr+N, greater<int>());
	cout<<arr[0]<<endl;
	return 0;
}

