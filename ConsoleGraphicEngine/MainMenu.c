#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include "CGEngine.h"

int mainMenu(char* );

//���� ȭ�� ó�� (�̺�Ʈ)
int mainMenu(char* message) {

    //����ȭ�� ������
    render(Main);

    //�˸� �޽��� ǥ��
    if (strcmp(message, "") == 0) {
        printf("�˸� �޽��� : ����\n");
    }
    else {
        printf("�˸� �޽��� : %s\n", message);
    }

    //����� �Է�
    char* userInput[32];
    printf("�Է� >>  ");
    scanf("%s", &userInput);

    //���� �̺�Ʈ ����
    if (strcmp(userInput, "1") == 0) {
        eventHandler(mainMenu, "�ſ� ��ȸ");
    }
    else if (strcmp(userInput, "2") == 0) {
        eventHandler(mainMenu, "� ��ȸ");
    }
    else if (strcmp(userInput, "3") == 0) {
        eventHandler(mainMenu, "��� �Ű�");
    }
    else if (strcmp(userInput, "4") == 0) {
        eventHandler(mainMenu, "ȥ�� �Ű�");
    }
    else if (strcmp(userInput, "5") == 0) {
        eventHandler(mainMenu, "��� �Ű�");
    }
    else {
        eventHandler(mainMenu, "�ùٸ��� �Է��ϼ���");
    }
}