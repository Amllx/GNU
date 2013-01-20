/*** Autogenerated by WIDL 1.5.22 from include/wmcodecdsp.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __wmcodecdsp_h__
#define __wmcodecdsp_h__

/* Forward declarations */

#ifndef __IWMValidate_FWD_DEFINED__
#define __IWMValidate_FWD_DEFINED__
typedef interface IWMValidate IWMValidate;
#endif

/* Headers for imported files */

#include <mediaobj.h>
#include <strmif.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IWMValidate interface
 */
#ifndef __IWMValidate_INTERFACE_DEFINED__
#define __IWMValidate_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWMValidate, 0xcee3def2, 0x3808, 0x414d, 0xbe,0x66, 0xfa,0xfd,0x47,0x22,0x10,0xbc);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("cee3def2-3808-414d-be66-fafd472210bc")
IWMValidate : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetIdentifier(
        GUID guidValidationID) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWMValidate, 0xcee3def2, 0x3808, 0x414d, 0xbe,0x66, 0xfa,0xfd,0x47,0x22,0x10,0xbc)
#endif
#else
typedef struct IWMValidateVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWMValidate* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWMValidate* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWMValidate* This);

    /*** IWMValidate methods ***/
    HRESULT (STDMETHODCALLTYPE *SetIdentifier)(
        IWMValidate* This,
        GUID guidValidationID);

    END_INTERFACE
} IWMValidateVtbl;
interface IWMValidate {
    CONST_VTBL IWMValidateVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWMValidate_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWMValidate_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWMValidate_Release(This) (This)->lpVtbl->Release(This)
/*** IWMValidate methods ***/
#define IWMValidate_SetIdentifier(This,guidValidationID) (This)->lpVtbl->SetIdentifier(This,guidValidationID)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IWMValidate_QueryInterface(IWMValidate* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IWMValidate_AddRef(IWMValidate* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IWMValidate_Release(IWMValidate* This) {
    return This->lpVtbl->Release(This);
}
/*** IWMValidate methods ***/
static FORCEINLINE HRESULT IWMValidate_SetIdentifier(IWMValidate* This,GUID guidValidationID) {
    return This->lpVtbl->SetIdentifier(This,guidValidationID);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IWMValidate_SetIdentifier_Proxy(
    IWMValidate* This,
    GUID guidValidationID);
void __RPC_STUB IWMValidate_SetIdentifier_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IWMValidate_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __wmcodecdsp_h__ */
