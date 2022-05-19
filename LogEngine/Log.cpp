/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include "Log.hpp"

std::string CurrentTime(std::string currentTime)
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];

    tstruct = *localtime(&now);
    if (currentTime == "now")
        strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);
    else if (currentTime == "date")
        strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
    return std::string(buf);
}

void AddLog(std::string logMsg)
{
    std::string filePath = "Log/log_" + CurrentTime("date") + ".txt";
    std::string now = CurrentTime("now");
    std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
}
