//#include<iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Room {
//public:
//    long long start, len;
//    Room(long long start, long long len) : start(start), len(len) {}
//    bool operator==(const Room &rhs) const {
//        return rhs.start >= start && rhs.start <= start + len;
//    }
//    bool operator<(const Room &rhs) const { return start + len < rhs.start; }
//    bool operator>(const Room &rhs) const { return start > rhs.start; }
//    long long addRoom() { return start + len++; }
//    bool isContinuous(const Room &room) const { return room.start == start + len; }
//    void sum(const Room &room) { len += room.len; }
//};
//
//int getIdx(const vector<Room>& rooms, const Room& room) {
//    int l = 0, r = rooms.size() - 1;
//    while (l <= r) {
//        int m = (l + r) / 2;
//        if (rooms[m] < room) l = m + 1;
//        else if (rooms[m] > room) r = m - 1;
//        else return m;
//    }
//    return (l + r) / 2;
//}
//
//vector<long long> solution(long long k, vector<long long> room_number) {
//    vector<long long> answer;
//    vector<Room> rooms;
//    for (long long no: room_number) {
//        Room room(no, 1);
//        if (rooms.empty()) {
//            rooms.push_back(room);
//            answer.push_back(no);
//            continue;
//        }
//
//        int idx = getIdx(rooms, room);
//        if (rooms[idx] == room) {
//            answer.push_back(rooms[idx].addRoom());
//            if (idx + 1 < rooms.size() && rooms[idx].isContinuous(rooms[idx + 1])) {
//                rooms[idx].sum(rooms[idx + 1]);
//                rooms.erase(rooms.begin() + idx + 1);
//            }
//        }
//        else {
//            answer.push_back(no);
//            if (*(rooms.begin() + idx) < room) idx++;
//            if (room.isContinuous(rooms[idx])) {
//                room.sum(rooms[idx]);
//                rooms[idx] = room;
//            }
//            else {
//                rooms.insert(rooms.begin() + idx, room);
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<long long> room_number;
//    room_number.push_back(9);
//    room_number.push_back(8);
//    room_number.push_back(7);
//    room_number.push_back(4);
//    room_number.push_back(6);
//    room_number.push_back(2);
//    room_number.push_back(3);
//    room_number.push_back(1);
//    room_number.push_back(5);
//    room_number.push_back(1);
//    room_number.push_back(2);
//    room_number.push_back(3);
//
//    solution(100, room_number);
//    return 0;
//}