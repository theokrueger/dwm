/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 0;  /* border pixel of windows */
static const unsigned int snap           = 8;  /* snap pixel */
static const unsigned int systraypinning = 1;  /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;  /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;  /* systray spacing */
static const int systraypinningfailfirst = 1;  /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;  /* 0 means no systray */
static const int showbar                 = 1;  /* 0 means no bar */
static const int topbar                  = 1;  /* 0 means bottom bar */
static const char *fonts[]               = { "monospace:size=10" };
static const char dmenufont[]            = "monospace:size=10";
static const char col_gray1[]            = "#222222";
static const char col_gray2[]            = "#444444";
static const char col_gray3[]            = "#bbbbbb";
static const char col_gray4[]            = "#eeeeee";
static const char col_pink[]             = "#ff66cc";
static const char *colors[][3]           = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_pink },
	[SchemeSel]  = { col_gray4, col_pink,  col_pink  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance      title   tags mask     isfloating   monitor */
    {  "discord",     "discord",    NULL,   1,            0,           1 },
	{  "Steam",       "Steam",      NULL,   1 << 1,       0,           1 },
	{  "Clementine",  "clementine", NULL,   1 << 2,       0,           1 },
	{  "Thunderbird", "Mail",       NULL,   1 << 3,       0,           1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "tl",      tile },    /* first entry is default */
	{ "fl",      NULL },    /* no layout function means floating behavior */
	{ "fs",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask // alt
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// note that due to my laziness this is actually suboptimal, having commands execute shell scripts instead would entail more extensibility and ease of modification.
/* applications */
static const char *app_terminal[]    = { "urxvt", NULL };       // bound to mod-shift-enter
static const char *app_webbrowser[]  = { "palemoon", NULL };    // bound to mod-shift-f
static const char *app_filemanager[] = { "pcmanfm", NULL };     // bound to mod-shift-g
static const char *app_editor[]      = { "code", NULL };        // bound to mod-shift-e
static const char *app_messenger[]   = { "discord", NULL };     // bound to mod-shift-d
static const char *app_gamestore[]   = { "steam", NULL };       // bound to mod-shift-s
static const char *app_emailclient[] = { "thunderbird", NULL }; // bound to mod-shift-t
/* screenshot */
#define IMAGESAVELOCATION "/home/theo/Pictures/screenshots/%y-%m-%d-%H:%M:%S.png"           // save location, lazy edition
#define VIDEOSAVELOCATION "/home/theo/Pictures/screenshots/captures/%y-%m-%d-%H:%M:%S.webm" // escrotum is dumb and requires a .webm extension to save at all, god i wish i used shell scripts instead of this garbage
static const char *screenshot_full[]             = { "escrotum", IMAGESAVELOCATION, NULL };             // bound to mod-prtsc
static const char *screenshot_select[]           = { "escrotum", IMAGESAVELOCATION, "-s", NULL };       // bound to mod-shift-prtsc
static const char *screenshot_select_clipboard[] = { "escrotum", "-s", "-C", NULL };                    // bound to mod-ctrl-prtsc
static const char *screenshot_select_video[]     = { "escrotum", VIDEOSAVELOCATION, "-s", "-r", NULL }; // bound to mod-ctrl-shift-prtsc, stop with ctrl-alt-s
/* media control */
#define XF86XK_AudioNext                 0x1008FF17
static const char *media_next[]          = { "playerctl", "next", NULL };            // bound to media next
#define XF86XK_AudioPrev                 0x1008FF16
static const char *media_previous[]      = { "playerctl", "previous", NULL };        // bound to media previous
#define XF86XK_AudioPlay                 0x1008FF14
static const char *media_playpause[]     = { "playerctl", "play-pause", NULL };      // bound to media play/pause
#define XF86XK_AudioRaiseVolume          0x1008FF13
static const char *media_volume_up[]     = { "playerctl", "volume", "0.05+", NULL }; // bound to media volume up
#define XF86XK_AudioLowerVolume          0x1008FF11
static const char *media_volume_down[]   = { "playerctl", "volume", "0.05-", NULL }; // bound to media volume down
#define XF86XK_AudioMute                 0x1008FF12
static const char *media_launch_player[] = { "clementine", NULL };                   // bound to media volume mute
/* display scaling */
#define PRIMARYDISPLAYSTRING     "DVI-D-0" // display to apply scaling keybinds to
#define DISPLAYFILTERTYPE        "nearest" // change display scaling filtering. valid types: nearest,bilinear
static const char *scale1080[]   = { "xrandr", "--output", PRIMARYDISPLAYSTRING, "--scale-from", "1920x1080", "--filter", DISPLAYFILTERTYPE, NULL }; // bound to mod-shift-backslash
static const char *scale720[]    = { "xrandr", "--output", PRIMARYDISPLAYSTRING, "--scale-from", "1280x720", "--filter", DISPLAYFILTERTYPE, NULL };  // bound to mod-shift-leftbracket
static const char *scale540[]    = { "xrandr", "--output", PRIMARYDISPLAYSTRING, "--scale-from", "960x540", "--filter", DISPLAYFILTERTYPE, NULL };   // bound to mod-shift-quote
static const char *scale768[]    = { "xrandr", "--output", PRIMARYDISPLAYSTRING, "--scale-from", "1024x768", "--filter", DISPLAYFILTERTYPE, NULL };  // bound to mod-shift-rightbracket
static const char *scale480[]    = { "xrandr", "--output", PRIMARYDISPLAYSTRING, "--scale-from", "640x480", "--filter", DISPLAYFILTERTYPE, NULL };   // bound to mod-shift-semicolon

/* default commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_pink, "-sf", col_gray4, NULL }; // launch dmenu

static Key keys[] = {
	/* added keys */
	// commands i have added or modified from defaults
	/* applications */
	{ MODKEY|ShiftMask,             XK_Return,                 spawn,          {.v = app_terminal } },    // spawn terminal (rxvt-unicode)
	{ MODKEY|ShiftMask,             XK_f,                      spawn,          {.v = app_webbrowser } },  // spawn browser (palemoon)
	{ MODKEY|ShiftMask,             XK_g,                      spawn,          {.v = app_filemanager } }, // spawn file manager (pcmanfm)
	{ MODKEY|ShiftMask,             XK_e,                      spawn,          {.v = app_editor } },      // spawn editor (code)
	{ MODKEY|ShiftMask,             XK_d,                      spawn,          {.v = app_messenger } },   // spawn instant messenger (discord)
	{ MODKEY|ShiftMask,             XK_s,                      spawn,          {.v = app_gamestore } },   // spawn game launcher (steam)
	{ MODKEY|ShiftMask,             XK_t,                      spawn,          {.v = app_emailclient } }, // spawn email client (thunderbird)
	/* screenshot */
	{ MODKEY,                       XK_Print,                  spawn,          {.v = screenshot_full } },             // take full screenshot (escrotum)
	{ MODKEY|ShiftMask,             XK_Print,                  spawn,          {.v = screenshot_select } },           // take screenshot of selection (escrotum)
	{ MODKEY|ControlMask,           XK_Print,                  spawn,          {.v = screenshot_select_clipboard } }, // take screenshot of selection and only copy to clipboard (escrotum)
	{ MODKEY|ControlMask|ShiftMask, XK_Print,                  spawn,          {.v = screenshot_select_video } },     // record screen selection, stop with ctl ctrl-alt-s (escrotum)
	/* media control */
	{ 0,                            XF86XK_AudioNext,          spawn,          {.v = media_next } },          // media player next entry (playerctl)
	{ 0,                            XF86XK_AudioPrev,          spawn,          {.v = media_previous } },      // media player previous entry (playerctl)
	{ 0,                            XF86XK_AudioPlay,          spawn,          {.v = media_playpause } },     // media player pause/play (playerctl)
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn,          {.v = media_volume_up } },     // media player increase volume by .05 (playerctl)
	{ 0,                            XF86XK_AudioLowerVolume,   spawn,          {.v = media_volume_down } },   // media player decrease volume by .05 (playerctl)
	{ 0,                            XF86XK_AudioMute,          spawn,          {.v = media_launch_player } }, // spawn audio player (clementine)
	/* windowing */
	{ MODKEY,                       XK_6,                      view,           {.ui = ~0 } }, // duplicate of XK_0
	{ MODKEY|ShiftMask,             XK_6,                      tag,            {.ui = ~0 } }, // duplicate of XK_0
	{ MODKEY|ShiftMask,             XK_m,                      togglefullscr,  {0} },         // toggles fullscreen on a window
	/* resolution */
	{ MODKEY|ShiftMask,             XK_backslash,              spawn,          {.v = scale1080 } },          // changes display scaling sorta (xrandr)
	{ MODKEY|ShiftMask,             XK_bracketright,           spawn,          {.v = scale720 } },           // changes display scaling sorta (xrandr)
	{ MODKEY|ShiftMask,             XK_apostrophe,             spawn,          {.v = scale540 } },           // changes display scaling sorta (xrandr)
	{ MODKEY|ShiftMask,             XK_bracketleft,            spawn,          {.v = scale768 } },           // changes display scaling sorta (xrandr)
	{ MODKEY|ShiftMask,             XK_semicolon,              spawn,          {.v = scale480 } },           // changes display scaling sorta (xrandr)
	/* default keys */
	{ MODKEY,                       XK_p,                      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_b,                      togglebar,      {0} },
	{ MODKEY,                       XK_j,                      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,                      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,                      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,                      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,                      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,                      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,                 zoom,           {0} },
	{ MODKEY,                       XK_Tab,                    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,                      killclient,     {0} },
	{ MODKEY,                       XK_t,                      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,                  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                  togglefloating, {0} },
	{ MODKEY,                       XK_0,                      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                 focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                 tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                                      0)
	TAGKEYS(                        XK_2,                                      1)
	TAGKEYS(                        XK_3,                                      2)
	TAGKEYS(                        XK_4,                                      3)
	TAGKEYS(                        XK_5,                                      4)
	/* remove tags 6-9
	TAGKEYS(                        XK_6,                                      5)
	TAGKEYS(                        XK_7,                                      6)
	TAGKEYS(                        XK_8,                                      7)
	TAGKEYS(                        XK_9,                                      8)
	*/
	{ MODKEY|ShiftMask,             XK_q,                      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = app_terminal } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

