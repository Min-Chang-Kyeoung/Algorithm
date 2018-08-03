#include "stdafx.h"
#include <iostream>
using namespace std;

bool dp[2001][2001];
int arr[2001];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		dp[i][i] = true;
	}

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = true;
	}

	for (int k = 3; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
			}
		}
	}
	
	int m;
	cin >>m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s-1][e-1] << "\n";
	}

    return 0;
}

