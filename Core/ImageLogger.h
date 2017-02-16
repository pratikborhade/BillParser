#ifndef IMAGELOGGER_H
#define IMAGELOGGER_H
#include "LoggingInterface.h"
#include "opencv2/core/mat.hpp"
class ImageLogger
{
	
	ImageLogger() = default;
public:
	static ImageLogger& GetInstance();
	ImageLogger(const ImageLogger&) = delete;
	cv::Mat *image = nullptr;
	
	void Log( cv::Mat &image );
	
	void Log( std::string name, cv::Mat& image );
	
	void CreateNewWindow();
	
	ImageLogger &operator=(const ImageLogger&) = delete;
	~ImageLogger();

};

#endif // IMAGELOGGER_H
