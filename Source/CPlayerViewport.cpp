// *************************************************************************************************************
//
//  Modul-Name     : CPlayerViewport.cpp
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
#include "CPlayerViewport.h"
#include "tMsgPlayerHolidayReq.h"
#include "tMsgPlayerHolidayReply.h"
/*
 *  These are the function prototypes for the message and signal processing functions.
 */
static tMsg* playerholidayreq(tSimObj* obj,tMsgPlayerHolidayReq* msg) ;
/*
 *  private macros
 */
/*
 * These are function prototypes for local object functions defined within 
 * the simulation object.
 */
/*
 *  The state function prototypes.
 */
static void aktiv_state(tSimObj *obj, uint64_t step);
static void urlaub_state(tSimObj *obj, uint64_t step);
/*
 *  The state array.
 */
static tUpdate update_functions[] = {
                                     aktiv_state,
                                     urlaub_state
                                    };

static int setvaluedb(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value);
static int setvalue(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value);
static void copy_from_template(tSimObj* obj, templateid_t tid);
/*
 *  These are accessor function to make the access easier.
 */
inline static std::string& SessionId(tSimObj* obj) {
    return ((CPlayerViewport*)(obj))->SessionId;
}
inline static std::string& Name(tSimObj* obj) {
    return ((CPlayerViewport*)(obj))->Name;
}
inline static std::string& Email(tSimObj* obj) {
    return ((CPlayerViewport*)(obj))->Email;
}
inline static std::string& Password(tSimObj* obj) {
    return ((CPlayerViewport*)(obj))->Password;
}
inline static std::map< uint64_t, tSimObjRef >& Games(tSimObj* obj) {
    return ((CPlayerViewport*)(obj))->Games;
}
/*
 *  End of accessor functions
 */
/*
 *  The template storage map
 */
static std::map<objectid_t, CPlayerViewport*> t_store;
/*
 *
 *       !!!!    Here is a collection of functions that are editable.   !!!!
 */
/*
 *  The state function implementation.
 */
/* **************************************************************************
 *
 *  Method-Name   : aktiv_state()
 *
 *  Partial generated source code.
 *
 * *************************************************************************/
static void aktiv_state(tSimObj *obj, uint64_t aCycle) {
    CPlayerViewport* playerviewport=((CPlayerViewport*)(obj));

// User-Defined-Code:AAAAAAFWtro2bdyqyk0=--pre
// End-Of-UDC:AAAAAAFWtro2bdyqyk0=--pre
// User-Defined-Code:AAAAAAFWtro2bdyqyk0=--post
// End-Of-UDC:AAAAAAFWtro2bdyqyk0=--post
}
/* **************************************************************************
 *
 *  Method-Name   : urlaub_state()
 *
 *  Partial generated source code.
 *
 * *************************************************************************/
static void urlaub_state(tSimObj *obj, uint64_t aCycle) {
    CPlayerViewport* playerviewport=((CPlayerViewport*)(obj));

// User-Defined-Code:AAAAAAFWtrpfIdzQa0k=--pre
// End-Of-UDC:AAAAAAFWtrpfIdzQa0k=--pre
// User-Defined-Code:AAAAAAFWtrpfIdzQa0k=--post
// End-Of-UDC:AAAAAAFWtrpfIdzQa0k=--post
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
    obj->update = urlaub_state;
    obj->state  = 0x0000000000000001;
    stdb_updatedata(obj->objid, IDA_STATE, 0, obj->state);
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
// User-Defined-Code: save-playerviewport
// End-Of-UDC: save-playerviewport
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
    CPlayerViewport* playerviewport_var = (CPlayerViewport*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        break;
    case IDA_STATE_IDX:
        ((CPlayerViewport*)obj)->state_idx = *((uint64_t*)(value));
        break;
    case IDA_NAME:
        playerviewport_var->Name=((char*)(value));
        break;
    case IDA_EMAIL:
        playerviewport_var->Email=((char*)(value));
        break;
    case IDA_PASSWORD:
        playerviewport_var->Password=((char*)(value));
        break;
    case IDA_GAMES:
        playerviewport_var->Games[valueindex]=tSimObjRef{*(objectid_t*)(value), 0};
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
    CPlayerViewport* playerviewport_var = (CPlayerViewport*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        stdb_updatedata(obj->objid, IDA_STATE, 0, obj->state);
        break;
    case IDA_NAME:
        playerviewport_var->Name=((char*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (char*)(value));
        break;
    case IDA_EMAIL:
        playerviewport_var->Email=((char*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (char*)(value));
        break;
    case IDA_PASSWORD:
        playerviewport_var->Password=((char*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (char*)(value));
        break;
    case IDA_GAMES:
        if (playerviewport_var->Games.find(valueindex) == playerviewport_var->Games.end()) {
            playerviewport_var->Games.insert(std::pair<uint64_t, tSimObjRef>(valueindex, tSimObjRef{*(objectid_t*)(value), simfindidx(*(objectid_t*)(value))}));
            stdb_createreferencedata(obj->objid, valueid, valueindex, *(objectid_t*)(value));
        } else {
            playerviewport_var->Games[valueindex]=tSimObjRef{*(objectid_t*)(value), simfindidx(*(objectid_t*)(value))};
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
    for (std::map< uint64_t, tSimObjRef >::iterator i =Games(obj).begin(); i != Games(obj).end(); ++i) {
        simfillref(&(i->second));
        if (i->second.objptr != 0) {
            i->second.objptr->parent = obj;
        }
    }
        /*
         * This is the shallowHistory functionality.
         */
        if (obj->state > ((sizeof(update_functions)/sizeof(update_functions[0]))-1)) {
            obj->state = 0;
            stdb_updatedata(obj->objid, IDA_STATE, 0, (uint64_t)0u);
        }
        obj->update   = update_functions[obj->state];
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
    CPlayerViewport* varplayerviewport = (CPlayerViewport*)obj;
    std::map<objectid_t, CPlayerViewport*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
        setvaluedb(obj, IDA_NAME, 0, (void*)found->second->Name.c_str());
        setvaluedb(obj, IDA_EMAIL, 0, (void*)found->second->Email.c_str());
        setvaluedb(obj, IDA_PASSWORD, 0, (void*)found->second->Password.c_str());
    }
}
// **************************************************************************
//
//  Method-Name   : create_playerviewport_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_playerviewport_obj(objectid_t  oid) {
    CPlayerViewport* newplayerviewport = new CPlayerViewport;

    if (newplayerviewport != 0) {
        newplayerviewport->base.type        = IDO_PLAYERVIEWPORT;
        newplayerviewport->base.objid       = oid;
        newplayerviewport->base.parent      = 0;
        newplayerviewport->base.state       = 0;
        newplayerviewport->base.setvalue    = setvalue;
        newplayerviewport->base.save        = save;
        newplayerviewport->base.update      = init_object;
        newplayerviewport->base.process     = process_sig;
        newplayerviewport->base.syncprocess = process_msg;
        if (0xc0000000 & oid) {
            t_store.insert(std::pair<templateid_t, CPlayerViewport*>(oid, newplayerviewport));
        }
    } else {
    }
    return ((tSimObj*)newplayerviewport);
}
// **************************************************************************
//
//  Method-Name   : create_new_playerviewport_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_playerviewport_obj(objectid_t  oid) {
    CPlayerViewport* newplayerviewport = new CPlayerViewport;

    if (newplayerviewport != 0) {
        newplayerviewport->base.type        = IDO_PLAYERVIEWPORT;
        newplayerviewport->base.objid       = oid;
        newplayerviewport->base.parent      = 0;
        newplayerviewport->base.state       = 0;
        newplayerviewport->base.setvalue    = setvalue;
        newplayerviewport->base.save        = save;
        newplayerviewport->base.update      = init_object;
        newplayerviewport->base.process     = process_sig;
        newplayerviewport->base.syncprocess = process_msg;
        newplayerviewport->state_idx = -1;
        //
        //  Create the object in the db.
        stdb_createobj(oid, IDO_PLAYERVIEWPORT);
        stdb_createdata(oid, IDA_STATE, 0, newplayerviewport->base.state);
        stdb_createdata(oid, IDA_STATE_IDX, 0, (int64_t)-1);
        //
        //  Now fill the attributes with values.
        //
        //  create the attribute data in the DB.
        stdb_createdata(oid, IDA_NAME, 0, newplayerviewport->Name.c_str());
        stdb_createdata(oid, IDA_EMAIL, 0, newplayerviewport->Email.c_str());
        stdb_createdata(oid, IDA_PASSWORD, 0, newplayerviewport->Password.c_str());
    } else {
    }
    return ((tSimObj*)newplayerviewport);
}
// **************************************************************************
//
//  Method-Name   : create_new_playerviewport_obj_from_template()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_playerviewport_obj_from_template(templateid_t  tid, objectid_t  oid) {
    CPlayerViewport* newplayerviewport = 0;
    std::map<objectid_t, CPlayerViewport*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
        newplayerviewport = new CPlayerViewport;
        if (newplayerviewport != 0) {
            newplayerviewport->base.type        = IDO_PLAYERVIEWPORT;
            newplayerviewport->base.objid       = oid;
            newplayerviewport->base.parent      = 0;
            newplayerviewport->base.state       = 0;
            newplayerviewport->base.setvalue    = setvaluedb;
            newplayerviewport->base.save        = save;
            newplayerviewport->base.update      = init_object;
            newplayerviewport->base.process     = process_sig;
            newplayerviewport->base.syncprocess = process_msg;
        newplayerviewport->state_idx = -1;
            //
            //  Create the object in the db.
            stdb_createobj(oid, IDO_PLAYERVIEWPORT);
            stdb_createdata(oid, IDA_STATE, 0, newplayerviewport->base.state);
            stdb_createdata(oid, IDA_STATE_IDX, 0, (int64_t)-1);
            //
            //  Copy data from template.
            //
            //  create the attribute data in the DB.
            stdb_createdata(oid, IDA_NAME, 0, newplayerviewport->Name.c_str());
            stdb_createdata(oid, IDA_EMAIL, 0, newplayerviewport->Email.c_str());
            stdb_createdata(oid, IDA_PASSWORD, 0, newplayerviewport->Password.c_str());
        } else {
        }
    } else {
    }
    return ((tSimObj*)newplayerviewport);
}

tObjLib playerviewport_factory= {0, 0, 0, IDO_PLAYERVIEWPORT, create_playerviewport_obj, create_new_playerviewport_obj, create_new_playerviewport_obj_from_template};
//
//
// this is a collection of left-over modifications.
// // User-Defined-Code: save-cplayerviewport
// end-of-// User-Defined-Code: save-cplayerviewport
