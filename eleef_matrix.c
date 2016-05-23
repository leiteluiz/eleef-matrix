#include "eleef_matrix.h"

void eleef_init_vector(eleef_vector* v)
{
    v->dim = 0;
    v->data = NULL;
}

void eleef_destroy_vector(eleef_vector* v)
{
    v->dim = 0;
    free(v->data);
    v->data = NULL;
}

void eleef_set_dim_vector(eleef_vector* v, int dim)
{
    if(v->dim == 0)
    {
        v->dim = dim;
        v->data = malloc(dim * sizeof(int));
        if(!v->data)
        {
            printf("ERROR(001):FAILED TO ALLOCATE MEMORY");
            return;
        }
    }

    else
    {
        free(v->data);
        v->data = NULL;
        v->dim = dim;
        v->data = malloc(dim * sizeof(int));
        if(!v->data)
        {
            printf("ERROR(001):FAILED TO ALLOCATE MEMORY");
            return;
        }
    }
}

void eleef_set_data_vector(eleef_vector* v, int index, int value)
{
    if(index>=0 && index<v->dim)
    {
        v->data[index] = value;
    }
    else
    {
        printf("ERROR(002):INVALID INDEX OF VECTOR");
        return;
    }
}

eleef_vector eleef_sum_vector(eleef_vector* v1, eleef_vector* v2)
{
    int i;
    eleef_vector vr;
    eleef_init_vector(&vr);
    if(v1->dim == v2->dim)
    {

        eleef_set_dim_vector(&vr, v1->dim);
        for(i=0; i<v1->dim; i++){
            vr.data[i] = v1->data[i]+v2->data[i];
        }
    }
    else
    {
        printf("ERROR(003):DIFFERENT SIZE OF VECTOR");
    }
    return vr;
}

eleef_vector eleef_sub_vector(eleef_vector* v1, eleef_vector* v2)
{
    int i;
    eleef_vector vr;
    eleef_init_vector(&vr);
    if(v1->dim == v2->dim)
    {

        eleef_set_dim_vector(&vr, v1->dim);
        for(i=0; i<v1->dim; i++){
            vr.data[i] = v1->data[i]-v2->data[i];
        }
    }
    else
    {
        printf("ERROR(003):DIFFERENT SIZE OF VECTOR");
    }
    return vr;
}

eleef_vector eleef_scalarmultiply_vector(eleef_vector* v, int scalar)
{
    int i;
    eleef_vector vr;
    eleef_init_vector(&vr);

    if(v->dim<=0)
    {
        printf("[EMPTY VECTOR]");
        return vr;
    }
    else
    {
        eleef_set_dim_vector(&vr, v->dim);
        for(i=0; i<v->dim; i++)
        {
            vr.data[i] = v->data[i]*scalar;
        }
        return vr;
    }
}

void eleef_show_vector(eleef_vector* v)
{
    int i;
    if(v->dim <= 0)
    {
        printf("[EMPTY VECTOR]");
        return;
    }
    else
    {
        printf("[ ");
        for(i=0; i<v->dim; i++)
        {
            printf("%d ", v->data[i]);
        }
        printf("]");
    }
}
