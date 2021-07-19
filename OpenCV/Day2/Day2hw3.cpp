//영상 처리에서 투영(projection)은 다음의 수식으로 표현된다. OpenCV 함수 중에
//cv::reduce() 함수를 이용해서 수식과 같이 수직 및 수평방향 투영을 수행하는 프
//로그램을 작성하고, 영상 파일을 읽어서 투영 히스토그램을 출력하시오.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void draw_histo(Mat hist, Mat& hist_img, Size size = Size(256, 300)) {
	if (hist.rows == 1) {
		hist_img = Mat(size, CV_8U, Scalar(255));

		normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);//열의 합 배열을 노말라이즈
	/*	열의 합이니까 그중에서 값을 정규화하는 것! 따라서 col을 할경우 열의 최대값까지 표현가능해져서 의미 일도 없음.*/

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
	Mat image = imread("./무지개.jpg",IMREAD_GRAYSCALE);
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