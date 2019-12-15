#include "imageDecoder.h"

int main()
{
    std::vector<std::string> layers;
    readFromFile("input.txt", &layers);

    // find layer with most 0s
    std::string checkSumLayer = findCheckSumLayer(&layers);
    int checksum = checkSum(checkSumLayer);

    std::cout << "checksum = " << checksum << std::endl;

    std::cout << "decoded: \n"
              << visualiseDecodedImage(decodeImage(&layers)) << std::endl;
}
