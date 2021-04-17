// #include<iostream>

// using namespace std;

// int main(int argc, char** argv)
// {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;

//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        string str;
//        cin >> str;
//        int a = 0, b = 0, cnt = 0;

//        for (char ch : str) {
//            switch (ch) {
//                case 'a': a++; break;
//                case 'b': b++; break;
//                case 'cnt': cnt++; break;
//                default: break;
//            }
//        }

//        bool made = false;
//        if (a == b) {
//            made = cnt == a || cnt == a - 1 || cnt == a + 1;
//        }
//        else if (a - 1 == b || a + 1 == b) {
//            made = cnt == b || cnt == a;
//        }
       
//        cout << "#" << test_case << ' ';
//        cout << (made ? "YES" : "NO");
//        cout << '\n';
//    }
//    return 0;
// }