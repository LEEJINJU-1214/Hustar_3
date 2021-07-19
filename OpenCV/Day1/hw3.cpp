//다음의 이벤트 제어 프로그램을 작성하시오
// 1)마우스 오른쪽 버튼 클릭시 원(클릭좌표에서 반지름 20픽셀)을 그린다.
// 2)마우스 왼쪽 버튼 클릭시 사각형(크기 30x30)을 그린다.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image;
String title = "제어프로그램";

void onMouse(int event, int x, int y, int flag, void *) {
	static Point pt(-1, -1);
	if (event == EVENT_FLAG_LBUTTON) {
		pt = Point(x, y);
		Rect rect(pt, Size(30, 30));
		rectangle(image, rect, 1);
		imshow(title, image);
		
	}
	else if (event == EVENT_FLAG_RBUTTON) {
		pt = Point(x, y);
		int radius = 20;
		circle(image, pt, radius, Scalar(150), 2);
		imshow(title, image);
		}

	
}
int main()
{
	image = Mat(300, 500, CV_8UC1, Scalar(255));
	imshow(title, image);
	setMouseCallback(title, onMouse, 0);
	waitKey(0);
	return 0;
}
