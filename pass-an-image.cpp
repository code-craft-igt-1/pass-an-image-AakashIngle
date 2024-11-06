#include <iostream>
#include "brightener.h"

int main() {
    try {
        Image image(512, 512);
        //std::cout << "Brightening a " << image.rows << " x " << image.columns << " image\n";
        ImageBrightener brightener(image);
        int attenuatedCount = brightener.BrightenWholeImage();
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";  // Handle invalid dimensions
    }

    return 0;
}
