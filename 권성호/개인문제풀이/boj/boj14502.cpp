#include <iostream>

using namespace std;

int		board[8][8];		//default 0
bool	isSpread[8][8];		//default false
int		N, M;				// 세로,가로 <=8
int		maxSaftyZone = 0;

void CopyBoard(int src[8][8], int dest[8][8])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			dest[i][j] = src[i][j];
	}
}

void InitIsSpread()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			isSpread[i][j] = false;
	}
}

bool IsInBoard(int i, int j)
{
	if (i >= 0 && i < N && j >= 0 && j < M)
		return true;
	else
		return false;
}

void Spread(int t_board[8][8], int i, int j)
{
	isSpread[i][j] = true;
	if (IsInBoard(i + 1, j) && t_board[i + 1][j] != 1 && !isSpread[i + 1][j])
	{	//(i,j)가 보드판 내부에 있고 t_board[i+1][j]가 벽이 아니면
		t_board[i + 1][j] = 2;
		Spread(t_board, i + 1, j);
	}
	if (IsInBoard(i, j + 1) && t_board[i][j + 1] != 1 && !isSpread[i][j + 1])
	{
		t_board[i][j + 1] = 2;
		Spread(t_board, i, j + 1);
	}
	if (IsInBoard(i - 1, j) && t_board[i - 1][j] != 1 && !isSpread[i - 1][j])
	{
		t_board[i - 1][j] = 2;
		Spread(t_board, i - 1, j);
	}
	if (IsInBoard(i, j - 1) && t_board[i][j - 1] != 1 && !isSpread[i][j - 1])
	{
		t_board[i][j - 1] = 2;
		Spread(t_board, i, j - 1);
	}
	
}

void SpreadVirus(int t_board[8][8])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (t_board[i][j] == 2 && !isSpread[i][j])
			{	//바이러스 발견
				Spread(t_board, i, j);
			}
		}
	}
}

void AddOneBlock(int t_board[8][8], int addedBlockCount)
{	//addedBlock: 벽을 몇개 추가했는지 count
	int i, j;
	if (addedBlockCount == 3)
	{	//벽 3개 추가 =>t_board에 대해 바이러스를 퍼트리자
		InitIsSpread();	//isSpread를 false
		SpreadVirus(t_board);

		int tempCount = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (t_board[i][j] == 0)
					tempCount++;
			}
		}
		maxSaftyZone = tempCount > maxSaftyZone ? tempCount : maxSaftyZone;
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (t_board[i][j] == 0)
				{	//빈칸이면 벽 하나 추가
					int tempBoard[8][8];
					CopyBoard(t_board, tempBoard);
					tempBoard[i][j] = 1;
					AddOneBlock(tempBoard, addedBlockCount + 1);
				}
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	}
	/*
	입력완료
	*/

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{	//빈칸이면 벽 하나 추가
				int t_board[8][8];
				CopyBoard(board, t_board);
				t_board[i][j] = 1;
				AddOneBlock(t_board, 1);
			}
		}
	}

	cout << maxSaftyZone << endl;
}