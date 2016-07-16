#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
    int flip_flag = 0;
    Mat out_image;
    
    if(argc != 4) {
        cout << "Usage: <cmd> <flip_code> <file_in> <file_out>\n";
        return -1;
    }
    Mat in_image = imread(argv[2],CV_LOAD_IMAGE_GRAYSCALE);
    if (in_image.empty()) {
        cout << "Error! Can't find image" << endl;
        return -1;
    }
    flip_flag = atoi(argv[1]);
    flip(in_image, out_image, flip_flag);
    imwrite(argv[3], out_image);
    string  win = "Flip the image";
    namedWindow(win);
    imshow(win, out_image);
    cout << "Press any key to exit ...\n";
    waitKey(0);
    return 0;
}

