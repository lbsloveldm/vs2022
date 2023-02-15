#include "OSUtils.h"

#include <windows.h>

std::wstring OSUtils::getCurrentDir() {

    WCHAR szCurrentDir[MAX_PATH] = { 0 };
    GetCurrentDirectoryW(sizeof(szCurrentDir) / sizeof(szCurrentDir[0]) - 1, szCurrentDir);

	return szCurrentDir;
}

std::wstring OSUtils::getExeDir() {
    WCHAR szModuleDir[MAX_PATH] = { 0 };
    GetModuleFileNameW(NULL, szModuleDir, sizeof(szModuleDir) / sizeof(szModuleDir[0]) - 1);
    std::wstring strExeDir = szModuleDir;

    int index = strExeDir.find_last_of(L'\\', strExeDir.length());
    if (index <= 0) {
        index = strExeDir.find_last_of(L'/', strExeDir.length());
    }
    if (index > 0) {
        strExeDir = strExeDir.substr(0, index);
    }

    return strExeDir;
}