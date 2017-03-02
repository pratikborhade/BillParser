#include "ImageProcessor.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include "ImageProcessingUtils.h"
#include "ImageLogger.h"

using namespace std;
using namespace cv;
/*
void ShowRegions()
{
 * set<unsigned long> regionsIds;
	for ( auto i = regions.begin<unsigned long>(); i!=regions.end<unsigned long>(); ++i)
		regionsIds.insert(*i);
		
	for( auto i = regionsIds.begin(); i != regionsIds.end(); ++i )
	{
		if( *i == 0 )
			continue;
		auto img = ImageProcessingUtils::SegmentRegion<unsigned long>(regions, *i);
		ImageLogger::GetInstance().Log("Segmented", img );
	}
}
*/
BasicProcessor::Regions BasicProcessor::ProcessImage( cv::Mat &image ) const
{
	Mat grey;
	
	cvtColor(image, grey, CV_BGR2GRAY);
	cv::threshold(grey, grey, 127, 255, cv::THRESH_BINARY);
	ImageLogger::GetInstance().Log( grey );
	
	
	Mat dialateKernel = getStructuringElement( cv::MorphShapes::MORPH_RECT, cv::Size(2,2), cv::Point(-1,-1));
	Mat tempDialate = ImageProcessingUtils::ApplyKernel<uchar>(grey, dialateKernel, []( const Mat &temp )
		{
			auto size = temp.size();
			if( temp.at<uchar>(size.height/2,size.width/2) == 0 )
				return 0;
			auto sum = temp.sum();
			sum = sum/255;
			if(sum > 4)
				return 255;
		} );
	/*cv::dilate(grey, tempDialate, dialateKernel);
	grey = tempDialate;
	ImageLogger::GetInstance().Log( grey );
	ImageLogger::GetInstance().CreateNewWindow();
	*/
	
	//have higher piority for vertical axis
	Mat tempErode;
	cv::erode( grey, tempErode, dialateKernel, cv::Point(-1,-1), 2 );
	grey= tempErode;
	ImageLogger::GetInstance().Log( grey );
	
	//invert
	Mat inverted;
	ImageProcessingUtils::OperateOnEachPixel<uchar, uchar>( grey, inverted, 
		[](const uchar &c) -> uchar
		{ 
			return 255-c; 
		} );
	ImageLogger::GetInstance().Log("Inverted", inverted );
	auto erodeKernel = CreateErodeKernel(cv::Size( 3, 3 ), horizontal);
	Mat invDial;
	cv::dilate(inverted, invDial, erodeKernel, cv::Point(-1,-1), 10);
	inverted = invDial;
	//regions
	/*
	auto regions = ImageProcessingUtils::ConnectedRegions(inverted, getStructuringElement( cv::MorphShapes::MORPH_RECT, cv::Size(3,3), cv::Point(-1,-1)), cv::Point(-1,-1));
	auto regionsImg = ImageProcessingUtils::AssignRandomColourToRegion(regions);
	ImageLogger::GetInstance().Log("Contected Regions", regionsImg );*/
	size_t sizeOfKernel = 3;
	
	while( true )
	{
		auto original = inverted.clone();
		auto kernelD = getStructuringElement( cv::MorphShapes::MORPH_ELLIPSE, cv::Size(sizeOfKernel,sizeOfKernel), cv::Point(-1,-1));
		auto kernelE = getStructuringElement( cv::MorphShapes::MORPH_ELLIPSE, cv::Size(sizeOfKernel-1,sizeOfKernel-1), cv::Point(-1,-1));
		Mat temp;
		cv::dilate(inverted, temp, kernelD);
		cv::erode(temp, inverted, kernelE);
		
		ImageLogger::GetInstance().Log("Operating", inverted );
		auto regions = ImageProcessingUtils::ConnectedRegions(inverted, getStructuringElement( cv::MorphShapes::MORPH_RECT, cv::Size(3,3), cv::Point(-1,-1)), cv::Point(-1,-1));
		auto regionsIds = ImageProcessingUtils::GetRegionsList(regions);
		
		auto regionsImg = ImageProcessingUtils::AssignRandomColourToRegion(regions);
		ImageLogger::GetInstance().Log("Contected Regions", regionsImg );
		
		if( regionsIds.size() > minNumberOfRegions &&  regionsIds.size() < maxNumberOfRegions)
			break;
		else if(regionsIds.size() < minNumberOfRegions )
		{
			inverted = original.clone();
			if( sizeOfKernel < 3 )
				throw "kenel size too small";
			sizeOfKernel = sizeOfKernel - 2;
		}
		else
			++sizeOfKernel;
	}
	
	throw "Not Implemented Exception";
}

/* this method tries to group all series
 * 
 * */
std::vector<size_t> BasicProcessor::FindRegions( const std::vector<size_t>& projection, size_t minRegions, size_t maxRegions ) const
{
	throw "Not Implemented";
}

Mat BasicProcessor::CreateErodeKernel( cv::Size size, ProcessDirection dir ) const
{
	Mat kernel = getStructuringElement( cv::MorphShapes::MORPH_RECT, size, cv::Point(size.width/2,size.height/2));
	for( size_t i = 0; i < size_t(size.width); ++i )
		for( size_t j=0; j< size_t(size.height); ++j )
		{
			if( dir == vertical && i == floor(size.width/2) )
				continue;
			else if( dir == horizontal && j == floor(size.height/2) )
				continue;
			kernel.at<uchar>( j, i ) = 0; 
		}
	return kernel;
}

std::vector<size_t> BasicProcessor::Projection( const cv::Mat& image, ProcessDirection direction) const
{
	cv::Mat transposeMat; 
	cv::transpose( image, transposeMat );
	
	const cv::Mat &use = direction == vertical ? image: transposeMat;
	auto size = use.size();
	std::vector<size_t> projection( size.height );
	for( size_t i=0; i<size_t(size.height); ++i )
	{
		size_t sum = 0;
		for( size_t j=0;j<size_t(size.width); ++j )
		{
			sum += use.at<uchar>(i, j, 0);
		}
		projection[i] = (sum/255);
	}
	return projection;
}