// *************************************************************************************************************
//
//  Modul-Name     : tMsgCreatePlayerReq.h
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
#ifndef TMSGCREATEPLAYERREQ_INC
#define TMSGCREATEPLAYERREQ_INC

#define IDM_CREATEPLAYERREQ 0x562d4643c4ccf0ae
//
//                   M e s s a g e c l a s s     d e c l a r a t i o n
typedef struct __tMsgCreatePlayerReq {
    uint64_t    id;
    void*       src;
    void*       dst;
    uint64_t    type;
    std::string Name;
    std::string Email;
    std::string Passwort;
} tMsgCreatePlayerReq;

#endif  // TMSGCREATEPLAYERREQ_INC
