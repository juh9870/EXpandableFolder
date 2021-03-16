[Variables]

; INDEX_0=1
TILE_0_X_O=77
TILE_0_Y_O=3
TILE_0_X=(1+(#TILE_0_X_O#-1)*[MeasureTimerCalc:])
TILE_0_Y=(3+(#TILE_0_Y_O#-3)*[MeasureTimerCalc:])
TILE_0_SELECTION=0
; INDEX_1=2
TILE_1_X_O=153
TILE_1_Y_O=3
TILE_1_X=(1+(#TILE_1_X_O#-1)*[MeasureTimerCalc:])
TILE_1_Y=(3+(#TILE_1_Y_O#-3)*[MeasureTimerCalc:])
TILE_1_SELECTION=0
; INDEX_2=3
TILE_2_X_O=1
TILE_2_Y_O=102
TILE_2_X=(1+(#TILE_2_X_O#-1)*[MeasureTimerCalc:])
TILE_2_Y=(3+(#TILE_2_Y_O#-3)*[MeasureTimerCalc:])
TILE_2_SELECTION=0
; INDEX_3=4
TILE_3_X_O=77
TILE_3_Y_O=102
TILE_3_X=(1+(#TILE_3_X_O#-1)*[MeasureTimerCalc:])
TILE_3_Y=(3+(#TILE_3_Y_O#-3)*[MeasureTimerCalc:])
TILE_3_SELECTION=0
TILE_F_SELECTION=0
Update_Tiles=[!UpdateMeter "MeterTile0"][!UpdateMeter "MeterTileIcon0"][!UpdateMeter "MeterTileText0"][!UpdateMeter "MeterTileSelection0"][!UpdateMeter "MeterTileHitbox0"][!UpdateMeter "MeterTile1"][!UpdateMeter "MeterTileIcon1"][!UpdateMeter "MeterTileText1"][!UpdateMeter "MeterTileSelection1"][!UpdateMeter "MeterTileHitbox1"][!UpdateMeter "MeterTile2"][!UpdateMeter "MeterTileIcon2"][!UpdateMeter "MeterTileText2"][!UpdateMeter "MeterTileSelection2"][!UpdateMeter "MeterTileHitbox2"][!UpdateMeter "MeterTile3"][!UpdateMeter "MeterTileIcon3"][!UpdateMeter "MeterTileText3"][!UpdateMeter "MeterTileSelection3"][!UpdateMeter "MeterTileHitbox3"]
Update=[!UpdateMeasure "MeasureSlide"][!UpdateMeasure "MeasureTimerCalc"][!UpdateMeter "MeterHitbox"]#Update_Tiles#[!Redraw]
FullyOppened=[!UpdateMeter "MeterTileHitbox0"][!UpdateMeter "MeterTileHitbox1"][!UpdateMeter "MeterTileHitbox2"][!UpdateMeter "MeterTileHitbox3"][!Redraw]
ClosingStart=[!UpdateMeter "MeterTileHitbox0"][!UpdateMeter "MeterTileHitbox1"][!UpdateMeter "MeterTileHitbox2"][!UpdateMeter "MeterTileHitbox3"][!Redraw]

TILE_F_X_O=1
TILE_F_Y_O=3

[MeasureFileIcon0]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=1
Type=Icon
IconSize=Large
OnChangeAction=[!SetOption MeterTileIcon0 ImageName [MeasureFileIcon0]]

[MeasureFileName0]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=1
Type=FileName
OnChangeAction=[!SetOption MeterTileText0 Text [MeasureFileName0]]

[MeasureFilePath0]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=1
Type=FilePath

[MeterTile0]
Meter=Shape
Shape=Rectangle #TILE_0_X#,#TILE_0_Y#,75,98 | Fill Color 0,0,0,(255*[MeasureTimerCalc:]) | Stroke Color 0, 0, 0, (255*[MeasureTimerCalc:])
DynamicVariables=1

[MeterTileHitbox0]
Meter=Shape
Shape=Rectangle #TILE_0_X_O#,#TILE_0_Y_O#,75,98 | Fill Color 0,0,0,1 | Stroke Color 0, 0, 0, 1
Hidden=(Clamp(Floor(1-[MeasureTimerCalc:]*2),0,1))
DynamicVariables=1


[MeterTileSelection0]
Meter=Shape
Shape=Rectangle (#TILE_0_X#+(#Tile_Width#-#Tiles_Selection_Width#)/2),#TILE_0_Y#,(#Tiles_Selection_Width#),(#Tiles_Text_OY#+[MeterTileText0:H]) | Fill Color #Hover_Selection_Color#,(#Hover_Selection_Opacity#*#TILE_0_SELECTION#*[MeasureTimerCalc:]) | Stroke Color #Hover_Selection_Color#, (#Hover_Selection_Border_Opacity#*#TILE_0_SELECTION#*[MeasureTimerCalc:])
DynamicVariables=1
Hidden=(Floor(1-[MeasureTimerCalc:]))
Group=SelectionGroup
LeftMouseUpAction=["[MeasureFilePath0]"]
MouseOverAction=[!SetVariable TILE_0_SELECTION 1][!UpdateMeter "MeterTileSelection0"][!Redraw]
MouseLeaveAction=[!SetVariable TILE_0_SELECTION 0][!UpdateMeter "MeterTileSelection0"][!Redraw]


[MeterTileIcon0]
Meter=Image
ImageName=[MeasureFileIcon0]
X=(#TILE_0_X#+#Tiles_Icon_OX#)
Y=(#TILE_0_Y#+#Tiles_Icon_OY#)
W=#Tiles_Icon_Size#
H=#Tiles_Icon_Size#
Container=MeterTile0
DynamicVariables=1

[MeterTileText0]
Meter=String
Text=[MeasureFileName0]
X=(#TILE_0_X#+#Tiles_Text_OX#)
Y=(#TILE_0_Y#+#Tiles_Text_OY#)
ClipStringW=#Tiles_Text_Width#
ClipStringH=#Tiles_Text_Height#
FontColor=255,255,255,255
StringAlign=CenterTop
ClipString=2
FontSize=9.5
AntiAlias=0
; FontFace=Segoe UI
StringEffect=Shadow
FontEffectColor=0,0,0,255
Container=MeterTile0
DynamicVariables=1

TILE_F_X_O=1
TILE_F_Y_O=3

[MeasureFileIcon1]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=2
Type=Icon
IconSize=Large
OnChangeAction=[!SetOption MeterTileIcon1 ImageName [MeasureFileIcon1]]

[MeasureFileName1]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=2
Type=FileName
OnChangeAction=[!SetOption MeterTileText1 Text [MeasureFileName1]]

[MeasureFilePath1]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=2
Type=FilePath

[MeterTile1]
Meter=Shape
Shape=Rectangle #TILE_1_X#,#TILE_1_Y#,75,98 | Fill Color 0,0,0,(255*[MeasureTimerCalc:]) | Stroke Color 0, 0, 0, (255*[MeasureTimerCalc:])
DynamicVariables=1

[MeterTileHitbox1]
Meter=Shape
Shape=Rectangle #TILE_1_X_O#,#TILE_1_Y_O#,75,98 | Fill Color 0,0,0,1 | Stroke Color 0, 0, 0, 1
Hidden=(Clamp(Floor(1-[MeasureTimerCalc:]*2),0,1))
DynamicVariables=1


[MeterTileSelection1]
Meter=Shape
Shape=Rectangle (#TILE_1_X#+(#Tile_Width#-#Tiles_Selection_Width#)/2),#TILE_1_Y#,(#Tiles_Selection_Width#),(#Tiles_Text_OY#+[MeterTileText1:H]) | Fill Color #Hover_Selection_Color#,(#Hover_Selection_Opacity#*#TILE_1_SELECTION#*[MeasureTimerCalc:]) | Stroke Color #Hover_Selection_Color#, (#Hover_Selection_Border_Opacity#*#TILE_1_SELECTION#*[MeasureTimerCalc:])
DynamicVariables=1
Hidden=(Floor(1-[MeasureTimerCalc:]))
Group=SelectionGroup
LeftMouseUpAction=["[MeasureFilePath1]"]
MouseOverAction=[!SetVariable TILE_1_SELECTION 1][!UpdateMeter "MeterTileSelection1"][!Redraw]
MouseLeaveAction=[!SetVariable TILE_1_SELECTION 0][!UpdateMeter "MeterTileSelection1"][!Redraw]


[MeterTileIcon1]
Meter=Image
ImageName=[MeasureFileIcon1]
X=(#TILE_1_X#+#Tiles_Icon_OX#)
Y=(#TILE_1_Y#+#Tiles_Icon_OY#)
W=#Tiles_Icon_Size#
H=#Tiles_Icon_Size#
Container=MeterTile1
DynamicVariables=1

[MeterTileText1]
Meter=String
Text=[MeasureFileName1]
X=(#TILE_1_X#+#Tiles_Text_OX#)
Y=(#TILE_1_Y#+#Tiles_Text_OY#)
ClipStringW=#Tiles_Text_Width#
ClipStringH=#Tiles_Text_Height#
FontColor=255,255,255,255
StringAlign=CenterTop
ClipString=2
FontSize=9.5
AntiAlias=0
; FontFace=Segoe UI
StringEffect=Shadow
FontEffectColor=0,0,0,255
Container=MeterTile1
DynamicVariables=1

TILE_F_X_O=1
TILE_F_Y_O=3

[MeasureFileIcon2]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=3
Type=Icon
IconSize=Large
OnChangeAction=[!SetOption MeterTileIcon2 ImageName [MeasureFileIcon2]]

[MeasureFileName2]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=3
Type=FileName
OnChangeAction=[!SetOption MeterTileText2 Text [MeasureFileName2]]

[MeasureFilePath2]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=3
Type=FilePath

[MeterTile2]
Meter=Shape
Shape=Rectangle #TILE_2_X#,#TILE_2_Y#,75,98 | Fill Color 0,0,0,(255*[MeasureTimerCalc:]) | Stroke Color 0, 0, 0, (255*[MeasureTimerCalc:])
DynamicVariables=1

[MeterTileHitbox2]
Meter=Shape
Shape=Rectangle #TILE_2_X_O#,#TILE_2_Y_O#,75,98 | Fill Color 0,0,0,1 | Stroke Color 0, 0, 0, 1
Hidden=(Clamp(Floor(1-[MeasureTimerCalc:]*2),0,1))
DynamicVariables=1


[MeterTileSelection2]
Meter=Shape
Shape=Rectangle (#TILE_2_X#+(#Tile_Width#-#Tiles_Selection_Width#)/2),#TILE_2_Y#,(#Tiles_Selection_Width#),(#Tiles_Text_OY#+[MeterTileText2:H]) | Fill Color #Hover_Selection_Color#,(#Hover_Selection_Opacity#*#TILE_2_SELECTION#*[MeasureTimerCalc:]) | Stroke Color #Hover_Selection_Color#, (#Hover_Selection_Border_Opacity#*#TILE_2_SELECTION#*[MeasureTimerCalc:])
DynamicVariables=1
Hidden=(Floor(1-[MeasureTimerCalc:]))
Group=SelectionGroup
LeftMouseUpAction=["[MeasureFilePath2]"]
MouseOverAction=[!SetVariable TILE_2_SELECTION 1][!UpdateMeter "MeterTileSelection2"][!Redraw]
MouseLeaveAction=[!SetVariable TILE_2_SELECTION 0][!UpdateMeter "MeterTileSelection2"][!Redraw]


[MeterTileIcon2]
Meter=Image
ImageName=[MeasureFileIcon2]
X=(#TILE_2_X#+#Tiles_Icon_OX#)
Y=(#TILE_2_Y#+#Tiles_Icon_OY#)
W=#Tiles_Icon_Size#
H=#Tiles_Icon_Size#
Container=MeterTile2
DynamicVariables=1

[MeterTileText2]
Meter=String
Text=[MeasureFileName2]
X=(#TILE_2_X#+#Tiles_Text_OX#)
Y=(#TILE_2_Y#+#Tiles_Text_OY#)
ClipStringW=#Tiles_Text_Width#
ClipStringH=#Tiles_Text_Height#
FontColor=255,255,255,255
StringAlign=CenterTop
ClipString=2
FontSize=9.5
AntiAlias=0
; FontFace=Segoe UI
StringEffect=Shadow
FontEffectColor=0,0,0,255
Container=MeterTile2
DynamicVariables=1

TILE_F_X_O=1
TILE_F_Y_O=3

[MeasureFileIcon3]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=4
Type=Icon
IconSize=Large
OnChangeAction=[!SetOption MeterTileIcon3 ImageName [MeasureFileIcon3]]

[MeasureFileName3]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=4
Type=FileName
OnChangeAction=[!SetOption MeterTileText3 Text [MeasureFileName3]]

[MeasureFilePath3]
Measure=Plugin
Plugin=FileView
Path=[MeasureFolder]
Index=4
Type=FilePath

[MeterTile3]
Meter=Shape
Shape=Rectangle #TILE_3_X#,#TILE_3_Y#,75,98 | Fill Color 0,0,0,(255*[MeasureTimerCalc:]) | Stroke Color 0, 0, 0, (255*[MeasureTimerCalc:])
DynamicVariables=1

[MeterTileHitbox3]
Meter=Shape
Shape=Rectangle #TILE_3_X_O#,#TILE_3_Y_O#,75,98 | Fill Color 0,0,0,1 | Stroke Color 0, 0, 0, 1
Hidden=(Clamp(Floor(1-[MeasureTimerCalc:]*2),0,1))
DynamicVariables=1


[MeterTileSelection3]
Meter=Shape
Shape=Rectangle (#TILE_3_X#+(#Tile_Width#-#Tiles_Selection_Width#)/2),#TILE_3_Y#,(#Tiles_Selection_Width#),(#Tiles_Text_OY#+[MeterTileText3:H]) | Fill Color #Hover_Selection_Color#,(#Hover_Selection_Opacity#*#TILE_3_SELECTION#*[MeasureTimerCalc:]) | Stroke Color #Hover_Selection_Color#, (#Hover_Selection_Border_Opacity#*#TILE_3_SELECTION#*[MeasureTimerCalc:])
DynamicVariables=1
Hidden=(Floor(1-[MeasureTimerCalc:]))
Group=SelectionGroup
LeftMouseUpAction=["[MeasureFilePath3]"]
MouseOverAction=[!SetVariable TILE_3_SELECTION 1][!UpdateMeter "MeterTileSelection3"][!Redraw]
MouseLeaveAction=[!SetVariable TILE_3_SELECTION 0][!UpdateMeter "MeterTileSelection3"][!Redraw]


[MeterTileIcon3]
Meter=Image
ImageName=[MeasureFileIcon3]
X=(#TILE_3_X#+#Tiles_Icon_OX#)
Y=(#TILE_3_Y#+#Tiles_Icon_OY#)
W=#Tiles_Icon_Size#
H=#Tiles_Icon_Size#
Container=MeterTile3
DynamicVariables=1

[MeterTileText3]
Meter=String
Text=[MeasureFileName3]
X=(#TILE_3_X#+#Tiles_Text_OX#)
Y=(#TILE_3_Y#+#Tiles_Text_OY#)
ClipStringW=#Tiles_Text_Width#
ClipStringH=#Tiles_Text_Height#
FontColor=255,255,255,255
StringAlign=CenterTop
ClipString=2
FontSize=9.5
AntiAlias=0
; FontFace=Segoe UI
StringEffect=Shadow
FontEffectColor=0,0,0,255
Container=MeterTile3
DynamicVariables=1
