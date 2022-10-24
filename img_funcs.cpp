#include <iostream>
#include "img_funcs.h"
#include "imageio.h"

void invert(std::string inpImg, std::string outImg){
    std::cout << "hi" << std::endl;
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(inpImg, img, h, w);
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            out[row][col] = 255 - img[row][col];
        }
    }
    writeImage(outImg, out, h, w);
}

void invertRight(std::string inpImg, std::string outImg){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(inpImg, img, h, w);
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++){
        for(int col = 0; col < w /2; col++){
            out[row][col] = img[row][col];
        }
    }
    for(int row = 0; row < h; row++){
        for(int col = w / 2; col < w; col++){
            out[row][col] = 255 - img[row][col];
        }
    }
    writeImage(outImg, out, h, w);
}

void whiteBox(std::string inpImg, std::string outImg){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(inpImg, img, h, w);
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            out[row][col] = img[row][col];
        }
    }
    for(int row = h/2 - h/4; row < h/2 + h/4; row++){
        for(int col = w/2 - w/4; col < w/2 + w/4; col++){
            out[row][col] = 255;
        }
    }
    writeImage(outImg, out, h, w);
}

void whiteFrame(std::string inpImg, std::string outImg){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(inpImg, img, h, w);
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            out[row][col] = img[row][col];
        }
    }
    for(int col = w/2 - w/4; col < w/2 + w/4; col++){
            out[h/2 - h/4][col] = 255;
    }
    for(int col = w/2 - w/4; col < w/2 + w/4; col++){
            out[h/2 + h/4][col] = 255;
    }
    for(int row = h/2 - h/4; row < h/2 + h/4; row++){
            out[row][w/2 - w/4] = 255;
    }
    for(int row = h/2 - h/4; row < h/2 + h/4; row++){
            out[row][w/2 + w/4] = 255;
    }
    writeImage(outImg, out, h, w);
}

void scale(std::string inpImg, std::string outImg){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(inpImg, img, h, w);
    int out[MAX_H][MAX_W];
    for(int row = 0; row < 2 * h && row < MAX_H; row += 2){
        for(int col = 0; col < 2 * w && col < MAX_W; col += 2){
            out[row][col] = img[row / 2][col /2];
            out[row + 1][col] = img[row / 2][col / 2];
            out[row][col + 1] = img[row / 2][col / 2];
            out[row + 1][col + 1] = img[row / 2][col / 2];
        }
    }
    int height = std::min(2 * h, MAX_H);
    int width = std::min(2 * w, MAX_W);
    writeImage(outImg, out, height, width);
}

void pixelate(std::string inpImg, std::string outImg){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(inpImg, img, h, w);
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row += 2){
        for(int col = 0; col < w; col += 2){
            int avg = (img[row][col] + img[row + 1][col] + img[row][col + 1] + img[row + 1][col + 1]) / 4;
            out[row][col] = avg;
            out[row + 1][col] = avg;
            out[row][col + 1] = avg;
            out[row + 1][col + 1] = avg;
        }
    }
    writeImage(outImg, out, h, w);
}