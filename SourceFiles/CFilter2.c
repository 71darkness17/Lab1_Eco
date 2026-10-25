/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CFilter2_D49144FE
 * </summary>
 *
 * <description>
 *   This source code describes the implementation of the interfaces for CFilter2_D49144FE
 * </description>
 *
 * <author>
 *   Copyright (c) 2018 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */


#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CFilter2.h"
#include "CCalculator.h"
#include "IEcoCalculator.h"

/*
 *
 * <summary>
 *   QueryInterface Function
 * </summary>
 *
 * <description>
 *   QueryInterface function for the IFilter2 interface
 * </description>
 *
 */
static int16_t ECOCALLMETHOD CFilter2_D49144FE_QueryInterface(/* in */ IFilter2Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CFilter2_D49144FE* pCMe = (CFilter2_D49144FE*)me;

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IFilter2)) {
        *ppv = &pCMe->m_pVTblIFilter2;
        pCMe->m_pVTblIFilter2->AddRef((IFilter2*)pCMe);
        return ERR_ECO_SUCCESS;
    }

    if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        if (pCMe->m_pIUnkInner != 0) {
            return pCMe->m_pIUnkInner->pVTbl->QueryInterface(pCMe->m_pIUnkInner, riid, ppv);
        }
        *ppv = &pCMe->m_pVTblIFilter2;
        pCMe->m_pVTblIFilter2->AddRef((IFilter2*)pCMe);
        return ERR_ECO_SUCCESS;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculator)) {
        if (pCMe->m_pIUnkInner == 0) {
            *ppv = 0;
            return ERR_ECO_NOINTERFACE;
        }
        return pCMe->m_pIUnkInner->pVTbl->QueryInterface(pCMe->m_pIUnkInner, riid, ppv);
    }

    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

/*
 *
 * <summary>
 *   AddRef Function
 * </summary>
 *
 * <description>
 *   AddRef function for the IFilter2 interface
 * </description>
 *
 */
static uint32_t ECOCALLMETHOD CFilter2_D49144FE_AddRef(/* in */ IFilter2Ptr_t me) {
    CFilter2_D49144FE* pCMe = (CFilter2_D49144FE*)me;

    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <summary>
 *   Release Function
 * </summary>
 *
 * <description>
 *   Release function for the IFilter2 interface
 * </description>
 *
 */
static uint32_t ECOCALLMETHOD CFilter2_D49144FE_Release(/* in */ IFilter2Ptr_t me) {
    CFilter2_D49144FE* pCMe = (CFilter2_D49144FE*)me;

    if (me == 0 ) {
        return -1;
    }

    --pCMe->m_cRef;
    if ( pCMe->m_cRef == 0 ) {
        if (pCMe->m_pIUnkInner != 0) {
            pCMe->m_pIUnkInner->pVTbl->Release(pCMe->m_pIUnkInner);
        }
        pCMe->Delete(pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <summary>
 *   Filter2 Function
 * </summary>
 *
 * <description>
 *   As Filter2 in MatLab with "same" argument
 * </description>
 *
 */
static double ECOCALLMETHOD CFilter2_D49144FE_CalcAdd(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return a + b;
}

static double ECOCALLMETHOD CFilter2_D49144FE_CalcSub(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return a - b;
}

static double ECOCALLMETHOD CFilter2_D49144FE_CalcMul(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return a * b;
}

static double ECOCALLMETHOD CFilter2_D49144FE_CalcDiv(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return (b == 0.0) ? 0.0 : a / b;
}

static int16_t ECOCALLMETHOD CFilter2_D49144FE_CalcQueryInterface(IEcoCalculatorPtr_t me, const UGUID* riid, void** ppv) {
    CFilter2_D49144FE* pCMe = (CFilter2_D49144FE*)me;

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculator)) {
        if (pCMe->m_pIUnkInner == 0) {
            *ppv = 0;
            return ERR_ECO_NOINTERFACE;
        }
        return pCMe->m_pIUnkInner->pVTbl->QueryInterface(pCMe->m_pIUnkInner, riid, ppv);
    }

    if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        if (pCMe->m_pIUnkInner == 0) {
            *ppv = 0;
            return ERR_ECO_NOINTERFACE;
        }
        return pCMe->m_pIUnkInner->pVTbl->QueryInterface(pCMe->m_pIUnkInner, riid, ppv);
    }

    if (IsEqualUGUID(riid, &IID_IFilter2)) {
        *ppv = &pCMe->m_pVTblIFilter2;
        pCMe->m_pVTblIFilter2->AddRef((IFilter2*)pCMe);
        return ERR_ECO_SUCCESS;
    }

    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

static uint32_t ECOCALLMETHOD CFilter2_D49144FE_CalcAddRef(IEcoCalculatorPtr_t me) {
    return CFilter2_D49144FE_AddRef((IFilter2Ptr_t)me);
}

static uint32_t ECOCALLMETHOD CFilter2_D49144FE_CalcRelease(IEcoCalculatorPtr_t me) {
    return CFilter2_D49144FE_Release((IFilter2Ptr_t)me);
}

static int16_t ECOCALLMETHOD CFilter2_D49144FE_Filter2(/* in */ IFilter2Ptr_t me, 
                                                       /* in */ uint32_t rows,
                                                       /* in */ uint32_t cols,
                                                       /* in */ const double* A,
                                                       /* in */ uint32_t kernelRows,
                                                       /* in */ uint32_t kernelCols,
                                                       /* in */ const double* H,
                                                       /* out */ double* B) {
    CFilter2_D49144FE* pCMe = (CFilter2_D49144FE*)me;
    int64_t centerRow, centerCol, sourceRow, sourceCol;
    double sum;
    uint32_t i, j, u, v;

    /* Pointer Validation */
    if (me == 0 || A == 0 || B == 0 || H == 0) {
        return ERR_ECO_POINTER;
    }

    if (rows == 0 || cols == 0 ||
        kernelRows == 0 || kernelCols == 0) {
        return ERR_ECO_INVALID_ARGUMENT;
    }

    centerRow = (int64_t)(kernelRows / 2);
    centerCol = (int64_t)(kernelCols / 2);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum = 0.0;

            for (u = 0; u < kernelRows; u++) {
                for (v = 0; v < kernelCols; v++) {
                    sourceRow = (int64_t)i + (int64_t)u - centerRow;
                    sourceCol = (int64_t)j + (int64_t)v - centerCol;

                    if (sourceRow >= 0 &&
                        sourceRow < (int64_t)rows &&
                        sourceCol >= 0 &&
                        sourceCol < (int64_t)cols) {

                        sum += H[u * kernelCols + v] *
                               A[sourceRow * cols + sourceCol];
                    }
                }
            }

            B[i * cols + j] = sum;
        }
    }

    return ERR_ECO_SUCCESS;
}




/*
 *
 * <summary>
 *   Init Function
 * </summary>
 *
 * <description>
 *   Instance initialization function
 * </description>
 *
 */
static int16_t ECOCALLMETHOD initCFilter2_D49144FE(/*in*/ CFilter2_D49144FEPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CFilter2_D49144FE* pCMe = (CFilter2_D49144FE*)me;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoUnknown* pOuterUnknown = (IEcoUnknown*)me;
    int16_t result = ERR_ECO_POINTER;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    if (me == 0) {
        return result;
    }

    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;
    pCMe->m_pIUnkInner = 0;

    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        return result;
    }

    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pCMe->m_pIMem);
    if (result != 0 || pCMe->m_pIMem == 0) {
        pIBus->pVTbl->Release(pIBus);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_Calculator, pOuterUnknown, &IID_IEcoUnknown, (void**)&pCMe->m_pIUnkInner);
    pIBus->pVTbl->Release(pIBus);

    if (result != 0 || pCMe->m_pIUnkInner == 0) {
        return ERR_ECO_NOINTERFACE;
    }

    return ERR_ECO_SUCCESS;
}

/*
 *
 * <summary>
 *   Create Function
 * </summary>
 *
 * <description>
 *   Instance creation function
 * </description>
 *
 */
static int16_t ECOCALLMETHOD createCFilter2_D49144FE(/* in */ CFilter2_D49144FEPtr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter) {
    (void)pIUnkOuter;
    if (pCMe == 0) {
        return ERR_ECO_POINTER;
    }
    return initCFilter2_D49144FE(pCMe, pIUnkSystem);
}

/*
 *
 * <summary>
 *   Delete Function
 * </summary>
 *
 * <description>
 *   Instance freeing function
 * </description>
 *
 */
static void ECOCALLMETHOD deleteCFilter2_D49144FE(/* in */ CFilter2_D49144FEPtr_t pCMe) {
    IEcoMemoryAllocator1* pIMem = 0;

    if (pCMe != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Freeing */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

/* IFilter2 Virtual Table */
IFilter2VTbl g_x75628C33E1CC4AC2B9DADEA51CFA9C9AVTbl_D49144FE = {
    CFilter2_D49144FE_QueryInterface,
    CFilter2_D49144FE_AddRef,
    CFilter2_D49144FE_Release,
    CFilter2_D49144FE_Filter2
};

IEcoCalculatorVTbl g_xIEcoCalculator_VTbl_D49144FE = {
    CFilter2_D49144FE_CalcQueryInterface,
    CFilter2_D49144FE_CalcAddRef,
    CFilter2_D49144FE_CalcRelease,
    CFilter2_D49144FE_CalcAdd,
    CFilter2_D49144FE_CalcSub,
    CFilter2_D49144FE_CalcMul,
    CFilter2_D49144FE_CalcDiv
};

/* Object Instance */
CFilter2_D49144FE g_xCFilter2_D49144FE = {
    &g_x75628C33E1CC4AC2B9DADEA51CFA9C9AVTbl_D49144FE,
    &g_xIEcoCalculator_VTbl_D49144FE,
    initCFilter2_D49144FE,
    createCFilter2_D49144FE,
    deleteCFilter2_D49144FE,
    1, /* m_cRef */
    0, /* m_pIMem */
    0, /* m_pISys */
    0, /* m_Name */
0  /* m_pIUnkInner */
};

typedef struct CFilter2Factory_D49144FE {
    IEcoComponentFactoryVTbl* m_pVTbl;
    uint32_t m_cRef;
    char_t* m_Name;
    char_t* m_Version;
    char_t* m_Manufacturer;
} CFilter2Factory_D49144FE;

static int16_t ECOCALLMETHOD CFilter2Factory_D49144FE_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoComponentFactory)) {
        *ppv = me;
        me->pVTbl->AddRef(me);
        return ERR_ECO_SUCCESS;
    }

    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

static uint32_t ECOCALLMETHOD CFilter2Factory_D49144FE_AddRef(IEcoComponentFactory* me) {
    CFilter2Factory_D49144FE* pCMe = (CFilter2Factory_D49144FE*)me;

    if (me == 0) {
        return (uint32_t)-1;
    }

    return ++pCMe->m_cRef;
}

static uint32_t ECOCALLMETHOD CFilter2Factory_D49144FE_Release(IEcoComponentFactory* me) {
    CFilter2Factory_D49144FE* pCMe = (CFilter2Factory_D49144FE*)me;

    if (me == 0) {
        return (uint32_t)-1;
    }

    --pCMe->m_cRef;
    if (pCMe->m_cRef == 0) {
        return 0;
    }

    return pCMe->m_cRef;
}

static int16_t ECOCALLMETHOD CFilter2Factory_D49144FE_Init(IEcoComponentFactory* me, IEcoUnknown* pISystem, void* pv) {
    (void)me;
    (void)pISystem;
    (void)pv;
    return ERR_ECO_SUCCESS;
}

static int16_t ECOCALLMETHOD CFilter2Factory_D49144FE_Alloc(IEcoComponentFactory* me,
                                                            IEcoUnknown* pISystem,
                                                            IEcoUnknown* pIUnknownOuter,
                                                            const UGUID* riid,
                                                            void** ppv) {
    CFilter2Factory_D49144FE* pCMe = (CFilter2Factory_D49144FE*)me;

    (void)pCMe;
    (void)pISystem;
    (void)pIUnknownOuter;

    if (ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IFilter2)) {
        *ppv = &g_xCFilter2_D49144FE;
        g_xCFilter2_D49144FE.Init(&g_xCFilter2_D49144FE, pISystem);
        ((IFilter2Ptr_t)*ppv)->pVTbl->AddRef((IFilter2Ptr_t)*ppv);
        return ERR_ECO_SUCCESS;
    }

    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

static char_t* ECOCALLMETHOD CFilter2Factory_D49144FE_get_Name(IEcoComponentFactory* me) {
    CFilter2Factory_D49144FE* pCMe = (CFilter2Factory_D49144FE*)me;
    if (me == 0) {
        return 0;
    }
    return pCMe->m_Name;
}

static char_t* ECOCALLMETHOD CFilter2Factory_D49144FE_get_Version(IEcoComponentFactory* me) {
    CFilter2Factory_D49144FE* pCMe = (CFilter2Factory_D49144FE*)me;
    if (me == 0) {
        return 0;
    }
    return pCMe->m_Version;
}

static char_t* ECOCALLMETHOD CFilter2Factory_D49144FE_get_Manufacturer(IEcoComponentFactory* me) {
    CFilter2Factory_D49144FE* pCMe = (CFilter2Factory_D49144FE*)me;
    if (me == 0) {
        return 0;
    }
    return pCMe->m_Manufacturer;
}

static IEcoComponentFactoryVTbl g_xFilter2Factory_D49144FE_VTbl = {
    CFilter2Factory_D49144FE_QueryInterface,
    CFilter2Factory_D49144FE_AddRef,
    CFilter2Factory_D49144FE_Release,
    CFilter2Factory_D49144FE_Alloc,
    CFilter2Factory_D49144FE_Init,
    CFilter2Factory_D49144FE_get_Name,
    CFilter2Factory_D49144FE_get_Version,
    CFilter2Factory_D49144FE_get_Manufacturer
};

static CFilter2Factory_D49144FE g_xFilter2Factory_D49144FE = {
    &g_xFilter2Factory_D49144FE_VTbl,
    1,
    (char_t*)"CFilter2",
    (char_t*)"1.0",
    (char_t*)"Vladimir Zavorokhin"
};

IEcoComponentFactory* GetIEcoComponentFactoryPtr_D49144FE(void) {
    return (IEcoComponentFactory*)&g_xFilter2Factory_D49144FE;
}
