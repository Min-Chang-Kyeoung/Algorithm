#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[51][51];
bool check[15];
vector<pair<int, int>> house;
vector<pair<int, int>> chiken;
int ans = 987654321;
int n, m;

void dfs(int num, int cnt) {
	if (num > chiken.size()) return;

	if (cnt == m) {
		int cmp = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = 987654321;
			for (int j = 0; j < chiken.size(); j++) {
				if (check[j]) {
					int r1 = house[i].first;
					int c1 = house[i].second;
					int r2 = chiken[j].first;
					int c2 = chiken[j].second;

					int res = abs(r1 - r2) + abs(c1 - c2);
					dist = min(dist, res);
				}
			}
			cmp += dist;
		}
		ans = min(cmp, ans);
		return;
	}

	check[num] = true;
	dfs(num + 1, cnt + 1);
	check[num] = false;
	dfs(num + 1, cnt);
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (board[i][j] == 2)
				chiken.push_back(make_pair(i, j));
		}
	}

	dfs(0, 0);

	cout << ans << "\n";
	return 0;
}