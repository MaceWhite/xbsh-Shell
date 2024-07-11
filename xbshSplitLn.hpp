#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>

const std::string TOKEN_DELIM = " \t\r\n\a\"";
constexpr int TOKEN_BUFFER_SIZE{256};

std::vector<std::string> xbshSplitLn(std::string line)
{
    int tokenBufferSize = TOKEN_BUFFER_SIZE;
    std::vector<std::string> tokens(tokenBufferSize); // Initialises a vector of 256 initial strings, all with null characters
    std::string token = "";

    std::size_t position = line.find(TOKEN_DELIM); // Finds the first delimiter

    if (position == std::string::npos)
    {
        token = line;
    }

    while (!token.empty()) // While token is not empty
    {
        tokens.push_back(token); // Adds the token to the vector
        position++;

        if (position >= tokenBufferSize)
        {
            tokenBufferSize += TOKEN_BUFFER_SIZE;
            tokens.resize(tokenBufferSize); // Resizes the vector to accommodate the new tokens
        }

        position = line.find(TOKEN_DELIM, position);

        if (position == std::string::npos)
        {
            token = line.substr(position); // Adds the last token to the vector
        }

        else
        {
            token = line.substr(position + 1, line.find(TOKEN_DELIM, position + 1) - position - 1);
            // Prepares the next tokem for loop iteration, making sure the function continues to split the input string into tokens untill all tokens have been processed
        }
        
    }

    return tokens;
}