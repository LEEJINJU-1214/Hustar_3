// �÷� ���� ������ Mat ��ü�� �ε��ؼ� ������ â�� ��ϵ� �������� ǥ���ϰ� ��test.jpg���� ��test.png�� ���Ϸ� ���� �����Ͻÿ�.�̶� ���� ������ ���� ���� ȭ���� �����Ͻÿ�.
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image;
void print_matInfo(string name, Mat img) {
	string mat_type;

}
int main() {
	string filename = "C:/Users/leeji/Documents/�������/�����.jpg";
	Mat color2gray = imread(filename, IMREAD_GRAYSCALE);//�������Ϸε�
	CV_Assert(color2gray.data);//����ó��

	vector<int> params_jpg, params_png;
	params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	params_jpg.push_back(100);
	params_png.push_back(IMWRITE_PNG_COMPRESSION);
	params_png.push_back(0);

	imwrite("C:/Users/leeji/Documents/�������/test.jpg", color2gray, params_jpg);
	imwrite("C:/Users/leeji/Documents/�������/test.png", color2gray, params_png);
	imshow("gray", color2gray);
	waitKey(0);

	return 0;


}
