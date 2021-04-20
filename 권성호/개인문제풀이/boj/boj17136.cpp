////1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.
//
////각 색종이는 5개
////1이 적힌 모든 칸에 색종이 있어야하고 0인 칸에는 없어야 한다
//
////inputBoard에 크기가 큰 색종이 부터 먼저 놓는 방식!
//
//#include <iostream>
//
//using namespace std;
//
//int				board[10][10];
////bool			visited[10][10];	//default false
//int				ans = 0;
//
//bool AllDrawn()
//{//board가 다 색종이로 칠해졌다면 true
//	int i, j;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (board[i][j] == 1)
//				return false;
//		}
//	}
//	return true;
//}
//
//bool checkBoard(int r, int c, int confettiSize)
//{//r,c위치에서 confettiSize색종이를 board에 올릴 수 있으면 true
//	int i, j;
//	for (i = r; i < r + confettiSize; i++)
//	{
//		for (j = c; j < c + confettiSize; j++)
//		{
//			if (board[i][j] != 1)
//				return false;
//		}
//	}
//	return true;
//}
//
//void Draw(int r, int c, int confettiSize)
//{//r,c위치에서 confettiSize색종이를 board에 그리기
//	int i, j;
//	for (i = r; i < r + confettiSize; i++)
//	{
//		for (j = c; j < c + confettiSize; j++)
//		{
//			board[i][j] = -1;
//		}
//	}
//}
//
//void PaintBoard(int confettiSize)
//{//confettiSize의 색종이를 5개 까지 board에 그리기
//	int i, j;
//	int count = 5;									//각 색종이는 최대 5개까지 사용가능
//	for (i = 0; i <= 10 - confettiSize; i++)
//	{
//		for (j = 0; j <= 10 - confettiSize; j++)
//		{
//			if (board[i][j] == 1)
//			{
//				if (checkBoard(i, j, confettiSize))
//				{
//					Draw(i, j, confettiSize);
//					count--; ans++;
//					if (count == 0) return;			//각 색종이는 최대 5개까지 사용가능
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	int i, j, k;
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//			cin >> board[i][j];
//	}
//	/*
//	input
//	*/
//	for (i = 5; i >= 1; i--)
//	{
//		PaintBoard(i);
//	}
//
//	if (AllDrawn())
//		cout << ans << endl;
//	else
//		cout << -1 << endl;
//	
//}

//삼성 A형 기출은 무조건 부르트 포스

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10;
const int INF = 987654321;

int arr[MAX][MAX];
int cnt, result;
int paper[6] = { 0, 5, 5, 5, 5, 5 };

void func(int y, int x)
{
	// 해당 줄은 다 확인했으므로 다음 줄 확인
	if (x == MAX)
	{
		func(y + 1, 0);
		return;
	}

	// 마지막 줄까지 다 확인했으므로 현재 색종이 개수 확인
	if (y == MAX)
	{
		result = min(result, cnt);
		return;
	}

	// 덮을 필요 없으므로 다음 칸 확인
	if (arr[y][x] == 0)
	{
		func(y, x + 1);
		return;
	}

	// 모든 경우의 수 다 확인
	for (int len = 5; len >= 1; len--)
	{
		// 현재 len 크기 색종이가 없거나 덮었을 때 범위를 벗어날 경우
		if (paper[len] == 0 || y + len > MAX || x + len > MAX)
		{
			continue;
		}

		bool flag = true;
		// len 길이만한 정사각형이 존재하는지 확인
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				if (arr[y + j][x + k] == 0)
				{
					flag = false;
					break;
				}
			}

			if (flag == false)
			{
				break;
			}
		}

		// 존재하지 않으면 확인할 필요 없음
		if (flag == false)
		{
			continue;
		}

		// 덮었다고 치고
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				arr[y + j][x + k] = 0;
			}
		}

		paper[len]--;
		cnt++;

		// 다음 칸 확인
		func(y, x + len);

		// 덮었던 색종이를 치운다
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				arr[y + j][x + k] = 1;
			}
		}

		paper[len]++;
		cnt--;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cin >> arr[i][j];
		}
	}

	result = INF;
	func(0, 0);
	if (result == INF)
		cout << -1 << "\n";
	else
		cout << result << "\n";

	return 0;
}