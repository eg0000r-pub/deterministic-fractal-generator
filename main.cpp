#include <iostream>

#include "variations.h"

using namespace std;

//bool checkIntersections(Aggregate const & aggregate) {
//    for (unsigned i = 0; i < aggregate.size()-1; i ++)
//        for (unsigned j = i+1; j < aggregate.size(); j ++)
//            if ((aggregate[i]-aggregate[j]).norm() <= 0.01f) return true;
//    return false;
//}

int main() {
    int n_iter;
    char frac_type;
    string out_file;

    cout << "Number of algorithm iterations: ";
    cin >> n_iter;

    if (n_iter <= 0) {
        cerr << "The number of iterations must be greater than 0" << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter the output file name: ";
    cin >> out_file;

    if (out_file.size() < 4 || out_file.substr(out_file.size()-4, 4) != ".vtk")
        out_file += ".vtk";

    cout << "Select aggregate type (a-d): ";
    cin >> frac_type;

    Aggregate aggregate;
    switch (frac_type) {
        case 'a':
            aggregate = getAggregateTypeA(n_iter);
            break;
        case 'b':
            aggregate = getAggregateTypeB(n_iter);
            break;
        case 'c':
            aggregate = getAggregateTypeC(n_iter);
            break;
        case 'd':
            aggregate = getAggregateTypeD(n_iter);
            break;
        default:
            cerr << "Unrecognized aggregate type" << endl;
    }

    dumpVtk(aggregate, out_file.c_str());

    //auto aggregate = getAggregateTypeD(3);

//    if (checkIntersections(aggregate))
//        cout << "Intersections detected" << endl;

    //dumpVtk(aggregate, "test-aggregate.vtk");

    return 0;
}
