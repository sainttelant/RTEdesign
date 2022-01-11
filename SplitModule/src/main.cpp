#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/features2d/features2d.hpp"
#include <opencv2/xfeatures2d/nonfree.hpp>
#include "opencv2/flann/flann.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include <videostab.h>

using namespace std;
using namespace cv;

// This class redirects cv::Exception to our process so that we can catch it and handle it accordingly.
class cvErrorRedirector {
public:
    int cvCustomErrorCallback( )
    {
        std::cout << "A cv::Exception has been caught. Skipping this frame..." << std::endl;
        return 0;
    }

    cvErrorRedirector() {
        redirectError((cv::ErrorCallback)cvCustomErrorCallback(), this);
    }
};

const int HORIZONTAL_BORDER_CROP = 30;

int main_01()
{
   
    
    //Create a object of stabilization class
    VideoStab stab;

    //Initialize the VideoCapture object
    VideoCapture cap("../SplitModule/data/18AF.avi");

    Mat frame_2, frame2;
    Mat frame_1, frame1;
    cap.read(frame_1);
    cap >> frame_1;
    cvtColor(frame_1, frame1, COLOR_BGR2GRAY);
    int fps = cap.get(CAP_PROP_FPS);
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    Mat smoothedMat(2,3,CV_64F);
    Mat smoothedFrame;
    VideoWriter outputVideo;
    outputVideo.open("../SplitModule/data/out1.mp4" , VideoWriter::fourcc('M', 'J', 'P', 'G'), fps , cv::Size(width,height),true);

    while(1)
    {
        cap.read(frame_2);
           cap >> frame_2;
           printf(">>>>>>>>>>>>>>>>>>>...............1 \n");
           if(frame_2.data == NULL)
            {
                break;
            }

            cvtColor(frame_2, frame2, COLOR_BGR2GRAY);
            smoothedFrame = stab.stabilize(frame_1 , frame_2);
            outputVideo.write(smoothedFrame);
            cv::imshow("Stabilized Video" , smoothedFrame);
            cv::waitKey(5);
            printf(">>>>>>>>>>>>>>>>>>>...............2 \n");
            frame_1 = frame_2.clone();
            frame2.copyTo(frame1);

    }
    printf(">>>>>>>>>>>>>>>>>>>...............4 \n");
    
    cv::destroyAllWindows();
   
    system("PAUSE");

    return 0;
}


