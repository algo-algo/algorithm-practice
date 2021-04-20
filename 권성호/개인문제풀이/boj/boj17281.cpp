//1) 타자 9명을 배정할 수 있는 모든 case에 대해 조사 => 9명중 중복 허용 안하고 9명 뽑는 모든 case
//2) 각 case에 대해 점수 계산
//3) 점수 중 max print
#include <iostream>
#include <vector>

using namespace std;

int			N;
int			hitters[50][9];	//매 이닝에서의 타자들의 결과
int			seq[9];			//타자의 순서가 저장될 배열(0번째에서 8번째까지)
bool		check[9];		//중복 확인 배열(default false)
int			ans = 0;


int CalScore() {	//현 seq에 대해 점수 계산
	int score = 0;
	int currentHitterIndex = 0;

	for (int i = 0; i < N; i++) {	//0이닝부터 N-1 이닝까지 쭉 돌면서 (hitters[i]=> i번째 이닝에서의 타자들의 결과)
		int outCnt = 0;
		int runners[4] = { 1,0,0,0 };
		while (true) {

			if (hitters[i][seq[currentHitterIndex]] == 0) {			//아웃
				outCnt++;
			}
			else if (hitters[i][seq[currentHitterIndex]] == 1) {	//안타
				if (runners[3] == 1)
					score++;
				for (int i = 2; i >= 0; i--)
					runners[i + 1] = runners[i];
				runners[0] = 1;
			}
			else if (hitters[i][seq[currentHitterIndex]] == 2) {	//2루타
				if (runners[3] == 1)
					score++;
				if (runners[2] == 1)
					score++;
				runners[2] = runners[0];
				runners[3] = runners[1];
				runners[0] = 1;
				runners[1] = 0;
			}
			else if (hitters[i][seq[currentHitterIndex]] == 3) {	//3루타
				if (runners[3] == 1)
					score++;
				if (runners[2] == 1)
					score++;
				if (runners[1] == 1)
					score++;
				runners[0] = 1;
				runners[1] = 0;
				runners[2] = 0;
				runners[3] = 1;
			}
			else if (hitters[i][seq[currentHitterIndex]] == 4) {	//홈련
				if (runners[3] == 1)
					score++;
				if (runners[2] == 1)
					score++;
				if (runners[1] == 1)
					score++;
				if (runners[0] == 1)
					score++;

				runners[0] = 1;
				runners[1] = 0;
				runners[2] = 0;
				runners[3] = 0;
			}
			currentHitterIndex = (currentHitterIndex + 1) % 9;
			if (outCnt == 3)	//3아웃이면 이번 이닝 끝
				break;
		}
	}

	return score;
}

void Brute_Force(int cnt) {	//cnt: 몇명을 뽑았는지

	if (cnt == 3) {	//4번째 선수는 이미 뽑혔음
		Brute_Force(cnt + 1);
		return;
	}

	if (cnt == 9) {	//9명을 뽑았다면 => 현 순서에 대해 점수 계산
		int score = CalScore();
		ans = ans > score ? ans : score;
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (!check[i]) {	//check[i]가 false라면 => i번째 선수는 안뽑힌 것 => 뽑자
			check[i] = true;
			seq[cnt] = i;
			Brute_Force(cnt + 1);
			check[i] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++){
		int temp;
		for (int j = 0; j < 9; j++) {
			cin >> temp;
			hitters[i][j] = temp;
		}
	}
	/*input*/

	check[0] = true;
	seq[3] = 0;	//4번 타자는 1번선수가 친다

	Brute_Force(0);

	cout << ans;
}