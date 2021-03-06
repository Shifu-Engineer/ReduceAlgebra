
/*
           ===========================
           XReduce TeXinfo Help Module
           ===========================

    This module is an X implementation of the Info
    help system.  It is heavily based on the ascii
    terminal help program by  Herbert Melenk, used
    by ascii Reduce.

    The intended utility of this module is:

 [0]  Initialise the help facility, by calling the
      function  HelpInitialise(parent, x, y, name,
      callback), where parent is a widget that the
      help window can use as a parent, x and y are
      the desired  width and height (in pixels) of
      the help window, name is the desired name of
      the help window and callback is a pointer to
      a function which returns a context string as
      may be used in the Help Guess Context method
      -- described below -- or NULL if you want no
      Guess Context button. You can call HelpInit-
      ialise more than once if you want, though it
      is unwise to do so while Help is open.

 [1]  Install an initial help file, with a call to
      HelpSetHelpFile(filename);  filename  should
      be a full pathname,  and it must be readable
      and seekable.   This call will open the help
      file,  if  possible,  and close any previous
      help file;  it also identifies and opens, if
      possible, the search-index file (usually the
      same name as the help file but with a ".hix"
      extension.  HelpSetHelpFile returns non-zero
      to indicate failure.

 [2]  Request an initial help topic,  if required,
      by calling HelpSetTopic(topic),  where topic
      is the  name of the required help node.   If
      a NULL topic is requested,  or if no initial
      topic is requested,  the  topmost node  will
      be  used.   HelpSetTopic  returns non - zero
      to indicate failure.  Note that HelpSetTopic
      should only be called after HelpSetHelpFile.

 [3]  If you wish, set the fonts you want the help
      window  to use,  with calls to the functions
      HelpSetTextFont (fn),  HelpSetXrefFont (fn),
      HelpSetButtonFont(fn),  HelpSetTitleFont(fn)
      and HelpSetVerbatimFont(fn), where arguments
      are strings giving, respectively,  fonts for
      normal text,  highlighting cross-references,
      buttons,  titles and verbatim  environments.
      Note that a non-proportional  font is a good
      idea for verbatim environments.  If no fonts
      are set,  defaults (ugly ones) will be  used
      instead.

 [4]  When the help facility is  called for,  call
      the function HelpInstallHelp(), without args
      This should cause the  help window to pop up
      and operate as a non-grabbing subshell until
      it is finished with.  It returns non-zero to
      indicate failure,  and it will happily do so
      if, for example, the helpfile is unavailable
      or not set.

 [5]  If the parent program wishes  to  close  the
      help window before the  help  facility would
      otherwise do so, it should call HelpClose(),
      with no arguments.   HelpClose()  returns no
      value;  if it is called when the help window
      is already closed, it does nothing.

 [6]  The current help filename can be obtained by
      calling the function HelpGetHelpFile(). This
      returns a shared string,  or NULL if no help
      file is currently set.

 [7]  Calls to HelpSetHelpFile() &  HelpSetTopic()
      may be made at any  time,  although doing so
      may  cause something of a  context jump  for
      the user.

 [8]  Finally, before the parent program exits, if
      it has ever called HelpSetHelpFile it should
      call the function HelpCloseHelpFile, to make
      sure that the file is closed and any changes
      to the help index file are saved. It is safe
      to call this function even if  no  help file
      has been opened.    This function also calls
      HelpClose, to ensure that the help window is
      properly closed.

      The help index file (extension ".hnx")  used
      for searching,  and for speeding the initial
      location of the Table of Contents,  is  made
      by this module, from the help file.   A call
      to the function HelpWriteIndexFile(),  after
      opening a help file,   will create and write
      the index file if possible,   returning non-
      zero for failure.  This takes a while.    If
      the  help module  is used without the  index
      file's presence,  there will not be a Search
      facility available.

      The callback given to HelpInitialise for use
      by the  Guess Context  facility  should be a
      pointer to a nullary function which examines
      the contextual status of the  parent program
      and returns a string which  Help  can use to
      search for likely references for help on the
      user's current dilemma. It should always try
      to return something, even if only "Top";  if
      it doesn't, the attempt is abandoned, and no
      indication of why is given  except an opaque
      warning message.

      In Reduce's case the  context callback  will
      probably  just return a concatenation of any
      likely-looking words in the last few inputs;
      your  callback  should probably do something
      vaguely similar. I know this is a bit basic.

      The  name given to  HelpInitialise  will  be
      duplicated by the function and may be freed;
      the string returned by the  context callback
      should be in space obtained from XtMalloc as
      the Guess Context code will try to free it.

      It is my hope  and intention  that this help
      module may be of some use to programs  other
      than XReduce. Before that, however, it is my
      hope and intention that this help module may
      be made to work.

          =============================
          Chris Cannam, Berlin Jan 1993
          =============================
*/


/*

 ===============================================
 Include lots of relevant and irrelevant headers
 ===============================================
 
   Include several useful  standard string and
   file managing headers, and all the relevant
   X header  information;  do  not include any
   headers specific to the application running
   the help module, so as to keep it modular.
*/


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/cursorfont.h>

#include <X11/Xaw/AsciiText.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Dialog.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/List.h>
#include <X11/Xaw/Paned.h>
#include <X11/Xaw/Scrollbar.h>
#include <X11/Xaw/Text.h>
#include <X11/Xaw/Toggle.h>
#include <X11/Xaw/Viewport.h>


/*

 ================================================
 Define global constants and filescoped variables
 ================================================

   Including four macros to facilitate creating
   and modifying widgets: WIDGET(q,z,k,v) makes
   a managed widget called z,  with class k and
   parent v, and assigns it to q; SETARG(q,z,k)
   sets the resource z  in the widget q  to the
   value k, and GETARG(q,z,k) gets the value of
   the resource z in the widget q,  and assigns
   it to k, which need not be a pointer.  Calls
   to SETARG and GETARG  should be grouped in a
   block,  preceded by BEGARG and terminated by
   FINARG, which handle a local Arg variable.
*/

#define FILE_TAG     "File:"
#define NODE_TAG     "Node:"
#define NEXT_TAG     "Next:"
#define PREV_TAG     "Prev:"
#define   UP_TAG     "Up:"
#define  TOC_TAG     "TagTable:"
#define DEFAULT_FONT "fixed"

#define END_OF_PAGE 0x1f
#define END_OF_LINE 0x0a
#define MAX_NODE    4000
#define MAX_TABLE   2000
#define MAX_LABELS  2000
#define MAX_BUFFER  10000
#define NAME_LENGTH 1000
#define TAG_LENGTH  100
#define LABEL_SPACE 2

#define WIDGET(q,z,k,v) { q = XtCreateManagedWidget((z),(k),(v),NULL,0); }
#define BEGARG          { Arg arg;
#define SETARG(q,z,k)   { XtSetArg(arg,(z), (k)); XtSetValues((q),&arg,1); }
#define GETARG(q,z,k)   { XtSetArg(arg,(z),&(k)); XtGetValues((q),&arg,1); }
#define FINARG          }
#define Try(x)          { if ((x)==-1 ) { goto oops; } else {}; }
#define TrL(x)          { if ((x)==-1L) { goto oops; } else {}; }
#define MenuP           ( helpMode == HelpMenuMode )

typedef struct _HelpSearchPage {
  char                   *page;
  char                   *comment;
  int                     frequency;
  struct _HelpSearchPage *next;
} HelpSearchPage;

typedef struct _HelpSearchTree {
  char                   *string;
  HelpSearchPage         *references;
  struct _HelpSearchTree *inferior;
  struct _HelpSearchTree *superior;
} HelpSearchTree;

typedef enum {
  HelpHeadMode,
  HelpTextMode,
  HelpXmplMode,
  HelpMenuMode
} HelpMode;

typedef enum {
  HelpTextDisplay,
  HelpSearchDisplay,
  HelpRouteDisplay
} HelpDisplayMode;

 Widget           prevButton;
static Widget           helpSh;
static Widget           helpBox;
static Widget           infoBox;
static Widget           fileLabel = NULL;
static Widget           nodeLabel;
static Widget           commandBox;
static Widget           quitButton;
static Widget           searchButton;
static Widget           showButton;
static Widget           upButton;
static Widget           nextButton;
static Widget           textViewport;
static Widget           textBox;
static Widget           textForm;
static Widget           textLabels[MAX_LABELS];
static Widget           menuViewport;
 Widget           menuBox;
 Widget           menuForm;
static Widget           menuLabels[MAX_LABELS];
static Widget           errorSh;
static Widget           errorBox;
static Widget           errorLabel;
static Widget           errorCommand;
static Widget           questionSh;
static Widget           questionBox;
static Widget           questionLabel;
static Widget           questionYes;
static Widget           questionNo;
static Widget           searchLabel1;
static Widget           searchLabel2;
static Widget           searchText;
static Widget           searchGo;
static Widget           buttonBox;
static Widget           searchGuess;
static Widget           referenceWidget;
static int              helpPaneHt;	/* in number of lines */
static int              menuPaneHt;
Boolean          helpInstalled = False;
static Boolean          writingSearch = False;
static Boolean          lastSearch    = False;
static Boolean          guessMode     = False;
static HelpDisplayMode  displayMode   = HelpTextDisplay;
static HelpMode         helpMode      = HelpTextMode;
static Dimension        helpWd;
static Dimension        helpHt;
static Dimension        helpTextWd;
 FILE           * helpFile = NULL;
 FILE           * helpSFil = NULL;
static char           * hefiName = NULL;
static char           * hesfName = NULL;
static char           * helpName = NULL;
HelpSearchPage * helpRout = NULL;
static HelpSearchPage * srchList = NULL;
static HelpSearchPage * comments = NULL;
static HelpSearchTree * searchBT = NULL;
static char       *  (* guess)() = NULL;
XFontStruct       * helpTextFont = NULL;
XFontStruct       * helpXrefFont = NULL;
XFontStruct       * helpCommFont = NULL;
XFontStruct       * helpHeadFont = NULL;
XFontStruct       * helpXmplFont = NULL;

static int           nrTable;
static long          nrNodes;
static int           nrLabels;	/* actually unused; probably should be used */
static int           nrMenu;	/* likewise */
static int           bPoint;
long          topNode = -1;
long          actNode = -1;
long          TOCNode = -1;

static char    tag[  TAG_LENGTH ];
static char   node[ NAME_LENGTH ];
static char   next[ NAME_LENGTH ];
static char   prev[ NAME_LENGTH ];
static char     up[ NAME_LENGTH ];
static char *nname[  MAX_NODE   ];
static long  naddr[  MAX_NODE   ];
static long  table[  MAX_TABLE  ]; /* Can't even remember what this is */
static char buffer[  MAX_BUFFER ];

static char *insignificantWords[] = {
  "the",   "a",    "and",    "but",      "note", "to",   "of",   "it",
  "when",  "how",  "why",    "however",  "on",   "this", "that", "there",
  "here",  "so",   "if",     "be",       "by",   "can",  "does", "done",
  "has",   "have", "is",     "examples", "its",  "may",  "must", "not",
  "only",  "or",   "syntax", "reduce", "section",  "than", "you",  "as",
   NULL,
};


void HelpClose();
void HelpMenuButton();
void HelpXrefButton();
void HelpSearchButton();
void SearchGo();
void SearchGuess();



int HelpError(ermsg)
  char *ermsg;
{
  fprintf(stderr,"Help Module: %s\n",ermsg);
  fflush(stderr);
  return -1;
}

int HelpError2s(ermsg, arg)
  char *ermsg;
  char *arg;
{
  fprintf(stderr,"Help Module: %s \"%s\"\n", ermsg, arg);
  fflush(stderr);
  return -1;
}

int HelpError2d(ermsg, arg)
  char *ermsg;
  int   arg;
{
  fprintf(stderr,"Help Module: %s {%d}\n", ermsg, arg);
  fflush(stderr);
  return -1;
}


XFontStruct *EnsureFont(fnP)
  XFontStruct *fnP;
{
  if (fnP == NULL) {

    HelpError2s("Absent font requested: using default",DEFAULT_FONT);
    if (!(fnP = XLoadQueryFont(XtDisplay(referenceWidget), DEFAULT_FONT)))
      HelpError2s("Couldn't load default font",DEFAULT_FONT);
  }
  return fnP;
}


int CreateContainingWidgets()
{
  int       i;
  Position  x;
  Position  y;
  Dimension wd;
  Dimension ht;
  Dimension bwd;
  Dimension swd;
  Dimension pht;
  Dimension sht;
  Dimension lwd;
  Dimension iwd;

  if ((helpTextFont = EnsureFont(helpTextFont)) == NULL) goto oops;
  if ((helpXrefFont = EnsureFont(helpXrefFont)) == NULL) goto oops;
  if ((helpCommFont = EnsureFont(helpCommFont)) == NULL) goto oops;
  if ((helpHeadFont = EnsureFont(helpHeadFont)) == NULL) goto oops;
  if ((helpXmplFont = EnsureFont(helpXmplFont)) == NULL) goto oops;

  helpSh     = XtCreatePopupShell("Help",
				  topLevelShellWidgetClass,
				  referenceWidget,
				  NULL, 0);

  errorSh    = XtCreatePopupShell("Error",
				  transientShellWidgetClass,
				  helpSh,
				  NULL, 0);

  questionSh = XtCreatePopupShell("Question",
				  transientShellWidgetClass,
				  helpSh,
				  NULL, 0);

  WIDGET( helpBox      , "helpBox"      ,     panedWidgetClass, helpSh       );
  WIDGET( commandBox   , "commandBox"   ,       boxWidgetClass, helpBox      );
  WIDGET( quitButton   , "quitButton"   ,   commandWidgetClass, commandBox   );
  WIDGET( searchButton , "searchButton" ,   commandWidgetClass, commandBox   );
  WIDGET( showButton   , "showButton"   ,   commandWidgetClass, commandBox   );
  WIDGET( infoBox      , "infoBox"      ,       boxWidgetClass, helpBox      );
  WIDGET( fileLabel    , "fileLabel"    ,     labelWidgetClass, infoBox      );
  WIDGET( nodeLabel    , "nodeLabel"    ,     labelWidgetClass, infoBox      );
  WIDGET( buttonBox    , "buttonBox"    ,       boxWidgetClass, helpBox      );
  WIDGET( prevButton   , "prevButton"   ,   commandWidgetClass, buttonBox    );
  WIDGET( upButton     , "upButton"     ,   commandWidgetClass, buttonBox    );
  WIDGET( nextButton   , "nextButton"   ,   commandWidgetClass, buttonBox    );
  WIDGET( textViewport , "textViewport" ,  viewportWidgetClass, helpBox      );
  WIDGET( textBox      , "textBox"      ,       boxWidgetClass, textViewport );
  WIDGET( textForm     , "textForm"     ,      formWidgetClass, textBox      );
  WIDGET( menuViewport , "menuViewport" ,  viewportWidgetClass, helpBox      );
  WIDGET( menuBox      , "menuBox"      ,       boxWidgetClass, menuViewport );
  WIDGET( menuForm     , "menuForm"     ,      formWidgetClass, menuBox      );
  WIDGET( errorBox     , "errorBox"     ,       boxWidgetClass, errorSh      );
  WIDGET( errorLabel   , "errorLabel"   ,     labelWidgetClass, errorBox     );
  WIDGET( errorCommand , "errorCommand" ,   commandWidgetClass, errorBox     );
  WIDGET( questionBox  , "questionBox"  ,       boxWidgetClass, questionSh   );
  WIDGET( questionLabel, "questionLabel",     labelWidgetClass, questionBox  );
  WIDGET( questionYes  , "questionYes"  ,   commandWidgetClass, questionBox  );
  WIDGET( questionNo   , "questionNo"   ,   commandWidgetClass, questionBox  );

  XtUnmanageChild(fileLabel);	/* For the moment let's do without */

  for (i = 0; i < MAX_LABELS; ++i) textLabels[i] = NULL;
  for (i = 0; i < MAX_LABELS; ++i) menuLabels[i] = NULL;

  XtTranslateCoords(referenceWidget, 150, 70, &x, &y);

  BEGARG;			/* This is an inefficient way of setting */
				/* arguments, but on this scale I really */
				/* don't think it matters                */

  SETARG(helpSh,       XtNtitle,              helpName);
  SETARG(infoBox,      XtNshowGrip,           False);
  SETARG(commandBox,   XtNshowGrip,           False);
  SETARG(buttonBox,    XtNshowGrip,           False);
  SETARG(fileLabel,    XtNfont,               helpCommFont);
  SETARG(nodeLabel,    XtNfont,               helpCommFont);
  SETARG(quitButton,   XtNfont,               helpCommFont);
  SETARG(searchButton, XtNfont,               helpCommFont);
  SETARG(showButton,   XtNfont,               helpCommFont);
  SETARG(upButton,     XtNfont,               helpCommFont);
  SETARG(prevButton,   XtNfont,               helpCommFont);
  SETARG(nextButton,   XtNfont,               helpCommFont);
  SETARG(fileLabel,    XtNborderWidth,        0);
  SETARG(nodeLabel,    XtNborderWidth,        0);
  SETARG(prevButton,   XtNborderWidth,        0);
  SETARG(nextButton,   XtNborderWidth,        0);
  SETARG(upButton,     XtNborderWidth,        0);
  SETARG(quitButton,   XtNborderWidth,        0);
  SETARG(showButton,   XtNborderWidth,        0);
  SETARG(searchButton, XtNborderWidth,        0);
  SETARG(prevButton,   XtNhighlightThickness, 1);
  SETARG(nextButton,   XtNhighlightThickness, 1);
  SETARG(upButton,     XtNhighlightThickness, 1);
  SETARG(quitButton,   XtNhighlightThickness, 1);
  SETARG(showButton,   XtNhighlightThickness, 1);
  SETARG(searchButton, XtNhighlightThickness, 1);
  SETARG(textViewport, XtNallowResize,        True);
  SETARG(textViewport, XtNallowHoriz,         False);
  SETARG(textViewport, XtNallowVert,          True);
  SETARG(textViewport, XtNforceBars,          True);
  SETARG(textViewport, XtNshowGrip,           False);
  SETARG(menuViewport, XtNallowHoriz,         False);
  SETARG(menuViewport, XtNallowVert,          True);
  SETARG(quitButton,   XtNlabel,              "Exit");
  SETARG(menuViewport, XtNforceBars,          True);
  SETARG(searchButton, XtNlabel,              "Search");
  SETARG(showButton,   XtNlabel,              "Show Route");

  GETARG(textViewport, XtNborderWidth, bwd);
  GETARG(buttonBox,    XtNhSpace,      swd);
  GETARG(buttonBox,    XtNvSpace,      sht);
  GETARG(infoBox,      XtNhSpace,      iwd);

  wd  =  helpWd - 2*swd - 2*bwd;
  lwd = (helpWd - 2*swd - 2*bwd - 4*iwd) / 3;
  ht  =  helpHt;

  SETARG(textViewport, XtNheight,            ht/2);
  SETARG(textViewport, XtNpreferredPaneSize, ht/2);
  SETARG(textViewport, XtNwidth,             wd);
  SETARG(textForm,     XtNheight,            ht/2);
  SETARG(textForm,     XtNwidth,             wd);
  SETARG(textForm,     XtNborderWidth,       0);
  SETARG(menuViewport, XtNheight,            ht/3);
  SETARG(menuViewport, XtNpreferredPaneSize, ht/3);
  SETARG(menuViewport, XtNwidth,             wd);
  SETARG(menuForm,     XtNheight,            ht/3);
  SETARG(menuForm,     XtNwidth,             wd);
  SETARG(menuForm,     XtNborderWidth,       0);

  XtRealizeWidget(helpSh);

  SETARG(fileLabel,    XtNwidth,             lwd);
  SETARG(nodeLabel,    XtNwidth,             lwd);
  SETARG(prevButton,   XtNwidth,             lwd);
  SETARG(upButton,     XtNwidth,             lwd);
  SETARG(nextButton,   XtNwidth,             lwd);
  SETARG(infoBox,      XtNwidth,             wd);
  SETARG(commandBox,   XtNwidth,             wd);
  SETARG(buttonBox,    XtNwidth,             wd);
  GETARG(prevButton,   XtNheight,            pht); pht  = pht + 2*sht;
  SETARG(infoBox,      XtNheight,            pht); ht  -= pht;
  SETARG(buttonBox,    XtNheight,            pht); ht  -= pht + 6*sht + 10*bwd;
  SETARG(textViewport, XtNheight,            ht/2);
  SETARG(textViewport, XtNpreferredPaneSize, ht/2);
  SETARG(textViewport, XtNwidth,             wd);
  SETARG(textForm,     XtNheight,            ht/2);
  SETARG(textForm,     XtNwidth,             wd);
  SETARG(menuViewport, XtNheight,            ht/3);
  SETARG(menuViewport, XtNpreferredPaneSize, ht/3);
  SETARG(menuViewport, XtNwidth,             wd);
  SETARG(menuForm,     XtNheight,            ht/3);
  SETARG(menuForm,     XtNwidth,             wd);
  SETARG(helpSh,       XtNwidth,             helpWd);
  SETARG(helpSh,       XtNheight,            helpHt);
  SETARG(helpBox,      XtNwidth,             helpWd);
  SETARG(helpBox,      XtNheight,            helpHt);
  SETARG(helpSh,       XtNx,                 x);
  SETARG(helpSh,       XtNy,                 y);
  SETARG(helpBox,      XtNx,                 x);
  SETARG(helpBox,      XtNy,                 y);

  FINARG;

  helpTextWd = (wd > 60) ? (wd - 30) : 30;

  searchGuess  =
    XtCreateWidget("searchGuess",  commandWidgetClass, buttonBox, NULL, 0);
  searchGo     =
    XtCreateWidget("searchGo",     commandWidgetClass, buttonBox, NULL, 0);
  searchLabel1 =
    XtCreateWidget("searchLabel",    labelWidgetClass,  textForm, NULL, 0);
  searchLabel2 =
    XtCreateWidget("searchLabel",    labelWidgetClass,  textForm, NULL, 0);
  searchText   =
    XtCreateWidget("searchText", asciiTextWidgetClass,  textForm, NULL, 0);
  
  XtAddCallback(searchGo,    XtNcallback, SearchGo,    0);
  XtAddCallback(searchGuess, XtNcallback, SearchGuess, 0);

  if (!helpSFil) XtUnmanageChild(searchButton);

  return 0;

 oops:

  return HelpError("Can't set up the help window as required");
}


int SkipChar(u)
  char u;
{
  char c;

  do {

    if (  feof(helpFile)) return HelpError("Unexpected EOF in help file");
    if (ferror(helpFile)) return HelpError("Error reading help file");

    fread (&c, 1, 1, helpFile);

  } while (c != u);

  return 0;
}


int ReadChar()
{
  char c;

  if (  feof(helpFile)) return HelpError("Unexpected EOF in help file");
  if (ferror(helpFile)) return HelpError("Error reading help file");

  fread (&c, 1, 1, helpFile);
  return c;
}


int ReadTag()
{
  char c;
  int  i = 0;

  while (((c = ReadChar()) != (char)-1) && (i < (TAG_LENGTH - 2)) &&
	       (isalnum(c) || isspace(c) ||
		(i == 0 && c == END_OF_LINE)))
    if (c != END_OF_LINE && !isspace(c)) tag[i++] = c;

  tag[i+1] = 0x0;

  if      (c == ':')   tag[i] = c;
  else if (c ==  -1) { tag[i] = 0x0;
		       return HelpError2s("Tag read failed after",tag); }
  return 0;
}


int ReadString(s)
  char *s;
{
  char c;
  int  i = 0;

  while (((c = ReadChar()) != (char)-1) &&
	 (isalnum(c) ||
	  c == ' ' || c == '?' || c == '_' ||  c == '-' ||
	  c == ':' || c == '.' || c == '(' ||  c == ')' ||
	  c == '%' || c == '^' || c == '!' ||
	  (c == '*' && i > 0 &&
	   (isprint(s[i-1]) && s[i-1] != '[')))) {

    s[i] = c; if (i != 0 || c != ' ') ++i;
  } s[i] = 0;

  if (c == -1) return HelpError2s("String read failed after",s);
  else         return 0;
}
  

long ReadNumber()
{
  char c;
  long n = 0;

  while (((c = ReadChar()) != (char)-1) && isdigit(c))
    n = 10 * n + (c-'0');

  if (c == (char)(-1))
       return (long)(HelpError2d("Number read failed: so far read",n));
  else return n;
}


int FindTOC()
{
  if (TOCNode == -1) {

    nrNodes = 0;

    do {

      Try(SkipChar(END_OF_PAGE));
      Try(SkipChar(END_OF_LINE));
      Try(ReadTag());

    } while (strcmp(tag,TOC_TAG));

    Try(SkipChar(END_OF_LINE));
    TOCNode = ftell(helpFile);

  } else {

    if (fseek(helpFile, TOCNode, 0)) {
      HelpError2d("Can't find TOC at",TOCNode);
      TOCNode = -1;
      return FindTOC();
    }
  }

 loop: 

  Try(ReadTag());
  if (strcmp(tag,NODE_TAG)) return 0;

  Try(ReadString(buffer));
  nname[nrNodes] = XtNewString(buffer);
  TrL(naddr[nrNodes] = ReadNumber());

  if ((++nrNodes) > MAX_NODE) return HelpError("Too many nodes in helpfile");

  goto loop;

 oops:
  return HelpError("Unable to find Table of Contents");
}


long FindNode(topic)
  char *topic;
{
  int i;

  for (i = 0; i < nrNodes && strcmp(topic, nname[i]); ++i);

  if (i < nrNodes) return(naddr[i]);

  else             return (long)(HelpError2s("No such node as",topic));
}



int HelpSetHelpFile(filename)
  char *filename;
{
  Arg   arg;
  char *spare;
  int   i, j;

  if (helpFile) fclose(helpFile);
  if (hefiName) XtFree(hefiName);

  if (!(helpFile = fopen(filename, "r")))
    return HelpError2s("Cannot open help file",filename);
  hefiName = XtNewString(filename);

  if (helpSFil) fclose(helpSFil);
  if (hesfName) XtFree(hesfName);

  spare = (char *)XtMalloc((j = strlen(filename)) + 10);
  strcpy(spare, filename);
  for (i = j; i >= 0 && spare[i] != '.'; --i);
  if (spare[i] == '.') strcpy(spare + i+1, "hnx");
  else strcpy(spare + j, ".hnx");

  hesfName = XtNewString(spare);

  if   (!(helpSFil = fopen(spare, "r"))) {
    (void)HelpError2s("Cannot open help index file",spare);
    (void)HelpError("Sorry, there will be no search utility");
  } else {
    if (fscanf(helpSFil, "%ld\n", &TOCNode) != 1) {
      (void)HelpError("Could not read TOC location from index file");
      TOCNode = -1;
    }
  }

  Try(FindTOC());
  TrL(topNode = FindNode("Top"));

  if (fileLabel) {
    sprintf(spare, "File: %s", filename);
    XtSetArg(arg, XtNlabel, spare);
    XtSetValues(fileLabel, &arg, 1);
  }

  XtFree(spare);
  return 0;

 oops: 
  return HelpError2s("Problem in reading help file",filename);
}


int HelpCloseHelpFile()
{
  HelpClose();

  if (helpFile) fclose(helpFile);
  if (hefiName) XtFree(hefiName);
  if (helpSFil) fclose(helpSFil);
  if (hesfName) XtFree(hesfName);

  return 0;
}


int HelpSetTopic(topic)
  char *topic;
{
  if (!helpFile) return HelpError("Attempt to set topic on nonexistent file");

  if (topic == NULL)  actNode = topNode;
  else                actNode = FindNode(topic);

  if (actNode == -1L) return HelpError("Attempt to set nonexistent topic");
  else                return 0;
}


int SizePanes()
{
  int       i;
  Arg       arg[2];
  int       ath;
  Dimension pah;
  Dimension vah;
  Dimension vbh;
  Dimension vth;

  i = 0; XtSetArg(arg[i], XtNheight, &vah); i++;
  XtGetValues(textViewport, arg, i);
  i = 0; XtSetArg(arg[i], XtNheight, &vbh); i++;
  XtGetValues(menuViewport, arg, i);

  ath = helpPaneHt + menuPaneHt;
  vth = vah + vbh;

  if      (helpPaneHt == 0) pah =       LABEL_SPACE + 1;
  else if (menuPaneHt == 0) pah = vth - LABEL_SPACE - 1;
  else {
    pah = (helpPaneHt * vth) / ath;
    if      (pah <  100)        pah = 100;
    else if (vth < (100 + pah)) pah = vth - 100;
  }

  i = 0; XtSetArg(arg[i], XtNheight, pah); i++;
  XtSetValues(textViewport, arg, i);

  i = 0; XtSetArg(arg[i], XtNheight, &vah); i++;
  XtGetValues(textForm, arg, i);
  i = 0; XtSetArg(arg[i], XtNheight, vah + 2); i++;
  XtSetValues(textBox,  arg, i);
  i = 0; XtSetArg(arg[i], XtNheight, &vbh); i++;
  XtGetValues(menuForm, arg, i);
  i = 0; XtSetArg(arg[i], XtNheight, vbh + 2 ); i++;
  XtSetValues(menuBox,  arg, i); 
  i = 0; XtSetArg(arg[i], XtNwidth, vbh + 2 ); i++;
  XtSetValues(menuBox, arg, i);

}


int InstantiateNodeLabels()
{
  Arg         arg[2];
  char       *curL;
  int         dir;
  int         asc;
  int         dsc;
  XCharStruct info;

  curL = (char *)XtMalloc(NAME_LENGTH + 8);
  XtSetArg(arg[0], XtNlabel, curL);

  sprintf(curL, "Help on ``%s''", node);
  XtSetValues(nodeLabel, arg, 1);

  if (strlen(next) > 0) sprintf(curL, "Next: %s", next);
  else                  sprintf(curL, "Next: (none)");
  XTextExtents(helpCommFont, curL, strlen(curL), &dir, &asc, &dsc, &info);
  XtSetArg(arg[1], XtNwidth, info.width + 10);
  XtSetValues(nextButton, arg, 2);

  if (strlen(prev) > 0) sprintf(curL, "Prev: %s", prev);
  else                  sprintf(curL, "Prev: (none)");
  XTextExtents(helpCommFont, curL, strlen(curL), &dir, &asc, &dsc, &info);
  XtSetArg(arg[1], XtNwidth, info.width + 10);
  XtSetValues(prevButton, arg, 2);

  if (strlen( up ) > 0) sprintf(curL, "Up: %s", up);
  else                  sprintf(curL, "Up: (none)");
  XTextExtents(helpCommFont, curL, strlen(curL), &dir, &asc, &dsc, &info);
  XtSetArg(arg[1], XtNwidth, info.width + 10);
  XtSetValues(upButton, arg, 2);

  XtFree(curL);
  return 0;
}


int InstantiateRoutedNode()
{
  HelpSearchPage *routEnd;
  HelpSearchPage *routPre;
  char            comment[25];
  int             vC = 1;

  routEnd = helpRout;
  routPre = NULL;

  while (routEnd) {

    if (!strcmp(routEnd->page, node)) {

      vC = routEnd->frequency + 1;

      if (routPre) {
	routPre->next = routEnd->next;
	if    (routEnd->comment) XtFree(routEnd->comment);
	XtFree(routEnd->page);
	XtFree((char *)routEnd);
	routEnd  = routPre->next;

      } else {
	helpRout = routEnd->next;
	if    (routEnd->comment) XtFree(routEnd->comment);
	XtFree(routEnd->page);
	XtFree((char *)routEnd);
	routEnd  = helpRout;
      }
    } else {

      routPre = routEnd;
      routEnd = routEnd->next;
    }
  }

  routEnd = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));
  routEnd->page       = XtNewString(node);
  routEnd->frequency  = vC;
  routEnd->next       = NULL;

  if      (vC  < 2) routEnd->comment = XtNewString(" ");
  else if (vC == 2) routEnd->comment = XtNewString(" (Visited twice)");
  else {
    sprintf( comment," (Visited %d times)",vC);
    routEnd->comment = XtNewString(comment);
  }

  if (routPre) routPre->next = routEnd;
  else helpRout = routEnd;

  return 0;
}



XFontStruct *GetFontForMode()
{
  switch(helpMode) {

  case HelpHeadMode:
    return helpHeadFont;

  case HelpTextMode:
    return helpTextFont;

  case HelpXmplMode:
    return helpXmplFont;

  case HelpMenuMode:
    return helpTextFont;

  default:
    HelpError2d("Warning: Unknown internal mode", helpMode);
    return helpTextFont;
  }
}


/* Create a label or command widget.  Arguments are: index of widget in  */
/* array; text to place in widget; flag for whether or not the widget    */
/* is a cross-reference (ie. highlighted and clickable); and flag for    */
/* whether or not a new line should be started for this widget (if not,  */
/* it will appear, we hope, after the previous widget on the same line.) */
/* Returns the new value of lab, or -1 to indicate failure.              */

int MakeWidget(lab, text, hl, nl)
  int      lab;
  char   * text;
  Boolean  hl;
  Boolean  nl;
{
  static Widget above = NULL;
  Widget       *labels;
  int           paneHt;
  
/*
  fprintf(stderr,"Making widget, lab %d, text \"%s\"\n",lab,text);
*/
  
  labels = MenuP ? menuLabels : textLabels;
  paneHt = MenuP ? menuPaneHt : helpPaneHt;

  if (lab > MAX_LABELS) return HelpError("Maximum text per page exceeded");
  if (lab == 0) { above = NULL;          paneHt = 0; }
  else if (nl)  { above = labels[lab-1]; paneHt  ++; }

  if (helpMode == HelpHeadMode && nl && lab > 0) {

    Arg    arg;
    char * txt;

    XtSetArg(arg, XtNlabel, &txt);
    XtGetValues(labels[lab-1], &arg, 1);

    while (*txt)
      if (isprint(*txt)) { helpMode = HelpTextMode; break; }
      else txt++;
  }

  if (MenuP) menuPaneHt = paneHt;
  else       helpPaneHt = paneHt;

  if (!nl && !hl && lab > 1 && XtClass(labels[lab-1]) == labelWidgetClass) {

    Arg    arg;
    char * prevText;
    char * totlText;
    int    prevLen;

    XtSetArg(arg, XtNlabel, &prevText);
    XtGetValues(labels[lab-1], &arg, 1);

    totlText = (char *)XtMalloc((prevLen=strlen(prevText)) + strlen(text) + 1);
    strcpy(totlText,  prevText);
    strcpy(totlText + prevLen, text);

    XtSetArg(arg, XtNlabel, totlText);
    XtSetValues(labels[lab-1], &arg, 1);

    XtFree((char *)totlText);
    return lab;

  } else {

    Arg arg[11];
    int i;

    i = 0; XtSetArg(arg[i], XtNfont, (hl?helpXrefFont:GetFontForMode())); i++;
           XtSetArg(arg[i], XtNlabel,                              text); i++;
           XtSetArg(arg[i], XtNborderWidth,                           0); i++;
           XtSetArg(arg[i], XtNhighlightThickness,                    1); i++;
	   XtSetArg(arg[i], XtNhorizDistance,       nl? 2*LABEL_SPACE:0); i++;
           XtSetArg(arg[i], XtNinternalHeight,            LABEL_SPACE/2); i++;
           XtSetArg(arg[i], XtNinternalWidth,         hl? LABEL_SPACE:0); i++;
	   XtSetArg(arg[i], XtNvertDistance,     above? 0:LABEL_SPACE*5); i++;
    if (lab > 0) {
           XtSetArg(arg[i], XtNfromHoriz,      (nl ? 0 : labels[lab-1])); i++;
	   XtSetArg(arg[i], XtNfromVert,                          above); i++;
	 }

    if (labels[lab] && 
	XtClass(labels[lab]) != (hl ? commandWidgetClass : labelWidgetClass)) {
           XtDestroyWidget(labels[lab]); labels[lab] = NULL;
    }
    if (labels[lab]) { XtSetValues(labels[lab], arg, i);}
    else {
      labels[lab] = XtCreateWidget((hl? "helpXref" : "helpText"),
				   (hl? commandWidgetClass : labelWidgetClass),
				   (MenuP ? menuForm  : textForm), arg, i);
      if (hl)
	if (MenuP)
	  XtAddCallback(labels[lab], XtNcallback, HelpMenuButton, 0);
	else
	  XtAddCallback(labels[lab], XtNcallback, HelpXrefButton, 0);
    }
    return ++lab;
  }
}



/* Takes two arguments, and displays some text in the normal text window.    */
/* Returns 0 for success, or other for failure.  The first arg is the text;  */
/* the second is a Multi-Purpose Flag.  Normally it is True if the text is   */
/* a cross-reference (to be highlighted and clickable); if the text is NULL  */
/* then if the flag is True, the window is cleared and prepared for a new    */
/* page, and if False, the current page is finished and displayed.           */
/* The third arg is True if the text is to be placed in the Menu window and  */
/* False if it is to go in the normal text window.  This also has a bearing  */
/* upon the formatting of cross-references (in menus they always start a     */
/* new line).  Menu and Text strings mustn't be mixed; finish one lot first. */

/* Does not preserve text argument.  Always call with a new clean string.    */


int PlaceText(text,hl)
  char   *text;
  Boolean hl;
{
  static int      lab = 0;      /* current label (or command) widget      */
  static Boolean  nln = False;	/* if next widget should start new line   */
  static unsigned pll = 0;	/* pixels so far on line                  */

  int         i;
  int         nwl;
  int         swl;
  int         dir;
  int         asc;
  int         dsc;
  unsigned    wwd;
  XCharStruct info;


  if (text == NULL)
    if (hl) {

      Widget *labels;
      labels = MenuP ? menuLabels : textLabels;

      for (lab = 0;
	   lab < MAX_LABELS && labels[lab] && XtIsManaged(labels[lab]); ++lab);
      if  (lab > 0) XtUnmanageChildren(labels, lab);

      pll  = 0;
      lab  = 0;
      return 0;

    } else {

      Widget *labels;
      labels = MenuP ? menuLabels : textLabels;

      if (MenuP) {

	Arg         arg[2];
	char       *txt;
	int         mwd = 0;


	for (i = 0; i < lab && menuLabels[i]; ++i) {

	  if (XtClass(menuLabels[i]) == commandWidgetClass) {

	    XtSetArg(arg[0], XtNlabel, &txt);
	    XtGetValues(menuLabels[i], arg, 1);
	    XTextExtents(helpXrefFont,txt,strlen(txt),&dir,&asc,&dsc,&info);

	    if (info.width > mwd) mwd = info.width;
	  }
	}

	XtSetArg(arg[0], XtNwidth, mwd + 10);
	XtSetArg(arg[1], XtNjustify, XtJustifyRight);

	if (mwd > 0)
	  for (i = 0; menuLabels[i]; ++i)
	    if (XtClass(menuLabels[i]) == commandWidgetClass)
	      XtSetValues(menuLabels[i], arg, 2);

      }

      for (i = lab;
	   i < MAX_LABELS && labels[i] && XtIsManaged(labels[i]); ++i);

      if (i > lab) XtUnmanageChildren(labels+lab, i-lab);
      if (lab > 0)   XtManageChildren(labels,       lab);

      return 0;
    }

  /*
  fprintf(stderr,"Displaying text \"%s\" with highlight flag %d\n", text, hl);
  */

  if      ((nwl = strlen(text)) == 0) return 0;
  while   (nwl  > 0 && text[nwl-1] == END_OF_LINE) text[--nwl] = 0;
  if      (nwl == 0) { nln = True; return 0; }
  if      (MenuP) {
    while (*text == ' ' && *(text+1) == ' ') { text ++; nwl --; }
    nln = hl;
 
  } else if (nwl > 3 && (strchr(text,'_') != NULL)) {

    for (swl = nwl;
	 swl >  0  && (isspace(text[swl-1]) || text[swl-1] == '_'); --swl);
    if  (swl == 0)
      if (helpMode == HelpXmplMode) { helpMode = HelpTextMode; return 0; }
      else                          { helpMode = HelpXmplMode; return 0; }
  }

  for (i = 0; text[i]; ++i) if (text[i] == END_OF_LINE) text[i] = ' ';

  if (!MenuP) {

    XTextExtents(hl ? helpXrefFont : GetFontForMode(),
		 text, nwl, &dir, &asc, &dsc, &info);

    wwd = (unsigned)(info.width) + (hl ? LABEL_SPACE : 0);

    if (pll + wwd > helpTextWd) nln = True;
    if (nln) pll  = wwd;
    else     pll += wwd;
  }

  Try(lab = MakeWidget(lab, text, hl, nln));

  nln = False;

  return 0;

 oops: return HelpError("Cannot construct text display widgets");
}



int DisplayPage(adr, routeFlag)
  long    adr;
  Boolean routeFlag;
{
  int     state;
  char    c;
  char    pch;
  char    ignore;
  char    newl[2];
  char   *sprBuf;
  Arg     arg;

  helpMode = HelpHeadMode;

  Try(PlaceText(NULL, True));
  if (fseek(helpFile, adr, 0)) return HelpError2d("Can't find node at",adr);

  pch      = 0;
  ignore   = 0;
  state    = 0;
  bPoint   = 0;
  nrTable  = 0;
  next[0]  = 0;
  prev[0]  = 0;
    up[0]  = 0;

  switch(displayMode) {

  case HelpRouteDisplay:

    XtSetArg(arg, XtNlabel, "Show Route");
    XtSetValues(showButton, &arg, 1);
    break;

  case HelpSearchDisplay:

    XtUnmanageChild(searchLabel1);
    XtUnmanageChild(searchLabel2);
    XtUnmanageChild(searchText);
    XtUnmanageChild(searchGo);
    XtUnmanageChild(searchGuess);
    XtManageChild(prevButton);
    XtManageChild(upButton);
    XtManageChild(nextButton);
    XtSetArg(arg, XtNlabel, "Search");
    XtSetValues(searchButton, &arg, 1);
    break;
  }

  displayMode = HelpTextDisplay;

  XtSetArg(arg, XtNwidth, &helpTextWd);
  XtGetValues(textViewport, &arg, 1);
  if  (helpTextWd > 100) helpTextWd -= 30 + 2*LABEL_SPACE;
  else helpTextWd = 60;

  Try(ReadTag()); /* warum nur ??*/
 loop:

   Try(ReadTag());


  if        (!strcmp(tag, FILE_TAG)) {
    Try(ReadString(tag )); goto loop;
  } else if (!strcmp(tag, NODE_TAG)) {
    Try(ReadString(node)); goto loop;
  } else if (!strcmp(tag, NEXT_TAG)) {
    Try(ReadString(next)); goto loop;
  } else if (!strcmp(tag, PREV_TAG)) {
    Try(ReadString(prev)); goto loop;
  } else if (!strcmp(tag,   UP_TAG)) {
    Try(ReadString(up  ));
  } else (void)HelpError2s("Unknown or unexpected node tag:",tag);

  Try(InstantiateNodeLabels());
  if (routeFlag) Try(InstantiateRoutedNode());

  while ((c = ReadChar()) != (char)-1 && c != END_OF_PAGE) {

    if (ignore && c == ignore) {
      if (c == '.') ignore = ']';
      else          ignore =  0;
      continue;
    }

    switch(c) {

    case '*':

      if (bPoint > 0 && 
	  (isprint(buffer[bPoint-1]) && buffer[bPoint-1] != '[')) {

	buffer[bPoint++] = c;
	break;

      } else {

	if (bPoint > 0)
	  if (buffer[bPoint-1] == '[') -- bPoint;
	  else if (isalnum(buffer[bPoint-1]) ||
		   buffer[bPoint-1] == '*'   ||
		   buffer[bPoint-1] == ')') {

	    buffer[bPoint++] = c;
	    state = 0;
	    break;
	  }

	buffer[bPoint] = 0;
	if (bPoint > 0) Try(PlaceText(buffer, False));

	state  = 2;
	bPoint = 0;
	break;
      }

    case ':':

      if      (state == 2) {
	state = 4;

	if (!MenuP &&
	    (!strncasecmp(buffer, "menu",bPoint) ||
	     !strncasecmp(buffer," menu",bPoint))) {

	  Try(PlaceText(NULL, False));
	  helpMode = HelpMenuMode;
	  Try(PlaceText(NULL,  True));
	}
      }
      else if (state == 4) {

	sprBuf = buffer;
	buffer[bPoint] = 0;
	if (bPoint > 4 && !strncasecmp(buffer, "note ", 5)) sprBuf += 5;
	if (bPoint > (sprBuf - buffer)) Try(PlaceText(sprBuf, True));
	state  =  0;
	bPoint =  0;
	ignore = '.';
      }
      else buffer[bPoint++] = c;

      break;

    case END_OF_LINE:

      if ((pch      == END_OF_LINE)  ||
	  (state    == 0 && MenuP)   ||
	  (helpMode == HelpXmplMode)) {

	buffer[bPoint] = 0;
	if (bPoint > 0) Try(PlaceText(buffer, False));
	  
	bPoint  = 0;	
	newl[0] = END_OF_LINE;
	newl[1] = 0;
	Try(PlaceText(newl, False));

	if (helpMode != HelpXmplMode && !MenuP) {

	  newl[0] = ' ';
	  newl[1] = 0;
	  Try(PlaceText(newl, False));
	  newl[0] = END_OF_LINE;
	  newl[1] = 0;
	  Try(PlaceText(newl, False));
	}
	break;
	
      } else {

	if (state == 0) {
	  buffer[bPoint++] = ' ';
	  buffer[bPoint  ] = 0;
	  Try(PlaceText(buffer, False));
	  bPoint = 0;
	} else buffer[bPoint++] = ' ';
	break;
      }

    default:

      buffer[bPoint++] = c;

      if (!((state == 2 && bPoint < NAME_LENGTH) &&
	    (isalnum(c) ||
	     c == ' ' || c == '?' || c == '_' || c == '-' ||
	     c == ':' || c == '.' || c == '(' || c == ')' ||
	     c == '!' || c == '%' || c == '^' ||
	     (c == '*' && bPoint > 0 &&
	      (isprint(buffer[bPoint-1]) && buffer[bPoint-1] != '[')) ||
	     (c == ' ' && bPoint > 0)))) state = 0;

      if (isspace(c) && state == 0 &&
	  bPoint > 1 && !isspace(buffer[bPoint-2])) {

	buffer[bPoint] = 0;
	Try(PlaceText(buffer, False));
	bPoint = 0;
      }
    }
    pch = c;
  }

  if (bPoint > 0) Try(PlaceText(buffer, False));
  Try(PlaceText(NULL, False));
  if (!MenuP) {
    helpMode    = HelpMenuMode;
    Try(PlaceText(NULL,  True));
    Try(PlaceText(NULL, False));
    menuPaneHt  = 0;
  }

  Try(SizePanes());

  return 0;

 oops:

  return HelpError("Failed to read and display page data correctly");
}


int DisplayChoices(comment,choice)
  char           *comment;
  HelpSearchPage *choice;
{
  HelpSearchPage *current;
  char           *text;

  helpMode   = HelpHeadMode;

  Try(PlaceText(NULL,  True));
  Try(PlaceText(NULL, False));

  text       = XtNewString(comment);
  menuPaneHt = 0;
  helpMode   = HelpMenuMode;

  Try(PlaceText(NULL,  True));
  Try(PlaceText(text, False));
  XtFree(text);

  for (current = choice; current; menuPaneHt ++, current = current->next) {

    text = XtNewString(current->page);
    Try(PlaceText(text, True));
    XtFree(text);

    text = XtNewString(current->comment);
    Try(PlaceText(text, False));
    XtFree(text);
  }

  Try(PlaceText(NULL, False));
  Try(SizePanes());
 return 0;

 oops:
  return HelpError2s("Choice list display failed, next item",current->page);
}


/*ARGSUSED*/
void HelpQuitButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  int i;

  if (guessMode && displayMode == HelpSearchDisplay) SearchGuess(w,a,b);

  XtPopdown(helpSh);

  for (i = 0; textLabels[i]; ++i) XtDestroyWidget(textLabels[i]);
  for (i = 0; menuLabels[i]; ++i) XtDestroyWidget(menuLabels[i]);

  XtDestroyWidget(helpSh);
  helpInstalled = False;
  fileLabel     = NULL;
  return;
}


/*ARGSUSED*/
void HelpDoneButtonAction(w, event)
  Widget w;
  XButtonEvent *event;
{
  HelpQuitButton(w, 0, 0);
}


/*ARGSUSED*/
void HelpShowButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  Arg arg;

  switch(displayMode) {

  case HelpRouteDisplay:

    XtSetArg(arg, XtNlabel, "Show Route");
    XtSetValues(showButton, &arg, 1);

    Try(DisplayPage(actNode, False));

    return;

  case HelpSearchDisplay:

    XtUnmanageChild(searchLabel1);
    XtUnmanageChild(searchLabel2);
    XtUnmanageChild(searchText);
    XtUnmanageChild(searchGo);
    XtUnmanageChild(searchGuess);
    XtManageChild(prevButton);
    XtManageChild(upButton);
    XtManageChild(nextButton);
    XtSetArg(arg, XtNlabel, "Search");
    XtSetValues(searchButton, &arg, 1);

    /* deliberately fall through */

  case HelpTextDisplay:

    displayMode = HelpRouteDisplay;

    helpPaneHt = 0;
    Try(DisplayChoices("\nPages visited so far:\n\n",helpRout));

    XtSetArg(arg, XtNlabel, "Show Current Page");
    XtSetValues(showButton, &arg, 1);

    return;
  }

 oops:
  (void)HelpError("Cannot display Show-Route page");
  return;
}


void HelpClose()
{
  if (helpInstalled) HelpQuitButton(quitButton, 0, 0);
  return;
}


/*ARGSUSED*/
void HelpPrevButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  if (strlen(prev) == 0) {

    XBell(XtDisplay(referenceWidget), 50);
    return;
  }

  TrL(actNode = FindNode(prev));
  Try(DisplayPage(actNode, True));
  return;

 oops: (void)HelpError2s("Problem in displaying help page for",prev);
  return;
}


/*ARGSUSED*/
void HelpNextButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  if (strlen(next) == 0) {

    XBell(XtDisplay(referenceWidget), 50);
    return;
  }

  TrL(actNode = FindNode(next));
  Try(DisplayPage(actNode, True));
  return;

 oops: (void)HelpError2s("Problem in displaying help page for",next);
  return;
}


/*ARGSUSED*/
void HelpUpButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  if (strlen(up) == 0 || !strcmp(up,"(dir)")) {

    XBell(XtDisplay(referenceWidget), 50);
    return;
  }

  TrL(actNode = FindNode(up));
  Try(DisplayPage(actNode, True));
  return;

 oops: (void)HelpError2s("Problem in displaying help page for",up);
  return;
}


/*ARGSUSED*/
void HelpMenuButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  int   i;
  int   n = -1;
  Arg   arg;
  char *xref;

  for (i = 0; i < MAX_LABELS && menuLabels[i]; ++i)
    if (menuLabels[i] == w) { n = i; break; }

  if (n == -1) {
    (void)HelpError("Unknown and undereferenceable menu button pressed");
    return;
  }

  XtSetArg(arg, XtNlabel, &xref);
  XtGetValues(menuLabels[n], &arg, 1);
  while (*xref && isspace(*xref)) xref ++;

  TrL(actNode = FindNode(xref));
  Try(DisplayPage(actNode, True));
  return;

 oops: (void)HelpError2s("Problem in displaying help page for",xref);
  return;
}



/*ARGSUSED*/
void HelpXrefButton(w, a, b)
  Widget w;
  caddr_t a, b;
{
  int   i;
  int   n = -1;
  Arg   arg;
  char *xref;

  for (i = 0; i < MAX_LABELS && textLabels[i]; ++i)
    if (textLabels[i] == w) { n = i; break; }

  if (n == -1) {
    (void)HelpError("Unknown and undereferenceable xref button pressed");
    return;
  }

  XtSetArg(arg, XtNlabel, &xref);
  XtGetValues(textLabels[n], &arg, 1);
  while (*xref && isspace(*xref)) xref ++;

  TrL(actNode = FindNode(xref));
  Try(DisplayPage(actNode, True));
  return;

 oops: (void)HelpError2s("Problem in displaying help page for",xref);
  return;
}



int HelpInstallHelp()
{
  Arg   arg;
  char *fL;
  Atom  wmPrtcls[2];

  if (helpInstalled) {

    XRaiseWindow(XtDisplay(referenceWidget),XtWindow(helpSh));
    return 0;

  } else {

    Try(CreateContainingWidgets());
    XtAddCallback(   quitButton, XtNcallback,   HelpQuitButton, 0);
    XtAddCallback( searchButton, XtNcallback, HelpSearchButton, 0);
    XtAddCallback(   showButton, XtNcallback,   HelpShowButton, 0);
    XtAddCallback(   prevButton, XtNcallback,   HelpPrevButton, 0);
    XtAddCallback(     upButton, XtNcallback,     HelpUpButton, 0);
    XtAddCallback(   nextButton, XtNcallback,   HelpNextButton, 0);

    wmPrtcls[0] =
      XInternAtom(XtDisplay(helpSh), "WM_DELETE_WINDOW", False);
    wmPrtcls[1] =
      XInternAtom(XtDisplay(helpSh), "WM_SAVE_YOURSELF", False);
    XtOverrideTranslations
      (helpSh,
       XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-help-done()"));
    XSetWMProtocols(XtDisplay(helpSh), XtWindow(helpSh), wmPrtcls, 2);

    helpInstalled = True;

    if (helpFile == NULL) { HelpClose();
			    return HelpError("No help available\n"); }
    if (topNode  ==   -1) { HelpClose();
			    return HelpError("Can't find Top node\n"); }
    if (actNode  ==   -1) actNode = topNode;

    XtPopup(helpSh, XtGrabNone);
    XRaiseWindow(XtDisplay(helpSh), XtWindow(helpSh));

    fL = (char *)XtMalloc(strlen(hefiName) + 10);
    sprintf(fL, "File: %s", hefiName);
    XtSetArg(arg, XtNlabel, fL);
    XtSetValues(fileLabel, &arg, 1);
    XtFree(fL);

    Try(DisplayPage(actNode, True));
    return 0;
  }

 oops: HelpClose(); return HelpError("Can't install Help facility");
}


int HelpSetTextFont(fn)
  char *fn;
{
  if ((helpTextFont= EnsureFont(XLoadQueryFont(XtDisplay(referenceWidget),fn)))
      == NULL) goto oops;

  if (helpInstalled) Try(DisplayPage(actNode, True));
  return 0;

 oops: return HelpError2s("Cannot load default font",DEFAULT_FONT);
}  


int HelpSetXrefFont(fn)
  char *fn;
{
  if ((helpXrefFont= EnsureFont(XLoadQueryFont(XtDisplay(referenceWidget),fn)))
      == NULL) goto oops;

  if (helpInstalled) Try(DisplayPage(actNode, True));
  return 0;

 oops: return HelpError2s("Cannot load default font",DEFAULT_FONT);
}  


int HelpSetButtonFont(fn)
  char *fn;
{
  if ((helpCommFont= EnsureFont(XLoadQueryFont(XtDisplay(referenceWidget),fn)))
      == NULL) goto oops;

  if (helpInstalled) Try(DisplayPage(actNode, True));
  return 0;

 oops: return HelpError2s("Cannot load default font",DEFAULT_FONT);
}  


int HelpSetTitleFont(fn)
  char *fn;
{
  if ((helpHeadFont= EnsureFont(XLoadQueryFont(XtDisplay(referenceWidget),fn)))
      == NULL) goto oops;

  if (helpInstalled) Try(DisplayPage(actNode, True));
  return 0;

 oops: return HelpError2s("Cannot load default font",DEFAULT_FONT);
}


int HelpSetVerbatimFont(fn)
  char *fn;
{
  if ((helpXmplFont= EnsureFont(XLoadQueryFont(XtDisplay(referenceWidget),fn)))
      == NULL) goto oops;

  if (helpInstalled) Try(DisplayPage(actNode, True));
  return 0;

 oops: return HelpError2s("Cannot load default font",DEFAULT_FONT);
}


char *HelpGetHelpFile()
{
  return hefiName;
}


int HelpInitialise(parent, wd, ht, name, callback)
  Widget    parent;
  Dimension wd;
  Dimension ht;
  char    * name;
  char * (* callback)();
{
  referenceWidget = parent;
  helpWd          = wd;
  helpHt          = ht;
  guess           = callback;
  helpName        = XtNewString(name);
  helpRout        = NULL;

  return 0;
}



/* The code that follows implements the Search facility.  We construct an  */
/* unbalanced binary search tree containing every significant word in the  */
/* Help file.  For each word there is a list of all nodes that refer to    */
/* the word, with a count of the number of times each node refers to it.   */
/* This list is kept in alphabetical order (not particularly useful!)      */
/* There is also a list of "insignificant words", which are to be ignored. */
/* The search is case-insensitive, and all words are stored in lower-case. */
/* We presume that the helpfile is known to be open, seekable &c.          */



HelpSearchPage *MakeSearchPage(cpage,stress)
  char *cpage;
  int   stress;
{
  HelpSearchPage *page;

  page = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));
  page->frequency = stress;
  page->page      = XtNewString(cpage);
  page->next      = NULL;

  return page;
}


HelpSearchTree *MakeSearchNode(cpage,word,stress)
  char *cpage;
  char *word;
  int   stress;
{
  HelpSearchTree *node;
  int             copy;

  node =   (HelpSearchTree *)XtMalloc(sizeof(HelpSearchTree));
  node->string     = (char *)XtMalloc(strlen(word) + 1);
  node->references = MakeSearchPage(cpage,stress);
  node->inferior   = NULL;
  node->superior   = NULL;

  for (copy = 0; word[copy]; ++copy) {
    (node->string)[copy] =
      isupper(word[copy]) ? tolower(word[copy]) : word[copy];
  } (node->string)[copy] = 0;

  return node;
}


int StoreInGivenNode(cpage,node,stress)
  char           *cpage;
  HelpSearchTree *node;
  int             stress;
{
  HelpSearchPage *curr;
  HelpSearchPage *prev;
  int             cmp;

  curr = node->references;
  prev = NULL;

  while (curr && ((cmp = strcmp(curr->page,cpage)) < 0)) {
    prev = curr;
    curr = curr->next;
  }

  if (curr && !cmp) curr->frequency += stress;

  else {

    if (prev)   prev->next       = MakeSearchPage(cpage,stress);
    else        node->references = MakeSearchPage(cpage,stress);

    if (curr)
      if (prev) prev->next->next       = curr;
      else      node->references->next = curr;
  }

  return 0;
} 


int StoreInGivenTree(cpage,word,tree,stress)
  char           *cpage;
  char           *word;
  HelpSearchTree *tree;
  int             stress;
{
  int cmp;

  if (cmp = strcasecmp(word, tree->string))
    if (cmp < 0)
      if (tree->inferior)
	return StoreInGivenTree(cpage,word,tree->inferior,stress);
      else return (tree->inferior = MakeSearchNode(cpage,word,stress), 0);
    else
      if (tree->superior)
	return StoreInGivenTree(cpage,word,tree->superior,stress);
      else return (tree->superior = MakeSearchNode(cpage,word,stress), 0);
  else
    return StoreInGivenNode(cpage,tree,stress);
}


int StoreMenuDescription(cpage,comment)
  char *cpage;
  char *comment;
{
  HelpSearchPage *current;
  HelpSearchPage *prev;

  for (prev = NULL, current = comments; current;
       prev = prev ? prev->next : comments, current = current->next)
    if (!strcmp(cpage,current->page)) return 0;

  if (prev)
    current = prev->next = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));
  else
    current = comments   = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));

  current->page    = XtNewString(cpage);
  current->comment = XtNewString(comment);
  current->next    = NULL;

  return 0;
}


int StoreSearchWord(cpage,word,accinit,stress,menuP)
  char   *cpage;
  char   *word;
  Boolean accinit;
  int     stress;
  Boolean menuP;
{
  static Boolean accept = True;
  static int     cix    = 0;
  static int     eix    = 0;
  static char    comment[NAME_LENGTH];
  static char    lastEnt[NAME_LENGTH];
  char         **currIW;
  int            i;
  int            j;

  /* If word only contains underscores (several), reject and flip accept */
  
  if (accinit) accept = True;
  else {

    for (i = j = 0; word[i] && word[i] == '_'; ++i, ++j);
    if (!word[i] && j > 3) {
      accept = !accept;
      return 0;
    }
  }

  if (!accept) return 0;

  /* If this is a menu item description, build it, or consider */
  /* storing a built description for saving later              */

  if (menuP)

    if (stress == 1) {

      if (cix + (i = strlen(word)) >= NAME_LENGTH - 2) {
	comment[cix = 0] = 0;
	return HelpError2s("Menu description overflow, word",word);
      }

      if (cix > 0) comment[cix++] = ' ';
      strcpy(comment + cix, word);
      cix += i;

    } else {

      if (cix > 0) {
	Try(StoreMenuDescription(lastEnt,comment));
	comment[cix = 0] = 0;
	lastEnt[eix = 0] = 0;
      }

      if (eix + (i = strlen(word)) >= NAME_LENGTH - 2) {
	lastEnt[eix = 0] = 0;
	return HelpError2s("Menu entry overflow, word",word);
      }

      if (i > 0) {
	if (eix > 0) lastEnt[eix++] = ' ';
	strcpy(lastEnt + eix, word);
	eix += i;
      }
    }

  /* Reject any word in the Insignificant Word List */

  for (currIW = insignificantWords; currIW && *currIW; ++currIW)
    if (!strcasecmp(word,*currIW)) return 0;

  /* Reject any word not containing alphabetical characters */

  for (i = 0; word[i] && !isalpha(word[i]); ++i);
  if (!word[i]) return 0;

  /* Store word */

  if (searchBT) {
    Try(StoreInGivenTree(cpage,word,searchBT,stress));
  } else searchBT = MakeSearchNode(cpage,word,stress);

  return 0;

 oops: return HelpError("Couldn't store word information in search tree");
}


HelpSearchPage *HelpSortRefList(p)	/* It's a crap bubble sort!! */
  HelpSearchPage *p;
{
  Boolean         finished = False;
  HelpSearchPage *pre;
  HelpSearchPage *cur;

  while (!finished)

    for  (cur = p, finished = True, pre = NULL;
	  cur && cur->next; pre = cur, cur = cur->next)

      if (cur->frequency < cur->next->frequency) {

	if (pre) pre->next = cur->next; else p = cur->next;
	cur->next = cur->next->next;
	if (pre) pre->next->next = cur; else p->next = cur;
	finished = False;
      }

  return p;
}


int HelpTrimSearchTree(node)
  HelpSearchTree *node;
{
  HelpSearchPage *refs;
  HelpSearchPage *prefs = NULL;

  if (node) {

    if (node->inferior) Try(HelpTrimSearchTree(node->inferior));

    refs = node->references;

    while (refs)

      if (refs->frequency < 2) {

	if (prefs) prefs->next = refs->next;
	else  node->references = refs->next;

	XtFree(refs->page);
	XtFree((char *)refs);

	if (prefs) refs = prefs->next;
	else       refs = node->references;

      } else {

	prefs = refs;
	refs  = refs->next;
      }

    if (node->references) node->references = HelpSortRefList(node->references);
    if (node->superior) Try(HelpTrimSearchTree(node->superior));
  }

  return 0;

 oops: return HelpError("Couldn't trim search tree");
}	  


int HelpReinstallNode(node,parent)
  HelpSearchTree *node;
  HelpSearchTree *parent;
{
  if (strcasecmp(node->string,parent->string) < 0)

    if  (parent->inferior) return HelpReinstallNode(node,parent->inferior);
    else parent->inferior = node;

  else

    if  (parent->superior) return HelpReinstallNode(node,parent->superior);
    else parent->superior = node;

  return 0;
}


int HelpDeleteNode(node,parent)
  HelpSearchTree *node;
  HelpSearchTree *parent;
{
  if (parent) {

    if (node == parent->inferior) parent->inferior = NULL;
    else                          parent->superior = NULL;

    if (node->inferior) Try(HelpReinstallNode(node->inferior,parent));
    if (node->superior) Try(HelpReinstallNode(node->superior,parent));

  } else {

    searchBT = node->inferior;

    if (node->superior) {
      searchBT = node->superior;
      if (node->inferior)
	Try(HelpReinstallNode(node->inferior,node->superior));
    }
  }

  if (node->references) XtFree((char *)(node->references));
  XtFree(node->string);
  XtFree((char *)node);

  return 0;

 oops: return HelpError("Couldn't delete node in search tree");
}


int HelpDeleteEmptyNodes(node,parent)
  HelpSearchTree *node;
  HelpSearchTree *parent;
{
  if (node) {

    if (node->inferior) Try(HelpDeleteEmptyNodes(node->inferior,node));
    if (node->superior) Try(HelpDeleteEmptyNodes(node->superior,node));
    if (node->references == NULL) Try(HelpDeleteNode(node,parent));
  }

  return 0;

 oops: return HelpError("Couldn't delete unwanted nodes from search tree");
}


/* A somewhat tagliatelle-alla-carbonaraesque function, possibly  */
/* accompanied by cheap Lambrusco.  Supposed to build up the tree */
/* of references for each word in the help file.  Relies largely  */
/* on the equally pasta-inclined function StoreSearchWord, some   */
/* pages overhead.  This whole machine badly needs rewriting;     */
/* at the moment it appears to be wobbly but working.             */

int HelpBuildSearchTree()
{
  char    current[NAME_LENGTH];
  char    c;
  int     i, j;
  int     nextstress = 1;
  long    cct = 0;
  Boolean menuP;

  if (fseek(helpFile, 0, 0)) return HelpError("Can't rewind help file");
  Try(SkipChar(END_OF_PAGE));

 getpage:

  Try(SkipChar(END_OF_LINE));

 gettags:

  Try(ReadTag());

  if        (!strcmp(tag,  TOC_TAG)) {
    Try(   HelpTrimSearchTree(searchBT));
    Try( HelpDeleteEmptyNodes(searchBT));
    return 0;
  }else if (!strcmp(tag, FILE_TAG)) {
    Try(ReadString(buffer));
    goto gettags;
  } else if (!strcmp(tag, NODE_TAG)) {
    Try(ReadString(current));
    for (i = j = 0; current[i]; ++i)
      if (isspace(current[i])) {
	if (i > j) {
	  c = current[i];
	  current[i] = 0;
	  Try(StoreSearchWord(current,current+j,True,nextstress,False));
	  current[i] = c;
	} j = i;
      }
  } else (void)HelpError2s("Unknown or unexpected node tag:",tag);

  Try(SkipChar(END_OF_LINE));
  if (writingSearch) fprintf(stderr,"[%d] ",++cct);
  menuP = False;

 getword:

  bPoint = 0;

  while (bPoint < MAX_BUFFER &&
	 (c = ReadChar()) != (char)-1 &&
	 (isalnum(c) || c == '!' || c == '\\' || c == '_' ||
	  (c == '-' && bPoint > 0) ||
	  (!isspace(c) && bPoint > 0 &&
	   (buffer[bPoint-1] == '!' ||
	    buffer[bPoint-1] == '\\')))) buffer[bPoint++] = c;

  while (bPoint > 0 &&
	 (buffer[bPoint-1] == '\\' || 
	  (buffer[bPoint-1] == '!' &&
	   (bPoint == 1 || buffer[bPoint-2] != '!')))) --bPoint;

  if (bPoint > 0) {
    buffer[bPoint] = 0;
    if (bPoint >= MAX_BUFFER) return HelpError2s("Word too long:",buffer);
    Try(StoreSearchWord(current,buffer,False,nextstress,menuP));
  }

  if (nextstress == 2 && c == ':') nextstress = 1;

  if (bPoint == 0 && c == '*') {

    while (bPoint < MAX_BUFFER && (c = ReadChar()) != (char)-1 &&
	   isalnum(c) || (!menuP && isspace(c) && bPoint == 0))
      if (!isspace(c)) buffer[bPoint++] = c;

    if (menuP || !strncasecmp(buffer, "note", bPoint)) nextstress = 2;
    else     if (!strncasecmp(buffer, "menu", bPoint)) menuP = True;
  }

  if (c == END_OF_PAGE) {
    if (menuP) StoreSearchWord(current,"",True,2,menuP);
    goto getpage;
  } else goto getword;

 oops: return HelpError("Couldn't build help search tree");
}


/* Write the help index file.  The format is as follows: the first line */
/* contains the fseek index of the table of contents in the help file;  */
/* the rest of the file contains entries formatted like this one:

vector
"MASS" 8
"G" 7
"INDEX" 6
"DOT_SIGN" 5
"High Energy Physics section" 3
"EPS" 2

   with succeeding entries separated by one or more blank lines.  The   */
/* fields present here show that the word "vector" is found in the page */
/* called "MASS", with a priority of 8, "G", with a priority of 7, and  */
/* so on.  The lines are sorted by priority number.                     */


int HelpWriteTreeToIndexFile(tree)
  HelpSearchTree *tree;
{
  HelpSearchPage *page;
  HelpSearchPage *comm;
  Boolean         gotC;

  if (tree) {

    if (tree->inferior) Try(HelpWriteTreeToIndexFile(tree->inferior));

    fprintf(helpSFil, "\n%s\n", tree->string);
    for (page = tree->references; page; page = page->next) {

      for (comm = comments, gotC = False; comm; comm = comm->next)
	if (!strcmp(page->page, comm->page)) {
	  fprintf(helpSFil, "\"%s\" \" %s\" %d\n",
		  page->page, comm->comment, page->frequency);
	  gotC = True;
	  break;
	}
      if (!gotC) fprintf(helpSFil, "\"%s\" \" \" %d\n",
			 page->page, page->frequency);
    }

    if (tree->superior) Try(HelpWriteTreeToIndexFile(tree->superior));
  }

  return 0;

 oops: return HelpError("Couldn't traverse tree properly");
}


int HelpWriteIndexFile()
{
  if (TOCNode < 0) return HelpError("No reference for TOC found");
  if (!hesfName)   return HelpError("No name for help index file available");

  if (helpSFil) fclose(helpSFil);
  if (!(helpSFil = fopen(hesfName, "w")))
    return HelpError2s("Cannot open help index file",hesfName);

  writingSearch = True;

  fprintf(stderr,"\nThis is the XR info-based help module.\n");
  fprintf(stderr,"\nWriting help index file \"%s\"...\n", hesfName);
  fprintf(stderr,"Building search tree from \"%s\"...\n", hefiName);

  Try(HelpBuildSearchTree());

  fprintf(stderr,"\nWriting search tree to index file...\n");

  rewind(helpSFil);
  fprintf(helpSFil,"%ld\n",TOCNode);
  Try(HelpWriteTreeToIndexFile(searchBT));
  fprintf(helpSFil,"\n\n::END::\n\n");
  fflush(helpSFil);

  fprintf(stderr,"Finished writing search tree.\n");
  writingSearch = False;

  if (!(helpSFil = fopen(hesfName, "r")))
    return HelpError2s("Cannot open help index file",hesfName);

  return 0;

 oops: return HelpError("Couldn't write index file");
}



HelpSearchPage *Get1WordSearchPage(word)
  char *word;
{
  char            c, p;
  char            check[NAME_LENGTH];
  char          **currIW;
  HelpSearchPage *result = NULL;
  HelpSearchPage *endres = NULL;

  for(currIW = insignificantWords; currIW && *currIW; ++currIW)
    if (!strcasecmp(word,*currIW)) return NULL;

  if (!helpSFil) {
    (void)HelpError2s("No help index file; can't look up",word);
    return NULL;
  }

  rewind(helpSFil);

  for (check[0] = 0; strcasecmp(check, word); ) {

    for (c = p  = 0; c != END_OF_LINE || p != END_OF_LINE;
	 p = c, fread(&c, 1, 1, helpSFil))
      if (feof(helpSFil) || ferror(helpSFil)) return NULL;
    
    fscanf(helpSFil, "%s\n", check);
  }

 loop:

  fread(&c, 1, 1, helpSFil);
  if (feof(helpSFil) || ferror(helpSFil) || c != '"') return result;

  if (result) {
    endres->next    = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));
    endres = endres->next;
  } else
    endres = result = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));

  endres->page    = (char *)XtMalloc(NAME_LENGTH);
  endres->comment = (char *)XtMalloc(NAME_LENGTH);
  endres->next    = NULL;

  fscanf(helpSFil, "%[^\"]\" \"%[^\"]\" %d\n",
	 endres->page, endres->comment, &(endres->frequency));

  goto loop;
}



HelpSearchPage *GetStringTitlePage(str,frequency)
  char *str;
  int   frequency;
{
  int             i;
  HelpSearchPage *result;

  for (i = 0; i < nrNodes && strcasecmp(str, nname[i]); ++i);

  if (i >= nrNodes) return NULL;
  else {

    result = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));
    result->comment   = XtNewString(" ");
    result->page      = XtNewString(nname[i]);
    result->next      = NULL;
    result->frequency = frequency;

    return result;
  }
}    



/* Mergesort.  We have two page reference lists, which we know are each */
/* already sorted in descending order of frequency; we merge into one.  */
/* Discards and frees both the old lists completely.                    */

HelpSearchPage *MergeSearchPages(a, b)
  HelpSearchPage *a;
  HelpSearchPage *b;
{
  HelpSearchPage *result = NULL;
  HelpSearchPage *endres = NULL;
  HelpSearchPage *t;

  while (a || b) {

    if (result) {
      endres->next    = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));
      endres = endres->next;
    } else
      endres = result = (HelpSearchPage *)XtMalloc(sizeof(HelpSearchPage));

    if (a && (!b || (a->frequency > b->frequency))) {

      endres->page      = a->page;
      endres->frequency = a->frequency;
      endres->comment   = a->comment;

      t = a;
      a = a->next;
      XtFree((char *)t);

    } else {

      endres->page      = b->page;
      endres->frequency = b->frequency;
      endres->comment   = b->comment;

      t = b;
      b = b->next;
      XtFree((char *)t);
    }
  }

  if (endres) endres->next = NULL;
  return result;
}



/* We have a page list, and want to weed out repeated pages by summing the  */
/* frequency counts for the repetitions and putting the new larger count    */
/* in just the one of them.  We'll do this simply by doing lots of compares */
/* down the list; this isn't exactly a time-intensive bit of code.          */

/* This function suggests to me that either I should try and write it again */
/* only more neatly, or I should make the page-list doubly linked. Or both. */

HelpSearchPage *CutRedundancies(p)
  HelpSearchPage *p;
{
  HelpSearchPage *q;
  HelpSearchPage *r;
  HelpSearchPage *i;
  Boolean         ch = False;

  for (q = p; q && q->next; q = q->next)

    for (i = q, r = q->next; r; )

      if (!strcmp(q->page, r->page)) {

	ch            = True;
	q->frequency += r->frequency;
        i->next       = r->next;

	XtFree(r->page);
	XtFree(r->comment);
	XtFree((char *)r);
	r = i->next;

      } else {

	r = r->next;
	i = i->next;
      }

  if (ch) p = HelpSortRefList(p);
  return p;
}



HelpSearchPage *GetXWordSearchPage(ct)
  char *ct;
{
  HelpSearchPage *build = NULL;
  char           *text;
  int             i, j;
  char            c;

  text = XtNewString(ct);
  i = j = 0;
  while (text[i] && isspace(text[i])) ++i;
  if (!text[i]) return NULL; else j = i;

 loop:

  while ((c = text[i]) &&
	 (isalnum(c) || c == '!' || c == '\\' || c == '_' ||
	  (c == '-' && i > j) ||
	  (!isspace(c) && i > j &&
	   (text[i-1] == '!' || text[i-1] == '\\')))) ++i;

  text[i] = 0;

  if (i > j) {

    build = MergeSearchPages(build, Get1WordSearchPage(text + j));
    build = MergeSearchPages(build, GetStringTitlePage(text + j, 500));
  }

  if (c) {
    i = j = i+1;
    goto loop;
  } else {
    XtFree(text);
    return
      CutRedundancies(MergeSearchPages(build, GetStringTitlePage(ct, 1000)));
  }
}



/*ARGSUSED*/
void SearchGo(w, a, b)
  Widget w;
  caddr_t a,b;
{
  char *word;
  Arg   arg;

  XtSetArg(arg, XtNstring, &word);
  XtGetValues(searchText, &arg, 1);
  lastSearch = True;
  srchList   = GetXWordSearchPage(word);

  if (srchList) {
    Try(DisplayChoices("\nPossible pages, in approximate order:", srchList));
  } else {

    char *comment;

    comment = (char *)XtMalloc(strlen(word) + 50);
    sprintf(comment,"\nNo references found for \"%s\"",word);
    Try(DisplayChoices(comment, srchList));
    XtFree(comment);
  }

 oops: return;
}



/* ARGSUSED */
void SearchGuess(w, a, b)
  Widget w;
  caddr_t a,b;
{
  Arg          arg;
  static char *otherText;

  if (guessMode) {

    if (otherText) {

      XtSetArg(arg, XtNstring, otherText);
      XtSetValues(searchText, &arg, 1);
      XtFree(otherText);
      otherText = NULL;
    }

    XtSetArg(arg, XtNeditType, XawtextEdit);
    XtSetValues(searchText, &arg, 1);

    XtManageChild(searchGo);
    XtSetArg(arg, XtNlabel, "Guess Context");
    XtSetValues(searchGuess, &arg, 1);
    guessMode = False;
    SearchGo (searchGo, a, b);
    return;

  } else {

    char *tempText;

    XtSetArg(arg, XtNstring, &tempText);
    XtGetValues(searchText, &arg, 1);
    otherText = XtNewString(tempText);

    if ((tempText = guess()) == NULL) {  /* get text from parent's callback */

      XtFree(otherText);
      otherText = NULL;
      (void)HelpError("Can't get Search Context (sorry)");
      return;

    } else {

      XtUnmanageChild(searchGo);

      XtSetArg(arg, XtNstring, tempText);
      XtSetValues(searchText, &arg, 1);

      XtSetArg(arg, XtNeditType, XawtextRead);
      XtSetValues(searchText, &arg, 1);

      XtSetArg(arg, XtNlabel, "Return to User Search");
      XtSetValues(searchGuess, &arg, 1);

      XtFree(tempText);
      guessMode = True;
      SearchGo(searchGo, a, b);
      return;
    }
  }
}



/*ARGSUSED*/
void HelpSearchButton(w, a, b)
  Widget w;
  caddr_t a,b;
{
  Arg         arg;
  int         dir;
  int         asc;
  int         dsc;
  XCharStruct info;
  Dimension   slw;

  switch(displayMode) {

  case HelpSearchDisplay:

    if (guess != NULL) {
 
      guessMode = False;

      XtUnmanageChild(searchGuess);
      XtSetArg(arg, XtNlabel, "Guess Context");
      XtSetValues(searchGuess, &arg, 1);
    }

    XtUnmanageChild(searchLabel1);
    XtUnmanageChild(searchLabel2);
    XtUnmanageChild(searchText);
    XtUnmanageChild(searchGo);

    XtManageChild(prevButton);
    XtManageChild(upButton);
    XtManageChild(nextButton);

    XtSetArg(arg, XtNlabel, "Search");
    XtSetValues(searchButton, &arg, 1);
    XtSetKeyboardFocus(textForm, textForm);

    Try(DisplayPage(actNode, False));

    return;

  case HelpRouteDisplay:

    XtSetArg(arg, XtNlabel, "Show Route");
    XtSetValues(showButton, &arg, 1);

    /* deliberately fall through */

  case HelpTextDisplay:

    displayMode = HelpSearchDisplay;

    BEGARG;

    SETARG(searchLabel1, XtNfont,                   helpTextFont);
    SETARG(searchLabel1, XtNlabel,              "Search string:");
    SETARG(searchLabel1, XtNvertDistance,                     20);
    SETARG(searchLabel1, XtNborderWidth,                       0);
    SETARG(searchGuess,  XtNfont,                   helpCommFont);
    SETARG(searchGuess,  XtNlabel,               "Guess Context");
    SETARG(searchGuess,  XtNborderWidth,                       0);
    SETARG(searchGuess,  XtNhighlightThickness,                1);
    SETARG(searchGo,     XtNfont,                   helpCommFont);
    SETARG(searchGo,     XtNlabel,              "Execute Search");
    SETARG(searchGo,     XtNborderWidth,                       0);
    SETARG(searchGo,     XtNhighlightThickness,                1);
    SETARG(searchText,   XtNfont,                   helpTextFont);
    SETARG(searchText,   XtNfromHoriz,              searchLabel1);
    SETARG(searchText,   XtNvertDistance,                     21);
    SETARG(searchText,   XtNborderWidth,                       0);
    SETARG(searchText,   XtNeditType,                XawtextEdit);
    SETARG(searchText,   XtNresize,            XawtextResizeBoth);
    SETARG(searchLabel2, XtNlabel,                           " ");
    SETARG(searchLabel2, XtNfromVert,               searchLabel1);
    SETARG(searchLabel2, XtNborderWidth,                       0);
    SETARG(searchButton, XtNlabel,         "Return to Help Page");
    GETARG(searchLabel1, XtNwidth,                           slw);
    SETARG(searchText,   XtNwidth,      (helpWd > slw + 60 ?
					 helpWd - slw - 30 : 30));

    XTextExtents(helpTextFont,"[(M0|W",6, &dir, &asc, &dsc, &info);
    SETARG(searchText, XtNheight, info.ascent + info.descent + 30);

    FINARG;

    XtUnmanageChild(prevButton);
    XtUnmanageChild(nextButton);
    XtUnmanageChild(upButton);

    if (guess != NULL) XtManageChild(searchGuess);
    XtManageChild(searchGo);

    XtManageChild(searchLabel1);
    XtManageChild(searchLabel2);
    XtManageChild(searchText);
    XtSetKeyboardFocus(textForm, searchText);

    helpPaneHt = 6;

    if (srchList) {
      Try(DisplayChoices("\nPossible pages, in approximate order:\n\n",
			 srchList));
    } else {
      if (lastSearch) {
	Try(DisplayChoices("\nLast search unsuccessful.", srchList));
      } else {
	Try(DisplayChoices("\nNo previous search results.", srchList));
      }
    }

    return;
  }

 oops:
  (void)HelpError("Cannot display search page");
  return;
}


/* ARGSUSED */
int HelpContextHelpAction(w, event, b, c)
  Widget w;
  XButtonEvent *event;
  caddr_t b,c;
{
  if (!helpInstalled) Try(HelpInstallHelp());
  if (displayMode != HelpSearchDisplay)
    HelpSearchButton(searchButton, 0, 0);
  if (guessMode)
    SearchGuess(searchGuess, 0, 0);
  SearchGuess(searchGuess, 0, 0);

  return;

 oops:
  return HelpError("Couldn't get a contextual help page");
}

