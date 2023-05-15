#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Read Images

// int main(int argc, char** argv )
// {
//     string path = "../Resources/test.png";
//     Mat img = imread(path);
//     imshow("Image", img);
//     waitKey(0); // N = wait for N ms, 0 for infinity
// }

// Read Videos

// int main(int argc, char** argv )
// {
//     string path = "../Resources/test.mp4";
//     VideoCapture cap(path);
//     Mat img;

//     while (1) {
//         cap.read(img);
//         imshow("Image", img);
//         waitKey(1);
//         // will catch an error once the video ends
//     }
// }

// Basic Functions

// int main(int argc, char** argv )
// {
//     string path = "../Resources/test.png";
//     Mat img = imread(path);
//     Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;

//     cvtColor(img, imgGray, COLOR_BGR2GRAY);

//     GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
//     Canny(imgBlur, imgCanny, 50, 150);

//     Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
//     dilate(imgCanny, imgDia, kernel);
//     erode(imgDia, imgErode, kernel);

//     imshow("Image", img);
//     imshow("Image Gray", imgGray);
//     imshow("Image Blur", imgBlur);
//     imshow("Image Canny", imgCanny);
//     imshow("Image Canny", imgDia);
//     imshow("Image Canny", imgErode);
//     waitKey(0);
// }

// Resize and Crop

// int main(int argc, char** argv )
// {
//     string path = "../Resources/test.png";
//     Mat img = imread(path);
//     Mat imgResize, imgCrop;

//     cout << img.size() << endl; // width x height

//     resize(img, imgResize, Size(), 0.5, 0.5);

//     Rect roi(100, 100, 250, 250);
//     imgCrop = img(roi);

//     // imshow("Image", img);
//     // imshow("Image", imgResize);
//     imshow("Image", imgCrop);

//     waitKey(0);
// }

// Draw Text and Shapes

// int main(int argc, char** argv )
// {
//     // Blank Image
//     Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

//     circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
//     rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255));
//     line(img, Point(130, 296), Point(283, 296), Scalar(0,0,0), 10);
//     putText(img, "ABC", Point(137, 292), FONT_HERSHEY_DUPLEX, 2, Scalar(123, 123, 23));
//     imshow("Image", img);

//     waitKey(0);
// }

// Warp Perspective

// int main(int argc, char** argv )
// {
//     // Blank Image
//     // 30 609 BL
//     // 214 598 BR 
//     // 210 387 TR
//     // 38 396 TL
//     string path = "../Resources/cards.jpeg";
//     Mat img = imread(path), matrix, imgWarp;

//     float w = 250.0, h = 350.0;

//     Point2f src[4] = {{38, 396}, {210, 387}, {214, 598}, {30, 609}};
//     Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

//     matrix = getPerspectiveTransform(src, dst);
//     warpPerspective(img, imgWarp, matrix, Point(w, h));

//     imshow("Image", imgWarp);

//     waitKey(0);
// }

// Color Detection

// int hmin = 0, smin = 110, vmin = 153;
// int hmax = 19, smax = 240, vmax = 255;

// int main(int argc, char** argv )
// {
//     string path = "../Resources/test.png";
//     Mat img = imread(path), imgHSV, mask;

//     cvtColor(img, imgHSV, COLOR_BGR2HSV);

//     namedWindow("Trackbars", (640, 200));
//     createTrackbar("Hue Min", "Trackbars", &hmin, 179);

//     while (1) {
//         Scalar lower(hmin, smin, vmin), upper(hmax, smax, vmax);
//         inRange(imgHSV, lower, upper, mask);

//         imshow("Image", mask);
//         waitKey(1);
//     }
// }

void getContours(Mat imgDil, Mat img) {
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // drawContours(img, contours, -1, Scalar(255, 0, 255), 2);



    for (int i = 0; i < contour.size(); i++) {
        int area = contourArea(contours[i]);
        cout << area << endl;

        vector<vector<Point> > conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        if (area > 1000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
            drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
            // boundRect[i] = boundRect(conPoly[i]);
            // rectangle(img, boundRect[i].tl())

            int objCor = (int)conPoly[i].size();

            if (objCor == 3) {
                objectType = "Tri";
            }

            if (objCor == 3) {
                objectType = "Tri";
            }
        }
    }
}

int main(int argc, char** argv )
{
    string path = "../Resources/test.png";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
}