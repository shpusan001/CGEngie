#include "CGEngine.h"

void CGEngineStart(int(*dbEvent)());
unsigned _stdcall eventThread(void* arg);

struct DBEventPack {
    int(*dbEvent)(char*);
    char* message;
};

//화면 파일 정의
const char* menuFileName[] = { "MainMenu.txt", "Person.txt", "Familly.txt", "Born.txt", "Marriage.txt", "Dead.txt" };


int main() {
    //CGEngine 시작, mainMenu 이벤트로 첫 시작
    CGEngineStart(mainMenu);
}

//엔진 시작 
void CGEngineStart(int(*dbEvent)()) {
    eventHandler(dbEvent, "");
    while (1) {}
}

//이벤트 핸들러
int eventHandler(int(*dbEvent)(char*), char* message) {
    
    //스레드에 매개변수로 보낼 구조체 정의
    struct DBEventPack* dbEventPack = malloc(sizeof(struct DBEventPack));
    dbEventPack->dbEvent = dbEvent;
    dbEventPack->message = message;

    //스레드 시작
    _beginthreadex(NULL, 0, eventThread, dbEventPack, 0, NULL);
}

//이벤트 스레드
unsigned _stdcall eventThread(void* arg) {

    //DBEventPack 구조체로 형 변환
    struct DBEventPack* dbEventPack = arg;

    int(*dbEvent)(char*) = dbEventPack->dbEvent;
    char* message = dbEventPack->message;

    //이벤트 실행
    dbEvent(message);

    // 구조체 메모리 해제
    free(dbEventPack);
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