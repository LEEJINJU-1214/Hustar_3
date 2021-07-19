#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
//문자열 출력 함수 - 그림자 효과
//1.  트렉바를 추가해서 카메라 영상의 밝기와 대비 변경할 수 있도록 수정하시오.
void put_string(Mat& frame, string text, Point pt, int value) {
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);//그림자효과
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);//작성문자

}
VideoCapture capture;//전역 변수 선언- 여러 함수에서 사용

void zoom_bar(int value, void*) {//트렉바 콜백함수
	capture.set(CAP_PROP_ZOOM, value);//줌 설정
}
void focus_bar(int value, void*) {
	capture.set(CAP_PROP_FOCUS, value);//초점 설정
}
void brightness_bar(int value, void*) {

	capture.set(CAP_PROP_BRIGHTNESS, value - 126);//초점 설정

}
void contrast_bar(int value, void*) {

	capture.set(CAP_PROP_CONTRAST, value -126);//초점 설정

}

int main()
{
	int zoom = capture.get(CAP_PROP_ZOOM);
	int focus = capture.get(CAP_PROP_FOCUS);
	int brightness = capture.get(CAP_PROP_BRIGHTNESS);
	int contrast = capture.get(CAP_PROP_CONTRAST);
	capture.open(0);//0번 카메라 연결
	CV_Assert(capture.isOpened());//카메라 연결 예외 처리
	capture.set(CAP_PROP_FRAME_WIDTH, 400); //카메라 프레임 너비
	capture.set(CAP_PROP_FRAME_HEIGHT, 300);
	capture.set(CAP_PROP_AUTOFOCUS, 0);//오토포커싱 중지
	capture.set(CAP_PROP_BRIGHTNESS, brightness);// 프레임 밝기 초기화
	capture.set(CAP_PROP_CONTRAST, contrast);// 프레임 대조 초기화

	

	string title = "카메라 속성변경";
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
