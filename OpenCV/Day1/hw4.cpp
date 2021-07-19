////3���� �߰��Ͽ� �ۼ�
// 1) [Ctrl]  + ���콺 �̺�Ʈ ��  ���������� �׸���. 
// 2)[Shift] + ���콺 �̺�Ʈ ��  �Ķ������� �׸���.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image;
String title = "�������α׷�";
Scalar red(0, 0, 255), blue(255, 0, 0);
Scalar black(0, 0, 0);
Scalar color;

void onMouse(int event, int x, int y, int flags, void *) {
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
		rectangle(image, rect, color, 1);
		imshow(title, image);

	}
		
	else if (event == EVENT_FLAG_RBUTTON) {
		
		pt = Point(x, y);
		int radius = 20;
		circle(image, pt, radius, color, 1);

		imshow(title, image);

		
	}
		
}
int main()
{
	image = Mat(300, 500, CV_8UC3, Scalar(255,255,255));
	imshow(title, image);
	setMouseCallback(title, onMouse, 0);
	waitKey(0);
	return 0;
}
