(setf *writingasmfile t)
(reload sys-consts)
(off pcmac)
(off usermode)
(on verboseload)
(asmout "main")
(dskin "$pk/firstkernel.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/main-start.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/io.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/intern.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/faslin.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/alloc.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/support.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/sys-support.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/externals.sl")
(dskin "/mnt/home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl/dist/kernel/brock/pthread.sl")
(dskin "$pk/lastkernel.sl")
(asmend)
(exitlisp)