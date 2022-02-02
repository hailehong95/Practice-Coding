#include <Windows.h>
#pragma comment (lib, "User32.Lib")
#pragma comment (linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	MessageBox(NULL, L"Hello, World!", L"Hi!", MB_OK | MB_ICONINFORMATION);
	return 0;
}