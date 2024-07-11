#pragma once
#include <Windows.h>
#include <direct.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
int xbshLaunch(std::vector<std::string> args)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    std::string commandLn = args[0];
    for (size_t i = 1; i < args.size(); i++)
    {
        commandLn += " " + args[i];
    }

    const std::wstring commandLnW = std::wstring(commandLn.begin(), commandLn.end()); // Convert to wide string
    LPWSTR commandLnLPWSTR = new wchar_t[commandLnW.size() + 1]; // Allocate memory for wide string
    wcscpy_s(commandLnLPWSTR, commandLnW.size() + 1, commandLnW.c_str()); // Allocate wide string

    if (!CreateProcess(
            nullptr, // No module name
            nullptr, // Command line
            nullptr, // Process handle not inheritable
            nullptr, // Thread handle not inheritable
            FALSE, // Set handle inheritance to FALSE
            0, // No creation flags
            nullptr,  // Use parent's environment block
            nullptr,  // Use parent's current directory
            &si,  // Reference to STARTUPINFO structure
            &pi))  // Reference to PROCESS_INFORMATION structure
    {
        delete[] commandLnLPWSTR;
        return -1;
    }

    delete[] commandLnLPWSTR;
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}