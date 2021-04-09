//#include<iostream>
//
//using namespace std;
//bool candidate[100000];
//
//void addCandidate(int ball, int size) {
//    if (ball > 0) candidate[ball -1] = true;
//    if (ball < size - 1) candidate[ball + 1] = true;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int N, Q;
//        cin >> N >> Q;
//
//        int ball = 0;
//        addCandidate(ball, N);
//
//        for (int i = 0; i < Q; i++) {
//            int A, B;
//            cin >> A >> B;
//            A--; B--;
//            swap(candidate[A], candidate[B]);
//
//            if (ball == A) ball = B;
//            else if (ball == B) ball = A;
//
//                addCandidate(ball, N);
//            }
//
//
//        int result = 0;
//        for (int i = 0; i < N; i++) {
//            if (candidate[i]) {
//                result++;
//                candidate[i] = false;
//            }
//        }
//        cout << "#" << test_case << " ";
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}