#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
//마스크 원소와 마스크 범위 입력화소 간의 일치 여부 확인
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
void erosion(Mat img, Mat& dst, Mat mask)//침식 연산 함수
{
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(1));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			Point start = Point(j, i) - h_m;
			bool check = check_match(img, start, mask, 0);//원소 일치여부 비교
			dst.at<uchar>(i, j) = (check) ? 255 : 0;//출력 화소저장
		}
	}
}
void dilation(Mat img, Mat& dst, Mat mask)//침식 연산 함수
{
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(0));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			Point start = Point(j, i) - h_m;
			bool check = check_match(img, start, mask, 1);//원소 일치여부 비교
			dst.at<uchar>(i, j) = (check) ? 0 : 255;//출력 화소저장
		}
	}
}
int main() {
	Mat image = imread("./이진주.jpg", 0);
	CV_Assert(image.data);
	resize(image, image,Size(400, 300));
	Mat th_img, dst1, dst2,dst3,dst4;
	threshold(image, th_img, 128, 255, THRESH_BINARY);//128이상의 값보다 클때 적용되는 최대값255, 문턱값 적용 스타일
	//THRESH_BINARY : 128보다 크면 255, 아니면 0으로 이진화 함.

	uchar data[] = { 0,1,0,
					1,1,1,
					0,1,0 };
	Mat mask(3, 3, CV_8UC1, data);
	imshow("image", image);
	imshow("이진영상", th_img);
	erosion(th_img, dst1, mask);//사용자 지정 함수
	dilation(th_img, dst2, mask);
	imshow("침식", dst1);
	imshow("팽창", dst2);

	morphologyEx(th_img, dst3, MORPH_ERODE, mask);
	morphologyEx(dst3, dst4, MORPH_DILATE, mask);
	imshow("침식->팽창", dst4);

	morphologyEx(th_img, dst3, MORPH_DILATE, mask);
	morphologyEx(dst3, dst4, MORPH_ERODE, mask);
	imshow("팽창->침식", dst4);


	waitKey();
	return 0;
}