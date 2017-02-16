#include <stdio.h>
#include <iostream>
#include <memory>
#include <cstring>
#include <tuple>

#include "BillParser.h"
#include "CharUtils.h"
#include "ImageProcessor.h"
#include "opencv2/highgui.hpp"
int main(int argc, char **argv)
{
    // read image
	BasicProcessor processor;
	auto img = cv::imread("/home/prat/reciept.png");
	processor.ProcessImage(img);
	return 0;
}
