//#include<iostream>
//#include<vector>
//
//using namespace std;
//int dice[6];
//int three[8][3] = { {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5} };
//
//int getMinVal(int side) {
//    int min = 2147483647;
//    switch (side) {
//        case 1:
//            for (int & item : dice) min = min < item ? min : item;
//            return min;
//        case 2:
//            // 2개인 경우 AF, BE, CD 제외 모두
//            for (int i = 0; i < 5; ++i) {
//                for (int j = i + 1; j < 6; ++j) {
//                    if (i + j == 5) continue;
//                    int tmp = dice[i] + dice[j];
//                    if (tmp < min) min = tmp;
//                }
//            }
//            return min;
//        case 3:
//            // 3개인 경우 ABC ABD ACE ADE BCF BDF CEF DEF
//            for (auto & item : three) {
//                int tmp = dice[item[0]] + dice[item[1]] + dice[item[2]];
//                if (tmp < min) min = tmp;
//            }
//            return min;
//        default:
//            return 0;
//    }
//}
//
//long long getResult(int n) {
//    long long result = 0;
//    if (n == 1) {
//        int max = 0;
//        for (int & item : dice) {
//            max = max > item ? max : item;
//            result += item;
//        }
//        return result - max;
//    }
//
//    long long nl = n;
//    long long side3 = getMinVal(3);
//    result += side3 * 4;
//
//    long long side2 = getMinVal(2);
//    result += side2 * 4;
//
//    result += side2 * (nl - 2LL) * 8LL;
//
//    long long side1 = getMinVal(1);
//    result += side1 * (nl - 2LL) * (nl * 5LL - 6LL);
//
//    return result;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n;
//    cin >> n;
//    for (int &item : dice) {
//        cin >> item;
//    }
//
//    cout << getResult(n);
//    cout << '\n';
//    return 0;
//}