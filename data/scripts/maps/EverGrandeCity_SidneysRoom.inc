EverGrandeCity_SidneysRoom_MapScripts:: @ 815B53F
	map_script 1, EverGrandeCity_SidneysRoom_MapScript1_15B54F
	map_script 4, EverGrandeCity_SidneysRoom_MapScript2_15B570
	map_script 2, EverGrandeCity_SidneysRoom_MapScript2_15B57F
	.byte 0

EverGrandeCity_SidneysRoom_MapScript1_15B54F:: @ 815B54F
	checkflag FLAG_DEFEATED_ELITE_4_SYDNEY
	call_if 1, EverGrandeCity_SidneysRoom_EventScript_15B564
	compare 0x409c, 1
	call_if 1, EverGrandeCity_SidneysRoom_EventScript_15B56A
	end

EverGrandeCity_SidneysRoom_EventScript_15B564:: @ 815B564
	call EverGrandeCity_SidneysRoom_EventScript_1A0757
	return

EverGrandeCity_SidneysRoom_EventScript_15B56A:: @ 815B56A
	call EverGrandeCity_SidneysRoom_EventScript_1A07FA
	return

EverGrandeCity_DrakesRoom_MapScript2_15B570:: @ 815B570
EverGrandeCity_SidneysRoom_MapScript2_15B570:: @ 815B570
	map_script_2 0x4001, 0, EverGrandeCity_SidneysRoom_EventScript_15B57A
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_15B57A:: @ 815B57A
	turnobject 255, 2
	end

EverGrandeCity_SidneysRoom_MapScript2_15B57F:: @ 815B57F
	map_script_2 0x409c, 0, EverGrandeCity_SidneysRoom_EventScript_15B589
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_15B589:: @ 815B589
	lockall
	call EverGrandeCity_SidneysRoom_EventScript_1A0710
	setvar 0x409c, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_15B596:: @ 815B596
	lock
	faceplayer
	checkflag FLAG_DEFEATED_ELITE_4_SYDNEY
	goto_if_eq EverGrandeCity_SidneysRoom_EventScript_15B5BD
	playbgm 450, 0
	msgbox EverGrandeCity_SidneysRoom_Text_190728, 4
	trainerbattle 3, OPPONENT_SIDNEY, 0, EverGrandeCity_SidneysRoom_Text_190823
	goto EverGrandeCity_SidneysRoom_EventScript_15B5C7
	end

EverGrandeCity_SidneysRoom_EventScript_15B5BD:: @ 815B5BD
	msgbox EverGrandeCity_SidneysRoom_Text_19086D, 4
	release
	end

EverGrandeCity_SidneysRoom_EventScript_15B5C7:: @ 815B5C7
	setflag FLAG_DEFEATED_ELITE_4_SYDNEY
	call EverGrandeCity_SidneysRoom_EventScript_1A0693
	msgbox EverGrandeCity_SidneysRoom_Text_19086D, 4
	release
	end
