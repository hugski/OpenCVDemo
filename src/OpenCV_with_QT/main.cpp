#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>
using namespace cv;

void cbMouse(int event, int x, int y, int flags, void *);
void tb1_Callback(int value, void *);
void tb2_Callback(int value, void *);
void checkboxCallBack(int state, void *);
void radioboxCallBack(int state, void *);
void pushbuttonCallBack(int, void *font);

Mat input_img, tmp_img;
const char mainWin [] = "opencv with Qt";
char msg[50];

int main(int ,char* argv[]){
    const char track1 [] = "TrackBar 1";
    const char track2 [] = "TrackBar 1";
    const char checkbox[] = "Check BOx";
    const char radiobox1 [] = "Radio Box1";
    const char radiobox2 [] = "Radio Box1";
    const char pushbutton [] = "Push Button";

    int tb1_value = 50;
    int tb2_value = 25;

    input_img = imread(argv[1]);
    if (input_img.empty()) {
        std::cout << "Error" << std::endl;
        return -1;
    }

    namedWindow(mainWin);
    QtFont font = fontQt("Arial", 20, Scalar(255, 0, 0, 0),
            QT_FONT_BLACK, QT_STYLE_NORMAL);

    setMouseCallback(mainWin, cbMouse, NULL);
    createTrackbar (track1, mainWin, &tb1_value, 100, tb1_Callback);
    createButton(checkbox, checkboxCallBack, 0, QT_CHECKBOX);
    createButton(pushbutton, pushbuttonCallBack, (void *)&font, QT_PUSH_BUTTON);
    createTrackbar(track2, mainWin, &tb2_value, 50, tb2_Callback);
    createButton(radiobox1, radioboxCallBack, 
            (void *) radiobox1, QT_RADIOBOX);
    createButton(radiobox2, radioboxCallBack,
            (void *) radiobox2, QT_RADIOBOX);

    imshow(mainWin, input_img);
    waitKey();
    return 0;
}

void tb1_Callback(int value, void *) {
    sprintf(msg, "Trackbar 1 changed. New value=%d", value);
    displayOverlay(mainWin, msg);
    return;
}

void tb2_Callback(int value, void *) {
    sprintf(msg, "Trackbar 2 changed, new value=%d", value);
    displayStatusBar(mainWin, msg, 1000);
    return ;
}

void cbMouse(int event, int x, int y, int flags, void *){
    static Point p1, p2;
    static bool p2set = false;

    if(event == EVENT_LBUTTONDOWN) {
        p1 = Point(x, y);
        p2set = false;
    } else if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) {
        if( x > input_img.size().width){
            x = input_img.size().width;
        } else if ( x < 0){
            x = 0;
        }
        if( y > input_img.size().width){
            y = input_img.size().width;
        } else if ( y < 0){
            y = 0;
        }
        p2 = Point(x, y);
        p2set = true;
        input_img.copyTo(tmp_img);
        rectangle(tmp_img, p1, p2, Scalar(0, 0, 255));
        imshow(mainWin, tmp_img);
    } else if (event == EVENT_LBUTTONUP && p2set){
        Mat submat = input_img(Rect(p1, p2));

        rectangle(input_img, p1, p2, Scalar(0, 0, 255), 2);
        imshow("main_win", input_img);
    }
    return ;
}

void checkboxCallBack(int state, void *){
    sprintf(msg, "Check box changed. new state=%d", state);
    displayStatusBar(mainWin, msg);
    return;
}

void radioboxCallBack(int state, void *id) {
    sprintf(msg, "%s changed. new State = %d", (char *) id, state);
    displayStatusBar(mainWin, msg);
    return;
}

void pushbuttonCallBack(int ,void * font){
    addText(input_img, "Push button clicked",
            Point(50,50), *(QtFont *) font);
    imshow(mainWin, input_img);
    return;
}