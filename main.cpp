#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int INF = 1000000000;
	int n;
	cin >> n;
	vector < vector < pair<int,int> > > g (n);
	for(int i = 0; i < n; i++)
    {
        int a, b;
        cin>>a>>b;
        g[i].push_back({a,b});
    }
    
	int s; // стартовая вершина
    cin>>s;
 
    // Реализация
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
    
    int t;
    cin>>t; // Восстановить путь до любой вершины t 
    vector<int> path;
    for (int v=t; v!=s; v=p[v])
        path.push_back (v);
    path.push_back (s);
    reverse (path.begin(), path.end());
    
}
    
