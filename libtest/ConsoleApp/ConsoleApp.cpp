// ConsoleApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <windows.h>

#include "mylib.h"
#include "MyDLL1.h"

#include "OSUtils.h"
#include "dllutils.h"
#include "StringUtils.h"

typedef void(__cdecl* MYPROC)();

void dll2Func();

int main()
{
    std::cout << "main() Hello World! begin\n";

    MyLib* p = new MyLib();
    p->testInLib();

    MyDLL1* q = new MyDLL1();
    q->dllFun();


    dll2Func();

    std::cout << "main() Hello World! end\n";
}

void dll2Func() {
    std::wstring strExeDir = OSUtils::getExeDir();
    
    std::wstring myDll2Path = strExeDir + L"\\" + L"dll2.dll";
    std::string myDll2PathA = StringUtils::WString2String(myDll2Path);

    int result = _access(myDll2PathA.c_str(), 0);
    if (result == -1) {
        std::cout << "dll file not exist, 显示调用(Loadlibrary + GetProcAddress)成功失败 " << myDll2PathA << std::endl;
        return ;
    }

    HMODULE hmodule = ::LoadLibraryEx(myDll2Path.c_str(), NULL, 0);
    DWORD erroNumber = GetLastError();

    BOOL loadSuccess = FALSE;

    if (hmodule != NULL)
    {
        MYPROC pFunc = (MYPROC)GetProcAddress(hmodule, "dll2Func");
        erroNumber = GetLastError();

        // If the function address is valid, call the function.

        if (NULL != pFunc)
        {
            loadSuccess = TRUE;
            (pFunc)();
        }
        // Free the DLL module.

        loadSuccess = FreeLibrary(hmodule);
    }
    if (loadSuccess) {
        std::cout << "dll 显示调用(Loadlibrary + GetProcAddress)成功！" << std::endl;
    }else {
        std::cout << "dll 显示调用(Loadlibrary + GetProcAddress)成功失败" << std::endl;
    }

}
