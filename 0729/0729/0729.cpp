// 0729.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
int dist[2200][2200];
int cnt[3];

bool same(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (dist[r][c] != dist[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int r, int c, int n) {
	if (same(r, c, n)) {
		cnt[dist[r][c] + 1] += 1;
		return;
	}
	int m = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(r + i * m, c + j * m, m);
		}
	}
}


int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	solve(0,0,n);

	cout << cnt[0] << "\n";
	cout << cnt[1] << "\n";
	cout << cnt[2] << "\n";

    return 0;
}

