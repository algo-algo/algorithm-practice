#include <iostream>
using namespace std;
class Pos
{
public:
	int xPos;
	int yPos;
	Pos() {};
	Pos(int x, int y) :xPos(x), yPos(y) {};
};

//방향에 따라서 currentPos를 이동한 위치를 리턴해주는 함수
Pos ChangePosByDirection(Pos currentPos, int direction)
{
	switch (direction)
	{
	case 1:
		currentPos.yPos++;
		break;
	case 2:
		currentPos.yPos--;
		break;
	case 3:
		currentPos.xPos--;
		break;
	case 4:
		currentPos.xPos++;
		break;
	default:
		break;
	}
	return currentPos;
}
//pos위치가 board 내부에 들어있으면 true
bool CheckPosInBoard(Pos pos, int N, int M)
{
	return (pos.xPos < N && pos.yPos < M&&pos.xPos >= 0 && pos.yPos >= 0);
}

class Dice
{
	int plane[6];			//각 면의 숫자
	Pos currentPos;			//주사위의 현 위치

	//주사위의 놓인 형태는 이 두가지 정보로 결정될 수 있음
	int currentTop;			//주사위의 어떤 면이 현제 위를 바라보고 있는지 담아두자(0~5)
	int currentRightSide;	//주사위의 rightSide정보
	int currentFront;

public:
	Dice(const Pos& pos): currentPos(pos)
	{	//초기 모든 평면의 값은 0
		for (int i = 0; i < 6; i++)
			plane[i] = 0;
		currentTop = 0;
		currentRightSide = 2;
		currentFront = 1;
	}
	Pos GetPos(){ return currentPos; }
	void SetPos(const Pos& pos) { currentPos = pos; }
	
	//전개도 상에서 plain면의 반대편 면을 반환
	int GetAcross(int plain)
	{
		switch (plain)
		{
		case 0:
			return 5;
		case 1:
			return 4;
		case 2:
			return 3;
		case 3:
			return 2;
		case 4:
			return 1;
		case 5:
			return 0;
		default:
			break;
		}
	}
	//direction방향으로 주사위를 굴리는 함수
	void TumbleByDirection(int direction)
	{	
		int temp;
		switch (direction)
		{
		case 1:
			currentPos.yPos++;
			temp = currentRightSide;
			currentRightSide = currentTop;
			currentTop = GetAcross(temp);
			break;
		case 2:
			currentPos.yPos--;
			temp = currentRightSide;
			currentRightSide = GetAcross(currentTop);
			currentTop = temp;
			break;
		case 3:
			currentPos.xPos--;
			temp = currentTop;
			currentTop = currentFront;
			currentFront = GetAcross(temp);
			break;
		case 4:
			currentPos.xPos++;
			temp = currentFront;
			currentFront = currentTop;
			currentTop = GetAcross(temp);
			break;
		default:
			break;
		}
	}

	void SetButtomValue(int val)
	{
		plane[GetAcross(currentTop)] = val;
	}

	int GetButtomValue()
	{
		return plane[GetAcross(currentTop)];
	}

	int GetTopValue()
	{
		return plane[currentTop];
	}
};

int board[20][20];
int instruction[1000];	//굴리는 방향에 대한 지시

int main()
{
	int i, j;
	int N, M;			//지도의 가로 세로 <=20
	int xPos, yPos;		//입력을 위해 선언해둔 변수
	int K;				//명령의 개수 <=1000
	cin >> N >> M >> xPos >> yPos >> K;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	}
	for (i = 0; i < K; i++)
		cin >> instruction[i];
	/*
	*입력 완료
	*/
	Dice myDice(Pos(xPos, yPos));
	Pos  tempPos;
	/*
	*세팅 완료
	*/
	for (i = 0; i < K; i++)
	{	//instruction 수 만큼 반복하면서
		//1. instruction수행 시 보드를 벗어나는지 확인 => 벗어나면 continue
		tempPos = ChangePosByDirection(myDice.GetPos(), instruction[i]);
		if (!CheckPosInBoard(tempPos, N, M))
			continue;
		//2. 주사위 이동
		//=> instruction 방향에 따라 주사위의 currentPos, currentTop, currentRightSide 값 변경
		myDice.TumbleByDirection(instruction[i]);
		//3. 이동한 곳의 보드 값이 0인지 확인
		tempPos = myDice.GetPos();
		if (!board[tempPos.xPos][tempPos.yPos])
		{	//=>3.1 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
			board[tempPos.xPos][tempPos.yPos] = myDice.GetButtomValue();
		}
		else
		{	//=>3.2 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며,
			//	칸에 쓰여 있는 수는 0이 된다.
			myDice.SetButtomValue(board[tempPos.xPos][tempPos.yPos]);
			board[tempPos.xPos][tempPos.yPos] = 0;
		}
		//4. 주사위 top에 있는 값 출력
		cout << myDice.GetTopValue() << endl;
	}


	return 0;
}