# Ping_Pong

## 컴퓨터공학 포토폴리오 김지우

<img src = "https://user-images.githubusercontent.com/60593969/104157253-228fa480-542e-11eb-9d6b-379f3032b449.gif" width="700px">\

## 간단한 C++ 연습용 게임 

## Class 설계
______________________
|Name|State|Behavior|
|:--:|:--:|--|
|cBall|위치정보(originalX, originalY), 방향(direction)| 현위치 초기화:Reset(), 방향변경:changeDirection(eDir d), 움직이기:Move()|
|cPaddle|위치정보(originalX, originalY)|현위치 초기화:Reset(), 위아래이동:moveUP(),moveDown()|
|cGameManager|console높너비, 점수판, 플레이어입력key값| 점수계산:ScoreUp(), 출력문:Draw(), 공이동:Input(), 공방향지정:Logic(), 실행:Run()|
