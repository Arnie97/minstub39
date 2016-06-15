	TITLE HPGCC Aplet Template
************************************************************
*
* File: HPGCC Aplet Template
* By: HPGCC Team
* Based on original work: October/12/2000 by J.Y Avenard 
************************************************************

INCLUDE =Entry39.h
INCLUDE =Common.h


****************************
* ARM ToolBox39 ROMPOINTERS
****************************

ASSEMBLE
=~xPrRUN	EQU	#113+4096*0
=~xShSPLASH	EQU	#113+4096*1
=~xHpgccABOUT	EQU	#113+4096*2
RPL

EXTERNAL xPrRUN
EXTERNAL xShSPLASH
EXTERNAL xHpgccABOUT



ASSEMBLE
	Dir_Head 11,HPGCC Aplet,113

RPL

     StndtType


INCLUDE =Sharedvar.h

ASSEMBLE 
	Vfield  L34,IntTable
	CON(5)	=DOHSTR
	REL(5)  endLink
	Link	_Main
	Link	_Entry
	Link	_Exit
	Link	_Action
	Link	_Reset
	Link    _About
*>>>	Add links to more routines here, they must
*	be paired w/ the defines just below
	
endLink
RPL

DEFINE Main		INT_00
DEFINE Entry		INT_01
DEFINE Exit		INT_02
DEFINE Action		INT_03
DEFINE Reset		INT_04
DEFINE About       INT_05

*>>>	Add defines for more routines here
*	INT_05..INT_09, INT_0A..INT_0F or BINT INT_NN
*	Use INT_10..INT_1F and INT_NN w/ care !
* Each entry should be in the form of:
* DEFINE LabelName	INT_xx

ASSEMBLE
	Vfield  IntTable,DirVar
RPL
ASSEMBLE
	CON(5)	=DOHSTR
	REL(5)  endCode
RPL

*
* DEFINES to get access to the saved parameters
*
DEFINE	HPGCCData@	LastBut3
DEFINE	HPGCCData!	LastBut3 REPLACE DROP
DEFINE	ARMCode@	LastBut3 CARCOMP
DEFINE  SplashData@ LastBut3 INNERCOMP ROLLDROP DROP
DEFINE  CustomData@ LastBut3 SEVEN NTHCOMPDROP


*
* Main code entry
*
NAMELESS _Main
  ::

*     StndCheck			( Default handler for the aplet )

* REPLACED BY THE FOLLOWING TO KNOW WHICH VIEW THE USER ENTERED FROM
{ StndVIEW StndVar StndReset StndEntry StndExit } BinLookup case EVAL

* STORE THE VIEW NUMBER IN TOPICVAR2

  TopicVar2!



** For each view, the main code is supposed to return 8 arguments (similar to the HP48/49 ParOuterLoop):
** Level: 8: View Entry handler (program)
**        7: View Exit handler (program)
**        6: Display handler (program)
**        5: Hard Key handler (program)
**        4: Flag to allow normal keys (TRUE or FALSE)
**        3: Menu Definition (list)
**        2: Initial Menu Page (System Binary)  
**        1: Error handler (program)
*<SOURCE CODE END>

     ' Entry			( view entry )
     ' Exit			( view exit )
		
     '				( view display )
	::
	EnsureMenuOff		( **Remove this line if you want the menu to be displayed )
	;
     '				( view hard key handlers )
	::
	  {
	   { kcEnter :: TakeOver Action ; }	( **ENTER will start your main code )
	   NULL{}
	   NULL{}
	   NULL{}
	   NULL{}
	   NULL{}
          }
          ONE KeyFace
       ;

    TRUE				( **Allow normal keys** )

    {					( **Initial menu** )
    { $ "" :: TakeOver  SplashData@	xShSPLASH ; }
    NullMenuKey
    NullMenuKey
    NullMenuKey
    NullMenuKey
	{ $ "" :: TakeOver About ; }
    }
    
    ONE 				( **Initial menu page** )

    '					( **Error object** )
    ::	TURNMENUON RECLAIMDISP	ERRJMP  ;
  ;

NAMELESS _Entry
  ::

*   GET SAVED APLET DATA

	CustomData@
	TopicVar1!


*   CUSTOMIZABLE SPLASHSCREEN

    SplashData@

	xShSPLASH

  ;

NAMELESS _Exit
  ::

*   SAVE APLET DATA AS PERMANENT

	HPGCCData@
	INNERCOMP
	TopicVar1@
	ROTDROPSWAP
	{}N
	HPGCCData!

   LeaveGraphView
  ;

NAMELESS _Action
  ::	

* PASS CURRENT VIEW NUMBER

*  ( # may be:	ApLet entered by:	)
*  ( ZERO	plot view		)
*  ( ONE	plot setup view		)
*  ( TWO	numeric view		)
*  ( THREE	numeric setup view	)
*  ( FOUR	symbolic view		)
*  ( FIVE	symbolic. setup view	)
*  ( SIX	note view		)
*  ( SEVEN	sketch view		)

  TopicVar2@


* PASS SAVED DATA THROUGH STACK
  TopicVar1@

  ARMCode@

  xPrRUN

* STORE POSSIBLY MODIFIED DATA
  TopicVar1!

* DROP THE VIEW NUMBER

  DROP

;


NAMELESS _Reset

* ADD/REMOVE THE NOP BELOW TO KEEP THE BYTE-ALIGNMENT
:: 

	HPGCCData@
	INNERCOMP
	NULL{}
	ROTDROPSWAP
    {}N
	HPGCCData!

;

NAMELESS _About
  ::	

  xHpgccABOUT

;

ASSEMBLE
endCode
RPL


*****************************************************************************
*		PARAMETER
*****************************************************************************

ASSEMBLE
	Vfield DirVar,DirCode
RPL
  {
	$ "ARMCODE HERE!!!"
	$ ""
	$ ""
    GROB 0000C 100001000000
    0
	0
* APPLICATION CUSTOM DATA HERE
	{ }
  }

ASSEMBLE
	Vfield DirCode,DirAlt
RPL
  { }

ASSEMBLE
	Vfield DirAlt,DirNot
RPL
  $ ""

ASSEMBLE
	Vfield DirNot,DirEnd
RPL
  { }
