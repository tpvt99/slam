#include <iostream>
#include <chrono>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv) {
    // Read the image in argv[1]
    cv::Mat image;
    image = cv::imread(argv[1]); // call cv::imread to read the image from file

    // Check the data is correctly loaded
    if (image.data == nullptr) {
        cerr << "file " << argv[1] << " not exist." << endl;
        return 0;
    }

    // print some basic information
    cout << "Image cols: " << image.cols << ", rows: " << image.rows << ", channels: " << image.channels << endl;
    cv::imshow("image", image); // show the image
    cv::waitKey(0); // display and wait for a keyboard input

    // Checking image type
    if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
        // We need grayscale image or RGB image
        
    }
}