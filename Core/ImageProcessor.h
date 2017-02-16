#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <string>
#include <vector>
#include <set>

enum ProcessDirection
{
	horizontal,
	vertical
};

class ImageProcessorInterface
{
public:
	size_t minNumberOfRegions = 2;
	size_t maxNumberOfRegions = 7;
	
	using Rect = cv::Rect;
	using Regions = std::vector<Rect>;
	///Gets the segmented image from different parts of bill
	virtual Regions  ProcessImage( cv::Mat &image ) const = 0;
	
	virtual ~ImageProcessorInterface() = default;
	
};

class BasicProcessor : public ImageProcessorInterface
{
protected:
	using Point = std::pair<std::size_t, std::size_t>;
public:
	BasicProcessor() = default;
	
	cv::Mat CreateErodeKernel( cv::Size size, ProcessDirection dir ) const;
	
	Regions ProcessImage( cv::Mat & image ) const;
	
	std::vector<size_t> Projection( const cv::Mat& image, ProcessDirection direction = vertical) const;
	
	std::vector<size_t> FindRegions( const std::vector<size_t>& projection, size_t minRegions, size_t maxRegions ) const;
	
	virtual ~BasicProcessor() = default;
};
#endif // IMAGEPROCESSOR_H
