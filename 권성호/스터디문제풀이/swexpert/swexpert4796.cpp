/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
 
#include<iostream>
 
using namespace std;
 
int N;
int arr[50000];
 
void InputAndInit()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        InputAndInit();
        bool isUp = true;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (isUp && arr[i] < arr[i + 1])         //이전에도 증가하고 있는 와중에 지금도 증가
                cnt++;
            else if (!isUp && arr[i] < arr[i + 1]) { //이전에는 감소하다가 지금 증가
                ans += cnt;
                cnt = 1;
                isUp = true;
            }
            else if (isUp && arr[i] > arr[i + 1]) {      //이전에는 증가하다 지금 감소
                isUp = false;
            }
            else if (!isUp && arr[i] > arr[i + 1]) { //이전에 감소하다가 지금 감소
                ans += cnt;
            }
        }
        //마지막 원소 확인
        if (arr[N-2] > arr[N - 1]) { //지금 감소
            ans += cnt;
        }
 
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}