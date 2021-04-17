//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class City {
//public:
//    int x, y, num, checkMap;
//    double e;
//    City* cp;
//    City (int x, int y, int checkMap, int num) { this->x = x; this->y = y; this->checkMap = checkMap; this->num = num; cp = nullptr; e = checkMap; }
//    bool operator==(const City& city) const { return x == city.x && y == city.y && checkMap == city.checkMap; }
//};
//City noKing(-1, -1, -1, -1);
//
//void giveUp(City& c1, City& c2, int distance) {
//    double effect = c2.checkMap / (double) distance;
//    if (effect > c1.e) {
//        c1.cp = &c2;
//        c1.e = effect;
//    }
//    else if (effect == c1.e && c1.cp != nullptr) c1.cp = &noKing;
//}
//
//void effect(City& a, City& b) {
//    int dx = a.x - b.x;
//    int dy = a.y - b.y;
//    int distance = dx * dx + dy * dy;
//    giveUp(a, b, distance);
//    giveUp(b, a, distance);
//}
//
//void fight(vector<City>& cities) {
//    int size = cities.size();
//    for (int i = 0; i < size; ++i) {
//        for (int j = i + 1; j < size; ++j) {
//            effect(cities[i], cities[j]);
//        }
//    }
//}
//
//void printCities(const vector<City>& cities) {
//    for (City city : cities) {
//        cout << ' ';
//        if (city.cp == &noKing) cout << 'D';
//        else if (city.cp == nullptr) cout << 'K';
//        else {
//            City* tmp = city.cp;
//            while (tmp->cp != nullptr) {
//                tmp = tmp->cp;
//            }
//            cout << tmp->num;
//        }
//    }
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int N;
//        cin >> N;
//        int x, y, checkMap;
//        vector<City> cities;
//        for (int i = 1; i <= N; ++i) {
//            cin >> x >> y >> checkMap;
//            cities.push_back({x, y, checkMap, i});
//        }
//
//        fight(cities);
//
//        cout << "#" << test_case;
//        printCities(cities);
//        cout << '\n';
//    }
//    return 0;
//}