#include "../include/instrumentation.h"
#include "../include/recursive_selector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    parse_args(argc, argv, &opt);

    // malloc with opt.size+1 for heapsort
    vet = (int *)malloc((opt.size + 1) * sizeof(int));

    // initialize
    resetcounter(&s);
    srand48(opt.seed);
    initVector(vet, opt.size);
    vet[opt.size] = vet[0]; // for heapsort

    retp = clock_gettime(CLOCK_MONOTONIC, &inittp);
    switch (opt.alg)
    {
    case ALGRECSEL:
        recursiveSelectionSort(vet, 0, opt.size - 1, &s);
        break;
    }
    retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
    clkDiff(inittp, endtp, &restp);
    sprintf(pref, "alg %s seed %d size %d time %ld.%.9ld",
            num2name(opt.alg),
            opt.seed, opt.size,
            restp.tv_sec, restp.tv_nsec);
    printsortperf(&s, buf, pref);
    printf("%s\n", buf);

    return 0
}
