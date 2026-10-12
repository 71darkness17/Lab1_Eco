/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   Lab1
 * </summary>
 *
 * <description>
 *   This source file is the entry point
 * </description>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IFilter2.h"
#include "CFilter2.h"

#include <math.h>
#include <stdio.h>

#define LOG_ERROR(args) do { \
        printf("[ERROR] %s:%d > ", __FILE_NAME__, __LINE__); \
        printf args; \
        printf("\n"); \
    } while(0)
#define VALIDATE_OR_GOTO(test, tag) do { \
    if(test) { \
        printf("[PASSED] %s\n", #test); \
    } else { \
        LOG_ERROR(("test %s failed", #test)); \
        goto tag; \
    } \
    } while(0)

extern CFilter2_D49144FE g_xCFilter2_D49144FE;

static int Filter2_TestArraysEqual(
    const double* actual,
    const double* expected,
    uint32_t count
) {
    uint32_t i;
    const double EPS = 1e-9;

    if (actual == 0 || expected == 0) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        if (!(fabs(actual[i] - expected[i]) <= EPS)) {
            return 0;
        }
    }

    return 1;
}


static int TestFilter2_IdentityKernel(IFilter2Ptr_t pIFilter2) {
    const double A[6] = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };

    const double H[1] = { 1.0 };

    const double expected[6] = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };

    double B[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    int16_t status;

    if (pIFilter2 == 0 ||
        pIFilter2->pVTbl == 0 ||
        pIFilter2->pVTbl->Filter2 == 0) {
        return 0;
    }

    status = pIFilter2->pVTbl->Filter2(
        pIFilter2,
        2, 3, A,
        1, 1, H,
        B
    );

    if (status != ERR_ECO_SUCCESS) {
        return 0;
    }

    return Filter2_TestArraysEqual(B, expected, 6);
}



static int TestFilter2_BoxKernel(IFilter2Ptr_t pIFilter2) {
    const double A[9] = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };

    const double H[9] = {
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0
    };

    const double expected[9] = {
        12.0, 21.0, 16.0,
        27.0, 45.0, 33.0,
        24.0, 39.0, 28.0
    };

    double B[9] = {
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0
    };

    int16_t status;

    if (pIFilter2 == 0 ||
        pIFilter2->pVTbl == 0 ||
        pIFilter2->pVTbl->Filter2 == 0) {
        return 0;
    }

    status = pIFilter2->pVTbl->Filter2(
        pIFilter2,
        3, 3, A,
        3, 3, H,
        B
    );

    if (status != ERR_ECO_SUCCESS) {
        return 0;
    }

    return Filter2_TestArraysEqual(B, expected, 9);
}


static int TestFilter2_AsymmetricKernel(IFilter2Ptr_t pIFilter2) {
    const double A[9] = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };

    const double H[3] = {
        1.0, 0.0, -1.0
    };

    const double expected[9] = {
        -2.0, -2.0,  2.0,
        -5.0, -2.0,  5.0,
        -8.0, -2.0,  8.0
    };

    double B[9] = {
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0
    };

    int16_t status;

    if (pIFilter2 == 0 ||
        pIFilter2->pVTbl == 0 ||
        pIFilter2->pVTbl->Filter2 == 0) {
        return 0;
    }

    status = pIFilter2->pVTbl->Filter2(
        pIFilter2,
        3, 3, A,
        1, 3, H,
        B
    );

    if (status != ERR_ECO_SUCCESS) {
        return 0;
    }

    return Filter2_TestArraysEqual(B, expected, 9);
}


static int TestFilter2_NullInput(IFilter2Ptr_t pIFilter2) {
    const double H[1] = { 1.0 };
    double B[4] = { 0.0, 0.0, 0.0, 0.0 };
    int16_t status;

    if (pIFilter2 == 0 ||
        pIFilter2->pVTbl == 0 ||
        pIFilter2->pVTbl->Filter2 == 0) {
        return 0;
    }

    status = pIFilter2->pVTbl->Filter2(
        pIFilter2,
        2, 2, 0,
        1, 1, H,
        B
    );

    return status == ERR_ECO_POINTER;
}


static int TestFilter2_ZeroRows(IFilter2Ptr_t pIFilter2) {
    const double A[4] = {
        1.0, 2.0,
        3.0, 4.0
    };

    const double H[1] = { 1.0 };
    double B[4] = { 0.0, 0.0, 0.0, 0.0 };
    int16_t status;

    if (pIFilter2 == 0 ||
        pIFilter2->pVTbl == 0 ||
        pIFilter2->pVTbl->Filter2 == 0) {
        return 0;
    }

    status = pIFilter2->pVTbl->Filter2(
        pIFilter2,
        0, 2, A,
        1, 1, H,
        B
    );

    return status == ERR_ECO_INVALID_ARGUMENT;
}


static int RunFilter2LoadTest(IFilter2Ptr_t pIFilter2,
                              IEcoMemoryAllocator1* pIMem,
                              uint32_t rows,
                              uint32_t cols,
                              uint32_t kernelRows,
                              uint32_t kernelCols,
                              uint32_t iterations,
                              const char* testName) {
    size_t elementCount;
    size_t kernelCount;
    size_t i;
    

    double* A = 0;
    double* B = 0;
    double H[25];

    uint32_t iteration;
    int16_t status;

    clock_t startTime;
    clock_t endTime;

    double totalMs;
    double averageMs;

    if (pIFilter2 == 0 ||
        pIFilter2->pVTbl == 0 ||
        pIFilter2->pVTbl->Filter2 == 0 ||
        rows == 0 ||
        cols == 0 ||
        kernelRows == 0 ||
        kernelCols == 0 ||
        kernelRows * kernelCols > 25 ||
        iterations == 0) {
        printf("[FAIL] %s: invalid parameters\n", testName);
        return 0;
    }

    elementCount = (size_t)rows * (size_t)cols;
    kernelCount = (size_t)kernelRows * (size_t)kernelCols;

    A = (double*)pIMem->pVTbl->Alloc(pIMem, elementCount * sizeof(double));
    B = (double*)pIMem->pVTbl->Alloc(pIMem, elementCount * sizeof(double));

    if (A == 0 || B == 0) {
        printf("[FAIL] %s: memory allocation failed\n", testName);

        pIMem->pVTbl->Free(pIMem, A);
        pIMem->pVTbl->Free(pIMem, B);

        return 0;
    }

    for (i = 0; i < elementCount; i++) {
        A[i] = (double)((int)(i % 101) - 50) / 10.0;
    }

    for (i = 0; i < kernelCount; i++) {
        H[i] = 1.0;
    }

    status = pIFilter2->pVTbl->Filter2(
        pIFilter2,
        rows,
        cols,
        A,
        kernelRows,
        kernelCols,
        H,
        B
    );

    if (status != ERR_ECO_SUCCESS) {
        printf("[FAIL] %s: warm-up call failed, code=%d\n",
               testName, (int)status);

        pIMem->pVTbl->Free(pIMem, A);
        pIMem->pVTbl->Free(pIMem, B);

        return 0;
    }

    startTime = clock();

    if (startTime == (clock_t)-1) {
        printf("[FAIL] %s: clock() failed\n", testName);

        pIMem->pVTbl->Free(pIMem, A);
        pIMem->pVTbl->Free(pIMem, B);

        return 0;
    }

    for (iteration = 0; iteration < iterations; iteration++) {
        status = pIFilter2->pVTbl->Filter2(
            pIFilter2,
            rows,
            cols,
            A,
            kernelRows,
            kernelCols,
            H,
            B
        );

        if (status != ERR_ECO_SUCCESS) {
            printf("[FAIL] %s: Filter2 returned %d\n",
                   testName, (int)status);

            pIMem->pVTbl->Free(pIMem, A);
            pIMem->pVTbl->Free(pIMem, B);

            return 0;
        }
    }

    endTime = clock();

    if (endTime == (clock_t)-1) {
        printf("[FAIL] %s: clock() failed\n", testName);

        pIMem->pVTbl->Free(pIMem, A);
        pIMem->pVTbl->Free(pIMem, B);

        return 0;
    }

    totalMs =
        ((double)(endTime - startTime) * 1000.0) /
        (double)CLOCKS_PER_SEC;

    averageMs = totalMs / (double)iterations;

    printf("\n[LOAD PASS] %s\n", testName);
    printf("Matrix: %u x %u\n", rows, cols);
    printf("Kernel: %u x %u\n", kernelRows, kernelCols);
    printf("Iterations: %u\n", iterations);
    printf("Total CPU time: %.3f ms\n", totalMs);
    printf("Average CPU time: %.3f ms/call\n", averageMs);

    pIMem->pVTbl->Free(pIMem, A);
    pIMem->pVTbl->Free(pIMem, B);

    return 1;
}

static int TestFilter2_LoadMedium(IFilter2Ptr_t pIFilter2, IEcoMemoryAllocator1* pIMem) {
    return RunFilter2LoadTest(
        pIFilter2, pIMem,
        512, 512,
        3, 3,
        20,
        "Medium load test"
    );
}

static int TestFilter2_LoadHeavy(IFilter2Ptr_t pIFilter2, IEcoMemoryAllocator1* pIMem) {
    return RunFilter2LoadTest(
        pIFilter2, pIMem,
        1024, 1024,
        5, 5,
        3,
        "Heavy load test"
    );
}

int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Pointer to the system interface */
    IEcoSystem1* pISys = 0;
    /* Pointer to the interface for working with the system interface bus */
    IEcoInterfaceBus1* pIBus = 0;
    /* Pointer to the memory management interface */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;

    IFilter2Ptr_t pIFilter = 0;

    /* System interface check and creation */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Free the system interface in case of an error */
            goto Release;
        }
    }

    /* Getting the interface for working with the interface bus */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Free in case of an error */
        goto Release;
    }
    /* Getting the memory management interface */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Check */
    if (result != 0 || pIMem == 0) {
        /* Free the system interface in case of an error */
        goto Release;
    }

    /* Memory block allocation */
    name = (char_t *)pIMem->pVTbl->Alloc(pIMem, 10);

    /* Fill the memory block */
    pIMem->pVTbl->Fill(pIMem, name, 'a', 9);


    /* Free the memory block */
    pIMem->pVTbl->Free(pIMem, name);

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_Filter2, (IEcoUnknown*)GetIEcoComponentFactoryPtr_D49144FE());
    if (result != 0) {
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_Filter2, 0, &IID_IFilter2, (void**) &pIFilter);
    if (result != 0 || pIFilter == 0) {
        goto Release;
    }

    /* Unit Tests */
    VALIDATE_OR_GOTO(TestFilter2_IdentityKernel(pIFilter), Release);
    VALIDATE_OR_GOTO(TestFilter2_AsymmetricKernel(pIFilter), Release);
    VALIDATE_OR_GOTO(TestFilter2_BoxKernel(pIFilter), Release);
    VALIDATE_OR_GOTO(TestFilter2_NullInput(pIFilter), Release);
    VALIDATE_OR_GOTO(TestFilter2_ZeroRows(pIFilter), Release);

    /* Load Tests */
    VALIDATE_OR_GOTO(TestFilter2_LoadMedium(pIFilter, pIMem), Release);
    VALIDATE_OR_GOTO(TestFilter2_LoadHeavy(pIFilter, pIMem), Release);
    

Release:

    if (pIFilter != 0) {
        pIFilter->pVTbl->Release(pIFilter);
    }

    /* Free the interface for working with the interface bus */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Free the memory management interface */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }


    /* Free the system interface */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}
