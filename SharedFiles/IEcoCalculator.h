/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   IEcoCalculator
 * </summary>
 *
 * <description>
 *   Calculator interface aggregated into the Filter2 component.
 * </description>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Zavorokhin. All rights reserved.
 * </author>
 *
 */

#ifndef __I_ECO_CALCULATOR_H__
#define __I_ECO_CALCULATOR_H__

#include "IEcoBase1.h"

/* IEcoCalculator IID = {6F74D0D6-669A-4E99-AAAA-68F280C41948} */
#ifndef __IID_IEcoCalculator
static const UGUID IID_IEcoCalculator = {0x01, 0x10, {0x6F, 0x74, 0xD0, 0xD6, 0x66, 0x9A, 0x4E, 0x99, 0xAA, 0xAA, 0x68, 0xF2, 0x80, 0xC4, 0x19, 0x48}};
#endif /* __IID_IEcoCalculator */

typedef struct IEcoCalculator* IEcoCalculatorPtr_t;

typedef struct IEcoCalculatorVTbl {
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoCalculatorPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoCalculatorPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoCalculatorPtr_t me);

    double (ECOCALLMETHOD *Addition)(/* in */ IEcoCalculatorPtr_t me, /* in */ double a, /* in */ double b);
    double (ECOCALLMETHOD *Subtraction)(/* in */ IEcoCalculatorPtr_t me, /* in */ double a, /* in */ double b);
    double (ECOCALLMETHOD *Multiplication)(/* in */ IEcoCalculatorPtr_t me, /* in */ double a, /* in */ double b);
    double (ECOCALLMETHOD *Division)(/* in */ IEcoCalculatorPtr_t me, /* in */ double a, /* in */ double b);
} IEcoCalculatorVTbl, *IEcoCalculatorVTblPtr_t;

interface IEcoCalculator {
    struct IEcoCalculatorVTbl* pVTbl;
} IEcoCalculator;

#endif /* __I_ECO_CALCULATOR_H__ */
