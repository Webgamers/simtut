// *************************************************************************************************************
//
//  Modul-Name     : CSinkShips.cpp
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
#include "CSinkShips.h"
/*
 *  These are the function prototypes for the message and signal processing functions.
 */
static int setvaluedb(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value);
static int setvalue(tSimObj * obj, valueid_t  valueid, valueindex_t  valueindex, void*  value);
static void copy_from_template(tSimObj* obj, templateid_t tid);
/*
 *  These are accessor function to make the access easier.
 */
/*
 *  End of accessor functions
 */
/*
 *  The template storage map
 */
static std::map<objectid_t, CSinkShips*> t_store;
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
// User-Defined-Code: save-sinkships
// End-Of-UDC: save-sinkships
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
    CSinkShips* sinkships_var = (CSinkShips*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
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
    CSinkShips* sinkships_var = (CSinkShips*)obj;

    switch (valueid) {
    case IDA_STATE:
        obj->state=*((uint64_t*)(value));
        stdb_updatedata(obj->objid, IDA_STATE, 0, obj->state);
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
    CSinkShips* varsinkships = (CSinkShips*)obj;
    std::map<objectid_t, CSinkShips*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
    }
}
// **************************************************************************
//
//  Method-Name   : create_sinkships_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_sinkships_obj(objectid_t  oid) {
    CSinkShips* newsinkships = new CSinkShips;

    if (newsinkships != 0) {
        newsinkships->base.type        = IDO_SINKSHIPS;
        newsinkships->base.objid       = oid;
        newsinkships->base.parent      = 0;
        newsinkships->base.state       = 0;
        newsinkships->base.setvalue    = setvalue;
        newsinkships->base.save        = save;
        newsinkships->base.update      = init_object;
        newsinkships->base.process     = process_sig;
        newsinkships->base.syncprocess = process_msg;
        if (0xc0000000 & oid) {
            t_store.insert(std::pair<templateid_t, CSinkShips*>(oid, newsinkships));
        }
    } else {
    }
    return ((tSimObj*)newsinkships);
}
// **************************************************************************
//
//  Method-Name   : create_new_sinkships_obj()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_sinkships_obj(objectid_t  oid) {
    CSinkShips* newsinkships = new CSinkShips;

    if (newsinkships != 0) {
        newsinkships->base.type        = IDO_SINKSHIPS;
        newsinkships->base.objid       = oid;
        newsinkships->base.parent      = 0;
        newsinkships->base.state       = 0;
        newsinkships->base.setvalue    = setvalue;
        newsinkships->base.save        = save;
        newsinkships->base.update      = init_object;
        newsinkships->base.process     = process_sig;
        newsinkships->base.syncprocess = process_msg;
        //
        //  Create the object in the db.
        stdb_createobj(oid, IDO_SINKSHIPS);
        stdb_createdata(oid, IDA_STATE, 0, newsinkships->base.state);
        //
        //  Now fill the attributes with values.
        //
        //  create the attribute data in the DB.
    } else {
    }
    return ((tSimObj*)newsinkships);
}
// **************************************************************************
//
//  Method-Name   : create_new_sinkships_obj_from_template()
//
//  Generated source code.
//
// **************************************************************************
static tSimObj* create_new_sinkships_obj_from_template(templateid_t  tid, objectid_t  oid) {
    CSinkShips* newsinkships = 0;
    std::map<objectid_t, CSinkShips*>::iterator found;

    found = t_store.find(tid);
    if (found != t_store.end()) {
        newsinkships = new CSinkShips;
        if (newsinkships != 0) {
            newsinkships->base.type        = IDO_SINKSHIPS;
            newsinkships->base.objid       = oid;
            newsinkships->base.parent      = 0;
            newsinkships->base.state       = 0;
            newsinkships->base.setvalue    = setvaluedb;
            newsinkships->base.save        = save;
            newsinkships->base.update      = init_object;
            newsinkships->base.process     = process_sig;
            newsinkships->base.syncprocess = process_msg;
            //
            //  Create the object in the db.
            stdb_createobj(oid, IDO_SINKSHIPS);
            stdb_createdata(oid, IDA_STATE, 0, newsinkships->base.state);
            //
            //  Copy data from template.
            //
            //  create the attribute data in the DB.
        } else {
        }
    } else {
    }
    return ((tSimObj*)newsinkships);
}

tObjLib sinkships_factory= {0, 0, 0, IDO_SINKSHIPS, create_sinkships_obj, create_new_sinkships_obj, create_new_sinkships_obj_from_template};
