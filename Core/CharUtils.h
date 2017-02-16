#ifndef CHARUTILS_H
#define CHARUTILS_H
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <tuple>
class CharUtils
{
public:
	CharUtils();
	static bool IsNumeral(wchar_t c);
	static bool IsCharacter(wchar_t c);
	static bool IsSpecialCharacter( wchar_t c);
	static bool IsCurrencySymbol(wchar_t c);
	static std::wstring ConvertString( const char *str, size_t len );
	~CharUtils();

};

#endif // CHARUTILS_H
