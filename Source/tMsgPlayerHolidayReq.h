// *************************************************************************************************************
//
//  Modul-Name     : tMsgPlayerHolidayReq.h
//
//  Copyrights by Hans-Juergen Lange <hjl@simulated-universe.de>. All rights reserved.
//
// *************************************************************************************************************
// HOC *********************************************************************************************************
//          |         |
// YYYYMMDD | Creator | description
//--------------------------------------------------------------------------------------------------------------
//          |         |
//----------+---------+-----------------------------------------------------------------------------------------
//          |         |
// HOC end *****************************************************************************************************
#pragma once
#ifndef TMSGPLAYERHOLIDAYREQ_INC
#define TMSGPLAYERHOLIDAYREQ_INC

#define IDM_PLAYERHOLIDAYREQ 0xeccb5fa644a34fef
//
//                   M e s s a g e c l a s s     d e c l a r a t i o n
typedef struct __tMsgPlayerHolidayReq {
    uint64_t   id;
    void*      src;
    void*      dst;
    uint64_t   type;
    objectid_t PlayerId;
    uint64_t   HowLong;
} tMsgPlayerHolidayReq;

#endif  // TMSGPLAYERHOLIDAYREQ_INC
