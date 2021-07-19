//다음의 컬러 영상 파일(logo.jpg)을 입력 받아서 RGB의 3개 채널을 분리하고, 각
//채널을 컬러 영상을 윈도우에 표시해 보자.즉, Red 채널은 빨간색으로, Green
//채널은 파란색으로, Blue 채널은 파란색으로 표현되도록 다음의 프로그램을 완성
//하시오.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



int main() {

	Mat image = imread("C:/Users/leeji/source/repos/opencv0421/opencv0421/logo.png", IMREAD_COLOR);
	CV_Assert(image.data);
	Mat bgr[3];

	Mat red, green, blue, image_not, image_th_g;
	split(image, bgr);
	
	bitwise_or(bgr[0], bgr[1], red);
	bitwise_or(bgr[0], bgr[2], green);
	bitwise_or(bgr[1], bgr[2], blue);

	bitwise_not(red, red);
	bitwise_not(green, green);
	bitwise_not(blue, blue);

	Mat zeros = cv::Mat::zeros(image.size(), CV_8UC1);
	Mat R[] = { zeros, zeros, red };
	Mat G[] = { zeros, green, zeros };
	Mat B[] = { blue, zeros, zeros };
	merge(R, 3, red);
	merge(G, 3, green);
	merge(B, 3, blue);
	imshow("image", image);
	imshow("red", red);
	imshow("green", green);
	imshow("blue", blue);
	

	waitKey(0);
	return 0;

}