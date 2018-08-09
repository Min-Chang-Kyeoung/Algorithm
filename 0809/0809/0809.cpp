// 0809.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n = 0;
	int arr[500000];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<int> s;
	stack<int> c;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int tmp = arr[i];
		int cnt = 1;
		while (!s.empty()) {
			if (s.top() <= arr[i]) {
				ans += (long long)c.top();
				if (s.top() == arr[i]) {
					cnt += c.top();
				}
			}
			else {
			 	break;
			}
			s.pop();
			c.pop();

			if (!s.empty()) {
				ans += 1LL;
			}
		}
		s.push(tmp);
		c.push(cnt);
	}
	cout << ans << "\n";
    return 0;
}

