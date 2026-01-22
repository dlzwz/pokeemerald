#include "global.h"
#include "event_data.h"
#include "level_caps.h"
#include "constants/flags.h"

// Level caps based on highest level Pokemon of each gym leader
// Gym 1 (Roxanne): Lv 15 - Nosepass
// Gym 2 (Brawly): Lv 19 - Makuhita
// Gym 3 (Wattson): Lv 24 - Manectric
// Gym 4 (Flannery): Lv 29 - Torkoal
// Gym 5 (Norman): Lv 31 - Slaking
// Gym 6 (Winona): Lv 33 - Altaria
// Gym 7 (Tate & Liza): Lv 42 - Solrock/Lunatone
// Gym 8 (Juan): Lv 46 - Kingdra
// Champion (Wallace): Lv 58 - Milotic
static const u8 sBadgeLevelCaps[NUM_BADGES + 1] = {
    [0] = 15,  // Before any badges
    [1] = 19,  // After Badge 1
    [2] = 24,  // After Badge 2
    [3] = 29,  // After Badge 3
    [4] = 31,  // After Badge 4
    [5] = 33,  // After Badge 5
    [6] = 42,  // After Badge 6
    [7] = 46,  // After Badge 7
    [8] = 58,  // After Badge 8, before Champion
};

u8 GetCurrentLevelCap(void)
{
    u8 i;
    u8 badgeCount = 0;

    // If player is champion, no level cap
    if (FlagGet(FLAG_IS_CHAMPION))
        return MAX_LEVEL;

    // Count badges
    for (i = 0; i < NUM_BADGES; i++)
    {
        if (FlagGet(FLAG_BADGE01_GET + i))
            badgeCount++;
    }

    return sBadgeLevelCaps[badgeCount];
}
