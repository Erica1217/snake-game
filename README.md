# snake-game

- C++ 프로그래밍 언어로 ncurses 라이브러리를 사용하여 Snake Game을 구현하였습니다.

# C++프로그래밍 /  3조
||학번 |이름|github username|
|--|--|--|--|
|조장|20191564|김신건|shinkeonkim|
|조원|20185290|이하영|hayeong-lee|
|조원|20185290|이하영|hayeong-lee|
|조원|20185290|이하영|hayeong-lee|
|조원|20185290|이하영|hayeong-lee|

# class 설계
- [참고사항](##참고)
- [SnakeMap](##SnakeMap) 김유진
- [Snake](##Snake) 김신건
- [Mission](##Mission) 최영락
- [ScoreBoardInfo](##ScoreBoardInfo) 이하영

- [Item](##Item) 이하영
- [Gate](##Gate) 김유진
- [ItemManager](##ItemManager) 최영락
- [GateManager](##GateManager) 김유진


- [GameManager](##GameManager)
- [Game](##Game) 
- [UIManager](##UIManager)
- [GameFlow](##GameFlow)
- [Point](##Point)



## 참고

### SnakeMap 요소 번호 목록
- 움직여도 되는 곳 : 0 
- SNAKE_HEAD : 1
- SNAKE: 2
- WALL : 3
- IMMUNE_WALL: 4
- GATE: 5
- GROWTH_ITEM: 6 
- POSION_ITEM: 7

## SnakeMap
- 생성자
    - SnakeMap(): 
- 멤버 변수
    - int total_stage_count: 전체 게임 stage의  개수 
    - vector<vector<vector<int>>> total_map: Snake game 전체 맵의 초기상태를 담고 있는 3차원 벡터. 인덱스 형식은 [stage][X][Y] 이다.
    - int current_stage: 현재 stage 번호, 0부터 시작한다.
    - vector<vector<int>> current_map: 현재 stage의 맵을 담고 있는 2차원 백터

- 멤버 함수
    - public
        - int getTotalMapCount(): 전체 게임 stage의 개수를 반환한다.
        - vector<vector<int>> getCurrentMap(): currnet_map을 반환한다.
        - int getPositionInfo(int x, int y): current_map[x][y]를 반환한다.
        - void setCurrentMap(int next_stage): currnet_stage를 next_stage로 set하고, current_map을 totalmap[next_stage]로 변경한다.
        - void setPositionInfo(int x, int y, int Info): current_map[x][y]를 info로 변경한다. info로 들어오는 숫자는 [참고사항의 SnakeMap 요소 번호 목록](##참고) 확인

        - void update (vector<Point> snake, vector<Point> gates, vector<Point> items) : 뱀, 게이트, 아이템 정보를 맵에 반영한다. 


## Snake 싱글톤
- 생성자

- 멤버 변수
    - final INIT_HEAD
    - final vector<point> INIT_BODY
    - final int INIT_DIRECTION
    - final int INIT_BODYSIZE
 
    - body_positions: vector<Point>
    - int current_direction: 

- 멤버 함수
    - void clear(): 
    - void move(): 
    - int getSnakeSize(): 
    - Point getHeadPosition(): body_positions[0]을 return한다.
    - bool isValidSize(): 
    - void setDirction(int d): 

### 구현 사항
- Snake 는 진행방향의 반대방향으로 이동할 수 없다
- Head 가 진행방향이다
- Head 방향 이동은 무시한다
- Tail 방향으로 이동할 수 없다
- Tail 방향으로 이동시 실패 (Game)
- 다른 실패 조건
    - Snake 는 자신의 Body 를 통과할 수 없다
    - Snake 는 벽 (Wall) 을 통과할 수 없다
- Head 방향 이동은 일정시간 틱 에 의해 이동한다
    - 예 ) 틱은 0.5 초
- 진행방향과 같은 방향키 입력은 무시한다.
    - 방향키
        - 위 : w 
        - 아래: s 
        - 왼쪽 : a
        - 오른쪽 : d
Snake 의 이동 방향에 Item 이 놓여 있는 경우
    - Snake 가 Item 을 획득한다
    - Growth Item 의 경우
        - 몸의 길이가 1 증가한다
    - Poison Item 의 경우
        - 몸의 길이가 1 감소한다
        - 몸의 길이가 3 보다 작아지면 실패
    - Growth Item 과 Poison Item 의 출현
        - Snake Body 가 있지 않은 임의의 위치에 출현
    - 출현 후 일정시간(10틱)이 지나면 사라지고 다른 위치에 나타나야 한다
    - 동시에 출현할 수 있는 Item 의 수는 3 개로 제한한다
    - 3개는 언제 만듬?

## Mission
- 생성자
    - Mission()
- 멤버변수
    - 뱀의 길이
    - poison_item_count
    - grows_item_count
    - Gate 사용횟수


- 멤버함수
    - setMission()
    - isComplete(stage, userData) : bool
    

## Item
- 생성자
    - Item()모두
- 멤버변수
    - Point pos: 아이템의 위치(positon)

    - int kinds : 아이템의 종류
        - 1: growth item
        - 2: posion item
    - int created_tick : 아이템 생성 시기 

## ItemManager
- 생성자
    - ItemManager()

- 멤버변수
    - vector<Item> items
- 멤버 함수
  - void makeItem()
  - Point eatItem()
  - void deleteItem()
    - 생성자에서 랜덤으로! 맵과 비교하며 적당한 난수 생성


## GateManager
- 생성자 :
    - GateManager(vector<vector<int>> snake_map)

- 멤버 변수 :
    - vector<Point> gate
    - bool is_passing: 뱀이 통과중인지 확인용
    - int life_time: 게이트 생존 시간 처리용

- 멤버 함수
    - public :
        - bool isPassing(): 매 프레임 호출되어서 게이트 유효성 체크 // 만들어진지 일정시간 지났거나 뱀이 다 통과했을 시 makeNewGate
        
        - Point isSnakeInGate(Point head): 스네이크 머리가 게이트인지? -> 반대편 게이트로 나올 위치 반환 // 뱀의 현재 dir 도 받아야 함

        - vector<Point> getGates();

        - void makeNewGate(): 맵에서 일반 wall 위치 중 새로운 게이트 생성
    - private :
    
## UserData
 - 생성자
    - UserData(){
        int current_length = 3;
        int max_length = 3;
        int growth_item_count = 0;
        int posion_item_count = 0;
        int used_gate_length = 0;
    }
    - UserData(int current_length, int max_length, int growth_item_count, int posion_item_count, int used_gate_count)
 - 멤버 변수
     - int current_length: 현재 뱀의 길이
     - int max_length: 현 라운드의 뱀의 최대 길이
     - int growth_item_count: 성장 아이템을 먹은 횟수
     - int posion_item_count: 독 아이템을 먹은 횟수
     - int used_gate_count: 게이트를 사용한 횟수
 - 멤버 함수
     - int getCurrentLength(): 현재 길이 반환
     - void setCurrentLength(int current_length): 현재 길이 설정
     - int getMaxLength(): 최대 길이 반환
     - void setMaxLength(int max_length): 최대 길이 설정
     - int getGrouthItemCount(): 성장 아이템 먹은 횟수 반환
     - void setGrowhItemCount(int grouth_item_count): 성장 아이템 먹은 횟수 설정
   

     - int getPosionItemCount(): 
     - void setPosionCount(int posion_item_count): 
     - int getUsedGateCount(): 
     - void setUsedGateCount(int used_gate_count):
      -  void GrowthItemIncrease() :성장아이템 먹은 횟수+1
    -  void PoisonItemIncrease() :감소아이템 먹은 횟수+1
    -  void UsedGateCountIncrease(); 게이트를 사용한 횟수+1

## Point
    - 멤버 변수

    - 멤버 함수
        - Point moveTo(Point origin);
        - bool isValid();