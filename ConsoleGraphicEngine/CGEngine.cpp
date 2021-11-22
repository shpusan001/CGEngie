#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include "CGEngine.h"

int CGEngine::render(const char* filename)
{
    char buffer[20];    // 파일을 읽을 때 사용할 임시 공간

    try {
        FILE* fp = fopen(filename, "r");    // hello.txt 파일을 읽기 모드로 열기.  

        fgets(buffer, sizeof(buffer), fp);    // hello.txt에서 문자열을 읽음

        printf("%s\n", buffer);    // Hello, world!: 파일의 내용 출력

        fclose(fp);    // 파일 포인터 닫기
    }
    catch (char* error) {
        printf(error);
    }

    return 0;
}