#include "test_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>

void SplitString(const std::string &input, const std::string &delim, std::vector<std::string> &parts)
{
    for (char *s = strtok((char *)input.data(), (char *)delim.data()); s; s = strtok(NULL, (char *)delim.data()))
    {
        if (s != NULL)
        {
            parts.push_back(s);
        }
    }
}

int load_txt_floats(float* dst, FILE* fp, int w, int h, int c)
{
    char* line = NULL;
    size_t read_len = 0;
    std::string delim = "\t\r\n <>()";

    int ret = getline(&line, &read_len, fp);
    if (ret == -1)
    {
        return -2;
    }
    size_t float_len = 0;
    std::vector<std::string> parts;
    SplitString(std::string(line), delim, parts);
    if(line)
        free(line);
    
    if (parts.size() != w * h * c)
    {  
        printf("Loaded %zu numbers in a line, expected (w, h, c) = (%d, %d, %d) = %d numbers.\n", parts.size(), w, h, c, w * h * c);
        return -1;
    } 
    for (int i = 0; i < w * h * c; ++i)
    {
        dst[i] = atof(parts[i].c_str());
    }
    return 0;
}

int compare_float_arrays()
{
    return 0;
}