// *************************************************************************************************************
//
//  Modul-Name     : CPlayerViewport.h
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
#ifndef PLAYERVIEWPORT_INC
#define PLAYERVIEWPORT_INC

//
//                   S i m o b j e c t    d e c l a r a t i o n
typedef struct __CPlayerViewport {
    tSimObj                          base;
    std::string                      SessionId;
    std::string                      Name;
    std::string                      Email;
    std::string                      Password;
    std::map< uint64_t, tSimObjRef > Games;
    int                              state_idx;
    tUpdate                          state_fnc;
} CPlayerViewport;

extern tObjLib playerviewport_factory;

#endif  // PLAYERVIEWPORT_INC
