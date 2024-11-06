#pragma once
#include <cstdint>
#include <stdexcept>
#include <memory> 
constexpr int MAX_ROWS = 1024;
constexpr int MAX_COLS = 1024;

struct Image {
    int rows;
    int columns;
    std::unique_ptr<uint8_t[]> pixels;

    Image(int r, int c) : rows(r), columns(c), pixels(nullptr) {
        if (rows > MAX_ROWS || columns > MAX_COLS) {
            throw std::invalid_argument("Image dimensions exceed maximum allowed size (1024x1024).");
        }
        pixels = std::make_unique<uint8_t[]>(rows * columns);
        std::fill_n(pixels.get(), rows * columns, 0);
    }
    // Disable copy constructor and copy assignment operator to prevent shallow copies
    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

    // Allow move constructor and move assignment operator
    Image(Image&&) noexcept = default;
    Image& operator=(Image&&) noexcept = default;
};
class ImageBrightener {
private:
	Image& m_inputImage;
public:
	ImageBrightener(Image& inputImage);
	int BrightenWholeImage();
	Image& GetImage() const;
};
