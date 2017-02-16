#ifndef IMAGEPROCESSINGUTILS_H
#define IMAGEPROCESSINGUTILS_H

#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <functional>
#include <unordered_map>
#include <vector>
#include <unordered_set>

class ImageProcessingUtils
{
public:
	using RegionType = unsigned long;
	ImageProcessingUtils()=default;
	
	template<typename T, typename Q>
	static bool OperateOnEachPixel( const cv::Mat& mat, cv::Mat &dest, std::function< Q(const T&)> func)
	{
		cv::Size size = mat.size();
		if( mat.channels() > 1 )
			throw "This method does not support multiple channels";
		if( mat.size() != dest.size() )
		{
			dest = cv::Mat(size, mat.type());
		}
		for( auto i=0; i<size.height; ++i )
			for ( auto j=0; j<size.width; ++j )
			{
				dest.at<Q>(i,j) = func( mat.at<T>(i,j) );
			}
		return true;
	}
	
	template<typename T>
	static cv::Mat SegmentRegion( const cv::Mat &regionMatrix, T regionId  )
	{
		cv::Mat segmented( regionMatrix.size(), CV_8UC1 );
		OperateOnEachPixel<T, uchar>( regionMatrix, segmented, [regionId]( const T &pix) -> uchar
			{
				return pix == regionId ? 255 : 0;
			}
		);
		return segmented;
	}

	
	//give a unique value to each pixel belonging to same region
	//currently supports 1 black and white images
	static cv::Mat ConnectedRegions( const cv::Mat& mat, const cv::Mat &kernel, cv::Point pt = cv::Point(-1, -1) );
	
	static cv::Mat AssignRandomColourToRegion(const cv::Mat &regionMatrix);
	
	static std::unordered_set<RegionType> GetRegionsList( const cv::Mat &regionMatrix);
	
	~ImageProcessingUtils()=default;

};

#endif // IMAGEPROCESSINGUTILS_H
