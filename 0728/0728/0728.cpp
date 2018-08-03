
#include "stdafx.h"
#include <iostream>
using namespace std;


int go(int sum, int goal) {
	if (sum == goal) return 1;
	if (sum > goal) return 0;
	int now = 0;

	now += go(sum + 1, goal);
	now += go(sum + 2, goal);
	now += go(sum + 3, goal);

	return now;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << go(0, n) << "\n";
	}
    return 0;
}

