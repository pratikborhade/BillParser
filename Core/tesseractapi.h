#ifndef Tesseractapi_H
#define Tesseractapi_H
#include <tesseract/baseapi.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <leptonica/allheaders.h>
#include <string>

class Tesseractapi
{
	tesseract::TessBaseAPI api;
	std::string language; 
	bool initialized;
public:
	tesseract::TessBaseAPI &GetApi();
	bool Init();
	void SetLanguage( std::string language );
	
	std::wstring Recognise( Pix *image );
	Tesseractapi();
	~Tesseractapi();

};

#endif // Tesseractapi_H
