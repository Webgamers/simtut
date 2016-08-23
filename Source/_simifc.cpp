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
#include "tMsgPlayerHolidayReq.h"
#include "tMsgPlayerHolidayReply.h"

#include "CGameViewport.h"
#include "CPlayerViewport.h"
//
//            S t a t i c   F u n c t i o n    p r o t o t y p e s
//
//
tSimObj* createobj(typeid_t  tid, objectid_t  oid) ;
// **************************************************************************
//
//  Method-Name   : msg_from_json_createplayerreq()
//
//  Generated source code.
//
// **************************************************************************
static tMsg* msg_from_json_createplayerreq(tJSON*  json) {
    tMsgCreatePlayerReq* newsig=(tMsgCreatePlayerReq*)create_msg(IDM_CREATEPLAYERREQ);
    tJSON *j;

    j=find(json, "Name");
    if (j!=0) {
        newsig->Name=to_string(j);
    }
    j=find(json, "Email");
    if (j!=0) {
        newsig->Email=to_string(j);
    }
    j=find(json, "Passwort");
    if (j!=0) {
        newsig->Passwort=to_string(j);
    }
    return ((tMsg*)(newsig));
}
// **************************************************************************
//
//  Method-Name   : msg_from_json_playerholidayreq()
//
//  Generated source code.
//
// **************************************************************************
static tMsg* msg_from_json_playerholidayreq(tJSON*  json) {
    tMsgPlayerHolidayReq* newsig=(tMsgPlayerHolidayReq*)create_msg(IDM_PLAYERHOLIDAYREQ);
    tJSON *j;

    j=find(json, "PlayerId");
    if (j!=0) {
        newsig->PlayerId=to_objectid_t(j);
    }
    j=find(json, "HowLong");
    if (j!=0) {
        newsig->HowLong=to_uint64_t(j);
    }
    return ((tMsg*)(newsig));
}
// **************************************************************************
//
//  Method-Name   : msg_to_json_createplayerreply()
//
//  Generated source code.
//
// **************************************************************************
static std::ostream& msg_to_json_createplayerreply(tMsg* aMsg, std::ostream& output) {
    tMsgCreatePlayerReply* msg=(tMsgCreatePlayerReply*)aMsg;
    output << "\"MsgId\": \"CreatePlayerReply\"";
    output <<  ", \"PlayerId\":" << (int64_t)msg->PlayerId;
    output <<  ", \"Error\":" << (int64_t)msg->Error;
    return (output);
}
// **************************************************************************
//
//  Method-Name   : msg_to_json_playerholidayreply()
//
//  Generated source code.
//
// **************************************************************************
static std::ostream& msg_to_json_playerholidayreply(tMsg* aMsg, std::ostream& output) {
    tMsgPlayerHolidayReply* msg=(tMsgPlayerHolidayReply*)aMsg;
    output << "\"MsgId\": \"PlayerHolidayReply\"";
    output <<  ", \"Error\":" << (int64_t)msg->Error;
    return (output);
}
// **************************************************************************
//
//  Method-Name   : siminit()
//
//  Generated source code.
//
// **************************************************************************
void siminit(void) {
    msgfrommap.insert(std::pair<std::string, msg_from_json>("CreatePlayerReq", msg_from_json_createplayerreq));
    msgfrommap.insert(std::pair<std::string, msg_from_json>("PlayerHolidayReq", msg_from_json_playerholidayreq));

    msgtomap.insert(std::pair<uint64_t, msg_to_json>(IDM_CREATEPLAYERREPLY, msg_to_json_createplayerreply));
    msgtomap.insert(std::pair<uint64_t, msg_to_json>(IDM_PLAYERHOLIDAYREPLY, msg_to_json_playerholidayreply));

    addsimobjfactory(&cgameviewport_factory);
    addsimobjfactory(&cplayerviewport_factory);
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
    case IDM_PLAYERHOLIDAYREQ:
        retval = (tMsg*)new tMsgPlayerHolidayReq;
        retval->id=msgid;
        retval->type = MSG_TYPE_REQUEST;
        break;
    case IDM_PLAYERHOLIDAYREPLY:
        retval = (tMsg*)new tMsgPlayerHolidayReply;
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
