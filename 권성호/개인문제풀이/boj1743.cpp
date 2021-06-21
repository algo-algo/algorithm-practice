#include <iostream>
#include <utility>
#include <queue>

using namespace std;

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

int N, M, K;
bool board[101][101];
bool visited[101][101];

void InputAndInit() {
	cin >> N >> M >> K;
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		board[r][c] = true;
	}
}

int BFS(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;
	int cnt = 1;

	while (q.size() != 0) {
		auto current = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];

			if (board[nextX][nextY] == true && visited[nextX][nextY] == false) {
				q.push({ nextX,nextY });
				visited[nextX][nextY] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	InputAndInit();

	int ans = 1;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (board[r][c] == true && visited[r][c] == false) { // 아직 방문 안한 쓰레기가 있으면
				int tmp = BFS({ r,c });
				ans = ans > tmp ? ans : tmp;
			}
		}
	}
	cout << ans << "\n";
}
