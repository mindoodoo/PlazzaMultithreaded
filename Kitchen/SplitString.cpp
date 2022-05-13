/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** SplitString
*/
#include "SplitString.hpp"

SplitString::SplitString(std::string originalStr, std::string sep)
        : _originalStr(originalStr) {
    size_t pos = 0;

    while ((pos = originalStr.find(sep)) != std::string::npos) {
        this->_tokens.push_back(originalStr.substr(0, pos));
        originalStr.erase(0, pos + sep.length());
    }
    if (originalStr != "")
        this->_tokens.push_back(originalStr);
}

const std::string &SplitString::getOriginalStr() const {
    return _originalStr;
}
