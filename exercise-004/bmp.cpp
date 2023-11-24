#include <fmt/chrono.h>
#include <fmt/format.h>
#include "iostream"

#include "CLI/CLI.hpp"
#include "bmp.h"


bool BMP::read(const std::string& fname){
    std::ifstream file(fname, std::ios_base::binary);
    if (!file) {
        std::cerr  << "Could not open the file.\n";
        return 1;
    }
    file.read(reinterpret_cast<char*>(&file_header.file_type), sizeof(BMPFileHeader::file_type));
    if (file_header.file_type != 0x4D42) {
        std::cerr << "File is not a BMP.\n";
        return 1;
    }
    file.read(reinterpret_cast<char*>(&file_header.file_size), sizeof(BMPFileHeader::file_size));
    file.read(reinterpret_cast<char*>(&file_header.reserved), sizeof(BMPFileHeader::reserved));
    file.read(reinterpret_cast<char*>(&file_header.offset_data), sizeof(BMPFileHeader::offset_data));
    file.read(reinterpret_cast<char*>(&info_header.size), sizeof(BMPInfoHeader::size));
    file.read(reinterpret_cast<char*>(&info_header.width), sizeof(BMPInfoHeader::width));
    file.read(reinterpret_cast<char*>(&info_header.height), sizeof(BMPInfoHeader::height));
    file.read(reinterpret_cast<char*>(&info_header.planes), sizeof(BMPInfoHeader::planes));
    file.read(reinterpret_cast<char*>(&info_header.bit_count), sizeof(BMPInfoHeader::bit_count));
    file.read(reinterpret_cast<char*>(&info_header.compression), 24);
    
    bmp_data.resize(info_header.size_image/3);
    file.seekg(file_header.offset_data, std::ios::beg);
    file.read(reinterpret_cast<char*>(bmp_data.data()), info_header.size_image); 
    /*
    for (auto pixel : this->bmp_data)
        {
            pixel.red = uint8_t(imageData[i++]);
            pixel.green = uint8_t(imageData[i++]);
            pixel.blue = uint8_t(imageData[i++]);
        }
    */
    file.close();
    return 0;
}
bool BMP::write(){
    const std::string ascii_symbols = " .:-=+*#%@";

    int index = 0;
    for (int h = info_header.height; h > 0; --h) {
        for (int w = 0; w < info_header.width; ++w) {
            int pixel = (bmp_data[(w+1)*h].blue + bmp_data[(w+1)*h].green + bmp_data[(w+1)*h].red) / 3;
            // Map the pixel value to an ASCII character
            int symbol_index = static_cast<int>((pixel / 255.0) * (ascii_symbols.size()-1));
            // Print the corresponding ASCII symbol
            fmt::print("{}", ascii_symbols[symbol_index]);
        }
        fmt::print("\n");
    }
    return 0;
}
