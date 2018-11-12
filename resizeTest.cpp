/*
  Smart LED Project
  COP4331C
  Pedrhom Nafisi
  Bo Williams
  Daniel Ohana
  Brandon Kessler
*/

/*
	This code checks to see if given certain picture height and width values,
  the resizer function will give the correct size of the new image.
*/

#include <iostream>

using namespace std;

int resizeTest(int height, int width) {
    double ratio = (double) width / (double) height;
    int newH, newW;
    double ratioH, ratioW;

    // Image that fits in LED
    if (height <= 32 && width <= 64) {
        newW = width;
        newH = height;
        ratioH = (double) newH / (double) height;
        ratioW = (double) newW / (double) width;
    }

    // Tall image or Wide image
    else if (height > width || (height < width && (1 / ratio > 0.5))) {
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

    return newH*newW;
}

int main(int argc, const char * argv[]) {
    int height, width;

    // Square image
    if(!(resizeTest(1200, 1200) == 32*32)) {
        cout << "Failure\n";
        return 0;
    }
    // Height bigger than width
    if(!(resizeTest(1400, 1200) == 32*27)) {
        cout << "Failure\n";
        return 0;
    }
    // Width bigger than height with ratio > 0.5
    if(!(resizeTest(1000, 1200) == 32*38)) {
        cout << "Failure\n";
        return 0;
    }
    // Width bigger than height with ratio < 0.5
    if(!(resizeTest(1000, 2000) == 32*64)) {
        cout << "Failure\n";
        return 0;
    }
    // Height and width fit in LED already
    if(!(resizeTest(32, 64) == 32*64)) {
        cout << "Failure\n";
        return 0;
    }
    if(!(resizeTest(1, 2) == 1*2)) {
        cout << "Failure\n";
        return 0;
    }

    cout << "Success\n";

    return 0;
}
