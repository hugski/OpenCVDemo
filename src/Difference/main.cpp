#include <opencv2/opencv.hpp>
#include <iostream>

void FindDifference(cv::Mat src1, cv::Mat src2, cv::Mat &dst, int threshold) {
    dst = cv::abs(src2 - src1);
    cv::threshold(dst, dst, threshold, 255, cv::THRESH_BINARY);
}
int main(int argc, char** argv){
    Mat image_1, image_2;
    image_1 = imread(argv[1]);
    image_2 = imread(argv[2]);
}