// *************************************************************************************************************
//
//  Modul-Name     : CGameViewport.cpp
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
//
//                      S y s t e m   i n c l u d e s
#include <simifc.h>
#include <stdint.h>
#include <stdlib.h>
#include <simobjfactory.h>
#include <vector>
#include <map>
#include "ids.h"
//
//                       M o d e l   i n c l u d e s
#include "CGameViewport.h"
#include "tMsgCreatePlayerReq.h"
#include "tMsgPlayerHolidayReq.h"
#include "tMsgPlayerHolidayReply.h"
#include "tMsgCreatePlayerReply.h"
/*
 *  These are the function prototypes for the message and signal processing functions.
 */
static tMsg* createplayerreq(tSimObj* obj,tMsgCreatePlayerReq* msg) ;
static tMsg* playerholidayreq(tSimObj* obj,tMsgPlayerHolidayReq* msg) ;
static int setvaluedb(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value);
static int setvalue(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value);
static void copy_from_template(tSimObj* obj, templateid_t tid);
/*
 *  These are accessor function to make the access easier.
 */
inline static uint64_t& LastCycle(tSimObj* obj) {
    return ((CGameViewport*)(obj))->LastCycle;
}
inline static std::map< uint64_t, tSimObjRef >& AllPlayers(tSimObj* obj) {
    return ((CGameViewport*)(obj))->AllPlayers;
}
/*
 *  End of accessor functions
 */
/*
 *  The template storage map
 */
static std::map<objectid_t, CGameViewport*> t_store;
/*
 *
 *       !!!!    Here is a collection of functions that are editable.   !!!!
 */
/* **************************************************************************
 *
 *  Method-Name   : createplayerreq()
 *
 *  Partial generated source code.
 *
 * *************************************************************************/
static tMsg* createplayerreq(tSimObj* obj,tMsgCreatePlayerReq* msg) {
    tMsg* retval=0;
// User-Defined-Code:createplayerreq
// End-Of-UDC:createplayerreq
    return (retval);
}
/* **************************************************************************
 *
 *  Method-Name   : playerholidayreq()
 *
 *  Partial generated source code.
 *
 * *************************************************************************/
static tMsg* playerholidayreq(tSimObj* obj,tMsgPlayerHolidayReq* msg) {
    tMsg* retval=0;
// User-Defined-Code:playerholidayreq
// End-Of-UDC:playerholidayreq
    return (retval);
}
// **************************************************************************
//
//  Method-Name   : save()
//
//  Generated source code.
//
// **************************************************************************
static int save(tSimObj* obj, uint64_t aCycle, ... ) {
    int result = 0;
// User-Defined-Code: save-gameviewport
// End-Of-UDC: save-gameviewport
    return (result);
}

//
//
//       !!!!          End of editable section of functions.             !!!!
//
// **************************************************************************
//
//  Method-Name   : setvalue()
//
// **************************************************************************
static int setvalue(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value) {
    int err=0;
    CGameViewport* gameviewport_var = (CGameViewport*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        break;
    case IDA_LASTCYCLE:
        gameviewport_var->LastCycle=*((uint64_t*)(value));
        break;
    case IDA_ALLPLAYERS:
        gameviewport_var->AllPlayers[valueindex]=tSimObjRef{*(objectid_t*)(value), 0};
        break;
    default:
        err=-1;
        break;
    }
    return (err);
}
// **************************************************************************
//
//  Method-Name   : setvaluedb()
//
// **************************************************************************
static int setvaluedb(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value) {
    int err=0;
    CGameViewport* gameviewport_var = (CGameViewport*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        stdb_updatedata(obj->objid, IDA_STATE, 0, obj->state);
        break;
    case IDA_LASTCYCLE:
        gameviewport_var->LastCycle=*((uint64_t*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (uint64_t)(gameviewport_var->LastCycle));
        break;
    case IDA_ALLPLAYERS:
        if (gameviewport_var->AllPlayers.find(valueindex) == gameviewport_var->AllPlayers.end()) {
            gameviewport_var->AllPlayers.insert(std::pair<uint64_t, tSimObjRef>(valueindex, tSimObjRef{*(objectid_t*)(value), simfindidx(*(objectid_t*)(value))}));
            stdb_createreferencedata(obj->objid, valueid, valueindex, *(objectid_t*)(value));
        } else {
            gameviewport_var->AllPlayers[valueindex]=tSimObjRef{*(objectid_t*)(value), simfindidx(*(objectid_t*)(value))};
            stdb_updatereferencedata(obj->objid, valueid, valueindex, *(objectid_t*)(value));
        }
        break;
    default:
        err=-1;
        break;
    }
    return (err);
}
// **************************************************************************
//
//  Method-Name   : init_object()
//
//  Generated source code.
//
// **************************************************************************
static void init_object(tSimObj * obj, uint64_t  aCycle) {
    /*
     * Fill all references with the pointers.
     */
    for (std::map< uint64_t, tSimObjRef >::iterator i =AllPlayers(obj).begin(); i != AllPlayers(obj).end(); ++i) {
        simfillref(&(i->second));
        if (i->second.objptr != 0) {
            i->second.objptr->parent = obj;
        }
    }
    /*
     *  This object has no statemachine.
     */
    obj->update   = 0;
    /*
     *  Switch over to update the DB as well if object attributes change.
     */
    obj->setvalue = setvaluedb;
}
// **************************************************************************
//
//  Method-Name   : process_sig()
//
//  Generated source code.
//
// **************************************************************************
static void process_sig(tSimObj * obj, tSig *sig) {
    switch (sig->id) {
    default:
        if ((sig->type == MSG_TYPE_INDICATION) && (obj->parent != 0) && (obj!=obj->parent)) {
            sig->dst = obj->parent;
            addmsg(sig);
        } else {
            delete sig;
        }
        break;
    }
}
// **************************************************************************
//
//  Method-Name   : process_msg()
//
//  Generated source code.
//
// **************************************************************************
static tMsg* process_msg(tSimObj * obj, tMsg * msg) {
    tMsg *retmsg=0;

    switch (msg->id) {
    case IDM_CREATEPLAYERREQ:
        retmsg=createplayerreq(obj,(tMsgCreatePlayerReq*)(msg));
        break;
    case IDM_PLAYERHOLIDAYREQ:
        retmsg=playerholidayreq(obj,(tMsgPlayerHolidayReq*)(msg));
        break;
    default:
        if (((msg->type == MSG_TYPE_REPLY) || (msg->type == MSG_TYPE_INDICATION)) && (obj->parent != 0) && (obj != obj->parent)) {
            retmsg = obj->parent->syncprocess(obj->parent, msg);
        } else {
        }
        break;
    }
    return (retmsg);
}
// **************************************************************************
//
//  Method-Name   : copy_from_template()
//
//  Generated source code.
//
// **************************************************************************
static void copy_from_template(tSimObj* obj, templateid_t  tid) {
    CGameViewport* vargameviewport = (CGameViewport*)obj;
    std::map<objectid_t, CGameViewport*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
        setvaluedb(obj, IDA_LASTCYCLE, 0, &found->second->LastCycle);
    }
}
// **************************************************************************
//
//  Method-Name   : create_gameviewport_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_gameviewport_obj(objectid_t  oid) {
    CGameViewport* newgameviewport = new CGameViewport;

    if (newgameviewport != 0) {
        newgameviewport->base.type        = IDO_GAMEVIEWPORT;
        newgameviewport->base.objid       = oid;
        newgameviewport->base.parent      = 0;
        newgameviewport->base.state       = 0;
        newgameviewport->base.setvalue    = setvalue;
        newgameviewport->base.save        = save;
        newgameviewport->base.update      = init_object;
        newgameviewport->base.process     = process_sig;
        newgameviewport->base.syncprocess = process_msg;
        if (0xc0000000 & oid) {
            t_store.insert(std::pair<templateid_t, CGameViewport*>(oid, newgameviewport));
        }
        newgameviewport->LastCycle = 0;
    } else {
    }
    return ((tSimObj*)newgameviewport);
}
// **************************************************************************
//
//  Method-Name   : create_new_gameviewport_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_gameviewport_obj(objectid_t  oid) {
    CGameViewport* newgameviewport = new CGameViewport;

    if (newgameviewport != 0) {
        newgameviewport->base.type        = IDO_GAMEVIEWPORT;
        newgameviewport->base.objid       = oid;
        newgameviewport->base.parent      = 0;
        newgameviewport->base.state       = 0;
        newgameviewport->base.setvalue    = setvalue;
        newgameviewport->base.save        = save;
        newgameviewport->base.update      = init_object;
        newgameviewport->base.process     = process_sig;
        newgameviewport->base.syncprocess = process_msg;
        //
        //  Create the object in the db.
        stdb_createobj(oid, IDO_GAMEVIEWPORT);
        stdb_createdata(oid, IDA_STATE, 0, newgameviewport->base.state);
        //
        //  Now fill the attributes with values.
        newgameviewport->LastCycle = 0;
        //
        //  create the attribute data in the DB.
        stdb_createdata(oid, IDA_LASTCYCLE, 0, (uint64_t)(newgameviewport->LastCycle));
    } else {
    }
    return ((tSimObj*)newgameviewport);
}
// **************************************************************************
//
//  Method-Name   : create_new_gameviewport_obj_from_template()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_gameviewport_obj_from_template(templateid_t  tid, objectid_t  oid) {
    CGameViewport* newgameviewport = 0;
    std::map<objectid_t, CGameViewport*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
        newgameviewport = new CGameViewport;
        if (newgameviewport != 0) {
            newgameviewport->base.type        = IDO_GAMEVIEWPORT;
            newgameviewport->base.objid       = oid;
            newgameviewport->base.parent      = 0;
            newgameviewport->base.state       = 0;
            newgameviewport->base.setvalue    = setvaluedb;
            newgameviewport->base.save        = save;
            newgameviewport->base.update      = init_object;
            newgameviewport->base.process     = process_sig;
            newgameviewport->base.syncprocess = process_msg;
            //
            //  Create the object in the db.
            stdb_createobj(oid, IDO_GAMEVIEWPORT);
            stdb_createdata(oid, IDA_STATE, 0, newgameviewport->base.state);
            //
            //  Copy data from template.
            newgameviewport->LastCycle = found->second->LastCycle;
            //
            //  create the attribute data in the DB.
            stdb_createdata(oid, IDA_LASTCYCLE, 0, (uint64_t)(newgameviewport->LastCycle));
        } else {
        }
    } else {
    }
    return ((tSimObj*)newgameviewport);
}

tObjLib gameviewport_factory= {0, 0, 0, IDO_GAMEVIEWPORT, create_gameviewport_obj, create_new_gameviewport_obj, create_new_gameviewport_obj_from_template};
//
//
// this is a collection of left-over modifications.
// // User-Defined-Code: save-cgameviewport
// end-of-// User-Defined-Code: save-cgameviewport
