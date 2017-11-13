#ifndef HSVMASK_H
#define HSVMASK_H

typedef struct
{
    int h_min;
    int h_max;
    int s_min;
    int s_max;
    int v_min;
    int v_max;
    int active;
}HSVMask;

#endif // HSVMASK_H
