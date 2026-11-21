#ifndef SOA_INTEGRAL_IMAGE_H
#define SOA_INTEGRAL_IMAGE_H

#include <vector>

#include "STBImage.h"

struct Image{
    std::vector<std::uint8_t> r;
    std::vector<std::uint8_t> g;
    std::vector<std::uint8_t> b;
};

struct ImageIntegral{
    std::vector<std::uint32_t> r;
    std::vector<std::uint32_t> g;
    std::vector<std::uint32_t> b;
};

Image from_STB_to_SoA_sequential(const STBImage &stb);

ImageIntegral compute_SoA_integral_image_sequential(const Image &input_img, int width, int height);

#endif
