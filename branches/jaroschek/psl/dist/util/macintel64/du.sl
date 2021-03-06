%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   DU.SL
%
%   PSL based UNIX style disk-used for MS-DOS
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load chars))
(fluid '(du-liste))

(de du(file)
   (let (du-liste)
	 (du1 ".")
	 (when (not (stringp file))(setq file nil))
	 (off gc)
     (when file (wrs (setq file(open file 'output))))
	 (setq du-liste (reverse du-liste))
	 (while du-liste
	      (prin2 (caar du-liste))
		  (tab 10)
		  (prin2t (cdar du-liste))
		  (pop du-liste))
     (when file (wrs nil) (close file))))

(de du1(base)
 % base is the name collected so far
   (let ((n 0)
         (m 0)
		 name name1 fs type
		(dir (directory "*.*")))
   (while dir
      (setq name (pop dir))
	  (when (not (eq (car (explode2 name)) '!.))
	        (setq fs (errorset (list 'filestatus name) nil nil))
			(setq fs (if (pairp fs)(car fs) nil))
            (setq type (when fs (cddr (assoc 'MODE fs))))
			(if (eq type 16)  % dir
			  (progn
			     (setq name1 (bldmsg "%w\%w" base name))
				 (printf "cd %w\%w%n" base name)
				 (cd name)
				 (setq m (du1 name1))
				 (cd "..")
			  )
			  (setq m (when fs (cddr (assoc 'SIZE fs))))
			)
			(when (numberp m)(setq n(plus n m)))
	))
	(push (cons n base) du-liste)
	n ))
 