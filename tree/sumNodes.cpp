#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
 
int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int elem;
    set<int, greater<int> > tree;
    while(fin >> elem) tree.insert(elem);

    double sum = 0;
    for(set<int, greater<int> >::iterator itr = tree.begin(); itr != tree.end(); itr++) sum += *itr;

    fout << fixed << setprecision(0) << sum << std::endl;
    return 0;
}
