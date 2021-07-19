//���� ó������ ����(projection)�� ������ �������� ǥ���ȴ�. OpenCV �Լ� �߿�
//cv::reduce() �Լ��� �̿��ؼ� ���İ� ���� ���� �� ������� ������ �����ϴ� ��
//�α׷��� �ۼ��ϰ�, ���� ������ �о ���� ������׷��� ����Ͻÿ�.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void draw_histo(Mat hist, Mat& hist_img, Size size = Size(256, 300)) {
	if (hist.rows == 1) {
		hist_img = Mat(size, CV_8U, Scalar(255));

		normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);//���� �� �迭�� �븻������
	/*	���� ���̴ϱ� ���߿��� ���� ����ȭ�ϴ� ��! ���� col�� �Ұ�� ���� �ִ밪���� ǥ������������ �ǹ� �ϵ� ����.*/

		for (int i = 0; i < hist.cols; i++) {
			float start_x = i;
			float end_x = (i + 1);
			Point2f pt1(start_x, 0);
			Point2f pt2(end_x, hist.at<float>(i));
			if (pt2.y >= 0) {
				rectangle(hist_img, pt1, pt2, Scalar(0));
			}
		}
		flip(hist_img, hist_img, 0);
	}
	else {
		hist_img = Mat(size, CV_8U, Scalar(255));
		normalize(hist, hist, 0, hist_img.cols, NORM_MINMAX);
		for (int i = 0; i < hist.rows; i++) {
			float start_x = i;
			float end_x = (i + 1);
			Point2f pt1(0, start_x);
			Point2f pt2(hist.at<float>(i), end_x);
			if (pt2.y >= 0) {
				rectangle(hist_img, pt1, pt2, Scalar(0));
			}
		}
	}

}

int main() {
	Mat image = imread("./������.jpg",IMREAD_GRAYSCALE);
	CV_Assert(!image.empty());
	Mat dst_col, dst_row, hist_img;
	reduce(image, dst_row, 0, REDUCE_SUM, CV_32F);
	reduce(image, dst_col, 1, REDUCE_SUM, CV_32F);

	draw_histo(dst_row, hist_img,image.size());
	imshow("hist_row", hist_img);
	draw_histo(dst_col, hist_img, image.size());
	imshow("image", image);
	imshow("hist_col", hist_img);

	waitKey();
	return 0;

}