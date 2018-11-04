//
//  main.cpp
//  image_resizer
//
//  Created by Daniel Ohana and Bo Williams on 11/4/18.
//  Copyright © 2018 Daniel Ohana. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

// TODO: Find out solution for images with ratio close to but less than 1.0.
// TODO: Get RGB image values instead of single values.


using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    int height, width;
    int newH, newW;
    double ratioH, ratioW;
    
    // Load image from path.
    Mat img = imread("/Users/danny/Desktop/Processes of OO Software/Developer/image_resizer/image_resizer/ratio_test.jpg");
    
    cv::Size s = img.size();
    height = s.height;
    width = s.width;
    
    cout << "Original image dimensions: ";
    cout << s.height;
    cout << "x";
    cout << s.width;
    cout<< " pixels\n";
    
    // Tall image
    if(height > width) {
        double ratio = (double) width / (double) height;
        newH = 32;
        newW = newH*ratio;
        ratioH = (double) newH / (double) height;
        ratioW = (double) newW / (double) width;
    }
    
    // Wide image
    else if(height < width && ((double) height / (double) width) <= 0.5) {
        double ratio = (double) width / (double) height;
        newW = 64;
        newH = newW/ratio;
        ratioH = (double) newH / (double) height;
        ratioW = (double) newW / (double) width;
    }
    
    // Square image
    else {
        newH = 32;
        newW = 32;
        ratioH = (double) newH / (double) height;
        ratioW = (double) newW / (double) width;
    }

    // Print original image.
    cvNamedWindow("Original picture", WINDOW_AUTOSIZE);
    imshow("Orginal picture", img);
    
    
    // Resize image and print it.
    cv::Mat resized_img;
    cvNamedWindow("Floodfill picture", WINDOW_AUTOSIZE);
    resize(img, resized_img, Size(newW, newH), ratioW, ratioH, CV_INTER_LANCZOS4);
    imshow("Floodfill picture", resized_img);
    
    cv::Size newS = resized_img.size();
    cout << "New image dimensions: ";
    cout << newS.height;
    cout << " x ";
    cout << newS.width;
    cout << " pixels\n";
    
    
    // Loop through the image matrix and touch each pixel.
    for (int y = 0; y < newH; y++) {
        for (int x = 0; x < newW; x++) {
            cout << resized_img.at<uint16_t>(x, y);
            cout << " ";
        }
        cout << "\n";
    }
    

    
    
    
    waitKey();
    
    
    return 0;
}
