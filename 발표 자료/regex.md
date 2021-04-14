## Regex

- 정규표현식(Regular Expression)이란 특정한 규칙을 가진 문자열을 표현하는데 사용하는 형식 언어
- 주어진 문자열에서 발견할 수 있는 글자 패턴을 표현한 식
- programming language 혹은 text editor에서 문자열 검색 및 치환을 위한 용도로 사용 가능(ex. visual studio)

표현 방법: **/{Expression}/{Flag}**

- sql 검색
  - 'Hi', 'Hello'로 시작하는 문장 검색
```mysql
SELECT *
FROM tbl
WHERE data REGEXP ('^Hi|^Hello');
```

## Exprression
### Chracter class
|Chracter|뜻|예시|
|--|--|--|
| `[]` |\괄호안의 어떤 문자든 하나| `[abc]` |
| `[^]` |부정 문자셋, 괄호안의 문자가 아닐때| `[^abc]` |
| `.` |모든 글자 (줄바꿈 문자 제외)| `...` |
| `\d` |digit 숫자| `\d\d` |
| `\D` |digit 숫자 아님| `\D\D` |
| `\w` |word 문자(변수 명)| `\w\w` |
| `\W` |word 문자 아님| `\W\W` |
| `\s` |space 공백| `\s` |
| `\S` |space 공백 아님| `\S\S` |

### Groups
|Chracter|뜻|예시|
|--|--|--|
| `|` |또는| `a|b` |
| `()` |그룹| `(ab)` |
| `(?:)` |저장하지 않는 그룹| `(?:ab)` |
| `?` |0 or 1| `a?` |
| `*` |0 or more| `a*` |
| `+` |not 0| `a+` |
| `{n}` | n개 | `a{3}` |
| `{a,}` | a 이상 | `a{2,}` |
| `{a,b}` | a 이상 b 이하 | `a{1,3}` |

### Boundary
|Chracter|뜻|예시|
|--|--|--|
| `\b` |단어 경계| `\babc`, `abc\b` | 
| `\B` |단어 경계가 아님| `\Bacb`, `acb\B` |
| `^` |문장의 시작| `^abc` |
| `$` |문장의 끝| `abc$` |

## Flag
### Type
|Flag|뜻|
|--|--|
| `g`| Global: 문자열 내 모든 패턴 탐색|
| `i`| Ignore Case: 대소문자 무시|
| `m`| Multi Line: 행이 바뀌어도 탐색|

## 연습용 사이트
- https://regexr.com/
- https://regexone.com/

### 예시
```
regex

1. Number
3.14529
-255.34
128
1.9e10
123,340.00
720p


2. Phone number
415-555-1234
650-555-2345
416)555-3456
202 555 4567
4035555678
416.555.9292


3. Email
tom@hogwarts.com
tom.riddle@hogwarts.com
tom.riddle+regexone@hogwarts.com
tom@hogwarts.eu.com
potter@hogwarts.com
harry@hogwarts.com
hermione+regexone@hogwarts.com


4. html tag
<a>This is a link</a>
<a href='https://regexone.com'>Link</a>
<div class='test_style'>Test</div>
<div>Hello <span>world</span></div>


5. jpg, png, gif
.bash_profile
workspace.doc
img0912.jpg
updated_img0912.png
documentation.html
favicon.gif
img0912.jpg.tmp
access.lock


6. Trim
			The quick brown fox...
jumps over the lazy dog.


7. Log
W/dalvikvm( 1553): threadid=1: uncaught exception
E/( 1553): FATAL EXCEPTION: main
E/( 1553): java.lang.StringIndexOutOfBoundsException
E/( 1553): at widget.List.makeView(ListView.java:1727)	makeView ListView.java 1727
E/( 1553): at widget.List.fillDown(ListView.java:652)	fillDown ListView.java 652
E/( 1553): at widget.List.fillFrom(ListView.java:709)	fillFrom ListView.java 709


8. URL
ftp://file_server.com:21/top_secret/life_changing_plans.pdf
https://regexone.com/lesson/introduction#section
file://localhost:4040/zip_file
https://s3cur3-server.com:9999/
market://search/angry%20birds
```
