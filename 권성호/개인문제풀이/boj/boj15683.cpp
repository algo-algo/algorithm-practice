#include <iostream>
#include <vector>
using namespace std;

class Pos
{
public:
	int row;
	int col;
	Pos(int r, int c) :row(r), col(c) {};
};

char _board[8][8];
int answer = 2147483647;
int N, M;	//사무실의 세로:N 가로: M <=8

// vector를 이용해 CCTVPosSet컨테이너를 만들어 모든 CCTV의 pos를 저장해 둔다.
// => 4^CCTVPosSet.size() 만큼의 케이스가 생기는 것임
vector<Pos> CCTVPosSet;


void LineSpreadByDirection(int direction, Pos pos, char board[8][8])
{
	int j;
	switch (direction)
	{
	case 0:	//동쪽방향
		for (j = pos.col + 1; j < M; j++)
		{
			if (board[pos.row][j] == 6)	//벽
				break;
			else if (board[pos.row][j] == 0)	//빈칸
				board[pos.row][j] = '#';
			else //CCTV 또는 #
				continue;
		}
		break;
	case 1://남쪽방향
		for (j = pos.row + 1; j < N; j++)
		{
			if (board[j][pos.col] == 6)
				break;
			else if (board[j][pos.col] == 0)
				board[j][pos.col] = '#';
			else
				continue;
		}
		break;
	case 2://서쪽
		for (j = pos.col - 1; j >= 0; j--)
		{
			if (board[pos.row][j] == 6)	//벽
				break;
			else if (board[pos.row][j] == 0)	//빈칸
				board[pos.row][j] = '#';
			else //CCTV 또는 #
				continue;
		}
		break;
	case 3://북쪽
		for (j = pos.row - 1; j >= 0; j--)
		{
			if (board[j][pos.col] == 6)
				break;
			else if (board[j][pos.col] == 0)
				board[j][pos.col] = '#';
			else
				continue;
		}
		break;
	default:
		break;
	}
}



void SpreadScope(vector<char> direction)
{
	char board[8][8];
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			board[i][j] = _board[i][j];
	}

	for (i = 0; i < CCTVPosSet.size(); i++)
	{
		//해당 pos의 board값을 확인해서 CCTV종류 확인
		switch (board[CCTVPosSet[i].row][CCTVPosSet[i].col])
		{
		case 1: //1번 CCTV
			LineSpreadByDirection(direction[i], CCTVPosSet[i], board);
			break;
		case 2:	//2번 CCTV
			switch (direction[i])
			{
			case 0:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				break;
			case 1:
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			case 2:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				break;
			case 3:
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			default:
				break;
			}

			break;
		case 3://3번 CCTV
			switch (direction[i])
			{
			case 0:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			case 1:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				break;
			case 2:
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				break;
			case 3:
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			default:
				break;
			}
			break;
		case 4://4번 CCTV
			switch (direction[i])
			{
			case 0:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			case 1:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			case 2:
				LineSpreadByDirection(0, CCTVPosSet[i], board);
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				break;
			case 3:
				LineSpreadByDirection(1, CCTVPosSet[i], board);
				LineSpreadByDirection(2, CCTVPosSet[i], board);
				LineSpreadByDirection(3, CCTVPosSet[i], board);
				break;
			default:
				break;
			}
			break;
		case 5:
			//2. 해당 CCTV의 방향을 확인
			LineSpreadByDirection(0, CCTVPosSet[i], board);
			LineSpreadByDirection(1, CCTVPosSet[i], board);
			LineSpreadByDirection(2, CCTVPosSet[i], board);
			LineSpreadByDirection(3, CCTVPosSet[i], board);
			break;
		default:
			break;
		}
		//3. 그에 맞게 전파 완료 => board를 돌면서 0의 갯수를 카운트
		int count = 0;
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < M; k++)
			{
				if (board[j][k] == 0)
					count++;
			}
		}
		answer = answer > count ? count : answer;
	}

	//direction 메모리 누수 방지
	vector<char> vclear;
	direction.swap(vclear);
	vclear.clear();
	direction.clear();
}

void SetDirection(vector<char> directionSet)
{
	int i, j;
	if (directionSet.size() == CCTVPosSet.size())
	{	//CCTVPosSet의 각 순서별 방향이 다 정해지면
		SpreadScope(directionSet);
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			vector<char> tempDirectionSet = directionSet;
			tempDirectionSet.push_back(i);
			SetDirection(tempDirectionSet);
		}
	}
}

int main()
{
	int i, j, k;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> _board[i][j];
			_board[i][j] -= '0';
			if (_board[i][j] >= 1 && _board[i][j] <= 5)
				CCTVPosSet.push_back(Pos(i, j));
		}
	}
	/*
	입력 완료
	*/

	if (CCTVPosSet.size() == 0)
	{
		int count = 0;
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < M; k++)
			{
				if (_board[j][k] == 0)
					count++;
			}
		}
		answer = count;
	}
	else
	{
		//2. CCTVPosSet을 기반으로 동서남북 케이스에 대해 모든 케이스를 DFS탐색
		for (i = 0; i < 4; i++)
		{
			vector<char> tempDirectionSet;
			tempDirectionSet.push_back(i);
			SetDirection(tempDirectionSet);
		}

	}

	//3. CCTVPosSet의 모든 cctv를 다 check하여 만든 board에 대해서 사각지대를 카운트하여 그중 최소값 선택해서 출력
	cout << answer << endl;
	return 0;
}



