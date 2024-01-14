#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>


int main()
{
	//const wchar_t* registryKeyPath = L"Excel.CSV\\shell\\test";
	const wchar_t* appName = L"C:\\APP\\Notepad++\\notepad++.exe";
	const wchar_t* iconPath = L"C:\\APP\\Notepad++\\updater\\updater.ico";

	HKEY hKey;
	if (RegCreateKey(HKEY_CLASSES_ROOT, L"Excel.CSV\\shell\\test", &hKey) == ERROR_SUCCESS) {
		RegSetValueEx(hKey, L"icon", 0, REG_SZ, (const BYTE*)iconPath, wcslen(iconPath) * 2);
		RegCloseKey(hKey);

		if (RegCreateKey(HKEY_CLASSES_ROOT, L"Excel.CSV\\shell\\test\\command", &hKey) == ERROR_SUCCESS) {
			wchar_t command[255];
			swprintf_s(command, L"%s \"%%1\"", appName);
			RegSetValueEx(hKey, NULL, 0, REG_SZ, (const BYTE*)command, wcslen(command) * 2);
			RegCloseKey(hKey);
		}
		std::cout << "OK" << std::endl;
	}
	else {
		std::cout << "FAIL" << std::endl;
	}

	return 0;
}
