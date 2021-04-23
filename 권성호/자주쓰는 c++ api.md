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


1.  선언
    * string s = "some string";
    * string s;

2.  메소드
<details>
   
    * <summary> erase <summary>
    
      * iterator erase (iterator p);
         * p가 가리키는 char를 삭제 
      * iterator erase (iterator first, iterator last);
         * [first, last)의 범위 char를 삭제 
    * find
      * size_t find (const string& str, size_t pos = 0) const;
         * pos: 찾기 시작할 위치
         * str: 찾고싶은 문자열
         * retrun: str이 처음 나오는 위치의 index
         
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
    
<details>

## 3. vector

## 4. set   

## 5. map

## 6. stack

## 7. queue

## 8. priority queue

## 9. pair

## 10. sort
