#include "tesseractapi.h"
#include <iconv.h>

#define TESSDATA "/home/prat/Softwares/tesseract/tessdata"
Tesseractapi::Tesseractapi()
{
	language = "eng";
	initialized = false;
}

bool Tesseractapi::Init()
{
	// setup
    api.SetPageSegMode(tesseract::PageSegMode::PSM_AUTO);
    api.SetVariable("save_best_choices", "T");
	initialized = api.Init((const char *)TESSDATA, language.c_str());
	return initialized;
}

tesseract::TessBaseAPI &Tesseractapi::GetApi()
{
	return api;
}

void Tesseractapi::SetLanguage( std::string lang )
{
	language = lang;
}

std::wstring Tesseractapi::Recognise( Pix *image )
{
	api.SetImage(image);
	api.Recognize(nullptr);
	
	char *chr = api.GetUTF8Text();
	std::size_t len = strlen(chr);
	wchar_t *wchar = (wchar_t *) malloc( len * sizeof(wchar_t) );
	auto icon = iconv_open( "UTF-8", "WCHAR_T");
	if ((iconv_t) -1 == icon) {
        throw "Cannot convert from utf8 to wide string";
    }
	
	++len;
	std::size_t outLen= sizeof(wchar_t);
    iconv(icon, &chr, &len,(char **) (&wchar), &outLen);
	
	std::wstring returnString(wchar);
	api.Clear();
	
	delete [] chr;
	delete [] wchar;
	return returnString;
}

Tesseractapi::~Tesseractapi()
{
}

