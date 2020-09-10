#include <bits/stdc++.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define ll long long int
#define li long int
#define fi first
#define se second
#define ffl fflush(stdout);
#define all(x) (x).begin,(x).end()
#define whT int t; cin>>t; while(t--)
typedef pair<ll,ll> pi;
void dsp(priority_queue<pi,vector<pi>,greater<pi>> pq) {
	while(!pq.empty()) {
		pi top = pq.top();
		cout<<top.se<<" "<<top.fi<<"\n";
		pq.pop();
	}
	cout<<"\n";
}
int main() 
{
	// #ifndef ONLINE_JUDGE
	// freopen("G:/coding/CPP/input.txt", "r", stdin);
	// freopen("G:/coding/CPP/output.txt", "w", stdout);
	// #else
	// ios_base::sync_with_stdio(false); cin.tie(NULL);
	// #endif
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	pi top;
	ll n,m;
	cin>>n>>m;
	li ti[m];
	ll jobs[n] = {0};
	for(int i=0;i<m;i++) {
		cin>>ti[i];
	}
	ll job = 0,thread,work;
	for(int i=0;i<n;i++) {
		pq.push(make_pair(0,i));
		jobs[i] = ti[i];
		job++;
	}
	while(job!=m) {
		top = pq.top();
		cout<<top.se<<" "<<top.fi<<"\n";
		thread = top.se;
		work = top.fi;
		// cout<<"work "<<thread<<" "<<work<<endl;
		pq.pop();
		pq.push(make_pair((jobs[thread]+work),thread));
		jobs[thread] = ti[job];
		job++;
	}
	dsp(pq);	
}
