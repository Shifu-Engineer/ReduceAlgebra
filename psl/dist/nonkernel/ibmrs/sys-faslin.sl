%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYSTEM-FASLIN.SL
% Title:          Fasl stuff needed at run time
%                 Based on VAX version.
% Author:         Eric Benson
% Created:        25 April 1982
% Modified:       4-Dec-84 15:05:42 (Vicki O'Day)
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983,  Hewlett-Packard Company, all rights reserved.
% Copyright (c) 1982 University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 10-Dec-90 (Winfried Neun)
% removed (strinf  for IBM RS 6000.
% 06-Apr-88 (Julian Padget)
%  Must do (wgetv symval <expr>) in CPSL.
% 4-Dec-84 15:05:34 (Vicki O'Day)
%  Added binaryopenupdate.
% 26-Sep-84 13:41:32 (Vicki O'Day)
%  Added binaryopenappend for use with Nmail.
% 27-Jul-84 (Vicki O'Day)
%  Added redefinition of binaryopenread, so if it fails it can call
%  conterror instead of kernel-fatal-error.
% 10-Jul-84 13:35:24 (RAM)
%  Replaced call to fopen with call to unixopen.  Unixopen will expand
%  shell variables (and some other fancy stuff).
% 2-Jul-84 (Vicki O'Day)
%  Removed functions in kernel.
% 27-Feb-84 17:00:24 (RAM)
%  Changed File and Title entries in header.
%  Added flagging as foreignfunction of fopen, fclose, putw,
%  fread, fwrite, fseek.
% 2-Dec-83  16:00:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                          

(compiletime (load fasl-decls sys-consts sys-macros io-decls))

(fluid '(argumentblock))

(de depositvaluecelllocation (x)
  (if (not *writingfaslfile)
    (progn (setf (getmem (iplus2 codebase* currentoffset*)) 
                 (loc (wgetv symval (idinf x))))
           (setf currentoffset* (iplus2 currentoffset* 4)))
    (progn (setf (getmem (iplus2 codebase* currentoffset*)) 
                 (makerelocword reloc-value-cell (findidnumber x)))
           (setf currentoffset* (iplus2 currentoffset* 4))
           (updatebittable 4 reloc-word))))

(de depositextrareglocation (x)
  (if (not *writingfaslfile)
    (progn (setf (getmem (iplus2 codebase* currentoffset*)) 
                 (loc (wgetv argumentblock
                       (wdifference x (wplus2 maxrealregs 1)))))
           (setf currentoffset* (iplus2 currentoffset* 4)))
    (progn (setf (getmem (iplus2 codebase* currentoffset*)) 
                 (makerelocword reloc-value-cell (wplus2 x 8150)))
           (setf currentoffset* (iplus2 currentoffset* 4))
           (updatebittable 4 reloc-word))))

(de depositfunctioncelllocation (x)
  (if (not *writingfaslfile)
    (progn (setf (getmem (iplus2 codebase* currentoffset*)) 
                 (iplus2 symfnc (itimes2 6 (idinf x))))
           (setf currentoffset* (iplus2 currentoffset* 4)))
    (progn (setf (getmem (iplus2 codebase* currentoffset*)) 
                 (makerelocword reloc-function-cell 
                  (findidnumber x)))
           (setf currentoffset* (iplus2 currentoffset* 4))
           (updatebittable 4 reloc-word))))



(declare-wstring openreadflag initially "r")
(declare-wstring openwriteflag initially "w")
(declare-wstring openappendflag initially "a")
(declare-wstring openupdateflag initially "r+")


% binaryopenread, binaryread, binaryreadblock and binaryclose
% are in the kernel, but binaryopenread needs to be redefined
% here so conterror instead of kernel-fatal-error will be called.

(de binaryopenread (filename) 
  (prog (f)
        (setq f 
              (unixopen (strbase filename) (strbase openreadflag)))
        (return (if (weq f 0)
                  (conterror 99 "Couldn't open binary file for input" 
                   (binaryopenread filename))
                  f))))

(de binaryopenwrite (filename)
  (prog (f)
        (setq f 
              (unixopen (strbase filename) (strbase openwriteflag)))
        (return (if (weq f 0)
                  (conterror 99 "Couldn't open binary file for output" 
                   (binaryopenwrite filename))
                  f))))

(de binaryopenappend (filename)
  (prog (f)
        (setq f 
              (unixopen (strbase filename) (strbase openappendflag)))
        (return (if (weq f 0)
                  (conterror 99 "Couldn't open binary file for append" 
                   (binaryopenappend filename))
                  f))))

(de binaryopenupdate (filename)
  (prog (f)
        (setq f 
              (unixopen (strbase filename) (strbase openupdateflag)))
        (return (if (weq f 0)
                  (conterror 99 "Couldn't open binary file for update" 
                   (binaryopenupdate filename))
                  f))))

(de binarywrite (channel n)
  (putw n channel))

(de binarywriteblock (channel blockbase blocksize)
  (fwrite blockbase 4 blocksize channel))

(de binarypositionfile (channel nastysystemdependentnumber)
  (fseek channel nastysystemdependentnumber 0))






