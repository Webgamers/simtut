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
/*
 *  These are the function prototypes for the message and signal processing functions.
 */
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
// **************************************************************************
//
//  Method-Name   : save()
//
//  Generated source code.
//
// **************************************************************************
static int save(tSimObj* obj, uint64_t aCycle, ... ) {
    int result = 0;
// User-Defined-Code: save-cplayerviewport
// End-Of-UDC: save-cplayerviewport
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
    CPlayerViewport* cplayerviewport_var = (CPlayerViewport*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        break;
    case IDA_NAME:
        cplayerviewport_var->Name=((char*)(value));
        break;
    case IDA_EMAIL:
        cplayerviewport_var->Email=((char*)(value));
        break;
    case IDA_PASSWORD:
        cplayerviewport_var->Password=((char*)(value));
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
    CPlayerViewport* cplayerviewport_var = (CPlayerViewport*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        stdb_updatedata(obj->objid, IDA_STATE, 0, obj->state);
        break;
    case IDA_NAME:
        cplayerviewport_var->Name=((char*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (char*)(value));
        break;
    case IDA_EMAIL:
        cplayerviewport_var->Email=((char*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (char*)(value));
        break;
    case IDA_PASSWORD:
        cplayerviewport_var->Password=((char*)(value));
        stdb_updatedata(obj->objid, valueid, valueindex, (char*)(value));
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
    CPlayerViewport* varcplayerviewport = (CPlayerViewport*)obj;
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
//  Method-Name   : create_cplayerviewport_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_cplayerviewport_obj(objectid_t  oid) {
    CPlayerViewport* newcplayerviewport = new CPlayerViewport;

    if (newcplayerviewport != 0) {
        newcplayerviewport->base.type        = IDO_CPLAYERVIEWPORT;
        newcplayerviewport->base.objid       = oid;
        newcplayerviewport->base.parent      = 0;
        newcplayerviewport->base.state       = 0;
        newcplayerviewport->base.setvalue    = setvalue;
        newcplayerviewport->base.save        = save;
        newcplayerviewport->base.update      = init_object;
        newcplayerviewport->base.process     = process_sig;
        newcplayerviewport->base.syncprocess = process_msg;
        if (0xc0000000 & oid) {
            t_store.insert(std::pair<templateid_t, CPlayerViewport*>(oid, newcplayerviewport));
        }
    } else {
    }
    return ((tSimObj*)newcplayerviewport);
}
// **************************************************************************
//
//  Method-Name   : create_new_cplayerviewport_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_cplayerviewport_obj(objectid_t  oid) {
    CPlayerViewport* newcplayerviewport = new CPlayerViewport;

    if (newcplayerviewport != 0) {
        newcplayerviewport->base.type        = IDO_CPLAYERVIEWPORT;
        newcplayerviewport->base.objid       = oid;
        newcplayerviewport->base.parent      = 0;
        newcplayerviewport->base.state       = 0;
        newcplayerviewport->base.setvalue    = setvalue;
        newcplayerviewport->base.save        = save;
        newcplayerviewport->base.update      = init_object;
        newcplayerviewport->base.process     = process_sig;
        newcplayerviewport->base.syncprocess = process_msg;
        //
        //  Create the object in the db.
        stdb_createobj(oid, IDO_CPLAYERVIEWPORT);
        stdb_createdata(oid, IDA_STATE, 0, newcplayerviewport->base.state);
        //
        //  Now fill the attributes with values.
        //
        //  create the attribute data in the DB.
        stdb_createdata(oid, IDA_NAME, 0, newcplayerviewport->Name.c_str());
        stdb_createdata(oid, IDA_EMAIL, 0, newcplayerviewport->Email.c_str());
        stdb_createdata(oid, IDA_PASSWORD, 0, newcplayerviewport->Password.c_str());
    } else {
    }
    return ((tSimObj*)newcplayerviewport);
}
// **************************************************************************
//
//  Method-Name   : create_new_cplayerviewport_obj_from_template()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_cplayerviewport_obj_from_template(templateid_t  tid, objectid_t  oid) {
    CPlayerViewport* newcplayerviewport = 0;
    std::map<objectid_t, CPlayerViewport*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
        newcplayerviewport = new CPlayerViewport;
        if (newcplayerviewport != 0) {
            newcplayerviewport->base.type        = IDO_CPLAYERVIEWPORT;
            newcplayerviewport->base.objid       = oid;
            newcplayerviewport->base.parent      = 0;
            newcplayerviewport->base.state       = 0;
            newcplayerviewport->base.setvalue    = setvaluedb;
            newcplayerviewport->base.save        = save;
            newcplayerviewport->base.update      = init_object;
            newcplayerviewport->base.process     = process_sig;
            newcplayerviewport->base.syncprocess = process_msg;
            //
            //  Create the object in the db.
            stdb_createobj(oid, IDO_CPLAYERVIEWPORT);
            stdb_createdata(oid, IDA_STATE, 0, newcplayerviewport->base.state);
            //
            //  Copy data from template.
            //
            //  create the attribute data in the DB.
            stdb_createdata(oid, IDA_NAME, 0, newcplayerviewport->Name.c_str());
            stdb_createdata(oid, IDA_EMAIL, 0, newcplayerviewport->Email.c_str());
            stdb_createdata(oid, IDA_PASSWORD, 0, newcplayerviewport->Password.c_str());
        } else {
        }
    } else {
    }
    return ((tSimObj*)newcplayerviewport);
}

tObjLib cplayerviewport_factory= {0, 0, 0, IDO_CPLAYERVIEWPORT, create_cplayerviewport_obj, create_new_cplayerviewport_obj, create_new_cplayerviewport_obj_from_template};
