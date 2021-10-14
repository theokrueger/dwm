# dwm
personalised fork of [dwm](https://dwm.suckless.org/)

designed for use by me, and as such will not make sense for anyone else

i suggest making your own fork of dwm instead of using any other fork, as none of them will fit your use case as good as your own version will

# directory
- [dwm](#dwm)
- [directory](#directory)
- [philosophy](#philosophy)
- [customisations](#customisations)
  - [visual](#visual)
  - [functional](#functional)
  - [keybinds](#keybinds)
    - [**windowing**](#windowing)
    - [**resolution**](#resolution)
    - [**applications**](#applications)
    - [**screenshot**](#screenshot)
    - [**media-control**](#media-control)
- [installation](#installation)
  - [dependencies](#dependencies)
    - [**required**](#required)
    - [**optional**](#optional)
- [acknowledgements](#acknowledgements)

# philosophy
keep it simple, stupid.
# customisations
## visual
* pink colour scheme
* tiling indicator text changed
    * tile: "[]=" -> "tl"
    * float: "><>" -> "fl"
    * monocole: "[M]" -> "fs"
* removed numbers from tags

## functional
* tags 9 -> 6
* snap pixel 32px -> 16px
* keybinds (see below)
* added [system tray patch](https://dwm.suckless.org/patches/systray/)
* added [actual fullscreen patch](https://dwm.suckless.org/patches/actualfullscreen/)
* box indicator on tabs is rectangular and centered

## keybinds
default modkey is OS

### **windowing**

| key         | function          | requires |
| ----------- | ----------------- | -------- |
| mod-6       | same as mod-0     | n/a      |
| mod-shift-m | toggle fullscreen | n/a      |

### **resolution**
press mod-ctrl-shift and a qwert to change resolution
mod-ctrl-shift-arrow for rotations
to be fixed l8r
### **applications**

| key               | function          | requires   |
| ----------------- | ----------------- | ---------- |
| mod-shift-enter   | terminal          | urxvt      |
| mod-shift-f       | web browser       | firefox    |
| mod-shift-g       | file manager      | pcmanfm    |
| mod-shift-e       | text editor       | code       |
| media volume mute | media player      | clementine |
| mod-shift-d       | instant messenger | discord    |
| mod-shift-s       | game launcher     | steam      |

### **screenshot**
you need to modify your save directory in config.h for these to work as intended.
| key         | function                          | requires |
| ----------- | --------------------------------- | -------- |
| mod-ctrl-s  | screenshot selection*             | escrotum |
| mod-shift-s | screenshot selection to clipboard | escrotum |

*requires setting output directory in config.h

### **media-control**

| key               | function                | requires  |
| ----------------- | ----------------------- | --------- |
| media next        | media next              | playerctl |
| media previous    | media previous          | playerctl |
| media play/pause  | media play/pause        | playerctl |
| media volume up   | media player volume +5% | playerctl |
| media volume down | media playervolume -5%  | playerctl |

# installation
## dependencies
### **required**
* [dmenu](https://archlinux.org/packages/community/x86_64/dmenu/)
* [freetype2](https://archlinux.org/packages/extra/x86_64/freetype2/)
* [libx11](https://archlinux.org/packages/extra/x86_64/libx11/)
* [libxft](https://archlinux.org/packages/extra/x86_64/libxft/)
* [libxinerama](https://archlinux.org/packages/extra/x86_64/libxinerama/)
* [st](https://dwm.suckless.org/st/)
    * optionally use [my fork](https://github.com/theokrueger/st) instead

```
$ sudo pacman -S dmenu freetype2 libx11 libxft libxinerama st
```

### **optional**
* [dwm-status](https://dwm.suckless.org/status_monitor/)
    * optionally use [my version](https://github.com/theokrueger/dwm-bar) instead
* [networkmanager-dmenu](https://aur.archlinux.org/packages/networkmanager-dmenu-git/)
* [escrotum-git](https://aur.archlinux.org/packages/escrotum-git/)
* [palemoon](https://aur.archlinux.org/packages/palemoon/)
* [xfe](https://aur.archlinux.org/packages/xfe/)
* [playerctl](https://archlinux.org/packages/community/x86_64/playerctl/)
* [clementine](https://archlinux.org/packages/community/x86_64/clementine/)

```
$ yay -S dwm-status-git dmenu pcmanfm playerctl escrotum-git palemoon elisa steam discord
```

# acknowledgements
[suckless.org](https://suckless.org/) for [dwm](https://dwm.suckless.org/)
[freedesktop.org](https://freedesktop.org/) for [XF86keysym.h](https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h)

