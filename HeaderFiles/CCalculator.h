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
 *   Calculator component used by Filter2 via aggregation.
 * </description>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */

#ifndef __C_CALCULATOR_H__
#define __C_CALCULATOR_H__

#include "IEcoCalculator.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

#ifndef __CID_Calculator
static const UGUID CID_Calculator = {0x01, 0x10, {0x2D, 0xB5, 0x9A, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
#endif /* __CID_Calculator */

extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_Calculator(void);

typedef struct CCalculator_2DB59A22* CCalculator_2DB59A22Ptr_t;

typedef struct CCalculator_2DB59A22 {
    IEcoCalculatorVTbl* m_pVTblIEcoCalculator;
    IEcoUnknownVTbl* m_pVTblINondelegatingUnk;

    int16_t (ECOCALLMETHOD *Init)(/*in*/ CCalculator_2DB59A22Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem);
    int16_t (ECOCALLMETHOD *Create)(/*in*/ CCalculator_2DB59A22Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter);
    void (ECOCALLMETHOD *Delete)(/*in*/ CCalculator_2DB59A22Ptr_t pCMe);

    uint32_t m_cRef;
    IEcoMemoryAllocator1* m_pIMem;
    IEcoSystem1* m_pISys;
    char_t* m_Name;
    IEcoUnknown* m_pIUnkOuter;
} CCalculator_2DB59A22;

#endif /* __C_CALCULATOR_H__ */
