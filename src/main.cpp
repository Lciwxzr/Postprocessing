#include <iostream>
#include "gromacs/fileio/xtcio.h"
#include "stdlib.h"
#include <vector>
#include "cal_func.h"
#include "gromacs/topology/index.h"



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
    std::vector<std::vector<rvec*>> coor_set_time;
    std::vector<float> result;
//    you need to edit the type of the two result cache variable in order to fit your own needs
    float res_temp, res_cache;
    res_temp = 0;


    //    code below is for reading index


        int *index, isize;
        char n_file[1000];
        char *grpname;


        std::cout<<"input the ndx file to read:\n";
        std::cin>>n_file;




        rd_index(n_file, 1, &isize, &index, &grpname);

        std::vector<int> group_index_vec;


        for(int iteror=0; iteror<isize; iteror++)
        {
            group_index_vec.push_back(*(index+iteror));

        }

    //    code above can generate a set of index which give a reference to atoms for analysis




//code below is for reading coordinate info and get result

    char fn[1000] ;
    std::cout<<"input the path of file :\n";
    std::cin >> fn;
    xd = open_xtc(fn, "r");
    read_first_xtc(xd, &natoms, &step, &time, box, &x, &prec, &bOK);

    do{
        for (int iteror=0;iteror<natoms;iteror++)
        {
            coor_set.push_back(x+iteror);
        }
        coor_set_time.push_back(coor_set);
        res_cache = count_value(coor_set, group_index_vec, res_temp);

        result.push_back(res_cache);
        for (int iteror=0;iteror<natoms;iteror++)
        {
            coor_set.pop_back();
        }

        x = new rvec[natoms];
        criter = read_next_xtc(xd, natoms, &step, &time, box, x, &prec, &bOK) ;
    }while(criter!=0);

//    code above is for frame reading and getting coordinate info of single atom



    std::cout<<"line for debug stoppoint";

    return 0;
}


