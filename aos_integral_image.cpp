#include "aos_integral_image.h"

std::vector<Pixel> from_STB_to_AoS_sequential(const STBImage &stb){
    int numPixels = stb.width * stb.height;
    std::vector<Pixel> aos(numPixels);
    for(int p=0; p<numPixels; p++) {
        int i = p*stb.channels;
        aos[p].r = stb.rgb_image[i];
        aos[p].g = stb.rgb_image[i + 1];
        aos[p].b = stb.rgb_image[i + 2];
    }
    return aos;
}

std::vector<PixelIntegral> compute_AoS_integral_image_sequential(const std::vector<Pixel> &input_img, int width,
                                                                 int height){
    std::vector<PixelIntegral> integral_img(width*height);

    for (int y=0; y<height; y++)
        for (int x=0; x<width; x++){

            int p = y*width+x;

            integral_img[p].r = input_img[p].r;
            integral_img[p].g = input_img[p].g;
            integral_img[p].b = input_img[p].b;

            if (x>0 && y>0)
            {
                integral_img[p].r += integral_img[p-1].r + integral_img[p-width].r - integral_img[p-width-1].r;
                integral_img[p].g += integral_img[p-1].g + integral_img[p-width].g - integral_img[p-width-1].g;
                integral_img[p].b += integral_img[p-1].b + integral_img[p-width].b - integral_img[p-width-1].b;
            }
            else if (x==0 && y>0)
            {
                integral_img[p].r += integral_img[p-width].r;
                integral_img[p].g += integral_img[p-width].g;
                integral_img[p].b += integral_img[p-width].b;
            }
            else if (x>0 && y==0)
            {
                integral_img[p].r += integral_img[p-1].r;
                integral_img[p].g += integral_img[p-1].g;
                integral_img[p].b += integral_img[p-1].b;
            }
        }
    return integral_img;
}