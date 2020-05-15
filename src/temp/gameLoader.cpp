#include "gameLoader.h"

void GameLoader::OnLoader()
{
    // 게임이 실행 중
    if(curGameOn)
    {
      //curGame.playing();
    }
    // 게임 모드 선택화면
    else
    {
        Render();
    }

}

// 선택창 렌더링
void GameLoader::Render()
{

}
