#include "CharUtils.h"
#include <set>
#include <iconv.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <codecvt>

wchar_t curreciesChars[] = {
	L'؋',
	L'Ƀ',
	L'฿',
	L'¢',
	L'₡',
	L'$',
	L'ج',
	L'د',
	L'ع',
	L'ك',//10
	L'ت',
	L'إ',
	L'₫',
	L'€',
	L'ƒ',
	L'₲',
	L'₴',
	L'₭',
	L'č',//20
	L'₥',
	L'₦',
	L'₱',
	L'£',
	L'$',
	L'ع',
	L'ق',
	L'س',
	L'៛',
	L'₹',//30
	L'₪',
	L'৳',
	L'₮',
	L'₩',
	L'¥'
	};
#define NumberOfCurrencies 35

CharUtils::CharUtils()
{
}

CharUtils::~CharUtils()
{
}


bool CharUtils::IsNumeral(wchar_t c)
{
	return isdigit(c);
}

bool CharUtils::IsCharacter(wchar_t c)
{
	return isalpha(c);
}

bool CharUtils::IsSpecialCharacter( wchar_t c)
{
	return !IsNumeral(c) && !IsCharacter(c) && !IsCurrencySymbol(c);
}

bool CharUtils::IsCurrencySymbol(wchar_t c)
{
	static std::set<wchar_t> currecies;
	if(currecies.size() == 0)
	{
		for ( std::size_t i = 0; i<NumberOfCurrencies; ++i )
		{
			currecies.insert(curreciesChars[i]);
		}
	}
	return currecies.find(c) != currecies.end();
}

std::wstring CharUtils::ConvertString( const char *str, size_t len ) 
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}
