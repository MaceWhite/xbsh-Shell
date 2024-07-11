#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <direct.h>

/*
   <<< FORWARD DECLARATIONS >>>
*/

int xbsh_CD(std::vector<std::string> args);
int xbsh_HELP(std::vector<std::string> args);
int xbsh_EXIT(std::vector<std::string> args);

/*
    <<< I DON'T KNOW WHAT TO NAME THIS PART >>>
*/

std::string builtin_commands[3] = {
    "cd",   // Change Directory
    "help", // Display Help info
    "exit", // Quit the shell
};

int (*builtin_func[])(std::vector<std::string>) = // Array of function pointers
    {
        xbsh_CD,
        xbsh_HELP,
        xbsh_EXIT,
};

int xbsh_NumberOfBuilt_Ins()
{
    return sizeof(builtin_commands) / sizeof(std::string);
}

/*
    <<< COMMANDS >>>
*/

int xbsh_CD(std::vector<std::string> args)
{
    if (args[1].empty())
    {
        std::cerr << "xbsh: Expected argument to 'cd'" << '\n';
    }
    else
    {
        if (_chdir(args[1].c_str()) != 0) // if chdir fails
        {
            std::cerr << "xbsh" << '\n';
        }
    }
    return 0;
}

int xbsh_HELP(std::vector<std::string> args)
{
    int i;
    std::cout << "XBSH - Version 1.0\n";

    for (int i = 0; i < xbsh_NumberOfBuilt_Ins(); i++)
    {
        std::cout << builtin_commands[i] << '\n';
    }

    return 1;
}

int xbsh_EXIT(std::vector<std::string> args)
{
    return 0;
}
