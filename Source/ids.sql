-- *************************************************************************************************************
--
--  Modul-Name     : ids.sql
--
--  Copyrights by Hans-Juergen Lange <hjl@simulated-universe.de>. All rights reserved.
--
-- *************************************************************************************************************
#ifndef __IDS_INC__
#define __IDS_INC__
--
--
--  This is the list of object ids used to identify object types in the DB
#define IDO_CGAMEVIEWPORT   cast (x'a44432a6418a4213' as bigint)
#define IDO_CPLAYERVIEWPORT cast (x'007b5f8b7f71bfa3' as bigint)
--
--
--  This is the list of attribute ids used to identify object attributes in the DB
#define IDA_EMAIL           cast (x'8680e530bc34959b' as bigint)
#define IDA_NAME            cast (x'842f3af822536317' as bigint)
#define IDA_PASSWORD        cast (x'3aff6d7112e2cfea' as bigint)
#define IDA_STATE           cast (x'9abc62b337d172c6' as bigint)
--
--
--  This is the list of enumeration ids used to identify enumerator values in the DB

#endif

