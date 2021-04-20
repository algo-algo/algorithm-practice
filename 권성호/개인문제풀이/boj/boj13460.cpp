//구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.
//보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다.
//가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다.
//빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈,각각 하나씩
//게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다
//이때, 파란 구슬이 구멍에 들어가면 안 된다.

//왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능
//빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다.빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다.
//빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다.또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다.

//=> 보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성

#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

int				dx[] = { -1,0,1,0 };
int				dy[] = { 0,1,0,-1 };
int				N, M; //(3 ≤ N, M ≤ 10) => brute force size!
char			board[10][10];
int				ans = numeric_limits<int>::max();

void DFS(int depth, const pair<int, int> redPose, const pair<int, int> bluePose)
{
	if (depth > 10)
		return; //10번 이상으로 연산을 하지는 않는다

	//상,하,좌,우 이동
	for (int i = 0; i < 4; i++)
	{		
		pair<int, int> nextRedPose = redPose;
		pair<int, int> nextBluePose = bluePose;

		/*------------------------------------------------------------*/
		bool blueFlag = false, redFlag = false;
		//=> 파란구슬 먼저 이동
		while (true)
		{
			//nextBluePose.second--;
			nextBluePose.first += dx[i];
			nextBluePose.second += dy[i];
			if (board[nextBluePose.first][nextBluePose.second] == 'O')
			{
				blueFlag = true;
				break;
			}
			if (board[nextBluePose.first][nextBluePose.second] == '#')
			{
				nextBluePose.first -= dx[i];
				nextBluePose.second -= dy[i];
				break;
			}
		}
		//빨간구슬 이동
		while (true)
		{
			//nextRedPose.second--;
			nextRedPose.first += dx[i];
			nextRedPose.second += dy[i];
			if (board[nextRedPose.first][nextRedPose.second] == 'O')
			{
				redFlag = true;
				break;
			}
			if (board[nextRedPose.first][nextRedPose.second] == '#')
			{
				/*nextRedPose.second++;*/
				nextRedPose.first -= dx[i];
				nextRedPose.second -= dy[i];
				break;
			}
		}

		if (blueFlag)
			continue;
		else
		{
			if (redFlag)
			{
				ans = ans < depth ? ans : depth;
				continue;
			}
		}

		//다음 위치 조정
		if (nextRedPose == nextBluePose)
		{
			if (i == 0)
			{	//상
				if (redPose.first < bluePose.first) //빨강이 위에 있었다면
					nextBluePose.first++;
				else
					nextRedPose.first++;
			}
			else if (i == 1)
			{	//오른쪽
				if (redPose.second < bluePose.second)
					nextRedPose.second--;
				else
					nextBluePose.second--;
			}
			else if (i == 2)
			{	//아래쪽
				if (redPose.first < bluePose.first) //빨강이 위에 있었다면
					nextRedPose.first--;
				else
					nextBluePose.first--;
			}
			else
			{
				if (redPose.second < bluePose.second)
					nextBluePose.second++;
				else
					nextRedPose.second++;
			}
		}
		DFS(depth + 1, nextRedPose, nextBluePose);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	pair<int, int> redPose, bluePose;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'B')
				bluePose = { i,j };
			if (board[i][j] == 'R')
				redPose = { i,j };
		}
	}
	/*input*/
	board[redPose.first][redPose.second] = '.';
	board[bluePose.first][bluePose.second] = '.';
	DFS(1, redPose, bluePose);

	/*output*/
	if (ans == numeric_limits<int>::max())
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}

