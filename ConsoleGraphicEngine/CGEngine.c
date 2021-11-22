#include "CGEngine.h"

void CGEngineStart(int(*dbEvent)());
unsigned _stdcall eventThread(void* arg);

struct DBEventPack {
    int(*dbEvent)(char*);
    char* message;
};

//ȭ�� ���� ����
const char* menuFileName[] = { "MainMenu.txt", "Person.txt", "Familly.txt", "Born.txt", "Marriage.txt", "Dead.txt" };


int main() {
    //CGEngine ����, mainMenu �̺�Ʈ�� ù ����
    CGEngineStart(mainMenu);
}

//���� ���� 
void CGEngineStart(int(*dbEvent)()) {
    eventHandler(dbEvent, "");
    while (1) {}
}

//�̺�Ʈ �ڵ鷯
int eventHandler(int(*dbEvent)(char*), char* message) {
    
    //�����忡 �Ű������� ���� ����ü ����
    struct DBEventPack* dbEventPack = malloc(sizeof(struct DBEventPack));
    dbEventPack->dbEvent = dbEvent;
    dbEventPack->message = message;

    //������ ����
    _beginthreadex(NULL, 0, eventThread, dbEventPack, 0, NULL);
}

//�̺�Ʈ ������
unsigned _stdcall eventThread(void* arg) {

    //DBEventPack ����ü�� �� ��ȯ
    struct DBEventPack* dbEventPack = arg;

    int(*dbEvent)(char*) = dbEventPack->dbEvent;
    char* message = dbEventPack->message;

    //�̺�Ʈ ����
    dbEvent(message);

    // ����ü �޸� ����
    free(dbEventPack);
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