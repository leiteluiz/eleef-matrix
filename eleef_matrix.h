#ifndef ELEEF_MATRIX_H_INCLUDED
#define ELEEF_MATRIX_H_INCLUDED

#include <stdlib.h>
#include <stdIO.h>
#include <malloc.h>

typedef struct
{
    int *data;
    int dim;
} eleef_vector;

typedef struct
{
    eleef_vector rows;
    int dim;
} eleef_matrix;

void eleef_init_vector(eleef_vector* v);

void eleef_destroy_vector(eleef_vector* v);

void eleef_set_dim_vector(eleef_vector* v, int dim);

void eleef_set_data_vector(eleef_vector* v, int index, int value);

eleef_vector eleef_sum_vector(eleef_vector* v1, eleef_vector* v2);

eleef_vector eleef_sub_vector(eleef_vector* v1, eleef_vector* v2);

//eleef_vector eleef_multiply_vector(eleef_vector* v1, eleef_vector* v2);

eleef_vector eleef_scalarmultiply_vector(eleef_vector* v, int scalar);

//eleef_vector eleef_scalrsum_vector(eleef_vector* v, int scalar);

//eleef_vector eleef_unity_vector(eleef_vector* v);

//int eleef_max_vector(eleef_vector* v);

//int eleef_min_vector(eleef_vector* v);

//int eleef_mean_vector(eleef_vector* v);

//eleef_vector* eleef_load_vector(eleef_vector* v);

void eleef_show_vector(eleef_vector* v);

#endif // ELEEF_MATRIX_H_INCLUDED
