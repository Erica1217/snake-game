# plan

# constant / enum

## DIRECTION
```cpp
enum Direction {
    UP, LEFT, DOWN, RIGHT
};
```

# Class

## SnakeMap

### 구현 사항
- Map
    - Map의 크기는 @@@ X @@@로 한다.
    - stage의 개수는 @@@개로 한다.
    - Map[][][]


- Wall
    - Gate 로 변할 수 있다.

- Immune Wall
    - Gate 로 변할 수 없다.

- 모든 Wall
    - Snake 가 통과할 수 없다.
    - Snake Head 와 충돌시 게임 실패

- Gate 의 출현 방법
    - @@@
    - 예시 1 : 게임 시작후 일정 시간 후 출현한다.
    - 예시 2 : 몸의 최대 길이 10 을 초과하면 발생

### attr

```cpp
- totalStageCount: int // stage 개수
- Map[][][]: vector<vector<vector<int>>> // Snake game 전체 맵을 담고 있는 배열
- currentStage: int // 현재 stage 번호, 0부터 시작한다.
- currentMap[][]: vector<vector<int>> // 현재 stage의 맵을 담고 있는 배열
```

### method

```cpp
- getTotalMapCount(): int
- setCurrentMap(int nextStage): void
- getCurrentMap(): vector<vector<int>>
- getPositionInfo(int Y, int X): int 
```

## Point 

### 구현 사항



### attr

```cpp
- Y: int
- X: int
```

## Snake

### 구현 사항
- Snake 는 진행방향의 반대방향으로 이동할
수 없다
- Head 가 진행방향이다
- Head 방향 이동은 무시한다
- Tail 방향으로 이동할 수 없다
- Tail 방향으로 이동시 실패 (Game
- 다른 실패 조건
    - Snake 는 자신의 Body 를 통과할 수 없다
    - Snake 는 벽 (Wall) 을 통과할 수 없다
- Head 방향 이동은 일정시간 틱 에 의해 이동한다
    - 예 ) 틱은 0.5 초
- 진행방향과 같은 방향키 입력은 무시한다.
    - 방향키
        - @@@ : @@@ 
        - @@@ : @@@ 
        - @@@ : @@@
        - @@@ : @@@
Snake 의 이동 방향에 Item 이 놓여 있는 경우
    - Snake 가 Item 을 획득한다
    - Growth Item 의 경우
        - 몸의 길이 ( 가 1 증가한다
    - Poison Item 의 경우
        - 몸의 길이 ( 가 1 감소한다
        - 몸의 길이가 3 보다 작아지면 실패
    - Growth Item 과 Poison Item 의 출현
        - Snake Body 가 있지 않은 임의의 위치에 출현
    - 출현 후 일정시간(@@@)이 지나면 사라지고 다른 위치에 나타나야 한다
    - 동시에 출현할 수 있는 Item 의 수는 3 개로 제한한다

### attr

```cpp
- headPosition: Point
- bodyPosition: vector<Point>
- currnetDirection: int
- bodySize: int
```
### method

```cpp
- move(): void
- isValidSize(): bool
- setDirction(int d): void
```

## Gate

### 구현 사항
- Gate 는 두 개가 한 쌍이다
- Gate 는 겹치지 않는 않는다
- Gate 는 임의의 위치에 있는 벽에서 나타난다
- Gate 에 Snake 가 진입하면 , 다른 Gate 로 진출한다
- Gate 에 Snake 가 진입중인 경우
    - Gate 는 사라지지 않는다
    - 다른 위치에서 Gate 가 나타나지 않는다
- Gate 는 한번에 한쌍만 나타난다

- Gate 가 나타나는 벽이 가장자리에 있을 때, 항상 Map 의 안쪽 방향으로 진출한다.
    - 상단 벽 => 아래 방향
    - 하단 벽 => 위 방향
    - 좌측 벽 => 오른쪽 방향
    - 우측 벽 => 왼쪽 방향
- Gate 가 나타나는 벽이 Map 의 가운데 있을 때 다음의 순서로 진출한다.
    - 진입 방향과 일치하는 방향이 우선
    - 진입 방향의 시계방향으로 회전하는 방향
    - 진입 방향의 역시계방향으로 회전하는 방향
    - 진입 방향과 반대방향

### attr

### method


## Item

### 구현 사항

### attr

### method



## ScoreBoard

### 구현 사항

### attr

### method


## Mission

### 구현 사항

### attr

### method