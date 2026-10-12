/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   IdFilter2
 * </summary>
 *
 * <description>
 *   This header describes the interface IFilter2
 * </description>
 *
 * <reference>
 *
 * </reference>
 *
 * <author>
 *   Copyright (c) 2018 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */

#ifndef __I_FILTER2_H__
#define __I_FILTER2_H__

#include "IEcoBase1.h"

/* IFilter2 IID = {75628C33-E1CC-4AC2-B9DA-DEA51CFA9C9A} */
#ifndef __IID_IFilter2
static const UGUID IID_IFilter2 = {0x01, 0x10, {0x75, 0x62, 0x8C, 0x33, 0xE1, 0xCC, 0x4A, 0xC2, 0xB9, 0xDA, 0xDE, 0xA5, 0x1C, 0xFA, 0x9C, 0x9A}};
#endif /* __IID_IFilter2 */

typedef struct IFilter2* IFilter2Ptr_t;

typedef struct IFilter2VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IFilter2Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IFilter2Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IFilter2Ptr_t me);

    /* IFilter2 */
    int16_t (ECOCALLMETHOD *Filter2)(/* in */ IFilter2Ptr_t me, 
                                     /* in */ uint32_t rows,
                                     /* in */ uint32_t cols,
                                     /* in */ const double* A,
                                     /* in */ uint32_t kernelRows,
                                     /* in */ uint32_t kernelCols,
                                     /* in */ const double* H,
                                     /* out */ double* B);

} IFilter2VTbl, *IFilter2VTblPtr_t;

interface IFilter2 {
    struct IFilter2VTbl *pVTbl;
} IFilter2;


#endif /* __I_FILTER2_H__ */

