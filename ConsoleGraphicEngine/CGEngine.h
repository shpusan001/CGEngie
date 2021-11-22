#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <cerrno>
#include <string.h>
#include <Windows.h>
#include <process.h>

// 화면 이름 열거형 
enum Menu {
    Main,
    Person,
    Familly,
    Born,
    Marriage,
    Dead,
};

//함수 정의
int mainMenu(char*);

