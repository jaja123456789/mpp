#ifndef __H265E_ENCTROPY_H__
#define __H265E_ENCTROPY_H__
#include "mpp_bitwrite.h"
typedef struct H265eContextModel {
    RK_U8 m_state;  ///< internal state variable
    RK_U8 bBinsCoded;
} H265eContextModel_t;

typedef struct H265eCabacCtx {
    MppWriteCtx *m_bitIf;
    RK_U32      m_low;
    RK_U32      m_range;
    RK_U32      m_bufferedByte;
    RK_S32      m_numBufferedBytes;
    RK_S32      m_bitsLeft;
    RK_U64      m_fracBits;
    RK_U8       m_bIsCounter;
} H265eCabacCtx_t;

void h265e_cabac_init(H265eCabacCtx_t *cabac_ctx, MppWriteCtx * bitIf);
void h265e_reset_enctropy(void *slice_ctx);
void h265e_cabac_resetBits(H265eCabacCtx_t *cabac_ctx);
void h265e_cabac_encodeBin(H265eCabacCtx_t *cabac_ctx, H265eContextModel_t *ctxModel, RK_U32 binValue);
void h265e_cabac_encodeBinTrm(H265eCabacCtx_t *cabac_ctx, RK_U32 binValue);
void h265e_cabac_start(H265eCabacCtx_t *cabac_ctx);
void h265e_cabac_finish(H265eCabacCtx_t *cabac_ctx);
void h265e_cabac_flush(H265eCabacCtx_t *cabac_ctx);
#endif
