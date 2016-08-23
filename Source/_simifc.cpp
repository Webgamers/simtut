// *************************************************************************************************************
//
//  Modul-Name     : _simifc.cpp
//
//  Copyrights by Hans-Juergen Lange <hjl@simulated-universe.de>. All rights reserved.
//
// *************************************************************************************************************
#include <simifc.h>
#include <stdint.h>
#include <stdlib.h>
#include <simobjfactory.h>
#include <vector>
#include <map>
#include <string>
#ifdef __linux__
#include <pthread.h>
#endif
#include <set>
#include "ids.h"
#include "tMsgDeleteReq.h"
#include "tMsgDeleteReply.h"
#include "tSigDeleteIndication.h"
#include "tSigDeleteConfirm.h"
//
//                       M o d e l   i n c l u d e s
#include "tMsgCreatePlayerReq.h"
#include "tMsgCreatePlayerReply.h"

#include "CPlayerViewport.h"
#include "CGameViewport.h"
//
//            S t a t i c   F u n c t i o n    p r o t o t y p e s
//
//
tSimObj* createobj(typeid_t  tid, objectid_t  oid) ;
// **************************************************************************
//
//  Method-Name   : siminit()
//
//  Generated source code.
//
// **************************************************************************
void siminit(void) {


    addsimobjfactory(&cplayerviewport_factory);
    addsimobjfactory(&cgameviewport_factory);
}
// **************************************************************************
//
//  Method-Name   : create_msg()
//
//  Generated source code.
//
// **************************************************************************
tMsg* create_msg(uint64_t  msgid, void*  dst, void*  src) {
    tMsg *retval;

    switch (msgid) {
    case IDM_DELETEREQ:
        retval = (tMsg*)new tMsgDeleteReq;
        retval->id=msgid;
        retval->type = MSG_TYPE_REQUEST;
        break;
    case IDM_DELETEREPLY:
        retval = (tMsg*)new tMsgDeleteReply;
        retval->id=msgid;
        retval->type = MSG_TYPE_REPLY;
        break;
    case IDM_CREATEPLAYERREQ:
        retval = (tMsg*)new tMsgCreatePlayerReq;
        retval->id=msgid;
        retval->type = MSG_TYPE_REQUEST;
        break;
    case IDM_CREATEPLAYERREPLY:
        retval = (tMsg*)new tMsgCreatePlayerReply;
        retval->id=msgid;
        retval->type = MSG_TYPE_REPLY;
        break;
    default:
        retval = 0;
        break;
    }
    retval->src=src;
    retval->dst=dst;
    return (retval);
}
// **************************************************************************
//
//  Method-Name   : create_sig()
//
//  Generated source code.
//
// **************************************************************************
tSig* create_sig(uint64_t  sigid, void*  dst, void*  src) {
    tSig *retval;

    switch (sigid) {
    case IDS_DELETEINDICATION:
        retval = (tSig*)new tSigDeleteIndication;
        retval->id=sigid;
        retval->type = MSG_TYPE_INDICATION;
        break;
    case IDS_DELETECONFIRM:
        retval = (tSig*)new tSigDeleteConfirm;
        retval->id=sigid;
        retval->type = MSG_TYPE_CONFIRM;
        break;
    default:
        retval = 0;
        break;
    }
    retval->src=src;
    retval->dst=dst;
    return (retval);
}
