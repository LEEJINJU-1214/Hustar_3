// 컬러 영상 파일을 Mat 객체로 로드해서 윈도우 창에 명암도 영상으로 표시하고 “test.jpg”와 “test.png” 파일로 각각 저장하시오.이때 영상 파일을 가장 좋은 화질로 압축하시오.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image;
void print_matInfo(string name, Mat img) {
	string mat_type;

}
int main() {
	string filename = "C:/Users/leeji/Documents/증명사진/고양이.jpg";
	Mat color2gray = imread(filename, IMREAD_GRAYSCALE);//영상파일로드
	CV_Assert(color2gray.data);//예외처리

	vector<int> params_jpg, params_png;
	params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	params_jpg.push_back(100);
	params_png.push_back(IMWRITE_PNG_COMPRESSION);
	params_png.push_back(0);

	imwrite("C:/Users/leeji/Documents/증명사진/test.jpg", color2gray, params_jpg);
	imwrite("C:/Users/leeji/Documents/증명사진/test.png", color2gray, params_png);
	imshow("gray", color2gray);
	waitKey(0);

	return 0;


}
