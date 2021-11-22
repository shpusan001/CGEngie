#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include "CGEngine.h"

int mainMenu(char* );

//메인 화면 처리 (이벤트)
int mainMenu(char* message) {

    //메인화면 렌더링
    render(Main);

    //알림 메시지 표시
    if (strcmp(message, "") == 0) {
        printf("알림 메시지 : 없음\n");
    }
    else {
        printf("알림 메시지 : %s\n", message);
    }

    //사용자 입력
    char* userInput[32];
    printf("입력 >>  ");
    scanf("%s", &userInput);

    //다음 이벤트 지정
    if (strcmp(userInput, "1") == 0) {
        eventHandler(mainMenu, "신원 조회");
    }
    else if (strcmp(userInput, "2") == 0) {
        eventHandler(mainMenu, "등본 조회");
    }
    else if (strcmp(userInput, "3") == 0) {
        eventHandler(mainMenu, "출생 신고");
    }
    else if (strcmp(userInput, "4") == 0) {
        eventHandler(mainMenu, "혼인 신고");
    }
    else if (strcmp(userInput, "5") == 0) {
        eventHandler(mainMenu, "사망 신고");
    }
    else {
        eventHandler(mainMenu, "올바르게 입력하세요");
    }
}