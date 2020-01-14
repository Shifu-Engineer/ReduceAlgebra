module ppsoln;  % Solve surd eqns, mainly by principle of powers method.

% Authors: Anthony C. Hearn and Stanley L. Kameny.

fluid '(!*complex !*msg !*numval !*ppsoln);

global '(bfone!*);

!*ppsoln := t;   % Keep this as internal switch.

symbolic procedure solve!-fractional!-power(u,x,var,mu);
   % Attempts solution of equation car u**cadr u=x with respect to
   % kernel var and with multiplicity mu, where cadr u is a rational
   % number.
   begin scalar v,w,z;
      v := simp!* car u;
      w := simp!* cadr u;
      z := solvesq(subs2 subtrsq(exptsq(v,numr w),exptsq(x,denr w)),
                   var,mu);
      w := subtrsq(simp('expt . u),x);
      z := check!-solns(z,numr w,var);
%     return if z eq 'unsolved then list list(list w,nil,mu) else z
      return if z eq 'unsolved then mkrootsof(w,var,mu) else z
   end;

symbolic procedure principle!-of!-powers!-soln(ex,x1,var,mu);
   % Finds solutions of ex=0 by the principle of powers method.  Return
   % 'unsolved if solutions can't be found.
   begin scalar z;
   a: if null x1 then return 'unsolved
       else if suitable!-expt car x1
	  and not((z := pr!-pow!-soln1(ex,car x1,var,mu)) eq 'unsolved)
	 then return z;
      x1 := cdr x1;
      go to a
   end;

symbolic procedure pr!-pow!-soln1(ex,y,var,mu);
   begin scalar oldkord,z;
      oldkord := updkorder y;
      z := reorder ex;
      setkorder oldkord;
      if ldeg z neq 1 then return 'unsolved;
      z := coeflis z;
      if length z neq 2 or caar z neq 0
        then errach list("solve confused",ex,z);
      z := exptsq(quotsq(negsq(cdar z ./ 1),cdadr z ./ 1),
            caddr caddr y);
      z := solvesq(subs2 addsq(simp!* cadr y,negsq z),var,mu);
      z := check!-solns(z,ex,var);
      return z
   end;

symbolic procedure check!-solns(z,ex,var);
   begin scalar x,y,fv,sx,vs;
      fv := freevarl(ex,var);
      for each z1 in z do
        fv := union(fv,union(freevarl(numr caar z1,var),
                             freevarl(denr caar z1,var)));
      fv := delete('i,fv);
     % this does only one random setting!!
      if fv then for each v in fv do
        if not flagp(v,'constant) then
           vs := (v . list('quotient,1+random 999,1000)) . vs;
      sx := if vs then numr subf(ex,vs) else ex;
      while z do
         if null cadar z then <<z := nil; x := 'unsolved>>
         else if
           <<y := numr subf(ex,list(caadar z . mk!*sq caaar z));
             null y
        % to do multiple random tests, the vs, sx setting and testing
        % would be moved here and done in a loop.
             or fv and null(y := numr subf(sx,list(caadar z .
                   mk!*sq subsq(caaar z,vs))))
             or null numvalue y>>
           then <<x := car z . x; z := cdr z>>
          else z := cdr z;
      return if null x then 'unsolved else x
   end;

symbolic procedure suitable!-expt u;
   eqcar(u,'expt) and eqcar(caddr u,'quotient) and cadr caddr u = 1
      and fixp caddr caddr u;

symbolic procedure freevarl(ex,var);
 <<for each k in allkern list(ex ./ 1) do l := union(l,varsift(k,var));
   delete(var,l)>>
   where l=if var then list var else nil;

symbolic procedure varsift(a,var);
   if atom a then
      if not(null a or numberp a or a eq var) then list a else nil
   else if get(car a,'dname) then nil
   else if car a eq '!*sq then varsift(prepsq cadr a,var)
%  else if car a memq '(arbint arbcomplex) then list a
   else if car a memq '(arbint arbcomplex)
     or (get(car a,'simpfn) eq 'simpiden and not smember(var,a))
    then list a
   else for each c in cdr a join varsift(c,var);

symbolic procedure numvalue u;
   % Find floating point value of sf u.
   begin scalar !*numval,x,c,cp,p,m;
      m := !*msg; !*msg := nil;
      !*numval := t;
      c := ('i memq freevarl(u,nil));
      if (cp := !*complex) then off complex;
      x := setdmode('rounded,t); p := precision 10;
      if x eq '!:rd!: then x := 'rounded;  % <==== to avoid error later
      if c then on complex;
      !*msg := m;
      u := numr simp prepf u;
      !*msg := nil;
      if c then off complex;
      if x then setdmode(x,t) else setdmode('rounded,nil);
      if cp then on complex; precision p;
      !*msg := m;
      return
        if eqcar(u,'!:rd!:) and (numvchk(100,z) where z=round!* u)
        or eqcar(u,'!:cr!:) and (numvchk(10,z) where z=retag crrl u)
           and (numvchk(10,z) where z=retag crim u)
            then nil else u
   end;

symbolic procedure numvchk(fact,z);
   if atom z then fact*abs z<1
   else lessp!:(timbf(bfloat fact,abs!: z),bfone!*);

endmodule;

end;