# snake-game

###  언어
- C++ 프로그래밍 언어
- ncurses

# 게임 방법
기존의 Snake Game 룰을 따르지만, 몇 가지 추가된 기능들이 있다.

뱀이 0.33초에 한번씩 (1초에 3번) 움직인다. 뱀이 한 칸 움직이는 시간을 1틱이라고 정의한다.

> 뱀이 자신의 몸이나 벽에 닿지 않고 최대한 오래 버티며 주어진 Mission을 수행하면 된다.

## 뱀 이동하기(방향키)
![뱀](./img/snake.jpg)

상하좌우는 다음과 같은 방향키로 움직인다.
```
- w : 위
- a : 왼쪽
- s : 아래
- d : 오른쪽
```
선택은 기본적으로 ENTER키로 한다.

## 아이템
![아이템](./img/item.jpg)
- ♥ : Growth Item
    - 이 아이템을 먹으면 뱀의 몸 길이가 1 길어진다.
    - 아이템 생성된 시점에서 20틱 이후 없어진다.
    - 아이템이 없어진 시점에서 3틱 이후 새로운 아이템이 생성된다.
- ♡ : Poison Item
    - 이 아이템을 먹으면 뱀의 몸 길이가 1 짧아진다.
    - 아이템 생성된 시점에서 20틱 이후 없어진다.
    - 아이템이 없어진 시점에서 3틱 이후 새로운 아이템이 생성된다.

## 게이트
>  ▦ 

- 게이트 입구로 들어가면 다른 게이트로 나온다.
- 게이트를 타면 그 게이트는 사라진다.
- 게이트는 5틱이후 다시 생성된다.
- 같은 벽에는 생성되지 않는다.

## 미션
![미션](./img/mission.jpg)
미션은 4가지 종류가 있다.

- 'B' : 현재 몸 길이와 지금까지 몸 길이중 가장 길었던 몸 길이가 출력된다. (현재 몸 길이) / (가장 긴 몸 길이)
- '+' : Growth Item을 먹은 횟수
- '-' : Poison Item을 먹은 횟수
- 'G' : Gate에 들어간 횟수


## C++프로그래밍(3조)

||학번 |이름|github username|
|--|--|--|--|
|조장|20191564|김신건|[shinkeonkim](https://github.com/shinkeonkim)|
|조원|20185290|이하영|[hayeong-lee](https://github.com/hayeong-lee)|
|조원|20191567|김유진|[Erica1217](https://github.com/Erica1217)|
|조원|20152635|김상홍|[bconfiden2](https://github.com/bconfiden2)|
|조원|20191678|최영락|[guahama](https://github.com/guahama)|

> 각 조원이 한 일이 궁금하다면 [클래스 설계](https://github.com/shinkeonkim/snake-game/blob/master/docs/class%20%EC%84%A4%EA%B3%84.md)를 참조해주세요.