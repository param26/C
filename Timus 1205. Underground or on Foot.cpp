#include<bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
typedef long long ll;
typedef pair<int,int> pie;
typedef long double ld;
const int nax = 250;
const int inf = 1e9+5;
vector<pair<int, long double>> vertices[nax];
bool visited[nax];
vector<long double> d(nax, inf);
map<pair<ld,ld>, int> coord;
vector<int> parent(nax);
vector<int> tcomp;
ld di(ld x1, ld y1, ld x2, ld y2, ld speed) {
	ld ret = 0.0;
	ld db = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	ret = db/speed;
	return ret;
}
ld di(pair<ld,ld> &a, pair<ld,ld> &b, ld sp) {
	ld x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second;
	return di(x1,y1,x2,y2, sp);
}
void dfs(int u) {
	if(visited[u]) return ;
	visited[u] = 1;
	for(auto it:vertices[u]) {
		if(!visited[it.first]) {
			dfs(it.first);
		}
	}
}
void cdfs(int u) {
	if(visited[u]) return ;
	visited[u] = 1;
	for(auto it:vertices[u]) {
		if(!visited[it.first]) {
			cdfs(it.first);
		}
	}
	tcomp.push_back(u);
}
void dij(int u) {
	d[u] = 0;
	//visited[u] = 1;
	set<pair<long double, int>> q;
	q.insert({0.0,u});
	while(!q.empty()) {
		int x = q.begin()->second;
		q.erase(q.begin());
		for(auto it:vertices[x]) {
			int v = it.first;
			ld w = it.second;
			if(d[x] + w < d[v]) {
				parent[v] = x;
				q.erase({d[v],v});
				d[v] = d[x] + w;
				q.insert({d[v],v});
			}
		}
	}
}
int main() {
	ld foot, under;
	cin >> foot >> under;
	int n;
	cin >> n;
	vector<pair<ld, ld>> stations(n+1);
	for(int i=1;i<=n;i++) {
		long double x, y;
		cin >> x >> y;
		stations[i] = make_pair(x,y);
		coord[{x,y}] = i;
	}
	int u, v;
	cin >> u >> v;
	while(u != 0) {
		//cin >> v;
		vertices[u].push_back(make_pair(v,di(stations[u], stations[v], under)));
		vertices[v].push_back(make_pair(u,di(stations[u], stations[v], under)));
		cin >> u >> v;
	}
	vector<vector<int>> comp;
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			tcomp.clear();
			cdfs(i);
			comp.push_back(tcomp);
		}	
	}
	
	debug()<<imie(comp);
	int m = comp.size();
	if(m > 1) {
		for(int i=0;i<m;i++) {
			for(int j=i+1;j<m;j++) {
				for(int k=0;k<(int)comp[i].size(); k++) {
					for(int l=0;l<(int)comp[j].size(); l++) {
						int x = comp[i][k], y = comp[j][l];
						ld distt = di(stations[x], stations[y], foot);
						vertices[x].push_back(make_pair(y, distt));
						vertices[y].push_back(make_pair(x, distt));
					}
				}
			}
		}
	}
	pair<ld, ld> from, to;
	cin >> from.first >> from.second;
	cin >> to.first >> to.second;
	bool f1 = 0, f2 = 0;
	if(coord[from] == 0) {
		coord[from] = n+1;
		f1 = 1;
	}
	if(coord[to] == 0) {
		coord[to] = n+2;
		f2 = 1;
	}
	int fromm, too;
	fromm = coord[from], too = coord[to];
	vertices[fromm].push_back(make_pair(too, di(from, to, foot)));
	vertices[too].push_back(make_pair(fromm, di(from, to, foot)));
	for(int i=1;i<=n;i++) {
		vertices[fromm].push_back({i, di(from, stations[i], foot)});
		vertices[i].push_back({fromm, di(from, stations[i], foot)});
		vertices[i].push_back({too, di(stations[i], to, foot)});
		vertices[too].push_back({i, di(stations[i], to, foot)});
	}
	dij(fromm);
	ld ans = d[too];
	//queue<int> q;
	//q.push(fromm);
	//memset(visited, 0 , nax);
	//visited[fromm] = 1;
	//parent[fromm] =-1;
	//while(!q.empty()) {
		//int x = q.front();
		//q.pop();
		//for(auto it:vertices[x]) {
			//if(!visited[it.first]) {
				//q.push(it.first);
				//parent[it.first] = x;
				//visited[it.first] = 1;
			//}
		//}
	//}
	parent[fromm] = -1;
	int vv = too;
	vector<int> aa;
	while(vv!= -1) {
		aa.push_back(vv);
		vv = parent[vv];
	}
	//debug()<<imie(aa);
	cout<< setprecision(15) << fixed << ans <<endl;
	reverse(aa.begin(), aa.end());
	debug()<<imie(aa) imie(fromm) imie(too);
	if(fromm == too) {
		cout<<0;
		return 0;
	}
	vector<int> out;
	for(auto it:aa) {
		if(it == too && f2 == 0) out.push_back(it);
		else if(it == fromm && f1 == 0) out.push_back(it);
		else if(it!=fromm && it!=too) out.push_back(it);
	}
	cout<<(int)out.size()<<" ";
	for(auto it:out) {
		cout<<it<<" ";
	}
}
