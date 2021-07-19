#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
   Mat image = imread("C:/Users/leeji/Documents/�������/�ڿ�.jpeg", IMREAD_COLOR);
   CV_Assert(image.data);

   Mat sharpen_imag;
   Mat sharpen_kernel = (Mat_<char>(3, 3) << 1, -2, 1,
                                             -2, 5, -2,
                                              1, -2, 1);
   filter2D(image, sharpen_imag, image.depth(), sharpen_kernel);
   imshow("img", image);
   imshow("sharpen", sharpen_imag);

   waitKey();
   return 0;
}