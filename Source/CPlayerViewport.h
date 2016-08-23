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
#ifndef CPLAYERVIEWPORT_INC
#define CPLAYERVIEWPORT_INC

//
//                   S i m o b j e c t    d e c l a r a t i o n
typedef struct __CPlayerViewport {
    tSimObj     base;
    std::string SessionId;
    std::string Name;
    std::string Email;
    std::string Password;
} CPlayerViewport;

extern tObjLib cplayerviewport_factory;

#endif  // CPLAYERVIEWPORT_INC
