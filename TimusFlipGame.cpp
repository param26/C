#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pie;
vector<string> v(4);
int ok = 65535;
bool ig(int board) {
	return (board==0||board == ok);
}
void tb(int &board) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			board = (board << 1) + (v[i][j] == 'b'? 1 : 0);
		}
	}
}
vector<int> flip(16);
bool coord(int i, int j) {
	return (i>=0 && i<4 && j>=0 && j<4);
}
void init() {
	int i=0, j = 0;
	for(int ret = 0 ; ret<16;ret++) {
		//debug()<<imie(i) imie(j);
		vector<vector<int>> mp(4, vector<int> (4,0));
		mp[i][j] = 1;
		if(coord(i+1,j)) mp[i+1][j] = 1;
		if(coord(i-1,j)) mp[i-1][j] = 1;
		if(coord(i,j-1)) mp[i][j-1] = 1;
		if(coord(i,j+1)) mp[i][j+1] = 1;
		int make = 0;
		for(int x=0;x<4;x++) {
			for(int y=0;y<4;y++) {
					make = (make << 1) + (mp[x][y]==1?1:0);
			}
		}
		flip[ret] = make;
		if(j == 3) {
			i++;
			j=0;
		} else j++;
		
	}
	//cout<<"reached\n";
}
int main() {
	for(int i=0;i<4;i++) {
		cin >> v[i];
	}
	int board = 0;
	tb(board);
	if(ig(board)) {
		cout<<0;
		return 0;
	}
	//cout<<(ig(65535)?"good":"not good\n");
	ll base = 65535;
	init();
	int moves=  20;
	//cout<<bitset<16>(65535).to_string();
	for(int mask = 0; mask <= base ; ++mask) {
		int newboard = board;
		for(int i=0;i<16;i++) {
			if(1 & (mask >> i)) {
				newboard ^= flip[i];
			}
		}
		if(ig(newboard)) {
			int k = __builtin_popcount(mask);
			moves = min(moves, k);
		}
	}
	if(moves == 20) cout<<"Impossible\n";
	else cout<<moves;
}

