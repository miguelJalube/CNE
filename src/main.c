#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LAYERS 2
#define INPUTS 10

//  Compute neuron output
float compute(float *weights, float *inputs, size_t size, float (*activation)(float)){
    float sum = 0.0;
    for(size_t i = 0; i < size; ++i){
        sum += weights[i]*inputs[i];
    }
    return activation(sum);
}

//  Weights initialisation
void weights_init(float *weights, size_t size){
    static int seeded = 0;
    if(!seeded){
        srand(time(NULL));
        seeded = 1;
    }

    for(size_t i = 0; i < size; ++i){
        weights[i] = rand();
    }
}

size_t output_number(size_t layer, size_t nbLayers, size_t nbInputs) {
    size_t nbOutputs = nbInputs;
    
    for (int i = 2; i <= layer; ++i) {
        nbOutputs *= 2;
    }

    return nbOutputs * (2 * (layer == nbLayers));
}

int main(int argv, char **argc){
    float *weights[LAYERS];

    //  Allocate memory
    for(size_t i = 0; i < LAYERS; ++i){
        weights[i] = (float*) malloc(sizeof(float) * output_number(i, LAYERS, INPUTS));
    }

    //1.    Randomly initialize weights


    //2.    Compute the neuron’s output y for a given input vector x
    //      y = ∑jwjxj
    //3.    Update weights: Wj(t+1) = Wj(t) + η(d-y)x  //so-called delta rule
    //      d is the desired output and η is the learning rate, 0.0 < η < 1.0 
    //4.    Repeat 2 and 3 for a given number of steps or until the error 
    //      is smaller than a given threshold, i.e., error < 1/2 ∑p (yp-dp)2

    return EXIT_SUCCESS;
}