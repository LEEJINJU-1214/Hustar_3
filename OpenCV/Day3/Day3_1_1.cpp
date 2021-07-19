////OpenCV 함수를 사용해서 컬러 영상에서 샤프닝을 수행하는 프로그램을 작성하시오
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter(Mat img, Mat& dst, Mat mask) {

	dst = Mat(img.size(), CV_32F, Scalar(0));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			float sum = 0;
			for (int u = 0; u < mask.rows; u++) {
				for (int v = 0; v < mask.cols; v++) {
					int y = i + u - h_m.y;
					int x = j + v - h_m.x;
					sum += (mask.at<float>(u, v)/9) * img.at<uchar>(y, x);
					//선택한 마스크 크기 따라 컨볼루션 계산
				}
			}
			if (sum > 255) sum = 255;
			if (sum < 0) sum = 0;

			dst.at<float>(i, j) = sum;
			//cout << dst.at<float>(i, j) << endl;
		}
	}
}
int main()
{
	Mat image = imread("C:/Users/leeji/Documents/증명사진/자연.jpeg", IMREAD_COLOR);
	CV_Assert(image.data);


	float data1[] = {
		1,1,1,
		1,1,1,
		1,1,1,
	};

	Mat mask1(3, 3, CV_32F, data1);

	Mat blur,rbg[3];
	Mat blur1, blur2, blur3;
	split(image, rbg);

	filter(rbg[0], rbg[0], mask1);
	filter(rbg[1], rbg[1], mask1);
	filter(rbg[2], rbg[2], mask1);
	
	rbg[0].convertTo(rbg[0], CV_8U);
	rbg[1].convertTo(rbg[1], CV_8U);
	rbg[2].convertTo(rbg[2], CV_8U);


	merge(rbg, 3, blur);
	//void merge(Mat src[], int N, Mat dest);
	// 
	// 합성될 입력배열 혹은 백터
	//void merge(vector<Mat> src, Mat dest);


	imshow("image", image);
	imshow("blur", blur);

	waitKey();
	return 0;
}

//filter2D로 구현
//#include <opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat image = imread("C:/Users/leeji/Documents/증명사진/자연.jpeg", 1);
//	CV_Assert(image.data);
//
//	float data1[] = {
//		1,1,1,
//		1,1,1,
//		1,1,1,
//	};
//	for (int i = 0; i < size(data1); i++)
//	{
//		data1[i] = data1[i] / size(data1);
//	}//마스크 크기로 나눠줌
//	Mat mask1(3, 3, CV_32F, data1);
//
//	Mat blur, blur1[3], rgb[3], dst;
//	filter2D(image, blur, -1, mask1);
//	split(image, rgb);
//	filter2D(rgb[0], blur1[0], -1, mask1);//색이 좀더 잘나옴
//	filter2D(rgb[1], blur1[1], -1, mask1);//cv2.CV_8U, cv2.CV_32F, cv2.CV_64F, -1지정시 입력값과 같은 출력값 생성
//	filter2D(rgb[2], blur1[2], -1, mask1);
//
//	merge(blur1, 3, dst);
//
//	imshow("image", image);
//	imshow("blur1", blur);
//	imshow("blur2", dst);
//	waitKey();
//	return 0;
//
//
//}