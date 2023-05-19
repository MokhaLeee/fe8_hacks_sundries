# Unit Debuff Banim Flashing Rework

A patch that allows you to customize the debuff flashing effect on unit during battle.

Usage:

Include file **EfxStatusUnitRework.event** and define your own debuff flashing effect in `EfxUnitDebuffPalConfigTable`, which you may define the flash R/G/B color and the flashing speed.

The R/G/B effect is recommended ranging **from 0 to 0x10**, the higher value may result in a more pronounced the shiny effect.

The speed range **from 0 to 3**, in which **0** will not change the color, **1** is the slow speed, **2** is the vanilla, and **3** may flash fast.

This patch is not conflict to any existing patch since the unit debuff index is not directly caught from unit struct, so don't worry.
