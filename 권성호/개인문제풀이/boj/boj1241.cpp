// 자신이 쓴 숫자가 다른 사람이 쓴 숫자의 배수이면 그 학생의 머리를 "톡톡" 친다.

// 전부 확인 => n^2

// 더 최적화 가능?
// hint: a가 b의 배수이고 b가 c의 배수이면 a가 c의 배수임

#include <iostream>

using namespace std;

int inputArr[100001];
int original[1000001];
int ansMap[1000001];
int N;
int maxVal;

void InputAndInit()
{


	maxVal = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> inputArr[i];
		maxVal = maxVal > inputArr[i] ? maxVal : inputArr[i];
	}
	for (int i = 1; i <= 1000001; i++)
		original[i] = 0;
	for (int i = 1; i <= N; i++)
		original[inputArr[i]]++;
	for (int i = 1; i <= 1000001; i++)
		ansMap[i] = original[i];


	return;
}

int main()
{
	InputAndInit();

	for (int i = 1; i <= maxVal; i++) {
		if (original[i] == 0)
			continue;

		int multiple = 2;
		while (i*multiple <= maxVal) {
			ansMap[i*multiple] += original[i];
			multiple++;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ansMap[inputArr[i]] - 1 << "\n";
	}

}