// *************************************************************************************************************
//
//  Modul-Name     : CGameViewport.h
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
#ifndef GAMEVIEWPORT_INC
#define GAMEVIEWPORT_INC

//
//                   S i m o b j e c t    d e c l a r a t i o n
typedef struct __CGameViewport {
    tSimObj                          base;
    uint64_t                         LastCycle;
    std::map< uint64_t, tSimObjRef > AllPlayers;
} CGameViewport;

extern tObjLib gameviewport_factory;

#endif  // GAMEVIEWPORT_INC
