#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>

constexpr int BUFFER_SIZE{1024};

std::string xbshReadLn()
{
    int bufferSize = BUFFER_SIZE;
    int pos = 0; // pos means position btw
    std::string buffer(bufferSize, '\0');
    // ^ Creates a string with how many characters are in bufferSize, initialized with null characters
    int c;

    if (buffer.empty())
    {
        std::cerr << "Error, couldn't intialise buffer." << '\n';
    }

    while ((c == std::cin.get()) != '\n' && c != EOF)
    {
        buffer.at(pos) = static_cast<char>(c);
        pos++;

        if (pos >= bufferSize)
        {
            bufferSize += BUFFER_SIZE;
            buffer.resize(bufferSize, '\0');

            if (buffer.empty())
            {
                std::cerr << "Error, couldn't resize buffer." << '\n';
                break;
            }
        }
    }
    buffer.at(pos) = '\0'; // Null-terminate the string
    return buffer;
}