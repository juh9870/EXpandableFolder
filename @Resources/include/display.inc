[MeterTileFolder]
Meter=Shape
Shape=Rectangle 0,0,(#PX#+#Tile_Width#),(#PY#+#Tile_Height#) | Fill Color 0,0,0,1 | Stroke Color 0,0,0,1
LeftMouseUpAction=["explorer.exe" #Path#]

[MeterTileIconFolder]
Meter=Image
ImageName=#@#folder.ico
X=#Tiles_Icon_OX#
Y=#Tiles_Icon_OY#
W=#Tiles_Icon_Size#
H=#Tiles_Icon_Size#

[MeasurePathFolderName]
Measure=String
String=#Path#
RegExpSubstitute=1
Substitute="^.*\\(.*)$":"\1"

[MeterTileTextFolder]
Meter=String
MeasureName=MeasurePathFolderName
Text=%1
X=#Tiles_Text_OX#
Y=#Tiles_Text_OY#
W=#Tiles_Text_Width#
H=#Tiles_Text_Height#
FontColor=255,255,255,255
StringAlign=CenterTop
ClipString=2
FontSize=9.5
AntiAlias=0
; FontFace=Segoe UI
StringEffect=Shadow
FontEffectColor=0,0,0,255
; UpdateDivider=-1