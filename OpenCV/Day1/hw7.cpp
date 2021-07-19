#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
//���ڿ� ��� �Լ� - �׸��� ȿ��
//1.  Ʈ���ٸ� �߰��ؼ� ī�޶� ������ ���� ��� ������ �� �ֵ��� �����Ͻÿ�.
void put_string(Mat& frame, string text, Point pt, int value) {
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);//�׸���ȿ��
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);//�ۼ�����

}
VideoCapture capture;//���� ���� ����- ���� �Լ����� ���

void zoom_bar(int value, void*) {//Ʈ���� �ݹ��Լ�
	capture.set(CAP_PROP_ZOOM, value);//�� ����
}
void focus_bar(int value, void*) {
	capture.set(CAP_PROP_FOCUS, value);//���� ����
}
void brightness_bar(int value, void*) {

	capture.set(CAP_PROP_BRIGHTNESS, value - 126);//���� ����

}
void contrast_bar(int value, void*) {

	capture.set(CAP_PROP_CONTRAST, value -126);//���� ����

}

int main()
{
	int zoom = capture.get(CAP_PROP_ZOOM);
	int focus = capture.get(CAP_PROP_FOCUS);
	int brightness = capture.get(CAP_PROP_BRIGHTNESS);
	int contrast = capture.get(CAP_PROP_CONTRAST);
	capture.open(0);//0�� ī�޶� ����
	CV_Assert(capture.isOpened());//ī�޶� ���� ���� ó��
	capture.set(CAP_PROP_FRAME_WIDTH, 400); //ī�޶� ������ �ʺ�
	capture.set(CAP_PROP_FRAME_HEIGHT, 300);
	capture.set(CAP_PROP_AUTOFOCUS, 0);//������Ŀ�� ����
	capture.set(CAP_PROP_BRIGHTNESS, brightness);// ������ ��� �ʱ�ȭ
	capture.set(CAP_PROP_CONTRAST, contrast);// ������ ���� �ʱ�ȭ

	

	string title = "ī�޶� �Ӽ�����";
	namedWindow(title);
	createTrackbar("zoom", title, &zoom, 10, zoom_bar);
	createTrackbar("focus", title, &focus, 40, focus_bar);
	createTrackbar("brightness", title, &brightness, 255, brightness_bar);
	createTrackbar("contrast", title, &contrast, 255, contrast_bar);
	for (;;) {
		Mat frame;
		capture >> frame;
		put_string(frame, "zoom:", Point(10, 230), zoom);
		put_string(frame, "focus:", Point(10, 270), focus);
		put_string(frame, "brightness:", Point(10, 300), brightness);
		put_string(frame, "contrast:", Point(10, 330), contrast);

		imshow(title, frame);
		if (waitKey(30) >= 0) break;

	}
	return 0;
}
