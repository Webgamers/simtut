// *************************************************************************************************************
//
//  Modul-Name     : tMsgCreatePlayerReply.h
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
#ifndef TMSGCREATEPLAYERREPLY_INC
#define TMSGCREATEPLAYERREPLY_INC

#define IDM_CREATEPLAYERREPLY 0x354344a83452bdc9
//
//                   M e s s a g e c l a s s     d e c l a r a t i o n
typedef struct __tMsgCreatePlayerReply {
    uint64_t id;
    void*    src;
    void*    dst;
    uint64_t type;
    uint64_t PlayerId;
    uint64_t Error;
} tMsgCreatePlayerReply;

#endif  // TMSGCREATEPLAYERREPLY_INC
