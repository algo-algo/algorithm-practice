//n개의 곡을 연주
//V[i]는 i번째 곡을 연주하기 전에 바꿀 수 있는 볼륨을 의미
//현재 볼륨이 P이고 지금 i번째 곡을 연주하기 전이라면, i번 곡은 P+V[i]나 P-V[i] 로 연주해야 한다.
//하지만, 0보다 작은 값으로 볼륨을 바꾸거나, M보다 큰 값으로 볼륨을 바꿀 수 없다.(예외 case)

//곡의 개수 N과 시작 볼륨 S, 그리고 M이 주어졌을 때, 
//마지막 곡을 연주할 수 있는 볼륨 중 최댓값을 구하는 프로그램을 작성

//(1 ≤ N ≤ 100, 1 ≤ M ≤ 1000, 0 ≤ S ≤ M)
//둘째 줄에는 각 곡이 시작하기 전에 줄 수 있는 볼륨의 차이가 주어진다. 
//이 값은 1보다 크거나 같고, M보다 작거나 같다.


//(중간에 볼륨 조절을 할 수 없다면) -1을 출력한다.

#include <iostream>
#include <queue>

using namespace std;

int N, S, M;
int V[100];
int check[1001];
queue<int> q;

void InputAndInit() {
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++)
		cin >> V[i];

	check[S] = 1;
	q.push(S);
}

int main()
{
	InputAndInit();

	int cnt = 0;
	while (q.size() != 0 && cnt != N) {
		int len = q.size();
		for (int j = 0; j < len; j++) {
			int idx = q.front(); q.pop();
			if (idx + V[cnt] <= M && check[idx + V[cnt]] != cnt + 1) {
				check[idx + V[cnt]] = cnt + 1;
				q.push(idx + V[cnt]);
			}
			if (idx - V[cnt] >= 0 && check[idx - V[cnt]] != cnt + 1) {
				check[idx - V[cnt]] = cnt + 1;
				q.push(idx - V[cnt]);
			}
		}
		cnt++;
	}

	if (q.size() == 0)
		cout << -1 << "\n";
	else {
		int max = -1;
		int len = q.size();
		for (int i = 0; i < len; i++){
			int current = q.front(); q.pop();
			max = max > current ? max : current;
		}
		cout << max << "\n";
	}
}
