#include "soa_integral_image.h"

Image from_STB_to_SoA_sequential(const STBImage &stb){
    int numPixels = stb.width * stb.height;
    Image soa;
    soa.r.resize(numPixels);
    soa.g.resize(numPixels);
    soa.b.resize(numPixels);

    for(int p=0; p<numPixels; p++) {
        int i = p*stb.channels;
        soa.r[p] = stb.rgb_image[i];
        soa.g[p] = stb.rgb_image[i + 1];
        soa.b[p] = stb.rgb_image[i + 2];
    }

    return soa;
}

ImageIntegral compute_SoA_integral_image_sequential(const Image &input_img, int width, int height){
    int numPixels = width * height;
    ImageIntegral integral_img;
    integral_img.r.resize(numPixels);
    integral_img.g.resize(numPixels);
    integral_img.b.resize(numPixels);

    for (int y=0; y<height; y++)
        for (int x=0; x<width; x++){

            int p = y * width + x;

            integral_img.r[p] = input_img.r[p];
            integral_img.g[p] = input_img.g[p];
            integral_img.b[p] = input_img.b[p];

            if (x>0 && y>0)
            {
                integral_img.r[p] += integral_img.r[p-1] + integral_img.r[p-width] - integral_img.r[p-width-1];
                integral_img.g[p] += integral_img.g[p-1] + integral_img.g[p-width] - integral_img.g[p-width-1];
                integral_img.b[p] += integral_img.b[p-1] + integral_img.b[p-width] - integral_img.b[p-width-1];
            }
            else if (x==0 && y>0)
            {
                integral_img.r[p] += integral_img.r[p-width];
                integral_img.g[p] += integral_img.g[p-width];
                integral_img.b[p] += integral_img.b[p-width];
            }
            else if (x>0 && y==0)
            {
                integral_img.r[p] += integral_img.r[p-1];
                integral_img.g[p] += integral_img.g[p-1];
                integral_img.b[p] += integral_img.b[p-1];
            }
        }
    return integral_img;
}