//#include<iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//int acc[360000];
//
//int timeToInt(const string& time) {
//    int result = 0;
//    result += time[7] - '0';
//    result += (time[6] - '0') * 10;
//    result += (time[4] - '0') * 60;
//    result += (time[3] - '0') * 600;
//    result += (time[1] - '0') * 3600;
//    result += (time[0] - '0') * 36000;
//    return result;
//}
//
//string setDigitForm(string str) {
//    if (str.length() == 1) return "0" + str;
//    return str;
//}
//
//string intToTime(int val) {
//    string hour = setDigitForm(to_string(val / 3600));
//    val %= 3600;
//    string minute = setDigitForm(to_string(val / 60));
//    string second = setDigitForm(to_string(val % 60));
//    return hour + ":" + minute + ":" + second;
//}
//
//string solution(string play_time, string adv_time, vector<string> logs) {
//    for (string& log: logs) {
//        acc[timeToInt(log.substr(0, 8))]++;
//        acc[timeToInt(log.substr(9, 8))]--;
//    }
//
//    int end = timeToInt(play_time), length = timeToInt(adv_time);
//    int cnt = 0, maxTime = 0;
//    long long sum = 0, maxSum = 0;
//    for (int t = 0; t <= end; ++t) {
//        cnt += acc[t];
//        acc[t] = cnt;
//
//        if (sum > maxSum) {
//            maxSum = sum;
//            if (t >= length) maxTime = t - length;
//        }
//
//        sum += acc[t];
//        if (t >= length) sum -= acc[t - length];
//    }
//    if (sum > maxSum) maxTime = end - length;
//
//    return intToTime(maxTime);
//}
//
////string solution(string play_time, string adv_time, vector<string> logs) {
////    vector<pair<int, int>> vec;
////    for (string& log: logs) {
////        vec.push_back({timeToInt(log.substr(0, 8)), timeToInt(log.substr(9, 8))});
////    }
////    sort(vec.begin(), vec.end());
////
////    priority_queue<int> pq;
////    queue<pair<int, int>> que;
////    int end = timeToInt(play_time), length = timeToInt(adv_time);
////    int time = 0, count = 0, val = 0, maxVal = 0, maxTime = 0, idx = 0;
////
////    while (time <= end) {
////        int tmp = 0;
////        while (vec[idx].first <= time) {
////            pq.push(vec[idx++].second);
////            tmp++;
////        }
////
////        while (!pq.empty() && pq.top() <= time) {
////            pq.pop();
////            tmp--;
////        }
////        que.push({time, tmp});
////        count += tmp;
////
////        int next = vec[idx].first;
////        if (!pq.empty() && pq.top() < next) next = pq.top();
////        if (!que.empty() && que.front().first < next + length) next = que.front().first - length;
////
////
////        val += (next - time) * count;
////        time += next;
////
////
////        if (val > maxVal) {
////            maxVal = val;
////            if (time >= length) maxTime = time - length;
////        }
////    }
////
////    return intToTime(maxTime);
////}
//
//int main() {
//    cout << solution("00:00:10", "00:00:10", vector<string>{"00:00:00-00:00:10", "00:00:05-00:00:10"}) << endl;
//    return 0;
//}