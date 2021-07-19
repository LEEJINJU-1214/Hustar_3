#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
//����ũ ���ҿ� ����ũ ���� �Է�ȭ�� ���� ��ġ ���� Ȯ��
bool check_match(Mat img, Point start, Mat mask, int mode = 0) {
	for (int u = 0; u < mask.rows; u++) {
		for (int v = 0; v < mask.cols; v++) {
			Point pt(v, u);
			int m = mask.at<uchar>(pt);
			int p = img.at<uchar>(start + pt);

			bool ch = (p == 255);
			if (m == 1 && ch == mode) {
				return false;
			}
		}

	}
	return true;
}
void erosion(Mat img, Mat& dst, Mat mask)//ħ�� ���� �Լ�
{
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(1));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			Point start = Point(j, i) - h_m;
			bool check = check_match(img, start, mask, 0);//���� ��ġ���� ��
			dst.at<uchar>(i, j) = (check) ? 255 : 0;//��� ȭ������
		}
	}
}
void dilation(Mat img, Mat& dst, Mat mask)//ħ�� ���� �Լ�
{
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(0));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			Point start = Point(j, i) - h_m;
			bool check = check_match(img, start, mask, 1);//���� ��ġ���� ��
			dst.at<uchar>(i, j) = (check) ? 0 : 255;//��� ȭ������
		}
	}
}
int main() {
	Mat image = imread("./������.jpg", 0);
	CV_Assert(image.data);
	resize(image, image,Size(400, 300));
	Mat th_img, dst1, dst2,dst3,dst4;
	threshold(image, th_img, 128, 255, THRESH_BINARY);//128�̻��� ������ Ŭ�� ����Ǵ� �ִ밪255, ���ΰ� ���� ��Ÿ��
	//THRESH_BINARY : 128���� ũ�� 255, �ƴϸ� 0���� ����ȭ ��.

	uchar data[] = { 0,1,0,
					1,1,1,
					0,1,0 };
	Mat mask(3, 3, CV_8UC1, data);
	imshow("image", image);
	imshow("��������", th_img);
	erosion(th_img, dst1, mask);//����� ���� �Լ�
	dilation(th_img, dst2, mask);
	imshow("ħ��", dst1);
	imshow("��â", dst2);

	morphologyEx(th_img, dst3, MORPH_ERODE, mask);
	morphologyEx(dst3, dst4, MORPH_DILATE, mask);
	imshow("ħ��->��â", dst4);

	morphologyEx(th_img, dst3, MORPH_DILATE, mask);
	morphologyEx(dst3, dst4, MORPH_ERODE, mask);
	imshow("��â->ħ��", dst4);


	waitKey();
	return 0;
}