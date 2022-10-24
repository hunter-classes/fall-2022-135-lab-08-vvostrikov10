#include <iostream>
#include "img_funcs.h"
#include "imageio.h"

int main(){
    std::string input = "into_the_breach.pgm";
    invert(input, "invert.pgm");
    invertRight(input, "invertRight.pgm");
    whiteBox(input, "whiteBox.pgm");
    whiteFrame(input, "whiteFrame.pgm");
    scale(input, "scale.pgm");
    pixelate(input, "pixelate.pgm");
    return 0;
}