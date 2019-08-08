#include <iostream>
#include <string>
#include <sstream>
#include <CImg.h>

using namespace cimg_library;

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input filename>" << std::endl;
        return(0);
    }

    CImg<float> sourceImage(argv[1]);

    std::cout << "Loaded image (" << argv[1] << ")" << std::endl;
    std::cout << "  Width:    " << sourceImage.width() << std::endl;
    std::cout << "  Height:   " << sourceImage.height() << std::endl;
    std::cout << "  Depth:    " << sourceImage.depth() << std::endl;
    std::cout << "  Spectrum: " << sourceImage.spectrum() << std::endl;

    if(sourceImage.spectrum() < 3) {
        std::cout << std::endl << "Image doesn't have enough channels to separate" << std::endl;
        return(0);
    }

    //Get the output file names

    std::string filenamePart;
    std::getline(std::istringstream(argv[1]), filenamePart, '.');

    //writhe the red channel out
    CImg<float> r_channel = sourceImage.get_channel(0);
    CImg<float> g_channel = sourceImage.get_channel(1);
    CImg<float> b_channel = sourceImage.get_channel(2);

    CImg<float> r_img(sourceImage.width(), sourceImage.height(), 1, 3);
    CImg<float> g_img(sourceImage.width(), sourceImage.height(), 1, 3);
    CImg<float> b_img(sourceImage.width(), sourceImage.height(), 1, 3);

    r_img.draw_image(0,0,0,0,r_channel);
    g_img.draw_image(0,0,0,1,g_channel);
    b_img.draw_image(0,0,0,2,b_channel);

    r_img.save_jpeg(std::string(filenamePart + "_r.jpg").c_str());
    g_img.save_jpeg(std::string(filenamePart + "_g.jpg").c_str());
    b_img.save_jpeg(std::string(filenamePart + "_b.jpg").c_str());

    return(0);
}