TITLE HPGCC Aplet Template
************************************************************
* By: HPGCC Team
* Based on original work: October/12/2000 by J.Y Avenard
************************************************************

INCLUDE =Entry39.h
INCLUDE =Common.h

* ARM ToolBox39 ROMPOINTERS
ASSEMBLE
=~xPrRUN	EQU	#113+4096*0
RPL

EXTERNAL xPrRUN

ASSEMBLE
	Dir_Head 11,HPGCC Aplet,113
RPL

StndtType

INCLUDE =Sharedvar.h

ASSEMBLE
	Vfield	L34,IntTable
	CON(5)	=DOHSTR
	REL(5)	endLink
	Link	_Main
	Link	_Entry
	Link	_Exit
	Link	_Reset

* Add links to more routines here
* they must be paired w/ the defines just below

endLink
RPL

DEFINE Main	INT_00
DEFINE Entry	INT_01
DEFINE Exit	INT_02
DEFINE Reset	INT_03

* Add defines for more routines here
* INT_05..INT_09, INT_0A..INT_0F or BINT INT_NN
* Use INT_10..INT_1F and INT_NN w/ care !
* Each entry should be in the form of:
* DEFINE LabelName	INT_xx

ASSEMBLE
	Vfield	IntTable,DirVar
RPL

ASSEMBLE
	CON(5)	=DOHSTR
	REL(5)	endCode
RPL

* DEFINES to get access to the saved parameters
DEFINE	HPGCCData@	LastBut3
DEFINE	HPGCCData!	LastBut3 REPLACE DROP
DEFINE	ARMCode@	LastBut3 CARCOMP
DEFINE	CustomData@	LastBut3 TWO NTHCOMPDROP


* Main code entry
* For each view, the main code entry is supposed to return 8 arguments
* (similar to the HP 48/49 ParOuterLoop).
NAMELESS _Main
::
* StndCheck			( Default handler for the aplet )
* REPLACED BY THE FOLLOWING TO KNOW WHICH VIEW THE USER ENTERED FROM
	{ StndVIEW StndVar StndReset StndEntry StndExit } BinLookup case EVAL

	( STORE THE VIEW NUMBER IN TOPICVAR2 )
	TopicVar2!

* Levels:
* 8: View entry handler	(program)
* 7: View exit handler	(program)
* 6: Display handler	(program)
* 5: Hard key handler	(program)
* 4: Normal keys flag	(boolean)
* 3: Menu definition	(list)
* 2: Initial menu page	(system binary)
* 1: Error handler	(program)

	' Entry			( 8 view entry )

	' Exit			( 7 view exit )

	'			( 6 view display )
	::
		EnsureMenuOff	( Remove this line if you want the menu to be displayed )
	;

	'			( 5 view hard key handlers )
	::
		{
			{ kcOn :: TurnOff TakeOver Entry ; }
			NULL{}
			NULL{}
			NULL{}
			NULL{}
			NULL{}
		}
		ONE KeyFace
	;

	TRUE			( 4 Allow normal keys )

	{			( 3 Initial menu )
		NullMenuKey
		NullMenuKey
		NullMenuKey
		NullMenuKey
		NullMenuKey
		NullMenuKey
	}

	ONE			( 2 Initial menu page )

	'			( 1 Error object )
	::
		TURNMENUON RECLAIMDISP ERRJMP
	;
;


NAMELESS _Entry
::
	( GET SAVED APLET DATA )
	CustomData@
	TopicVar1!

	( PASS CURRENT VIEW NUMBER )
	TopicVar2@

	( # may be:	aplet entered by: )
	( ZERO	plot view		)
	( ONE	plot setup view		)
	( TWO	numeric view		)
	( THREE	numeric setup view	)
	( FOUR	symbolic view		)
	( FIVE	symbolic. setup view	)
	( SIX	note view		)
	( SEVEN	sketch view		)

	( PASS SAVED DATA THROUGH STACK )
	TopicVar1@

	ARMCode@
	xPrRUN

	( STORE POSSIBLY MODIFIED DATA )
	TopicVar1!

	( DROP THE VIEW NUMBER )
	DROP
;


NAMELESS _Exit
::
	( SAVE APLET DATA AS PERMANENT )
	HPGCCData@
	INNERCOMP
	TopicVar1@
	ROTDROPSWAP
	{}N
	HPGCCData!

	LeaveGraphView
;


NAMELESS _Reset
* ADD/REMOVE THE NOP BELOW TO KEEP THE BYTE-ALIGNMENT
::
	HPGCCData@
	INNERCOMP
	NULL{}
	ROTDROPSWAP
* {}N
	HPGCCData!
;


ASSEMBLE
endCode
RPL


* PARAMETER
ASSEMBLE
	Vfield DirVar,DirCode
RPL

{
	$ "ARMCODE HERE!!!"
	( APPLICATION CUSTOM DATA HERE )
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
