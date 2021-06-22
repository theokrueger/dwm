# my version of dwm
dont use this
but if you want to you will have to modify `*sscmd[]`, `*ssscmd[]`, and `*ssccmd[]` in `config.h` to point to your home directory instead of mine because i took the lazy route

# customisations
**visual**
* coloured the titlebar pink
**modified keybinds**
*application*
* mod-shift-enter : urxvt (terminal)
**added keybinds**
*application*
* mod-shift-f : palemoon (browser)
* mod-shift-g : pcmanfm (file manager)
* mod-shift-m : code (vscode)
* media vol mute : sayonara-player (media player)
*screenshot*
* mod-print : escrotum screenshot
* mod-shift-print : escrotum screenshot selection
* mod-ctrl-shift-print : escrotum screenshot selection to clipboard only
*media *
* media next : playerctl media next
* media previous : playerctl media previous
* media play/pause : playerctl play/pause
* media vol up : playerctl volume + 0.05
* media vol down : playerctl volume - 0.05

# "dependencies"
only required for keybinds
* urxvt
* palemoon
* pcmanfm
* escrotum
* playerctl
* code

packages
`sudo pacman -S urxvt palemoon pcmanfm escrotum playerctl code`
aur
`yay palemoon`
`yay sayonara-player`

# acknowledgements
[suckless.org](https://suckless.org/) for [dwm](https://dwm.suckless.org/)
[freedesktop.org](https://freedesktop.org/) for [XF86keysym.h](https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h)