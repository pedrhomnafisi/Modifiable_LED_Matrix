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
#include <fstream>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    int height, width;
    int newH, newW;
    double ratioH, ratioW;
    
    // Load image from path.
    Mat img = imread("/Users/danny/Desktop/Processes of OO Software/Developer/image_resizer/image_resizer/wide_test.jpg");
    
    cv::Size s = img.size();
    height = s.height;
    width = s.width;
    
    double ratio = (double) width / (double) height;
    
    // Tall image or Wide image
    if (height > width || (height < width && (1 / ratio > 0.5))) {
        newH = 32;
        newW = newH*ratio;
        ratioH = (double) newH / (double) height;
        ratioW = (double) newW / (double) width;
    }
    
    // Wide image
    else if (height < width && (1 / ratio <= 0.5)) {
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
//    imshow("Orginal picture", img);
    
    // Resize image and print it.
    cv::Mat resized_img;
    cvNamedWindow("Floodfill picture", WINDOW_AUTOSIZE);
    resize(img, resized_img, Size(newW, newH), ratioW, ratioH, CV_INTER_LANCZOS4);
//    imshow("Floodfill picture", resized_img);
    
    cv::Size newS = resized_img.size();
    
    // Write new dimensions to the file.
    ofstream outfile;
    outfile.open("resized_img.txt");
    outfile << newS.height;
    outfile << "\n";
    outfile << newS.width;
    outfile << "\n";
    
    // Loop through the image matrix and touch each pixel.
    for (int y = 0; y < newH; y++) {
        for (int x = 0; x < newW; x++) {
            
            Vec3f v = resized_img.at<cv::Vec3b>(y,x);
            
            // The opencv standard gives the array in BGR format which is why
            // the indices look off.
            float blue = v[0];
            float green = v[1];
            float red = v[2];
            
            // Write RBG values to the file.
            outfile << red;
            outfile << ",";
            outfile << green;
            outfile << ",";
            outfile << blue;
            
            // Write '~' instead of ',' to indicate the end of the file.
            if (y == newH - 1 && x == newW - 1) {
                outfile << "~";
            } else {
                outfile << ",";
            }
        }
    }
    
    outfile.close();
    
    
    waitKey();
    
    
    return 0;
}
