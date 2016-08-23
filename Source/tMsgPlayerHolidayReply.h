// *************************************************************************************************************
//
//  Modul-Name     : tMsgPlayerHolidayReply.h
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
#ifndef TMSGPLAYERHOLIDAYREPLY_INC
#define TMSGPLAYERHOLIDAYREPLY_INC

#define IDM_PLAYERHOLIDAYREPLY 0xb5e0065f2d81a528
//
//                   M e s s a g e c l a s s     d e c l a r a t i o n
typedef struct __tMsgPlayerHolidayReply {
    uint64_t id;
    void*    src;
    void*    dst;
    uint64_t type;
    uint64_t Error;
} tMsgPlayerHolidayReply;

#endif  // TMSGPLAYERHOLIDAYREPLY_INC
