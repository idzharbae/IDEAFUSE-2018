#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 


int N,M,C;
int arr[200000] = {0};
int candy[200000] = {0};
int dijkstra(int n,int source, vector<pair<int, int> > G[], int dest) {
    int INF = (int)1e9;
    vector<int> D(n, INF);
    D[source] = 0;
    set<pair<int, int> > Q;
    Q.insert({0,source});
    
    candy[source] = 0;
    while(!Q.empty())   {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
        
        for(auto next: G[u])    {
            int v = next.first, weight = next.second;
            
            if(v == dest and candy[u] >= C and D[u] + weight < D[v]){
				if(Q.find( {D[v],v})!=Q.end())
                    Q.erase(Q.find( {D[v], v} ));
                   
				D[v] = D[u] + weight;
                Q.insert( {D[v], v} );
              // cout<<D[v]<<endl<<endl;
			}
			
            if(v != dest and D[u] + weight < D[v] ) {
                if(Q.find( {D[v],v})!=Q.end())
                    Q.erase(Q.find( {D[v], v} ));
                   
				D[v] = D[u] + weight;
                Q.insert( {D[v], v} );
                candy[v] = candy[u] + arr[v];
              // cout<<v<<" "<<candy[v]<<" Candy now\n";
            }
        }
    }
   // cout<<"FINISH\n";
    return D[dest];
}

int main(){
	cin>>N>>M>>C;
	M = M+2;
	vector<pair<int, int> > adj[N*M];
	
	for(int i = 0; i < N; i++){
	if(i < N-1){	
		adj[(i+2)*M-1].push_back({(i+1)*M-1, 1});
		
		for(int j = 0; j < M; j++)
			adj[(i+1)*M+j].push_back({i*M, 1+j});
		

		}
		for(int j = 0; j < M-1; j++){
			adj[i*M+j].push_back({i*M+j+1,1});
			adj[i*M+j+1].push_back({i*M+j,1});
		}
	}
	
	
	for(int i = 0; i < N; i++){
		string input; cin>>input;
		for(int j = 0; j < M; j++){
			if(j == 0 or j == M-1) continue;
			arr[i*M+j] = (int)(input[j] - '0');			
		}
		
	}
	
	cout<<min(dijkstra(N*M,(N-1)*M,adj,0),dijkstra(N*M,(N-1)*M,adj,M-1)) <<endl;
	return 0;
}

