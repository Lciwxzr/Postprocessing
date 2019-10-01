#ifndef CAL_FUNC_H
#define CAL_FUNC_H


#include<stdlib.h>
#include<vector>
#include "gromacs/fileio/xtcio.h"

//input of the function means firstly analysis reference (coordinates of all atoms in the system)
//secondly the result cache which provides a type reference for the function

template <class T>
T count_value(const std::vector<rvec*> coor_set, const std::vector<int> index, T& res_temp)
{
    res_temp+= 1;

    return res_temp;
}
#endif // CAL_FUNC_H
