
# Usage

Inside **EkrDragonHook.event**, modify for `EkrDragonSpecialRountineHook` as you wish. I have introduced to macros for beginners and wizardry:

- `EkrDragonCommonIntroChunk`
  - **@class**: class index
  - **@banim_intro**: Frame battle anim index on battle starting
  - **@banim_main**: Main frame battle anim index
  - **@banim_exit**: Frame battle anim index on battle ending

<br>

- `EkrDragonHookChunk` (**wizardry only**)
  - **@type**: the same as `EkrDragonStatus::type` in vanilla. 0 for normal banim, 1 for DracoZombie, 2 for DemonKing and 3 for Myrrh. You may set your own type as 4+ but for now I can not guarantee no bugs for DIY.
  - **@class**: Class index
  - **@config**: (1 << 0) for unique banim and (1 << 2) for Myrrh style common intro. Set it as (1 << 0) if you want apply your own intro function.
  - **@intro_routine**: `void (*intro_routine)(struct Anim *anim, u32 priv)` in place of vanilla DK & DZ & Myrrh intro routine.
  - **@priv**: u32 of arg2 for **@intro_routine**.

Let me take an example:

```c
EkrDragonCommonIntroChunk(0x3C, 0xC5, 0xC4, 0xC6)
```

Here 0x3C is the class index for Myrrh, 0xC5 is the starting frame index for Battle-Animations, 0xC4 is the main battle frame index and 0xC6 is the ending fram index. Then you may got a myrrh style banim for class_3C.

# Tips

Since

# Known Issues

- 1. Manakete style banim has not been introduced non-weapon avoid anim yet.
- 2. `EkrDragonHandler::type` inherits from vanilla, which is a redundancy for such hack. But since there is still a considerable amount of code in `banim` that has not been interpreted (and I also encourage you to participate in [decompile project](https://github.com/FireEmblemUniverse/fireemblem8u) as well), so for now I tend to keep this data for consistency with the vanilla.
- 3. Epic banims which involves BG effects (DemonKing, DracoZombie, etc) have not been unlocked for ally units, since it will cause bad effect when you try to let DK attack to DK, etc.
