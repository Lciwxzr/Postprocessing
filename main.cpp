#include <iostream>
#include "gromacs/fileio/xtcio.h"

using namespace std;

int main()
{
    char f_name[1000];
//    cin >> f_name;
    cin.getline(f_name, 6);
    t_fileio* xtc_test;
    xtc_test = open_xtc(f_name, "r");
    cout << "Hello World!" << endl;
    return 0;
}
