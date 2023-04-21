# FE8U CHAX

- date: 2023-04-21
- branch: [shifeng-dev](https://github.com/MokhaLeee/fe8_hacks_sundries/tree/shifeng-dev)

## Api

- manim: up
- post-action hook
- chapter-init-hook
- phase-init-hook

## Hacks

- bmbattle: item skill inori & dmg-handler
- remove skill

## Memmap

| Remap | Address     | Size    | Note  |
| :---: | :----:      | :----:  | :---  |
| RAM   | `0x203EDB9` | `0x3`   | 1 Byte left  |
| ROM   | `0x8EF2F18` | `0x4CC` | nope  |

## Hack note

`B623EC`: PostCombatLoop
`B6246C`: PostCombatSkills
`B6284C`: WTACalcFunctions
`B4045C`: SkillTester
`B51218`: ReMove
