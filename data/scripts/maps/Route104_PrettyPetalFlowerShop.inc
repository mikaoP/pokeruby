Route104_PrettyPetalFlowerShop_MapScripts:: @ 815BDE4
	map_script 3, Route104_PrettyPetalFlowerShop_MapScript1_15BDEA
	.byte 0

Route104_PrettyPetalFlowerShop_MapScript1_15BDEA:: @ 815BDEA
	setflag FLAG_LANDMARK_FLOWER_SHOP
	checkflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	goto_if 0, Route104_PrettyPetalFlowerShop_EventScript_15BE03
	checkflag FLAG_BADGE03_GET
	goto_if 0, Route104_PrettyPetalFlowerShop_EventScript_15BE03
	setflag FLAG_TEMP_1
	end

Route104_PrettyPetalFlowerShop_EventScript_15BE03:: @ 815BE03
	setobjectxyperm 1, 4, 6
	end

Route104_PrettyPetalFlowerShop_EventScript_15BE0B:: @ 815BE0B
	lock
	faceplayer
	checkflag FLAG_TEMP_1
	goto_if_eq Route104_PrettyPetalFlowerShop_EventScript_15BE7C
	msgbox Route104_PrettyPetalFlowerShop_Text_1C5EC6, 4
	checkflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	goto_if_eq Route104_PrettyPetalFlowerShop_EventScript_15BE4A
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	msgbox Route104_PrettyPetalFlowerShop_Text_1C5F48, 5
	compare RESULT, 1
	call_if 1, Route104_PrettyPetalFlowerShop_EventScript_15BE6A
	compare RESULT, 0
	call_if 1, Route104_PrettyPetalFlowerShop_EventScript_15BE73
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_15BE4A:: @ 815BE4A
	msgbox Route104_PrettyPetalFlowerShop_Text_1C5F1B, 5
	compare RESULT, 1
	call_if 1, Route104_PrettyPetalFlowerShop_EventScript_15BE6A
	compare RESULT, 0
	call_if 1, Route104_PrettyPetalFlowerShop_EventScript_15BE73
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_15BE6A:: @ 815BE6A
	msgbox Route104_PrettyPetalFlowerShop_Text_1C5F9D, 4
	return

Route104_PrettyPetalFlowerShop_EventScript_15BE73:: @ 815BE73
	msgbox Route104_PrettyPetalFlowerShop_Text_1C6121, 4
	return

Route104_PrettyPetalFlowerShop_EventScript_15BE7C:: @ 815BE7C
	message Route104_PrettyPetalFlowerShop_Text_1A0C42
	waitmessage
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Items
	msgbox Route104_PrettyPetalFlowerShop_Text_1A0C02, 4
	release
	end

	.align 2
Route104_PrettyPetalFlowerShop_Items:: @ 815BE94
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_NONE
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_15BEA4:: @ 815BEA4
	lock
	faceplayer
	checkflag FLAG_RECEIVED_WAILMER_PAIL
	goto_if 0, Route104_PrettyPetalFlowerShop_EventScript_15BEB9
	msgbox Route104_PrettyPetalFlowerShop_Text_1C61E8, 4
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_15BEB9:: @ 815BEB9
	msgbox Route104_PrettyPetalFlowerShop_Text_1C6158, 4
	giveitem_std ITEM_WAILMER_PAIL
	msgbox Route104_PrettyPetalFlowerShop_Text_1C61E8, 4
	setflag FLAG_RECEIVED_WAILMER_PAIL
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_15BEDA:: @ 815BEDA
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_DAILY_RECEIVED_BERRY_FLOWER_SHOP
	goto_if_eq Route104_PrettyPetalFlowerShop_EventScript_15BF1A
	msgbox Route104_PrettyPetalFlowerShop_Text_1C62DA, 4
	random 8
	addvar RESULT, ITEM_CHERI_BERRY
	giveitem_std RESULT
	compare RESULT, 0
	goto_if_eq Route104_PrettyPetalFlowerShop_EventScript_1A029B
	setflag FLAG_DAILY_RECEIVED_BERRY_FLOWER_SHOP
	msgbox Route104_PrettyPetalFlowerShop_Text_1C6335, 4
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_15BF1A:: @ 815BF1A
	msgbox Route104_PrettyPetalFlowerShop_Text_1C6335, 4
	release
	end
