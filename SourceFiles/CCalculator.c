/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CCalculator
 * </summary>
 *
 * <description>
 *   Independent calculator component with aggregated interface support.
 * </description>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CCalculator.h"

static double ECOCALLMETHOD CCalculator_Add(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return a + b;
}

static double ECOCALLMETHOD CCalculator_Sub(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return a - b;
}

static double ECOCALLMETHOD CCalculator_Mul(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return a * b;
}

static double ECOCALLMETHOD CCalculator_Div(IEcoCalculatorPtr_t me, double a, double b) {
    (void)me;
    return (b == 0.0) ? 0.0 : a / b;
}

static int16_t ECOCALLMETHOD CCalculator_QueryInterface(IEcoCalculatorPtr_t me, const UGUID* riid, void** ppv) {
    CCalculator_2DB59A22* pCMe = (CCalculator_2DB59A22*)me;

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculator)) {
        *ppv = &pCMe->m_pVTblIEcoCalculator;
        pCMe->m_pVTblIEcoCalculator->AddRef((IEcoCalculator*)pCMe);
        return ERR_ECO_SUCCESS;
    }

    if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        if (pCMe->m_pIUnkOuter != 0) {
            return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
        }
        *ppv = &pCMe->m_pVTblINondelegatingUnk;
        pCMe->m_pVTblINondelegatingUnk->AddRef((IEcoUnknown*)pCMe);
        return ERR_ECO_SUCCESS;
    }

    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

static uint32_t ECOCALLMETHOD CCalculator_AddRef(IEcoCalculatorPtr_t me) {
    CCalculator_2DB59A22* pCMe = (CCalculator_2DB59A22*)me;
    if (me == 0) return (uint32_t)-1;
    return ++pCMe->m_cRef;
}

static uint32_t ECOCALLMETHOD CCalculator_Release(IEcoCalculatorPtr_t me) {
    CCalculator_2DB59A22* pCMe = (CCalculator_2DB59A22*)me;
    if (me == 0) return (uint32_t)-1;
    --pCMe->m_cRef;
    if (pCMe->m_cRef == 0) {
        pCMe->Delete(pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

static int16_t ECOCALLMETHOD initCCalculator_2DB59A22(/*in*/ CCalculator_2DB59A22Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CCalculator_2DB59A22* pCMe = (CCalculator_2DB59A22*)me;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    int16_t result = ERR_ECO_POINTER;

    if (me == 0 || pIUnkSystem == 0) {
        return result;
    }

    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    if (result != 0 || pIBus == 0) {
        return result;
    }

    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**)&pCMe->m_pIMem);
    pIBus->pVTbl->Release(pIBus);

    if (result != 0 || pCMe->m_pIMem == 0) {
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    return ERR_ECO_SUCCESS;
}

static int16_t ECOCALLMETHOD createCCalculator_2DB59A22(/* in */ CCalculator_2DB59A22Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter) {
    if (pCMe == 0) {
        return ERR_ECO_POINTER;
    }
    pCMe->m_pIUnkOuter = pIUnkOuter;
    return initCCalculator_2DB59A22(pCMe, pIUnkSystem);
}

static void ECOCALLMETHOD deleteCCalculator_2DB59A22(/* in */ CCalculator_2DB59A22Ptr_t pCMe) {
    IEcoMemoryAllocator1* pIMem = 0;

    if (pCMe != 0) {
        pIMem = pCMe->m_pIMem;
        if (pCMe->m_Name != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        if (pIMem != 0) {
            pIMem->pVTbl->Release(pIMem);
        }
    }
}

static IEcoCalculatorVTbl g_xIEcoCalculator_VTbl_2DB59A22 = {
    CCalculator_QueryInterface,
    CCalculator_AddRef,
    CCalculator_Release,
    CCalculator_Add,
    CCalculator_Sub,
    CCalculator_Mul,
    CCalculator_Div
};

static IEcoUnknownVTbl g_xIEcoUnknown_VTbl_NonDelegating_2DB59A22 = {
    CCalculator_QueryInterface,
    CCalculator_AddRef,
    CCalculator_Release
};

CCalculator_2DB59A22 g_xCCalculator_2DB59A22 = {
    &g_xIEcoCalculator_VTbl_2DB59A22,
    &g_xIEcoUnknown_VTbl_NonDelegating_2DB59A22,
    initCCalculator_2DB59A22,
    createCCalculator_2DB59A22,
    deleteCCalculator_2DB59A22,
    1,
    0,
    0,
    0,
    0
};

typedef struct CCalculatorFactory_2DB59A22 {
    IEcoComponentFactoryVTbl* m_pVTbl;
    uint32_t m_cRef;
    char_t* m_Name;
    char_t* m_Version;
    char_t* m_Manufacturer;
} CCalculatorFactory_2DB59A22;

static int16_t ECOCALLMETHOD CCalculatorFactory_2DB59A22_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
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

static uint32_t ECOCALLMETHOD CCalculatorFactory_2DB59A22_AddRef(IEcoComponentFactory* me) {
    CCalculatorFactory_2DB59A22* pCMe = (CCalculatorFactory_2DB59A22*)me;
    if (me == 0) return (uint32_t)-1;
    return ++pCMe->m_cRef;
}

static uint32_t ECOCALLMETHOD CCalculatorFactory_2DB59A22_Release(IEcoComponentFactory* me) {
    CCalculatorFactory_2DB59A22* pCMe = (CCalculatorFactory_2DB59A22*)me;
    if (me == 0) return (uint32_t)-1;
    --pCMe->m_cRef;
    if (pCMe->m_cRef == 0) return 0;
    return pCMe->m_cRef;
}

static int16_t ECOCALLMETHOD CCalculatorFactory_2DB59A22_Init(IEcoComponentFactory* me, IEcoUnknown* pISystem, void* pv) {
    (void)me; (void)pISystem; (void)pv;
    return ERR_ECO_SUCCESS;
}

static int16_t ECOCALLMETHOD CCalculatorFactory_2DB59A22_Alloc(IEcoComponentFactory* me,
                                                                  IEcoUnknown* pISystem,
                                                                  IEcoUnknown* pIUnknownOuter,
                                                                  const UGUID* riid,
                                                                  void** ppv) {
    (void)me; (void)pISystem; (void)pIUnknownOuter;
    if (ppv == 0) return ERR_ECO_POINTER;

    if (IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoCalculator)) {
        *ppv = &g_xCCalculator_2DB59A22;
        ((IEcoCalculatorPtr_t)*ppv)->pVTbl->AddRef((IEcoCalculatorPtr_t)*ppv);
        return ERR_ECO_SUCCESS;
    }

    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

static char_t* ECOCALLMETHOD CCalculatorFactory_2DB59A22_get_Name(IEcoComponentFactory* me) {
    CCalculatorFactory_2DB59A22* pCMe = (CCalculatorFactory_2DB59A22*)me;
    if (me == 0) return 0;
    return pCMe->m_Name;
}

static char_t* ECOCALLMETHOD CCalculatorFactory_2DB59A22_get_Version(IEcoComponentFactory* me) {
    CCalculatorFactory_2DB59A22* pCMe = (CCalculatorFactory_2DB59A22*)me;
    if (me == 0) return 0;
    return pCMe->m_Version;
}

static char_t* ECOCALLMETHOD CCalculatorFactory_2DB59A22_get_Manufacturer(IEcoComponentFactory* me) {
    CCalculatorFactory_2DB59A22* pCMe = (CCalculatorFactory_2DB59A22*)me;
    if (me == 0) return 0;
    return pCMe->m_Manufacturer;
}

static IEcoComponentFactoryVTbl g_xCalculatorFactory_2DB59A22_VTbl = {
    CCalculatorFactory_2DB59A22_QueryInterface,
    CCalculatorFactory_2DB59A22_AddRef,
    CCalculatorFactory_2DB59A22_Release,
    CCalculatorFactory_2DB59A22_Alloc,
    CCalculatorFactory_2DB59A22_Init,
    CCalculatorFactory_2DB59A22_get_Name,
    CCalculatorFactory_2DB59A22_get_Version,
    CCalculatorFactory_2DB59A22_get_Manufacturer
};

static CCalculatorFactory_2DB59A22 g_xCalculatorFactory_2DB59A22 = {
    &g_xCalculatorFactory_2DB59A22_VTbl,
    1,
    (char_t*)"CCalculator",
    (char_t*)"1.0",
    (char_t*)"Vladimir Zavorokhin"
};

IEcoComponentFactory* GetIEcoComponentFactoryPtr_Calculator(void) {
    return (IEcoComponentFactory*)&g_xCalculatorFactory_2DB59A22;
}
