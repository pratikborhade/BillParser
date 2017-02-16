#include "ImageProcessingUtils.h"
#include <set>
#include <unordered_map>

using namespace cv;
using namespace std;

Mat ImageProcessingUtils::ConnectedRegions( const cv::Mat& mat, const Mat &kernel, cv::Point pt)
{
	if( mat.channels() > 1 )
		throw "ImageProcessingUtils::ConnectedRegions : Does not support more than 1 channels";
	auto type = CV_MAKETYPE(cv::DataType<RegionType>::depth, 1);
	Mat regionMatrix(mat.size(), type );
	regionMatrix.zeros(mat.size(), type);
	
	RegionType connectedRegions = 1;
	auto size = mat.size();
	if( pt == cv::Point(-1, -1) )
	{
		pt.x = std::floor(kernel.size().width/2);
		pt.y = std::floor(kernel.size().height/2);
	}
	
	auto kerSize = kernel.size();
	for ( size_t i=0; i < size_t(size.height); ++i )
	{
		for ( size_t j=0; j < size_t(size.width); ++j )
		{
			auto &imgpix = mat.at<uchar>(i, j);
			if( imgpix < 100 )
				continue;
			auto currentRegion = connectedRegions+1;
			
			for( size_t p=0; p < size_t( kerSize.height ); ++p )
			{
				for( size_t q=0; q<size_t(kerSize.width); ++q )
				{
					if( p==size_t(pt.y) && q==size_t(pt.x) )
						continue;
					long offsetX = long(j+q-pt.x);
					long offsetY = long(i+p-pt.y);
					if( offsetX < 0 || offsetY < 0 || offsetX > size.width || offsetY > size.height)
						continue;
					auto &imgpix = mat.at<uchar>(offsetY, offsetX);
					auto &kerPix = kernel.at<uchar>(p,q);
					if( imgpix < 10 || kerPix == 0 )
						continue;
					auto regPix = regionMatrix.at<RegionType>( offsetY, offsetX);
					if( regPix > 0 && regPix < currentRegion )
					{
						auto oldRegion = currentRegion;
						currentRegion = regPix;
						if(oldRegion < connectedRegions+1)
						{
							OperateOnEachPixel<RegionType, RegionType>(regionMatrix, regionMatrix, [currentRegion, oldRegion]( RegionType pix )-> RegionType
							{
								if(pix == oldRegion)
									return currentRegion;
								return pix;
							}
							);
						}
					}
				}
			}
			regionMatrix.at<RegionType>(i,j) = currentRegion;
			if(currentRegion == connectedRegions+1 )
				++connectedRegions;
			
		}
	}
	return regionMatrix;
}

cv::Mat ImageProcessingUtils::AssignRandomColourToRegion(const cv::Mat &regionMatrix)
{
	auto imgSize = regionMatrix.size();
	cv::Mat segmented( imgSize, Vec3b::type);
	unordered_map<RegionType, Vec3b> dictOfRegions;
	
	for( int i=0; i< imgSize.height; ++i )
	{
		for( int j=0; j < imgSize.width; ++j )
		{
			auto &pix = regionMatrix.at<RegionType>(i,j);
			if( pix > 0 )
			{
				if(dictOfRegions.find(pix) == dictOfRegions.end())
				{
					dictOfRegions[pix] = Vec3b( rand()%255, rand()%255, rand()%255);
				}
				segmented.at<Vec3b>(i,j) = dictOfRegions[pix];
			}
			else
				segmented.at<Vec3b>(i,j) = Vec3b( 0, 0, 0);
		}
	}
	return segmented;
}

std::unordered_set<ImageProcessingUtils::RegionType> ImageProcessingUtils::GetRegionsList( const cv::Mat &regionMatrix)
{
	std::unordered_set<RegionType>  returnSet;
	std::transform( regionMatrix.begin<RegionType>(), regionMatrix.end<RegionType>(), std::inserter(returnSet,returnSet.end()), [&returnSet]( const RegionType &pix)
		{
			return pix;
		});
	return returnSet;
}
