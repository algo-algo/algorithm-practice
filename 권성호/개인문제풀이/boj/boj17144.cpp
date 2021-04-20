#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int		R,C;	//<=50
int		T;		//<=1000
int		board[50][50];	
int		t_board[50][50];	//1초간 확산 중 변하는 것은 board 변하지 않는 고정된 것이 t_board
bool    boardMask[50][50];

void InitBoardMask()
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			boardMask[i][j] = false;
	}
}
void InitTempBoard()
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			t_board[i][j] = board[i][j];
	}
}

int main()
{
	int i, j, k;
	int answer = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> R >> C >> T;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			cin >> board[i][j];
	}
	/*
	입력완료
	*/
	vector<pair<int,int>> posSet;
	int spreadAmount;
	int vacumePos;
	while (T-- != 0)
	{
		//미세먼지 전파
		InitBoardMask();
		InitTempBoard();
		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				if (t_board[i][j] > 0)
				{	//미세먼지 발견 => 확산
					//1. 확산할 수 있는 방향 확인  주의: 한번 확산된 영역에서 또 확산하면 안됨
					posSet.clear();
					if (i - 1 >= 0 && t_board[i - 1][j] != -1)
						posSet.push_back(make_pair(i - 1, j));
					if (i + 1 < R&&t_board[i + 1][j] != -1)
						posSet.push_back(make_pair(i + 1, j));
					if (j - 1 >= 0 && t_board[i][j - 1] != -1)
						posSet.push_back(make_pair(i, j - 1));
					if (j + 1 < C && t_board[i][j + 1] != -1)
						posSet.push_back(make_pair(i, j + 1));
					//2. 확산되는 곳에 확산시키고 현재 위치도 갱신한다
					spreadAmount = t_board[i][j] / 5;
					for (k = 0; k < posSet.size(); k++)
						board[posSet[k].first][posSet[k].second] += spreadAmount;
					board[i][j] -= spreadAmount * posSet.size();
				}
			}
		}
		//공기청정기 가동
		//1. 공기청정기 위치 찾기
		//2. 위쪽처리
		//3. 밑쪽처리		
		int direction;
		int next = 0, prev;
		int currentRow, currentCol = 1;
		for (i = 0; i < R; i++)
		{
			if (board[i][0] == -1)
			{
				vacumePos = i;			//vacumePos에는 청정기 위쪽 index를 저장
				break;
			}
		}
		currentRow = vacumePos;
		prev = board[currentRow][currentCol];
		board[currentRow][currentCol] = 0;
		direction = 2;
		while (next != -1)
		{
			switch (direction)
			{
			case 1:
				next = board[--currentRow][currentCol];
				board[currentRow][currentCol] = prev;
				prev = next;
				if (currentRow == 0)
					direction = 4;
				break;
			case 2:
				next = board[currentRow][++currentCol];
				board[currentRow][currentCol] = prev;
				prev = next;
				if (currentCol == C - 1)
				{	//방향전환 필요
					direction = 1;
				}
				break;
			case 3:
				next = board[++currentRow][currentCol];
				if(next !=-1)
					board[currentRow][currentCol] = prev;
				prev = next;
				break;
			case 4:
				next = board[currentRow][--currentCol];
				board[currentRow][currentCol] = prev;
				prev = next;
				if (currentCol == 0)
					direction = 3;
				break;
			default:
				break;
			}
		}

		currentCol = 1;
		next = 0;
		currentRow = vacumePos + 1;
		prev = board[currentRow][currentCol];
		board[currentRow][currentCol] = 0;
		direction = 2;
		while (next != -1)
		{
			switch (direction)
			{
			case 1:
				next = board[--currentRow][currentCol];
				if (next != -1)
					board[currentRow][currentCol] = prev;
				prev = next;
				break;
			case 2:
				next = board[currentRow][++currentCol];
				board[currentRow][currentCol] = prev;
				prev = next;
				if (currentCol == C - 1)
				{	//방향전환 필요
					direction = 3;
				}
				break;
			case 3:
				next = board[++currentRow][currentCol];
				if (next != -1)
					board[currentRow][currentCol] = prev;
				prev = next;
				if (currentRow == R-1)
					direction = 4;
				break;
			case 4:
				next = board[currentRow][--currentCol];
				board[currentRow][currentCol] = prev;
				prev = next;
				if (currentCol == 0)
					direction = 1;
				break;
			default:
				break;
			}
		}
	}

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (board[i][j] > 0)
				answer += board[i][j];
		}
	}

	cout << answer;
}