//������ �÷� ���� ����(logo.jpg)�� �Է� �޾Ƽ� RGB�� 3�� ä���� �и��ϰ�, ��
//ä���� �÷� ������ �����쿡 ǥ���� ����.��, Red ä���� ����������, Green
//ä���� �Ķ�������, Blue ä���� �Ķ������� ǥ���ǵ��� ������ ���α׷��� �ϼ�
//�Ͻÿ�.
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