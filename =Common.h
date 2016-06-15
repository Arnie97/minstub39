***	=Common.h 1.3

INCLUDE =Head39.h

ASSEMBLE

	 LISTM


* Dir_Head <len> <name> ( <romid> | 7FF )

Dir_Head MACRO
	 NIBASC \HP39BinB\
	 CON(2)  $1	       length of name
	 NIBASC \$2\	       name
DirStart CON(5) =DORRP
	 CON(3) #$3	       attached rompart id
	 REL(5) DirEnd	       link to last object in directory
	 CON(5) 0
L1	 CON(2) 0	       last link
	 ENDM


* Lib_Head <len> <name>

Lib_Head MACRO
	 NIBASC \HP39BinH\
	 CON(2) $1
	 NIBASC \$2\
	 ENDM


Vfield	 MACRO
	 CON(5) (*)-($1)
$2	 CON(2) 0
	 ENDM


Cfield	 MACRO
	 CON(5) (*)-($1)
$2	 CON(2) 0
=$3	 EQU	(*)-(DirStart)
	 ENDM


HELPONLY MACRO
	 CON(1)  (nonALG)+1*(hasHELP)+0*(hasALIAS)+0*(hasPDATA)
	 CON(6)  =~$1
	 ENDM

Link	 MACRO
	 CON(5) ($1)-(DirStart)
	 ENDM

RPL



ASSEMBLE

altROMID	EQU   #6FD

=~altFUNCTOPIC	EQU   (altROMID)+4096*0
=~altPOLARTOPIC EQU   (altROMID)+4096*1
=~altPARAMTOPIC EQU   (altROMID)+4096*2
=~altSEQTOPIC	EQU   (altROMID)+4096*3
=~altSTATTOPIC	EQU   (altROMID)+4096*4
=~altSOLVETOPIC EQU   (altROMID)+4096*5

RPL

EXTERNAL altFUNCTOPIC
EXTERNAL altPOLARTOPIC
EXTERNAL altPARAMTOPIC
EXTERNAL altSEQTOPIC
EXTERNAL altSTATTOPIC
EXTERNAL altSOLVETOPIC

EXTERNAL nFUNCTION
EXTERNAL xFUNCTAB
EXTERNAL xFUNCSYMB

EXTERNAL nPARAMETRIC
EXTERNAL xPARAMTAB
EXTERNAL xPARAMSYMB

EXTERNAL xDFLTNOTE
EXTERNAL xDFLTPICT

DEFINE altFunctType  { altFUNCTOPIC  nFUNCTION	 xFUNCTAB  xFUNCSYMB  xDFLTNOTE xDFLTPICT }
DEFINE altParamtType { altPARAMTOPIC nPARAMETRIC xPARAMTAB xPARAMSYMB xDFLTNOTE xDFLTPICT }

***********************************************
*					      *
*   COMMON DEFINES FOR FULL_FLEDGED APLETS    *
*					      *
***********************************************


EXTERNAL topic_NONE
EXTERNAL  view_NONE

DEFINE dummy_tType { topic_NONE view_NONE view_NONE view_NONE view_NONE view_NONE }



***********************************************
*					      *
*   COMMON DEFINES FOR CODE EMBEDED APLETS    *
*					      *
***********************************************

EXTERNAL  topic_CAPLET
EXTERNAL view01_CAPLET
EXTERNAL view23_CAPLET
EXTERNAL view45_CAPLET
EXTERNAL     xREADNOTE
EXTERNAL     xREADPICT

DEFINE StndtType { topic_CAPLET view01_CAPLET view23_CAPLET view45_CAPLET xREADNOTE xREADPICT }

DEFINE StndVIEW  MINUSONE   { { "Start" :: ZERO INT_00 ; } }
DEFINE StndVar	 MINUSTWO   MiniVar
DEFINE StndReset MINUSTHREE NOP
DEFINE StndEntry MINUSFOUR  NOP
DEFINE StndExit  MINUSFIVE  NOP

DEFINE StndCheck { StndVIEW StndVar StndReset StndEntry StndExit } BinLookup case EVAL DROP

DEFINE StndMenu  DummyMenuErr

