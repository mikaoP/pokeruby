#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"
#include "decompress.h"
#include "palette.h"

extern s16 gBattleAnimArgs[];
extern u8 gBattleAnimBankAttacker;
extern u8 gBattleAnimBankTarget;

extern struct INCBIN_U8 gAttractTilemap;
extern struct INCBIN_U8 gAttractGfx;
extern struct INCBIN_U8 gAttractPal;

extern u16 gUnknown_030041B4;
extern u16 gUnknown_030042C0;

static void sub_80D21F0(u8 taskId);

// love_bg (makes the BG a background of hearts.)
// Used in Attract.

void sub_80D2100(u8 taskId)
{
    struct Struct_sub_8078914 subStruct;
    u8* tempvar;
    REG_BLDCNT = 0x3F42;
    REG_BLDALPHA = 0x1000;
    REG_BG1CNT_BITFIELD.priority = 3;
    REG_BG1CNT_BITFIELD.screenSize = 0;
    if (!NotInBattle())
        REG_BG1CNT_BITFIELD.charBaseBlock = 1;

    gUnknown_030042C0 = 0;
    gUnknown_030041B4 = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    sub_8078914(&subStruct);
    tempvar = subStruct.field_4;
    DmaFill32(3, 0x0, tempvar, 0x1000);
    LZDecompressVram(&gAttractTilemap, tempvar);
    LZDecompressVram(&gAttractGfx, subStruct.field_0);
    LoadCompressedPalette(&gAttractPal, subStruct.field_8 << 4, 32);
    if (NotInBattle())
        sub_80763FC(subStruct.field_8, (u16 *)subStruct.field_4, 0, 0);

    gTasks[taskId].func = sub_80D21F0;
}

void sub_80D21F0(u8 taskId)
{
    struct Struct_sub_8078914 subStruct;

    switch (gTasks[taskId].data[12])
    {
    case 0:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]++;
            REG_BLDALPHA = gTasks[taskId].data[11] | ((16 - gTasks[taskId].data[11]) << 8);
            if (gTasks[taskId].data[11] == 16)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 1:
        if (++gTasks[taskId].data[11] == 0x8D)
        {
            gTasks[taskId].data[11] = 16;
            gTasks[taskId].data[12]++;
        }
        break;
    case 2:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]--;
            REG_BLDALPHA = gTasks[taskId].data[11] | ((16 - gTasks[taskId].data[11]) << 8);
            if (gTasks[taskId].data[11] == 0)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 3:
        sub_8078914(&subStruct);
        {
            u8 *addr = subStruct.field_0;
            u32 size = 0x2000;
            while (1)
            {
                DmaFill32(3, 0, addr, 0x1000);
                addr += 0x1000;
                size -= 0x1000;
                if (size <= 0x1000)
                {
                    DmaFill32(3, 0, addr, size);
                    break;
                }
            }
        }
        DmaClear32(3, subStruct.field_4, 0x800);
        if (!NotInBattle())
            REG_BG1CNT_BITFIELD.charBaseBlock = 0;

        gTasks[taskId].data[12]++;
        // fall through
    case 4:
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        REG_BG1CNT_BITFIELD.priority = 1;
        DestroyAnimVisualTask(taskId);
        break;
    }
}
