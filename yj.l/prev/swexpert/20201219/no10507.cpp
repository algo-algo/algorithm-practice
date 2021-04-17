// #include<iostream>
// #include<vector>

// using namespace std;

// int getContinueousDay (vector<int> study, int p, int size) {
//     int max = p + 1;
//     if (size == 1) return max;

//     int h, t = 1, len = 1, hacking = p;
//     for (h = 1; h < size; h++) {
//         int chitting = study[h] - study[h - 1] - 1;

//         while (chitting > hacking && h != t) {
//             int re = study[t] - study[t - 1] - 1;
//             len -= re + 1;
//             hacking += re;
//             t++;
//         }

//         if (chitting > hacking) {
//             hacking = p;
//             len = 1;
//             t++;
//             continue;
//         }

//         len += chitting + 1;
//         hacking -= chitting;
//         max = len + hacking > max ? len + hacking : max;
//     }
//     return max;
// }

// int main(int argc, char** argv)
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int test_case;
//     int T;
//     cin>>T;

//     for(test_case = 1; test_case <= T; ++test_case)
//     {
//         vector<int> study;
//         int n, p, num;
//         cin >> n >> p;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> num;
//             study.push_back(num);
//         }

//         cout << "#" << test_case << ' ';
//         cout << getContinueousDay(study, p, n);
//         cout << '\n';
//     }
//     return 0;
// }