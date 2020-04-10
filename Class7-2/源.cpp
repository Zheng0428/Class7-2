#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = cv::imread("D:\\a\\3.png", 0);
	cv::Mat canny;
	/*threshold(srcMat, canny, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);*/
	Canny(srcMat, canny, 100,120);
	std::vector <cv::Vec2f> lines;
	cv::HoughLines(canny, lines, 1, CV_PI / 180, 100);
	imshow("src1", canny);
	std::vector<cv::Vec2f>::iterator it = lines.begin();
	for (; it != lines.end(); ++it)
	{
		float rho = (*it)[0], theta = (*it)[1];
		cv::Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;
		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
		cv::line(srcMat, pt1, pt2, cv::Scalar(0, 0, 255), 1);
		
	}
	imshow("src", srcMat);
	cv::waitKey(0);

}