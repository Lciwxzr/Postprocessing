#include <iostream>
#include "gromacs/fileio/xtcio.h"
#include "stdlib.h"
#include <vector>


int main()
{

    t_fileio   *xd;
    int         indent;
    char        buf[256];
    rvec       *x;
    matrix      box;
    int         nframe, natoms;
    int64_t     step;
    real        prec, time;
    gmx_bool    bOK;
    int criter;
    rvec * cor;
    std::vector<rvec*> cor_set;



    char fn[1000] ;
    std::cout<<"input the path of file :";
    std::cin >> fn;
//    cin.getline(fn, 6);
    xd = open_xtc(fn, "r");
    read_first_xtc(xd, &natoms, &step, &time, box, &x, &prec, &bOK);
    for (int iteror=0;iteror<natoms;iteror++)
    {
        cor_set.push_back(x+iteror);
    }

    criter = read_next_xtc(xd, natoms, &step, &time, box, x, &prec, &bOK) ;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
