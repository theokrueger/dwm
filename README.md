# dwm
personalised fork of [dwm](https://dwm.suckless.org/)

designed for use by me, and as such will not make sense for anyone else

i suggest making your own fork of dwm instead of using any other fork, as none of them will fit your use case as good as your own version will

# directory
- [philosophy](#philosophy)
- [customisations](#customisations)
    - [visual](#visual)
    - [functional](#functional)
    - [keybinds](#keybinds)
        - [windowing](#windowing)
        - [applications](#applications)
        - [screenshot](#screenshot)
        - [media-control](#media-control)
- [installation](#installation)
    - [dependencies](#dependencies)
        - [required](#required)
        - [optional](#optional)
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
* status is drawn on all monitors

## functional
* tags 9 -> 5
* snap pixel 32px -> 16px
* keybinds (see below)

## keybinds
default modkey is alt

### **windowing**

| key   | function      | requires |
| ----- | ------------- | -------- |
| mod-6 | same as mod-0 | n/a      |

### **applications**

| key               | function     | requires        |
| ----------------- | ------------ | --------------- |
| mod-shift-enter   | terminal     | urxvt           |
| mod-shift-f       | web browser  | palemoon        |
| mod-shift-g       | file manager | pcmanfm         |
| mod-shift-m       | text editor  | code            |
| media volume mute | media player | sayonara-player |

### **screenshot**
you need to modify your save directory in config.h for these to work as intended.
| key                  | function                          | requires |
| -------------------- | --------------------------------- | -------- |
| mod-print            | screenshot                        | escrotum |
| mod-shift-print      | screenshot selection              | escrotum |
| mod-ctrl-print       | screenshot selection to clipboard | escrotum |
| mod-ctrl-shift-print | screen record selection           | escrotum |

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
    * optionally use [my fork](https://github.com/theokrueger/dmenu) instead
* [freetype2](https://archlinux.org/packages/extra/x86_64/freetype2/)
* [libx11](https://archlinux.org/packages/extra/x86_64/libx11/)
* [libxft](https://archlinux.org/packages/extra/x86_64/libxft/)
* [libxinerama](https://archlinux.org/packages/extra/x86_64/libxinerama/)
* [rxvt](https://aur.archlinux.org/packages/rxvt/)

```
$ sudo pacman -S dmenu freetype2 libx11 libxft libxinerama rxvt-unicode
```

### **optional**
* [dwm-status](https://dwm.suckless.org/status_monitor/)
    * optionally use [my fork](https://github.com/theokrueger/dwm-bar) instead
* [escrotum-git](https://aur.archlinux.org/packages/escrotum-git/)
* [palemoon](https://aur.archlinux.org/packages/palemoon/)
* [pcmanfm](https://archlinux.org/packages/community/x86_64/pcmanfm/)
* [playerctl](https://archlinux.org/packages/community/x86_64/playerctl/)
* [sayonara-player](https://aur.archlinux.org/packages/sayonara-player/)

```
$ yay -S dwm-status-git dmenu pcmanfm playerctl escrotum-git palemoon sayonara-player
```

# acknowledgements
[suckless.org](https://suckless.org/) for [dwm](https://dwm.suckless.org/)

[freedesktop.org](https://freedesktop.org/) for [XF86keysym.h](https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h)
