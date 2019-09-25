#include <iostream>
#include "gromacs/fileio/xtcio.h"
#include "stdlib.h"
#include <vector>
#include "cal_func.h"



int main()
{

    t_fileio   *xd;
    rvec       *x;
    matrix      box;
    int          natoms;
    int64_t     step;
    real        prec, time;
    gmx_bool    bOK;
    int criter;
    std::vector<rvec*> coor_set;
    std::vector<float> result;
//    you need to edit the type of the two result cache variable in order to fit your own needs
    float res_temp, res_cache;
    res_temp = 0;



    char fn[1000] ;
    std::cout<<"input the path of file :";
    std::cin >> fn;
//    cin.getline(fn, 6);
    xd = open_xtc(fn, "r");
    read_first_xtc(xd, &natoms, &step, &time, box, &x, &prec, &bOK);
    coor_set.reserve(natoms);
    for (int iteror=0;iteror<natoms;iteror++)
    {
        coor_set.push_back(x+iteror);
    }
    do{
        res_cache = count_value(coor_set, res_temp);
        result.push_back(res_cache);
        criter = read_next_xtc(xd, natoms, &step, &time, box, x, &prec, &bOK) ;
    }while(criter!=0);
    std::cout << "Hello World!" << std::endl;
    return 0;
}


