#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int card[500000];
int num[500000];
bool check; 
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}

	sort(card,card+n);

	

	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n;
		check = false;
		while (left <= right) {
			int mid = (left+right) / 2;
			if (num[i] == card[mid]) {
				cout << "1" << " ";
				check = true;
				break;
			}
			else if (card[mid] > num[i]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (!check)	cout << "0" << " ";
	}
	cout << "\n";

    return 0;
}