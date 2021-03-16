[Variables]
Amount=([MeasureFileCount:]+[MeasureFoldersCount:]+1)

; <=========================================>
; <=============== EDIT AREA ===============>
; <=========================================>

; To change image of base tile, replace folder.ico in @Resources folder

; Uncoment this line (and comment next one) for custom folder width.
; Tiles_Len=1
Tiles_Len=(Ceil(Sqrt(#Amount#)))

; Don't change this
Tiles_Height=(#Tiles_Len#-Floor((#Tiles_Len#**2 - #Amount#)/#Tiles_Len#))

; Path to folder
Path=


Tile_Width=75
Tile_Height=98

Tiles_Icon_Size=44
Tiles_Text_Height=32
Tiles_Text_Width=80
Tiles_Text_Icon_Spacing=4
Tiles_Selection_Width=76
Tile_Spacing=1

; Measured in seconds
Animation_Speed=0.1
; Total amount of frames.
; Limit is ~60 fps, trying to incerease number of frames past this limit will cause slower animation.
Timer_Steps=6

; Tile paddings
PX=1
PY=3


; <======= Position of root folder in expanded window =======>
; Uncomment only the one you want

; Top-left
Root_Position=0

;Top-right
; Root_Position=(#Tiles_Len#-1)

; Bottom-left
; Root_Position=(#Tiles_Len#*(#Tiles_Height#-1))

; Bottom-right
; Root_Position=(#Tiles_Len#*#Tiles_Height#-1)

; Approximately in a middle
; Root_Position=(Floor(#Tiles_Height#/2)*#Tiles_Len#+Floor(#Tiles_Len#/2))


; Color of folder background.
; Format is Red, Green, Blue, Opacity. Every value is [0,255] range
; Set opacity to 0 to disable background
; Multiply opacity by [MeasureTimerCalc:] for dynamic opacity. 
;   don't forget to enclose formula in ()
Background_Color=0,0,0,(0*[MeasureTimerCalc:])
Background_Border=0,0,0,(0*[MeasureTimerCalc:])

; Color of selection rectangle.
Hover_Selection_Color=153,203,240
Hover_Selection_Opacity=38
Hover_Selection_Border_Opacity=76






; <=========================================>
; <============== DON'T TOUCH ==============>
; <=========================================>


Tiles_Step_X=(#Tile_Width#+#Tile_Spacing#)
Tiles_Step_Y=(#Tile_Height#+#Tile_Spacing#)
Tiles_Icon_OX=((#Tile_Width#-#Tiles_Icon_Size#)/2)
; Tiles_Icon_OY=((#Tile_Height#-#Tiles_Text_Height#-#Tiles_Text_Icon_Spacing#-#Tiles_Icon_Size#)/2)
Tiles_Icon_OY=1

Tiles_Text_OX=((#Tile_Width#)/2)
Tiles_Text_OY=(#Tiles_Icon_Size#+#Tiles_Icon_OY#+#Tiles_Text_Icon_Spacing#)

Index_Offset=max(#Root_Position#-#Amount#+1,0)
TILE_F_X=(#PX#+#Tiles_Step_X#*(#Root_Position# % #Tiles_Len#))
TILE_F_Y=(#PY#+#Tiles_Step_Y#*Floor(#Root_Position# / #Tiles_Len#))

;timer
Timer_Step=(1/#Timer_Steps#)
Timer_Step_Delay=((#Animation_Speed#/#Timer_Steps#)*1000)

TIMER=0

Hitbox_Width=(#PX# + (#Tile_Width#+#Tile_Spacing#)*( 1 + (#Tiles_Len#-1)*[MeasureTimerCalc:]) - #Tile_Spacing#)
Hitbox_Height=(#PY# + (#Tile_Height#+#Tile_Spacing#)*( 1 + (#Tiles_Height#-1)*[MeasureTimerCalc:]) - #Tile_Spacing#)

Hitbox_X=(#TILE_F_X#*(1-[MeasureTimerCalc:])-#PX#)
Hitbox_Y=(#TILE_F_Y#*(1-[MeasureTimerCalc:])-#PY#)