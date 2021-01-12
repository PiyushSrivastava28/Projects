#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat translateImg(Mat& img, int offsetx, int offsety) 
{
	Mat trans_mat = (Mat_<double>(2, 3) << 1, 0, offsetx, 0, 1, offsety);
	warpAffine(img, img, trans_mat, img.size());
	return img;
}

int main()
{
	int angle=0;
	cout << "Enter angle to rotate : ";
	cin >> angle;
	String str;
	cout << "Enter image name with proper format(image.jpg) : ";
	cin >> str;
	Mat image = imread( str , IMREAD_UNCHANGED);
	if (image.empty())
	{
		cout << "ERROR!";
		cin.get();
		return -1;
	}
	int width = image.cols;
	int height = image.rows;
	if (width > height)
		height = width;
	else
		width = height;
	Point2f pc(image.cols/2., image.rows/2.);
	Mat Rotated = getRotationMatrix2D(pc, angle, 0.5);
	Mat x;
	warpAffine(image, x, Rotated,Size(width,height));
	x=translateImg(x, +width/10, -height/10);
	imshow("Original_Image", image);
	imshow("Rotated_Image", x);
	waitKey(0);
	destroyWindow("Original_Image");
	destroyWindow("Rotated_Image");
	return 0;
}