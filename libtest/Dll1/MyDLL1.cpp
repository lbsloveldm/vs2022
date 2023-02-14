#include "pch.h"

#include<iostream>

#include "MyDLL1.h"



void MyDLL1::dllFun() {
	std::cout << "DLL加载：隐式加载。 （注意，必须将导出类声明为 “__declspec(dllexport)”， 否则没有.lib 文件） " << std::endl;

}