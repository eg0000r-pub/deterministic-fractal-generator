//
// Created by egor on 5/29/23.
//

#ifndef DETERMINISTIC_AGGREGATES_VARIATIONS_H
#define DETERMINISTIC_AGGREGATES_VARIATIONS_H

#include <FractalCommon/FractalCommon.h>

// Aggregate with Df = log(9)/log(3) = 2
// Particles can be represented with spheres of r=1
Aggregate getAggregateTypeA(int n_iter);

// NAMED FRACTAL:  3D Vicsek fractal
// Aggregate with Df = log(7)/log(3) = 1.7712
// Particles can be represented with spheres of r=1 or cubes with a=2
Aggregate getAggregateTypeB(int n_iter);

// NAMED FRACTAL: Menger sponge
// Aggregate with Df = log(20)/log(3) = 2.727
// Particles can be represented with spheres of r=1 or cubes with a=2
Aggregate getAggregateTypeC(int n_iter);

// NAMED FRACTAL: Sierpinski pyramid
// Aggregate with Df = log(4)/log(2) = 2
// Particles can be represented with spheres of r=1
Aggregate getAggregateTypeD(int n_iter);

#endif //DETERMINISTIC_AGGREGATES_VARIATIONS_H
