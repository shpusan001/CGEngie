#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <cerrno>
#include <string.h>
#include <Windows.h>

// ȭ�� �̸� ������ 
enum Menu {
    Main,
    Person,
    Familly,
    Born,
    Marriage,
    Dead,
};

//�Լ� ����
int mainMenu(char*);

