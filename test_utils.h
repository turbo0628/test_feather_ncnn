#pragma once
#define _GNU_SOURCE

#include <string>
#include <vector>
#include <stdio.h>

void SplitString(const std::string &input, const std::string &delim, std::vector<std::string> &parts);

int load_txt_floats(float* dst, FILE* fp, int w, int h, int c);