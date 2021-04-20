#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int				R, C, M;
bool			board[100][100];

class Pos
{
public:
	int row;
	int col;
	Pos() {};
	Pos(int r, int c) :row(r), col(c) {};

	bool operator==(const Pos& pos)
	{
		return row == pos.row && col == pos.col;
	}
};

class Shark
{
public:
	Pos pos;
	int s;
	int d;
	int z;
	Shark(Pos p, int _s, int _d, int _z) :pos(p), s(_s), d(_d), z(_z) {};

	//Pos같으면 같다고 하는 연산으로 == 을 지정
	bool operator==(const Shark& shark)
	{
		return pos == shark.pos;
	}

	Pos Move()
	{
		int i;
		int t_s = s;
		int length;
		switch (d)
		{
		case 1:
			length = pos.row;
			break;
		case 2:
			length = R - 1 - pos.row;
			break;
		case 3:
			length = C - 1 - pos.col;
			break;
		case 4:
			length = pos.col;
			break;
		default:
			break;
		}
		while (t_s >= length * 2)
		{
			t_s -= length * 2;
			switch (d)
			{
			case 1:
				d = 2;
				length = R - 1 - pos.row;
				break;
			case 2:
				d = 1;
				length = pos.row;
				break;
			case 3:
				d = 4;
				length = pos.col;
				break;
			case 4:
				d = 3;
				length = C - 1 - pos.col;
				break;
			default:
				break;
			}
		}

		//최종적으로 t_s번만 상어를 더 이동시키면 된다.
		for (i = 0; i < t_s; i++)
		{
			switch (d)
			{
			case 1:
				if (pos.row == 0)
				{
					d = 2;
					pos.row++;
				}
				else
					pos.row--;
				break;
			case 2:
				if (pos.row == R - 1)
				{
					d = 1;
					pos.row--;
				}
				else
					pos.row++;
				break;
			case 3:
				if (pos.col == C - 1)
				{
					d = 4;
					pos.col--;
				}
				else
					pos.col++;
				break;
			case 4:
				if (pos.col == 0)
				{
					d = 3;
					pos.col++;
				}
				else
					pos.col--;
				break;
			default:
				break;
			}
		}

		return pos;
	}
};

bool cmp(const Shark& s1, const Shark& s2)
{
	return s1.z < s2.z;
}

vector<Shark>	sharkSet;

//보드 초기화
void InitBoard()
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			board[i][j] = false;
	}
}

//sharkSet가지고 보드 색칠
void DrawBoard()
{
	int i;
	for (i = 0; i < sharkSet.size(); i++)
		board[sharkSet[i].pos.row][sharkSet[i].pos.col] = true;
}

int main()
{
	int i, j, k;
	int answer = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> R >> C >> M;
	//상어 입력
	int row, col, s, d, z;
	for (i = 0; i < M; i++)
	{
		cin >> row >> col >> s >> d >> z;
		sharkSet.push_back(Shark(Pos(row-1, col-1), s, d, z));
	}
	/*
	입력완료
	*/
	InitBoard();
	DrawBoard();
	for (i = 0; i < C; i++)
	{	
		//1. i행 상어 낚시
		for (j = 0; j < R; j++)
		{
			if (board[j][i])
			{	//처음 물고기 발견
				Shark t_shark(Pos(j, i), 0, 0, 0);
				auto iter = find(sharkSet.begin(), sharkSet.end(), t_shark);
				answer += iter->z;
				sharkSet.erase(iter);
				break;
			}
		}
		//2. 상어 이동
		InitBoard();
		vector<Pos> delPosSet;
		for (j = 0; j < sharkSet.size(); j++)
		{
			Pos t_pos = sharkSet[j].Move();
			if (board[t_pos.row][t_pos.col])
			{	//이미 상어가 있는 자리라면 => 크기가 큰 상어만 남기고 나머지 상어는 지워야함
				delPosSet.push_back(t_pos);
			}
			else
				board[t_pos.row][t_pos.col] = true;
		}
		sort(sharkSet.begin(), sharkSet.end(), cmp);
		for (j = 0; j < delPosSet.size(); j++)
		{
			auto iter = find(sharkSet.begin(), sharkSet.end(), Shark(delPosSet[j], 0, 0, 0));
			sharkSet.erase(iter);
		}

	}


	cout << answer;
}