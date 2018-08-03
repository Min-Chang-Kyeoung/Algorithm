// 0725.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
const int MAX = 100010;
using namespace std;

bool check[MAX];
int dist[MAX];

int main()
{
	int n, k;
	cin >> n >> k;

	queue <int> q;
	q.push(n);
	check[n] = true;


	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now-1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}

		if (now * 2 < MAX) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}

		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
	}

	cout << dist[k] << "\n";

    return 0;
}