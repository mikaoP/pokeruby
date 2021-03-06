RustboroCity_Gym_MapScripts:: @ 81578D8
	.byte 0

RustboroCity_Gym_EventScript_1578D9:: @ 81578D9
	trainerbattle 1, OPPONENT_ROXANNE, 0, RustboroCity_Gym_Text_183EE5, RustboroCity_Gym_Text_183FC4, RustboroCity_Gym_EventScript_1578FE
	checkflag FLAG_RECEIVED_TM39
	goto_if 0, RustboroCity_Gym_EventScript_15793C
	msgbox RustboroCity_Gym_Text_184252, 4
	release
	end

RustboroCity_Gym_EventScript_1578FE:: @ 81578FE
	message RustboroCity_Gym_Text_1840AB
	waitmessage
	call RustboroCity_Gym_EventScript_1A02C5
	msgbox RustboroCity_Gym_Text_1840D5, 4
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar 0x405a, 1
	addvar 0x4085, 1
	setvar 0x8008, 1
	call RustboroCity_Gym_EventScript_1A01C0
	compare 0x4085, 6
	call_if 1, RustboroCity_Gym_EventScript_1A00FB
	goto RustboroCity_Gym_EventScript_15793C
	end

RustboroCity_Gym_EventScript_15793C:: @ 815793C
	giveitem_std ITEM_TM39
	compare RESULT, 0
	goto_if_eq RustboroCity_Gym_EventScript_1A029B
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_184170, 4
	release
	end

RustboroCity_Gym_EventScript_157960:: @ 8157960
	trainerbattle 0, OPPONENT_JOSH, 0, RustboroCity_Gym_Text_183D99, RustboroCity_Gym_Text_183DDD
	msgbox RustboroCity_Gym_Text_183DF9, 6
	end

RustboroCity_Gym_EventScript_157977:: @ 8157977
	trainerbattle 0, OPPONENT_TOMMY, 0, RustboroCity_Gym_Text_183E38, RustboroCity_Gym_Text_183E78
	msgbox RustboroCity_Gym_Text_183E98, 6
	end

RustboroCity_Gym_EventScript_15798E:: @ 815798E
	lock
	faceplayer
	checkflag FLAG_DEFEATED_RUSTBORO_GYM
	goto_if_eq RustboroCity_Gym_EventScript_1579A3
	msgbox RustboroCity_Gym_Text_183A4B, 4
	release
	end

RustboroCity_Gym_EventScript_1579A3:: @ 81579A3
	msgbox RustboroCity_Gym_Text_183C90, 4
	release
	end

RustboroCity_Gym_EventScript_1579AD:: @ 81579AD
	lockall
	checkflag FLAG_BADGE01_GET
	goto_if_eq RustboroCity_Gym_EventScript_1579CD
	goto RustboroCity_Gym_EventScript_1579D7
	end

RustboroCity_Gym_EventScript_1579BD:: @ 81579BD
	lockall
	checkflag FLAG_BADGE01_GET
	goto_if_eq RustboroCity_Gym_EventScript_1579CD
	goto RustboroCity_Gym_EventScript_1579D7
	end

RustboroCity_Gym_EventScript_1579CD:: @ 81579CD
	msgbox RustboroCity_Gym_Text_1842E6, 4
	releaseall
	end

RustboroCity_Gym_EventScript_1579D7:: @ 81579D7
	msgbox RustboroCity_Gym_Text_1842CC, 4
	releaseall
	end
