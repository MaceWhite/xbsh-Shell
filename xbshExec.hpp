#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "xbshBuiltIn.hpp"
#include "xbshLaunch.hpp"

int xbshExec(std::vector<std::string> args)
{
    int i;

    if (args[0].empty())
    {
        return 1;
    }

    for (i = 0; i < xbsh_NumberOfBuilt_Ins(); i++)
    {
        if (args[0] == builtin_commands[i])
        {
            return (*builtin_func[i])(args);
        }
    }

    return 0;
}