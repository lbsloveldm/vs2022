#pragma once

#include<iostream>
#include<string>

class StringUtils {
public:

	//�����ֽ�char*ת��Ϊ���ֽ�wchar_t*  
	static wchar_t* AnsiToUnicode(const char* szStr);

	//�����ֽ�wchar_t*ת��Ϊ���ֽ�char*  
	static char* UnicodeToAnsi(const wchar_t* szStr);

	static std::string WString2String(const std::wstring& ws);

	// string => wstring
	static std::wstring String2WString(const std::string& s);
};
