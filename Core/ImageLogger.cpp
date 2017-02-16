#include "ImageLogger.h"
#include "opencv2/highgui.hpp"
#include <sstream>

unsigned int variable = 0;

ImageLogger& ImageLogger::GetInstance()
{
	static ImageLogger instance;
	return instance;
}

void ImageLogger::Log(cv::Mat &img)
{
	std::stringstream ss;
	ss<<variable;
	cv::imshow( cv::String(ss.str()) , img);
	cv::waitKey(0);
}

void ImageLogger::Log( std::string name, cv::Mat& image )
{
	cv::imshow( name , image);
	cv::waitKey(0);
}

void ImageLogger::CreateNewWindow()
{
	variable++;
}

ImageLogger::~ImageLogger()
{
}

