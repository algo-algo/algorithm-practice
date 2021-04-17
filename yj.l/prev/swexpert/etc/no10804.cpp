//#include<iostream>
//
//using namespace std;
//char nums[1001];
//
//void init() {
//    for (int i = 0; i < 1001; i++) {
//        if (nums[i] == '\0') break;
//        nums[i] = '\0';
//    }
//}
//
//char reverse(char ch) {
//    switch (ch) {
//        case 'p': return 'q';
//        case 'q': return 'p';
//        case 'b': return 'd';
//        case 'd': return 'b';
//        default: return '\0';
//    }
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
//        cin >> nums;
//
//        int size;
//        for (size = 0; size < 1001; size++) {
//            if (nums[size] == '\0') break;
//        }
//
//        cout << "#" << test_case << " ";
//
//        for (int i = size - 1; i >= 0; i--) {
//            cout << reverse(nums[i]);
//        }
//
//        cout << '\n';
//    }
//    return 0;
//}