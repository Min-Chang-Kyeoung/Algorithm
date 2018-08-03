#include <queue>
#include <iostream>
using namespace std;
int maze[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main()
{
	int n, m;
	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	q.push(make_pair(0, 0));
	maze[0][0] = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr >= 0 && nr < n&& nc >= 0 && nc < m) {
				q.push(make_pair(nr, nc));
				maze[nr][nc] = maze[r][c] + 1;
			}
		}

	}

	cout << maze[n - 1][m - 1] << "\n";

	return 0;
}

