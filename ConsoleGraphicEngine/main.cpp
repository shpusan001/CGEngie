#include <stdio.h>
#include <Windows.h>
#include "CGEngine.h"

int main() {
	CGEngine *cgEngine =  new CGEngine();
	cgEngine->render("hi.txt");
	getchar();
}