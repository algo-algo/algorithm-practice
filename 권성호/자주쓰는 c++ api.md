## 1. Array

0.  헤더
    * 없음
2.  선언
    * 전역 선언
      *  int arr[100]; // default false
      *  프로그래머스에서는 테스트케이스마다 초기화 해 줘야하나? =>
    * 지역 선언
      * int arr[100];

## 2. String
-----------------------
* string에서 index접근 시 char가 나온다. => char는 기본적으로 아스키코드 숫자 값!
* char type을 출력하면 알아서 char로 나옴
* char type을 더하면 정수로 취급됨   
-----------------------

1.  선언
    * string s = "some string";
    * string s;

2.  메소드
    * erase
      * iterator erase (iterator p);
         * p가 가리키는 char를 삭제 
      * iterator erase (iterator first, iterator last);
         * [first, last)의 범위 char를 삭제 
--------------
erase는 iterator와 size_t일때의 동작이 다르니 무조건 iterator로 사용한다고 생각하자!
그리고 erase말고는 다 위치를 size_t로 표현함!!

--------------
    * find
      * size_t find (const string& str, size_t pos = 0) const;
         * pos: 찾기 시작할 위치
         * str: 찾고싶은 문자열
         * retrun: str이 처음 나오는 위치의 index
         * 찾고자 하는 문자열이 없을 때 -1리턴
          
    * insert
      *  string& insert (size_t pos, const string& str);
         * pos: insert point
         * str: 넣어질 string
    * replace
      * string& replace (size_t pos,  size_t len,  const string& str);
         * str: replace될 string
         * [pos,pos+len)만큼의 문자열이 str로 replace됨
       
    * substr
      * string substr (size_t pos = 0, size_t len = npos) const;
         * [pos, pose+len)만큼의 문자열이 substr됨
         
    * stoi, stol, stoll
    

## 3. vector

1.  선언 
   * vector<int> vec;
   
2.  메소드

## 4. set 
1.  선언 
   * set<int> vec;
   
2.  메소드
   * begin
   * end
   * rbegin
   * rend
   * size
   * insert
   * erase
   * find
   * lower_bound
      * iterator lower_bound (const value_type& val) const;
   * upper_bound
      * iterator upper_bound (const value_type& val) const; 

## 5. map
1.  선언 
   * map<int,int> vec;
   
2.  메소드
   * begin
   * end
   * rbegin
   * rend
   * size
   * insert
   * erase
   * find
      * iterator find (const key_type& k); 
   * lower_bound
      * iterator lower_bound (const key_type& k);
   * upper_bound
      * iterator upper_bound (const key_type& k);

## 6. stack

1.  선언 
   * stack<int> s;
   
2.  메소드
   * top(접근용)
   * pop(원소 제거)
   * push
   * size
 


## 7. queue
1.  선언 
   * queue<int> q;
   
2.  메소드
   * front(접근용)
   * pop(원소 제거)
   * push
   * size

## 8. priority queue
1.  선언 
   * priority_queue< int, vector<int>, less<int> > pq;
   * priority_queue< pair<int,int>, vector<pair<int,int>>, less<pair<int,int>> > pq;
   * priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

2.  메소드
   * push
   * pop
   * top
   * size
3. 비교 연산자 제정의 예시
   * ![image](https://user-images.githubusercontent.com/41561652/115808590-b1e12680-a425-11eb-939a-df0cc7c24fe0.png)


## 9. pair

## 10. sort
* 비교 연산자 제정의 예시
   * ![image](https://user-images.githubusercontent.com/41561652/115807833-4d719780-a424-11eb-8acb-266d140202e0.png)
