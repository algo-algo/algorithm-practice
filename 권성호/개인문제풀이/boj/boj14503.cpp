#include <iostream>
using namespace std;

int board[50][50];	//default zero

class Pos
{
	int rowPos;
	int colPos;
public:
	Pos(){}
	Pos(int row, int col) :rowPos(row), colPos(col) {};
	int GetRowPos() { return rowPos; }
	int GetColPos() { return colPos; }
	void MoveUp() { rowPos--; }
	void MoveDown() { rowPos++; }
	void MoveLeft() { colPos--; }
	void MoveRight() { colPos++; }
};

class Cleaner
{
	int currentDirection;		//현재 청소기가 바라보고 있는 방향
	Pos currentPos;				//board에서 현재 청소기의 위치
	
public:
	Cleaner(int direction, Pos pos) :currentDirection(direction), currentPos(pos) {};

	void SetPos(Pos pos) { currentPos = pos; }
	Pos GetPos() { return currentPos; }
	
	//방향을 왼쪽으로 이동
	void TurnLeft()
	{
		switch (currentDirection)
		{
		case 0:
			currentDirection = 3;
			break;
		case 1:
			currentDirection = 0;
			break;
		case 2:
			currentDirection = 1;
			break;
		case 3:
			currentDirection = 2;
			break;
		default:
			break;
		}
	}

	//현재 방향 기준으로 currentPos를 한칸 전진
	void GoStraight()
	{
		switch (currentDirection)
		{
		case 0:
			currentPos.MoveUp();
			break;
		case 1:
			currentPos.MoveRight();
			break;
		case 2:
			currentPos.MoveDown();
			break;
		case 3:
			currentPos.MoveLeft();
			break;
		default:
			break;
		}
	}

	//현재 방향 기준으로 currentPos를 한칸 후진
	void GoBack()
	{
		switch (currentDirection)
		{
		case 0:
			currentPos.MoveDown();
			break;
		case 1:
			currentPos.MoveLeft();
			break;
		case 2:
			currentPos.MoveUp();
			break;
		case 3:
			currentPos.MoveRight();
			break;
		default:
			break;
		}
	}

	//현재 방향 기준 정면 한칸 앞이 청소 가능한 구역이면 true
	bool isCleanable(int N, int M)
	{
		Pos t_pos = currentPos;
		switch (currentDirection)
		{
		case 0:
			t_pos.MoveUp();
			break;
		case 1:
			t_pos.MoveRight();
			break;
		case 2:
			t_pos.MoveDown();
			break;
		case 3:
			t_pos.MoveLeft();
			break;
		default:
			break;
		}
		if (t_pos.GetRowPos() < 0 || t_pos.GetRowPos() >= N
			|| t_pos.GetColPos() < 0 || t_pos.GetColPos() >= M)
		{	//벽인 경우
			return false;
		}
		if (board[t_pos.GetRowPos()][t_pos.GetColPos()] == 0)
			return true;
		else
			return false;
	}
	//현재 방향 기준 후진이 가능하면 true
	bool isBackable(int N, int M)
	{
		Pos t_pos = currentPos;
		switch (currentDirection)
		{
		case 0:
			t_pos.MoveDown();
			break;
		case 1:
			t_pos.MoveLeft();
			break;
		case 2:
			t_pos.MoveUp();
			break;
		case 3:
			t_pos.MoveRight();
			break;
		default:
			break;
		}
		if (t_pos.GetRowPos() < 0 || t_pos.GetRowPos() >= N
			|| t_pos.GetColPos() < 0 || t_pos.GetColPos() >= M ||
			board[t_pos.GetRowPos()][t_pos.GetColPos()] == 1)
		{	//벽인 경우
			return false;
		}
		else
			return true;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int count = 0;
	int i, j;
	int N, M;						// 세로,가로 <=50
	int t_row, t_col, t_direction;
	cin >> N >> M;
	cin >> t_row >> t_col >> t_direction;
	Cleaner myCleaner(t_direction, Pos(t_row, t_col));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	}
	/*
	*초기 설정 완료
	*/
	bool	backFlag = false;
	bool	goOne = false;
	Pos		t_pos;
	while (true)
	{
		goOne = false;
		if (!backFlag)
		{	//1. 후진으로 넘어온게 아니라면 현재 위치 청소
			t_pos = myCleaner.GetPos();
			board[t_pos.GetRowPos()][t_pos.GetColPos()] = 2;
			count++;
		}
		backFlag = false;
		for (i = 0; i < 4; i++)
		{
			myCleaner.TurnLeft();
			if (myCleaner.isCleanable(N, M))
			{	//(방금 왼쪽으로 회전한)현재 방향 기준 정면 한칸 앞이 청소 가능한 구역이면 
				myCleaner.GoStraight();		//현재 방향 기준으로 currentPos를 한칸 전진
				goOne = true;
				break;						//1번부터 다시 진행
			}
		}
		if (goOne)
			continue;

		//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는
		if (myCleaner.isBackable(N, M))
		{	//후진이 가능한 경우
			myCleaner.GoBack();
			backFlag = true;
			continue;
		}
		else
		{	//후진이 불가능한 경우
			cout << count << endl;
			return 0;
		}
	}
	return 0;
}