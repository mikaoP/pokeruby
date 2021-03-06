FortreeCity_House4_MapScripts:: @ 815817E
	.byte 0

FortreeCity_House4_EventScript_15817F:: @ 815817F
	msgbox FortreeCity_House4_Text_1867AF, 2
	end

FortreeCity_House4_EventScript_158188:: @ 8158188
	lockall
	checkflag FLAG_RECEIVED_MENTAL_HERB
	goto_if_eq FortreeCity_House4_EventScript_158204
	checkflag FLAG_WINGULL_DELIVERED_MAIL
	goto_if_eq FortreeCity_House4_EventScript_1581D6
	checkflag FLAG_WINGULL_SENT_ON_ERRAND
	goto_if_eq FortreeCity_House4_EventScript_1581C2
	msgbox FortreeCity_House4_Text_186835, 4
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_WINGULL_MOSSDEEP_HOUSE
	applymovement 3, FortreeCity_House4_Movement_158218
	waitmovement 0
	removeobject 3
	releaseall
	end

FortreeCity_House4_EventScript_1581C2:: @ 81581C2
	applymovement LAST_TALKED, FortreeCity_House4_Movement_1A0839
	waitmovement 0
	msgbox FortreeCity_House4_Text_18684E, 4
	releaseall
	end

FortreeCity_House4_EventScript_1581D6:: @ 81581D6
	applymovement LAST_TALKED, FortreeCity_House4_Movement_1A0839
	waitmovement 0
	msgbox FortreeCity_House4_Text_186881, 4
	giveitem_std ITEM_MENTAL_HERB
	compare RESULT, 0
	goto_if_eq FortreeCity_House4_EventScript_1A029B
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_158204:: @ 8158204
	applymovement LAST_TALKED, FortreeCity_House4_Movement_1A0839
	waitmovement 0
	msgbox FortreeCity_House4_Text_186924, 4
	releaseall
	end

FortreeCity_House4_Movement_158218:: @ 8158218
	step_15
	step_15
	step_18
	step_25
	step_13
	step_end

FortreeCity_House4_EventScript_15821E:: @ 815821E
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox FortreeCity_House4_Text_18695C, 4
	waitmoncry
	release
	end
