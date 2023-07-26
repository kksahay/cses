#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N];
void bfs(int s, int n) {
	vector<bool> visited(n + 1, 0);
	vector<int> dist(n + 1);
	vector<int> par(n + 1, -1);
	par[s] = 0;
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(int u: adj[curr]) {
			if(visited[u])
				continue;
			visited[u] = true;
			dist[u] = dist[curr] + 1;
			par[u] = curr;
			q.push(u);
		}
	}
	if(par[n] == -1) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	cout << dist[n] + 1 << '\n';
	vector<int> path;
	while(n != 0) {
		path.push_back(n);
		n = par[n]; 
	}
	reverse(path.begin(), path.end());
	for(int x: path) {
		cout << x << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	//while(m--) {
		//int x, y;
		//cin >> x >> y;
		//adj[x].push_back(y);
		//adj[y].push_back(x);
	//}
	//bfs(1, n);
	int base = log2(m);
	cout << base;
	return 0;
}
