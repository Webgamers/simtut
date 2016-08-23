// *************************************************************************************************************
//
//  Modul-Name     : ids.h
//
//  Copyrights by Hans-Juergen Lange <hjl@simulated-universe.de>. All rights reserved.
//
// *************************************************************************************************************
#pragma once
#ifndef __IDS_INC__
#define __IDS_INC__

#define Lock(lock) pthread_spin_lock(&lock)
#define Unlock(lock) pthread_spin_unlock(&lock)
#define FilledReference(obj) tSimObjRef {obj->objid, obj}
#define SendToReference(ref, msg) ref->second.objptr->syncprocess(ref->second.objptr, (tMsg*)msg);
#define SignalToReference(ref, sig) ref->second.objptr->process(ref->second.objptr, (tSig*)sig);
#define NewObject(tid, p) createobj(tid, simnextidx())->parent=p

typedef std::map<uint64_t, tSimObjRef>::iterator tObjectRefIterator;
//
//
//  This is the list of object ids used to identify object types in the DB
#define IDO_CGAMEVIEWPORT   (0xa44432a6418a4213)
#define IDO_CPLAYERVIEWPORT (0x007b5f8b7f71bfa3)
//
//
//  This is the list of attribute ids used to identify object attributes in the DB
#define IDA_EMAIL           (0x8680e530bc34959b)
#define IDA_NAME            (0x842f3af822536317)
#define IDA_PASSWORD        (0x3aff6d7112e2cfea)
#define IDA_STATE           (0x9abc62b337d172c6)
//
//
//  This is the list of enumeration ids used to identify object enumerators in the DB

#endif  // __IDS_INC__

