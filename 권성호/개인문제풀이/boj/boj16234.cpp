#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int			N, L, R;
int			board[50][50];
bool		boardMask[50][50];	//default false
int			answer;
vector<pair<int, int>> indexSet;

void InitBoardMask()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			boardMask[i][j] = false;
	}
}

bool IsUnion(int people1, int people2)
{
	int absVal = abs(people1 - people2);
	return (absVal >= L && absVal <= R);
}

void FindUnion(int i, int j)
{
	boardMask[i][j] = true;
	if (find(indexSet.begin(), indexSet.end(), make_pair(i, j)) == indexSet.end())
		indexSet.push_back(make_pair(i, j));

	if (j + 1 < N&&IsUnion(board[i][j], board[i][j + 1])&& !boardMask[i][j + 1])
		FindUnion(i, j + 1);
	if (i + 1 < N&&IsUnion(board[i][j], board[i + 1][j]) && !boardMask[i+1][j])
		FindUnion(i + 1, j);
	if (j - 1 >= 0 && IsUnion(board[i][j], board[i][j - 1]) && !boardMask[i][j - 1])
		FindUnion(i, j - 1);
	if (i - 1 >= 0 && IsUnion(board[i][j], board[i - 1][j]) && !boardMask[i-1][j])
		FindUnion(i - 1, j);
	
}

int main()
{
	int i, j, k;
	int average, unionPeopleSize;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> L >> R;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cin >> board[i][j];
	}
	/*
	입력 완료
	*/
	bool			isGo = true;		//열릴 국경선이 하나도 없으면 false
	bool			isConti;
	while (isGo)
	{
		isGo = false;
		InitBoardMask();
		//dfs 방식으로 모든 국가를 탐색하면서 국경선이 열릴지 확인
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{	//board[i][j]를 출발로 연합 찾기
				if (!boardMask[i][j])
				{
					indexSet.clear();
					isConti = false;
					if (j + 1 < N&&IsUnion(board[i][j], board[i][j + 1])&&!boardMask[i][j+1])
					{
						isGo = true;
						isConti = true;
						boardMask[i][j] = true;
						if (find(indexSet.begin(), indexSet.end(), make_pair(i, j)) == indexSet.end())
							indexSet.push_back(make_pair(i, j));
						FindUnion(i, j + 1);
					}
					if (i + 1 < N&&IsUnion(board[i][j], board[i + 1][j]) && !boardMask[i+1][j])
					{
						isGo = true;
						isConti = true;
						boardMask[i][j] = true;
						if (find(indexSet.begin(), indexSet.end(), make_pair(i, j)) == indexSet.end())
							indexSet.push_back(make_pair(i, j));
						FindUnion(i + 1, j);
					}
					if (j - 1 >= 0 && IsUnion(board[i][j], board[i][j - 1]) && !boardMask[i][j - 1])
					{
						isGo = true;
						isConti = true;
						boardMask[i][j] = true;
						if (find(indexSet.begin(), indexSet.end(), make_pair(i, j)) == indexSet.end())
							indexSet.push_back(make_pair(i, j));
						FindUnion(i, j - 1);
					}
					if (i - 1 >= 0 && IsUnion(board[i][j], board[i - 1][j]) && !boardMask[i-1][j])
					{
						isGo = true;
						isConti = true;
						boardMask[i][j] = true;
						if (find(indexSet.begin(), indexSet.end(), make_pair(i, j)) == indexSet.end())
							indexSet.push_back(make_pair(i, j));
						FindUnion(i - 1, j);
					}
					if (isConti)
					{	//board[i][j]를 출발로 관련 연합의 위치를 indexSet에 모두 저장
						unionPeopleSize = 0;
						for (k = 0; k < indexSet.size(); k++)
							unionPeopleSize += board[indexSet[k].first][indexSet[k].second];
						average = unionPeopleSize / indexSet.size();
						for (k = 0; k < indexSet.size(); k++)
							board[indexSet[k].first][indexSet[k].second] = average;
					}


					int x = 8;
				}


			}
		}

		if(isGo)
			answer++;
	}


	cout << answer;
}