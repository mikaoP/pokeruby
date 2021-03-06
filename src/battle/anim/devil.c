#include "global.h"
#include "battle_anim.h"
#include "rom_8077ABC.h"
#include "sprite.h"
#include "trig.h"

extern s16 gBattleAnimArgs[8];
extern u8 gBattleAnimBankTarget;

void sub_80D2ABC(struct Sprite *sprite)
{
    if (sprite->data[3] == 0)
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        StartSpriteAnim(sprite, 0);
        sprite->subpriority = sub_8079E90(gBattleAnimBankTarget) - 1;
        sprite->data[2] = 1;
    }
    sprite->data[0] += sprite->data[2];
    sprite->data[1] = (sprite->data[0] * 4) % 256;
    if (sprite->data[1] < 0)
        sprite->data[1] = 0;
    sprite->pos2.x = Cos(sprite->data[1], 30 - sprite->data[0] / 4);
    sprite->pos2.y = Sin(sprite->data[1], 10 - sprite->data[0] / 8);
    if (sprite->data[1] > 128 && sprite->data[2] > 0)
        sprite->data[2] = -1;
    if (sprite->data[1] == 0 && sprite->data[2] < 0)
        sprite->data[2] = 1;
    sprite->data[3]++;
    if (sprite->data[3] < 10 || sprite->data[3] > 0x50)
        sprite->invisible = sprite->data[0] % 2;
    else
        sprite->invisible = FALSE;
    if (sprite->data[3] > 0x5A)
        move_anim_8072740(sprite);
}
