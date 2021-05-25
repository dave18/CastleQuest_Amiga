/* main.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

/* Common Block Declarations */

struct {
    logical debug;
    integer iseed;
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer form[2000]	/* was [100][20] */, form2[1200]	/* was [60][
	    20] */, inst[1000]	/* was [50][20] */, long_[10000]	/* was [400][
	    20] */, hint[1000]	/* was [50][20] */;
} block1_;

#define block1_1 block1_

struct {
    integer savar[400];
} block2_;

#define block2_1 block2_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__421 = 421;
static integer c__428 = 428;
static integer c__417 = 417;
static integer c__429 = 429;
static integer c__402 = 402;
static integer c__414 = 414;
static integer c__415 = 415;
static integer c__416 = 416;
static integer c__422 = 422;
static integer c__418 = 418;
static integer c__425 = 425;
static integer c__419 = 419;
static integer c__420 = 420;
static integer c__412 = 412;
static integer c__602 = 602;
static integer c__426 = 426;
static integer c__850 = 850;
static integer c__851 = 851;
static integer c__852 = 852;
static integer c__853 = 853;
static integer c__854 = 854;


/*     CASTLEQUEST BY MICHAEL S. HOLTZMAN/MARK A. KERSHENBLATT 2/80 */
/*           Modified to run under IBM's CP/CMS, 9/81, by M. Holtzman */

/* -------------------------------------------------------------- */
/*     ITEMS  = LOCATIONS OF THE ITEMS */
/*     VERBS  = LIST OF ALLOWABLE VERBS. */
/*     NOUNS  = LIST OF ALLOWABLE NOUNS. */
/*     ROOM   = CURRENT ROOM */
/*     LROOM  = LAST ROOM */
/*     NUMB   = NUMBER OF ITEMS BEING CARRIED. */
/*     GUN    = STAUS OF GUN (0=NOTHING,1=LOADED) */
/*     LOCK   = 0=LOCKED,1=1ST #,2=2ND #,3=OPEN. */
/*     WIND1  = WINDOW IN ROOM 1 (0=NAILED,1=BROKEN,2=BARRED,3=OPEN) */
/*     DOOR(I)= DOOR IN ROOM I (0=LOCKED,1=CLOSED,2=OPEN) */
/*     SHUTTR = STATUS OF SHUTTER (0=CLOSED, 1=OPEN) */
/*     BUT    = BUTLER(0=SLEEPING,1=AWAKE,2=HOLDING NOTE,3=GONE FOR GOOD, */
/*                     4=DEAD AS A DOORNAIL. */
/*     BAT    = STATUS OF BAT (0=GONE,1=BLOCKING WAY,HUNGRY) */
/*     NOTE   = NUMBER OF NOTE BUTLER IS HOLDING. */
/*     NDEATH = NUMBER OF TIMES PLAYER HAS DIED. */
/*     LAMP   =STATUS OF LAMP (0=OFF,1=ON,2=DIM,3=EMPTY) */
/*     ROPE   = (0=LOOSE,1=TIED TO BED,2=HANGING,-2=GONE,3=TIED TO HOOK) */
/*     VALUE  = POINT VALUE OF FINDING EACH TREASURE. */
/*     HUNCH  = HUNCHBACK(0=HUNGRY,1=FOLLOWING,2=GONE) */
/*     BOTTLE = BOTTLE FILLED? */
/*     BLOOD  = BLOOD IN BOTTLE? */
/*     WATER  = WATER IN BOTTLE? */
/*     MELT   = HOLE MELTED IN ICE? */
/*     HOLE   = CYCLOPS SHAPED HOLE IN DOOR? */
/*     WIZ    = WIZARD STILL AROUND? */
/*     TORCH  = IS TORCH LIT? */
/*     FIRE   = IS FIRE BURNING? */
/*     SUN    = IS SUN UP(0=UP,1=SETTING) */
/*     MASTER = (0=IN COFFIN,1=ASLEEP,2=PINNED,3=UP,4=DEAD) */
/*     LMOVE  = # MOVES WITH  LAMP   LIT. */
/*     MMOVE  = # MOVES WITH MATCHES LIT. */
/*     MATCH  = MATCHES(0=UNLIT,1=LIT,2=GONE) */
/*     SCORE  = ACCUMULATED SCORE. */
/*     MAS1,2,3,4 = MASTER SECTION STATUS (LOGICAL) */
/* -------------------------------------------------------------- */


real rdm_(real* seed)
{
  int r;
  r=rand() % 1000;
  return (real)r/(real)1000.0;
}


/* Main program */ MAIN__()
{
    /* Initialized data */

    static integer nitems = 30;
    static integer leave[100] = { 7,0,0,3,0,0,7,0,0,1,1,0,7,0,3,0,5,0,3,10,0,
	    7,0,0,3,0,0,0,0,0,5,5,5,0,2,0,0,10,0,0,0,9,3,9,1,0,0,0,0,0,6,3,3,
	    0,6,0,0,0,0,0,1,9,9,1,0,0,10,7,1,7,7,3,0,0,1,10,3,0,0,0,0,3,3,0,7,
	    3,7,1,7,0,3,0,0,3,0,0,0,0,7,0 };
    static integer enter[100] = { 0,0,1,0,0,3,0,0,0,0,0,3,10,0,0,0,10,1,0,1,3,
	    0,0,7,0,0,0,7,0,0,0,0,0,0,0,8,0,0,0,0,7,0,0,5,0,0,0,1,0,0,2,0,7,0,
	    0,0,0,0,0,0,19,9,1,1,1,0,7,3,3,0,3,5,0,1,0,0,0,0,7,9,0,3,0,3,0,5,
	    1,0,0,9,1,0,7,0,0,0,0,0,7,0 };
    static integer prev[100] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    static char pw[4+1] = "..  ";

    /* Format strings */
    static char fmt_1001[] = "(\002- Welcome to CASTLEQUEST!! Would you like\
 instructions?\002)";
    static char fmt_6301[] = "(\0020  TOP OF LOOP (STATEMENT 20)\002)";
    static char fmt_1064[] = "(\0020  It is now pitch dark. If you procede y\
ou may stumble and fall.\002)";
    static char fmt_6302[] = "(\0020  NUMBER OF MOVES IS \002,i3)";
    static char fmt_1089[] = "(\0020  You'd better hurry.  The sun is settin\
g.\002)";
    static char fmt_1088[] = "(\0020  Your match has burnt out.\002)";
    static char fmt_1009[] = "(\0020  The lantern seems to be out of fluid\
.\002)";
    static char fmt_1083[] = "(\0020  You're lamp is getting dim.  Perhaps y\
ou\002,/,\002   should look for more fuel.\002)";
    static char fmt_1085[] = "(\0020  I took the liberty of filling the lamp\
 with \002,\002kerosene.\002)";
    static char fmt_6303[] = "(\0020  ABOUT TO CALL \"DES\": II IS \002,i3)";
    static char fmt_1098[] = "(\0020  A copy of Shakespeare's \"HAMLET\" lie\
s on the \002,\002desk.\002)";
    static char fmt_1100[] = "(\0020  A wall of fire bars the way to the NE\
.\002)";
    static char fmt_1110[] = "(\0020  There is a large opening in the grou\
nd.\002)";
    static char fmt_1011[] = "(\0020  A rope is hooked to the top of the pre\
cipice.\002)";
    static char fmt_1116[] = "(\0020  Some ice has melted, leaving a large h\
ole.\002)";
    static char fmt_1117[] = "(\0020  There is a cyclops-shaped hole in the \
door.\002)";
    static char fmt_1118[] = "(\0020  There is a fairly large cyclops starin\
g at you.\002)";
    static char fmt_1119[] = "(\0020  The cyclops turns to you and says:\002\
,/,\002      \"Hey buddy!.  Got a light??\"\002)";
    static char fmt_1128[] = "(\0020  A powerful wizard blocks your way with\
 his staff.\002)";
    static char fmt_1136[] = "(\0020  There is a passable hole in the door\
.\002)";
    static char fmt_1141[] = "(\0020  Your axe is trembling slightly.\002)";
    static char fmt_1145[] = "(\0020  I think I hear footsteps behind you\
.\002)";
    static char fmt_1077[] = "(\0020  You fall in the dark and break your ne\
ck.\002)";
    static char fmt_9501[] = "(\0020  RETURN FROM MOVE: ROOM=\002,i8,\002 LR\
OOM =\002,i8)";
    static char fmt_1019[] = "(\0020  The door is locked.\002)";
    static char fmt_1042[] = "(\0020  The door is closed.\002)";
    static char fmt_1021[] = "(\0020  The door is boarded up.\002)";
    static char fmt_1043[] = "(\0020  You have fallen through a trap door an\
d find...\002)";
    static char fmt_1049[] = "(\0020  A huge vampire bat hangs from the door\
frame\002,\002 and blocks your way.\002)";
    static char fmt_1066[] = "(\0020  A combination lock bars the door.\002)";
    static char fmt_1006[] = "(\0020  There is no way to go in that directio\
n.\002)";
    static char fmt_1101[] = "(\0020  You can't get through the fire.\002)";
    static char fmt_1127[] = "(\0020  Some magical power will not let you pa\
ss.\002)";
    static char fmt_8005[] = "(\0020  SPECIAL MOVE FROM \002,i3,\002 TO \002\
,i3)";
    static char fmt_1081[] = "(\0020  Something you're carrying won't fit in\
to the house.\002)";
    static char fmt_1094[] = "(\0020  Count Vladimir clamps his fangs on you\
r neck!!\002)";
    static char fmt_1012[] = "(\0020  You can't carry anything else.\002)";
    static char fmt_1034[] = "(\0020  The butler is lame, and could not keep\
 up with you.\002)";
    static char fmt_1146[] = "(\0020  What do you want with a heavy, dead bu\
tler?\002)";
    static char fmt_1033[] = "(\0020  Sorry, but you don't have your library\
 card.\002)";
    static char fmt_1045[] = "(\0020  Take note of what??\002)";
    static char fmt_1093[] = "(\0020  It's not a good idea to take a hungry\
 \002,\002hunchback.\002)";
    static char fmt_1003[] = "(\0020  I don't see that here.\002)";
    static char fmt_1074[] = "(\0020  You have nothing to carry it in.\002)";
    static char fmt_1099[] = "(\0020  The bottle is already full.\002)";
    static char fmt_1004[] = "(\0020  You don't have it with you.\002)";
    static char fmt_1112[] = "(\0020  The grappling hook and the rope\002\
,\002 are lying on the ground.\002)";
    static char fmt_1039[] = "(\0020  With what?? Your bare hands??\002)";
    static char fmt_1122[] = "(\0020  The cyclops hurls you against the wa\
ll \002,\002and chuckles quietly.\002)";
    static char fmt_1086[] = "(\0020  A vampire can only be killed with a wo\
oden \002,\002stake.\002)";
    static char fmt_1129[] = "(\0020  The wizard's eyes flare as he raises h\
is staff.\002,/,\002   His awesome magic prevents you from attacking.\002)";
    static char fmt_1061[] = "(\0020  The acid dissolves the bars.  The wind\
ow is clear.\002)";
    static char fmt_1062[] = "(\0020  The werewolf howls in pain and runs aw\
ay.\002)";
    static char fmt_1063[] = "(\0020  The acid has burned a hole in the floo\
r.\002)";
    static char fmt_1071[] = "(\0020  The rope slithers out the window and f\
alls \002,\002out of reach.\002)";
    static char fmt_1070[] = "(\0020  The rope is dangling out the window\
.\002)";
    static char fmt_1072[] = "(\0020  The rope is already out the window.\
\002)";
    static char fmt_1007[] = "(\0020  Load the gun with what?\002)";
    static char fmt_1047[] = "(\0020  You had better watch your mouth.\002)";
    static char fmt_1079[] = "(\0020  You bring it to the height of ecstasy\
.\002)";
    static char fmt_1137[] = "(\0020  The letter \"H\" appears for an instan\
t on the wall.\002)";
    static char fmt_1138[] = "(\0020  A mystical voice says \"OH\".\002)";
    static char fmt_1139[] = "(\0020  The letter \"N\" forms out of mist.\
\002)";
    static char fmt_1140[] = "(\0020  A large \"K\" emerges from the floor\
.\002)";
    static char fmt_1134[] = "(\0020  The walls of the cavern tremble as you\
 unleash the\002,/,\002   terrible power contained in the sword.\002)";
    static char fmt_1135[] = "(\0020  The wizard, sensing a stronger power t\
han his own,\002,/,\002   flees in a blinding flash and a cloud of smoke.\
\002)";
    static char fmt_1095[] = "(\0020  Nothing happens.\002)";
    static char fmt_1055[] = "(\0020  You killed a deaf-mute butler (Not ver\
y sporting\002,\002 of you).\002)";
    static char fmt_1056[] = "(\0020  You just murdered an innocent hunchbac\
k.\002)";
    static char fmt_1123[] = "(\0020  The cyclops flings you across the room\
 and \002,\002laughs hysterically.\002)";
    static char fmt_1060[] = "(\0020  You don't have the sword with you.\002)"
	    ;
    static char fmt_1087[] = "(\0020  The vampire clutches at the stake and \
dies,\002,/,\002   leaving only a pile of dust.\002)";
    static char fmt_1130[] = "(\0020  A note materializes on the wall which \
reads:\002)";
    static char fmt_1131[] = "(\0020  EMERGENCY EXIT--The mirror maze will l\
ead you\002)";
    static char fmt_1132[] = "(\002   to the locked door.  The exit lies wit\
hin.\002)";
    static char fmt_1050[] = "(\0020  Feed the bat with what??\002)";
    static char fmt_1051[] = "(\0020  The bat gulps down the blood and flitt\
ers away.\002)";
    static char fmt_1052[] = "(\0020  Bats don't eat food, they eat blood. L\
ike yours.\002)";
    static char fmt_1090[] = "(\0020  The hunchback gobbles down the food \
and\002,\002 smiles at you.\002)";
    static char fmt_1091[] = "(\0020  Werewolves eat only fresh meat.\002)";
    static char fmt_1092[] = "(\0020  The butler is not allowed to eat.\002)";
    static char fmt_1124[] = "(\0020  Boy are you dumb!  A cyclops doesn't e\
at food.\002)";
    static char fmt_1097[] = "(\0020  You don't have any food.\002)";
    static char fmt_1017[] = "(\0020  YUMMY! That was good.\002)";
    static char fmt_1018[] = "(\0020  GLUG GLUG GLUG GLUG BELCH!!\002)";
    static char fmt_1113[] = "(\0020  INDE--URP--GESTION !!!\002)";
    static char fmt_1104[] = "(\0020  I'm sorry.  I don't have a corkscrew\
.\002)";
    static char fmt_1080[] = "(\0020  Jump from where??\002)";
    static char fmt_1059[] = "(\0020  You swan dive off the tower and drown \
in the moat .\002)";
    static char fmt_1105[] = "(\0020  You plummet headlong into the crashing\
 surf\002)";
    static char fmt_1106[] = "(\002   and are *SPLATTERED* on the rocks belo\
w.\002)";
    static char fmt_1020[] = "(\0020  The door is already open.\002)";
    static char fmt_1125[] = "(\0020  The door is way too heavy for you to m\
ove it.\002)";
    static char fmt_1025[] = "(\0020  I see no door here.\002)";
    static char fmt_1036[] = "(\0020  The door will neither open nor close\
.\002)";
    static char fmt_1022[] = "(\0020  The shutter is open, but there are bar\
s over \002,\002the window.\002)";
    static char fmt_1023[] = "(\0020  The window is nailed shut.\002)";
    static char fmt_1024[] = "(\0020  There is a silver cross in the drawer\
!\002)";
    static char fmt_1026[] = "(\0020  It wouldn't be much of a lock if you c\
ould \002,\002just open it.\002)";
    static char fmt_1027[] = "(\0020  A skeleton key falls out of the book\
.\002)";
    static char fmt_1028[] = "(\0020  A literary classic, but we don't have \
time to read.\002)";
    static char fmt_1031[] = "(\0020  You can't close a broken window.\002)";
    static char fmt_1032[] = "(\0020  I never liked classics, anyway.\002)";
    static char fmt_1067[] = "(\0020  I'm afraid you don't have the key.\002)"
	    ;
    static char fmt_1068[] = "(\0020  Unless you're a safecracker, I suggest\
 you \002,\002use the combination.\002)";
    static char fmt_1121[] = "(\0020  The torch is burning noisily.\002)";
    static char fmt_1075[] = "(\0020  You have nothing to light it with.\002)"
	    ;
    static char fmt_1120[] = "(\0020  The cyclops chokes from the rancid tob\
acco, and\002,/,\002   crashes through the door in search of water.\002)";
    static char fmt_1103[] = "(\0020  The fire smoulders and goes out.\002)";
    static char fmt_1102[] = "(\0020  You don't have any water.\002)";
    static char fmt_9998[] = "(\0020  You made \002,i4,\002 moves, and score\
d \002,i4,\002 points.\002)";
    static char fmt_1041[] = "(\0020  The door can now be opened.\002)";
    static char fmt_1040[] = "(\0020  You just broke every bone in your ha\
nd.\002,/,\002   You might try an axe or something....\002)";
    static char fmt_1046[] = "(\0020  The window IS already broken.\002)";
    static char fmt_1048[] = "(\0020  The mirrors shatter in an explosion of\
 flying glass.\002)";
    static char fmt_1084[] = "(\0020  You are not strong enough to break it\
.\002)";
    static char fmt_1111[] = "(\0020  It is out of reach.\002)";
    static char fmt_1035[] = "(\0020  You can't get back the way you came\
.\002)";
    static char fmt_1076[] = "(\0020  I hate to tell you this, but I can't s\
wim.\002)";
    static char fmt_1082[] = "(\0020  You dont have a boat to cross in.\002)";
    static char fmt_1142[] = "(\0020  The ceiling begins to vibrate and crum\
bles,\002,/,\002   crushing you under tons of concrete.\002)";
    static char fmt_1143[] = "(\0020  The floor erupts violently, swallowing\
 you\002,\002 in a sea of molten lava.\002)";
    static char fmt_1069[] = "(\0020  The rope is anchored securely to the b\
ed.\002)";
    static char fmt_1010[] = "(\0020  The rope is tied securely to the grapp\
ling hook.\002)";
    static char fmt_1029[] = "(\0020  \"The master loves Shakespeare\".\002)";
    static char fmt_1030[] = "(\0020  \"Look behind the mirror.\"\002)";
    static char fmt_1114[] = "(\0020  THAT IS A PRIVILEGED INSTRUCTION.\002)";
    static char fmt_1015[] = "(\0020  The lock is now open.\002)";
    static char fmt_1013[] = "(\0020  I don't know how to apply that here\
.\002)";
    static char fmt_1014[] = "(\0020  You blew it. I think you'd better star\
t over.\002)";
    static char fmt_1054[] = "(\0020  Unfortunately the gun is not loaded\
.\002)";
    static char fmt_1053[] = "(\0020  You killed a werewolf. An old gypsy wo\
man\002,/,\002   appears and drags away the body.\002)";
    static char fmt_1058[] = "(\0020  The bullet does not penetrate the bat'\
s thick hide.\002)";
    static char fmt_1057[] = "(\0020  There is nothing here to shoot.\002)";
    static char fmt_1126[] = "(\0020  The cyclops does not even feel the imp\
act of \002,\002the bullet.\002)";
    static char fmt_1065[] = "(\0020  Your bullet misses.\002)";
    static char fmt_1044[] = "(\0020  The butler cannot be aroused.\002)";
    static char fmt_7101[] = "(\0020  ENTER THE PASSWORD:\002)";
    static char fmt_7102[] = "(a4)";
    static char fmt_1073[] = "(\0020  OK, from now on I will give only short\
 descriptions.\002)";
    static char fmt_1002[] = "(\0020  That would be a neat trick.\002)";
    static char fmt_1037[] = "(\0020  The light is out.\002)";
    static char fmt_1038[] = "(\0020  The light is burning dimly.\002)";
    static char fmt_1016[] = "(\0020  You can't be serious.\002)";
    static char fmt_1005[] = "(\0020  I don't think I can do that.\002)";
    static char fmt_1096[] = "(\0020  You already have it.\002)";
    static char fmt_1107[] = "(\0020  The gnome is very nimble and dodges ou\
t of \002,\002your reach.\002)";
    static char fmt_1133[] = "(\0020  The wizard raises his staff. You ar\
e\002,\002 blinded by a sudden explosion of light.\002)";
    static char fmt_1144[] = "(\0020  The glacier begins to melt in a torren\
tial flood,\002,/,\002   and swallows you in a sea of icy cold water.\002)";
    static char fmt_1109[] = "(\0020  You missed him, JERK!!\002)";
    static char fmt_1108[] = "(\0020  You killed a dirty little gnome.\002)";
    static char fmt_1008[] = "(\0020  OK\002)";
    static char fmt_9997[] = "(\0020  You scored \002,i4,\002 out of \002,\
i4,\002 points.\002)";
    static char fmt_7001[] = "(\0020  This qualifies you as a \"CLASS A\" MA\
STER!\002)";
    static char fmt_7002[] = "(\0020  You are a MASTER at CASTLEQUEST.\002)";
    static char fmt_7003[] = "(\0020  You receive an EXPERT rating for your \
effort.\002)";
    static char fmt_7004[] = "(\0020  You rate as a NOVICE EXPLORER for this\
 game.\002)";
    static char fmt_7005[] = "(\0020  You are a GREENHORN at this game!!\002)"
	    ;
    static char fmt_7006[] = "(\0020  You don't deserve to WALK THE EARTH!\
!\002)";

    /* System generated locals */
    integer i__1;
    static integer equiv_0[2];

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio(), s_rsfe(), e_rsfe(), s_cmp();
    /* Subroutine */ int s_stop();

    /* Local variables */
    static real seed;
#define fire ((logical *)&block2_1 + 84)
#define hole ((logical *)&block2_1 + 206)
    extern /* Subroutine */ int help_();
#define lamp ((integer *)&block2_1 + 97)
#define prec ((logical *)&block2_1 + 85)
    extern integer isig_();
    static integer lock;
    static logical save;
#define numb ((integer *)&block2_1 + 94)
#define door ((integer *)&block2_1 + 100)
#define wher ((integer *)&block2_1 + 70)
#define rope ((integer *)&block2_1 + 66)
#define note ((integer *)&block2_1 + 95)
#define wolf ((logical *)&block2_1 + 205)
#define melt ((logical *)&block2_1 + 207)
    extern /* Subroutine */ int init_();
#define room ((integer *)&block2_1 + 60)
    extern /* Subroutine */ int move_(), yorn_();
#define wind1 ((integer *)&block2_1 + 86)
#define wind2 ((integer *)&block2_1 + 87)
    static integer i, j, k, l;
    static real brief;
#define match ((integer *)&block2_1 + 68)
#define blood ((logical *)&block2_1 + 90)
#define hunch ((integer *)&block2_1 + 67)
#define gnome ((logical *)&block2_1 + 204)
#define score ((integer *)&block2_1 + 88)
#define value ((integer *)&block2_1 + 30)
#define ipass ((integer *)&block2_1 + 96)
#define torch ((logical *)&block2_1 + 208)
#define items ((integer *)&block2_1)
#define lmove ((integer *)&block2_1 + 99)
#define mmove ((integer *)&block2_1 + 98)
#define water ((logical *)&block2_1 + 92)
#define lroom ((integer *)&block2_1 + 61)
    extern /* Subroutine */ int wwolf_(), input_();
    static char ca[4];
    static integer ii, jj;
#define ibrief ((integer *)&block2_1 + 203)
#define ndeath ((integer *)&block2_1 + 200)
#define object (equiv_0 + 1)
    static integer maxabs;
#define masect ((logical *)&block2_1 + 210)
#define action (equiv_0)
    extern /* Subroutine */ int ggnome_(), adscor_();
#define lokval ((integer *)&block2_1 + 81)
#define bottle ((logical *)&block2_1 + 91)
#define master ((integer *)&block2_1 + 69)
#define butval ((integer *)&block2_1 + 82)
#define maxscr ((integer *)&block2_1 + 202)
#define notval ((integer *)&block2_1 + 80)
#define ropval ((integer *)&block2_1 + 83)
    extern /* Subroutine */ int invent_(), savres_();
#define numove ((integer *)&block2_1 + 89)
#define shuttr ((integer *)&block2_1 + 65)
#define bat ((logical *)&block2_1 + 63)
    extern /* Subroutine */ int obj_(), des_();
    //extern doublereal rdm_();
    static real val;
#define max_ ((integer *)&block2_1 + 201)
#define gun ((logical *)&block2_1 + 62)
#define but ((integer *)&block2_1 + 64)
#define sun ((integer *)&block2_1 + 93)
#define wiz ((logical *)&block2_1 + 209)
#define mas1 ((logical *)&block2_1 + 211)
#define mas2 ((logical *)&block2_1 + 212)
#define mas3 ((logical *)&block2_1 + 213)
#define mas4 ((logical *)&block2_1 + 214)

    /* Fortran I/O blocks */
    static cilist io___64 = { 0, 6, 0, fmt_1001, 0 };
    static cilist io___66 = { 0, 6, 0, fmt_6301, 0 };
    static cilist io___67 = { 0, 6, 0, fmt_1064, 0 };
    static cilist io___68 = { 0, 6, 0, fmt_6302, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_1089, 0 };
    static cilist io___70 = { 0, 6, 0, fmt_1088, 0 };
    static cilist io___71 = { 0, 6, 0, fmt_1009, 0 };
    static cilist io___72 = { 0, 6, 0, fmt_1064, 0 };
    static cilist io___73 = { 0, 6, 0, fmt_1083, 0 };
    static cilist io___74 = { 0, 6, 0, fmt_1085, 0 };
    static cilist io___75 = { 0, 6, 0, fmt_6303, 0 };
    static cilist io___76 = { 0, 6, 0, fmt_1098, 0 };
    static cilist io___77 = { 0, 6, 0, fmt_1100, 0 };
    static cilist io___78 = { 0, 6, 0, fmt_1110, 0 };
    static cilist io___79 = { 0, 6, 0, fmt_1011, 0 };
    static cilist io___80 = { 0, 6, 0, fmt_1116, 0 };
    static cilist io___81 = { 0, 6, 0, fmt_1117, 0 };
    static cilist io___82 = { 0, 6, 0, fmt_1118, 0 };
    static cilist io___83 = { 0, 6, 0, fmt_1119, 0 };
    static cilist io___84 = { 0, 6, 0, fmt_1128, 0 };
    static cilist io___85 = { 0, 6, 0, fmt_1136, 0 };
    static cilist io___86 = { 0, 6, 0, fmt_1141, 0 };
    static cilist io___87 = { 0, 6, 0, fmt_1145, 0 };
    static cilist io___89 = { 0, 6, 0, fmt_1077, 0 };
    static cilist io___90 = { 0, 6, 0, fmt_9501, 0 };
    static cilist io___91 = { 0, 6, 0, fmt_1019, 0 };
    static cilist io___92 = { 0, 6, 0, fmt_1042, 0 };
    static cilist io___93 = { 0, 6, 0, fmt_1021, 0 };
    static cilist io___94 = { 0, 6, 0, fmt_1042, 0 };
    static cilist io___95 = { 0, 6, 0, fmt_1043, 0 };
    static cilist io___96 = { 0, 6, 0, fmt_1049, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_1066, 0 };
    static cilist io___99 = { 0, 6, 0, fmt_1006, 0 };
    static cilist io___100 = { 0, 6, 0, fmt_1006, 0 };
    static cilist io___101 = { 0, 6, 0, fmt_1101, 0 };
    static cilist io___103 = { 0, 6, 0, fmt_1042, 0 };
    static cilist io___104 = { 0, 6, 0, fmt_1127, 0 };
    static cilist io___105 = { 0, 6, 0, fmt_1128, 0 };
    static cilist io___106 = { 0, 6, 0, fmt_8005, 0 };
    static cilist io___107 = { 0, 6, 0, fmt_1006, 0 };
    static cilist io___108 = { 0, 6, 0, fmt_1081, 0 };
    static cilist io___109 = { 0, 6, 0, fmt_1094, 0 };
    static cilist io___110 = { 0, 6, 0, fmt_1012, 0 };
    static cilist io___111 = { 0, 6, 0, fmt_1034, 0 };
    static cilist io___112 = { 0, 6, 0, fmt_1146, 0 };
    static cilist io___113 = { 0, 6, 0, fmt_1033, 0 };
    static cilist io___114 = { 0, 6, 0, fmt_1045, 0 };
    static cilist io___115 = { 0, 6, 0, fmt_1093, 0 };
    static cilist io___116 = { 0, 6, 0, fmt_1003, 0 };
    static cilist io___117 = { 0, 6, 0, fmt_1012, 0 };
    static cilist io___118 = { 0, 6, 0, fmt_1074, 0 };
    static cilist io___119 = { 0, 6, 0, fmt_1099, 0 };
    static cilist io___120 = { 0, 6, 0, fmt_1004, 0 };
    static cilist io___121 = { 0, 6, 0, fmt_1112, 0 };
    static cilist io___122 = { 0, 6, 0, fmt_1011, 0 };
    static cilist io___123 = { 0, 6, 0, fmt_1039, 0 };
    static cilist io___124 = { 0, 6, 0, fmt_1039, 0 };
    static cilist io___125 = { 0, 6, 0, fmt_1122, 0 };
    static cilist io___126 = { 0, 6, 0, fmt_1039, 0 };
    static cilist io___127 = { 0, 6, 0, fmt_1086, 0 };
    static cilist io___128 = { 0, 6, 0, fmt_1129, 0 };
    static cilist io___129 = { 0, 6, 0, fmt_1061, 0 };
    static cilist io___130 = { 0, 6, 0, fmt_1062, 0 };
    static cilist io___131 = { 0, 6, 0, fmt_1061, 0 };
    static cilist io___132 = { 0, 6, 0, fmt_1063, 0 };
    static cilist io___133 = { 0, 6, 0, fmt_1071, 0 };
    static cilist io___134 = { 0, 6, 0, fmt_1070, 0 };
    static cilist io___135 = { 0, 6, 0, fmt_1072, 0 };
    static cilist io___136 = { 0, 6, 0, fmt_1011, 0 };
    static cilist io___137 = { 0, 6, 0, fmt_1119, 0 };
    static cilist io___138 = { 0, 6, 0, fmt_1007, 0 };
    static cilist io___139 = { 0, 6, 0, fmt_1047, 0 };
    static cilist io___140 = { 0, 6, 0, fmt_1079, 0 };
    static cilist io___141 = { 0, 6, 0, fmt_1137, 0 };
    static cilist io___142 = { 0, 6, 0, fmt_1138, 0 };
    static cilist io___143 = { 0, 6, 0, fmt_1139, 0 };
    static cilist io___144 = { 0, 6, 0, fmt_1140, 0 };
    static cilist io___145 = { 0, 6, 0, fmt_1134, 0 };
    static cilist io___146 = { 0, 6, 0, fmt_1135, 0 };
    static cilist io___147 = { 0, 6, 0, fmt_1095, 0 };
    static cilist io___148 = { 0, 6, 0, fmt_1055, 0 };
    static cilist io___149 = { 0, 6, 0, fmt_1056, 0 };
    static cilist io___150 = { 0, 6, 0, fmt_1123, 0 };
    static cilist io___151 = { 0, 6, 0, fmt_1060, 0 };
    static cilist io___152 = { 0, 6, 0, fmt_1087, 0 };
    static cilist io___153 = { 0, 6, 0, fmt_1130, 0 };
    static cilist io___154 = { 0, 6, 0, fmt_1131, 0 };
    static cilist io___155 = { 0, 6, 0, fmt_1132, 0 };
    static cilist io___156 = { 0, 6, 0, fmt_1086, 0 };
    static cilist io___157 = { 0, 6, 0, fmt_1050, 0 };
    static cilist io___158 = { 0, 6, 0, fmt_1051, 0 };
    static cilist io___159 = { 0, 6, 0, fmt_1052, 0 };
    static cilist io___160 = { 0, 6, 0, fmt_1090, 0 };
    static cilist io___161 = { 0, 6, 0, fmt_1091, 0 };
    static cilist io___162 = { 0, 6, 0, fmt_1092, 0 };
    static cilist io___163 = { 0, 6, 0, fmt_1124, 0 };
    static cilist io___164 = { 0, 6, 0, fmt_1097, 0 };
    static cilist io___165 = { 0, 6, 0, fmt_1017, 0 };
    static cilist io___166 = { 0, 6, 0, fmt_1018, 0 };
    static cilist io___167 = { 0, 6, 0, fmt_1113, 0 };
    static cilist io___168 = { 0, 6, 0, fmt_1104, 0 };
    static cilist io___169 = { 0, 6, 0, fmt_1080, 0 };
    static cilist io___170 = { 0, 6, 0, fmt_1059, 0 };
    static cilist io___171 = { 0, 6, 0, fmt_1105, 0 };
    static cilist io___172 = { 0, 6, 0, fmt_1106, 0 };
    static cilist io___173 = { 0, 6, 0, fmt_1019, 0 };
    static cilist io___174 = { 0, 6, 0, fmt_1020, 0 };
    static cilist io___175 = { 0, 6, 0, fmt_1125, 0 };
    static cilist io___176 = { 0, 6, 0, fmt_1021, 0 };
    static cilist io___177 = { 0, 6, 0, fmt_1020, 0 };
    static cilist io___178 = { 0, 6, 0, fmt_1025, 0 };
    static cilist io___179 = { 0, 6, 0, fmt_1036, 0 };
    static cilist io___180 = { 0, 6, 0, fmt_1022, 0 };
    static cilist io___181 = { 0, 6, 0, fmt_1023, 0 };
    static cilist io___182 = { 0, 6, 0, fmt_1024, 0 };
    static cilist io___183 = { 0, 6, 0, fmt_1026, 0 };
    static cilist io___184 = { 0, 6, 0, fmt_1027, 0 };
    static cilist io___185 = { 0, 6, 0, fmt_1028, 0 };
    static cilist io___186 = { 0, 6, 0, fmt_1031, 0 };
    static cilist io___187 = { 0, 6, 0, fmt_1031, 0 };
    static cilist io___188 = { 0, 6, 0, fmt_1032, 0 };
    static cilist io___189 = { 0, 6, 0, fmt_1019, 0 };
    static cilist io___190 = { 0, 6, 0, fmt_1067, 0 };
    static cilist io___191 = { 0, 6, 0, fmt_1068, 0 };
    static cilist io___192 = { 0, 6, 0, fmt_1009, 0 };
    static cilist io___193 = { 0, 6, 0, fmt_1121, 0 };
    static cilist io___194 = { 0, 6, 0, fmt_1075, 0 };
    static cilist io___195 = { 0, 6, 0, fmt_1120, 0 };
    static cilist io___196 = { 0, 6, 0, fmt_1117, 0 };
    static cilist io___197 = { 0, 6, 0, fmt_1103, 0 };
    static cilist io___198 = { 0, 6, 0, fmt_1102, 0 };
    static cilist io___199 = { 0, 6, 0, fmt_9998, 0 };
    static cilist io___200 = { 0, 6, 0, fmt_1041, 0 };
    static cilist io___201 = { 0, 6, 0, fmt_1039, 0 };
    static cilist io___202 = { 0, 6, 0, fmt_1040, 0 };
    static cilist io___203 = { 0, 6, 0, fmt_1046, 0 };
    static cilist io___204 = { 0, 6, 0, fmt_1046, 0 };
    static cilist io___205 = { 0, 6, 0, fmt_1048, 0 };
    static cilist io___206 = { 0, 6, 0, fmt_1084, 0 };
    static cilist io___207 = { 0, 6, 0, fmt_1111, 0 };
    static cilist io___208 = { 0, 6, 0, fmt_1035, 0 };
    static cilist io___210 = { 0, 6, 0, fmt_1076, 0 };
    static cilist io___211 = { 0, 6, 0, fmt_1116, 0 };
    static cilist io___212 = { 0, 6, 0, fmt_1082, 0 };
    static cilist io___214 = { 0, 6, 0, fmt_1142, 0 };
    static cilist io___215 = { 0, 6, 0, fmt_1143, 0 };
    static cilist io___216 = { 0, 6, 0, fmt_1069, 0 };
    static cilist io___217 = { 0, 6, 0, fmt_1010, 0 };
    static cilist io___218 = { 0, 6, 0, fmt_1071, 0 };
    static cilist io___219 = { 0, 6, 0, fmt_1071, 0 };
    static cilist io___220 = { 0, 6, 0, fmt_1029, 0 };
    static cilist io___221 = { 0, 6, 0, fmt_1030, 0 };
    static cilist io___222 = { 0, 6, 0, fmt_1114, 0 };
    static cilist io___223 = { 0, 6, 0, fmt_1015, 0 };
    static cilist io___224 = { 0, 6, 0, fmt_1013, 0 };
    static cilist io___225 = { 0, 6, 0, fmt_1014, 0 };
    static cilist io___226 = { 0, 6, 0, fmt_1054, 0 };
    static cilist io___227 = { 0, 6, 0, fmt_1053, 0 };
    static cilist io___228 = { 0, 6, 0, fmt_1055, 0 };
    static cilist io___229 = { 0, 6, 0, fmt_1058, 0 };
    static cilist io___230 = { 0, 6, 0, fmt_1057, 0 };
    static cilist io___231 = { 0, 6, 0, fmt_1126, 0 };
    static cilist io___232 = { 0, 6, 0, fmt_1065, 0 };
    static cilist io___233 = { 0, 6, 0, fmt_1044, 0 };
    static cilist io___234 = { 0, 6, 0, fmt_7101, 0 };
    static cilist io___235 = { 0, 6, 0, fmt_7102, 0 };
    static cilist io___237 = { 0, 6, 0, fmt_1073, 0 };
    static cilist io___238 = { 0, 6, 0, fmt_1002, 0 };
    static cilist io___239 = { 0, 6, 0, fmt_1037, 0 };
    static cilist io___240 = { 0, 6, 0, fmt_1064, 0 };
    static cilist io___241 = { 0, 6, 0, fmt_1038, 0 };
    static cilist io___242 = { 0, 6, 0, fmt_1004, 0 };
    static cilist io___243 = { 0, 6, 0, fmt_1016, 0 };
    static cilist io___244 = { 0, 6, 0, fmt_1005, 0 };
    static cilist io___245 = { 0, 6, 0, fmt_1096, 0 };
    static cilist io___246 = { 0, 6, 0, fmt_1107, 0 };
    static cilist io___247 = { 0, 6, 0, fmt_1133, 0 };
    static cilist io___248 = { 0, 6, 0, fmt_1136, 0 };
    static cilist io___249 = { 0, 6, 0, fmt_1144, 0 };
    static cilist io___251 = { 0, 6, 0, fmt_1109, 0 };
    static cilist io___252 = { 0, 6, 0, fmt_1108, 0 };
    static cilist io___253 = { 0, 6, 0, fmt_1108, 0 };
    static cilist io___254 = { 0, 6, 0, fmt_1008, 0 };
    static cilist io___255 = { 0, 6, 0, fmt_9998, 0 };
    static cilist io___256 = { 0, 6, 0, fmt_9997, 0 };
    static cilist io___257 = { 0, 6, 0, fmt_7001, 0 };
    static cilist io___259 = { 0, 6, 0, fmt_7002, 0 };
    static cilist io___261 = { 0, 6, 0, fmt_7003, 0 };
    static cilist io___262 = { 0, 6, 0, fmt_7004, 0 };
    static cilist io___263 = { 0, 6, 0, fmt_7005, 0 };
    static cilist io___264 = { 0, 6, 0, fmt_7006, 0 };





/*     INTEGER PARLEN,PARMAX/25/,NUMCOM/0/ */
/*     INTEGER SIGID,AWCC/'AWCC'/,A6L2/'A6L2'/,A3TB/'A3TB'/ */













    init_();
    seed = (real) _BLNK__1.iseed;

    _BLNK__1.debug=1;

    srand(time(0));

    save = FALSE_;
    maxabs = *maxscr;
/* *** */
/* omment out the parameter fetch and check code: */
/*     CALL PAR(PARSTG,PARLEN,PARMAX,1,1) */
/*     DO 2 JJ=1,PARLEN */
/*        IF(EQUC(PARSTG(JJ),COMMA)) NUMCOM=NUMCOM+1 */
/*        IF(EQUC(PARSTG(JJ),COMMA)) GOTO 2 */
/*        GOTO(7,9),NUMCOM */
/*        PAR1(JJ)=PARSTG(JJ) */
/*        GOTO 2 */
/* 7      CONTINUE */
/*        PAR2(JJ=FLAG)=PARSTG(JJ) */
/*        GOTO 2 */
/* 9   CONTINUE */
/*        PAR3(JJ=FLAG)=PARSTG(JJ) */
/* 2   CONTINUE */
/*     IF(LCOMC(4,PAR1(1),DEBU(1)) .EQ.0.OR. */
/*    1LCOMC(4,PAR2(1),DEBU(1)) .EQ. 0 .OR. */
/*    2LCOMC(4,PAR3(1),DEBU(1)) .EQ. 0) DEBUG=.TRUE. */
/*     IF(LCOMC(4,PAR1(1),REST(1)) .EQ. 0.OR. */
/*    1LCOMC(4,PAR2(1),REST(1)) .EQ.0 .OR. */
/*    2LCOMC(4,PAR3(1),REST(1)) .EQ.0) GOTO 158 */
/* ***** */

/* L1: */
    s_wsfe(&io___64);
    e_wsfe();
    yorn_(&ii);
    if (ii == 0) {
	goto L10;
    }
    help_(&c__0, room);
L10:


L20:
    if (_BLNK__1.debug) {
	s_wsfe(&io___66);
	e_wsfe();
    }

    if (*room <= 40 || *room >= 95 || (*lamp == 1 || *lamp == 2) && (items[20]
	     == -1 || items[20] == *room) || *match == 1 && (items[14] == -1 
	    || items[14] == *room)) {
	goto L22;
    }
    s_wsfe(&io___67);
    e_wsfe();
    goto L25;
L22:
    ++(*numove);
    if (_BLNK__1.debug) {
	s_wsfe(&io___68);
	do_fio(&c__1, (char *)&(*numove), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (items[7] >= 57 && items[7] <= 64) {
	items[7] = (integer) (rdm_(&seed) * (float)7. + (float)57.);
    }
    if (*numove > 100 && *sun == 0 && *master < 4) {
	s_wsfe(&io___69);
	e_wsfe();
    }
    if (*numove > 100) {
	*sun = 1;
    }
    if (*match != 1) {
	goto L404;
    }
    ++(*mmove);
    if (*mmove < 10) {
	goto L404;
    }
    *match = 2;
    if (items[14] == -1) {
	--(*numb);
    }
    items[14] = 0;
    s_wsfe(&io___70);
    e_wsfe();
/* heck to see if glacier is melted yet, and if cyclops has crashed */
/* through the door yet. (These both require the match). If not, decrease 
*/
/*  MAX because match is needed to get them.  (MAX determines when */
/*  the player has found everything). */
    if (! (*hole)) {
	*max_ += -10;
    }
    if (! (*melt)) {
	*max_ += -10;
    }
    goto L20;
L404:
    if (*lamp == 0 || *lamp == 3) {
	goto L410;
    }
    ++(*lmove);
    if (*lmove < 75) {
	goto L410;
    }
    if (*lmove != 100) {
	goto L405;
    }
    *lamp = 3;
    s_wsfe(&io___71);
    e_wsfe();
    s_wsfe(&io___72);
    e_wsfe();
    goto L25;
L405:
    if (*lmove != 75) {
	goto L410;
    }
    *lamp = 2;
    s_wsfe(&io___73);
    e_wsfe();
    if (items[0] != -1 || items[20] != -1) {
	goto L410;
    }
    s_wsfe(&io___74);
    e_wsfe();
    items[0] = 0;
    --(*numb);
    *lmove = -75;
    *lamp = 1;
L410:
    ii = *room + isig_(&prev[*room - 1]) * 200;
    if (_BLNK__1.debug) {
	s_wsfe(&io___75);
	do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    des_(&ii);
    if (items[7] == -1) {
	des_(&c__421);
    }
    if (*room == 100) {
	goto L9100;
    }
/* L23: */
/*     ...SPECIAL ROOM CONDITIONS... */
    ii = 0;
    if (*room != 8) {
	goto L501;
    }
    ii = *but + 400;
    goto L550;
L501:
    if (*room != 1) {
	goto L505;
    }
    if (*shuttr == 0) {
	goto L502;
    }
    ii = *wind1 + 405;
    des_(&ii);
    if (items[16] == 29) {
	des_(&c__428);
    }
    ii = 0;
    goto L504;
L502:
    des_(&c__417);
L504:
    if (*rope == 2) {
	ii = 413;
    }
    goto L550;
L505:
    if (*room != 10) {
	goto L507;
    }
    ii = *wind2 + 405;
    goto L550;
L507:
    if (*room != 13 && *room != 17) {
	goto L509;
    }
    if (*room == 13) {
	s_wsfe(&io___76);
	e_wsfe();
    }
    ii = *ipass * 412;
    goto L550;
L509:
    if (*room != 29) {
	goto L511;
    }
    if (*rope != 2) {
	goto L511;
    }
    ii = 413;
L511:
    if (*room != 43) {
	goto L513;
    }
    ii = *master + 423;
L513:
    if (*room != 47) {
	goto L515;
    }
    if (*fire) {
	s_wsfe(&io___77);
	e_wsfe();
    }
    goto L550;
L515:
    if (*room != 40) {
	goto L517;
    }
    if (door[79] == 2) {
	s_wsfe(&io___78);
	e_wsfe();
    }
    goto L551;
L517:
    if (*room != 83 && *room != 84) {
	goto L519;
    }
    if (*prec) {
	s_wsfe(&io___79);
	e_wsfe();
    }
    goto L550;
L519:
    if (*room != 65) {
	goto L521;
    }
    if (*melt) {
	s_wsfe(&io___80);
	e_wsfe();
    }
    goto L550;
L521:
/*      ...CYCLOPS IN ROOM... */
    if (*room != 86) {
	goto L523;
    }
    if (*hole) {
	s_wsfe(&io___81);
	e_wsfe();
    }
    if (! (*hole) && items[26] != -3) {
	s_wsfe(&io___82);
	e_wsfe();
    }
    if (! (*hole) && items[26] == -3) {
	s_wsfe(&io___83);
	e_wsfe();
    }
    goto L550;
L523:
    if (*room != 93) {
	goto L525;
    }
    if (*wiz) {
	s_wsfe(&io___84);
	e_wsfe();
    }
    goto L550;
L525:
    if (*room != 99) {
	goto L527;
    }
    if (*masect) {
	s_wsfe(&io___85);
	e_wsfe();
    }
    goto L550;
L527:
    if (items[3] > -2) {
	*note = 1;
    }
/* L549: */
    if (*room <= 90 || *room >= 94) {
	goto L550;
    }
    if (items[11] != -1 || ! (*wiz)) {
	goto L550;
    }
    i__1 = *room + 318;
    des_(&i__1);
L550:
    if (ii == 0) {
	goto L551;
    }
    des_(&ii);
L551:
    if (*room <= 99 && *room >= 95 && items[2] == -1) {
	s_wsfe(&io___86);
	e_wsfe();
    }
    ii = 0;
    obj_(items, room, score, value);
    if (*numove > 15 && (*room <= 25 && *room >= 4) || *wolf) {
	wwolf_(&ii, wolf);
    }
    if (*room >= 45 && *room <= 92 || *gnome) {
	ggnome_(&ii, gnome);
    }
    if (ii > 0) {
	goto L902;
    }
    if (! (*wolf) || items[7] != -1) {
	goto L24;
    }
    des_(&c__429);
    *hunch = 2;
    items[7] = 0;
    *wolf = FALSE_;
    --(*numb);
L24:
    if (rdm_(&seed) < (float).008) {
	s_wsfe(&io___87);
	e_wsfe();
    }
L25:
    input_(action);

/*     BRANCH DEPENDING ON VERB READ. */

    j = action[0];
L26:
    switch ((int)j) {
	case 1:  goto L101;
	case 2:  goto L101;
	case 3:  goto L101;
	case 4:  goto L101;
	case 5:  goto L101;
	case 6:  goto L101;
	case 7:  goto L101;
	case 8:  goto L101;
	case 9:  goto L101;
	case 10:  goto L101;
	case 11:  goto L111;
	case 12:  goto L112;
	case 13:  goto L113;
	case 14:  goto L114;
	case 15:  goto L115;
	case 16:  goto L116;
	case 17:  goto L117;
	case 18:  goto L118;
	case 19:  goto L119;
	case 20:  goto L120;
	case 21:  goto L121;
	case 22:  goto L122;
	case 23:  goto L123;
	case 24:  goto L124;
	case 25:  goto L125;
	case 26:  goto L126;
	case 27:  goto L127;
	case 28:  goto L128;
	case 29:  goto L129;
	case 30:  goto L130;
	case 31:  goto L131;
	case 32:  goto L132;
	case 33:  goto L133;
	case 34:  goto L134;
	case 35:  goto L135;
	case 36:  goto L136;
	case 37:  goto L137;
	case 38:  goto L138;
	case 39:  goto L139;
	case 40:  goto L140;
	case 41:  goto L141;
	case 42:  goto L142;
	case 43:  goto L143;
	case 44:  goto L144;
	case 45:  goto L145;
	case 46:  goto L146;
	case 47:  goto L147;
	case 48:  goto L148;
	case 49:  goto L149;
	case 50:  goto L150;
	case 51:  goto L151;
	case 52:  goto L152;
	case 53:  goto L153;
	case 54:  goto L154;
	case 55:  goto L155;
	case 56:  goto L156;
	case 57:  goto L157;
	case 58:  goto L158;
	case 59:  goto L159;
	case 60:  goto L160;
	case 61:  goto L161;
    }

L101:
    if (*room <= 40 || *room >= 95 || (*lamp == 1 || *lamp == 2) && (items[20]
	     == *room || items[20] == -1)) {
	goto L420;
    }
    if ((items[14] == -1 || items[14] == *room) && *match == 1) {
	goto L420;
    }
    s_wsfe(&io___89);
    e_wsfe();
    goto L902;
L420:
    ii = *lroom;
    *lroom = *room;
    move_(room, &j);
/* L428: */
    if (_BLNK__1.debug) {
	s_wsfe(&io___90);
	do_fio(&c__1, (char *)&(*room), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*lroom), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*room >= 57 && *room <= 64) {
	*lroom = (integer) (rdm_(&seed) * (float)6. + (float)58.);
    }
    if (*room >= 0) {
	goto L102;
    }
    *room = -(*room);
    if (*room <= 0) {
	*room = 0;
    }
    if (*room == 0) {
	goto L102;
    }
    if ((*lroom != 2 || *room != 4) && (*lroom != 4 || *room != 2)) {
	goto L601;
    }
    if (door[1] >= 2) {
	goto L103;
    }
    if (door[1] == 0) {
	s_wsfe(&io___91);
	e_wsfe();
    }
    if (door[1] == 1) {
	s_wsfe(&io___92);
	e_wsfe();
    }
    goto L106;
L601:
/*     ...KITCHEN... */
    if (*room != 7) {
	goto L605;
    }
    if (door[5] == 2) {
	goto L103;
    }
    if (door[5] == 0) {
	s_wsfe(&io___93);
	e_wsfe();
    }
    if (door[5] == 1) {
	s_wsfe(&io___94);
	e_wsfe();
    }
    goto L106;
L605:
/*     ...SECRET PASSAGE... */
    if ((*room != 13 || *lroom != 17) && (*room != 17 || *lroom != 13)) {
	goto L609;
    }
    if (*ipass == 0) {
	*room = 0;
    }
    goto L102;
L609:
/*     ...TRAP DOOR... */
    if (*room != 2 || *lroom != 3) {
	goto L613;
    }
    if (items[3] != -1) {
	goto L103;
    }
    *room = 16;
    *lroom = 0;
    s_wsfe(&io___95);
    e_wsfe();
    goto L103;
L613:
/*     ...ATTIC... */
    if ((*room != 21 || *lroom != 20) && (*room != 20 || *lroom != 21)) {
	goto L615;
    }
    if (! (*bat)) {
	goto L103;
    }
    s_wsfe(&io___96);
    e_wsfe();
    goto L106;
L615:
/*     ...COMBINATION LOCK... */
    if (*room != 23 || *lroom != 21) {
	goto L617;
    }
    if (lock == 3) {
	goto L103;
    }
    s_wsfe(&io___98);
    e_wsfe();
    goto L106;
L617:
/*     ...MIRROR ROOM... */
    if (*lroom != 27) {
	goto L619;
    }
    if (rdm_(&seed) < (float).2) {
	goto L618;
    }
    *room = 27;
    *lroom = 27;
    prev[*room - 1] = 1;
    goto L20;
L618:
    *room = wher[(integer) (rdm_(&seed) * 9 + 1) - 1];
    goto L103;
L619:
/*     ...ROPE OUT WINDOW... */
    if ((*room != 29 || *lroom != 1) && (*room != 1 || *lroom != 29)) {
	goto L621;
    }
    if (*rope == 2) {
	goto L103;
    }
    s_wsfe(&io___99);
    e_wsfe();
    goto L106;
L621:
/*     ...JUMP FROM SMOKING ROOM... */
    if (*room != 39 || *lroom != 10) {
	goto L623;
    }
L622:
    if (*wind2 == 3) {
	*lroom = 0;
    }
    if (*wind2 == 3) {
	goto L103;
    }
    s_wsfe(&io___100);
    e_wsfe();
    goto L106;
L623:
/*     ...FIRE... */
    if (*room != 48 || *lroom != 47) {
	goto L625;
    }
    if (! (*fire)) {
	goto L103;
    }
    s_wsfe(&io___101);
    e_wsfe();
    goto L106;
L625:
/*      ...END OF GAME... */
    if (*room != 70 || *lroom != 71) {
	goto L626;
    }
    i__1 = nitems;
    for (k = 1; k <= i__1; ++k) {
	if (items[k - 1] == 71) {
	    items[k - 1] = 70;
	}
/* L628: */
    }
    goto L630;
L626:
    if (*room != 71 || *lroom != 70) {
	goto L627;
    }
    i__1 = nitems;
    for (k = 1; k <= i__1; ++k) {
	if (items[k - 1] == 70) {
	    items[k - 1] = 71;
	}
/* L632: */
    }
L630:
    adscor_(&ii);
    if (ii < *max_) {
	goto L103;
    }
    if (items[2] != -1) {
	goto L103;
    }
    *room = 99;
    *lroom = 0;
    goto L103;
L627:
/*      ...HATCH (GOING DOWN)... */
    if (*room != 80 || *lroom != 40) {
	goto L629;
    }
    if (door[79] == 2) {
	goto L103;
    }
    *room = 0;
    goto L102;
L629:
/*     ...HATCH (GOING UP)... */
    if (*room != 40 || *lroom != 80) {
	goto L631;
    }
    if (door[79] == 2) {
	goto L103;
    }
    *room = 0;
    s_wsfe(&io___103);
    e_wsfe();
    goto L106;
L631:
/*     ...PRECIPICE... */
    if ((*room != 83 || *lroom != 84) && (*room != 84 || *lroom != 83)) {
	goto L633;
    }
    if (! (*prec)) {
	*room = 0;
    }
    goto L102;
L633:
/*     ...MELT ICE ... */
    if (*room != 90 || *lroom != 65) {
	goto L635;
    }
    if (! (*melt)) {
	*room = 0;
    }
    goto L102;
L635:
/*     ...CYCLOPS SHAPED HOLE... */
    if (*room != 88 || *lroom != 86) {
	goto L637;
    }
    if (! (*hole)) {
	*room = 0;
    }
    goto L102;
L637:
    if (*room != 93 || *lroom != 92) {
	goto L639;
    }
    if (items[11] == -1) {
	goto L103;
    }
    *room = 0;
    s_wsfe(&io___104);
    e_wsfe();
    goto L106;
L639:
/*     ...WIZARD. . . */
    if (*room != 94 || *lroom != 93) {
	goto L641;
    }
    if (! (*wiz)) {
	goto L102;
    }
    s_wsfe(&io___105);
    e_wsfe();
    *room = 0;
    goto L106;
L641:
    if (*room != 70 || *lroom != 71) {
	goto L643;
    }
    if (items[2] != -1) {
	goto L102;
    }
    adscor_(&ii);
    if (ii < *max_) {
	goto L102;
    }
    *room = 99;
    *lroom = 0;
    goto L102;
L643:
    if (*room != 95 || *lroom != 99) {
	goto L645;
    }
    if (*masect) {
	goto L102;
    }
    *room = 0;
    goto L102;
L645:
    s_wsfe(&io___106);
    do_fio(&c__1, (char *)&(*lroom), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*room), (ftnlen)sizeof(integer));
    e_wsfe();
    goto L20;
L102:
    if (*room != 0) {
	goto L103;
    }
    s_wsfe(&io___107);
    e_wsfe();
L106:
    *room = *lroom;
    *lroom = ii;
    goto L25;
L103:
/*     ...BOAT IN CASTLE... */
    if ((*room != 8 || *lroom != 12) && (*room != 1 || *lroom != 29)) {
	goto L28;
    }
    if (items[13] != -1) {
	goto L29;
    }
    s_wsfe(&io___108);
    e_wsfe();
    goto L106;
L28:
/*      ...MASTER AWAKE... */
    if (*room != 41 || *lroom != 43) {
	goto L29;
    }
    if (*master != 3) {
	goto L29;
    }
    s_wsfe(&io___109);
    e_wsfe();
    goto L902;
L29:
    if (*master == 1 || *master == 2) {
	*master = 3;
    }
    prev[*room - 1] = prev[*room - 1] + 1 + *ibrief;
    if (prev[*room - 1] > 5) {
	prev[*room - 1] = *ibrief;
    }
    goto L20;

L111:
/*     ---TAKE--- */
    if (*numb < 10 || *object == 26 || *object == 5) {
	goto L206;
    }
    s_wsfe(&io___110);
    e_wsfe();
    goto L25;
L206:
    if (*object == 31) {
	goto L207;
    }
    if (*object == 8 && *hunch == 1) {
	goto L204;
    }
    if (*object == 46 && (*room != 13 && *room != 10)) {
	goto L201;
    }
    if (*object == 9 && *rope == 2) {
	goto L454;
    }
    if (*object == 9 && *rope == 3) {
	goto L452;
    }
    if (*object == 16 && *rope == 3) {
	goto L452;
    }
    if (*object == 26 && (*room == 32 || *room == 40 || *room == 68 || *room 
	    == 81)) {
	goto L215;
    }
/* L203: */
    if (*object != 49) {
	goto L766;
    }
    if (*but != 4) {
	s_wsfe(&io___111);
	e_wsfe();
    }
    if (*but == 4) {
	s_wsfe(&io___112);
	e_wsfe();
    }
L766:
    if (*object == 46) {
	s_wsfe(&io___113);
	e_wsfe();
    }
    if (*object == 52) {
	s_wsfe(&io___114);
	e_wsfe();
    }
    if (*object == 8) {
	s_wsfe(&io___115);
	e_wsfe();
    }
    if (*object == 49 || *object == 46 || *object == 52 || *object == 8) {
	goto L25;
    }
    if (*object > nitems) {
	goto L730;
    }
    if (items[*object - 1] == -1) {
	goto L750;
    }
    if (*object == 20 && *room == 3) {
	goto L204;
    }
    if (*object == 6 && *room == 12) {
	goto L204;
    }
    if (items[*object - 1] != *room && items[*object - 1] != -2) {
	goto L201;
    }
    if (*object == 26 || *object == 5) {
	goto L215;
    }
L204:
    items[*object - 1] = -1;
    ++(*numb);
    goto L800;
L201:
    s_wsfe(&io___116);
    e_wsfe();
/* L205: */
    goto L25;
L454:
    *rope = 0;
    items[8] = -1;
    ++(*numb);
    goto L800;
L452:
    if (*prec && *room == 83) {
	goto L303;
    }
    if (items[8] != *room || items[15] != *room) {
	goto L201;
    }
    items[8] = -1;
    items[15] = -1;
    *numb += 2;
    if (*prec) {
	*prec = FALSE_;
    }
    goto L800;
L207:
/* TAKE ALL -- pick up everything in the room, except blood or water. */
    i__1 = nitems;
    for (ii = 1; ii <= i__1; ++ii) {
	if (ii == 5 || ii == 26) {
	    goto L208;
	}
	if (items[ii - 1] != *room) {
	    goto L208;
	}
	items[ii - 1] = -1;
	++(*numb);
	if (*numb < 10) {
	    goto L208;
	}
	s_wsfe(&io___117);
	e_wsfe();
	goto L25;
L208:
	;
    }
    goto L800;
L215:
    if (items[17] != -1) {
	goto L216;
    }
    if (*bottle) {
	goto L218;
    }
    items[*object - 1] = -1;
    *bottle = TRUE_;
    if (*object == 5) {
	*blood = TRUE_;
    }
    if (*object == 26) {
	*water = TRUE_;
    }
    goto L800;
L216:
    s_wsfe(&io___118);
    e_wsfe();
    goto L25;
L218:
    s_wsfe(&io___119);
    e_wsfe();
    goto L25;

L112:
/*     ---DROP--- */
    if (*object == 31) {
	goto L211;
    }
    if (*object > nitems) {
	goto L700;
    }
    if ((*object == 9 || *object == 16) && *rope == 3) {
	goto L453;
    }
    if (items[*object - 1] != -1) {
	goto L210;
    }
L217:
    items[*object - 1] = *room;
/* If in MIRROR MAZE, put object in the upstairs hallway */
    if (*room == 27) {
	items[*object - 1] = 9;
    }
    if (*object == 5 || *object == 26) {
	goto L220;
    }
    if ((*object == 2 || *object == 20) && *gun) {
	goto L221;
    }
    --(*numb);
    if (*object == 18 && *bottle) {
	goto L222;
    }
    if (*room != 8) {
	goto L800;
    }
    if (*but == 0 || *but >= 3) {
	goto L800;
    }
    if (items[10] != 8 || items[9] != 8) {
	goto L800;
    }
    items[9] = -3;
    items[10] = -3;
    *but = 2;
    des_(&c__402);
    goto L25;
L210:
    s_wsfe(&io___120);
    e_wsfe();
    goto L25;
L453:
    if (items[8] != -1 || items[15] != -1) {
	goto L720;
    }
    items[8] = *room;
    items[15] = *room;
    *numb += -2;
    if (*room != 84) {
	s_wsfe(&io___121);
	e_wsfe();
    }
    if (*room == 84) {
	*prec = TRUE_;
    }
    if (*room == 84) {
	s_wsfe(&io___122);
	e_wsfe();
    }
    goto L25;
L211:
    for (ii = 1; ii <= 30; ++ii) {
	if (items[ii - 1] != -1) {
	    goto L212;
	}
	items[ii - 1] = *room;
L212:
	;
    }
    if (*bottle) {
	*bottle = FALSE_;
    }
    if (*water) {
	*water = FALSE_;
    }
    if (*blood) {
	*blood = FALSE_;
    }
    if (*gun) {
	*gun = FALSE_;
    }
    *numb = 0;
    goto L800;
L220:
    *bottle = FALSE_;
    if (*object == 5) {
	*blood = FALSE_;
    }
    if (*object == 26) {
	*water = FALSE_;
    }
    goto L800;
L221:
    *gun = FALSE_;
    if (*object == 20) {
	--(*numb);
    }
    if (*object == 20) {
	items[1] = *room;
    }
    goto L800;
L222:
    if (! (*blood)) {
	goto L223;
    }
    *blood = FALSE_;
    *bottle = FALSE_;
    items[4] = *room;
    goto L800;
L223:
    *water = FALSE_;
    *bottle = FALSE_;
    items[25] = *room;
    goto L800;

L113:
/*     ---ENTER--- */
    j = enter[*room - 1];
    if (j == 0) {
	goto L314;
    }
    ++(*numove);
    goto L26;
L114:
/*     ---LEAVE--- */
    if (leave[*room - 1] == 0) {
	goto L140;
    }
    j = leave[*room - 1];
    ++(*numove);
    goto L26;
L115:
/*     ---ATTACK--- */
    if (*gnome && *object == 77) {
	goto L760;
    }
    if (*object != 76 && *object != 49 && *object != 55) {
	goto L229;
    }
    if (*object == 55 && (*room != 20 || ! (*bat))) {
	goto L201;
    }
    if (*object == 49 && (*room != 8 || *but == 4)) {
	goto L201;
    }
    if (*object == 76 && ! (*wolf)) {
	goto L201;
    }
    s_wsfe(&io___123);
    e_wsfe();
    yorn_(&ii);
    if (ii == 0) {
	goto L25;
    }
    if (*object == 76) {
	des_(&c__414);
    }
    if (*object == 49) {
	des_(&c__415);
    }
    if (*object == 55) {
	des_(&c__416);
    }
    goto L25;
L229:
    if (*object != 8) {
	goto L230;
    }
    s_wsfe(&io___124);
    e_wsfe();
    yorn_(&ii);
    if (ii == 0) {
	goto L25;
    }
    if (items[7] != *room && items[7] != -1) {
	goto L201;
    }
    if (items[7] == -1) {
	--(*numb);
    }
    items[7] = 0;
    des_(&c__422);
    goto L25;
L230:
    if (*object != 78) {
	goto L231;
    }
    if (*room != 86 || *hole) {
	goto L201;
    }
    s_wsfe(&io___125);
    e_wsfe();
    goto L25;
L231:
    if (*object != 39) {
	goto L234;
    }
    if (*master == 4) {
	goto L234;
    }
    s_wsfe(&io___126);
    e_wsfe();
    yorn_(&ii);
    if (ii == 0) {
	goto L25;
    }
    s_wsfe(&io___127);
    e_wsfe();
    goto L25;
L234:
    if (*object != 80) {
	goto L236;
    }
    if (*room != 93 || ! (*wiz)) {
	goto L201;
    }
L235:
    s_wsfe(&io___128);
    e_wsfe();
    goto L25;
L236:
    des_(&c__418);
    goto L25;
L116:
/*     ---KILL--- */
    goto L115;
L117:
/*     ---THROW--- */
    if (*room == 47 && *object == 26) {
	goto L391;
    }
    if (*object == 16) {
	goto L241;
    }
    if (*object == 9) {
	goto L240;
    }
    if (*object > nitems) {
	goto L740;
    }
    if (items[*object - 1] != -1 && items[*object - 1] != *room) {
	goto L720;
    }
    if (*object == 12) {
	goto L380;
    }
    if (*object == 3) {
	goto L380;
    }
    if (*object == 6 && *room == 43) {
	goto L247;
    }
    if (*object != 25) {
	goto L240;
    }
    if (items[24] != -1) {
	goto L720;
    }
    --(*numb);
    if (*room != 1) {
	goto L232;
    }
    if (*shuttr == 0) {
	goto L238;
    }
    *wind1 = 3;
    s_wsfe(&io___129);
    e_wsfe();
    items[24] = 0;
    goto L25;
L232:
    if (! (*wolf)) {
	goto L233;
    }
    s_wsfe(&io___130);
    e_wsfe();
    *wolf = FALSE_;
    items[24] = 0;
/*              Reduce MAX by ten, because the acid is needed to */
/*              get passed the bars and retrieve the statue. */
    *max_ += -10;
    goto L25;
L233:
    if (*room != 10) {
	goto L238;
    }
    if (*wind2 < 1) {
	goto L238;
    }
    *wind2 = 3;
    s_wsfe(&io___131);
    e_wsfe();
    goto L25;
L238:
    s_wsfe(&io___132);
    e_wsfe();
    items[24] = 0;
    *max_ += -10;
    goto L25;
L240:
    if (*object != 9) {
	goto L241;
    }
    if (*rope == 3) {
	goto L472;
    }
    if (*room != 1) {
	goto L112;
    }
    if (*wind1 != 3) {
	goto L217;
    }
    if (*rope > 0) {
	goto L242;
    }
    *rope = -2;
    --(*numb);
    items[8] = 0;
    s_wsfe(&io___133);
    e_wsfe();
    goto L25;
L242:
    if (*rope > 1) {
	goto L243;
    }
    *rope = 2;
    s_wsfe(&io___134);
    e_wsfe();
    *score += *ropval;
    *ropval = 0;
    --(*numb);
    items[8] = *room;
    goto L25;
L243:
    s_wsfe(&io___135);
    e_wsfe();
    goto L25;
L241:
    if (*object != 16) {
	goto L474;
    }
L472:
    if (*room != 83) {
	goto L112;
    }
    *prec = TRUE_;
    items[15] = 84;
    items[8] = 84;
    *numb += -2;
    s_wsfe(&io___136);
    e_wsfe();
    goto L25;
L474:
    if (*object != 27) {
	goto L475;
    }
    if (*room != 86 || *hole) {
	goto L112;
    }
    items[26] = -3;
    --(*numb);
    s_wsfe(&io___137);
    e_wsfe();
    goto L25;
L475:
    goto L112;
L380:
    if (*object == 12 && *room == 99 && ! (*masect)) {
	goto L767;
    }
    if (*object == 12 && *room == 93 && *wiz) {
	goto L765;
    }
    if (*gnome) {
	goto L770;
    }
    if (*object == 12) {
	items[11] = *room;
    }
    if (*object == 3 && *room < 95) {
	items[2] = *room;
    }
    --(*numb);
    if (*wolf) {
	*object = 76;
    }
    if (items[7] == *room || items[7] == -1) {
	*object = 8;
    }
    if (*room == 8) {
	*object = 49;
    }
    if (*room == 20) {
	*object = 55;
    }
    if (*room == 86) {
	*object = 78;
    }
    if (*room == 93 && *wiz) {
	goto L235;
    }
    if (*room == 6) {
	*object = 56;
    }
    if (*room == 6) {
	goto L137;
    }
    goto L379;
L118:
/*     ---LOAD--- */
    if (*object == 0) {
	*object = 20;
    }
    if (*object != 20) {
	goto L700;
    }
    if (items[19] != -1) {
	goto L720;
    }
    if (items[1] == -1) {
	goto L274;
    }
    s_wsfe(&io___138);
    e_wsfe();
    goto L25;
L274:
    if (! (*gun)) {
	--(*numb);
    }
    *gun = TRUE_;
    goto L800;
L119:
/*    ---FUCK--- */
    if (*object != 0) {
	goto L261;
    }
    s_wsfe(&io___139);
    e_wsfe();
    goto L25;
L261:
    s_wsfe(&io___140);
    e_wsfe();
    goto L25;
L120:
/*     ---WAVE--- */
    if (items[*object - 1] != -1) {
	goto L720;
    }
    if (*room < 95 || *object != 3) {
	goto L264;
    }
    if (*room == 99) {
	goto L264;
    }
    if (*room != 95) {
	goto L813;
    }
    if (*mas1) {
	goto L262;
    }
    s_wsfe(&io___141);
    e_wsfe();
    *mas1 = TRUE_;
    *score += 3;
    goto L25;
L813:
    if (*room != 96) {
	goto L814;
    }
    if (*mas2) {
	goto L262;
    }
    s_wsfe(&io___142);
    e_wsfe();
    *mas2 = TRUE_;
    *score += 2;
    goto L25;
L814:
    if (*room != 97) {
	goto L815;
    }
    if (*mas3) {
	goto L262;
    }
    s_wsfe(&io___143);
    e_wsfe();
    *mas3 = TRUE_;
    *score += 3;
    goto L25;
L815:
    if (*mas4) {
	goto L262;
    }
    s_wsfe(&io___144);
    e_wsfe();
    *mas4 = TRUE_;
    *score += 2;
    goto L25;
L264:
    if (*room != 93) {
	goto L263;
    }
    if (! (*wiz)) {
	goto L262;
    }
    s_wsfe(&io___145);
    e_wsfe();
    s_wsfe(&io___146);
    e_wsfe();
    *wiz = FALSE_;
    goto L25;
L263:
    if (*room != 43) {
	goto L262;
    }
    if (*master == 0 || *master == 4) {
	goto L262;
    }
    if (*object != 19) {
	goto L262;
    }
    if (items[18] != -1) {
	goto L720;
    }
    *master = 2;
    des_(&c__425);
    goto L25;
L262:
    s_wsfe(&io___147);
    e_wsfe();
    goto L25;
L121:
/*     ---STAB--- */
    if (*object == 39) {
	goto L247;
    }
    if (*object == 80) {
	goto L765;
    }
    if (items[11] != -1) {
	goto L246;
    }
    if (*gnome && *object == 77) {
	goto L770;
    }
    items[11] = *room;
    --(*numb);
L379:
    if (*object != 49 && *object != 76 && *object != 55 && *object != 78 && *
	    object != 8) {
	goto L730;
    }
    if (*object != 55) {
	goto L381;
    }
    if (*room != 20 || ! (*bat)) {
	goto L201;
    }
    des_(&c__419);
    goto L25;
L381:
    if (*object != 76) {
	goto L382;
    }
    if (! (*wolf)) {
	goto L201;
    }
    des_(&c__420);
    goto L25;
L382:
    if (*object != 49) {
	goto L244;
    }
    if (*room != 8) {
	goto L201;
    }
    if (*but == 4) {
	goto L740;
    }
    *but = 4;
    s_wsfe(&io___148);
    e_wsfe();
    goto L25;
L244:
    if (*object != 8) {
	goto L266;
    }
    if (items[7] != *room && items[7] != -1) {
	goto L201;
    }
    *hunch = 2;
    if (items[7] == -1) {
	--(*numb);
    }
    s_wsfe(&io___149);
    e_wsfe();
/* L245: */
    items[*object - 1] = 0;
    goto L25;
L266:
    if (*object != 78) {
	goto L730;
    }
    if (*room != 86 || *hole) {
	goto L201;
    }
    s_wsfe(&io___150);
    e_wsfe();
    goto L25;
L246:
    s_wsfe(&io___151);
    e_wsfe();
    goto L25;
L247:
    if (*master == 0) {
	goto L201;
    }
    if (*master == 4 || *room != 43) {
	goto L740;
    }
    if (items[5] != -1) {
	goto L250;
    }
    s_wsfe(&io___152);
    e_wsfe();
    *master = 4;
    items[5] = 0;
    --(*numb);
    *score += 25;
    for (ii = 1; ii <= 10; ++ii) {
	wher[ii - 1] = 2;
/* L252: */
    }
    s_wsfe(&io___153);
    e_wsfe();
    s_wsfe(&io___154);
    e_wsfe();
    s_wsfe(&io___155);
    e_wsfe();
    goto L25;
L250:
    s_wsfe(&io___156);
    e_wsfe();
    goto L25;
L122:
/*     ---FEED--- */
    if (*object != 55) {
	goto L251;
    }
    if (*room != 20) {
	goto L201;
    }
    if (items[4] == -1) {
	goto L248;
    }
    if (items[21] == -1) {
	goto L249;
    }
    s_wsfe(&io___157);
    e_wsfe();
    goto L25;
L248:
    items[4] = 0;
    *bat = FALSE_;
    *bottle = FALSE_;
    *blood = FALSE_;
    s_wsfe(&io___158);
    e_wsfe();
    goto L25;
L249:
    s_wsfe(&io___159);
    e_wsfe();
    goto L25;
L251:
    if (items[21] != -1) {
	goto L224;
    }
    if (*object != 8) {
	goto L265;
    }
    if (items[7] != *room) {
	goto L201;
    }
    *hunch = 1;
    items[21] = 0;
    --(*numb);
    s_wsfe(&io___160);
    e_wsfe();
    goto L25;
L265:
    if (*object != 76) {
	goto L253;
    }
    if (! (*wolf)) {
	goto L201;
    }
    s_wsfe(&io___161);
    e_wsfe();
    goto L25;
L253:
    if (*object != 49) {
	goto L267;
    }
    if (*room != 8) {
	goto L201;
    }
    if (*but == 4) {
	goto L740;
    }
    s_wsfe(&io___162);
    e_wsfe();
    goto L25;
L267:
    if (*object != 78) {
	goto L700;
    }
    if (*room != 86 || *hole) {
	goto L201;
    }
    s_wsfe(&io___163);
    e_wsfe();
    goto L25;
L224:
    s_wsfe(&io___164);
    e_wsfe();
    goto L25;
L123:
/*     ---EAT--- */
    if (*object != 22) {
	goto L730;
    }
    if (items[21] != -1 && items[21] != *room) {
	goto L720;
    }
    s_wsfe(&io___165);
    e_wsfe();
    items[21] = -3;
    goto L25;
L124:
/*     ---DRINK--- */
    if (*object > nitems) {
	goto L730;
    }
    if (*object == 26 && (*room == 32 || *room == 40 || *room == 68 || *room 
	    == 81)) {
	goto L254;
    }
    if (items[*object - 1] != -1 && items[*object - 1] != *room) {
	goto L720;
    }
    if (*object == 5) {
	goto L730;
    }
    if (*object != 26) {
	goto L385;
    }
    *bottle = FALSE_;
    *water = FALSE_;
    items[25] = 0;
L254:
    s_wsfe(&io___166);
    e_wsfe();
    goto L25;
L385:
    if (*object != 25) {
	goto L260;
    }
    s_wsfe(&io___167);
    e_wsfe();
    items[24] = 0;
    goto L25;
L260:
    if (*object != 7) {
	goto L700;
    }
    s_wsfe(&io___168);
    e_wsfe();
    goto L25;
L125:
/*     ---JUMP--- */
    if (*room == 42) {
	goto L259;
    }
    if (*room != 1 && *room != 10) {
	goto L258;
    }
    if (*room != 10) {
	goto L256;
    }
    if (*wind2 != 3) {
	goto L255;
    }
    *room = 39;
    *lroom = 0;
    goto L622;
L255:
    s_wsfe(&io___169);
    e_wsfe();
    goto L25;
L256:
    if (*wind1 != 3) {
	goto L255;
    }
    ii = 801;
    goto L900;
L258:
    if (*room != 38) {
	goto L383;
    }
    s_wsfe(&io___170);
    e_wsfe();
    goto L902;
L383:
    if (*room != 67 && *room != 76) {
	goto L255;
    }
    s_wsfe(&io___171);
    e_wsfe();
    s_wsfe(&io___172);
    e_wsfe();
    goto L902;
L259:
    ii = 805;
    goto L900;
L126:
/*     ---INVENTORY--- */
    invent_(&nitems);
    goto L25;
L127:
/*     ---OPEN--- */
    if (*room == 86 || *room == 88) {
	goto L393;
    }
    if (*object == 0 && *room <= 25) {
	*object = 47;
    }
    if (*object == 7) {
	goto L385;
    }
    if (*object != 47) {
	goto L275;
    }
    if (*room == 6) {
	goto L272;
    }
    if (door[*room - 1] == -2) {
	goto L276;
    }
    if (door[*room - 1] < 0) {
	goto L273;
    }
    if (door[*room - 1] == 0) {
	s_wsfe(&io___173);
	e_wsfe();
    }
L271:
    if (door[*room - 1] == 2) {
	s_wsfe(&io___174);
	e_wsfe();
    }
    if (door[*room - 1] != 1) {
	goto L25;
    }
    door[*room - 1] = 2;
    goto L800;
L393:
    s_wsfe(&io___175);
    e_wsfe();
    goto L25;
L272:
    if (door[5] == 0) {
	s_wsfe(&io___176);
	e_wsfe();
    }
    if (door[5] == 2) {
	s_wsfe(&io___177);
	e_wsfe();
    }
    if (door[5] != 1) {
	goto L25;
    }
    door[5] = 2;
    *room = 7;
    *lroom = 6;
    *score += *notval;
    *notval = 0;
    goto L20;
L273:
    s_wsfe(&io___178);
    e_wsfe();
    goto L25;
L276:
    s_wsfe(&io___179);
    e_wsfe();
    goto L25;
L275:
    if (*object != 38) {
	goto L277;
    }
    if (*room != 1) {
	goto L201;
    }
    *shuttr = 1;
    s_wsfe(&io___180);
    e_wsfe();
    des_(&c__428);
    goto L25;
L277:
    if (*object != 37) {
	goto L278;
    }
    if (*room != 1 && *room != 10) {
	goto L201;
    }
    if (*room == 1 && *shuttr == 0) {
	goto L201;
    }
    s_wsfe(&io___181);
    e_wsfe();
    goto L25;
L278:
    if (*object != 48) {
	goto L279;
    }
    if (*room != 1) {
	goto L201;
    }
    if (items[18] == 0) {
	items[18] = 1;
    }
    if (items[18] != 1) {
	goto L800;
    }
    s_wsfe(&io___182);
    e_wsfe();
    *score += value[18];
    value[18] = 0;
    goto L25;
L279:
    if (*object != 33) {
	goto L280;
    }
    s_wsfe(&io___183);
    e_wsfe();
    goto L25;
L280:
    if (*object != 46) {
	goto L282;
    }
    if (*room != 13) {
	goto L281;
    }
    if (items[3] == -3) {
	items[3] = *room;
    }
    if (items[3] != *room) {
	goto L281;
    }
    s_wsfe(&io___184);
    e_wsfe();
    goto L25;
L281:
    s_wsfe(&io___185);
    e_wsfe();
    goto L25;
L282:
    if (*object != 40) {
	goto L285;
    }
    if (*room != 43) {
	goto L314;
    }
    if (*master < 4) {
	*master = (*sun << 1) + 1;
    }
    ii = *master + 423;
    des_(&ii);
    goto L25;
L285:
    goto L314;
L128:
/*     ---CLOSE--- */
    if (*object == 0 && *room <= 25) {
	*object = 47;
    }
    if (*object != 47) {
	goto L284;
    }
    if (*room == 7) {
	goto L283;
    }
    if (door[*room - 1] == -2) {
	goto L276;
    }
    if (door[*room - 1] < 0) {
	goto L272;
    }
    if (door[*room - 1] == 2) {
	door[*room - 1] = 1;
    }
    goto L800;
L283:
    *room = 6;
    *lroom = 0;
    goto L800;
L284:
    if (*object != 38) {
	goto L286;
    }
    if (*room != 1) {
	goto L201;
    }
    *shuttr = 0;
    goto L800;
L286:
    if (*object != 37) {
	goto L288;
    }
    if (*room != 1) {
	goto L287;
    }
    if (*wind1 != 1) {
	goto L800;
    }
    s_wsfe(&io___186);
    e_wsfe();
    goto L25;
L287:
    if (*room != 10) {
	goto L201;
    }
    if (*wind2 != 1) {
	goto L800;
    }
    s_wsfe(&io___187);
    e_wsfe();
    goto L25;
L288:
    if (*object != 48) {
	goto L290;
    }
    if (*room != 1) {
	goto L201;
    }
    if (items[18] == 1) {
	items[18] = 0;
    }
    goto L800;
L290:
    if (*object != 46) {
	goto L289;
    }
    s_wsfe(&io___188);
    e_wsfe();
    goto L25;
L289:
    if (*object != 40) {
	goto L740;
    }
    if (*master >= 3) {
	goto L740;
    }
    if (*master < 3) {
	*master = 0;
    }
    goto L800;
L129:
/*     ---LOCK--- */
    if (*object != 47) {
	goto L700;
    }
    if (*room == 21) {
	goto L296;
    }
    if (door[*room - 1] == -1) {
	goto L273;
    }
    if (door[*room - 1] == -2) {
	goto L276;
    }
    if (items[3] != -1) {
	goto L292;
    }
    door[*room - 1] = 0;
    s_wsfe(&io___189);
    e_wsfe();
    goto L25;
L296:
    lock = 0;
    door[20] = 0;
    goto L800;
L292:
    s_wsfe(&io___190);
    e_wsfe();
    goto L25;
L130:
/*     ---UNLOCK--- */
    if (*object == 0 && *room <= 25) {
	*object = 47;
    }
    if (*object != 47) {
	goto L730;
    }
    if (*room == 21) {
	goto L294;
    }
    if (door[*room - 1] == -1) {
	goto L273;
    }
    if (door[*room - 1] == -2) {
	goto L271;
    }
    if (items[3] != -1) {
	goto L292;
    }
    door[*room - 1] = 1;
    goto L800;
L294:
    s_wsfe(&io___191);
    e_wsfe();
    goto L25;
L131:
/*     ---ON--- */
    if (*object == 0) {
	*object = 21;
    }
L132:
/*     ---LIGHT--- */
    if (*object > nitems) {
	goto L700;
    }
    if (items[20] == *room && *object == 21) {
	goto L319;
    }
    if (*object == 27 && *room == 86) {
	goto L324;
    }
    if (items[*object - 1] != -1 && items[*object - 1] != *room) {
	goto L720;
    }
    if (*object != 21) {
	goto L320;
    }
L319:
    if (*lamp == 3) {
	goto L471;
    }
    if (*lamp == 0) {
	ii = 0;
    }
    *lamp = 1;
    if (*lmove > 75) {
	*lamp = 2;
    }
    if (ii == 0 && *room > 40) {
	goto L410;
    }
    goto L712;
L471:
    s_wsfe(&io___192);
    e_wsfe();
    goto L25;
L320:
/* L321: */
    if (*object != 15) {
	goto L323;
    }
    *match = 1;
    if (*room > 40 && (*lamp == 0 || *lamp == 3)) {
	goto L410;
    }
    goto L712;
L323:
    if (*object != 27) {
	goto L477;
    }
L324:
    if (items[14] != -1) {
	goto L322;
    }
    if (*match != 1) {
	goto L322;
    }
    if (*room == 86 && ! (*hole)) {
	goto L476;
    }
    if (items[26] != -1) {
	goto L700;
    }
    ii = 803;
    goto L900;
L477:
    if (*object != 13) {
	goto L730;
    }
    if (*match != 1) {
	goto L322;
    }
    *torch = TRUE_;
    s_wsfe(&io___193);
    e_wsfe();
    goto L25;
L322:
    s_wsfe(&io___194);
    e_wsfe();
    goto L25;
L476:
    if (items[26] != -3) {
	goto L700;
    }
    s_wsfe(&io___195);
    e_wsfe();
    s_wsfe(&io___196);
    e_wsfe();
    items[26] = 0;
    *hole = TRUE_;
    goto L25;
L133:
/*     ---OFF--- */
    if (*object == 0) {
	*object = 21;
    }
L134:
/*     --EXTINGUISH--- */
    if (*object == 34) {
	goto L391;
    }
    if (*object > nitems) {
	goto L700;
    }
    if (items[*object - 1] != -1 && items[*object - 1] != *room) {
	goto L720;
    }
/* L293: */
    if (*object != 21) {
	goto L295;
    }
    *lamp = 0;
    goto L710;
L295:
/* L298: */
    if (*object != 15) {
	goto L399;
    }
    *match = 0;
    goto L710;
L399:
    if (*object != 13) {
	goto L730;
    }
    *torch = FALSE_;
    goto L800;
L391:
    if (items[25] != -1) {
	goto L392;
    }
    items[25] = 0;
    *bottle = FALSE_;
    *water = FALSE_;
    *fire = FALSE_;
    s_wsfe(&io___197);
    e_wsfe();
    goto L25;
/* L394: */
    if (*object != 13) {
	goto L392;
    }
    if (items[12] != *room && items[12] != -1) {
	goto L201;
    }
    *torch = FALSE_;
    goto L800;
L392:
    s_wsfe(&io___198);
    e_wsfe();
    goto L25;
L135:
/*     ---LOOK--- */
    prev[*room - 1] = 0;
    goto L20;
L136:
/*     ---SCORE--- */
    adscor_(&ii);
    ii = *score + ii;
    s_wsfe(&io___199);
    do_fio(&c__1, (char *)&(*numove), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L25;
L137:
/*     ---BREAK--- */
    if (*object != 56) {
	goto L305;
    }
    if (*room != 6) {
	goto L201;
    }
    if (items[2] != -1 && items[2] != *room) {
	goto L297;
    }
    s_wsfe(&io___200);
    e_wsfe();
    door[5] = 1;
    goto L25;
L297:
    s_wsfe(&io___201);
    e_wsfe();
    yorn_(&ii);
    if (ii == 0) {
	goto L25;
    }
    s_wsfe(&io___202);
    e_wsfe();
    goto L25;
L305:
    if (*object != 37) {
	goto L299;
    }
    if (*room != 1) {
	goto L304;
    }
    if (*wind1 >= 1) {
	s_wsfe(&io___203);
	e_wsfe();
    }
    if (*wind1 >= 1) {
	goto L25;
    }
    *wind1 = 1;
    goto L800;
L304:
    if (*room != 10) {
	goto L201;
    }
    if (*wind2 >= 1) {
	s_wsfe(&io___204);
	e_wsfe();
    }
    if (*wind2 >= 1) {
	goto L25;
    }
    *wind2 = 3;
    goto L800;
L299:
    if (*object != 50) {
	goto L309;
    }
    if (*room == 55) {
	goto L303;
    }
    if (*ipass == 1 && *room == 17) {
	goto L201;
    }
    if (*room != 17) {
	goto L308;
    }
    *ipass = 1;
    *score += 10;
    des_(&c__412);
    goto L25;
L308:
    if (*room != 27) {
	goto L201;
    }
    s_wsfe(&io___205);
    e_wsfe();
    goto L902;
L309:
    if (*object == 47 && *room == 99) {
	goto L767;
    }
    s_wsfe(&io___206);
    e_wsfe();
    goto L25;
L303:
    s_wsfe(&io___207);
    e_wsfe();
    goto L25;
L138:
L139:
/*     ---POUR--- */
    if (*object > nitems) {
	goto L740;
    }
    if (items[*object - 1] != -1) {
	goto L201;
    }
    if (*object == 5 || *object == 25 || *object == 26) {
	goto L112;
    }
    if (*object == 7) {
	goto L385;
    }
    if (*object != 1) {
	goto L740;
    }
    if (items[20] != -1) {
	goto L112;
    }
    *lmove = 0;
    if (*lamp == 2) {
	*lamp = 1;
    }
    if (*lamp == 3) {
	*lamp = 0;
    }
    items[0] = 0;
    --(*numb);
    goto L25;
L140:
/*     ---BACK--- */
    if (*lroom > 0) {
	goto L291;
    }
    s_wsfe(&io___208);
    e_wsfe();
    goto L25;
L291:
    i = *room;
    *room = *lroom;
    *lroom = i;
    ++(*numove);
    goto L20;
L141:
/*     ---SWIM--- */
    if (*room != 32 && *room != 68 && *room != 81 && *room != 40) {
	goto L314;
    }
    s_wsfe(&io___210);
    e_wsfe();
    goto L25;
L142:
/*     ---MELT--- */
    if (*object != 79) {
	goto L730;
    }
    if (*room != 65) {
	goto L201;
    }
    if (items[12] != -1 || ! (*torch)) {
	goto L740;
    }
    if (*melt) {
	goto L769;
    }
    *melt = TRUE_;
    s_wsfe(&io___211);
    e_wsfe();
    if (! (*water)) {
	items[25] = *room;
    }
    obj_(items, room, score, value);
    goto L25;
L143:
/*     ---CROSS--- */
    if (*room != 32 && *room != 40) {
	goto L351;
    }
    if (items[13] != -1) {
	goto L352;
    }
    if (*room != 32) {
	goto L350;
    }
    *room = 40;
    *lroom = 0;
    goto L103;
L350:
    *room = 32;
    *lroom = 0;
    goto L103;
L351:
    if (*room != 68 && *room != 81) {
	goto L314;
    }
    if (items[13] != -1) {
	goto L352;
    }
    if (*room == 68) {
	goto L356;
    }
    *room = 68;
    *lroom = 0;
    goto L103;
L356:
    *room = 81;
    *lroom = 0;
    goto L103;
L352:
    s_wsfe(&io___212);
    e_wsfe();
    goto L25;
L144:
/*     ---QUIT--- */
    goto L9000;
L145:
/*     ---HONK--- */
    if (*room < 95) {
	goto L262;
    }
    if (*room != 99) {
	goto L398;
    }
    if (*mas1) {
	*score += 2;
    }
    if (*mas2) {
	++(*score);
    }
    if (*mas3) {
	++(*score);
    }
    if (*mas4) {
	++(*score);
    }
    *room = 100;
    brief = (float)0.;
    goto L20;
L398:
    if (*room == 95 || *room == 97) {
	s_wsfe(&io___214);
	e_wsfe();
    }
    if (*room == 96 || *room == 98) {
	s_wsfe(&io___215);
	e_wsfe();
    }
    *ndeath = 3;
    goto L902;
L146:
/*     ---TIE--- */
    if (*object != 9) {
	goto L409;
    }
    if (items[8] != -1) {
	goto L201;
    }
    if (*room != 1) {
	goto L411;
    }
    if (*rope == 3) {
	goto L411;
    }
    *rope = 1;
    items[8] = 1;
/* L353: */
    s_wsfe(&io___216);
    e_wsfe();
    goto L25;
L409:
    if (*object != 16) {
	goto L700;
    }
L411:
    if (items[15] != -1 || items[8] != -1) {
	goto L314;
    }
    *rope = 3;
    s_wsfe(&io___217);
    e_wsfe();
    goto L25;
L147:
/*     ---UNTIE--- */
    if (*object != 9) {
	goto L406;
    }
    if (*rope == 3) {
	goto L407;
    }
    if (items[8] != *room) {
	goto L201;
    }
    if (*rope != 1) {
	goto L317;
    }
    *rope = 0;
    goto L800;
L317:
    if (*rope != 2) {
	goto L314;
    }
    *rope = -2;
    s_wsfe(&io___218);
    e_wsfe();
/* heck if STATUE,MONEY, and SWORD found. If not, reduce MAX (which */
/*   determines when every treasure has been found) because the */
/*   rope is necessary to find each of these treasures. */
    if (value[11] != 0) {
	*max_ += -10;
    }
    if (value[16] != 0) {
	*max_ += -10;
    }
    if (value[28] != 0) {
	*max_ += -10;
    }
    items[8] = 0;
    goto L25;
L406:
    if (*object != 16) {
	goto L700;
    }
L407:
    if (items[15] != -1 && items[15] != *room) {
	goto L201;
    }
    if (*prec) {
	goto L408;
    }
    *rope = 0;
    goto L800;
L408:
    s_wsfe(&io___219);
    e_wsfe();
    items[8] = 83;
    *rope = 0;
    goto L25;
L148:
/*     ---READ--- */
    if (*object != 46) {
	goto L300;
    }
    if (*room != 13 && *room != 10) {
	goto L201;
    }
    goto L281;
L300:
    if (*object != 52) {
	goto L700;
    }
    if (*but != 2) {
	goto L201;
    }
    *score += *butval;
    *butval = 0;
    if (*note >= 1) {
	goto L302;
    }
    *note = 1;
    s_wsfe(&io___220);
    e_wsfe();
    *but = 0;
    goto L25;
L302:
    *note = 2;
    s_wsfe(&io___221);
    e_wsfe();
    *but = 3;
    goto L25;
L149:
/*     ---FILL--- */
    if (*object > nitems) {
	goto L700;
    }
    if (items[*object - 1] != -1) {
	goto L720;
    }
    if (*object != 18) {
	goto L427;
    }
    if (*bottle) {
	goto L218;
    }
    if (*room == 32 || *room == 40 || *room == 68 || items[25] == *room) {
	*object = 26;
    }
    if (items[4] == *room) {
	*object = 5;
    }
    if (*object == 18) {
	goto L740;
    }
    goto L111;
L427:
    if (*object != 21) {
	goto L740;
    }
    if (items[0] != -1) {
	goto L740;
    }
    if (*lamp == 2) {
	*lamp = 1;
    }
    if (*lamp == 3) {
	*lamp = 0;
    }
    items[0] = 0;
    --(*numb);
    *lmove = -75;
    goto L800;
L150:
/*     ---HINT--- */
    ii = *room;
    help_(&ii, object);
    goto L25;
L151:
/*     --GOTO-- */
/*     CALL GUINFO(2,SIGID) */
/*     IF(SIGID.EQ.AWCC.OR.SIGID.EQ.A6L2.OR. */
/*    1SIGID.EQ.A3TB) GOTO 425 */
    s_wsfe(&io___222);
    e_wsfe();
    goto L25;
/* 425  CONTINUE */
/*     WRITE(6,1115) */
/*     READ(5,426) ROOM */
/* 426  FORMAT(I3) */
/*     IF (ROOM .GT. 100) GOTO 425 */
/*     GOTO 428 */
L152:
/*     ---LEFT--- */
    if (*room != 21) {
	goto L314;
    }
    if (lock > 0) {
	goto L312;
    }
    if (*object != 42) {
	goto L316;
    }
    lock = 1;
    goto L800;
L312:
    if (lock == 1) {
	goto L316;
    }
    if (*object != 44) {
	goto L316;
    }
    lock = 3;
    *score += *lokval;
    *lokval = 0;
    door[20] = 1;
    s_wsfe(&io___223);
    e_wsfe();
    goto L25;
L153:
/*     ---RIGHT--- */
    if (*room != 21) {
	goto L314;
    }
    if (lock != 1) {
	goto L316;
    }
    if (*object != 43) {
	goto L316;
    }
    lock = 2;
    goto L800;
L314:
    s_wsfe(&io___224);
    e_wsfe();
    goto L25;
L316:
    s_wsfe(&io___225);
    e_wsfe();
    lock = 0;
    goto L25;
L154:
/*     ---SHOOT--- */
    if (items[19] != -1) {
	goto L700;
    }
    if (*gun) {
	goto L480;
    }
    s_wsfe(&io___226);
    e_wsfe();
    goto L25;
L480:
    *gun = FALSE_;
    if (*gnome && (*object == 0 || *object == 77)) {
	goto L770;
    }
    if (*object == 76) {
	goto L481;
    }
    if (*object == 8) {
	goto L482;
    }
    if (*object == 49) {
	goto L483;
    }
    if (*object == 55) {
	goto L484;
    }
    if (*object == 78) {
	goto L486;
    }
    if (*object == 80) {
	goto L262;
    }
L481:
    if (*object != 76 && ! (*wolf)) {
	goto L482;
    }
    if (! (*wolf)) {
	goto L201;
    }
    if (rdm_(&seed) < (float).15) {
	goto L487;
    }
    *wolf = FALSE_;
    items[1] = *room;
    s_wsfe(&io___227);
    e_wsfe();
    des_(&c__602);
    goto L25;
L482:
    if (items[7] != *room && items[7] != -1 && *object != 8) {
	goto L483;
    }
    if (items[7] != *room && items[7] != -1) {
	goto L201;
    }
    if (items[7] == -1) {
	--(*numb);
    }
    items[7] = 0;
    items[1] = 0;
    *hunch = 2;
    goto L25;
L483:
    if (*room != 8 && *object != 49) {
	goto L484;
    }
    if (*room != 8) {
	goto L201;
    }
    if (*but == 4) {
	goto L485;
    }
    *but = 4;
    items[1] = 0;
    s_wsfe(&io___228);
    e_wsfe();
    goto L25;
L484:
    if (*room != 20 && *object != 55) {
	goto L486;
    }
    if (! (*bat)) {
	goto L485;
    }
    s_wsfe(&io___229);
    e_wsfe();
    items[1] = *room;
    goto L25;
L485:
    s_wsfe(&io___230);
    e_wsfe();
    *gun = TRUE_;
    ++(*numb);
    goto L25;
L486:
    if (*object != 78 && *room != 86) {
	goto L485;
    }
    if (*hole) {
	goto L485;
    }
    s_wsfe(&io___231);
    e_wsfe();
    items[1] = 0;
    goto L25;
L487:
    s_wsfe(&io___232);
    e_wsfe();
    items[1] = *room;
    ii = 1;
    wwolf_(&ii, wolf);
    if (ii == 0) {
	goto L25;
    }
    goto L902;
L155:
/*     ---WAKE--- */
    if (*object != 49) {
	goto L490;
    }
    if (*but < 3) {
	goto L488;
    }
    s_wsfe(&io___233);
    e_wsfe();
    goto L25;
L488:
    *but = 1;
    if (items[9] == -3) {
	*but = 2;
    }
    if (items[9] == 8 && items[10] == 8) {
	*but = 2;
    }
    if (*but != 2) {
	goto L489;
    }
    items[9] = -3;
    items[10] = -3;
L489:
    ii = *but + 400;
    des_(&ii);
    goto L25;
L490:
    if (*object != 39) {
	goto L491;
    }
    if (*room != 43) {
	goto L201;
    }
    if (*master == 0 || *master == 4) {
	goto L740;
    }
    *master = 3;
    des_(&c__426);
    goto L25;
L491:
    goto L740;
L156:
/*     ---POOF--- */
    if (*room != 56 && *room != 15) {
	goto L262;
    }
    if (door[1] == 0) {
	goto L262;
    }
    if (items[7] == -1) {
	items[7] = 57;
    }
    if (items[13] == -1) {
	items[13] = *room;
    }
    if (*room == 56) {
	goto L547;
    }
    *room = 56;
    *lroom = 0;
    goto L20;
L547:
    *room = 15;
    *lroom = 0;
    goto L20;
L157:
/*     ---SUSPEND--- */
    ii = 1;
    save = TRUE_;
    savres_(&ii);
    goto L9000;
L158:
/*     ---RESTORE--- */
    ii = 0;
    savres_(&ii);
    goto L20;
L159:
/*     ---DEBUG--- */
    s_wsfe(&io___234);
    e_wsfe();
    s_rsfe(&io___235);
    do_fio(&c__1, ca, 4L);
    e_rsfe();
    if (s_cmp(ca, pw, 4L, 4L) != 0) {
	goto L730;
    }
    _BLNK__1.debug = TRUE_;
    goto L800;
L160:
/*     ---VERBOSE--- */
    *ibrief = 0;
    _BLNK__1.debug = FALSE_;
    goto L800;
L161:
/*     ---BRIEF--- */
    *ibrief = 1;
    s_wsfe(&io___237);
    e_wsfe();
    goto L25;
L700:
    s_wsfe(&io___238);
    e_wsfe();
    goto L25;
L710:
    s_wsfe(&io___239);
    e_wsfe();
    if (*room > 40 && ((*lamp == 0 || *lamp == 3) && *match == 0)) {
	s_wsfe(&io___240);
	e_wsfe();
    }
    goto L25;
L712:
    s_wsfe(&io___241);
    e_wsfe();
    goto L25;
L720:
    s_wsfe(&io___242);
    e_wsfe();
    goto L25;
L730:
    s_wsfe(&io___243);
    e_wsfe();
    goto L25;
L740:
    s_wsfe(&io___244);
    e_wsfe();
    goto L25;
L750:
    s_wsfe(&io___245);
    e_wsfe();
    goto L25;
L760:
    s_wsfe(&io___246);
    e_wsfe();
    goto L25;
L765:
    items[12] = 86;
    s_wsfe(&io___247);
    e_wsfe();
    goto L902;
L767:
    *masect = TRUE_;
    s_wsfe(&io___248);
    e_wsfe();
    goto L25;
L769:
    s_wsfe(&io___249);
    e_wsfe();
    goto L902;
L770:
    if (action[0] == 54) {
	goto L775;
    }
    val = rdm_(&seed);
    if (*object == 3) {
	items[2] = *room;
    }
    if (*object == 12 || *object == 77) {
	items[11] = *room;
    }
    --(*numb);
    if (val < (float).8) {
	goto L772;
    }
    s_wsfe(&io___251);
    e_wsfe();
    ii = 0;
    ggnome_(&ii, gnome);
    if (ii > 0) {
	goto L902;
    }
    goto L25;
L772:
    s_wsfe(&io___252);
    e_wsfe();
    *gnome = FALSE_;
    obj_(items, room, score, value);
    goto L25;
L775:
    s_wsfe(&io___253);
    e_wsfe();
    *gnome = FALSE_;
    items[1] = 44;
    goto L25;
L800:
    s_wsfe(&io___254);
    e_wsfe();
    goto L25;
L900:
/*     ---DEATH AND REINCARNATION--- */
    des_(&ii);
L902:
    ++(*ndeath);
    *lamp = 0;
    *numb = 0;
    *score += -10;
    *gnome = FALSE_;
    *wolf = FALSE_;
    if (items[19] == -1) {
	*gun = FALSE_;
    }
    if (items[17] == -1) {
	*bottle = FALSE_;
    }
    if (items[25] == -1) {
	*water = FALSE_;
    }
    if (items[4] == -1) {
	*blood = FALSE_;
    }
    if (items[6] == -1) {
	items[6] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[11] == -1) {
	items[11] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[16] == -1) {
	items[16] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[18] == -1) {
	items[18] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[22] == -1) {
	items[22] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[23] == -1) {
	items[23] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[27] == -1) {
	items[27] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[28] == -1) {
	items[28] = (integer) (rdm_(&seed) * 7 + 57);
    }
    if (items[29] == -1) {
	items[29] = (integer) (rdm_(&seed) * 7 + 57);
    }
    switch ((int)*ndeath) {
	case 1:  goto L905;
	case 2:  goto L920;
	case 3:  goto L935;
	case 4:  goto L9100;
    }
L905:
    des_(&c__850);
    yorn_(&ii);
    if (ii == 0) {
	goto L9000;
    }
    des_(&c__851);
/*     RESET LOCATION, ITEMS, ETC. AFTER DEATH. */
    *room = 1;
    *lroom = 0;
    i__1 = nitems;
    for (ii = 1; ii <= i__1; ++ii) {
	if (items[ii - 1] == -1) {
	    items[ii - 1] = (integer) (rdm_(&seed) * 19 + 2);
	}
/* L906: */
    }
    goto L20;
L920:
    des_(&c__852);
    yorn_(&ii);
    if (ii == 0) {
	goto L9000;
    }
    des_(&c__853);
    *room = 9;
    *lroom = 0;
    i__1 = nitems;
    for (ii = 1; ii <= i__1; ++ii) {
	if (items[ii - 1] == -1) {
	    items[ii - 1] = (integer) (rdm_(&seed) * 19 + 2);
	}
/* L922: */
    }
    goto L20;
L935:
    des_(&c__854);

L9000:
    if (! save) {
	goto L9100;
    }
    adscor_(&ii);
    ii = *score + ii;
    s_wsfe(&io___255);
    do_fio(&c__1, (char *)&(*numove), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L9900;

L9100:
/*     ---END OF GAME (WINNER)--- */
    adscor_(&ii);
    ii = *score + ii;
    s_wsfe(&io___256);
    do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&maxabs, (ftnlen)sizeof(integer));
    e_wsfe();
    if (ii >= maxabs) {
	s_wsfe(&io___257);
	e_wsfe();
    }
    jj = maxabs / 4;
    k = maxabs - jj;
    if (ii < maxabs && ii >= k) {
	s_wsfe(&io___259);
	e_wsfe();
    }
    l = k - jj;
    if (ii < k && ii >= l) {
	s_wsfe(&io___261);
	e_wsfe();
    }
    k = l - jj;
    if (ii < l && ii >= k) {
	s_wsfe(&io___262);
	e_wsfe();
    }
    l = k - jj;
    if (ii < k && ii >= l) {
	s_wsfe(&io___263);
	e_wsfe();
    }
    if (ii < l) {
	s_wsfe(&io___264);
	e_wsfe();
    }
L9900:

/*    ********* */
/* L1078: */
/* L1115: */


/* L9999: */
    s_stop("", 0L);
} /* MAIN__ */

#undef mas4
#undef mas3
#undef mas2
#undef mas1
#undef wiz
#undef sun
#undef but
#undef gun
#undef max_
#undef bat
#undef shuttr
#undef numove
#undef ropval
#undef notval
#undef maxscr
#undef butval
#undef master
#undef bottle
#undef lokval
#undef action
#undef masect
#undef object
#undef ndeath
#undef ibrief
#undef lroom
#undef water
#undef mmove
#undef lmove
#undef items
#undef torch
#undef ipass
#undef value
#undef score
#undef gnome
#undef hunch
#undef blood
#undef match
#undef wind2
#undef wind1
#undef room
#undef melt
#undef wolf
#undef note
#undef rope
#undef wher
#undef door
#undef numb
#undef prec
#undef lamp
#undef hole
#undef fire


