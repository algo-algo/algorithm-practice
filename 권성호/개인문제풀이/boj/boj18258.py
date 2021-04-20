import sys

input=sys.stdin.readline

#리스트를 사용해 queue구현
class MyQueue:
    def __init__(self):
        self.queue = []
        self.cnt = 0                #사실상 queue의 맨 앞을 가리키는 놈

    def push(self,X):               #리스트의 맨 뒤가 데이터가 들어가는 곳이고 맨 앞이 나가는 곳으로 설계
        self.queue.append(X)

    def pop(self):
        if len(self.queue) <= self.cnt:
            return -1
        else:
            result = self.queue[self.cnt]
            self.cnt = self.cnt+1
        return result     #맨 앞 요소를 반환하고 삭제

    def size(self):
        return len(self.queue)-self.cnt

    def empty(self):
        if len(self.queue) <= self.cnt:
            return 1
        return 0

    def front(self):
        if len(self.queue) <= self.cnt:
            return -1
        return self.queue[self.cnt]

    def back(self):
        if len(self.queue) <= self.cnt:
            return -1
        return self.queue[-1]

cmdNum = int(input().strip())
q = MyQueue()
for i in range(cmdNum):
    cmdStr = input().strip()
    cmd = None
    number = None
    if len(cmdStr.split(' ')) == 2:
        cmd, number = cmdStr.split(' ')
        number = int(number)
    else:
        cmd = cmdStr

    if cmd == 'push':
        q.push(number)
    elif cmd == 'pop':
        print(q.pop())
    elif cmd == 'size':
        print(q.size())
    elif cmd == 'empty':
        print(q.empty())
    elif cmd == 'front':
        print(q.front())
    elif cmd == 'back':
        print(q.back())
