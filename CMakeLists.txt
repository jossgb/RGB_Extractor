cmake_minimum_required(VERSION 3.14)
project(RGB_Extractor)

set(CMAKE_CXX_STANDARD 14)


add_executable(RGB_Extractor main.cpp)
include_directories("/usr/local/include")
include_directories("/opt/X11/include")
include_directories("CImg")

target_link_directories(RGB_Extractor PUBLIC /usr/local/lib)
target_link_directories(RGB_Extractor PUBLIC /opt/X11/lib)

target_link_libraries(RGB_Extractor X11 png jpeg tiff fftw3_threads armadillo)
add_definitions(-Dcimg_use_jpeg -Dcimg_use_fftw3 -Dcimg_use_png -Dcimg_use_openmp -Dcimg_use_tiff)
