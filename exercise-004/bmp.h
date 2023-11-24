#ifndef BMP_H
#define BMP_H

#include <fmt/chrono.h>
#include <fmt/format.h>
#include "CLI/CLI.hpp"

struct BMPFileHeader {
    uint16_t file_type = 0x4D42;          // File type always BM which is 0x42
    uint32_t file_size = 0;               // Size of the file (in bytes)
    uint32_t reserved = 0;                // Reserved
    uint32_t offset_data = 0;             // Start position of pixel data (bytes from the beginning of the file)
};

struct BMPInfoHeader {
    uint32_t size{ 0 };                      // Size of this header (in bytes)
    int32_t width{ 0 };                      // width of bitmap in pixels
    int32_t height{ 0 };                     // height of bitmap in pixels
                                             //       (if positive, bottom-up, with origin in lower left corner)
                                             //       (if negative, top-down, with origin in upper left corner)
    uint16_t planes{ 1 };                    // No. of planes for the target device, this is always 1
    uint16_t bit_count{ 24 };                 // No. of bits per pixel
    uint32_t compression{ 0 };               // 0 or 3 - uncompressed.
    uint32_t size_image{ 0 };                // 0 - for uncompressed images
    int32_t x_pixels_per_meter{ 0 };         // 0 for most bmp files
    int32_t y_pixels_per_meter{ 0 };         // 0 for most bmp files
    uint32_t colors_used{ 0 };               // No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
    uint32_t colors_important{ 0 };          // No. of colors used for displaying the bitmap. If 0 all colors are required
};

struct BMPColorHeader {
     uint8_t red;
     uint8_t green;
     uint8_t blue;
};

struct BMP {
     BMPFileHeader file_header;
     BMPInfoHeader info_header;
     BMPColorHeader color_header;
     std::vector<BMPColorHeader> bmp_data;
 
    BMP(std::string& fname) {
        read(fname);
    }
    bool read(const std::string& fname);
    bool write();
};

#endif