ASSEMBLE
	CLRLIST ALL
RPL

* Turn Off Assembly Listing 1.1
**miscdoc+*******************************************^******
************************************************************
**
** File:    OffList.h Version 1.0, 23/03/00
** Machine: Enterprise
**
************************************************************
**+miscdoc**************************************************

**miscdoc+**************************************************
************************************************************
**
**  This file turns off the assembly listing so the contents
**  of "Header.h" are not shown in every listing that
**  includes "Header.h".
**
**  The last file in "Header.h" should be "OnList.h", to 
**  turn back on the assembly listing.
**
************************************************************
**+miscdoc**************************************************
RPL		( insure RPL-mode exit )
*************************************************************************
*
*       File:	Dftault.h Version 1.8, 04/17/95
*       DEFINE statements for all the Variables Dftault Values.
*
*************************************************************************

*** Default for Shared Topic Variables
DEFINE DftXmin		% -6.5
DEFINE DftXmax		% 6.5
DEFINE DftYmin		% -3.1
DEFINE DftYmax		% 3.2
DEFINE DftHTick 	% 1
DEFINE DftVTick 	% 1
DEFINE DftHZoom 	% 4
DEFINE DftVZoom 	% 4
DEFINE DftAngle		# 2	( Rad )
DEFINE DftTStart	% 0
DEFINE DftTStep		% 0.1
DEFINE DftTZoom		% 4
DEFINE DftTFlags	0
DEFINE DftFormat	# 1
DEFINE DftDigits	# 0

*** Default for Polar
DEFINE DftThetaMin      % 0
DEFINE DftThetaMax      % 6.28318530718         ( %2PI )
DEFINE DftThetaStp      % 0.1308996939          ( %PI/24 )

*** Default for Paramatric
DEFINE DftTmin          % 0
DEFINE DftTmax          % 12
DEFINE DftPStep         % 0.1

*** Default for Sequence
DEFINE DftSeqXmin       % -2
DEFINE DftSeqXmax       % 24
DEFINE DftSeqYmin	% -2
DEFINE DftSeqYmax	% 10.6
DEFINE DftSeqNmin       % 1
DEFINE DftSeqNmax       % 24
DEFINE DftSeqType       # 1
DEFINE DftSeqTStart     % 1
DEFINE DftSeqTStep      % 1

*** Default for Solve
DEFINE DftSolveTcol     # 1
DEFINE DftSolveTrow     # 1

*** Default for Statistics
DEFINE DftStatXmin      % -2
DEFINE DftStatXmax      % 24
DEFINE DftStatYmin      % -2
DEFINE DftStatYmax      % 10.6
DEFINE DftStatType      # 1	( 1=1Var, 2=2Var Statistic )
DEFINE DftStatPlot	# 1	( 1=Histogram, 2=BoxWhisker )
DEFINE DftHisWidth	% 1
DEFINE DftHmin		% 0
DEFINE DftHmax		% 20

DEFINE DftStatMark	# 54321
DEFINE DftStatModel	# 11111
RPL		( insure RPL-mode exit )
** 	Charlemagne System Flags 1.1
**miscdoc+**************************************************
************************************************************
**
** File:    SysFlags.h Version 1.1, 07/01/94
** Machine: Charlemagne
**
************************************************************
**+miscdoc**************************************************

**miscdoc+**************************************************
************************************************************
**
** Default system flag values
**
**   These equates define the system flag values to be used 
**   when the machine is reset.  The exact value depends on
**   the system flag number assignments and the individual
**   system flag default values.
**
************************************************************
**+miscdoc**************************************************
ASSEMBLE
DefSysF64-33 EQU	#00000002
DefSysF32-01 EQU	#04010FF0
DefSysF65-96 EQU	#42000000       Just Algebraic Mode is On by Default
DefSysF97-128 EQU	#00000000
**		"103F" specifies binary integer wordsize of 64;, RAD
**		all other flags are clear
RPL

**miscdoc+**************************************************
************************************************************
**
** System flag RPL number assignments
**
**   All states represented by multiple flags should
**   start on a flag number nibble boundary (e.g., 1, 5, ...)
**   for more efficient code.
**
**   All single-bit flags should by default be CLEAR.  For
**   example, the "last arguments" mode is enabled (the default)
**   when "fnLastArgs" is CLEAR.
**
************************************************************
**+miscdoc**************************************************

**
** Symbolic math system flags:
**
DEFINE fnSolutions	ONE		( solution mode )
DEFINE fnConstants	TWO		( constants mode )
DEFINE fnResults	THREE		( results mode )
DEFINE fnCareful	FOUR		( careful evaluation mode )

**
** Binary integer math system flags:
**
DEFINE fnBinWordS1	FIVE		( binary integer wordsize )
  ( must start on nibble boundary )
DEFINE fnBinWordS2	SIX
DEFINE fnBinWordS3	SEVEN
DEFINE fnBinWordS4	EIGHT
DEFINE fnBinWordS5	NINE
DEFINE fnBinWordS6	TEN
DEFINE fnBinBase1	ELEVEN		( binary integer base )
  ( must follow "fnBinWordS6" )
DEFINE fnBinBase2	TWELVE

**
** Floating-point math system flags:
**
DEFINE fnPmtMode	FOURTEEN	( financial BEGIN/END mode )
DEFINE fnComVecDi1	FIFTEEN		( complex number and vector
					mode )
DEFINE fnComVecDi2	SIXTEEN
DEFINE fnAngle1		SEVENTEEN	( angle mode )
  ( must start on a nibble boundary )
DEFINE fnAngle2		EIGHTEEN
DEFINE fnComplex2D	NINETEEN	( complex 2D mode )
DEFINE fnUnderfAct	TWENTY		( underflow action )
DEFINE fnOverfAct	TWENTYONE	( overflow action )
DEFINE fnInfResAct	TWENTYTWO	( infinite result action )
DEFINE fnUnderfNeg	TWENTYTHREE	( underflow-negative indicator )
DEFINE fnUnderfPos	TWENTYFOUR	( underflow-positive indicator )
DEFINE fnOverflow	TWENTYFIVE	( overflow indicator )
DEFINE fnInfResult	TWENTYSIX	( infinite result indicator )
DEFINE fnSymbCx         TWENTYSEVEN     ( symbolic-comples decompilation )
**
** Plotting, I/O, and printing system flags:
**
DEFINE fnSimuPlot	TWENTYEIGHT	( simultaneous plot mode )
DEFINE fnAxesPlot	TWENTYNINE	( axis drawing plot mode )
DEFINE fnPlotBoth	THIRTY		( plot both LHS & RHS even if LHS is ID )
DEFINE fnConnectPt	THIRTYONE	( connect points mode )
DEFINE fnGCursor        THIRTYTWO	( graphics cursor type mode )
DEFINE fnIODevice	THIRTYTHREE	( I/O device )
DEFINE fnPrintDev	THIRTYFOUR	( print device )
DEFINE fnIODataFmt	THIRTYFIVE	( I/O data format )
DEFINE fnOverwrite      THIRTYSIX	( variable overwrite mode )
DEFINE fnDblSpace	THIRTYSEVEN	( double-space print mode )
DEFINE fnNoAutoCR	THIRTYEIGHT	( suppress auto CR mode )
DEFINE fnNoIOStsMsg	THIRTYNINE	( suppress I/O status messages )


**
** Time management system flags:
**
DEFINE fnClockOn	FORTY		( clock display mode )
DEFINE fnClockFmt	FORTYONE	( clock display format )
DEFINE fnDateFmt	FORTYTWO	( date format )
DEFINE fnResRepAlm	FORTYTHREE	( reschedule unacknowledged
					repeat alarms mode )
DEFINE fnDelNRAlm	FORTYFOUR	( delete acknowledged non-repeat
					alarms mode )

**
** Display format system flags:
**
DEFINE fnNumDigs1	FORTYFIVE	( number of decimal digits )
  ( must start on nibble boundary )
DEFINE fnNumDigs2	FORTYSIX
DEFINE fnNumDigs3	FORTYSEVEN
DEFINE fnNumDigs4	FIRTYEIGHT
DEFINE fnNumDisp1	FORTYNINE	( number display format )
  ( must start on nibble boundary )
DEFINE fnNumDisp2	FIFTY
DEFINE fnRadix		FIFTYONE	( radix mark )
DEFINE fnMultiDisp	FIFTYTWO	( multi-line display mode )
DEFINE fnShowPrec	FIFTYTHREE	( show precedence mode )
DEFINE fnIgnoreTiny	FIFTYFOUR	( zero out tiny matrix elements )

**
** Miscellaneous system flags:
**
DEFINE fnLastArgs	FIFTYFIVE	( last arguments mode )
DEFINE fnErrorBeep	FIFTYSIX	( error beep mode )
DEFINE fnAlarmBeep	FIFTYSEVEN	( alarm beep mode )
DEFINE fnVerbose	FIFTYEIGHT	( verbose display mode )
DEFINE fnNameOnly	FIFTYNINE	( variable name only mode  )
DEFINE fnTriAlpha	SIXTY		( 3-way alpha mode )
DEFINE fnTriUser	SIXTYONE	( 3-way user keys mode )
DEFINE fnUserKeys	SIXTYTWO	( user keys mode )
DEFINE fnNoParse	SIXTYTHREE	( special parser mode )
DEFINE fnIndexWrap	SIXTYFOUR	( index wraparound indicator )

**miscdoc+**************************************************
************************************************************
**
** System flag assembly number assignments
**
**   See "System flag RPL number assignments" for flag 
**   descriptions
**
************************************************************
**+miscdoc**************************************************

ASSEMBLE
**
** Symbolic math system flags:
**
SolutionsFl  EQU 1
ConstantsFl  EQU 2
ResultsFl    EQU 3
CarefulFl    EQU 4

**
** Binary integer math system flags:
**
BinWordSFl1  EQU 5	must start on a nibble boundary
BinWordSBCt  EQU 6	number of bits
** Flag 2    EQU 6
** Flag 3    EQU 7
** Flag 4    EQU 8
** Flag 5    EQU 9
** Flag 6    EQU 10
BinBaseFl1   EQU 11	must follow "BinWordSFl6"
BinBaseBCt   EQU 2	number of bits
** Flag 2    EQU 12

**
** Floating-point math system flags:
**
ComVecDiFl1  EQU 15
ComVecDiBCt  EQU 2	number of bits
** Flag2     EQU 16
AngleFl1     EQU 17	must start on a nibble boundary
AngleBCt     EQU 2	number of bits
** Flag2     EQU 18
Complex2DFl  EQU 19
UnderfActFl  EQU 20
OverfActFl   EQU 21
InfResActFl  EQU 22
UnderfNegFl  EQU 23
UnderfPosFl  EQU 24
OverflowFl   EQU 25
InfResultFl  EQU 26

**
** Plotting, I/O, and printing system flags:
**
FunctPlotFl  EQU 30
ConnectPtFl  EQU 31
GCursorFl    EQU 32
IODeviceFl   EQU 33
PrintDevFl   EQU 34
IODataFmtFl  EQU 35
OverwriteFl  EQU 36
DblSpaceFl   EQU 37
NoAutoCRFl   EQU 38
NoIOStsMsgFl EQU 39

**
** Time management system flags:
**
ClockOnFl    EQU 40
ClockFmtFl   EQU 41
DateFmtFl    EQU 42
ResRepAlmFl  EQU 43
DelNRAlmFl   EQU 44

**
** Display format system flags:
**
NumDigsFl1   EQU 45	must start on a nibble boundary
NumDigsBCt   EQU 4	number of bits
** Flag2     EQU 46
** Flag3     EQU 47
** Flag4     EQU 48
NumDispFl1   EQU 49	must start on a nibble boundary
NumDispBCt   EQU 2	number of bits
** Flag2     EQU 50
RadixFl      EQU 51
MultiDispFl  EQU 52
ShowPrecFl   EQU 53

**
** Miscellaneous system flags:
**
LastArgsFl   EQU 55
ErrorBeepFl  EQU 56
AlarmBeepFl  EQU 57
VerboseFl    EQU 58
FastEqViewFl EQU 59
TriAlphaFl   EQU 60
TriUserFl    EQU 61
UserKeysFl   EQU 62
NoParseFl    EQU 63
IndexWrapFl  EQU 64


**miscdoc+**************************************************
************************************************************
**
**  System flag computed nibble and bit assignments
**
************************************************************
**+miscdoc**************************************************

AlarmBeepNib EQU ((AlarmBeepFl)-1)/4
AlarmBeepBit EQU ((AlarmBeepFl)-1)%4

AngleNib     EQU ((AngleFl1)-1)/4
AngleBit1    EQU ((AngleFl1)-1)%4
AngleBit2    EQU (AngleBit1)+1

BinBaseNib   EQU ((BinBaseFl1)-1)/4
BinBaseBit1  EQU ((BinBaseFl1)-1)%4

BinWordSNib  EQU ((BinWordSFl1)-1)/4
BinWordSBit1 EQU ((BinWordSFl1)-1)%4

CarefulNib   EQU ((CarefulFl)-1)/4
CarefulBit   EQU ((CarefulFl)-1)%4

ClockFmtNib  EQU ((ClockFmtFl)-1)/4
ClockFmtBit  EQU ((ClockFmtFl)-1)%4

ClockOnNib   EQU ((ClockOnFl)-1)/4
ClockOnBit   EQU ((ClockOnFl)-1)%4

Complex2DNib EQU ((Complex2DFl)-1)/4
Complex2DBit EQU ((Complex2DFl)-1)%4

ComVecDiNib  EQU ((ComVecDiFl1)-1)/4
ComVecDiBit1 EQU ((ComVecDiFl1)-1)%4

ConnectPtNib EQU ((ConnectPtFl)-1)/4
ConnectPtBit EQU ((ConnectPtFl)-1)%4

ConstantsNib EQU ((ConstantsFl)-1)/4
ConstantsBit EQU ((ConstantsFl)-1)%4

DateFmtNib   EQU ((DateFmtFl)-1)/4
DateFmtBit   EQU ((DateFmtFl)-1)%4

DblSpaceNib  EQU ((DblSpaceFl)-1)/4
DblSpaceBit  EQU ((DblSpaceFl)-1)%4

DelNRAlmNib  EQU ((DelNRAlmFl)-1)/4
DelNRAlmBit  EQU ((DelNRAlmFl)-1)%4

ErrorBeepNib EQU ((ErrorBeepFl)-1)/4
ErrorBeepBit EQU ((ErrorBeepFl)-1)%4

FastEViewNib EQU ((FastEqViewFl)-1)/4
FastEViewBit EQU ((FastEqViewFl)-1)%4

FunctPlotNib EQU ((FunctPlotFl)-1)/4
FunctPlotBit EQU ((FunctPlotFl)-1)%4

GCursorNib   EQU ((GCursorFl)-1)/4
GCursorBit   EQU ((GCursorFl)-1)%4

IndexWrapNib EQU ((IndexWrapFl)-1)/4
IndexWrapBit EQU ((IndexWrapFl)-1)%4

InfResActNib EQU ((InfResActFl)-1)/4
InfResActBit EQU ((InfResActFl)-1)%4

InfResultNib EQU ((InfResultFl)-1)/4
InfResultBit EQU ((InfResultFl)-1)%4

IODataFmtNib EQU ((IODataFmtFl)-1)/4
IODataFmtBit EQU ((IODataFmtFl)-1)%4

IODeviceNib  EQU ((IODeviceFl)-1)/4
IODeviceBit  EQU ((IODeviceFl)-1)%4

LastArgsNib  EQU ((LastArgsFl)-1)/4
LastArgsBit  EQU ((LastArgsFl)-1)%4

VerboseNib   EQU ((VerboseFl)-1)/4
VerboseBit   EQU ((VerboseFl)-1)%4

MultiDispNib EQU ((MultiDispFl)-1)/4
MultiDispBit EQU ((MultiDispFl)-1)%4

NoAutoCRNib  EQU ((NoAutoCRFl)-1)/4
NoAutoCRBit  EQU ((NoAutoCRFl)-1)%4

NoIOStMsgNib EQU ((NoIOStsMsgFl)-1)/4
NoIOStMsgBit EQU ((NoIOStsMsgFl)-1)%4

NoParseNib   EQU ((NoParseFl)-1)/4
NoParseBit   EQU ((NoParseFl)-1)%4

NumDigsNib   EQU ((NumDigsFl1)-1)/4
NumDigsBit1  EQU ((NumDigsFl1)-1)%4

NumDispNib   EQU ((NumDispFl1)-1)/4
NumDispBit1  EQU ((NumDispFl1)-1)%4

OverfActNib  EQU ((OverfActFl)-1)/4
OverfActBit  EQU ((OverfActFl)-1)%4

OverflowNib  EQU ((OverflowFl)-1)/4
OverflowBit  EQU ((OverflowFl)-1)%4

OverwriteNib EQU ((OverwriteFl)-1)/4
OverwriteBit EQU ((OverwriteFl)-1)%4

PrintDevNib  EQU ((PrintDevFl)-1)/4
PrintDevBit  EQU ((PrintDevFl)-1)%4

RadixNib     EQU ((RadixFl)-1)/4
RadixBit     EQU ((RadixFl)-1)%4

ResRepAlmNib EQU ((ResRepAlmFl)-1)/4
ResRepAlmBit EQU ((ResRepAlmFl)-1)%4

ResultsNib   EQU ((ResultsFl)-1)/4
ResultsBit   EQU ((ResultsFl)-1)%4

ShowPrecNib  EQU ((ShowPrecFl)-1)/4
ShowPrecBit  EQU ((ShowPrecFl)-1)%4

SolutionsNib EQU ((SolutionsFl)-1)/4
SolutionsBit EQU ((SolutionsFl)-1)%4

TriAlphaNib  EQU ((TriAlphaFl)-1)/4
TriAlphaBit  EQU ((TriAlphaFl)-1)%4

TriUserNib   EQU ((TriUserFl)-1)/4
TriUserBit   EQU ((TriUserFl)-1)%4

UnderfActNib EQU ((UnderfActFl)-1)/4
UnderfActBit EQU ((UnderfActFl)-1)%4

UnderfNegNib EQU ((UnderfNegFl)-1)/4
UnderfNegBit EQU ((UnderfNegFl)-1)%4

UnderfPosNib EQU ((UnderfPosFl)-1)/4
UnderfPosBit EQU ((UnderfPosFl)-1)%4

UserKeysNib  EQU ((UserKeysFl)-1)/4
UserKeysBit  EQU ((UserKeysFl)-1)%4

RPL
RPL		( insure RPL-mode exit )
** Non-Macro Property Lists Symbols 1.28
**miscdoc+**************************************************
************************************************************ 
**
** File:    PropList.h Version 1.30, 05/30/95
** Machine: Charlemagne
**
************************************************************
**+miscdoc**************************************************

**miscdoc+**************************************************
************************************************************ 
**
**	This file contains equates defining 
**	property-list bits and parse-data for non-macro 
**      romwords.  (Equates for macros are defined elsewhere.)
**
************************************************************
**
**  History:	6 JUL 88	Created by CP & MJ
**
************************************************************
**+miscdoc**************************************************

**miscdoc+**************************************************
************************************************************ 
**
**	Equates for Property-List Bits
**
**	These equates (and the implied order of the properties) 
**	must be consistent with the property-list bits for 
**	macros as defined elsewhere.
**
************************************************************
**+miscdoc**************************************************
ASSEMBLE

* most significant nibble equates:

nonALG EQU 8			not-allowed-in-algebraics flag 
hasHELP EQU 4			has-help-data flag
hasPROMPTM EQU 4		same as above
hasALIAS EQU 2			has-algebraic-alias flag
hasPDATA EQU 1			has-parse-data flag

* the remaining equates are only relevant for algebraic functions.
* next most significant nibble equates:

hasDER EQU 8			has-derivative flag
hasINV EQU 4			has-inverse flag
hasCOLCT EQU 2			has-COLCT-data flag
hasEXPND EQU 1			has-EXPND-data flag

* least significant nibble equates:

hasFORM EQU 8			has-FORM-menu flag
hasINTG EQU 4			has-Integral-data flag
hasWHERE EQU 2			has-WHERE-code flag
hasVUNS EQU 1			has-veryunsymin-code flag

**miscdoc+**************************************************
************************************************************ 
**
**	Equates for Parse-Data
**
**	Each equate name has the structure:
**
**		 pd<component abbreviation>
**
**	where the component abbreviation is that of the ERS
**	section on parsing symbolic objects.
**
************************************************************
**+miscdoc**************************************************

pdEX EQU #0		general expression
pdOP EQU #1		operator
pdQE EQU #2		quoted expression
pdQN EQU #3		quoted name
pdLP EQU #4		left parenthesis
pdRP EQU #5		right parenthesis
pdCM EQU #6		comma (non-radix)
pdEQ EQU #7		equal-sign separator
pdOS0 EQU #8		optional repeat 0
pdOS1 EQU #9		optional repeat 1
pdOS2 EQU #A		optional repeat 2
pdOS3 EQU #B		optional repeat 3
pdOS4 EQU #C		optional repeat 4
pdOS5 EQU #D		optional repeat 5
pdOS6 EQU #E		optional repeat 6
pdOS7 EQU #F		optional repeat 7

RPL

**miscdoc+**************************************************
************************************************************
**
** Defines for plot type property lists
**
************************************************************
**+miscdoc**************************************************
DEFINE ViewUI_loc ONE
DEFINE SetupUI_loc TWO
DEFINE DrTkOvr# THREE
DEFINE DrwDptch# FOUR
DEFINE PlIndVar#  FIVE
DEFINE FnNames# SIX
DEFINE PltCleanup#  SEVEN
DEFINE AxesDsrd# EIGHT
DEFINE TraceProp# NINE
DEFINE HasFcnFlg# TEN
DEFINE CrunchProc#  ELEVEN
DEFINE ShowP# TWELVE
DEFINE DefResProc# THIRTEEN
DEFINE IsStat# FOURTEEN
DEFINE PrgDpnd# FIFTEEN
DEFINE newXend# SIXTEEN
DEFINE PointDsp# SEVENTEEN
DEFINE PointXit# EIGHTEEN
DEFINE PointErr# NINETEEN
DEFINE PointMenu# TWENTY
DEFINE AutoSc# TWENTYONE
DEFINE PlotLoop# TWENTYTWO
DEFINE ShowProc# TWENTYTHREE
DEFINE GridDsrd# TWENTYFOUR
DEFINE AxisLabels# TWENTYFIVE
DEFINE IndepVal# TWENTYSIX

**miscdoc+**************************************************
**
** Defines for Interactive Plotting trace sublist
**    { Coordinate_display
**      Cursor_movement_handler
**      { TraceInit SplitTraceInit }
**      { DispX     DispY          )
**      Not_used ( Enter_loc )
**      topic_specific interactive plot init ( called by PlotInteractInit )
**      UpdateCross
**    }
**
**+miscdoc**************************************************
DEFINE COORD_h_loc   ONE
DEFINE ARROW_h_loc   TWO
DEFINE Init_h_loc    THREE
DEFINE XY_h_loc      FOUR
DEFINE Enter_loc     FIVE
DEFINE InitIP_h_loc  SIX
DEFINE UpdCrs_h_loc  SEVEN

**miscdoc+**************************************************
************************************************************
**
** Defines for Table Type type property lists
**
************************************************************
**+miscdoc**************************************************
DEFINE TBGroupLoc# THREE
DEFINE TBZoomLoc# FOUR
DEFINE TBDecompLoc# FIVE
DEFINE TSDefSplitRow# SIX
DEFINE TSSplitRows# SEVEN
DEFINE TSErrorLoc# EIGHT
DEFINE TSComplexLoc# NINE
DEFINE TSPlot>Loc# TEN
**miscdoc+**************************************************
************************************************************
**
** Defines for Topic Type type property lists
**
************************************************************
**+miscdoc**************************************************
DEFINE InstanceBint#	ONE
DEFINE TopicEntry#	TWO
DEFINE TopicExit#	THREE
DEFINE Topic1stView#	FOUR
DEFINE TopicText#	FIVE
DEFINE AltViews#	SIX
DEFINE DirectoryChk#	SEVEN
DEFINE ApletVars#	EIGHT
DEFINE ApletReset#	NINE

**miscdoc+**************************************************
************************************************************
**
** Defines for Topic Type-List Locations
**
************************************************************
**+miscdoc**************************************************
DEFINE TopicTyp_loc ONE
DEFINE PlotTyp_loc  TWO
DEFINE TableTyp_loc THREE
DEFINE SymbTyp_loc  FOUR
DEFINE NoteTyp_loc  FIVE
DEFINE PictTyp_loc  SIX

**miscdoc+**************************************************
************************************************************
**
** Defines for Topic Instance Bints
**
************************************************************
**+miscdoc**************************************************
DEFINE funcPTR# ZERO
DEFINE polarPTR# ONE
DEFINE paramPTR# TWO
DEFINE seqPTR# THREE
DEFINE statPTR# FOUR
DEFINE solvePTR# FIVE
DEFINE otherPTR# SIX

RPL		( insure RPL-mode exit )
**	TITLE Key Code and Plane Definitions 1.8
**miscdoc+*******************************************^******
************************************************************
**
** File:    KeyCodes.h Version 1.8, 01/17/95
**
************************************************************
**+miscdoc**************************************************

**miscdoc+**************************************************
************************************************************
**
** The key plane definitions here are listed in numerical
** order.  All names begin with "kp" (to indicate a "k"ey 
** "p"lane), and the names describe the key plane specified.
**
************************************************************
**+miscdoc**************************************************

DEFINE kpNoShift	ONE
DEFINE kpLeftShift	TWO
DEFINE kpRightShift	TWO
DEFINE kpANoShift	FOUR
DEFINE kpALeftShift	FIVE
DEFINE kpARightShft	FIVE

**miscdoc+**************************************************
************************************************************
**
** The key code definitions here are listed in numerical
** order.  All names begin with "kc" (to indicate a "k"ey 
** "c"ode), and names are chosen to best describe the primary
** operation of the key.
**
************************************************************
**+miscdoc**************************************************

**
** For backwards compatibility:
**
DEFINE kcBackspace	BINT21

**
** Unshifted key codes:
**

DEFINE kcSoftKey1	ONE
DEFINE kcSoftKey2	TWO
DEFINE kcSoftKey3	THREE
DEFINE kcSoftKey4	FOUR
DEFINE kcSoftKey5	FIVE
DEFINE kcSoftKey6	SIX

DEFINE kcPlotView	EIGHT
DEFINE kcSymbView	SEVEN
DEFINE kcNumView	NINE
( unused key )
DEFINE kcUpArrow	TEN
( unused key )

DEFINE kcHome		BINT11
DEFINE kcLibrary	BINT12
DEFINE kcSplitView	THIRTEEN
DEFINE kcLeftArrow	BINT14
DEFINE kcDownArrow	BINT15
DEFINE kcRightArrow	BINT16

DEFINE kcVarsMenu	BINT17
DEFINE kcMathMenu	BINT18
DEFINE kcDer		BINT19
DEFINE kcXTTheta   	BINT20
DEFINE kcDel 		BINT21

DEFINE kcSin		BINT22
DEFINE kcCos		BINT23
DEFINE kcTan		BINT24
DEFINE kcNaturalLog	BINT25
DEFINE kcDecimalLog	BINT26

DEFINE kcSqr		BINT27
DEFINE kcPower		BINT28
DEFINE kcLeftParen	BINT29
DEFINE kcRightParen	BINT30
DEFINE kcDivide		BINT31

DEFINE kcComma		BINT32
DEFINE kc7		BINT33
DEFINE kc8		BINT34
DEFINE kc9		BINT35
DEFINE kcTimes		BINT36

DEFINE kcAlpha		BINT37
DEFINE kc4		BINT38
DEFINE kc5		BINT39
DEFINE kc6		BINT40
DEFINE kcMinus		BINT41

DEFINE kcRightShift	BINT42
DEFINE kcLeftShift	BINT42
DEFINE kc1		BINT43
DEFINE kc2		BINT44
DEFINE kc3		BINT45
DEFINE kcPlus		BINT46

DEFINE kcOn		BINT47
DEFINE kc0		BINT48
DEFINE kcPeriod		BINT49
DEFINE kcNegate		BINT50
DEFINE kcEnter		BINT51


**
** Left-shifted key codes:
**

DEFINE kcSymbSetupView	BINT7
DEFINE kcPlotSetupView	BINT8
DEFINE kcNumSetupView	NINE

DEFINE kcModes		BINT11
DEFINE kcNotesView	BINT12
DEFINE kcPictView	BINT13


DEFINE kcChars		BINT17
DEFINE kcCmds		BINT18
DEFINE kcIntegral	BINT19
DEFINE kcEnterExp	BINT20
DEFINE kcClear		BINT21

DEFINE kcAsin		BINT22
DEFINE kcAcos		BINT23
DEFINE kcAtan		BINT24
DEFINE kcLog		BINT25
DEFINE kcAlog		BINT26

DEFINE kcSqrt		BINT27
DEFINE kcNthRoot	BINT28
DEFINE kcAbs		BINT29
DEFINE kcArg		BINT30
DEFINE kcInverse	BINT31

DEFINE kcMemory		BINT32
DEFINE kcListTask	BINT33
DEFINE kc{		BINT34
DEFINE kc}		BINT35
DEFINE kcFactorial	BINT36

DEFINE kcUpperAlpha	BINT37
DEFINE kcMatrix         BINT38
DEFINE kc[		BINT39
DEFINE kc]		BINT40
DEFINE kcAngle		BINT41


DEFINE kcProgramTask	BINT43
DEFINE kcHelp		BINT44
DEFINE kcPI		BINT45
DEFINE kcSigma		BINT46

DEFINE kcOff		BINT47
DEFINE kcNotes		BINT48
DEFINE kcEqual		BINT49
DEFINE kcAnd		BINT50
DEFINE kcAnswer		BINT51

RPL		( insure RPL-mode exit )
**	TITLE Topic Outer Loop Defines 1.1
**miscdoc+*******************************************^******
************************************************************
**
** File:    TopicOuterLoop.h Version 1.1, 10/28/94
**
************************************************************
**+miscdoc**************************************************

**
** Topic outer loop reserved TOL vars:
**
DEFINE TOLRESVARSEND+1	FIVE
**
DEFINE TopicEntry!	TOLVar1!
DEFINE TopicEntry@	TOLVar1@
DEFINE TopicEntryDo	TOLVar1@ EVAL
DEFINE TopicExit!	TOLVar2!
DEFINE TopicExit@	TOLVar2@
DEFINE TopicExitDo	TOLVar2@ EVAL
DEFINE ViewEntry!	TOLVar3!
DEFINE ViewEntry@	TOLVar3@
DEFINE ViewEntryDo	TOLVar3@ EVAL
DEFINE ViewExit!	TOLVar4!
DEFINE ViewExit@	TOLVar4@
DEFINE ViewExitDo	TOLVar4@ EVAL
RPL		( insure RPL-mode exit )
**miscdoc+*******************************************^******
************************************************************
**
** File:    InputForm.h Version 1.7, 03/08/95
** Machine: Alcuin
**
** Input Form macros and equates
**
************************************************************
**+miscdoc**************************************************

**
** Input form event messages:
**
DEFINE IFM_DISPTITLE		ONE
DEFINE IFM_SETTITLEGROB	   	TWO
DEFINE IFM_SETTITLEDECOMP	THREE
DEFINE IFM_DISPCLIENT	    	FOUR
DEFINE IFM_SETCLIENTBACK	FIVE
DEFINE IFM_DISPLABEL		SIX
DEFINE IFM_DISPFIELD		SEVEN
DEFINE IFM_SETIFKEYOB	   	EIGHT
DEFINE IFM_SETFGROB	   	NINE
DEFINE IFM_SETFDECOMP	   	TEN
DEFINE IFM_DISPHELP		ELEVEN
DEFINE IFM_SETHELPGROB	   	TWELVE
DEFINE IFM_SETHELPDECOMP	THIRTEEN
DEFINE IFM_SETINITFOCUSFID	FOURTEEN
DEFINE IFM_SETINPFORMMENU	FIFTEEN
DEFINE IFM_SETAPPMENUKEYS	SIXTEEN
DEFINE IFM_POSTCREATE		SEVENTEEN
DEFINE IFM_SETKEYOB	   	EIGHTEEN
DEFINE IFM_LOSTFOCUS	 	NINETEEN
DEFINE IFM_GOTFOCUS	 	TWENTY
DEFINE IFM_UNSHOWSEL		TWENTYONE
DEFINE IFM_SHOWSEL		TWENTYTWO
DEFINE IFM_EDITFIELD	 	TWENTYTHREE
DEFINE IFM_PARSE	 	TWENTYFOUR
DEFINE IFM_POSTPARSE	   	TWENTYFIVE
DEFINE IFM_CHOOSE	 	TWENTYSIX
DEFINE IFM_CHECK	  	TWENTYSEVEN
DEFINE IFM_QUIT		 	TWENTYEIGHT
DEFINE IFM_DONE		 	TWENTYNINE
DEFINE IFM_RESET	    	THIRTYONE
DEFINE IFM_SETRESETCHOICES	THIRTYTWO
DEFINE IFM_RESETFIELD	   	THIRTYTHREE
DEFINE IFM_RESETALL	    	THIRTYFOUR
DEFINE IFM_DISPOBTYPES	   	THIRTYFIVE
DEFINE IFM_SETOBTYPEDESCS    	THIRTYSIX
DEFINE IFM_GETCHOICE	   	THIRTYSEVEN
DEFINE IFM_CHOOSENEXT	  	THIRTYEIGHT
DEFINE IFM_CHOOSEBYCHR	 	THIRTYNINE
DEFINE IFM_SETCHOICES	 	FORTY
DEFINE IFM_SETUSERVALUE		FORTYONE
DEFINE IFM_SETEDLINEMENU    	FORTYTWO
DEFINE IFM_SETAPPEDLMENUKEYS	FORTYTHREE
DEFINE IFM_ENDEDIT&STO	    	FORTYFOUR
DEFINE IFM_CHKOBTYPE	   	FORTYFIVE
DEFINE IFM_CHKOBVALUE	   	FORTYSIX
DEFINE IFM_POSTCHANGE		FORTYSEVEN
DEFINE IFM_SETDOWNFID	   	FORTYEIGHT
DEFINE IFM_SETUPFID	   	FORTYNINE
DEFINE IFM_SETFARDOWNFID	FIFTY
DEFINE IFM_SETFARUPFID		FIFTYONE
DEFINE IFM_SETNEXTFID		FIFTYTWO
DEFINE IFM_SETPREVFID		FIFTYTHREE
DEFINE IFM_SETNEXTFOCUSFID   	FIFTYFOUR
DEFINE IFM_SETFOCUSOK?	   	FIFTYFIVE
DEFINE IFM_POSTDONE	   	FIFTYSIX

** 
** Input form display area management:
**
** Title=DA1 Client=DA2a Help=DA2b(no edit) Edit=DA2b(edit) Menu=DA3
**
DEFINE TitleOK?		DA1OK?
DEFINE ClientOK?	:: DA2aOK? DA2aLess1OK? ClrNewEditL OR ;
DEFINE EditOK?		:: NoEditLine? caseTRUE   DA2bOK? ;
DEFINE HelpOK?		:: EditLExists? caseTRUE  DA2bOK? ;
DEFINE MenuOK?		DA3OK?
DEFINE HelpTemp?	DA2bTemp?
DEFINE ClientBad?	DA2aBad?
DEFINE HelpBad?		DA2bBad?
DEFINE SetTValid	SetDA1Valid
DEFINE SetCValid	SetDA2aValid
DEFINE SetEValid	SetDA2bValid
DEFINE SetHValid	SetDA2bValid
DEFINE SetMValid	SetDA3Valid
DEFINE SetTNoCh		SetDA1NoCh
DEFINE SetCNoCh		SetDA2aNoCh
DEFINE SetENoCh		SetDA2bNoCh
DEFINE SetHNoCh		SetDA2bNoCh
DEFINE SetMNoCh		SetDA3NoCh
DEFINE SetCTemp		SetDA2aTemp
DEFINE SetETemp		SetDA2bTemp
DEFINE SetHTemp		SetDA2bTemp
DEFINE SetTBad		SetDA1Bad
DEFINE SetCBad		SetDA2aBad
DEFINE SetEBad		SetDA2bBad
DEFINE SetHBad		SetDA2bBad
DEFINE SetMBad		SetDA3Bad
**
DEFINE SetTCEMNoCh	:: SetTNoCh SetCNoCh SetENoCh SetMNoCh ;
DEFINE SetTCENoCh	:: SetTNoCh SetCNoCh SetENoCh ;
DEFINE SetTCHNoCh	:: SetTNoCh SetCNoCh SetHNoCh ;
DEFINE SetTCMNoCh	:: SetTNoCh SetCNoCh SetMNoCh ;
DEFINE SetTCNoCh	:: SetTNoCh SetCNoCh ;
DEFINE SetCMNoCh	:: SetCNoCh SetMNoCh ;
DEFINE SetTMNoCh	:: SetTNoCh SetMNoCh ;
DEFINE SetTHMNoCh	:: SetTNoCh SetHNoCh SetMNoCh ;
DEFINE SetAllNoCh	SetDAsNoCh
DEFINE SetCHMBad	:: SetCBad SetHBad SetMBad ;
DEFINE ClrAllOK		ClrDAsOK


**
** Input form field types:
**
DEFINE FTYPE_NA		ZERO

DEFINE FTYPE_TEXT	ONE
DEFINE FTYPE_TTAUTOALG  TWO
DEFINE FTYPE_ALGTEXT    THREE

DEFINE FTYPE_LIST	FOUR
DEFINE FTYPE_LTFIXED	EIGHT
DEFINE FTYPE_LTMEMOB	SIXTEEN
DEFINE FTYPE_FIXEDLIST	TWELVE
DEFINE FTYPE_MEMOBLIST	TWENTY

DEFINE FTYPE_CHECK	THIRTYTWO

DEFINE FTYPE_AT		THREE
DEFINE FTYPE_TL		FIVE
DEFINE FTYPE_ATL	SEVEN
DEFINE FTYPE_TFL	THIRTEEN
DEFINE FTYPE_TML	TWENTYONE
DEFINE FTYPE_ATML	TWENTYTHREE

DEFINE FTYPE_TLC	THIRTYSEVEN  ( for internal use only )

**
** Input form object types:
**
DEFINE OBTYPE_NA	MINUSTWO

DEFINE OBTYPE_ANY	MINUSONE

DEFINE OBTYPE_REAL	ZERO
DEFINE OBTYPE_CMP	ONE
DEFINE OBTYPE_STR	TWO
DEFINE OBTYPE_RARRAY	THREE
DEFINE OBTYPE_CARRAY	FOUR
DEFINE OBTYPE_LIST	FIVE
DEFINE OBTYPE_ID	SIX
DEFINE OBTYPE_USERPRGM	EIGHT
DEFINE OBTYPE_SYMB	NINE
DEFINE OBTYPE_HXS	TEN
DEFINE OBTYPE_UNIT	THIRTEEN

**
** Input form decompile formats:
**
DEFINE FMT_NA		MINUSONE
DEFINE FMT_NONE		ONE
DEFINE FMT_DFLT		TWO
DEFINE FMT_STD		FOUR

DEFINE FMT_1STCHAR	EIGHT

DEFINE FMT_PART1	SIXTEEN
DEFINE FMT_PART2	THIRTYTWO

DEFINE FMT_NONE&1STCH	NINE
DEFINE FMT_P1&NONE	SEVENTEEN
DEFINE FMT_P1&DFLT	EIGHTEEN
DEFINE FMT_P1&STD	TWENTY
DEFINE FMT_P2&NONE	THIRTYTHREE
DEFINE FMT_P2&DFLT	THIRTYFOUR
DEFINE FMT_P2&STD	THIRTYSIX
DEFINE FMT_P1&NONE&1STCH  TWENTYFIVE

**
** Input form label and field standard rows and columns:
**
DEFINE LROW1		TEN
DEFINE LROW2		NINETEEN
DEFINE LROW3		TWENTYEIGHT
DEFINE LROW4		THIRTYSEVEN
DEFINE LROW5		FORTYSIX

DEFINE FROW1		EIGHT
DEFINE FROW2		SEVENTEEN
DEFINE FROW3		TWENTYSIX
DEFINE FROW4		THIRTYFIVE
DEFINE FROW5		FORTYFOUR

DEFINE COL1		ONE
DEFINE COL1+C		EIGHT
DEFINE COL1.5		FOUR
DEFINE COL1.5+C		ELEVEN
DEFINE COL2		SEVEN
DEFINE COL2+C		FOURTEEN
DEFINE COL2.5		TEN
DEFINE COL3		THIRTEEN
DEFINE COL3.5		SIXTEEN
DEFINE COL4		NINETEEN
DEFINE COL4.5		TWENTYTWO
DEFINE COL4.5+C		TWENTYNINE
DEFINE COL5		TWENTYFIVE
DEFINE COL5+C		THIRTYTWO
DEFINE COL5.5		TWENTYEIGHT
DEFINE COL6		THIRTYONE
DEFINE COL6.5		THIRTYFOUR
DEFINE COL7		THIRTYSEVEN
DEFINE COL7.5		FORTY
DEFINE COL7.5+C		FORTYSEVEN
DEFINE COL8		FORTYTHREE
DEFINE COL8+C		FIFTY
DEFINE COL8.5		FORTYSIX
DEFINE COL9		FORTYNINE
DEFINE COL9+C		FIFTYSIX
DEFINE COL9.5		FIFTYTWO
DEFINE COL10		FIFTYFIVE
DEFINE COL10+C		SIXTYTWO
DEFINE COL10.5		FIFTYEIGHT
DEFINE COL11		SIXTYONE
DEFINE COL11.5		SIXTYFOUR
DEFINE COL11.5+C	71
DEFINE COL12		FOURTHREE ( decimal 67 )
DEFINE COL12+C		SEVENTYFOUR
DEFINE COL12.5		SEVENTY
DEFINE COL13		73
DEFINE COL13+C		EIGHTY
DEFINE COL13.5		76
DEFINE COL14		SEVENTYNINE
DEFINE COL14+C		FIVESIX ( decimal 86 )
DEFINE COL14.5		LISTCMP ( decimal 82 )
DEFINE COL15		2LIST ( decimal 85 )
DEFINE COL15+C		92
DEFINE COL15.5		88
DEFINE COL15.5+C	95
DEFINE COL16		BINT_91d
DEFINE COL16+C		NINETYEIGHT
DEFINE COL16.5		94
DEFINE COL16.5+C	SIXFIVE ( decimal 101 )
DEFINE COL17		IDREAL ( decimal 97 )
DEFINE COL17+C		104
DEFINE COL17.5		IDARRY ( decimal 100 )
DEFINE COL17.5+C	107
DEFINE COL18		103
DEFINE COL18+C		110
DEFINE COL18.5		106
DEFINE COL18.5+C	LAMREAL ( decimal 113 )
DEFINE COL19		109
DEFINE COL19+C		BINT_116d
DEFINE COL19.5		lamany ( decimal 112 )
DEFINE COL19.5+C	119
DEFINE COL20		BINT_115d
DEFINE COL20+C		BINT_122d
DEFINE COL20.5		118
DEFINE COL21		121
DEFINE COL21.5		124
DEFINE COL22		127

**
** Input form standard field widths and heights:
**
DEFINE FWIDTH_C		SIX ( check width )
DEFINE CHECK_WIDTH+1	SEVEN
DEFINE FWIDTH_CHR	SIX ( field character width )

DEFINE FWIDTH1		SEVEN
DEFINE FWIDTH2		THIRTEEN
DEFINE FWIDTH3		NINETEEN
DEFINE FWIDTH4		TWENTYFIVE
DEFINE FWIDTH5		THIRTYONE
DEFINE FWIDTH6		THIRTYSEVEN
DEFINE FWIDTH7		FORTYTHREE
DEFINE FWIDTH8		FORTYNINE
DEFINE FWIDTH9		FIFTYFIVE
DEFINE FWIDTH10		SIXTYONE
DEFINE FWIDTH11		FOURTHREE ( decimal 67 )
DEFINE FWIDTH12		73
DEFINE FWIDTH13		SEVENTYNINE
DEFINE FWIDTH14		2LIST ( decimal 85 )
DEFINE FWIDTH15		BINT_91d
DEFINE FWIDTH16		IDREAL ( decimal 97 )
DEFINE FWIDTH17		103
DEFINE FWIDTH18		109
DEFINE FWIDTH19		BINT_115d
DEFINE FWIDTH20		121
DEFINE FWIDTH21		127

DEFINE FHEIGHT1		NINE
DEFINE FHEIGHT2		EIGHTEEN


**
** Input form display area metrics:
**
DEFINE HELP_AREA_TOP	FORTYSIX
DEFINE HELP_MSG_TOP	FIFTY
DEFINE HELP_BOTTOM	FIFTYFIVE
DEFINE HELP_HEIGHT	TEN

DEFINE CLIENT_TOP	SEVEN
DEFINE CLIENT_TOP+1	EIGHT
DEFINE CLIENT_HEIGHT	THIRTYNINE


**
** Miscellany:
**
DEFINE NULL		MINUSONE

DEFINE FVAL_NA		MINUSONE
DEFINE FVAL_NULL	MINUSONE
DEFINE FVALS_NULL	MINUSONE

DEFINE CHOICES_NULL	MINUSONE

DEFINE ID_NULL		MINUSONE

DEFINE OPTDATA_NULL	MINUSONE


*************************************************************************
*	
*	Simple DEFINEs to TOL var access, starting at TOLRESVARSEND+1
*	
*************************************************************************

DEFINE GetFieldOffset		TOLVar5@
DEFINE GetLabelOffset		TOLVar6@
DEFINE GetMyFieldId		TOLVar7@
DEFINE GetFocus			TOLVar8@
DEFINE GetIFKeyOb		TOLVar9@
DEFINE GetIFMenuRow		TOLVar10@
DEFINE GetIFMenu		TOLVar11@
DEFINE GetFAreaStates		TOLVar12@
DEFINE GetClientBack		TOLVar13@
DEFINE GetIFExit		TOLVar14@
DEFINE GetIsInpFormTask		TOLVar15@
DEFINE IsInpFormTask?		TOLVar15@
DEFINE GetTitleSpec		TOLVar16@
DEFINE GetFormProc		TOLVar17@
DEFINE GetFieldCount		TOLVar18@
DEFINE GetLabelCount		TOLVar19@

DEFINE SetFieldOffset		TOLVar5!
DEFINE SetLabelOffset		TOLVar6!
DEFINE SetMyFieldId		TOLVar7!
DEFINE SetFocus			TOLVar8!
DEFINE SetIFKeyOb		TOLVar9!
DEFINE SetIFMenuRow		TOLVar10!
DEFINE SetIFMenu		TOLVar11!
DEFINE SetFAreaStates		TOLVar12!
DEFINE SetClientBack		TOLVar13!
DEFINE SetIFExit		TOLVar14!
DEFINE SetIsInpFormTask		TOLVar15!
DEFINE SetTitle			TOLVar16!
DEFINE SetFormProc		TOLVar17!
DEFINE SetFieldCount		TOLVar18!
DEFINE SetLabelCount		TOLVar19!

*************************************************************************
*	
*	DEFINEs for secondaries with crunched names.
*	
*************************************************************************

DEFINE GetTitle			gFormTitle

DEFINE GetLabelText		gLblText
DEFINE GetLabelCol		gLblCol
DEFINE GetLabelRow		gLblRow
DEFINE GetLabelLoc		gLblLoc
DEFINE SetLabelText		sLblText
DEFINE SetLabelCol		sLblCol
DEFINE SetLabelRow		sLblRow
DEFINE SetLabelLoc		sLblLoc
DEFINE GetFieldProc		gFldProc
DEFINE GetFieldCol		gFldCol
DEFINE GetFieldRow		gFldRow
DEFINE GetFieldWidth		gFldWidth
DEFINE GetFieldHeight		gFldHeight
DEFINE GetFieldType		gFldType
DEFINE GetFieldObTypes		gFldObTypes
DEFINE GetFieldFormat		gFldFormat
DEFINE GetFieldHelp		gFldHelp
DEFINE GetFieldOptData1		gFldOptDat1
DEFINE GetFieldOptData2		gFldOptDat2
DEFINE GetFieldResetVal		gFldResetVal
DEFINE GetFieldVal		gFldVal
DEFINE GetFieldLoc		gFldLoc
DEFINE GetFieldSize		gFldSize
DEFINE SetFieldProc		sFldProc
DEFINE SetFieldCol		sFldCol
DEFINE SetFieldRow		sFldRow
DEFINE SetFieldWidth		sFldWidth
DEFINE SetFieldHeight		sFldHeight
DEFINE SetFieldType		sFldType
DEFINE SetFieldObTypes		sFldObTypes
DEFINE SetFieldFormat		sFldFormat
DEFINE SetFieldHelp		sFldHelp
DEFINE SetFieldOptData1		sFldOptDat1
DEFINE SetFieldOptData2		sFldOptDat2
DEFINE SetFieldResetVal		sFldResetVal
DEFINE SetFieldVal		sFldVal
DEFINE SetFieldLoc		sFldLoc
DEFINE SetFieldSize		sFldSize
RPL		( insure RPL-mode exit )
**miscdoc+*******************************************^******
************************************************************
**
** File:    Choose.h Version 1.12, 02/17/95
** Machine: Alcuin
**
************************************************************
**+miscdoc**************************************************

**
** Choose list event messages:
**
DEFINE LM_SETROWCOUNT		FIFTYSEVEN
DEFINE LM_SETROWHEIGHT		FIFTYEIGHT
DEFINE LM_SETROWWIDTH		FIFTYNINE
DEFINE LM_SETVIEWTYPE		SIXTY
DEFINE LM_SETPICKTYPE		SIXTYONE
DEFINE LM_SETITEMCOUNT		SIXTYTWO
DEFINE LM_SET1STROWXY		SIXTYTHREE
DEFINE LM_SETFOCUSPOS		SIXTYFOUR
DEFINE LM_DISPBORDER		BINT_65d
DEFINE LM_DISPPROMPT		FOURTWO  ( decimal 66 )
DEFINE LM_SETPROMPTGROB		FOURTHREE  ( decimal 67 )
DEFINE LM_SETCHOOSEKEYOB	SIXTYEIGHT
DEFINE LM_SETKEYOB		FOURFIVE  ( decimal 69 )
DEFINE LM_SETPROMPTDECOMP	SEVENTY
DEFINE LM_DISPLIST		SEVENTYFOUR
DEFINE LM_DISPITEM		SEVENTYNINE
DEFINE LM_SETITEM		EIGHTY
DEFINE LM_SETITEMGROB		EIGHTYONE
DEFINE LM_SETITEMDECOMP		LISTCMP  ( decimal 82 )
DEFINE LM_SETMENU		FIVETHREE  ( decimal 83 )
DEFINE LM_SAVECOVWIND		FIVEFOUR  ( decimal 84 )
DEFINE LM_POSTCREATE		2LIST  ( decimal 85 )
DEFINE LM_PICK			FIVESIX  ( decimal 86 )
DEFINE LM_RESTCOVWIND		LISTLAM  ( decimal 87 )
DEFINE LM_QUIT			BINT_91d
DEFINE LM_DONE			BINT_96d
DEFINE LM_GOTFOCUS 		IDREAL ( decimal 97 )
DEFINE LM_SETFOCUS       	IDCMP ( decimal 98 )
DEFINE LM_SETSIDE        	ONEHUNDRED
DEFINE LM_SETDECOMPFORMAT	SIXFIVE ( decimal 101 )

**
** Choose display area management:
**
** border=DA1; prompt line=DA2a; list area=DA2b
**
DEFINE BorderOK?		DA1OK?
DEFINE PromptOK?		DA2aOK?
DEFINE ListOK?			DA2bOK?
DEFINE ListBad?			DA2bBad?
DEFINE ClrPOK			ClrDA2aOK
DEFINE ClrLOK			ClrDA2bOK
DEFINE SetBValid		SetDA1Valid
DEFINE SetPValid		SetDA2aValid
DEFINE SetLValid		SetDA2bValid
DEFINE SetPNoCh			SetDA2aNoCh
DEFINE SetLNoCh			SetDA2bNoCh
DEFINE SetBBad			SetDA1Bad
DEFINE SetPBad			SetDA2aBad
DEFINE SetLBad			SetDA2bBad
DEFINE SetBPLNoCh		SetDA12NoCh
DEFINE SetB3NoCh		SetDA13NoCh
DEFINE SetBP3NoCh		SetDA12a3NCh

**
** Choose box metrics:
**
DEFINE DFLT_ROW_COUNT	FIVE 		( norm-view default visible row count )
DEFINE DFLT_1STROW_X    TWENTY 		( default first row X location )
DEFINE DFLT_1STROW_Y	FOURTEEN	( default first row Y location )
DEFINE DFLT_ROW_WIDTH   BINT_91d	( default row width )
DEFINE DFLT_ROW_HEIGHT  NINE		( default row height )

DEFINE MAXV_WIDTH	XHI		( max-view width )
DEFINE MAXV_HEIGHT	FIFTYSIX 	( max-view height )
DEFINE MAXV_DFLTROWCOUNT	SIX	( max-view default visible row count )

DEFINE PROMPT_HEIGHT 	EIGHT		( prompt area height )

DEFINE U/DWIDTH		SIX		( more-up/down icon width )
DEFINE U/DHEIGHT	FIVE		( more-up/down icon height )

**
** Choose pick types:
**
DEFINE PICKTYPE_MULTI	TRUE
DEFINE PICKTYPE_SINGLE	FALSE

** Choose view types:
**
DEFINE VIEWTYPE_MAX	TRUE
DEFINE VIEWTYPE_NORM	FALSE

** Choose initial side type:
DEFINE SIDE_LEFT	TRUE
DEFINE SIDE_RIGHT	FALSE


**
** Choose variable access, starting at TOLRESVARSEND+1:
**
DEFINE CHOOSEVARCOUNT		THIRTYNINE ( max_var_num - min_var_num + 1 )
DEFINE CHOOSEARGCOUNT		EIGHT ( number of stack args saved )
**
DEFINE ChooseExit!	    	TOLVar5!
DEFINE ChooseExit@	    	TOLVar5@
DEFINE DASpecFlags!		TOLVar6!
DEFINE DASpecFlags@		TOLVar6@
DEFINE ViewOnly!		TOLVar7!
DEFINE ViewOnly?		TOLVar7@
DEFINE LFocus!	  	  	TOLVar8!
DEFINE LFocus@			TOLVar8@
DEFINE List!	    		TOLVar9!
  DEFINE RightChProc!  		  TOLVar9!
DEFINE List@	    		TOLVar9@
  DEFINE RightChProc@  		  TOLVar9@
DEFINE DecompFmt!		TOLVar10!
DEFINE DecompFmt@		TOLVar10@
DEFINE Prompt!			TOLVar11!
DEFINE Prompt@			TOLVar11@
DEFINE ChooseProc!		TOLVar12!
DEFINE ChooseProc@		TOLVar12@

DEFINE ChAppVar1!		TOLVar13!
DEFINE ChAppVar1@		TOLVar13@
DEFINE ChAppVar2!		TOLVar14!
DEFINE ChAppVar2@		TOLVar14@
DEFINE ChAppVar3!		TOLVar15!
DEFINE ChAppVar3@		TOLVar15@
DEFINE ChAppVar4!		TOLVar16!
DEFINE ChAppVar4@		TOLVar16@
DEFINE ChAppVar5!		TOLVar17!
DEFINE ChAppVar5@		TOLVar17@

DEFINE 2Column!         	TOLVar18!
DEFINE 2Column?         	TOLVar18@
DEFINE LeftChProc!		TOLVar19!
DEFINE LeftChProc@		TOLVar19@
DEFINE SetLeftFocus     	:: TRUE TOLVar20! ;
DEFINE LeftFocus?       	TOLVar20@
DEFINE SetRightFocus    	:: FALSE TOLVar20! ;
DEFINE RightFocus?		:: TOLVar20@ NOT ;

DEFINE OppItemCount!		TOLVar21!
DEFINE OppItemCount@		TOLVar21@
DEFINE OppRowHeight!		TOLVar22!
DEFINE OppRowHeight@		TOLVar22@
DEFINE OppRowCount!		TOLVar23!
DEFINE OppRowCount@		TOLVar23@
DEFINE OppRowWidth!		TOLVar24!
DEFINE OppRowWidth@		TOLVar24@
DEFINE Opp1stRowX!		TOLVar25!
DEFINE Opp1stRowX@		TOLVar25@
DEFINE Opp1stRowY!		TOLVar26!
DEFINE Opp1stRowY@		TOLVar26@
DEFINE OppLFocus!		TOLVar27!
DEFINE OppLFocus@		TOLVar27@
DEFINE OppFocusPos!		TOLVar28!
DEFINE OppFocusPos@		TOLVar28@
DEFINE OppDecompFmt!		TOLVar29!
DEFINE OppDecompFmt@		TOLVar29@

DEFINE MenuWindow!		TOLVar30!
DEFINE MenuWindow@		TOLVar30@
DEFINE Window!			TOLVar31!
DEFINE Window@			TOLVar31@
DEFINE FocusPos!	    	TOLVar32!
DEFINE FocusPos@	    	TOLVar32@
DEFINE RowHeight!	    	TOLVar33!
DEFINE RowHeight@	    	TOLVar33@
DEFINE RowWidth!	    	TOLVar34!
DEFINE RowWidth@	    	TOLVar34@
DEFINE 1stRowY!	    		TOLVar35!
DEFINE 1stRowY@	    		TOLVar35@
DEFINE 1stRowX!	    		TOLVar36!
DEFINE 1stRowX@	    		TOLVar36@
DEFINE RowCount!		TOLVar37!
DEFINE RowCount@ 	   	TOLVar37@
DEFINE ItemCount!		TOLVar38!
DEFINE ItemCount@		TOLVar38@
DEFINE ChooseMenu!		TOLVar39!
DEFINE ChooseMenu@		TOLVar39@
DEFINE ViewType!	   	TOLVar40!
DEFINE ViewType@ 	   	TOLVar40@
DEFINE IsMaxView? 	   	TOLVar40@
DEFINE PickedItems!		TOLVar41!
DEFINE PickedItems@		TOLVar41@
DEFINE PickType!		TOLVar42!
DEFINE PickType@		TOLVar42@
DEFINE IsMultiPick?		TOLVar42@
DEFINE IsChooseTask!            TOLVar43!
DEFINE IsChooseTask@            TOLVar43@
DEFINE IsChooseTask?            TOLVar43@

RPL		( insure RPL-mode exit )
** 	Charlemagne Equation Writer Constants 1.1
**miscdoc+**************************************************
************************************************************
**
** File:    EQW.h Version 1.1, 07/01/94
** Machine: Charlemagne
**
************************************************************
**+miscdoc**************************************************

** The current GBox number:
DEFINE CurrentGbox#	SEVEN
RPL		( insure RPL-mode exit )
ASSEMBLE
**	TITLE Plot Variable Methods 1.21
RPL
**miscdoc+*******************************************^******
************************************************************
**
** File:    PlotVars.h Version 1.21, 03/28/95
** Machine: Elsie
**
************************************************************
**+miscdoc**************************************************
DEFINE PL_GET_xpos		TopicVar1@
DEFINE PL_PUT_xpos		TopicVar1!
DEFINE PL_GET_Crunch&Disp_proc	TopicVar2@
DEFINE PL_PUT_Crunch&Disp_proc	TopicVar2!
DEFINE PL_GET_ShowitProc	TopicVar3@
DEFINE PL_PUT_ShowitProc	TopicVar3!
DEFINE PL_GET_step%		TopicVar4@
DEFINE PL_PUT_step%		TopicVar4!
DEFINE PLIP_GET_%%yorigin	TopicVar5@
DEFINE PLIP_PUT_%%yorigin	TopicVar5!
DEFINE PLIP_GET_%%xorigin	TopicVar6@
DEFINE PLIP_PUT_%%xorigin	TopicVar6!
DEFINE IP_GET_#ytarget		TopicVar7@
DEFINE IP_PUT_#ytarget		TopicVar7!
DEFINE IP_GET_#xtarget		TopicVar8@
DEFINE IP_PUT_#xtarget		TopicVar8!
DEFINE PLIP_GET_yratio%%	TopicVar9@
DEFINE PLIP_PUT_yratio%%	TopicVar9!
DEFINE PLIP_GET_xratio%%	TopicVar10@
DEFINE PLIP_PUT_xratio%%	TopicVar10!
DEFINE PL_GET_CACHED_PTYPE	TopicVar11@
DEFINE PL_PUT_CACHED_PTYPE	TopicVar11!
DEFINE IP_GET_mark#y		TopicVar12@
DEFINE IP_PUT_mark#y		TopicVar12!
DEFINE IP_GET_#PICTh-1		TopicVar13@
DEFINE IP_PUT_#PICTh-1		TopicVar13!
DEFINE IP_GET_#PICTw-1		TopicVar14@
DEFINE IP_PUT_#PICTw-1		TopicVar14!
DEFINE PLIP_GET_indep_val	TopicVar15@
DEFINE PLIP_PUT_indep_val	TopicVar15!
DEFINE PL_GET_%xend		TopicVar16@
DEFINE PL_PUT_%xend		TopicVar16!
DEFINE PLIP_GET_%xstart		TopicVar17@
DEFINE PLIP_PUT_%xstart		TopicVar17!
DEFINE PLIP_GET_SAVED_DEPTH	TopicVar18@
DEFINE PLIP_PUT_SAVED_DEPTH	TopicVar18!
DEFINE IP_GET_LASTSHADE  	TopicVar19@
DEFINE IP_PUT_LASTSHADE 	TopicVar19!
DEFINE PL_GET_LastXArray	TopicVar20@
DEFINE PL_PUT_LastXArray	TopicVar20!
DEFINE PL_GET_LastYArray	TopicVar21@
DEFINE PL_PUT_LastYArray	TopicVar21!
DEFINE IP_GET_CACHED_DispMenu	TopicVar22@
DEFINE IP_PUT_CACHED_DispMenu	TopicVar22!
DEFINE IP_GET_CACHED_Handlers	TopicVar23@
DEFINE IP_PUT_CACHED_Handlers	TopicVar23!
DEFINE IP_GET_CACHED_TrcXpr	TopicVar24@
DEFINE IP_PUT_CACHED_TrcXpr	TopicVar24!
DEFINE IP_GET_CACHED_TrcYProc	TopicVar25@
DEFINE IP_PUT_CACHED_TrcYProc	TopicVar25!
DEFINE IP_GET_CACHED_DispProcs	TopicVar26@
DEFINE IP_PUT_CACHED_DispProcs	TopicVar26!
DEFINE IP_GET_WhichEq#		TopicVar27@
DEFINE IP_PUT_WhichEq#		TopicVar27!
DEFINE PL_GET_CRUNCHC_cache	TopicVar28@
DEFINE PL_PUT_CRUNCHC_cache	TopicVar28!
DEFINE IP_GET_TANL_cache	TopicVar29@
DEFINE IP_PUT_TANL_cache	TopicVar29!
DEFINE IP_GET_#x&ytarget	:: TopicVar8@ TopicVar7@ ;
DEFINE IP_GET_step%		TopicVar30@
DEFINE IP_PUT_step%		TopicVar30!
DEFINE IP_GET_%xend		TopicVar31@
DEFINE IP_PUT_%xend		TopicVar31!
DEFINE IP_GET_MENU_DISP_STATE	TopicVar32@
DEFINE IP_PUT_MENU_DISP_STATE	TopicVar32!
DEFINE IP_GET_GROB_UNDER_MARK	TopicVar33@
DEFINE IP_PUT_GROB_UNDER_MARK	TopicVar33!
DEFINE IP_GET_GROB_UNDER_CROSS	TopicVar34@
DEFINE IP_PUT_GROB_UNDER_CROSS	TopicVar34!
DEFINE IP_GET_MODE_num		TopicVar35@
DEFINE IP_PUT_MODE_num		TopicVar35!
DEFINE IP_GET_initial_RB_x	TopicVar36@
DEFINE IP_PUT_initial_RB_x	TopicVar36!
DEFINE IP_GET_mark#x		TopicVar37@
DEFINE IP_PUT_mark#x		TopicVar37!
DEFINE LEFTCOL                  TopicVar38@
DEFINE PL_PUT_LEFTCOL           TopicVar38!
DEFINE RIGHTCOL                 TopicVar39@
DEFINE PL_PUT_RIGHTCOL          TopicVar39!
DEFINE IP_PUT_ENVOK             TopicVar40!
DEFINE IP_GET_ENVOK             TopicVar40@
DEFINE IP_PUT_SAVEDEPTH         TopicVar41!
DEFINE IP_GET_SAVEDEPTH         TopicVar41@
DEFINE IP_PUT_EXITFCN           TopicVar42!
DEFINE IP_GET_EXITFCN           TopicVar42@
DEFINE IP_PUT_CURSORSTATE       TopicVar43!
DEFINE IP_GET_CURSORSTATE       TopicVar43@
DEFINE PL_PUT_PAUSE            TopicVar44!
DEFINE PL_GET_PAUSE            TopicVar44@
DEFINE PLIP_PUT_HYBRID         TopicVar45!
DEFINE PLIP_GET_HYBRID         TopicVar45@
* defines used in HYBRID
DEFINE NOSPLIT          ZERO
DEFINE GRAPHLEFT        ONE
DEFINE GRAPHZOOM        TWO
*
DEFINE IP_PUT_SAVEPARAMS       TopicVar46!
DEFINE IP_GET_SAVEPARAMS       TopicVar46@
DEFINE IP_PUT_DependVal        TopicVar91!
DEFINE IP_GET_DependVal        TopicVar91@
************************************************************
** Bit Mask for Individual bit of the PlotFlag
**
** See PlotFlag in TopicDir/share.d for flag
**   descriptions
**
************************************************************

DEFINE AutoScaleMsk ONE
DEFINE AxesDsrdMsk TWO
DEFINE ConnectedMsk FOUR
DEFINE EraseMsk EIGHT
DEFINE GridDsrdMsk SIXTEEN
DEFINE HighResMsk THIRTYTWO
DEFINE LabelMsk SIXTYFOUR
DEFINE RecenterMsk 128
DEFINE SimultMsk 256
DEFINE SolidCurMsk 512


************************************************************
* Plot2Flg
*   bit 0         Redraw
*   bit 1-5       symbolic view focus position
*   bit 6-9       sketch set pagenum: zero based
*   bit a         TraceMask
*   bit b         CoordMask
************************************************************

************************************************************
** Bit Mask for Individual field of the Plot2Flg
************************************************************
DEFINE Redraw      ONE
DEFINE SumbFocus   # 3E
DEFINE SketchPage  # 3C0
DEFINE TraceMask   1024
DEFINE CoordMask   2048



************************************************************
** Flag for Angle and HAngle Mode Variables 
************************************************************
DEFINE DEGFlag  ONE
DEFINE RADFlag	TWO
DEFINE GRADFlag THREE
DEFINE HAngleMask THREE
RPL
RPL		( insure RPL-mode exit )
RPL
**miscdoc+*******************************************^******
************************************************************
**
** File:    CalcDir.h Version 1.4, 04/18/95
** Machine: Charlemagne
**
************************************************************
**+miscdoc**************************************************
********************************************************************************
*
* Description:  Calculator Directory Defines
* Author:       C.M.Patton
* Created:      September 16, 1994
* Modified:     
* Language:     RPL
* Status:       Experimental (Do Not Distribute)
*
* (c) Copyright 1992, Hewlett-Packard Company, all rights reserved.
*
********************************************************************************
DEFINE GETVAR_Ans  LastBut0
DEFINE GETVAR_g9  LastBut1
DEFINE GETVAR_g8  LastBut2
DEFINE GETVAR_g7  LastBut3
DEFINE GETVAR_g6  LastBut4
DEFINE GETVAR_g5  LastBut5
DEFINE GETVAR_g4  LastBut6
DEFINE GETVAR_g3  LastBut7
DEFINE GETVAR_g2  LastBut8
DEFINE GETVAR_g1  LastBut9
DEFINE GETVAR_g0  LastBut10
DEFINE GETVAR_l9  LastBut11
DEFINE GETVAR_l8  LastBut12
DEFINE GETVAR_l7  LastBut13
DEFINE GETVAR_l6  LastBut14
DEFINE GETVAR_l5  LastBut15
DEFINE GETVAR_l4  LastBut16
DEFINE GETVAR_l3  LastBut17
DEFINE GETVAR_l2  LastBut18
DEFINE GETVAR_l1  LastBut19
DEFINE GETVAR_l0  LastBut20
DEFINE GETVAR_m9  LastBut21
DEFINE GETVAR_m8  LastBut22
DEFINE GETVAR_m7  LastBut23
DEFINE GETVAR_m6  LastBut24
DEFINE GETVAR_m5  LastBut25
DEFINE GETVAR_m4  LastBut26
DEFINE GETVAR_m3  LastBut27
DEFINE GETVAR_m2  LastBut28
DEFINE GETVAR_m1  LastBut29
DEFINE GETVAR_m0  LastBut30
DEFINE GETVAR_FIT LastBut31
DEFINE GETVAR_a fxget_a
DEFINE GETVAR_b fxget_b
DEFINE GETVAR_c fxget_c
DEFINE GETVAR_d fxget_d
DEFINE GETVAR_f fxget_f
DEFINE GETVAR_g fxget_g
DEFINE GETVAR_h fxget_h
DEFINE GETVAR_j fxget_j
DEFINE GETVAR_k fxget_k
DEFINE GETVAR_l fxget_l
DEFINE GETVAR_m fxget_m
DEFINE GETVAR_n fxget_n
DEFINE GETVAR_o fxget_o
DEFINE GETVAR_p fxget_p
DEFINE GETVAR_q fxget_q
DEFINE GETVAR_r fxget_r
DEFINE GETVAR_s fxget_s
DEFINE GETVAR_t fxget_t
DEFINE GETVAR_u fxget_u
DEFINE GETVAR_v fxget_v
DEFINE GETVAR_w fxget_w
DEFINE GETVAR_x fxget_x
DEFINE GETVAR_y fxget_y
DEFINE GETVAR_z fxget_z
DEFINE GETVAR_z0 fxget_z0
DEFINE GETVAR_z1 fxget_z1
DEFINE GETVAR_z2 fxget_z2
DEFINE GETVAR_z3 fxget_z3
DEFINE GETVAR_z4 fxget_z4
DEFINE GETVAR_z5 fxget_z5
DEFINE GETVAR_z6 fxget_z6
DEFINE GETVAR_z7 fxget_z7
DEFINE GETVAR_z8 fxget_z8
DEFINE GETVAR_z9 fxget_z9

***********************************************
*                                             *
* Statistics Misc data array index Definition *
*    Data stored in stat directory            *
*    Usse StatMisc@ StatMisc! for access      *
***********************************************

DEFINE sMEANS   ONE
DEFINE sTOTS    TWO
DEFINE sSVARS   THREE
DEFINE sPVARS   FOUR
DEFINE sSSDEV   FIVE
DEFINE sPSDEV   SIX
DEFINE sNS      SEVEN
DEFINE sMINS    EIGHT
DEFINE sMAXS    NINE
DEFINE sMED     TEN
DEFINE sQ1      ELEVEN
DEFINE sQ3      TWELVE
DEFINE sMEANX   THIRTEEN
DEFINE sSX      FOURTEEN
DEFINE sSX2     FIFTEEN
DEFINE sMEANY   SIXTEEN
DEFINE sSY      SEVENTEEN
DEFINE sSY2     EIGHTEEN
DEFINE sSXY     NINETEEN
DEFINE sCORR    TWENTY
DEFINE sCOV     TWENTYONE
DEFINE sRELERR  TWENTYTWO
RPL		( insure RPL-mode exit )
**        TITLE Table View DEFINEs 1.40
**miscdoc+*******************************************^******
************************************************************
**
** File:    Table.h Version 1.40, 04/19/95
**
************************************************************
**+miscdoc**************************************************

**rpldoc+***************************************************
************************************************************
**
**
** Purpose: Central repository for table view DEFINEs
**
**
************************************************************
**+rpldoc***************************************************

* Table DEFINEs

DEFINE TB7chrs FALSE
DEFINE TB8chrs TRUE
DEFINE TBSmallFont FALSE
DEFINE TBMediumFont TRUE

DEFINE TBFontBit ONE
DEFINE TBBuildBit TWO

************************************************************
*
* DEFINEs for split numeric view uses	( FUNCTION/POLAR, etc.)
*
DEFINE TS_RightSuffix@ TopicVar60@
DEFINE TS_RightSuffix! TopicVar60!

DEFINE TS_LeftSuffix@ TopicVar59@
DEFINE TS_LeftSuffix! TopicVar59!

DEFINE TS_MkErrorGrob@ TopicVar58@
DEFINE TS_MkErrorGrob! TopicVar58!

DEFINE TS_Step@ TopicVar57@
DEFINE TS_Step! TopicVar57!

DEFINE TS_RightPrefix@ TopicVar56@
DEFINE TS_RightPrefix! TopicVar56!

DEFINE TS_LeftPrefix@ TopicVar55@
DEFINE TS_LeftPrefix! TopicVar55!

DEFINE TS_IndpX@ TopicVar54@
DEFINE TS_IndpX! TopicVar54!

DEFINE TS_Rows@ TopicVar53@
DEFINE TS_Rows! TopicVar53!

DEFINE TS_Group@ TopicVar52@
DEFINE TS_Group! TopicVar52!

DEFINE TS_Fn@ TopicVar51@
DEFINE TS_Fn! TopicVar51!

DEFINE TS_Start@ TopicVar50@
DEFINE TS_Start! TopicVar50!

DEFINE TS_row@ TopicVar49@
DEFINE TS_row! TopicVar49!

************************************************************
*
* DEFINEs for full numeric view uses	( FUNCTION/POLAR, etc.)
*
DEFINE TV_TBImCache@ TopicVar34@
DEFINE TV_TBImCache! TopicVar34!

DEFINE TV_ShowComplex@ TopicVar33@
DEFINE TV_ShowComplex! TopicVar33!

DEFINE TV_ZoomList@ TopicVar32@
DEFINE TV_ZoomList! TopicVar32!

DEFINE TV_Decomp@ TopicVar31@
DEFINE TV_Decomp! TopicVar31!

DEFINE TV_DefMode@ TopicVar30@
DEFINE TV_DefMode! TopicVar30!

DEFINE TV_GroupSize@ TopicVar29@
DEFINE TV_GroupSize! TopicVar29!

DEFINE TV_OldStep@ TopicVar28@
DEFINE TV_OldStep! TopicVar28!

DEFINE TV_OldStart@ TopicVar27@
DEFINE TV_OldStart! TopicVar27!

DEFINE TV_IndpVals@ TopicVar26@
DEFINE TV_IndpVals! TopicVar26!

DEFINE TV_CacheRows@ TopicVar25@
DEFINE TV_CacheRows! TopicVar25!

DEFINE TV_BTRow1@ TopicVar24@
DEFINE TV_BTRow1! TopicVar24!

DEFINE TV_IVCache!@ TopicVar23@
DEFINE TV_IVCache!! TopicVar23!

DEFINE TV_IVCache@@ TopicVar22@
DEFINE TV_IVCache@! TopicVar22!

DEFINE TV_Build@ TopicVar21@
DEFINE TV_Build! TopicVar21!

DEFINE TV_IndVar@ TopicVar20@
DEFINE TV_IndVar! TopicVar20!

DEFINE TV_Str1@ TopicVar19@
DEFINE TV_Str1! TopicVar19!

DEFINE TV_Str2@ TopicVar18@
DEFINE TV_Str2! TopicVar18!

DEFINE TV_Str3@ TopicVar17@
DEFINE TV_Str3! TopicVar17!

DEFINE TV_TBCache@ TopicVar16@
DEFINE TV_TBCache! TopicVar16!

DEFINE TV_InvCurs@ TopicVar15@
DEFINE TV_InvCurs! TopicVar15!

DEFINE TV_DVGrob1@ TopicVar14@
DEFINE TV_DVGrob1! TopicVar14!

DEFINE TV_DVGrob2@ TopicVar13@
DEFINE TV_DVGrob2! TopicVar13!

DEFINE TV_DVGrob3@ TopicVar12@
DEFINE TV_DVGrob3! TopicVar12!

DEFINE TV_DFunc1@ TopicVar11@
DEFINE TV_DFunc1! TopicVar11!

DEFINE TV_DFunc2@ TopicVar10@
DEFINE TV_DFunc2! TopicVar10!

DEFINE TV_DFunc3@ TopicVar9@
DEFINE TV_DFunc3! TopicVar9!

DEFINE TV_IVGrob@ TopicVar8@
DEFINE TV_IVGrob! TopicVar8!

DEFINE TV_TStart@ TopicVar7@
DEFINE TV_TStart! TopicVar7!

DEFINE TV_TStep@ TopicVar6@
DEFINE TV_TStep! TopicVar6!

DEFINE TV_TFont@ TopicVar5@
DEFINE TV_TFont! TopicVar5!

DEFINE TV_TBrow@ TopicVar4@
DEFINE TV_TBrow! TopicVar4!

DEFINE TV_TBcol@ TopicVar3@
DEFINE TV_TBcol! TopicVar3!

DEFINE TV_TNfns@ TopicVar2@
DEFINE TV_TNfns! TopicVar2!

DEFINE TV_TCol1@ TopicVar1@
DEFINE TV_TCol1! TopicVar1!

************************************************************
*
* Statistics DEFINEs
*

DEFINE STFontBit ONE

************************************************************
*
* DEFINEs for TopicVar uses ( STATISTICS )
*

DEFINE TV_STFont@ TopicVar1@
DEFINE TV_STFont! TopicVar1!

DEFINE TV_STrow@ TopicVar2@
DEFINE TV_STrow! TopicVar2!

DEFINE TV_STcol@ TopicVar3@
DEFINE TV_STcol! TopicVar3!

DEFINE TV_STCol1@ TopicVar4@
DEFINE TV_STCol1! TopicVar4!

DEFINE TV_STRow1@ TopicVar5@
DEFINE TV_STRow1! TopicVar5!

DEFINE TV_STInvCurs@ TopicVar6@
DEFINE TV_STInvCurs! TopicVar6!

DEFINE TV_STGrob1@ TopicVar7@
DEFINE TV_STGrob1! TopicVar7!

DEFINE TV_STGrob2@ TopicVar8@
DEFINE TV_STGrob2! TopicVar8!

DEFINE TV_STGrob3@ TopicVar9@
DEFINE TV_STGrob3! TopicVar9!

DEFINE TV_STGrob4@ TopicVar10@
DEFINE TV_STGrob4! TopicVar10!

******************************
* Warning: The following eight are equated to hard loads in 
*          STStoMax, STRclMax, and STRclArry.  If these change,
*          update the corresponding routines!
*
DEFINE TV_STArry4@ TopicVar11@
DEFINE TV_STArry4! TopicVar11!

DEFINE TV_STArry3@ TopicVar12@
DEFINE TV_STArry3! TopicVar12!

DEFINE TV_STArry2@ TopicVar13@
DEFINE TV_STArry2! TopicVar13!

DEFINE TV_STArry1@ TopicVar14@
DEFINE TV_STArry1! TopicVar14!

DEFINE TV_STMax1@ TopicVar15@
DEFINE TV_STMax1! TopicVar15!

DEFINE TV_STMax2@ TopicVar16@
DEFINE TV_STMax2! TopicVar16!

DEFINE TV_STMax3@ TopicVar17@
DEFINE TV_STMax3! TopicVar17!

DEFINE TV_STMax4@ TopicVar18@
DEFINE TV_STMax4! TopicVar18!
*
*****************************

************************************************************
**
** DEFINEs for Statistic Numeric Setup Variables
** see TopicDir/statDir.d for detail
************************************************************

DEFINE SNtypeData       ONE
DEFINE SNtypeSVar       TWO
DEFINE SNtypeSumm       THREE

DEFINE SVarTySample     ONE
DEFINE SVarTyPopula     TWO

DEFINE SModelLinear     ONE
DEFINE SModelLog        TWO
DEFINE SModelExp        THREE
DEFINE SModelPower      FOUR
DEFINE SModelQuad       FIVE
DEFINE SModelCubic      SIX
DEFINE SModelLogis      SEVEN
DEFINE SModelUser       EIGHT

************************************************************
** Bit Mask for Individual bit of ReCalcFlag.
** One bit for each Data Set. (See TopicDir/statDir.d)
************************************************************
DEFINE D1ReCalc ONE
DEFINE D2ReCalc TWO
DEFINE D3ReCalc FOUR
DEFINE D4ReCalc EIGHT
DEFINE D5ReCalc SIXTEEN
DEFINE D6ReCalc THIRTYTWO
DEFINE D7ReCalc SIXTYFOUR
DEFINE D8ReCalc 128
DEFINE D9ReCalc 256
DEFINE D0ReCalc 512

************************************************************
*
* DEFINEs for Solve Num View
*
DEFINE 1COLVARCOUNT_MAX FOUR    ( maximum total number of variables
				possible for the 1-column solve layout
				)
RPL		( insure RPL-mode exit )
**        TITLE Matrix Editor DEFINEs 1.9
**miscdoc+*******************************************^******
************************************************************
**
** File:    MatEdit.h Version 1.9, 02/19/95
**
************************************************************
**+miscdoc**************************************************

**rpldoc+***************************************************
************************************************************
**
**
** Purpose: Central repository for matrix editor DEFINEs
**
**
************************************************************
**+rpldoc***************************************************

DEFINE TV_InvOn@ TopicVar20@
DEFINE TV_InvOn! TopicVar20!

DEFINE TV_Vector@ TopicVar19@
DEFINE TV_Vector! TopicVar19!

DEFINE TV_MEMatIndex@ TopicVar18@
DEFINE TV_MEMatIndex! TopicVar18!

DEFINE TV_MEInTempOb@ TopicVar17@
DEFINE TV_MEInTempOb! TopicVar17!

DEFINE TV_METype@ TopicVar16@
DEFINE TV_METype! TopicVar16!

DEFINE TV_MEGrob4@ TopicVar15@
DEFINE TV_MEGrob4! TopicVar15!

DEFINE TV_MEGrob3@ TopicVar14@
DEFINE TV_MEGrob3! TopicVar14!

DEFINE TV_MEGrob2@ TopicVar13@
DEFINE TV_MEGrob2! TopicVar13!

DEFINE TV_MEGrob1@ TopicVar12@
DEFINE TV_MEGrob1! TopicVar12!

DEFINE TV_MEAdvance@ TopicVar11@
DEFINE TV_MEAdvance! TopicVar11!

DEFINE TV_MERunning@ TopicVar10@
DEFINE TV_MERunning! TopicVar10!

DEFINE TV_MEInvCurs@ TopicVar9@
DEFINE TV_MEInvCurs! TopicVar9!

DEFINE TV_MERow1@ TopicVar8@
DEFINE TV_MERow1! TopicVar8!

DEFINE TV_MECol1@ TopicVar7@
DEFINE TV_MECol1! TopicVar7!

DEFINE TV_MEArry@ TopicVar6@
DEFINE TV_MEArry! TopicVar6!

DEFINE TV_MEFont@ TopicVar5@
DEFINE TV_MEFont! TopicVar5!

DEFINE TV_MErow@ TopicVar4@
DEFINE TV_MErow! TopicVar4!

DEFINE TV_MEcol@ TopicVar3@
DEFINE TV_MEcol! TopicVar3!

DEFINE TV_MERows@ TopicVar2@
DEFINE TV_MERows! TopicVar2!

DEFINE TV_MECols@ TopicVar1@
DEFINE TV_MECols! TopicVar1!
RPL		( insure RPL-mode exit )
**miscdoc+*******************************************^******
************************************************************
**
** File:    IO.h Version 1.16, 05/02/95
** Machine: Alcuin
**
************************************************************
**+miscdoc**************************************************

**miscdoc+*********************************************************************
** File Structure Conventions
**
**
** Binary Transfer Type
**
** <header><T><ID NameForm><object><pad>
** |			  |
** +-- len < 128 bytes ---+
**
**
**   where <T> is a single character:
**							In the extended set/
**           character | interpretation		      | Ascii/Binary/Either
**          -----------+------------------------------+-------------------
**       SubTypeZapChr | Zaplet			      | Y B
**       SubTypeNteChr | Note			      |	Y E
**       SubTypePgmChr | Program		      |	Y E
**       SubTypeVarChr | Variable		      |	N B
**       SubTypeLstChr | List (subtype of Variable)   |	Y B
**       SubTypeMatChr | Matrix (subtype of Variable) |	Y B
**       SubTypeLibChr | Library		      |	N B
**       SubTypeTgtChr | Target List		      | N B
**	 SubTypeVecChr | ASCII Vector specification   | N A
**       SubTypeDirChr | Directory List               | N A
**       SubTypeAnyChr | *wildcard*                   | Y neither
**
** Note: The following defines must be in adjacent ascending ASCII order:

ASSEMBLE
SubTypeChrBase	EQU 65 ( "A"--must match first define )
RPL
DEFINE SubTypeDirChr		CHR "A"
DEFINE SubTypeZapChr 		CHR "B"
DEFINE SubTypeNteChr 		CHR "C"
DEFINE SubTypePgmChr 		CHR "D"
DEFINE SubTypeVarChr 		CHR "E"
DEFINE SubTypeLstChr		CHR "F"
DEFINE SubTypeMatChr 		CHR "G"
DEFINE SubTypeLibChr 		CHR "H"
DEFINE SubTypeTgtChr 		CHR "I"
DEFINE SubTypeVecChr		CHR "J"
DEFINE SubTypeAnyChr            CHR "K"

** -------------------------------------------------------------------------
** ASCII Transfer Type (entire file is readable text): Program/Note
**
** <header><T><SP><count><SP><name><body of text>
**	          |		   |
**	          +---C$ format --+
**
**  where <T> is <SubTypePgmChr> or <SubTypeNteChr> (i.e. a program or note>
** -------------------------------------------------------------------------
** ASCII Transfer Type (entire file is readable text): Vector
**
** <header><T><SP><count><SP><name><SP><number><SP>...
**	          |		   |
**	          +---C$ format --+
**
**  where <T> is <SubTypeVec> (if the name does not designate a variable
**  which accepts a vector, an error will result.)
** -------------------------------------------------------------------------
**
** ASCII Transfer Type (entire file is readable text):
**
** <header><U><SP><T><SP><count><SP><name><count><SP><name>...
**	                 |               ||               |
**	                 +---C$ format --++---C$ format --+
**	          type       filename         elsiename
**	          |                                       |
**	          +---------------------------------------+----- ...
**		              file record
**
**  Where <U> is <SubTypeDirChr> and <T> is as above (excluding SubTypeTgtChr)
**  but including <SubTypeDirChr>
**
**+miscdoc*********************************************************************

**miscdoc+*******************************************^******
************************************************************
**
** Standard file names for object store files
**
************************************************************
**+miscdoc**************************************************

** The root directory file name:
DEFINE $IORootFile      "HP39DIR.000"
DEFINE idIORootFile     ID HP39DIR.000

** The root directory Elsie name:
DEFINE idIORootName     ID Root

** The current directory pointer file name:
DEFINE $IOCurrentDir    "HP39DIR.CUR"


**miscdoc+*******************************************^******
************************************************************
**
** I/O event message defines
**
************************************************************
**+miscdoc**************************************************

DEFINE IOM_ChooseStoreLoc	ONE
DEFINE IOM_NoObFile		TWO
DEFINE IOM_Sending		THREE
DEFINE IOM_Getting		FOUR
DEFINE IOM_Receiving		FIVE
DEFINE IOM_ResetCurrentDir?	SIX
DEFINE IOM_ResetRootDir?	SEVEN

RPL		( insure RPL-mode exit )

** CoveredRom1/test.a:

** CoveredRom1/pramtest2.a:

** CoveredRom1/nwsutl.a:

** CoveredRom2/head.a:

** CoveredRom2/link.a:

** CoveredRom2/covINTG.s:
EXTERNAL INTGSIN
EXTERNAL I:-InvSin
EXTERNAL INTGCOS
EXTERNAL I:LnTan
EXTERNAL INTGTAN
EXTERNAL INTGASIN
EXTERNAL INTGACOS
EXTERNAL INTGATAN
EXTERNAL INTGSINH
EXTERNAL I:-InvSinh
EXTERNAL I:LnTanh
EXTERNAL INTGCOSH
EXTERNAL I:Tanh
EXTERNAL INTGTANH
EXTERNAL INTGEXPM
EXTERNAL INTGALOG
EXTERNAL INTGLN
EXTERNAL INTGLOG
EXTERNAL INTGINV
EXTERNAL I:Atan
EXTERNAL INTGSQ
EXTERNAL INTGSQRT
EXTERNAL I:Asinh
EXTERNAL I:Acosh
EXTERNAL INTGSIGN
EXTERNAL INTGDER

** CoveredRom2/covmanip.s:
EXTERNAL mT->=
EXTERNAL m<-T=
EXTERNAL mAFlq
EXTERNAL mAFqq
EXTERNAL mAFrq
EXTERNAL m<->+
EXTERNAL m<->-
EXTERNAL m<->*
EXTERNAL m<->/
EXTERNAL m<-A-+
EXTERNAL m<-A--
EXTERNAL m<-A/*
EXTERNAL m<-A//
EXTERNAL m<-A^*
EXTERNAL mA->+-
EXTERNAL mA->--
EXTERNAL mA->*/
EXTERNAL mA->//
EXTERNAL mA->^^
EXTERNAL mD->/+
EXTERNAL mD->/-
EXTERNAL mD->^+
EXTERNAL mD->^-
EXTERNAL mD->E+
EXTERNAL mD->E-
EXTERNAL mD->L*
EXTERNAL mD->L/
EXTERNAL m[]CHS*
EXTERNAL m[]CHS/
EXTERNAL m[]CHSL
EXTERNAL m[]INV^
EXTERNAL m[]INVE
EXTERNAL m1/[]*
EXTERNAL m1/[]/
EXTERNAL m1/[]^
EXTERNAL m1/[]E
EXTERNAL m-[]L
EXTERNAL m-[]*
EXTERNAL m-[]/
EXTERNAL m-[]+
EXTERNAL m-[]-
EXTERNAL mE^*
EXTERNAL mE^/
EXTERNAL mE[]^
EXTERNAL mL*^
EXTERNAL mL[]*
EXTERNAL mL[]/
EXTERNAL m<-M+*
EXTERNAL m<-M-*
EXTERNAL adjdivsign
EXTERNAL adjsign
EXTERNAL adjdiv
EXTERNAL m<-M*^
EXTERNAL m<-M/^
EXTERNAL m<-M*E
EXTERNAL m<-M/E
EXTERNAL m<-M+L
EXTERNAL m<-M-L
EXTERNAL mM->op
EXTERNAL m<T>+
EXTERNAL m<T>*
EXTERNAL m<-T+-
EXTERNAL m<-T*/
EXTERNAL m<-[+-
EXTERNAL m<-[*/
EXTERNAL m]->+-
EXTERNAL m]->*/
EXTERNAL m->[]<-+-
EXTERNAL m->[]<-*/
EXTERNAL mCONJ[]
EXTERNAL mRE[]
EXTERNAL mIM[]
EXTERNAL REIM[]*
EXTERNAL m->TRG
EXTERNAL m->DEFSIN
EXTERNAL m->DEFCOS
EXTERNAL m->DEFTAN
EXTERNAL m->DEFASIN
EXTERNAL m->DEFACOS
EXTERNAL m->DEFATAN
EXTERNAL m->DEFSINH
EXTERNAL m->DEFCOSH
EXTERNAL m->DEFTANH
EXTERNAL m->DEFASINH
EXTERNAL m->DEFACOSH
EXTERNAL m->DEFATANH
EXTERNAL mSIN+
EXTERNAL mCOS+
EXTERNAL mTAN+
EXTERNAL mSINH+
EXTERNAL mCOSH+
EXTERNAL mTANH+
EXTERNAL covmanCOL

** CoveredRom2/covWHERE.s:
EXTERNAL WHEREFCNAPPL
EXTERNAL WHEREDER
EXTERNAL WHEREIFTE
EXTERNAL WHEREWHERE
EXTERNAL covWSPLIT
EXTERNAL WHEREINTG
EXTERNAL WHERESUM

** CoveredRom2/covports.s:
EXTERNAL XSTOCHECK
EXTERNAL XSTOCHECK10
EXTERNAL covLBSTO
EXTERNAL XEQXDPTCH
EXTERNAL Xcont
EXTERNAL CHECKEXISTS
EXTERNAL covmetaLIBS
EXTERNAL XRCLp?
EXTERNAL XRCLpNL
EXTERNAL XRCLpL
EXTERNAL XRCLp*
EXTERNAL XEVALp?
EXTERNAL XEVALp*
EXTERNAL XPURGEp?
EXTERNAL XPURGEp*
EXTERNAL convertaddrs
EXTERNAL XRCLp?acc>

** CoveredRom2/covCOL.s:
EXTERNAL COLCTDER
EXTERNAL COLCTINTG
EXTERNAL COLCTSUM
EXTERNAL COLCTIFTE
EXTERNAL COLCTQUOTE
EXTERNAL COLCTFCNAP

** CoveredRom2/covDIFS.s:
EXTERNAL covD/D*
EXTERNAL covD/DCROSS
EXTERNAL covD/DDOT
EXTERNAL covD/D+
EXTERNAL covD/D-
EXTERNAL covD/D/
EXTERNAL covD/D=
EXTERNAL covD/Dalg=
EXTERNAL covD/DABS
EXTERNAL covD/DACOS
EXTERNAL covD/DACOSH
EXTERNAL covD/DALOG
EXTERNAL covD/DARG
EXTERNAL covD/DASIN
EXTERNAL covD/DASINH
EXTERNAL covD/DATAN
EXTERNAL covD/DATANH
EXTERNAL covD/DCOS
EXTERNAL covD/DCOSH
EXTERNAL covD/DEXP
EXTERNAL covD/DINV
EXTERNAL covD/DLN
EXTERNAL covD/DLNP1
EXTERNAL covD/DLOG
EXTERNAL covD/DIFTE
EXTERNAL covD/DSIN
EXTERNAL covD/DSINH
EXTERNAL covD/DSQ
EXTERNAL covD/DSQRT
EXTERNAL covD/DTAN
EXTERNAL covD/DTANH
EXTERNAL covD/D^
EXTERNAL covD/D^X
EXTERNAL covD/D^Y
EXTERNAL covD/DDER
EXTERNAL covD/DWHERE
EXTERNAL covD/DINTG
EXTERNAL covD/DSUM
EXTERNAL covD/DAPPLY

** CoveredRom2/covForm.s:
EXTERNAL covMANMENU+-
EXTERNAL covMANMENU*/
EXTERNAL covMANMENU^
EXTERNAL covMANEXP
EXTERNAL covMANMENULN
EXTERNAL covMANCSIV
EXTERNAL covMANMENUEQ
EXTERNAL covMANMENUCX
EXTERNAL covMANTRG
EXTERNAL covMANATG

** CoveredRom2/covINVS.s:
EXTERNAL covINV+
EXTERNAL covINV-
EXTERNAL covINV=
EXTERNAL covINV*
EXTERNAL covINV/
EXTERNAL covINV^
EXTERNAL covINV^X
EXTERNAL covINVEXP
EXTERNAL covINVSIN
EXTERNAL covINVCOS
EXTERNAL covINVTAN
EXTERNAL covINVSINH
EXTERNAL covINVCOSH
EXTERNAL covINVTANH
EXTERNAL covINVALOG
EXTERNAL covINVEXPM1

** CoveredRom2/end.a:

** LinearAlgebra/head.a:

** LinearAlgebra/LinAlglink.a:

** LinearAlgebra/Egv.s:
EXTERNAL laSRAD
EXTERNAL laVMAX%%
**EXTERNAL laEGVL
EXTERNAL laEGVL%%
**EXTERNAL laEGV
EXTERNAL laSCHUR
EXTERNAL laEgHF
EXTERNAL laECQhQAQh
EXTERNAL laEgQkHA
EXTERNAL laEgRSchur
EXTERNAL laEgIsoVal
EXTERNAL laEgRQRI
EXTERNAL laEgQRIk0
EXTERNAL laEgRQRIk1
EXTERNAL laEgRWilk3
EXTERNAL laEgM*RG3
EXTERNAL laEgWilk2
EXTERNAL laEgM*G2
EXTERNAL laEgValr
EXTERNAL laEgRotR
EXTERNAL laSchur2
EXTERNAL laEgVecR
EXTERNAL laEgVcSngl
EXTERNAL laEgVcUrhs
EXTERNAL laEgVcPair
EXTERNAL laEgSclCls
EXTERNAL laEgCSchur
EXTERNAL laEgCQRI
EXTERNAL laEgCQRIk1
EXTERNAL laEgVecC
EXTERNAL laEgPrep
EXTERNAL laFPMUTE
EXTERNAL laBPMUTE
EXTERNAL laFSCALE

** LinearAlgebra/LeastSq.s:
EXTERNAL laLSQ
EXTERNAL laUserQR
EXTERNAL laUserLQ
EXTERNAL lauserQR
EXTERNAL laQRF
EXTERNAL laQhA
EXTERNAL laQhB
EXTERNAL laSETDIAG
EXTERNAL laRQF
EXTERNAL laQ2hX
EXTERNAL laRSVF
EXTERNAL laQRrank
EXTERNAL laQRSVecUp
EXTERNAL laQRminSV
EXTERNAL laQRmaxSV
EXTERNAL rMAKEPCOPY
EXTERNAL rPACKARRYD
EXTERNAL MAKEEPIDN

** LinearAlgebra/Svd.s:
EXTERNAL laSNORM
EXTERNAL laSNORM%%
**EXTERNAL laRANK
EXTERNAL laSVL
EXTERNAL laSVD
EXTERNAL laSvdUBD
EXTERNAL laSvdLtUBD
EXTERNAL laSvdUQhQA
EXTERNAL laSvdAPPhV
EXTERNAL laSvdAPk
EXTERNAL laSvdGPROT
EXTERNAL laSvdBDQR
EXTERNAL laSvdQR2x2
EXTERNAL laSvdFDirC
EXTERNAL laSvdBDirC
EXTERNAL laSvdGShft
EXTERNAL laSvdQRSF
EXTERNAL laSvdQRSB
EXTERNAL laSvdQRF
EXTERNAL laSvdQRB
EXTERNAL laSvdCROTR
EXTERNAL laSvdCROTL
EXTERNAL laSvdPSort
EXTERNAL laSvdPrep

** LinearAlgebra/SysSlv.s:
**EXTERNAL laTRACE
*EXTERNAL laCOND
*EXTERNAL laCONDdone
*EXTERNAL laVMAXJRP
*EXTERNAL laUserLU
*EXTERNAL laRefineDT
*EXTERNAL laSV
*EXTERNAL laSVc
*EXTERNAL laIVF
*EXTERNAL laULHSVF
*EXTERNAL laLsdScale
*EXTERNAL laScIntRnd
*EXTERNAL laRREF
*EXTERNAL laRedRow
*EXTERNAL laRedHere?
*EXTERNAL laEGetTiny

** LinearAlgebra/end.a:
RPL		( insure RPL-mode exit )
* Turn On Assembly Listing 1.1
**miscdoc+*******************************************^******
************************************************************
**
** File:    OnList.h Version 1.1, 07/01/94
** Machine: Charlemagne
**
************************************************************
**+miscdoc**************************************************

**miscdoc+**************************************************
************************************************************
**
**  This file turns on the assembly listing after the 
**  contents of "Header.h".
**
**  The first file in "Header.h" should be "OffList.h", to 
**  turn off the assembly listing.
**
************************************************************
**+miscdoc**************************************************

ASSEMBLE
	SETLIST CODE, INCLUDE, PSEUDO
RPL
RPL		( insure RPL-mode exit )
** TITLE Keyword.h Version 1.1 Date 95/12/04
** Plot type keywords

EXTERNAL nFUNCTION
EXTERNAL nSOLVE
EXTERNAL nPOLAR
EXTERNAL nPARAMETRIC
EXTERNAL nSCATTER
EXTERNAL nHISTOGRAM
EXTERNAL nSEQUENCE
EXTERNAL nBOXWHISKER

** old Plot type keywords

EXTERNAL nCONIC
EXTERNAL nTRUTH
EXTERNAL nBAR
EXTERNAL PCONTDRAW
EXTERNAL SLOPEDRAW
EXTERNAL WIREDRAW
EXTERNAL PSURFDRAW
EXTERNAL GRIDDRAW

** Table type keywords

EXTERNAL xFUNCTAB
EXTERNAL xPOLARTAB
EXTERNAL xPARAMTAB
EXTERNAL xSEQTAB
EXTERNAL xSTATTAB
EXTERNAL xSOLVETAB

** Symbolic type keywords

EXTERNAL xFUNCSYMB
EXTERNAL xPOLARSYMB
EXTERNAL xPARAMSYMB
EXTERNAL xSEQSYMB
EXTERNAL xSTATSYMB
EXTERNAL xSOLVESYMB

** Topic type keywords

EXTERNAL nFUNCTOPIC
EXTERNAL nPOLARTOPIC
EXTERNAL nPARAMTOPIC
EXTERNAL nSEQTOPIC
EXTERNAL nSTATTOPIC
EXTERNAL nSOLVETOPIC

** Note type keywords

EXTERNAL xFUNCNOTE
EXTERNAL xPOLARNOTE
EXTERNAL xPARAMNOTE
EXTERNAL xSEQNOTE
EXTERNAL xSTATNOTE
EXTERNAL xSOLVENOTE

** Sketch type keywords

EXTERNAL xFUNCPICT
EXTERNAL xPOLARPICT
EXTERNAL xPARAMPICT
EXTERNAL xSEQPICT
EXTERNAL xSTATPICT
EXTERNAL xSOLVEPICT
RPL		( insure RPL-mode exit )

** UserCommands2
EXTERNAL xxDEG
EXTERNAL xxRAD
EXTERNAL xxGRAD
EXTERNAL xSTD
EXTERNAL xFIX
EXTERNAL xSCI
EXTERNAL xENG
EXTERNAL xFRACTION
EXTERNAL xSTAIRSTEP
EXTERNAL xCOBWEB
EXTERNAL xHIST
EXTERNAL xBOXW
EXTERNAL xLINFIT
EXTERNAL xLOGFIT
EXTERNAL xEXPFIT
EXTERNAL xPOWERFIT
EXTERNAL xQUADFIT
EXTERNAL xCUBICFIT
EXTERNAL xLOGISFIT
EXTERNAL xUSERFIT
EXTERNAL xStat1Var
EXTERNAL xStat2Var
EXTERNAL xxITERATE
EXTERNAL xTRN
EXTERNAL xSEQ
EXTERNAL xRECURSE
EXTERNAL xMKMAT


*
* Covered Function
*
EXTERNAL xIDN
EXTERNAL xUBASE
EXTERNAL xUVAL
EXTERNAL xCOND
EXTERNAL xTRACE
EXTERNAL xSRAD
EXTERNAL xSNRM
EXTERNAL xRANK
EXTERNAL xEGV
EXTERNAL xEGVL
EXTERNAL xSVD
EXTERNAL xSVL
EXTERNAL xLU
EXTERNAL xQR
EXTERNAL xLQ
EXTERNAL xSCHUR
EXTERNAL xRREF
EXTERNAL xSORT
EXTERNAL xREVLIST
EXTERNAL xPRODLIST
EXTERNAL xSUMLIST
EXTERNAL xDELTALIST
EXTERNAL xSIZE
EXTERNAL xCOT
EXTERNAL xSEC
EXTERNAL xCSC
EXTERNAL xACOT
EXTERNAL xASEC
EXTERNAL xACSC
EXTERNAL xUTPC
EXTERNAL xUTPT
EXTERNAL xLSQ
EXTERNAL xSTD
EXTERNAL xxDEG
EXTERNAL xxRAD
EXTERNAL xxGRAD
EXTERNAL xSTD
EXTERNAL xFIX
EXTERNAL xSCI
EXTERNAL xENG
EXTERNAL xFRACTION
EXTERNAL xSTAIRSTEP
EXTERNAL xCOBWEB
EXTERNAL xHIST
EXTERNAL xBOXW
EXTERNAL xLINFIT
EXTERNAL xLOGFIT
EXTERNAL xEXPFIT
EXTERNAL xPOWERFIT
EXTERNAL xQUADFIT
EXTERNAL xCUBICFIT
EXTERNAL xLOGISFIT
EXTERNAL xUSERFIT
EXTERNAL xStat1Var
EXTERNAL xStat2Var
EXTERNAL xxITERATE
EXTERNAL xTRN
EXTERNAL xSEQ

*
* Keyboard Hidden Key
*
EXTERNAL ANSKey0.1
EXTERNAL ANSKey0.2
EXTERNAL ANSKey0.3
EXTERNAL ANSKey0.4
EXTERNAL ANSKey0.5
EXTERNAL ANSKey1.1
EXTERNAL ANSKey1.2
EXTERNAL ANSKey1.3
EXTERNAL ANSKey1.4
EXTERNAL ANSKey1.5
EXTERNAL ANSKey1.6
EXTERNAL ANSKey2.1
EXTERNAL ANSKey2.2
EXTERNAL ANSKey2.3
EXTERNAL ANSKey2.4
EXTERNAL ANSKey3.1
EXTERNAL ANSKey3.2
EXTERNAL ANSKey3.3
EXTERNAL ANSKey3.4
EXTERNAL ANSKey3.5
EXTERNAL ANSKey3.6
EXTERNAL ANSKey4.1
EXTERNAL ANSKey4.2
EXTERNAL ANSKey4.3
EXTERNAL ANSKey4.4
EXTERNAL ANSKey4.5
EXTERNAL ANSKey5.1
EXTERNAL ANSKey5.2
EXTERNAL ANSKey5.3
EXTERNAL ANSKey5.4
EXTERNAL ANSKey5.5
EXTERNAL ANSKey6.1
EXTERNAL ANSKey6.2
EXTERNAL ANSKey6.3
EXTERNAL ANSKey6.4
EXTERNAL ANSKey6.5
EXTERNAL ANSKey7.1
EXTERNAL ANSKey7.2
EXTERNAL ANSKey7.3
EXTERNAL ANSKey7.4
EXTERNAL ANSKey7.5
EXTERNAL ANSKey8.1
EXTERNAL ANSKey8.2
EXTERNAL ANSKey8.3
EXTERNAL ANSKey8.4
EXTERNAL ANSKey8.5
EXTERNAL ANSKey9.1
EXTERNAL ANSKey9.2
EXTERNAL ANSKey9.3
EXTERNAL ANSKey9.4
EXTERNAL ANSKey9.5
EXTERNAL NSKey0.2
EXTERNAL NSKey0.3
EXTERNAL NSKey0.4
EXTERNAL NSKey2.1
EXTERNAL NSKey2.2
EXTERNAL NSKey2.3
EXTERNAL NSKey3.1
EXTERNAL NSKey3.2
EXTERNAL NSKey3.3
EXTERNAL NSKey4.1
EXTERNAL NSKey4.2
EXTERNAL NSKey4.3
EXTERNAL NSKey4.4
EXTERNAL NSKey4.5
EXTERNAL NSKey5.1
EXTERNAL NSKey5.2
EXTERNAL NSKey5.3
EXTERNAL NSKey5.4
EXTERNAL NSKey5.5
EXTERNAL NSKey6.1
EXTERNAL NSKey6.2
EXTERNAL NSKey6.3
EXTERNAL NSKey6.4
EXTERNAL NSKey6.5
EXTERNAL NSKey7.2
EXTERNAL NSKey7.3
EXTERNAL NSKey7.4
EXTERNAL NSKey7.5
EXTERNAL NSKey8.1
EXTERNAL NSKey8.2
EXTERNAL NSKey8.3
EXTERNAL NSKey8.4
EXTERNAL NSKey8.5
EXTERNAL NSKey9.1
EXTERNAL NSKey9.2
EXTERNAL NSKey9.3
EXTERNAL NSKey9.4
EXTERNAL NSKey9.5
EXTERNAL ALSKey0.1
EXTERNAL ALSKey0.2
EXTERNAL ALSKey0.3
EXTERNAL ALSKey0.4
EXTERNAL ALSKey0.5
EXTERNAL ALSKey1.1
EXTERNAL ALSKey1.2
EXTERNAL ALSKey1.3
EXTERNAL ALSKey1.4
EXTERNAL ALSKey1.5
EXTERNAL ALSKey1.6
EXTERNAL ALSKey2.1
EXTERNAL ALSKey2.2
EXTERNAL ALSKey2.3
EXTERNAL ALSKey2.4
EXTERNAL ALSKey3.1
EXTERNAL ALSKey3.2
EXTERNAL ALSKey3.3
EXTERNAL ALSKey3.4
EXTERNAL ALSKey3.5
EXTERNAL ALSKey3.6
EXTERNAL ALSKey4.1
EXTERNAL ALSKey4.2
EXTERNAL ALSKey4.3
EXTERNAL ALSKey4.4
EXTERNAL ALSKey4.5
EXTERNAL ALSKey5.1
EXTERNAL ALSKey5.2
EXTERNAL ALSKey5.3
EXTERNAL ALSKey5.4
EXTERNAL ALSKey5.5
EXTERNAL ALSKey6.1
EXTERNAL ALSKey6.2
EXTERNAL ALSKey6.3
EXTERNAL ALSKey6.4
EXTERNAL ALSKey6.5
EXTERNAL ALSKey7.1
EXTERNAL ALSKey7.2
EXTERNAL ALSKey7.3
EXTERNAL ALSKey7.4
EXTERNAL ALSKey7.5
EXTERNAL ALSKey8.1
EXTERNAL ALSKey8.2
EXTERNAL ALSKey8.3
EXTERNAL ALSKey8.4
EXTERNAL ALSKey8.5
EXTERNAL ALSKey9.1
EXTERNAL ALSKey9.2
EXTERNAL ALSKey9.3
EXTERNAL ALSKey9.4
EXTERNAL ALSKey9.5
EXTERNAL LSKey0.1
EXTERNAL LSKey0.2
EXTERNAL LSKey0.3
EXTERNAL LSKey0.4
EXTERNAL LSKey0.5
EXTERNAL LSKey1.1
EXTERNAL LSKey1.2
EXTERNAL LSKey1.3
EXTERNAL LSKey1.4
EXTERNAL LSKey1.5
EXTERNAL LSKey1.6
EXTERNAL LSKey2.1
EXTERNAL LSKey2.2
EXTERNAL LSKey2.3
EXTERNAL LSKey3.1
EXTERNAL LSKey3.2
EXTERNAL LSKey3.3
EXTERNAL LSKey4.1
EXTERNAL LSKey4.2
EXTERNAL LSKey4.3
EXTERNAL LSKey4.4
EXTERNAL LSKey4.5
EXTERNAL LSKey5.1
EXTERNAL LSKey5.2
EXTERNAL LSKey5.3
EXTERNAL LSKey5.4
EXTERNAL LSKey5.5
EXTERNAL LSKey6.1
EXTERNAL LSKey6.2
EXTERNAL LSKey6.3
EXTERNAL LSKey6.4
EXTERNAL LSKey6.5
EXTERNAL LSKey7.1
EXTERNAL LSKey7.2
EXTERNAL LSKey7.3
EXTERNAL LSKey7.4
EXTERNAL LSKey7.5
EXTERNAL LSKey8.1
EXTERNAL LSKey8.2
EXTERNAL LSKey8.3
EXTERNAL LSKey8.4
EXTERNAL LSKey8.5
EXTERNAL LSKey9.1
EXTERNAL LSKey9.2
EXTERNAL LSKey9.3
EXTERNAL LSKey9.4
EXTERNAL LSKey9.5


**
** MetaKernel System Flags
**
DEFINE fnMultiLine		BINT65
DEFINE fnMultiLineStrings	BINT66
DEFINE fnDigitalClock		BINT67
DEFINE fnCmdAutoIndent		BINT68
DEFINE fnFullScreenEdit		BINT69
DEFINE fnMultiLine2GROB		BINT70
DEFINE fnDesasmWithAdr		BINT71
DEFINE fnBigFontStack		BINT72
DEFINE fnBigFontCmd		BINT73
DEFINE fnRightJustifiedStack	BINT74
DEFINE fnKeystrokeBeep		BINT75
DEFINE fnFilerConfirmation	BINT76
DEFINE fnFilerConfirm		BINT77
DEFINE fnKernelParam		BINT78
DEFINE fnPrettyPrint		BINT79
DEFINE fnSmallFontEQWStack	BINT80
DEFINE fnSmallFontEQWGrob	BINT81
DEFINE fnSmallFontEQWEdit	BINT82
DEFINE fnGrobDisplay		BINT83
DEFINE fnMKSmallFontMenu	BINT84
DEFINE fnSystemRPLStack		BINT85
DEFINE fnMASDDecompiler		BINT86
DEFINE fnRecursiveStack		BINT87
DEFINE fnRecursiveEdit		BINT88
DEFINE fnAddressesCLE		BINT89
DEFINE fnSmallFontChoose	BINT90
DEFINE fnArrayOnly		BINT91
DEFINE fnMLMASDMode		BINT92
DEFINE fnErableHeader		BINT93
DEFINE fnAutoSave		BINT94
DEFINE fnAlgebraicMode		BINT95
DEFINE fnMenuOn			BINT96
DEFINE fnVerticalList		BINT97
DEFINE fnVerticalVector		BINT98

* Erable Flags
DEFINE fnVerboseCAS	BINT99		( set for informations )
DEFINE fnStep		BINT100  	( set for step by step mode on )
DEFINE fnVXXL		BINT101		( internal use: true if VXXL success )
DEFINE fnPgcd		BINT102		( set for no gcd computations )
DEFINE fnComplex	BINT103		( set for complex mode )
DEFINE fnInvLN		BINT104		( internal use:	LN->-INV[-LN]] )
DEFINE fnExact		BINT105		( set for approx mode )
DEFINE fnTSIMP		BINT106		( set for TSIMP call inside SERIES )
DEFINE fnModular	BINT107  	( internal use:	modular computation )
DEFINE fnDivTest	BINT108 	( internal use:	testing remainder=0 )
DEFINE fnNumFactor	BINT109 	( set to allow numeric factorization )
DEFINE fnBigData	BINT110		( set for large matrices )
DEFINE fnRecurse	BINT111  	( set: don't simplify inside non rational operation )
DEFINE fniIsIrrq	BINT112  	( set to see i as an irrquad c=-1 )
DEFINE fnpfexpa		BINT113    	( set to disable linearity simplif. )
DEFINE fnIncreasePower	BINT114   	( set for increasing power x+1 -> 1+x )
DEFINE fnSqrt		BINT115   	( internal use:	sqrt not as irrquad )
DEFINE fnPreferSin	BINT116  	( set if sin are prefered to cos )
DEFINE fnChooseMenu	BINT117    	( set for menu as choosebox )
DEFINE fnKeepInt	BINT118    	( set if xINT is not simplified ) 
DEFINE fnNoCare		BINT119   	( set if non rigourous mode )
DEFINE fnSilent		BINT120		( set to allow silent mode switch )
DEFINE fnLNABS		BINT121  	( set if xLN returns LN[ABS[]] )


ASSEMBLE

MultiLineFl	EQU	65
MultiLineNib	EQU	((MultiLineFl)-1)/4
MultiLineBit	EQU	((MultiLineFl)-1)%4
MultiLineStringsFl	EQU	66
MultiLineStringsNib	EQU	((MultiLineStringsFl)-1)/4
MultiLineStringsBit	EQU	((MultiLineStringsFl)-1)%4
DigitalClockFl	EQU	67
DigitalClockNib	EQU	((DigitalClockFl)-1)/4
DigitalClockBit	EQU	((DigitalClockFl)-1)%4
CmdAutoIndentFl	EQU	68
CmdAutoIndentNib	EQU	((CmdAutoIndentFl)-1)/4
CmdAutoIndentBit	EQU	((CmdAutoIndentFl)-1)%4
FullScreenEditFl	EQU	69
FullScreenEditNib	EQU	((FullScreenEditFl)-1)/4
FullScreenEditBit	EQU	((FullScreenEditFl)-1)%4
MultiLine2GROBFl	EQU	70
MultiLine2GROBNib	EQU	((MultiLine2GROBFl)-1)/4
MultiLine2GROBBit	EQU	((MultiLine2GROBFl)-1)%4
DesasmWithAdrFl	EQU	71
DesasmWithAdrNib	EQU	((DesasmWithAdrFl)-1)/4
DesasmWithAdrBit	EQU	((DesasmWithAdrFl)-1)%4
BigFontStackFl	EQU	72
BigFontStackNib	EQU	((BigFontStackFl)-1)/4
BigFontStackBit	EQU	((BigFontStackFl)-1)%4
BigFontCmdFl	EQU	73
BigFontCmdNib	EQU	((BigFontCmdFl)-1)/4
BigFontCmdBit	EQU	((BigFontCmdFl)-1)%4
RightJustifiedStackFl	EQU	74
RightJustifiedStackNib	EQU	((RightJustifiedStackFl)-1)/4
RightJustifiedStackBit	EQU	((RightJustifiedStackFl)-1)%4
KeystrokeBeepFl	EQU	75
KeystrokeBeepNib	EQU	((KeystrokeBeepFl)-1)/4
KeystrokeBeepBit	EQU	((KeystrokeBeepFl)-1)%4
FilerConfirmationFl	EQU	76
FilerConfirmationNib	EQU	((FilerConfirmationFl)-1)/4
FilerConfirmationBit	EQU	((FilerConfirmationFl)-1)%4
FilerConfirmFl	EQU	77
FilerConfirmNib	EQU	((FilerConfirmFl)-1)/4
FilerConfirmBit	EQU	((FilerConfirmFl)-1)%4
KernelParamFl	EQU	78
KernelParamNib	EQU	((KernelParamFl)-1)/4
KernelParamBit	EQU	((KernelParamFl)-1)%4
PrettyPrintFl	EQU	79
PrettyPrintNib	EQU	((PrettyPrintFl)-1)/4
PrettyPrintBit	EQU	((PrettyPrintFl)-1)%4
SmallFontEQWStackFl	EQU	80
SmallFontEQWStackNib	EQU	((SmallFontEQWStackFl)-1)/4
SmallFontEQWStackBit	EQU	((SmallFontEQWStackFl)-1)%4
SmallFontEQWGrobFl	EQU	81
SmallFontEQWGrobNib	EQU	((SmallFontEQWGrobFl)-1)/4
SmallFontEQWGrobBit	EQU	((SmallFontEQWGrobFl)-1)%4
SmallFontEQWEditFl	EQU	82
SmallFontEQWEditNib	EQU	((SmallFontEQWEditFl)-1)/4
SmallFontEQWEditBit	EQU	((SmallFontEQWEditFl)-1)%4
GrobDisplayFl	EQU	83
GrobDisplayNib	EQU	((GrobDisplayFl)-1)/4
GrobDisplayBit	EQU	((GrobDisplayFl)-1)%4
MKSmallFontMenuFl	EQU	84
MKSmallFontMenuNib	EQU	((MKSmallFontMenuFl)-1)/4
MKSmallFontMenuBit	EQU	((MKSmallFontMenuFl)-1)%4
SystemRPLStackFl	EQU	85
SystemRPLStackNib	EQU	((SystemRPLStackFl)-1)/4
SystemRPLStackBit	EQU	((SystemRPLStackFl)-1)%4
MASDDecompilerFl	EQU	86
MASDDecompilerNib	EQU	((MASDDecompilerFl)-1)/4
MASDDecompilerBit	EQU	((MASDDecompilerFl)-1)%4
RecursiveStackFl	EQU	87
RecursiveStackNib	EQU	((RecursiveStackFl)-1)/4
RecursiveStackBit	EQU	((RecursiveStackFl)-1)%4
RecursiveEditFl	EQU	88
RecursiveEditNib	EQU	((RecursiveEditFl)-1)/4
RecursiveEditBit	EQU	((RecursiveEditFl)-1)%4
AddressesCLEFl	EQU	89
AddressesCLENib	EQU	((AddressesCLEFl)-1)/4
AddressesCLEBit	EQU	((AddressesCLEFl)-1)%4
SmallFontChooseFl	EQU	90
SmallFontChooseNib	EQU	((SmallFontChooseFl)-1)/4
SmallFontChooseBit	EQU	((SmallFontChooseFl)-1)%4
ArrayOnlyFl	EQU	91
ArrayOnlyNib	EQU	((ArrayOnlyFl)-1)/4
ArrayOnlyBit	EQU	((ArrayOnlyFl)-1)%4
MLMASDModeFl	EQU	92
MLMASDModeNib	EQU	((MLMASDModeFl)-1)/4
MLMASDModeBit	EQU	((MLMASDModeFl)-1)%4
ErableHeaderFl	EQU	93
ErableHeaderNib	EQU	((ErableHeaderFl)-1)/4
ErableHeaderBit	EQU	((ErableHeaderFl)-1)%4
AutoSaveFl	EQU	94
AutoSaveNib	EQU	((AutoSaveFl)-1)/4
AutoSaveBit	EQU	((AutoSaveFl)-1)%4
AlgebraicModeFl	EQU	95
AlgebraicModeNib	EQU	((AlgebraicModeFl)-1)/4
AlgebraicModeBit	EQU	((AlgebraicModeFl)-1)%4
MenuOnFl	EQU	96
MenuOnNib	EQU	((MenuOnFl)-1)/4
MenuOnBit	EQU	((MenuOnFl)-1)%4
VerticalListFl	EQU	97
VerticalListNib	EQU	((VerticalListFl)-1)/4
VerticalListBit	EQU	((VerticalListFl)-1)%4
VerticalVectorFl	EQU	98
VerticalVectorNib	EQU	((VerticalVectorFl)-1)/4
VerticalVectorBit	EQU	((VerticalVectorFl)-1)%4


** Erable ML Flags
ComplexFl	EQU	103
ComplexNib	EQU	((ComplexFl)-1)/4
ComplexBit	EQU	((ComplexFl)-1)%4


ExactModeFl	EQU	105
ExactModeNib	EQU	((ExactModeFl)-1)/4
ExactModeBit	EQU	((ExactModeFl)-1)%4


RPL

** Flash Pointer object
FEXTERNAL FSTR1
FEXTERNAL FSTR2
FEXTERNAL FSTR3
FEXTERNAL FSTR4
FEXTERNAL FSTR5
FEXTERNAL FSTR6
FEXTERNAL FSTR7
FEXTERNAL FSTR8
FEXTERNAL FSTR9
FEXTERNAL FSTR10
FEXTERNAL FSTR11
FEXTERNAL FSTR12
FEXTERNAL FSTR13


* CAS flash pointer declarations
FEXTERNAL xEXPAND
FEXTERNAL xFACTOR
FEXTERNAL xSUBST
FEXTERNAL xDERVX
FEXTERNAL xINTVX
FEXTERNAL xLIMIT
FEXTERNAL xTAYLOR0
FEXTERNAL xSERIES
FEXTERNAL xSOLVEVX
FEXTERNAL xPLOT
FEXTERNAL xPLOTADD
FEXTERNAL xIBP
FEXTERNAL xPREVAL
FEXTERNAL xRISCH
FEXTERNAL xDERIV
FEXTERNAL xDESOLVE
FEXTERNAL xLAP
FEXTERNAL xILAP
FEXTERNAL xLDEC
FEXTERNAL xTEXPAND
FEXTERNAL xLIN
FEXTERNAL xTSIMP
FEXTERNAL xLNCOLLECT
FEXTERNAL xEXPLN
FEXTERNAL xSINCOS
FEXTERNAL xTLIN
FEXTERNAL xTCOLLECT
FEXTERNAL xTRIG
FEXTERNAL xTRIGCOS
FEXTERNAL xTRIGSIN
FEXTERNAL xTRIGTAN
FEXTERNAL xTAN2SC
FEXTERNAL xHALFTAN
FEXTERNAL xTAN2SC2
FEXTERNAL xATAN2S
FEXTERNAL xASIN2T
FEXTERNAL xASIN2C
FEXTERNAL xACOS2S
FEXTERNAL xDIV2
FEXTERNAL xIDIV2
FEXTERNAL xQUOT
FEXTERNAL xIQUOT
FEXTERNAL xREMAINDER
FEXTERNAL xIREMAINDER
FEXTERNAL xGCD
FEXTERNAL xLCM
FEXTERNAL xEGCD
FEXTERNAL xIEGCD
FEXTERNAL xABCUV
FEXTERNAL xIABCUV
FEXTERNAL xLGCD
FEXTERNAL xSIMP2
FEXTERNAL xPARTFRAC
FEXTERNAL xPROPFRAC
FEXTERNAL xPTAYL
FEXTERNAL xHORNER
FEXTERNAL xEULER
FEXTERNAL xPA2B2
FEXTERNAL xCHINREM
FEXTERNAL xICHINREM
FEXTERNAL xISPRIME?
FEXTERNAL xNEXTPRIME
FEXTERNAL xPREVPRIME
FEXTERNAL xSOLVE
FEXTERNAL xZEROS
FEXTERNAL xFCOEF
FEXTERNAL xFROOTS
FEXTERNAL xFACTORS
FEXTERNAL xDIVIS
FEXTERNAL xTRAN
FEXTERNAL xHADAMARD
FEXTERNAL xrref
FEXTERNAL xREF
FEXTERNAL xAXM
FEXTERNAL xAXL
FEXTERNAL xQXA
FEXTERNAL xAXQ
FEXTERNAL xGAUSS
FEXTERNAL xSYLVESTER
FEXTERNAL xPCAR
FEXTERNAL xJORDAN
FEXTERNAL xMAD
FEXTERNAL xLINSOLVE
FEXTERNAL xVANDERMONDE
FEXTERNAL xHILBERT
FEXTERNAL xDIV
FEXTERNAL xCURL
FEXTERNAL xLAPL
FEXTERNAL xHESS
FEXTERNAL xLEGENDRE
FEXTERNAL xTCHEBYCHEFF
FEXTERNAL xHERMITE
FEXTERNAL xLAGRANGE
FEXTERNAL xFOURIER
FEXTERNAL xSIGNTAB
FEXTERNAL xTABVAR
FEXTERNAL xTABVAL
FEXTERNAL xDIVPC
FEXTERNAL xTRUNC
FEXTERNAL xSEVAL
FEXTERNAL xTEVAL
FEXTERNAL xMAP
FEXTERNAL xXNUM
FEXTERNAL xXQ
FEXTERNAL xREORDER
FEXTERNAL xLVAR
FEXTERNAL xFXND
FEXTERNAL xEXLR
FEXTERNAL xLNAME
FEXTERNAL xADDTMOD
FEXTERNAL xSUBTMOD
FEXTERNAL xMULTMOD
FEXTERNAL xDIVMOD
FEXTERNAL xDIV2MOD
FEXTERNAL xPOWMOD
FEXTERNAL xINVMOD
FEXTERNAL xGCDMOD
FEXTERNAL xEXPANDMOD
FEXTERNAL xFACTORMOD
FEXTERNAL xRREFMOD
FEXTERNAL xMODSTO
FEXTERNAL xMENUXY
FEXTERNAL xKEYEVAL
FEXTERNAL xGROBADD
FEXTERNAL xSCROLL
FEXTERNAL xCASCFG
FEXTERNAL xMAIN
FEXTERNAL xALGB
FEXTERNAL xCMPLX
FEXTERNAL xTRIGO
FEXTERNAL xMATR
FEXTERNAL xDIFF
FEXTERNAL xARIT
FEXTERNAL xSOLVER
FEXTERNAL xEXP&LN
FEXTERNAL xEPSX0
FEXTERNAL x?
FEXTERNAL x\9F
FEXTERNAL xPROMPTSTO
FEXTERNAL xVER
FEXTERNAL BerlekampP
FEXTERNAL Berlekamp
FEXTERNAL ErrInfRes
FEXTERNAL ErrUndefRes
FEXTERNAL ErrBadDim
FEXTERNAL ALG48MSOLV
FEXTERNAL GMSOLV
FEXTERNAL GBASIS
FEXTERNAL GSOLVE
FEXTERNAL GFACTOR
FEXTERNAL GREDUCE
FEXTERNAL REDUCE
FEXTERNAL FASTREDUCE
FEXTERNAL ONE{}POLY
FEXTERNAL TWO{}POLY
FEXTERNAL THREE{}POLY
FEXTERNAL TWO::POLY
FEXTERNAL ::POLY
FEXTERNAL {}POLY
FEXTERNAL >TPOLY
FEXTERNAL >HPOLY
FEXTERNAL >TPOLYN
FEXTERNAL >HPOLYN
FEXTERNAL MKPOLY
FEXTERNAL ONE>POLY
FEXTERNAL >POLY
FEXTERNAL ALG48FCTR?
FEXTERNAL MFactTriv
FEXTERNAL CheckPNoExt
FEXTERNAL PPP
FEXTERNAL PFactor
FEXTERNAL PSqff
FEXTERNAL PHFctr
FEXTERNAL PHFctr1
FEXTERNAL PHFctr0
FEXTERNAL DeCntMulti
FEXTERNAL DoLS
FEXTERNAL PNFctr
FEXTERNAL PSQFF
FEXTERNAL LiftZAdic
FEXTERNAL LFCProd
FEXTERNAL UFactor
FEXTERNAL UFactor1
FEXTERNAL MonicLf
FEXTERNAL DemonicLf
FEXTERNAL LiftLinear
FEXTERNAL LiftGeneral
FEXTERNAL UFactorDeg2
FEXTERNAL CombineFac
FEXTERNAL CombProd
FEXTERNAL CombInit
FEXTERNAL CombNext
FEXTERNAL RmCombNext
FEXTERNAL PFactTriv
FEXTERNAL VarFactor
FEXTERNAL PFactPowCnt
FEXTERNAL PDivLk
FEXTERNAL Prime+
FEXTERNAL Prime-
FEXTERNAL ZFactor
FEXTERNAL NFactor
FEXTERNAL NFactorSpc
FEXTERNAL DupTypeS?
FEXTERNAL SFactor
FEXTERNAL SPollard
FEXTERNAL BFactor
FEXTERNAL BrentPow
FEXTERNAL ZPrime?
FEXTERNAL ZIsPrime?
FEXTERNAL SIsPrime?
FEXTERNAL BIsPrime?
FEXTERNAL BRabin
FEXTERNAL ZTrialDiv2
FEXTERNAL ZTrialPrime?
FEXTERNAL ZTrialDiv
FEXTERNAL QMod
FEXTERNAL QMODSYMext
FEXTERNAL ModPow
FEXTERNAL ZQUOText
FEXTERNAL ZMod
FEXTERNAL ZDIVext
FEXTERNAL QRoot
FEXTERNAL ZSQRT
FEXTERNAL PEvalMod
FEXTERNAL QAddMod
FEXTERNAL QSubMod
FEXTERNAL QMulMod
FEXTERNAL QDivMod
FEXTERNAL QInvMod
FEXTERNAL QGcdMod
FEXTERNAL QGcdExMod
FEXTERNAL IsV>V?
FEXTERNAL PEvalFast?
FEXTERNAL PZadic
FEXTERNAL GCDHEUext
FEXTERNAL H>Z
FEXTERNAL #>Z
FEXTERNAL Z2BIN
FEXTERNAL COERCE2Z
FEXTERNAL Z>S
FEXTERNAL S>Z
FEXTERNAL S>Z?
FEXTERNAL Z>ZH
FEXTERNAL R>Z
FEXTERNAL Z>R
FEXTERNAL DupQIsZero?
FEXTERNAL QIsZero?
FEXTERNAL DupZIsOne?
FEXTERNAL ZIsOne?
FEXTERNAL DupZIsNeg?
FEXTERNAL ZIsNeg?
FEXTERNAL ListPos
FEXTERNAL AppendList
FEXTERNAL Contains?
FEXTERNAL SortList
FEXTERNAL ZTrim
FEXTERNAL ZAbs
FEXTERNAL PNMax
FEXTERNAL LISTMAXext
FEXTERNAL ZNMax
FEXTERNAL ZNMin
FEXTERNAL ZNLT?
FEXTERNAL DISTDIVext
FEXTERNAL DupZIsTwo?
FEXTERNAL DupZIsEven?
FEXTERNAL Univar?
FEXTERNAL SUnivar?
FEXTERNAL ZBits
FEXTERNAL ZBit?
FEXTERNAL LOPMext
FEXTERNAL SWAPRMULT
FEXTERNAL QMul
FEXTERNAL RMULText
FEXTERNAL RASOP
FEXTERNAL SWAPRSUB
FEXTERNAL QSub
FEXTERNAL RSUBext
FEXTERNAL SWAPRADD
FEXTERNAL QAdd
FEXTERNAL RADDext
FEXTERNAL SWAPRDIV
FEXTERNAL RDIVext
FEXTERNAL QDiv
FEXTERNAL R15SIMP
FEXTERNAL PPow#
FEXTERNAL RP#
FEXTERNAL MPext
FEXTERNAL MP0
FEXTERNAL MPEXEC
FEXTERNAL RPext
FEXTERNAL PREPARext
FEXTERNAL x+ext
FEXTERNAL x-ext
FEXTERNAL x*ext
FEXTERNAL x=ext
FEXTERNAL x/ext
FEXTERNAL 2SYMBINCOMP
FEXTERNAL x^ext
FEXTERNAL EXPAND^
FEXTERNAL addtXROOT
FEXTERNAL xssSYMXROOT
FEXTERNAL addtMIN
FEXTERNAL xssSYMMIN
FEXTERNAL addtMAX
FEXTERNAL xssSYMMAX
FEXTERNAL addt<
FEXTERNAL xssSYM<?
FEXTERNAL addt<=
FEXTERNAL xssSYM<=?
FEXTERNAL addt>
FEXTERNAL xssSYM>?
FEXTERNAL addt>=
FEXTERNAL xssSYM>=?
FEXTERNAL addt==
FEXTERNAL xssSYM=?
FEXTERNAL addt!=
FEXTERNAL xssSYM#?
FEXTERNAL addt%
FEXTERNAL xssSYM%
FEXTERNAL addt%CH
FEXTERNAL xssSYM%CH
FEXTERNAL addt%T
FEXTERNAL xssSYM%T
FEXTERNAL addtMOD
FEXTERNAL xssSYMMOD
FEXTERNAL addtTRNC
FEXTERNAL xssSYMTRCXY
FEXTERNAL addtRND
FEXTERNAL xssSYMRNDXY
FEXTERNAL addtCOMB
FEXTERNAL xssSYMCOMB
FEXTERNAL addtPERM
FEXTERNAL xssSYMPERM
FEXTERNAL addtOR
FEXTERNAL xssSYMOR
FEXTERNAL addtAND
FEXTERNAL xssSYMAND
FEXTERNAL addtXOR
FEXTERNAL xssSYMXOR
FEXTERNAL 2LAMBIND
FEXTERNAL 3LAMBIND
FEXTERNAL SYMBINCOMP
FEXTERNAL CKINNERCOMP
FEXTERNAL DUPCKLEN{}
FEXTERNAL CKCARCOMP
FEXTERNAL CARCOMPext
FEXTERNAL RISCH13
FEXTERNAL CXRIext
FEXTERNAL RIXCext
FEXTERNAL IRXCext
FEXTERNAL IRXC2
FEXTERNAL SWAPNDXF
FEXTERNAL NDXFext
FEXTERNAL SWAPFXND
FEXTERNAL FXNDext
FEXTERNAL QXNDext
FEXTERNAL NDXQext
FEXTERNAL TYPEIRRQ?
FEXTERNAL DTYPEIRRQ?
FEXTERNAL BESTMATRIXTYPE
FEXTERNAL {}TO[]
FEXTERNAL []TO{}
FEXTERNAL DUPNULL[]?
FEXTERNAL CKSAMESIZE
FEXTERNAL DTYPENDO?
FEXTERNAL DTYPFMAT?
FEXTERNAL CKNUMARRY
FEXTERNAL 2DMATRIX?
FEXTERNAL MATRIXDIM
FEXTERNAL SAMEMATRIX
FEXTERNAL SAMEMATSCTYPE
FEXTERNAL CKMATRIXELEM
FEXTERNAL MATRIX2ARRAY
FEXTERNAL MATRIX2LIST
FEXTERNAL LIST2MATRIX
FEXTERNAL LENMATRIX
FEXTERNAL XEQARRY>
FEXTERNAL MATEXPLODE
FEXTERNAL ARRAY2MATRIX
FEXTERNAL XEQ>ARRY
FEXTERNAL XEQ>ARRAY1
FEXTERNAL CKALG
FEXTERNAL TYPEZ?
FEXTERNAL DUPTYPEZ?
FEXTERNAL CK1Z
FEXTERNAL CK2Z
FEXTERNAL CK3Z
FEXTERNAL CK1Cext
FEXTERNAL C2C%%
FEXTERNAL ZZ2C%%ext
FEXTERNAL Z2%%
FEXTERNAL C%>C%%
FEXTERNAL E%%>C%%
FEXTERNAL R2Zext
FEXTERNAL Z2Sext
FEXTERNAL CKFPOLYext
FEXTERNAL CK2FPOLY
FEXTERNAL IDNTLAM?
FEXTERNAL FLOAT?
FEXTERNAL CKSYMREALCMP
FEXTERNAL TYPEIDNTLAM?
FEXTERNAL REAL?
FEXTERNAL TYPEREALZINT?
FEXTERNAL OBJ2REAL
FEXTERNAL METAINT?
FEXTERNAL METAPOSINT?
FEXTERNAL OBJINT?
FEXTERNAL OBJPOSINT?
FEXTERNAL CKINT>0
FEXTERNAL Z>#
FEXTERNAL CLEANIDLAM
FEXTERNAL ssSYMDER
FEXTERNAL SYMDER
FEXTERNAL DERIVext
FEXTERNAL siSYMDER
FEXTERNAL DERIVIDNT
FEXTERNAL DERIVIDNT1
FEXTERNAL DERIV
FEXTERNAL METADERIV
FEXTERNAL DO>STRID
FEXTERNAL METADEROP
FEXTERNAL METADER+
FEXTERNAL METADER-
FEXTERNAL METADER*
FEXTERNAL METADER/
FEXTERNAL METADER^
FEXTERNAL METADERFCN
FEXTERNAL METADERDER
FEXTERNAL METADERI4
FEXTERNAL METADERI3
FEXTERNAL METADERIFTE
FEXTERNAL DERARG
FEXTERNAL METADEREXP
FEXTERNAL METADERLN
FEXTERNAL METADERLNP1
FEXTERNAL METADERLOG
FEXTERNAL METADERALOG
FEXTERNAL METADERABS
FEXTERNAL METADERINV
FEXTERNAL METADERNEG
FEXTERNAL METADERSQRT
FEXTERNAL METADER&NEG
FEXTERNAL METADERSQ
FEXTERNAL METADERSIN
FEXTERNAL METADERCOS
FEXTERNAL METADERTAN
FEXTERNAL METADERSINH
FEXTERNAL METADERCOSH
FEXTERNAL METADERTANH
FEXTERNAL METADERASIN
FEXTERNAL METADERACOS
FEXTERNAL METADERATAN
FEXTERNAL METADERASH
FEXTERNAL METADERACH
FEXTERNAL METADERATH
FEXTERNAL pshder*
FEXTERNAL SQRTINVpshd*
FEXTERNAL ckaddt*
FEXTERNAL ckaddt+
FEXTERNAL ckaddt-
FEXTERNAL VERNUMext
FEXTERNAL MENUXYext
FEXTERNAL SAVECASFLAGS
FEXTERNAL SAFEPURGE
FEXTERNAL RESTORECASFLAGS
FEXTERNAL CASFLAGEVAL
FEXTERNAL FLAGEXPAND
FEXTERNAL EXPANDBOTH
FEXTERNAL FLAGFACTOR
FEXTERNAL FLAGLISTEXEC
FEXTERNAL FLAGSYMBEXEC
FEXTERNAL FLAGIDNTEXEC
FEXTERNAL FLAGINTVX
FEXTERNAL DERVX
FEXTERNAL SOLVEXFLOAT
FEXTERNAL SYMLIMIT
FEXTERNAL FLAGMATRIXLIMIT
FEXTERNAL TAYLOR0
FEXTERNAL FLAGSERIES
FEXTERNAL PLOTSTK
FEXTERNAL PLOTADD
FEXTERNAL FLAGIBP
FEXTERNAL FLAGPREVAL
FEXTERNAL MATRIXRISCH
FEXTERNAL FLAGRISCH
FEXTERNAL FLAGDERIV
FEXTERNAL FLAGLAP
FEXTERNAL FLAGILAP
FEXTERNAL FLAGDESOLVE
FEXTERNAL FLAGLDSSOLV
FEXTERNAL FLAGLDECSOLV
FEXTERNAL FLAGTEXPAND
FEXTERNAL FLAGLIN
FEXTERNAL FLAGTSIMP
FEXTERNAL FLAGLNCOLLECT
FEXTERNAL FLAGEXPLN
FEXTERNAL FLAGSINCOS
FEXTERNAL FLAGTLIN
FEXTERNAL FLAGTCOLLECT
FEXTERNAL FLAGTRIG
FEXTERNAL FLAGTRIGCOS
FEXTERNAL FLAGTRIGSIN
FEXTERNAL FLAGTRIGTAN
FEXTERNAL FLAGTAN2SC
FEXTERNAL FLAGHALFTAN
FEXTERNAL FLAGTAN2SC2
FEXTERNAL FLAGATAN2S
FEXTERNAL FLAGASIN2T
FEXTERNAL FLAGASIN2C
FEXTERNAL FLAGACOS2S
FEXTERNAL CK&CONVINT
FEXTERNAL CK&CONV2INT
FEXTERNAL CONVBACK2INT
FEXTERNAL CONVBACKINT
FEXTERNAL STEPIDIV2
FEXTERNAL FLAGDIV2
FEXTERNAL FLAGGCD
FEXTERNAL PEGCD
FEXTERNAL IEGCD
FEXTERNAL ABCUV
FEXTERNAL IABCUV
FEXTERNAL FLAGLGCD
FEXTERNAL FLAGLCM
FEXTERNAL FLAGSIMP2
FEXTERNAL FLAGPARTFRAC
FEXTERNAL FLAGPROPFRAC
FEXTERNAL FLAGPTAYL
FEXTERNAL FLAGHORNER
FEXTERNAL EULER
FEXTERNAL PA2B2
FEXTERNAL FLAGCHINREM
FEXTERNAL ICHINREM
FEXTERNAL ISPRIME
FEXTERNAL SOLVE1EQ
FEXTERNAL SOLVEMANYEQ
FEXTERNAL ZEROS1EQ
FEXTERNAL ZEROSMANYEQ
FEXTERNAL FCOEF
FEXTERNAL FROOTS
FEXTERNAL FACTORS
FEXTERNAL DIVIS
FEXTERNAL STUDMULT
FEXTERNAL STUDDIV
FEXTERNAL rref
FEXTERNAL FLAGQXA
FEXTERNAL FLAGAXQ
FEXTERNAL FLAGGAUSS
FEXTERNAL FLAGSYLVESTER
FEXTERNAL PCAR
FEXTERNAL MADNOCK
FEXTERNAL SYSTEM
FEXTERNAL VANDERMONDE
FEXTERNAL HILBERTNOCK
FEXTERNAL FLAGJORDAN
FEXTERNAL CURL
FEXTERNAL DIVERGENCE
FEXTERNAL LAPLACIAN
FEXTERNAL HESSIAN
FEXTERNAL HERMITE
FEXTERNAL TCHEBNOCK
FEXTERNAL LEGENDRE
FEXTERNAL LAGRANGE
FEXTERNAL FOURIER
FEXTERNAL SIGNE
FEXTERNAL TABVAR
FEXTERNAL FLAGDIVPC
FEXTERNAL FLAGTRUNC
FEXTERNAL FLAGSEVAL
FEXTERNAL XNUM
FEXTERNAL REORDER
FEXTERNAL USERLVAR
FEXTERNAL USERLIDNT
FEXTERNAL EXLR
FEXTERNAL ADDTMOD
FEXTERNAL MADDTMOD
FEXTERNAL SUBTMOD
FEXTERNAL MSUBTMOD
FEXTERNAL MULTMOD
FEXTERNAL MAT*SCMOD
FEXTERNAL SC*MATMOD
FEXTERNAL MAT*MATMOD
FEXTERNAL DIVMOD
FEXTERNAL GCD1MOD
FEXTERNAL INVMOD
FEXTERNAL MINVMOD
FEXTERNAL FLAGDIV2MOD
FEXTERNAL FLAGPOWMOD
FEXTERNAL FLAGMPOWMOD
FEXTERNAL EXPAMOD
FEXTERNAL FLAGEXPAMOD
FEXTERNAL FLAGFACTORMOD
FEXTERNAL MFACTORMOD
FEXTERNAL RREFMOD
FEXTERNAL KEYEVAL
FEXTERNAL LIFCext
FEXTERNAL EvalNoCKx*
FEXTERNAL EvalNoCKx+
FEXTERNAL EvalNoCKx-
FEXTERNAL EvalNoCKx/
FEXTERNAL EvalNoCKx^
FEXTERNAL EvalNoCKxCHS
FEXTERNAL EvalNoCKxINV
FEXTERNAL EvalNoCKxMOD
FEXTERNAL EvalNoCKxPERM
FEXTERNAL EvalNoCKxCOMB
FEXTERNAL EvalNoCKxOR
FEXTERNAL EvalNoCKxAND
FEXTERNAL EvalNoCKxXOR
FEXTERNAL EvalNoCKxXROOT
FEXTERNAL TABVALext
FEXTERNAL TOLISText
FEXTERNAL FROMLISText
FEXTERNAL PFEXECext
FEXTERNAL LOP1ext
FEXTERNAL LOPAext
FEXTERNAL LISTSECOext
FEXTERNAL rpnQOBJext
FEXTERNAL CK1TONOext
FEXTERNAL COLCext
FEXTERNAL SYMCOLCT
FEXTERNAL COLC1
FEXTERNAL COLC2
FEXTERNAL MULMULText
FEXTERNAL METAMULMULT
FEXTERNAL METAMM2
FEXTERNAL COMPLISText
FEXTERNAL METACOMPRIM
FEXTERNAL METACOMP0
FEXTERNAL METACOMP1
FEXTERNAL ADDLISText
FEXTERNAL DIVISext
FEXTERNAL FACT1ext
FEXTERNAL FACTOext
FEXTERNAL ZFACTO
FEXTERNAL SOLVext
FEXTERNAL FRND
FEXTERNAL BICARREE?
FEXTERNAL REALBICAR
FEXTERNAL FEVIDENText
FEXTERNAL EVIDENText
FEXTERNAL EVIDSOLV
FEXTERNAL DEG2ext
FEXTERNAL METADEG2
FEXTERNAL METADEG1
FEXTERNAL DEG1
FEXTERNAL FDEG2ext
FEXTERNAL PIext
FEXTERNAL RACTOFACext
FEXTERNAL FACTORACext
FEXTERNAL RFACText
FEXTERNAL RFACT2ext
FEXTERNAL RFACTSTEP3
FEXTERNAL RFACTSTEP5
FEXTERNAL METASOLV
FEXTERNAL METASOLVOUT
FEXTERNAL METASOLV2
FEXTERNAL METASOLV4
FEXTERNAL ADDMULTIPL
FEXTERNAL FACTOOBJext
FEXTERNAL SLVARext
FEXTERNAL SIMPLIFY
FEXTERNAL SIMP1ext
FEXTERNAL SYMEXPAN
FEXTERNAL SIMPVAR
FEXTERNAL ID>DERext
FEXTERNAL SIMPIDNT
FEXTERNAL RCLALLIDNT
FEXTERNAL RCL1IDNT
FEXTERNAL SIMPSYMBS
FEXTERNAL SYMINTEGRAL
FEXTERNAL SIMPUSERFCN
FEXTERNAL EVALUSERFCN
FEXTERNAL SIMP|
FEXTERNAL DENOLCMext
FEXTERNAL METADENOLCM
FEXTERNAL SWPSIMPNDXF
FEXTERNAL SIMPNDXFext
FEXTERNAL SIMPext
FEXTERNAL SIMPEXTOK
FEXTERNAL MAKEPROFOND
FEXTERNAL SLOWSIMP2L
FEXTERNAL SIMPGCDext
FEXTERNAL SIMP3ext
FEXTERNAL SIMP3LISText
FEXTERNAL SIMP3LSTSLOW
FEXTERNAL LPGCDext
FEXTERNAL SLOWGCDext
FEXTERNAL QGcd
FEXTERNAL GCDext
FEXTERNAL CGCDext
FEXTERNAL CMODext
FEXTERNAL ZGCDext
FEXTERNAL ZGcd
FEXTERNAL TSIMP2ext
FEXTERNAL TSIMPext
FEXTERNAL TSIMP3ext
FEXTERNAL LASTCOMP
FEXTERNAL SQFF2ext
FEXTERNAL PPZ
FEXTERNAL PZHSTR
FEXTERNAL HORNER1ext
FEXTERNAL PEval
FEXTERNAL RISCHext
FEXTERNAL risch/
FEXTERNAL rischABS
FEXTERNAL IBP
FEXTERNAL SQRT_IN?
FEXTERNAL IS_SQRT?
FEXTERNAL XROOT_IN?
FEXTERNAL IS_XROOT?
FEXTERNAL STOPRIMIT
FEXTERNAL CONTAINS_LN?
FEXTERNAL ISNT_IDNT?
FEXTERNAL RISCHPF
FEXTERNAL RISCHRAT
FEXTERNAL rischlogpart
FEXTERNAL PREVALext
FEXTERNAL WARNSING
FEXTERNAL INText
FEXTERNAL INT3
FEXTERNAL FOURIERext
FEXTERNAL 3DUP
FEXTERNAL #3+ROLL
FEXTERNAL 2DROPTRUE
FEXTERNAL IRRQ#ULTIMATE
FEXTERNAL LESSCOMPLEX?
FEXTERNAL LISTIRRQ
FEXTERNAL LIST1i-1-i
FEXTERNAL LIST10-10
FEXTERNAL TABLECOSext
FEXTERNAL TABLETANext
FEXTERNAL DROPZ1
FEXTERNAL DROPZ0
FEXTERNAL TESTINFINI
FEXTERNAL INFINIext
FEXTERNAL MINUSINFext
FEXTERNAL PLUSINFext
FEXTERNAL ?ext
FEXTERNAL POSINFext
FEXTERNAL POSUNDEFext
FEXTERNAL pisur2
FEXTERNAL pisur-2
FEXTERNAL pi
FEXTERNAL metapi
FEXTERNAL 'xPI
FEXTERNAL metai
FEXTERNAL 'xi
FEXTERNAL ipi
FEXTERNAL metaipi
FEXTERNAL meta-pi
FEXTERNAL metapi/2
FEXTERNAL metapi/4
FEXTERNAL meta-pi/2
FEXTERNAL meta-pi/4
FEXTERNAL pifois2
FEXTERNAL deuxipi
FEXTERNAL metapi*2
FEXTERNAL base_ln
FEXTERNAL meta_e
FEXTERNAL NEXTPext
FEXTERNAL INSERT{}N
FEXTERNAL COMPRIMext
FEXTERNAL TCOLLECT
FEXTERNAL SIGMAEXPext
FEXTERNAL LINEXPext
FEXTERNAL SIGMAEXP2ext
FEXTERNAL TCHEBext
FEXTERNAL SINEXPA
FEXTERNAL METASINEXPA
FEXTERNAL SINEXPA+
FEXTERNAL SINEXPA-
FEXTERNAL SINEXPA*
FEXTERNAL SINEXPA*1
FEXTERNAL COSEXPA
FEXTERNAL METACOSEXPA
FEXTERNAL COSEXPA+
FEXTERNAL COSEXPA-
FEXTERNAL COSEXPA*
FEXTERNAL COSEXPA*1
FEXTERNAL EXPEXPA
FEXTERNAL METAEXPEXPA
FEXTERNAL EXPEXPA+
FEXTERNAL EXPEXPA-
FEXTERNAL EXPEXPA*
FEXTERNAL EXPEXPANEG
FEXTERNAL EXPEXPA*1
FEXTERNAL LNEXPA
FEXTERNAL METALNEXPA
FEXTERNAL LNEXPA*
FEXTERNAL LNEXPA/
FEXTERNAL LNEXPA^
FEXTERNAL LINEXPA
FEXTERNAL MTRIG2SYMB
FEXTERNAL LNCOLCext
FEXTERNAL METATANEXPA
FEXTERNAL TEXPAext
FEXTERNAL MAT+
FEXTERNAL MADD
FEXTERNAL MAT-
FEXTERNAL MSUB
FEXTERNAL VADD
FEXTERNAL VSUB
FEXTERNAL MAT*
FEXTERNAL MMMULT
FEXTERNAL MVMULT
FEXTERNAL SCL*MAT
FEXTERNAL MAT*SCL
FEXTERNAL VPMULT
FEXTERNAL MAT^
FEXTERNAL MATCROSS
FEXTERNAL MATDOT
FEXTERNAL RNDARRY
FEXTERNAL TRCARRY
FEXTERNAL XYext
FEXTERNAL MAT/SCL
FEXTERNAL MAT/
FEXTERNAL MATCHS
FEXTERNAL MATSQUARE
FEXTERNAL MATCONJ
FEXTERNAL MATRE
FEXTERNAL MATIM
FEXTERNAL MATTRACE
FEXTERNAL MATTRAN
FEXTERNAL mattran
FEXTERNAL mattrn
FEXTERNAL MATSUB
FEXTERNAL submeta
FEXTERNAL MATREPL
FEXTERNAL VRRDM
FEXTERNAL VRRDMmeta
FEXTERNAL MATRANM
FEXTERNAL DIMRANM
FEXTERNAL MATDET
FEXTERNAL MATRDET
FEXTERNAL MATFNORM
FEXTERNAL MATRNORM
FEXTERNAL MATCNORM
FEXTERNAL MATRREF
FEXTERNAL MATREF
FEXTERNAL MATRANK
FEXTERNAL MATINV
FEXTERNAL MATREFRREF
FEXTERNAL INXREDext
FEXTERNAL METAMATRED
FEXTERNAL METAPIVOT
FEXTERNAL PIVOTNORM
FEXTERNAL PIVOTFLOAT
FEXTERNAL SYSText
FEXTERNAL STOSYSText
FEXTERNAL MAKESYSText
FEXTERNAL VARGENext
FEXTERNAL NULLVECTOR?
FEXTERNAL FINDELN
FEXTERNAL PULLEL[S]
FEXTERNAL BANGARRY
FEXTERNAL PUT[]
FEXTERNAL MATRIX>DIAG
FEXTERNAL MATRIXDIAG>
FEXTERNAL la+ELEMsym
FEXTERNAL INSERTROW[]
FEXTERNAL insertrow[]
FEXTERNAL INSERTCOL[]
FEXTERNAL INSERT[]ROW[]
FEXTERNAL INSERT[]COL[]
FEXTERNAL MATRIXRCI
FEXTERNAL MATRIXRCIJ
FEXTERNAL MATRIXCSWAP
FEXTERNAL MATRIXRSWAP
FEXTERNAL MATRIX-ROW
FEXTERNAL METAMAT-ROW
FEXTERNAL MATRIX-COL
FEXTERNAL METAMATCSWAP
FEXTERNAL METAMATRSWAP
FEXTERNAL STOMAText
FEXTERNAL MATIDN
FEXTERNAL OBJDIMS2MAT
FEXTERNAL LCPROG2M
FEXTERNAL MAKE2DMATRIX
FEXTERNAL make2dmatrix
FEXTERNAL ADDMATOBJext
FEXTERNAL VUNARYOP
FEXTERNAL VBINARYOP
FEXTERNAL PEVAL
FEXTERNAL MATEGVL
FEXTERNAL ROOTM2ROOT
FEXTERNAL MADJ
FEXTERNAL MATEGV
FEXTERNAL JORDAN
FEXTERNAL QXA
FEXTERNAL AXQ
FEXTERNAL GAUSS
FEXTERNAL SYLVESTER
FEXTERNAL metasplit
FEXTERNAL m-1&m+1
FEXTERNAL meta1/meta
FEXTERNAL 1&meta
FEXTERNAL meta/2
FEXTERNAL addt2
FEXTERNAL addt/
FEXTERNAL meta2*
FEXTERNAL meta1-sq
FEXTERNAL metasq+1
FEXTERNAL metasq-1
FEXTERNAL meta-1
FEXTERNAL NDROPZERO
FEXTERNAL 2DROPZ0
FEXTERNAL metaadd
FEXTERNAL metasub
FEXTERNAL metamult
FEXTERNAL metadiv
FEXTERNAL meta^
FEXTERNAL addt^
FEXTERNAL metapow
FEXTERNAL metafraction?
FEXTERNAL metaxroot
FEXTERNAL top&addt*
FEXTERNAL top&addt/
FEXTERNAL addti
FEXTERNAL metaEQUAL?
FEXTERNAL 2metaundef#
FEXTERNAL 1metaundef#
FEXTERNAL metaundef
FEXTERNAL 2metainf#
FEXTERNAL 1metainf#
FEXTERNAL metainftype
FEXTERNAL unsignedinf
FEXTERNAL plusinf
FEXTERNAL NDROPplusinf
FEXTERNAL minusinf
FEXTERNAL NDROPminusinf
FEXTERNAL MetaAdd
FEXTERNAL xssSYM+
FEXTERNAL MetaSub
FEXTERNAL xssSYM-
FEXTERNAL MetaMul
FEXTERNAL xssSYM*
FEXTERNAL MetaDiv
FEXTERNAL xssSYM/
FEXTERNAL NDROPZ0
FEXTERNAL NDROPZ1
FEXTERNAL MetaPow
FEXTERNAL xssSYM^
FEXTERNAL MetaNeg
FEXTERNAL xSYMCHS
FEXTERNAL metaneg
FEXTERNAL metackneg
FEXTERNAL metasimp
FEXTERNAL metapi?
FEXTERNAL metaCOMPARE
FEXTERNAL STRICTmetaCOMPARE
FEXTERNAL EQUALPOSMETA
FEXTERNAL EQUALPOS2META
FEXTERNAL vgerxssSYMSUM
FEXTERNAL DISTRIB/
FEXTERNAL metareal?
FEXTERNAL ModExpa
FEXTERNAL ModAdd
FEXTERNAL ModSub
FEXTERNAL ModMul
FEXTERNAL ModDiv
FEXTERNAL ModDiv2
FEXTERNAL ModInv
FEXTERNAL ModGcd
FEXTERNAL ModLGCD
FEXTERNAL ModLOPD
FEXTERNAL MODULOMODext
FEXTERNAL MODULOMAText
FEXTERNAL Mod
FEXTERNAL ModFctr
FEXTERNAL PARTFRAC
FEXTERNAL INPARTFRAC
FEXTERNAL PARTFRACRAT
FEXTERNAL PFext
FEXTERNAL IEGCDext
FEXTERNAL REGCDext
FEXTERNAL EGCDext
FEXTERNAL INEGCD
FEXTERNAL EGCDSWAP
FEXTERNAL EGCDNEWG
FEXTERNAL PDer
FEXTERNAL INTEGRext
FEXTERNAL LRDMext
FEXTERNAL RRDMext
FEXTERNAL DEGREext
FEXTERNAL FHORNER
FEXTERNAL HORNext
FEXTERNAL HORN1
FEXTERNAL MHORNext
FEXTERNAL PTAYLext
FEXTERNAL LAGRANGEext
FEXTERNAL PSEUDOPREP
FEXTERNAL PSEUDODIV
FEXTERNAL IDIV2
FEXTERNAL BESTDIV2
FEXTERNAL CDIV2ext
FEXTERNAL QUOText
FEXTERNAL NEWDIVext
FEXTERNAL QDivRem
FEXTERNAL DIV2LISText
FEXTERNAL DIVOBJext
FEXTERNAL DIVMETAOBJ
FEXTERNAL LOPDext
FEXTERNAL QUOTOBJext
FEXTERNAL DIVISIBLE?
FEXTERNAL QDiv?
FEXTERNAL FastDiv?
FEXTERNAL POTENCEext
FEXTERNAL PDIV2ext
FEXTERNAL PSetSign
FEXTERNAL PLCZ
FEXTERNAL HSECO2RCext
FEXTERNAL SECO2CMPext
FEXTERNAL SECO2CMPPOL
FEXTERNAL SECO2CMPCART
FEXTERNAL VALOBJext
FEXTERNAL R2SYM
FEXTERNAL VAL2ext
FEXTERNAL INVAL2
FEXTERNAL METAVAL2
FEXTERNAL VAL1
FEXTERNAL VAL1M
FEXTERNAL addt0meta
FEXTERNAL HALFTAN
FEXTERNAL COS2TAN/2
FEXTERNAL cos2tan/2
FEXTERNAL 1-x^2/1+x^2
FEXTERNAL SIN2TAN/2
FEXTERNAL sin2tan/2
FEXTERNAL 2x/1+x^2
FEXTERNAL TAN2TAN/2
FEXTERNAL tan2tan/2
FEXTERNAL addtTAN/2
FEXTERNAL TRIGTAN
FEXTERNAL COS2TAN
FEXTERNAL cos2tan
FEXTERNAL SIN2TAN
FEXTERNAL sin2tan
FEXTERNAL TRIGext
FEXTERNAL HYP2EXPext
FEXTERNAL EXPLNext
FEXTERNAL SERIESEXPLN
FEXTERNAL LNP12LN
FEXTERNAL LOG2LN
FEXTERNAL ALOG2EXP
FEXTERNAL EXPM2EXP
FEXTERNAL SQRT2LNEXP
FEXTERNAL sqrt2lnexp
FEXTERNAL TAN2EXP
FEXTERNAL tan2exp
FEXTERNAL ASIN2LN
FEXTERNAL asin2ln
FEXTERNAL ACOS2LN
FEXTERNAL acos2ln
FEXTERNAL TAN2SCext
FEXTERNAL TAN2SC
FEXTERNAL sin/cos
FEXTERNAL SIN2TCext
FEXTERNAL SIN2TC
FEXTERNAL cos*tan
FEXTERNAL COS2ext
FEXTERNAL sqrt1-sin^2
FEXTERNAL SIN2ext
FEXTERNAL sqrt1-cos^2
FEXTERNAL ATAN2Sext
FEXTERNAL ATAN2ASIN
FEXTERNAL atan2asin
FEXTERNAL ASIN2Text
FEXTERNAL ASIN2ATAN
FEXTERNAL asin2atan
FEXTERNAL ASIN2Cext
FEXTERNAL ASIN2ACOS
FEXTERNAL pi/2-acos
FEXTERNAL pi/2-meta
FEXTERNAL ACOS2Sext
FEXTERNAL pi/2-asin
FEXTERNAL ACOS2ASIN
FEXTERNAL ATAN2LNext
FEXTERNAL atan2ln
FEXTERNAL TAN2SC2ext
FEXTERNAL TAN2SC2
FEXTERNAL 2*1-cos/sin
FEXTERNAL TAN2CS2
FEXTERNAL 2*sin/1+cos
FEXTERNAL SIN2EXPext
FEXTERNAL sin2exp
FEXTERNAL COS2EXPext
FEXTERNAL cos2exp
FEXTERNAL SINH2EXPext
FEXTERNAL sinh2exp
FEXTERNAL COSH2EXPext
FEXTERNAL cosh2exp
FEXTERNAL TANH2EXPext
FEXTERNAL tanh2exp
FEXTERNAL ASINH2LNext
FEXTERNAL asinh2ln
FEXTERNAL ACOSH2LNext
FEXTERNAL acosh2ln
FEXTERNAL ATANH2LNext
FEXTERNAL atanh2ln
FEXTERNAL XROOT2ext
FEXTERNAL xroot2expln
FEXTERNAL LN2ext
FEXTERNAL SINCOSext
FEXTERNAL exp2sincos
FEXTERNAL metai*
FEXTERNAL LN2ATAN
FEXTERNAL VAR=LIST
FEXTERNAL IDNTEXEC
FEXTERNAL SYMISOL
FEXTERNAL SYMQFORM
FEXTERNAL LISTEXEC
FEXTERNAL LISTEXEC1
FEXTERNAL SECOEXEC
FEXTERNAL EQUATION?
FEXTERNAL USERFCN?
FEXTERNAL SYMBEXEC
FEXTERNAL MEVALext
FEXTERNAL CASNUMEVAL
FEXTERNAL CASCOMPEVAL
FEXTERNAL REPLACE2BY1
FEXTERNAL NR_REPLACE
FEXTERNAL SYMBWHERE
FEXTERNAL CASCRUNCH
FEXTERNAL APPROXCOMPEVAL
FEXTERNAL LIMIText
FEXTERNAL REWRITEIFINF
FEXTERNAL SYMTAYLOR
FEXTERNAL SYMPAPRX
FEXTERNAL TRUNCDL
FEXTERNAL LIMSERIES!
FEXTERNAL LIMITX!
FEXTERNAL LIMITNOVX!
FEXTERNAL LIMERR0!
FEXTERNAL LIMERR1!
FEXTERNAL LIMIT!
FEXTERNAL LIMSTEP1!
FEXTERNAL LIMSTEP2!
FEXTERNAL LIMSTEP3!
FEXTERNAL LIMSTEP4!
FEXTERNAL LIMLIM!
FEXTERNAL n{}N
FEXTERNAL LIMLIM1!
FEXTERNAL LIMCMPL!
FEXTERNAL LIMEQUFR!
FEXTERNAL LIMEQU!
FEXTERNAL LIMEQU0!
FEXTERNAL LIM+-!
FEXTERNAL LIMERR10!
FEXTERNAL LIMNEG!
FEXTERNAL LIMRAC!
FEXTERNAL LIMINV!
FEXTERNAL LIM/!
FEXTERNAL LIMPOW!
FEXTERNAL LIMSQ!
FEXTERNAL LIM*!
FEXTERNAL LIMDIVPC!
FEXTERNAL DIVPC!
FEXTERNAL LIMPROFEND!
FEXTERNAL LIMPROF!
FEXTERNAL LIM%#!
FEXTERNAL LIMPROF0!
FEXTERNAL LIMPROF1!
FEXTERNAL LIMPROF2!
FEXTERNAL LIMINVLN!
FEXTERNAL LIMLN!
FEXTERNAL LIMEXP!
FEXTERNAL LIMSINCOS!
FEXTERNAL LIMATAN!
FEXTERNAL LIMASIN!
FEXTERNAL LIMSQRT!
FEXTERNAL LIMFLOOR!
FEXTERNAL LIMABS!
FEXTERNAL LPROF!
FEXTERNAL LIM#VARX!
FEXTERNAL LIMBETA!
FEXTERNAL LIMALPHA!
FEXTERNAL HORNEXP!
FEXTERNAL HORNCOS!
FEXTERNAL HORNSIN!
FEXTERNAL LIMSC0!
FEXTERNAL LIMSC1!
FEXTERNAL HORNATAN!
FEXTERNAL LIMATAS!
FEXTERNAL HORNASIN!
FEXTERNAL HORNASIN1!
FEXTERNAL HORNLN!
FEXTERNAL LNOBJ!
FEXTERNAL NEWLIMHORN
FEXTERNAL LIMHORN!
FEXTERNAL LRDM!
FEXTERNAL LIMDL!
FEXTERNAL LIMDLINF!
FEXTERNAL LIMINFSIGN!
FEXTERNAL LIMMAX!
FEXTERNAL LIMCOMP!
FEXTERNAL VARCOMP2!
FEXTERNAL LIMSORT!
FEXTERNAL VARCOMP!
FEXTERNAL VARCOMPLN!
FEXTERNAL VARCOMP3!
FEXTERNAL VARCOMP31!
FEXTERNAL VARCOMP32!
FEXTERNAL VARCOMP33!
FEXTERNAL LIMERR6!
FEXTERNAL LIMVALOBJ!
FEXTERNAL LIMVAL!
FEXTERNAL EQUIV!
FEXTERNAL LVARXNX2!
FEXTERNAL SIMP1!
FEXTERNAL FindCurVar
FEXTERNAL LIMVAR!
FEXTERNAL VAR%
FEXTERNAL ISOL1
FEXTERNAL ISOLALL
FEXTERNAL ISOL2ext
FEXTERNAL BEZOUTMSOLV
FEXTERNAL ROOT{}N
FEXTERNAL MHORNER
FEXTERNAL MHORNER1
FEXTERNAL SQFFext
FEXTERNAL MSQFF
FEXTERNAL %1TWO
FEXTERNAL MZSQFF
FEXTERNAL MZSQFF1
FEXTERNAL MSECOSQFF
FEXTERNAL MLISTSQFF
FEXTERNAL METASQFFext
FEXTERNAL SECOSQFFext
FEXTERNAL CSQFFext
FEXTERNAL SUMSQRext
FEXTERNAL VXXLext
FEXTERNAL METALISTVXXL
FEXTERNAL VXXLFext
FEXTERNAL VXXL1ext
FEXTERNAL VXXL0
FEXTERNAL VXXL2NR
FEXTERNAL VXXL2
FEXTERNAL LIDNText
FEXTERNAL LVARXNXext
FEXTERNAL ISPOLYNOMIAL?
FEXTERNAL 2POLYNOMIAL?
FEXTERNAL VXINDEP?
FEXTERNAL LVARXNX2ext
FEXTERNAL RLVARext
FEXTERNAL LLVARDext
FEXTERNAL VXLVARext
FEXTERNAL LVARext
FEXTERNAL VX>LVARext
FEXTERNAL VX>
FEXTERNAL VX!
FEXTERNAL prepvarlist
FEXTERNAL LIDNTLVAR
FEXTERNAL LISTOPRAC
FEXTERNAL LISTOPext
FEXTERNAL LISTOPSQRT
FEXTERNAL LVARDext
FEXTERNAL >VARLIST
FEXTERNAL DEPTHext
FEXTERNAL DEPTHOBJext
FEXTERNAL TRIMext
FEXTERNAL PTrim
FEXTERNAL TRIMOBJext
FEXTERNAL NEWTRIMext
FEXTERNAL >POLYTRIM
FEXTERNAL ELMGext
FEXTERNAL SWAPRNEG
FEXTERNAL QNeg
FEXTERNAL RNEGext
FEXTERNAL SWAPRRE
FEXTERNAL RREext
FEXTERNAL SWAPRIM
FEXTERNAL RIMext
FEXTERNAL xREext
FEXTERNAL xSYMRE
FEXTERNAL xIMext
FEXTERNAL xSYMIM
FEXTERNAL RCONJext
FEXTERNAL addtCONJ
FEXTERNAL xSYMCONJ
FEXTERNAL QCONJext
FEXTERNAL QABSext
FEXTERNAL RABSext
FEXTERNAL ZABS
FEXTERNAL CZABS
FEXTERNAL xABSext
FEXTERNAL addtABS
FEXTERNAL xSYMABS
FEXTERNAL addtABSEXACT
FEXTERNAL addtSIGN
FEXTERNAL xSYMSIGN
FEXTERNAL addtARG
FEXTERNAL xSYMARG
FEXTERNAL ARG2
FEXTERNAL INTERNALARG2
FEXTERNAL QUADRANT
FEXTERNAL CNORMext
FEXTERNAL CXIRext
FEXTERNAL QNORMext
FEXTERNAL SXSQRext
FEXTERNAL XSQRext
FEXTERNAL CK%%SQRT
FEXTERNAL C%%SQRT
FEXTERNAL ZINTSQRT
FEXTERNAL SHALT
FEXTERNAL CKLN
FEXTERNAL xLNext
FEXTERNAL addtLN
FEXTERNAL xSYMLN
FEXTERNAL EXPANDLN
FEXTERNAL CMPLXLN
FEXTERNAL LNATANext
FEXTERNAL REALLN
FEXTERNAL xEXPext
FEXTERNAL xINVext
FEXTERNAL xvext
FEXTERNAL xCOSext
FEXTERNAL xSINext
FEXTERNAL xTANext
FEXTERNAL xCOSHext
FEXTERNAL xSINHext
FEXTERNAL xTANHext
FEXTERNAL xASINext
FEXTERNAL xACOSext
FEXTERNAL xATANext
FEXTERNAL addtCOS
FEXTERNAL xSYMCOS
FEXTERNAL addtSIN
FEXTERNAL xSYMSIN
FEXTERNAL addtTAN
FEXTERNAL xSYMTAN
FEXTERNAL addtSINACOS
FEXTERNAL addtASIN
FEXTERNAL xSYMASIN
FEXTERNAL addtACOS
FEXTERNAL xSYMACOS
FEXTERNAL addtATAN
FEXTERNAL xSYMATAN
FEXTERNAL addtSINH
FEXTERNAL xSYMSINH
FEXTERNAL addtCOSH
FEXTERNAL xSYMCOSH
FEXTERNAL addtTANH
FEXTERNAL xSYMTANH
FEXTERNAL xATANHext
FEXTERNAL addtATANH
FEXTERNAL xSYMATANH
FEXTERNAL xASINHext
FEXTERNAL addtASINH
FEXTERNAL xSYMASINH
FEXTERNAL xACOSHext
FEXTERNAL addtACOSH
FEXTERNAL xSYMACOSH
FEXTERNAL addtSQRT
FEXTERNAL xSYMSQRT
FEXTERNAL xSQext
FEXTERNAL addtSQ
FEXTERNAL xSYMSQ
FEXTERNAL addtINV
FEXTERNAL xSYMINV
FEXTERNAL addtEXP
FEXTERNAL xSYMEXP
FEXTERNAL addtD->R
FEXTERNAL xSYMD>R
FEXTERNAL addtR->D
FEXTERNAL xSYMR>D
FEXTERNAL addtFLOOR
FEXTERNAL xSYMFLOOR
FEXTERNAL addtCEIL
FEXTERNAL xSYMCEIL
FEXTERNAL addtIP
FEXTERNAL xSYMIP
FEXTERNAL addtFP
FEXTERNAL xSYMFP
FEXTERNAL addtXPON
FEXTERNAL xSYMXPON
FEXTERNAL addtMANT
FEXTERNAL xSYMMANT
FEXTERNAL addtLNP1
FEXTERNAL xSYMLNP1
FEXTERNAL addtLOG
FEXTERNAL xSYMLOG
FEXTERNAL addtALOG
FEXTERNAL xSYMALOG
FEXTERNAL addtEXPM
FEXTERNAL xSYMEXPM1
FEXTERNAL factorial
FEXTERNAL facts
FEXTERNAL addtFACT
FEXTERNAL xSYMFACT
FEXTERNAL factzint
FEXTERNAL addtNOT
FEXTERNAL xSYMNOT
FEXTERNAL Verbose1
FEXTERNAL Verbose2
FEXTERNAL Verbose3
FEXTERNAL VerboseN
FEXTERNAL GETERABLEMSG
FEXTERNAL ERABLEERROR
FEXTERNAL CANTFACTOR
FEXTERNAL TRANSCERROR
FEXTERNAL NONUNARYERR
FEXTERNAL INTERNALERR
FEXTERNAL INVALIDOP
FEXTERNAL ISOLERR
FEXTERNAL NONINTERR
FEXTERNAL INTVARERR
FEXTERNAL Z>#ERR
FEXTERNAL Z<0ERR
FEXTERNAL VXINDEPERR
FEXTERNAL NONPOLYSYST
FEXTERNAL COMPLEXERR
FEXTERNAL VALMUSTBE0
FEXTERNAL SWITCHNOTALLOWED
FEXTERNAL ERR$EVALext
FEXTERNAL Sys1IT
FEXTERNAL QSq
FEXTERNAL spdStepZint
FEXTERNAL REPLACEZBYR
FEXTERNAL xADDTOREAL
FEXTERNAL xSIGMAVX
FEXTERNAL xSIGMA
FEXTERNAL xPsi
FEXTERNAL xPSI
FEXTERNAL xRESULTANT
FEXTERNAL xIBERNOULLI
FEXTERNAL xGAMMA
FEXTERNAL xqr
FEXTERNAL xGRAMSCHMIDT
FEXTERNAL xSYST2MAT
FEXTERNAL xCHOLESKY
FEXTERNAL xDIAGMAP
FEXTERNAL xISOM
FEXTERNAL xMKISOM
FEXTERNAL xKER
FEXTERNAL xIMAGE
FEXTERNAL xBASIS
FEXTERNAL xIBASIS
FEXTERNAL xAUGMENT
FEXTERNAL xPMINI
FEXTERNAL xCYCLOTOMIC
FEXTERNAL xSTURM
FEXTERNAL xSTURMAB
FEXTERNAL xFDISTRIB
FEXTERNAL xDISTRIB
FEXTERNAL xEXP2POW
FEXTERNAL xPOWEXPAND
FEXTERNAL xTAN2CS2
FEXTERNAL xCIRC
FEXTERNAL xC2P
FEXTERNAL xP2C
FEXTERNAL xMSLV
FEXTERNAL xDOMAIN
FEXTERNAL xSIMPLIFY
FEXTERNAL xDROITE
FEXTERNAL xSTORE
FEXTERNAL xDEF
FEXTERNAL xASSUME
FEXTERNAL xUNASSUME
FEXTERNAL xREWRITE
FEXTERNAL xINTEGER
FEXTERNAL xCONSTANTS
FEXTERNAL xHYPERBOLIC
FEXTERNAL xMODULAR
FEXTERNAL xPOLYNOMIAL
FEXTERNAL xTESTS
FEXTERNAL xMATHS
FEXTERNAL xCOLLECT
FEXTERNAL xUNASSIGN
FEXTERNAL xCM
FEXTERNAL xCHRNUM
FEXTERNAL xDEDICACE
FEXTERNAL CASRESERVED53
FEXTERNAL CASRESERVED54
FEXTERNAL CASRESERVED55
FEXTERNAL CASRESERVED56
FEXTERNAL CASRESERVED57
FEXTERNAL CASRESERVED58
FEXTERNAL CASRESERVED59
FEXTERNAL CASRESERVED60
FEXTERNAL CASRESERVED61
FEXTERNAL CASRESERVED62
FEXTERNAL CASRESERVED63
FEXTERNAL CASRESERVED64
FEXTERNAL CASRESERVED65
FEXTERNAL CASRESERVED66
FEXTERNAL CASRESERVED67
FEXTERNAL CASRESERVED68
FEXTERNAL CASRESERVED69
FEXTERNAL CASRESERVED70
FEXTERNAL CASRESERVED71
FEXTERNAL CASRESERVED72
FEXTERNAL CASRESERVED73
FEXTERNAL CASRESERVED74
FEXTERNAL CASRESERVED75
FEXTERNAL CASRESERVED76
FEXTERNAL CASRESERVED77
FEXTERNAL CASRESERVED78
FEXTERNAL CASRESERVED79
FEXTERNAL CASRESERVED80
FEXTERNAL CASRESERVED81
FEXTERNAL CASRESERVED82
FEXTERNAL CASRESERVED83
FEXTERNAL CASRESERVED84
FEXTERNAL CASRESERVED85
FEXTERNAL CASRESERVED86
FEXTERNAL CASRESERVED87
FEXTERNAL CASRESERVED88
FEXTERNAL CASRESERVED89
FEXTERNAL CASRESERVED90
FEXTERNAL CASRESERVED91
FEXTERNAL CASRESERVED92
FEXTERNAL CASRESERVED93
FEXTERNAL CASRESERVED94
FEXTERNAL CASRESERVED95
FEXTERNAL CASRESERVED96
FEXTERNAL CASRESERVED97
FEXTERNAL CASRESERVED98
FEXTERNAL CASRESERVED99
FEXTERNAL QpiZ
FEXTERNAL QPI
FEXTERNAL QpiSym
FEXTERNAL QpiArry
FEXTERNAL QpiList
FEXTERNAL Qpi
FEXTERNAL Qpi%
FEXTERNAL GetRoot
FEXTERNAL Approx
FEXTERNAL #FACT
FEXTERNAL CHECKSING
FEXTERNAL DESOLVE
FEXTERNAL ODE_INT
FEXTERNAL LINSOLV
FEXTERNAL LDECSOLV
FEXTERNAL LDEGENE
FEXTERNAL LDEPART
FEXTERNAL LDSSOLVext
FEXTERNAL ODETYPESTO
FEXTERNAL ODE_SEPAR
FEXTERNAL LAPext
FEXTERNAL ILAPext
FEXTERNAL ILAPRAText
FEXTERNAL ILAPDELTA
FEXTERNAL ILAPEXP
FEXTERNAL ILAPEXPSC
FEXTERNAL MENUext
FEXTERNAL WRITEMENU
FEXTERNAL CFGDISPLAY
FEXTERNAL NEWVX
FEXTERNAL NEWMODULO
FEXTERNAL SWITCHON
FEXTERNAL SWITCHOFF
FEXTERNAL FLAGNAME
FEXTERNAL COMPLEXON
FEXTERNAL COMPLEXOFF
FEXTERNAL EXACTON
FEXTERNAL EXACTOFF
FEXTERNAL COMPLEXMODE
FEXTERNAL SETCOMPLEX
FEXTERNAL COMPLEX?
FEXTERNAL REALMODE
FEXTERNAL CLRCOMPLEX
FEXTERNAL EXACTMODE
FEXTERNAL SETEXACT
FEXTERNAL NUMMODE
FEXTERNAL CLREXACT
FEXTERNAL EXACT?
FEXTERNAL STEPBYSTEP
FEXTERNAL NOSTEPBYSTEP
FEXTERNAL VERBOSEMODE
FEXTERNAL SILENTMODE
FEXTERNAL RECURMODE
FEXTERNAL NONRECMODE
FEXTERNAL PLUSAT0
FEXTERNAL SETPLUSAT0
FEXTERNAL PLUSATINFTY
FEXTERNAL CLRPLUSAT0
FEXTERNAL SPARSEDATA
FEXTERNAL FULLDATA
FEXTERNAL RIGORMODE
FEXTERNAL SLOPPYMODE
FEXTERNAL SLOPPY?
FEXTERNAL MENUCHOOSE?
FEXTERNAL MENUCHOOSE
FEXTERNAL MENUGENE1
FEXTERNAL MENUBASE1
FEXTERNAL MENUCMPLX1
FEXTERNAL MENUTRIG1
FEXTERNAL MENUMAT1
FEXTERNAL MENUARIT1
FEXTERNAL MENUSOLVE1
FEXTERNAL MENUEXPLN1
FEXTERNAL MENUDIFF1
FEXTERNAL PROMPTSTO1
FEXTERNAL XGROBext
FEXTERNAL GROBADDext
FEXTERNAL DISPLAYext
FEXTERNAL SCROLLext
FEXTERNAL RCLMODULO
FEXTERNAL RCLPERIOD
FEXTERNAL RCLVX
FEXTERNAL STOVX
FEXTERNAL STOMODULO
FEXTERNAL RCLEPS
FEXTERNAL ISIDREAL?
FEXTERNAL ADDTOREAL
FEXTERNAL RESETCASCFG
FEXTERNAL FRACPARITY
FEXTERNAL POLYPARITY
FEXTERNAL PARITYTEST
FEXTERNAL COSTEST
FEXTERNAL SHRINKEVEN
FEXTERNAL SINTEST
FEXTERNAL SHRINK2SYM
FEXTERNAL SHRINKSYM
FEXTERNAL SHRINK2ASYM
FEXTERNAL SHRINKASYM
FEXTERNAL FR2ND%
FEXTERNAL POLYSYM
FEXTERNAL POLYASYM
FEXTERNAL P2P#
FEXTERNAL NDEvalN/D
FEXTERNAL PEvalN/D
FEXTERNAL POSITIFext
FEXTERNAL SIGNE1ext
FEXTERNAL SIGNEext
FEXTERNAL SIGNUNDEF
FEXTERNAL SIGNPLUS
FEXTERNAL SIGNMOINS
FEXTERNAL SIGNELN
FEXTERNAL SIGNEEXP
FEXTERNAL SIGNESIN
FEXTERNAL SIGNECOS
FEXTERNAL SIGNETAN
FEXTERNAL SIGNEATAN
FEXTERNAL SIGNESQRT
FEXTERNAL SUBSIGNE
FEXTERNAL SIGNERIGHT
FEXTERNAL SIGNELEFT
FEXTERNAL >SIGNE
FEXTERNAL SIGNE>
FEXTERNAL SIGNMULText
FEXTERNAL ZSIGNECK
FEXTERNAL SIGNEERROR
FEXTERNAL ZSIGNE
FEXTERNAL zsigne
FEXTERNAL PASCAL_NEXTLINE
FEXTERNAL DELTAPSOLVE
FEXTERNAL SOLVEMETASYST
FEXTERNAL REDUCEMETASYST
FEXTERNAL REDUCEMETAPSYST
FEXTERNAL SOLVECRAMER
FEXTERNAL QUOTExSIGMA
FEXTERNAL SUM
FEXTERNAL FLAGSUM
FEXTERNAL SUMVX
FEXTERNAL FLAGSUMVX
FEXTERNAL RATSUM
FEXTERNAL FTAYL
FEXTERNAL CSTFRACTION?
FEXTERNAL NONRATSUM
FEXTERNAL LINEARAPPLY
FEXTERNAL linearapply
FEXTERNAL meta_cst?
FEXTERNAL HYPERGEO
FEXTERNAL fk+1/fk
FEXTERNAL A/B2PQR
FEXTERNAL GOSPER?
FEXTERNAL ZEILBERGER
FEXTERNAL SYMPSI
FEXTERNAL sympsi
FEXTERNAL SYMPSIN
FEXTERNAL sympsin
FEXTERNAL IBERNOULLI
FEXTERNAL FLAGRESULTANT
FEXTERNAL RESULTANT
FEXTERNAL RESULTANTLP
FEXTERNAL RESPSHIFTQ
FEXTERNAL ADDONEVAR
FEXTERNAL IROOTS
FEXTERNAL TYPEGAUSSINT?
FEXTERNAL DTYPEGAUSSINT?
FEXTERNAL DUPTYPEGAUSSINT?
FEXTERNAL PPZZ
FEXTERNAL DISTRIB*
FEXTERNAL NONALGERR
FEXTERNAL ALGCASCOMPEVAL
FEXTERNAL fnConstantsEvalNoCK
FEXTERNAL SymPsi
FEXTERNAL %PSI
FEXTERNAL %%PSI
FEXTERNAL C%PSI
FEXTERNAL C%%PSI
FEXTERNAL %PSIN
FEXTERNAL %%PSIN
FEXTERNAL C%PSIN
FEXTERNAL C%%PSIN
FEXTERNAL SYMGAMMA
FEXTERNAL SymGamma
FEXTERNAL %GAMMA
FEXTERNAL %%GAMMA
FEXTERNAL C%GAMMA
FEXTERNAL C%%GAMMA
FEXTERNAL C%%GAMMAsmall
FEXTERNAL C%%STIRF
FEXTERNAL EXACTMATIDN
FEXTERNAL FLAGLU
FEXTERNAL FLAGQR
FEXTERNAL QR
FEXTERNAL CKGRAMSCHMIDT
FEXTERNAL USERGRAMSCHMIDT
FEXTERNAL GRAMSCHMIDT
FEXTERNAL MATOP
FEXTERNAL CKISOMETRIE
FEXTERNAL ISOMETRIE
FEXTERNAL SIGMAxi^2
FEXTERNAL CKORTHOGONAL
FEXTERNAL MKISOMETRIE
FEXTERNAL VECTtVECT
FEXTERNAL IMAT*
FEXTERNAL IMAT/
FEXTERNAL MATDEPTH
FEXTERNAL IMMMULT
FEXTERNAL IMVMULT
FEXTERNAL KER
FEXTERNAL IMAGE
FEXTERNAL BASIS
FEXTERNAL CKCOHERENTLIST
FEXTERNAL IBASIS
FEXTERNAL AUGMENT
FEXTERNAL THROWNULLLINES
FEXTERNAL SYST2MAT
FEXTERNAL CHOLESKY
FEXTERNAL CHOLESKYNOCK
FEXTERNAL PMINI
FEXTERNAL DROITE
FEXTERNAL rischstepout
FEXTERNAL addtSIGNonly
FEXTERNAL obj2-meta1
FEXTERNAL risch0!
FEXTERNAL generate_atan
FEXTERNAL gen_ln_only
FEXTERNAL RISCH1LOG
FEXTERNAL RISCHLOG
FEXTERNAL RISCHATAN
FEXTERNAL Exp<Ln
FEXTERNAL addtATANH*2
FEXTERNAL 'ID210
FEXTERNAL TRIGTAN^
FEXTERNAL pldrpSYMBNSWP1+
FEXTERNAL SQRT1+TAN^2
FEXTERNAL COS*1+TAN^2
FEXTERNAL TRIGPOW
FEXTERNAL TWICEONE>POLY
FEXTERNAL EXTRACTCOMMONDENO
FEXTERNAL REWRITEFORSOLVE
FEXTERNAL REWRITE1FORSOLVE
FEXTERNAL CYCLOTOMIC
FEXTERNAL metaproduct
FEXTERNAL POLYATX^#
FEXTERNAL POWEXPAND
FEXTERNAL powexpand
FEXTERNAL DISTRIB
FEXTERNAL EXP2POW
FEXTERNAL exp2pow
FEXTERNAL exp2pow*
FEXTERNAL exp2pow/
FEXTERNAL exp2pow*LN
FEXTERNAL exp2pow/LN
FEXTERNAL x^only
FEXTERNAL FDISTRIB
FEXTERNAL FULLDISTRIB
FEXTERNAL DISTRIB*&/
FEXTERNAL DISTRIB-
FEXTERNAL DISTRIBNEG
FEXTERNAL DISTRIB+NEG
FEXTERNAL DISTRIB-NEG
FEXTERNAL DISTRIB*&/UNARY
FEXTERNAL MYCKSYMBN
FEXTERNAL FLAGTAN2CS2
FEXTERNAL TAN2CS2NOCK
FEXTERNAL TAN2CS2ext
FEXTERNAL CKPERMext
FEXTERNAL CIRCext
FEXTERNAL P2Cext
FEXTERNAL C2Pext
FEXTERNAL PFSTEP1ext
FEXTERNAL PFSTEP2ext
FEXTERNAL PFSTEP3ext
FEXTERNAL GCDSTEP
FEXTERNAL IEGCDSTEP
FEXTERNAL DOMAIN
FEXTERNAL MSLV
FEXTERNAL FLAGSIMPLIFY
FEXTERNAL CKSIMPLIFY
FEXTERNAL INSIMPLIFY
FEXTERNAL REMOVEFROMASSUME
FEXTERNAL REWRITEMENU
FEXTERNAL MATHSMENU
FEXTERNAL INTEGERMENU
FEXTERNAL CONSTANTSMENU
FEXTERNAL HYPERBOLICMENU
FEXTERNAL MODULARMENU
FEXTERNAL POLYNOMIALMENU
FEXTERNAL TESTSMENU
FEXTERNAL CHOOSE>$
FEXTERNAL cassyminner
FEXTERNAL 2cassyminner
FEXTERNAL CASSYM+
FEXTERNAL CASSYM-
FEXTERNAL CASSYM*
FEXTERNAL CASSYM/
FEXTERNAL CHANGECASCFG
FEXTERNAL VARSCREEN
FEXTERNAL ISMETACOMPLEX?
FEXTERNAL FLAGSTURM
FEXTERNAL STURM
FEXTERNAL sturm
FEXTERNAL MAPSTURM
FEXTERNAL SIGNCHANGE#
FEXTERNAL STURMAB
FEXTERNAL ZERO#INAB
FEXTERNAL STURMLSIGN
FEXTERNAL STURMREDUCE
FEXTERNAL STURMSSIGN
FEXTERNAL SPLITHYPOTHESIS
FEXTERNAL VARINTERVAL
FEXTERNAL IDLAMINTERVAL
FEXTERNAL SIGNTABTOSYMB
FEXTERNAL HELPSYMB
FEXTERNAL HELPSTR
FEXTERNAL CMDLIST
FEXTERNAL CASHELPMAIN
FEXTERNAL TESTEUROPE
FEXTERNAL CASHELP
FEXTERNAL CASHELPLIST
FEXTERNAL CASHELPSTR
