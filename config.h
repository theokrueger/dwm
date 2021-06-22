/* See LICENSE file for copyright and license details. */

/* XF86XK binds from https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h */
#define XF86XK_AudioNext        0x1008FF17
#define XF86XK_AudioPrev        0x1008FF16
#define XF86XK_AudioPlay        0x1008FF14
#define XF86XK_AudioRaiseVolume 0x1008FF13
#define XF86XK_AudioLowerVolume 0x1008FF11
#define XF86XK_AudioMute        0x1008FF12

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_pink[]        = "#ff66cc";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_pink },
	[SchemeSel]  = { col_gray4, col_pink,  col_pink  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	/* { "Gimp",     NULL,       NULL,       0,            1,           -1 }, */
    { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
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
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
/* programs */
static const char *termcmd[]     = { "urxvt", NULL };                                                                        // bound to mod-shift-enter
static const char *pmcmd[]       = { "palemoon", NULL };                                                                     // bound to mod-shift-f
static const char *fmcmd[]       = { "pcmanfm", NULL };                                                                      // bound to mod-shift-g
static const char *ccmd[]        = { "code", NULL };                                                                         // bound to mod-shift-m
/* screenshot */
static const char *sscmd[]       = { "escrotum", "/home/theo/Pictures/screenshots/%y-%m-%d-%H%M%S.png", NULL };              // bound to mod-prtsc
static const char *ssscmd[]      = { "escrotum", "-s", "/home/theo/Pictures/screenshots/%y-%m-%d-%H%M%S.png", NULL };        // bound to mod-shift-prtsc
static const char *sssccmd[]     = { "escrotum", "-s", "-C", NULL };                                                         // bound to mod-ctrl-prtsc
static const char *ssrscmd[]     = { "escrotum", "-s", "-r", "/home/theo/Pictures/screenshots/%y-%m-%d-%H%M%S.webm", NULL }; // bound to mod-ctrl-shift-prtsc, stop with ctrl-alt-s
/* media control */
static const char *pctlnextcmd[] = { "playerctl", "next", NULL };                                                            // bound to media next
static const char *pctlprevcmd[] = { "playerctl", "previous", NULL };                                                        // bound to media previous
static const char *pctlppcmd[]   = { "playerctl", "play-pause", NULL };                                                      // bound to media play/pause
static const char *pctluvolcmd[] = { "playerctl", "volume", "0.05+", NULL };                                                 // bound to media volume up
static const char *pctldvolcmd[] = { "playerctl", "volume", "0.05-", NULL };                                                 // bound to media volume down
static const char *mpcmd[]       = { "sayonara", NULL };                                                                     // bound to media volume mute
/* default commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_pink, "-sf", col_gray4, NULL };

static Key keys[] = {
	/* added keys */
	{ MODKEY|ShiftMask,             XK_Return,                 spawn,          {.v = termcmd } },            // spawn urxvt (terminal)
	{ MODKEY|ShiftMask,             XK_f,                      spawn,          {.v = pmcmd } },              // spawn palemoon (browser)
	{ MODKEY|ShiftMask,             XK_g,                      spawn,          {.v = fmcmd } },              // spawn pcmanfm (file manager)
	{ MODKEY|ShiftMask,             XK_m,                      spawn,          {.v = ccmd } },               // spawn editor (code)
	{ MODKEY,                       XK_Print,                  spawn,          {.v = sscmd } },              // take screenshot of main screen (escrotum)
	{ MODKEY|ShiftMask,             XK_Print,                  spawn,          {.v = ssscmd } },             // take screenshot with selection (escrotum)
	{ MODKEY|ControlMask,           XK_Print,                  spawn,          {.v = sssccmd } },            // take screenshot with selection and only copy to clipboard (escrotum)
	{ MODKEY|ControlMask|ShiftMask, XK_Print,                  spawn,          {.v = ssrscmd } },            // record screen selection, stop with ctl ctrl-alt-s (escrotum)
	{ 0,                            XF86XK_AudioNext,          spawn,          {.v = pctlnextcmd } },        // media player next entry (playerctl)
	{ 0,                            XF86XK_AudioPrev,          spawn,          {.v = pctlprevcmd } },        // media player previous entry (playerctl)
	{ 0,                            XF86XK_AudioPlay,          spawn,          {.v = pctlppcmd } },          // media player pause/play (playerctl)
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn,          {.v = pctluvolcmd } },        // media player increase volume by .05 (playerctl)
	{ 0,                            XF86XK_AudioLowerVolume,   spawn,          {.v = pctldvolcmd } },        // media player decrease volume by .05 (playerctl)
	{ 0,                            XF86XK_AudioMute,          spawn,          {.v = mpcmd } },              // spawn sayonara (audio player)
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
	TAGKEYS(                        XK_6,                                      5)
	TAGKEYS(                        XK_7,                                      6)
	TAGKEYS(                        XK_8,                                      7)
	TAGKEYS(                        XK_9,                                      8)
	{ MODKEY|ShiftMask,             XK_q,                      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

