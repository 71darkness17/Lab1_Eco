/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CFilter2
 * </summary>
 *
 * <description>
 *   This header describes the implementation of the CFilter2 component
 * </description>
 *
 * <author>
 *   Copyright (c) 2018 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */

#ifndef __C_FILTER2_H__
#define __C_FILTER2_H__

#include "IFilter2.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoCalculator.h"

#ifndef __CID_Filter2
static const UGUID CID_Filter2 = {0x01, 0x10, {0xD4, 0x91, 0x44, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
#endif /* __CID_Filter2 */

extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_D49144FE(void);

typedef struct CFilter2_D49144FE* CFilter2_D49144FEPtr_t;

typedef struct CFilter2_D49144FE {

    /* IFilter2 interface function table */
    IFilter2VTbl* m_pVTblIFilter2;
    /* Aggregated calculator interface */
    IEcoCalculatorVTbl* m_pVTblIEcoCalculator;

    /* Instance initialization */
    int16_t (ECOCALLMETHOD *Init)(/*in*/ CFilter2_D49144FEPtr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem);
    /* Instance creation */
    int16_t (ECOCALLMETHOD *Create)(/*in*/ CFilter2_D49144FEPtr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter);
    /* Deletion */
    void (ECOCALLMETHOD *Delete)(/*in*/ CFilter2_D49144FEPtr_t pCMe);

    /* Reference counter */
    uint32_t m_cRef;

    /* Interface for memory operations */
    IEcoMemoryAllocator1* m_pIMem;

    /* System interface */
    IEcoSystem1* m_pISys;

    /* Instance data */
    char_t* m_Name;

    /* Aggregated calculator component as IEcoUnknown for true aggregation */
    IEcoUnknown* m_pIUnkInner;

} CFilter2_D49144FE;

#endif /* __C_FILTER2_H__ */
