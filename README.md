# dwm
personalised fork of [dwm](https://dwm.suckless.org/)

designed for use by me, and as such will not make sense for anyone else

i suggest making your own fork of dwm instead of using any other fork, as none of them will fit your use case as good as your own version will

# directory
- [philosophy](#philosophy)
- [customisations](#customisations)
    - [visual](#visual)
    - [keybinds](#keybinds)
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
* coloured the titlebar pink

## keybinds
### **applications**

| key               | function     | requires        |
| ----------------- | ------------ | --------------- |
| mod-shift-enter   | terminal     | urxvt           |
| mod-shift-f       | web browser  | palemoon        |
| mod-shift-g       | file manager | pcmanfm         |
| mod-shift-m       | text editor  | code            |
| media volume mute | media player | sayonara-player |

### **screenshot**
| key             | function                          | requires |
| --------------- | --------------------------------- | -------- |
| mod-print       | screenshot                        | escrotum |
| mod-shift-print | screenshot selection              | escrotum |
| mod-ctrl-print  | screenshot selection to clipboard | escrotum |

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
* [freetype2](https://archlinux.org/packages/extra/x86_64/freetype2/)
* [libx11](https://archlinux.org/packages/extra/x86_64/libx11/)
* [libxft](https://archlinux.org/packages/extra/x86_64/libxft/)
* [libxinerama](https://archlinux.org/packages/extra/x86_64/libxinerama/)
* [rxvt](https://aur.archlinux.org/packages/rxvt/)

```
$ sudo pacman -S freetype2 libx11 libxft libxinerama rxvt
```

### **optional**
* [dmenu](https://archlinux.org/packages/community/x86_64/dmenu/)
    * optionally use [my fork](https://github.com/theokrueger/dmenu) instead
* [escrotum-git](https://aur.archlinux.org/packages/escrotum-git/)
* [palemoon](https://aur.archlinux.org/packages/palemoon/)
* [playerctl](https://archlinux.org/packages/community/x86_64/playerctl/)

```
$ sudo pacman -S dmenu playerctl
$ yay palemoon
$ yay escrotum-git
```

# acknowledgements
[suckless.org](https://suckless.org/) for [dwm](https://dwm.suckless.org/)

[freedesktop.org](https://freedesktop.org/) for [XF86keysym.h](https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h)
