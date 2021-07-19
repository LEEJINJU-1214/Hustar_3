//������ �̺�Ʈ ���� ���α׷��� �ۼ��Ͻÿ�
// 1)���콺 ������ ��ư Ŭ���� ��(Ŭ����ǥ���� ������ 20�ȼ�)�� �׸���.
// 2)���콺 ���� ��ư Ŭ���� �簢��(ũ�� 30x30)�� �׸���.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image;
String title = "�������α׷�";

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
