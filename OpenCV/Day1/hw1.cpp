////1. 600행, 400열의 윈도우를 만들고, 영상내의 100, 100 좌표에 200×300 크기의 빨간색 사각형을 그리시오.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Scalar red(0, 0, 255), white(255, 255, 255);
	Mat image(600, 400, CV_8UC3, white);
	Point pt1(100, 100);
	Rect rect(pt1, Size(200, 300));
	rectangle(image, rect, red, FILLED,1);
	imshow("사각형", image);
	waitKey(0);
	return 0;
}
