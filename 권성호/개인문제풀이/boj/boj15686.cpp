#include <iostream>
#include <vector>
using namespace std;


int _abs(int x)
{
	return x > 0 ? x : -x;
}

class Pos
{
public:
	int row;
	int col;
	Pos(int r, int c) :row(r), col(c) {};
	
	int Distance(const Pos& pos)
	{
		return _abs(row - pos.row) + _abs(col - pos.col);
	}
};

int				N, M;				//N<=50, M<=13
int				board[50][50];
int				answer = 2147483647;
vector<Pos>		housePos;

//선택된 M개의 치킨집을 가지고 집 하나에 대해 최소 치킨거리 구하는 함수
int MinChickenDistance(Pos house, vector<Pos> chickenPos)
{
	int i;
	int tempMin;
	int minVal = 2147483647;
	for (i = 0; i < chickenPos.size(); i++)
	{
		tempMin = house.Distance(chickenPos[i]);
		minVal = tempMin < minVal ? tempMin : minVal;
	}
	return minVal;
}

int CalMinDistance(vector<Pos> chickenPos)
{
	int minVal = 0;
	int i, j;
	for (i = 0; i < housePos.size(); i++)
		minVal += MinChickenDistance(housePos[i], chickenPos);
	return minVal;
}

void FindchickenPos(vector<Pos> chickenPos, int r, int c)
{
	int i, j;

	if (chickenPos.size() == M)
	{	//치킨집을 모두 선택해서 chickenPos에 위치가 다 저장된 상태 => chickenPos가지고 최소거리 구하기
		int tempMin = CalMinDistance(chickenPos);
		answer = tempMin < answer ? tempMin : answer;
	}
	else
	{
		for (i = r; i < N; i++)
		{
			if (i == r)
			{
				for (j = c + 1; j < N; j++)
				{
					if (board[i][j] == 2)
					{
						vector<Pos> t_chickenPos = chickenPos;
						t_chickenPos.push_back(Pos(i, j));
						FindchickenPos(t_chickenPos, i, j);
					}
				}
			}
			else
			{
				for (j = 0/*c + 1*/; j < N; j++)
				{
					if (board[i][j] == 2)
					{
						vector<Pos> t_chickenPos = chickenPos;
						t_chickenPos.push_back(Pos(i, j));
						FindchickenPos(t_chickenPos, i, j);
					}
				}
			}
			
		}
	}


}


int main()
{
	int i, j, k;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				housePos.push_back(Pos(i, j));
		}

	}
	/*
	입력완료
	*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (board[i][j] == 2)
			{
				vector<Pos> chickenPos;
				chickenPos.push_back(Pos(i, j));
				FindchickenPos(chickenPos, i, j);
			}

		}
	}
	cout << answer << endl;
}