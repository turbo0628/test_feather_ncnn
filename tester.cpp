#include <assert.h>
#include <stdio.h>
#include <string>

#include <ncnn/net.h>
#include <ncnn/mat.h>

#include "test_utils.h"

#include <feather/net.h>

int main(int argc, char*  argv[])
{
    assert(argc == 3);
    int w = 224;
    int h = 224;
    int c = 3;
    float* input_data = (float*) malloc(sizeof(float) * w * h * c);
    
    FillRandInputData(input_data, w * h *c, 1182591); //Magic number for pseudo random seed.
    onst char* input_name = "data";
    const char* output_name = "prob";
    ncnn::Net net_ncnn;
    // Initialize
    net_ncnn.load_param(argv[1]);
    net_ncnn.load_model(argv[2]);

    ncnn::Mat in(w, h, c, input_data); // input blob as above
    ncnn::Mat out;
    ncnn::Extractor ex = net_ncnn.create_extractor();

    ex.set_light_mode(true);
    ex.input(input_name, in);
    ex.extract(output_name, out);
    printf("ncnn out shape %d %d %d\n", out.c, out.h, out.w);
    net_ncnn.clear();


    feather::Net feather_net;
    feather_net.LoadParam(argv[1]);
    feather_net.LoadWeights(argv[2]);
    feather_net.FeedInput(input_name, in);
    feather_net.Forward();
    
    float* outp = NULL;
    int outn = 0;
    int outc = 0;
    int outh = 0;
    int outw = 0;
    feather_net.Extract(output_name, &outp, &outn, &outc, &outh, &outw);
    printf("feather out shape %d %d %d %d\n", outn, outc, outh, outw);

    for(int i = 0; i < 30; ++i)
    {
        printf("%f vs %f\n", outp[i], out[i]);
    }
    if (input_data)
        free(input_data);
    return 0;
}
