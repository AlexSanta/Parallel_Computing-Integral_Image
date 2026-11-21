#ifndef AOS_INTEGRAL_IMAGE_SEQ_H
#define AOS_INTEGRAL_IMAGE_SEQ_H

#include "STBImage.h"

#include <vector>

struct Pixel {
    std::uint8_t r, g, b;
};

struct PixelIntegral
{
    std::uint32_t r, g, b;
};

std::vector<Pixel> from_STB_to_AoS_sequential(const STBImage &stb);

std::vector<PixelIntegral> compute_AoS_integral_image_sequential(const std::vector<Pixel> &input_img, int width,
                                                      int height);

#endif
