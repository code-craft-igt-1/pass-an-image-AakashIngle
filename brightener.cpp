#include "brightener.h"
#include <iostream>

ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) {}

int ImageBrightener::BrightenWholeImage() {
    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_inputImage.rows; ++x) {
        for (int y = 0; y < m_inputImage.columns; ++y) {
            int pixelIndex = x * m_inputImage.columns + y;
            if (m_inputImage.pixels[pixelIndex] > (255 - 25)) {
                ++attenuatedPixelCount;
                m_inputImage.pixels[pixelIndex] = 255;
            }
            else {
                m_inputImage.pixels[pixelIndex] += 25;
            }
        }
    }
    return attenuatedPixelCount;
}

Image& ImageBrightener::GetImage() const {
    return m_inputImage;
}
