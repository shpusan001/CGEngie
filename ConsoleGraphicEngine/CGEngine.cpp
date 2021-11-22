#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include "CGEngine.h"

int CGEngine::render(const char* filename)
{
    char buffer[20];    // ������ ���� �� ����� �ӽ� ����

    try {
        FILE* fp = fopen(filename, "r");    // hello.txt ������ �б� ���� ����.  

        fgets(buffer, sizeof(buffer), fp);    // hello.txt���� ���ڿ��� ����

        printf("%s\n", buffer);    // Hello, world!: ������ ���� ���

        fclose(fp);    // ���� ������ �ݱ�
    }
    catch (char* error) {
        printf(error);
    }

    return 0;
}