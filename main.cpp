#include <iostream>
#include "img_funcs.h"
#include "imageio.h"

int main(){
    std::string input = "into_the_breach.pgm";
    invert(input, "taskA.pgm");
    invertRight(input, "taskB.pgm");
    whiteBox(input, "taskC.pgm");
    whiteFrame(input, "taskD.pgm");
    scale(input, "taskE.pgm");
    pixelate(input, "taskF.pgm");
    return 0;
}