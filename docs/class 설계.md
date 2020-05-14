# class 설계

## SnakeMap
### attr

```cpp
- totalMapCount: int
- Map[][][]: vector<vector<vector<int>>>
- currentStage: int
- currentMap[][]: vector<vector<int>>
```

### method

```cpp
- getTotalMapCount(): int
- getCurrentMap(): vector<vector<int>>
- getPositionInfo(int Y, int X): int 
```

## Point 
### attr
```cpp
- Y: int
- X: int
```

## Snake
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



## Item