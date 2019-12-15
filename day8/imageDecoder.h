#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// image in pixels
const int width = 25;
const int height = 6;

void readFromFile(std::string fileName, std::vector<std::string> *vec)
{
    std::ifstream ifs(fileName);
    std::string line;

    // read single line
    while (!ifs.eof() && getline(ifs, line))
    {
        // calculate numlayers
        const int digitsPerLayer = width * height;

        if (line.length() % digitsPerLayer != 0)
        {
            // bad image
            std::cout << "Error bad image for given height, width params" << std::endl;
            return;
        }

        const int numLayers = line.length() / digitsPerLayer;

        std::cout << "digitsPerLayer = " << digitsPerLayer << " => numLayers = " << numLayers << std::endl;

        for (int i = 0; i < numLayers; i++)
        {
            int startIndex = i * digitsPerLayer;

            vec->push_back(line.substr(startIndex, digitsPerLayer));
        }
    }

    ifs.close();
}

std::string findCheckSumLayer(std::vector<std::string> *vec)
{
    int minNum0s = vec->begin()->length() + 1;
    std::string currentMin = "not yet found";
    for (std::string layer : *vec)
    {
        int count = std::count(layer.begin(), layer.end(), '0');

        if (count < minNum0s)
        {
            minNum0s = count;
            currentMin = layer;
        }
    }

    std::cout << currentMin << "\n " << minNum0s << std::endl;

    return currentMin;
}

int checkSum(std::string layer)
{
    int ones = std::count(layer.begin(), layer.end(), '1');
    int twos = std::count(layer.begin(), layer.end(), '2');
    return ones * twos;
}

std::string decodeImage(std::vector<std::string> *image)
{
    std::string decodedImage;

    // for each pixel
    for (int i = 0; i < image->begin()->length(); i++)
    {
        auto it = image->begin();

        while (it->at(i) == '2')
        {
            it++;
        }

        decodedImage += it->at(i);

        if (i % (width) == width - 1)
        {
            decodedImage += '\n';
        }
    }

    return decodedImage;
}

std::string visualiseDecodedImage(std::string image)
{
    std::string output;
    for (int i = 0; i < image.length(); i++)
    {
        if (image.at(i) == '0')
        {
            output += " ";
        }
        else if (image.at(i) == '1')
        {
            output += 'x';
        }
        else if (image.at(i) == '\n')
        {
            output += '\n';
        }
    }

    return output;
}
