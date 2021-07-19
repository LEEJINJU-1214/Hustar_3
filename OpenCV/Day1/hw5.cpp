//1. 4번 문제에서 다음을 추가하여 프로그램을 작성하시오

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image;
String title = "제어프로그램";
String bartitle_line = "선굵기";
String bartitle_radius = "원반지름";
Scalar red(0, 0, 255), blue(255, 0, 0), black(0, 0, 0);
Scalar color;

void onChange(int value, void* userdata)//트랙바 콜백 함수 // 트랙바 위치가 변경될때 마다 호출되는 콜백 함수의 포인터
{

}
void onMouse(int event, int x, int y, int flags, void* ) {
	static Point pt(-1, -1);
	color = black;
	

	if (flags & EVENT_FLAG_CTRLKEY) {
		color = red;
	}
	else if (flags & EVENT_FLAG_SHIFTKEY) {
		color = blue;
	}
	if (event == EVENT_FLAG_LBUTTON) {
		pt = Point(x, y);
		Rect rect(pt, Size(30, 30));
		rectangle(image, rect, color, int(getTrackbarPos(bartitle_line, title)));
		imshow(title, image);
	}

	else if (event == EVENT_FLAG_RBUTTON) {

		pt = Point(x, y);
		int radius = 20;
		circle(image, pt, int(getTrackbarPos(bartitle_radius, title)), color, int(getTrackbarPos(bartitle_line, title)));
		imshow(title, image);
	}

}

int main()
{
	int value_line = 5;
	int value_radius = 25;
	image = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));
	imshow(title, image);
	createTrackbar(bartitle_line, title, &value_line, 10, onChange);
	createTrackbar(bartitle_radius, title, &value_radius, 50, onChange);
	setMouseCallback(title, onMouse,0);
	
	waitKey(0);
	return 0;
}
