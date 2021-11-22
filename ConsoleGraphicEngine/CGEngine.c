#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <cerrno>
#include <string.h>
#include <Windows.h>

#include "CGEngine.h"

void CGEngineStart(int(*dbEvent)());



//ȭ�� ���� ����
const char* menuFileName[] = { "MainMenu.txt", "Person.txt", "Familly.txt", "Born.txt", "Marriage.txt", "Dead.txt" };


int main() {
    //CGEngine ����, mainMenu �̺�Ʈ�� ù ����
    CGEngineStart(mainMenu);
}

//���� ���� 
void CGEngineStart(int(*dbEvent)()) {
    eventHandler(dbEvent, "");
}

//�̺�Ʈ �ڵ鷯
int eventHandler(int(*dbEvent)(char*), char* message) {
    dbEvent(message);
}

//Ŀ�� �̵�
void setCusor(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//ȭ�� ������ 
int  render(int file)
{
    char buffer[256];    // ���� ����

    FILE* fp;
    errno_t err;

    char* filename = menuFileName[file];

    // ���� ������ �� ����
    for (int i = 0; i < sizeof(buffer) / sizeof(char); i++) {
        buffer[i] = NULL;
    }

    //���� ����
    err = fopen_s(&fp, filename, "r");

    // ���� ����
    if (err == 0) {

        //ȭ�� ����
        system("cls");

        //ȭ�鿡 ������
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