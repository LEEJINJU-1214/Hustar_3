//1. 예제_8.5.1의 rotation() 함수를 이용해서 영상 파일을 입력 받아서 300,100 좌표를 기준으로 30도 회전하도록 프로그램을 작성하시오. 
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
uchar bilinear_value(Mat img, double x, double y) {
	if (x >= img.cols - 1) x--;
	if (y >= img.rows - 1) y--;

	//4개 화소 가져옴

	Point pt((int)x, (int)y);
	int A = img.at<uchar>(pt);
	int B = img.at<uchar>(pt+Point(0,1));
	int C= img.at<uchar>(pt + Point(1, 0));
	int D = img.at<uchar>(pt + Point(1, 1));

	double alpha = y - pt.y;
	double beta = x - pt.x;
	int M1 = A + (int)cvRound(alpha * (B - A));
	int M2 = C + (int)cvRound(alpha * (D - C));
	int P = M1 + (int)cvRound(beta * (M2 - M1));

	return saturate_cast<uchar>(P);
}
void rotation(Mat img, Mat&dst, double dgree,Point pt) {
	double radian = dgree / 180 * CV_PI;
	double sin_value = sin(radian);
	double cos_value =cos(radian);

	Rect rect(Point(0, 0), img.size());
	dst = Mat(img.size(), img.type(), Scalar(0));

	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			int jj = j - pt.x;
			int ii = i - pt.y;
			double x = jj * cos_value + ii * sin_value + pt.x;
			double y = -jj * sin_value + ii * cos_value + pt.y;
			if (rect.contains(Point2d(x, y)))
				dst.at<uchar>(i, j) = bilinear_value(img, x, y);

		}
	}


}
void affine_transform(Mat img, Mat& dst, Mat map, Size size) {
	dst = Mat(img.size(), img.type(), Scalar(0));
	Rect rect(Point(0, 0), img.size());
	Mat inv_map;
	invertAffineTransform(map, inv_map);
	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			Point3d ji(j, i, 1);
			Mat xy = inv_map * (Mat)ji;
			Point2d pt = (Point2d)xy;
			if (rect.contains(pt))
				dst.at<uchar>(i, j) = bilinear_value(img, pt.x, pt.y);
		}
	}
}
int main() {
	Mat image = imread("./자연.jpeg", 0);
	resize(image, image, Size(400, 300));
	CV_Assert(image.data);
	//Point2f pt1[3] = { Point2f(10,200),Point2f(200,150),Point2f(300,300) };
	//Point2f pt2[3] = { Point2f(10,10),Point2f(250,10),Point2f(300,300) };
	Point center(300, 100);
	double angle = 30.0;
	double scale = 1;


	Mat rot_map = getRotationMatrix2D(center, angle, scale);
	Mat dst1,dst2;
	affine_transform(image, dst1, rot_map, image.size());
	//warpAffine(image, dst1, rot_map, image.size(),INTER_LINEAR);

	rotation(image, dst2, -angle, center);
	imshow("image", image);
	imshow("rotation_affine", dst1);
	imshow("rotation_function", dst2);
	waitKey();
	return 0;


}