// #include<iostream>
// #include<vector>

// #define MAX 2000000000000000000LL
// using namespace std;
// string bobNalice[] = {"Bob", "Alice"};

// void setVector (vector<long long int>& vec) {
//     long long int a = 2, b = 3;
//     for (int i = 0; a < MAX && b < MAX; i++) {
//         int btern = i & 1;
//         int atern = !btern;

//         if (atern) vec.push_back(a);
//         else vec.push_back(b);

//         a *= 2;
//         b *= 2;
//         a += atern;
//         b += btern;
//     }
// }

// string getResult(vector<long long int>& vec, long long int num) {
//     int size = vec.size();
//     for (int i = 0; i < size; i++) {
//         if (num < vec[i]) return bobNalice[i % 2];
//     }
// }

// int main(int argc, char** argv)
// {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;

//     vector<long long int> vec;
//     setVector(vec);

//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        long long int N;
//        cin >> N;

//        cout << "#" << test_case << ' ';
//        cout << getResult(vec, N);
//        cout << '\n';
//    }
//    return 0;
// }