// #include<iostream>

// using namespace std;
// int rgbMap[3][10];

// void init() {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 10; j++) {
//             rgbMap[i][j] = 0;
//         }
//     }
// }

// bool isSet () {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 8; j++) {
//             while (rgbMap[i][j] >= 3) rgbMap[i][j] -= 3;
//             if (rgbMap[i][j] == 0) continue;
//             rgbMap[i][j + 1] -= rgbMap[i][j];
//             rgbMap[i][j + 2] -= rgbMap[i][j];
//             rgbMap[i][j] = 0;
//             if (rgbMap[i][j + 1] < 0 || rgbMap[i][j + 2] < 0) return false;
//         }
//         if (rgbMap[i][8] % 3 != 0 || rgbMap[i][9] % 3 != 0) return false;
//     }
//     return true;
// }

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
//        init();

//        string str1, str2;
//        cin >> str1 >> str2;
//        int len = str1.length();
//        int r = 0, g = 0, b = 0;
//        for (int i = 0; i < len; i++) {
//            int num = str1[i] - '0' - 1;
//            int rgb = 0;
//            if (str2[i] == 'G') { rgb = 1; g++; }
//            else if (str2[i] == 'B') { rgb = 2; b++; }
//            else r++;
//            rgbMap[rgb][num]++;
//        }
       
//        bool win = r % 3 == 0 && g % 3 == 0 && b % 3 == 0 && isSet();


//        cout << "#" << test_case << ' ';
//        cout << (win ? "Win" : "Continue");
//        cout << '\n';
//    }
//    return 0;
// }