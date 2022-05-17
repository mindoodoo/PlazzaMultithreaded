/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** SplitString
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>

class SplitString {
public:
    // Builds new SplitString object
    // Splits string originalStr on sep
    // Split string is then available in vector _tokens
    SplitString(std::string originalStr, std::string sep);

    std::vector<std::string> _tokens;

    const std::string &getOriginalStr() const;

private:
    std::string const _originalStr;
};
