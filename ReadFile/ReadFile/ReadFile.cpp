#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#define BSIZE 64

int wmain(int argc, WCHAR* argv[]) {
	HANDLE fileHandle;
	DWORD dwBytesToRead = BSIZE;
	wchar_t ReadBuffer[BSIZE] = { 0 };

	fileHandle = CreateFileW(argv[1], GENERIC_READ, 0, NULL, 3, FILE_ATTRIBUTE_NORMAL, NULL);

	BOOL bRead = ReadFile(fileHandle, ReadBuffer, BSIZE, 0, NULL);
	ReadBuffer[0] = (wchar_t)" ";

	if (bRead) {
		wprintf(L"%s", ReadBuffer);
	} else {
		printf("something boo boo'd");
	}

	CloseHandle(fileHandle);

	return 0;
}