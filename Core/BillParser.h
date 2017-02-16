#ifndef BILLPARSER_H
#define BILLPARSER_H

#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include <vector>

struct Price
{
	std::wstring product;
	double total;
	double numberOfItems;
	double pricePerItem;
};

enum amountType
{
	pricePerCurrency,
	priceTotal,
	numberOfItems
};

struct lineType
{
	std::size_t hasNumeric;
	bool hasCurrency;
	std::string format;
	std::vector<std::string> types;
	lineType()
	{
		hasNumeric = 0;
		hasCurrency = 0;
		format = "";
	}
	bool operator==( const lineType &other ) const
	{
		return hasCurrency == other.hasCurrency && hasNumeric == other.hasNumeric && format == other.format;
	}
	
	double Equivalence( const lineType &other ) const;
};

enum ContentType
{
	header,
	lines,
	total,
	footer
};


#endif // BILLPARSER_H
