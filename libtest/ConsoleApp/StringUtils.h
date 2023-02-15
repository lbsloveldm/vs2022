#pragma once

#include<iostream>
#include<string>

class StringUtils {
public:

	//将单字节char*转化为宽字节wchar_t*  
	static wchar_t* AnsiToUnicode(const char* szStr);

	//将宽字节wchar_t*转化为单字节char*  
	static char* UnicodeToAnsi(const wchar_t* szStr);

	static std::string WString2String(const std::wstring& ws);

	// string => wstring
	static std::wstring String2WString(const std::string& s);
};
