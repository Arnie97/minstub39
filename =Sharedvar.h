***     Simplified Defintion for shared fixed length variables 1.1

ASSEMBLE
	Cfield	L1,L2,Xmin
RPL
	DftXmin

ASSEMBLE
	Cfield 	L2,L3,Xmax
RPL
	DftXmax

ASSEMBLE
	Cfield  L3,L4,Ymin
RPL
	DftYmin

ASSEMBLE
	Cfield  L4,L5,Ymax
RPL
	DftYmax

ASSEMBLE
	Cfield  L5,L6,Xmin2
RPL
	% -6.5

ASSEMBLE
	Cfield  L6,L7,Xmax2
RPL
	% 6.5

ASSEMBLE
	Cfield  L7,L8,Ymin2
RPL
	% -3.1

ASSEMBLE
	Cfield  L8,L9,Ymax2
RPL
	% 3.2

ASSEMBLE
	Cfield  L9,L10,HTick
RPL
	DftHTick

ASSEMBLE
	Cfield  L10,L11,VTick
RPL
	DftVTick

ASSEMBLE
	Cfield	L11,L12,HZoom
RPL
	DftHZoom

ASSEMBLE
	Cfield	L12,L13,VZoom
RPL
	DftVZoom

ASSEMBLE
	Cfield	L13,L14,Angle
RPL
	DftAngle

ASSEMBLE
	Cfield	L14,L15,LastX
RPL
	% 0

ASSEMBLE
	Cfield	L15,L16,LastY
RPL
	% 0

ASSEMBLE
	Cfield  L16,L17,LastIndep
RPL
	% 0

ASSEMBLE
	Cfield  L17,L18,LastEq
RPL
	# 00001

ASSEMBLE
	Cfield  L18,L19,PlotFlag
RPL
	# 00186

** AutoScale	EQU	# 00001	( 0=No, 1=AutoScale before Draw, Dflt=0)
** AxesDesired  EQU     # 00002 ( 0=No Axes, 1=Draw Axes, Dflt=1 )
** Connected    EQU     # 00004 ( 0=Not, 1=Connected, Dflt=1 )
** Erase	EQU	# 00008	( 0=Don't, 1=Erase before Draw, Dflt=0 )
** GridDesired  EQU     # 00010 ( 0=No Grid, 1=Draw Grid, Dflt=0 )
** HighRes      EQU     # 00020 ( 0=Low Res, 1=High Res,  Dflt=0 )
** Label	EQU	# 00040 ( 0=No Label, 1=Label, Dflt=0 )
** Recenter	EQU	# 00080 ( 0=Don't, 1=Recenter when Zoom, Dflt=1)
** Simult       EQU     # 00100 ( 0=Not, 1=Simultaneously, Dflt=1 )
** SolidCursor	EQU	# 00200	( 0=No, 1=Inverse Crosshairs, Dflt=0 )

ASSEMBLE
	Cfield  L19,L20,Plot2Flg
RPL
	# 1

** Redraw	EQU	# 00001 ( 0=No, 1=redraw, Dflt=1 )

ASSEMBLE
	Cfield  L20,L21,PlotCKSUM
RPL
	% 0

ASSEMBLE
	Cfield  L21,L22,SplitCKSUM
RPL
	% 0

ASSEMBLE
	Cfield  L22,L23,Split2CKSUM
RPL
	% 0

ASSEMBLE
	Cfield  L23,L24,TStart
RPL
	DftTStart

ASSEMBLE
	Cfield  L24,L25,TStep
RPL
	DftTStep

ASSEMBLE
	Cfield  L25,L26,TZoom
RPL
	DftTZoom

** Bit 0: Font
** Bit 1: Building table
ASSEMBLE
	Cfield  L26,L27,TFlags
RPL
	DftTFlags

ASSEMBLE
	Cfield  L27,L28,Trow
RPL
	0

ASSEMBLE
	Cfield  L28,L29,Tcol
RPL
	1

ASSEMBLE
	Cfield  L29,L30,TCol1
RPL
	1

ASSEMBLE
	Cfield  L30,L31,SplitRow
RPL
	3

ASSEMBLE
	Cfield  L31,L32,BTRow1
RPL
	0

ASSEMBLE
        Cfield  L32,L33,Format
RPL
        DftFormat

ASSEMBLE
        Cfield  L33,L34,Digits
RPL
        DftDigits

