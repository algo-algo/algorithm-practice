#include <iostream>
#include <string>
#include <vector>
using namespace std;

//direction에 맞게 gear를 1칸 회전(깊은 복사)
void RotateGear(string& gear, int direction)
{
	int i;
	int temp[8];
	for (i = 0; i < 8; i++)
		temp[i] = gear[i];

	if (direction == 1)
	{	//시계
		for (i = 0; i < 7; i++)
		{
			gear[i + 1] = temp[i];
		}
		gear[0] = temp[7];
	}
	else
	{	//반시계
		for (i = 0; i < 7; i++)
		{
			gear[i] = temp[i + 1];
		}
		gear[7] = temp[0];
	}
}

int main()
{
	int i, j, k;
	int temp1, temp2;
	int score = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string	gear[4];						//4개의 톱니바퀴 상태 => 0:N극 / 1:S극
	int		K;								//회전 수 <=100
	vector<pair<int, int>> rotation;		//K개의 회전 방법 <회전시킨 톱니 번호, 방향> // 방향: 1->시계 -1->반시계
	for (i = 0; i < 4; i++)		
		cin >> gear[i];
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> temp1 >> temp2;
		rotation.push_back(make_pair(temp1 -1, temp2));
	}
	/*
	입력 완료
	*/
	int t_direction;
	char leftMgnet, rightMagnet;
	for (i = 0; i < K; i++)
	{	// 루프 한번 당 rotation의 pair를 하나씩 확인해서 톱니를 돌려줘야 함	
		//4. 이 것을 전파가 끝나거나 모든 톱니로 전파가 마무리 될 때 까지 진행

		//1. pair에서 회전시킬 톱니 번호를 얻어서 [2], [6] index의 톱니 값을 얻음 => 추 후에 양 옆으로 전파할 때 사용될 값들
		leftMgnet = gear[rotation[i].first][6];
		rightMagnet = gear[rotation[i].first][2];
		//1. pair에서 회전시킬 톱니 번호를 얻어서 방향에 맞게 회전
		RotateGear(gear[rotation[i].first], rotation[i].second);

		//2.오른쪽 전파
		t_direction = rotation[i].second;
		for (j = rotation[i].first; j < 3; j++)
		{

			if (rightMagnet != gear[j + 1][6])
			{
				t_direction *= -1;
				rightMagnet = gear[j + 1][2];
				RotateGear(gear[j + 1], t_direction);
			}
			else
				break;
		}
		//3. 왼쪽 전파
		t_direction = rotation[i].second;
		for (j = rotation[i].first; j > 0; j--)
		{
			if (leftMgnet != gear[j - 1][2])
			{
				t_direction *= -1;
				leftMgnet = gear[j - 1][6];
				RotateGear(gear[j - 1], t_direction);
			}
			else
				break;
		}
	}

	if (gear[0][0] == '1')
		score++;
	if (gear[1][0] == '1')
		score += 2;
	if (gear[2][0] == '1')
		score += 4;
	if (gear[3][0] == '1')
		score += 8;

	cout << score << endl;
	return 0;
}