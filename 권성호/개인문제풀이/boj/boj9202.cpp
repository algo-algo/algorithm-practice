//찾아야할 단어의 최대 길이가 8이라는 것을 이용해 보자
//
//- 처음w를 다 벡터에 담아두고 w[i]가 발견될 때 마다 i를 방문표시 후 별도 detectSet에 넣어주자
//
//- board에서 bfs로 찾을 때 한 글자마다 후보군 w[i]의 i값을 들고다니면서 후보군이 없을 경우 backtracking 조건으로 쓰자

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Pose {
public:
	int x, y;
	Pose() {};
	Pose(const int& x, const int& y) {
		this->x = x;
		this->y = y;
	}
};

string		wordDictionary[300000];
bool		checkwordDictionary[300000];
int			wordNum;
int			boggleNum;
string		boggleBoard[4];
bool		checkBoggleBoard[4][4];

const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

struct cmp {
	bool operator() (string a, string b) const {
		if (a.size() == b.size())
		{
			return a < b;
		}
		return a.size() > b.size();
	}
};

set<string, cmp> findStrSet;

void InputAndInit() {
	findStrSet.clear();	//발견된 놈은 set에 추가 후 wordDictionary에서는 지우자(중복 제거)
	for (int i = 0; i < wordNum; i++)
		checkwordDictionary[i] = false;
	for (int r = 0; r < 4; r++)
		cin >> boggleBoard[r];
}

void InitCandidateIdxVec(const char& firstChar, vector<int>& candidateIdxVec) {
	candidateIdxVec.clear();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			checkBoggleBoard[i][j] = false;

	for (int r = 0; r < wordNum; r++){
		if (checkwordDictionary[r] == true || wordDictionary[r][0] != firstChar) 
			continue;
		if (wordDictionary[r].size() == 1){
			findStrSet.insert(wordDictionary[r]);
			checkwordDictionary[r] = true;
		}
		else
			candidateIdxVec.push_back(r);
	}
}

bool IsInTheBoard(const Pose& p)
{
	return (p.x >= 0 && p.x < 4 && p.y >= 0 && p.y < 4);
}

void DFS(Pose currentPose, int depth, const vector<int>& candidateIdxVec)
{
	if (candidateIdxVec.size() == 0 || depth == 8)
		return;

	for (int i = 0; i < 8; i++){
		Pose nextPose({ currentPose.x + dx[i], currentPose.y + dy[i] });
		if (!IsInTheBoard(nextPose) || checkBoggleBoard[nextPose.x][nextPose.y] == true)
			continue;

		vector<int> nextCandidateIdxVec;
		for (int r = 0; r < candidateIdxVec.size(); r++){
			if (checkwordDictionary[candidateIdxVec[r]] != false || wordDictionary[candidateIdxVec[r]][depth] != boggleBoard[nextPose.x][nextPose.y])
				continue;
			if (wordDictionary[candidateIdxVec[r]].size() == depth + 1)
			{
				findStrSet.insert(wordDictionary[candidateIdxVec[r]]);
				checkwordDictionary[candidateIdxVec[r]] = true;
			}
			else
				nextCandidateIdxVec.push_back(candidateIdxVec[r]);
		}
		checkBoggleBoard[nextPose.x][nextPose.y] = true;
		DFS(nextPose, depth + 1, nextCandidateIdxVec);
		checkBoggleBoard[nextPose.x][nextPose.y] = false;
	}
}

void DoProcess()
{
	//해당 boggleBoard에 대해, 얻을 수 있는 최대 점수, 가장 긴 단어, 찾은 단어의 개수를 출력
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			vector<int> candidateIdxVec;
			InitCandidateIdxVec(boggleBoard[i][j], candidateIdxVec);
			checkBoggleBoard[i][j] = true;
			DFS(Pose(i, j), 1, candidateIdxVec);
			checkBoggleBoard[i][j] = false;
		}
	}
}

void PrintResult()
{	//findStrSet을 순회하면서 얻을 수 있는 최대 점수, 가장 긴 단어(여러개라면 그중 사전순 가장 앞-> set 정렬 기준 제정의 해서 한번에 찾자), 찾은 단어의 개수를 출력

	int maxScore = 0;
	for (auto iter = findStrSet.begin(); iter != findStrSet.end(); iter++)
	{
		if (iter->size() >= 1 && iter->size() <= 2)
			maxScore += 0;
		else if (iter->size() >= 3 && iter->size() <= 4)
			maxScore += 1;
		else if (iter->size() == 5)
			maxScore += 2;
		else if (iter->size() == 6)
			maxScore += 3;
		else if (iter->size() == 7)
			maxScore += 5;
		else if (iter->size() == 8)
			maxScore += 11;
	}
	string longestStr = *findStrSet.begin();
	int num = findStrSet.size();
	cout << maxScore << " " << longestStr << " " << num << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> wordNum;
	for (int i = 0; i < wordNum; i++)
		cin >> wordDictionary[i];

	cin >> boggleNum;
	for (int test_case = 0; test_case < boggleNum; test_case++) 
	{
		InputAndInit();
		DoProcess();
		PrintResult();
	}
	return 0;
}