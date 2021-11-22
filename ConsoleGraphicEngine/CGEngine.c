#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <cerrno>
#include <string.h>
#include <Windows.h>

#include "CGEngine.h"

void CGEngineStart(int(*dbEvent)());



//화면 파일 정의
const char* menuFileName[] = { "MainMenu.txt", "Person.txt", "Familly.txt", "Born.txt", "Marriage.txt", "Dead.txt" };


int main() {
    //CGEngine 시작, mainMenu 이벤트로 첫 시작
    CGEngineStart(mainMenu);
}

//엔진 시작 
void CGEngineStart(int(*dbEvent)()) {
    eventHandler(dbEvent, "");
}

//이벤트 핸들러
int eventHandler(int(*dbEvent)(char*), char* message) {
    dbEvent(message);
}

//커서 이동
void setCusor(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//화면 렌더링 
int  render(int file)
{
    char buffer[256];    // 파일 버퍼

    FILE* fp;
    errno_t err;

    char* filename = menuFileName[file];

    // 버퍼 쓰레기 값 정리
    for (int i = 0; i < sizeof(buffer) / sizeof(char); i++) {
        buffer[i] = NULL;
    }

    //파일 오픈
    err = fopen_s(&fp, filename, "r");

    // 에러 검출
    if (err == 0) {

        //화면 정리
        system("cls");

        //화면에 렌더링
        fread(buffer, 1, sizeof(buffer), fp);
        printf("%s\n", buffer);
        fclose(fp);
    }
    else if (err == ENOENT) {
        printf("[Randering Faild]: No such file or directory");
    }
    else if (err == EIO) {
        printf("[Randering Faild]: I/O Error");
    }
    else if (err == EACCES) {
        printf("[Randering Faild]: Permission denied");
    }
    else {
        printf("[Randering Faild]: Error");
    }

    return 0;
}