//{시작 시간, 끝나는 시간, 회의 인원}
//회의를 진행할 수 있는 최대 인원을 출력
//임의의 회의 K(1≤ K ≤ N)는 회의 K − 1과 회의 K + 1과는 회의 시간이 겹치고 다른 회의들과는 회의 시간이 겹치지 않는다.


#include <iostream>
#include <vector>

using namespace std;

struct Meeting
{
	int start, end, person;
};

int					DP[25];
int					N;
vector<Meeting>		meetings;

void InputAndInit()
{
	int s, e, p;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e >> p;
		meetings.push_back({ s,e,p });
	}
}

int Maximun(const int& x1, const int& x2)
{
	return x1 > x2 ? x1 : x2;
}

int main()
{
	InputAndInit();

	if (N == 1) {
		cout << meetings[0].person << '\n';
		return 0;
	}
	DP[0] = meetings[0].person;
	DP[1] = Maximun(DP[0], meetings[1].person);
	for (int i = 2; i < N; i++)
		DP[i] = Maximun(DP[i - 1], DP[i - 2] + meetings[i].person);
	cout << DP[N - 1] << '\n';
}