#include "xbshReadLn.hpp"
#include "xbshSplitLn.hpp"
#include "xbshExec.hpp"

// xbsh: eXtremely bad shell

/*
    Lifetime of a shell

    Intialise: Shell reads and executes its config files.
    Interpret: Shell reads commands from stdin and executes them.
    Terminate: Shell executes any shutdown commands, frees memory and exits.
*/

void xbshLoop(); // Forward declaration

/*
    Loop of a shell

    Read: Reads commands from standard input.
    Parse: Splits command string into arguments and programs
    Execute: Runs command after parsing.
*/

int main()
{
    xbshLoop();

    return 0;
}

void xbshLoop() // Basic loop of xbsh
{
    std::string line;
    std::vector<std::string> args;
    int status;

    do
    {
        std::printf("xbsh >_  ");
        line = xbshReadLn();
        args = xbshSplitLn(line);
        status = xbshExec(args);


    } while (status);
}