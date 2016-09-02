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
#define IDO_GAMEVIEWPORT   cast (x'f0718fbb134addfa' as bigint)
#define IDO_PLAYERVIEWPORT cast (x'9a8545eab88ef541' as bigint)
#define IDO_SINKSHIPS      cast (x'85f4879249c67139' as bigint)
--
--
--  This is the list of attribute ids used to identify object attributes in the DB
#define IDA_ALLPLAYERS     cast (x'e4b62dfc62f3e188' as bigint)
#define IDA_EMAIL          cast (x'8680e530bc34959b' as bigint)
#define IDA_GAMES          cast (x'796ecba4c5ae0ada' as bigint)
#define IDA_LASTCYCLE      cast (x'73e575ab63945e57' as bigint)
#define IDA_NAME           cast (x'842f3af822536317' as bigint)
#define IDA_PASSWORD       cast (x'3aff6d7112e2cfea' as bigint)
#define IDA_STATE          cast (x'9abc62b337d172c6' as bigint)
#define IDA_STATE_IDX      cast (x'f3eeb7b1abb2553e' as bigint)
--
--
--  This is the list of enumeration ids used to identify enumerator values in the DB

#endif

