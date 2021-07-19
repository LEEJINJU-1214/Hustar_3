//1. 가로 600, 세로 400크기 영상에 200×200크기의 태극 문양을 그리시오.(힌트 : 타원그리기 함수 이용)
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Scalar red(0, 0, 255), white(255, 255, 255), blue(255,0,0);
	Mat image(600, 400, CV_8UC3, white);
	Point pt1(200, 300);

	ellipse(image, pt1, Size(100, 100), 0, 180, 360, red,FILLED, 1);
	ellipse(image, pt1, Size(100, 100), 0, 0,180, blue, FILLED, 1);
	ellipse(image, Point(250,300), Size(50, 50), 0, 0, 180, red, FILLED, 1);
	ellipse(image, Point(150, 300), Size(50, 50), 0, 180, 360, blue, FILLED, 1);
	imshow("태극기 그리기", image);
	waitKey(0);
	return 0;


}
