#include <opencv2/opencv.hpp>
#include <iostream>


int main(int argc, char** argv){
    cv::Mat img = cv::imread(argv[1], -1);
    if( img.empty()) {
        std::cout << "Image not exist" << std::endl;
        return -1;
    }
        
    cv::namedWindow ("Example1",cv::WINDOW_AUTOSIZE);
    cv::imshow("Example1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
}

