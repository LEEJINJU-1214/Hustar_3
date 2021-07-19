//PC ī�޶� ���ؼ� ������ �Է¹޾Ƽ� �¿츦 ����� flip_test.avi �̸��� ������ ���Ϸ� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
	VideoCapture capture(0);
	CV_Assert(capture.isOpened());

	double fps = 15;
	int delay = cvRound(1000.0 / fps);
	Size size(640, 480);
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	cout << fourcc << endl;
	capture.set(CAP_PROP_FRAME_WIDTH, size.width);
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);
	capture.set(CAP_PROP_BRIGHTNESS,64);

	cout << "widtg X height:" << size << endl;
	cout << "VideoWriter:: fourcc: " << fourcc << endl;
	cout << "delay:" << delay << endl;
	cout << "fps" << fps << endl;
	VideoWriter writer;

	writer.open("../flip_test.avi", fourcc, fps, size);
	CV_Assert(writer.isOpened());

	for (;;) {
		Mat frame;
		capture >> frame;
		writer << frame;
		flip(frame, frame, 1);
		imshow("ī�޶� ���󺸱�", frame);
		if (waitKey(delay) >= 0)
			break;
	}
	return 0;

}
	
