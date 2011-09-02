module torsionb;

% Author: James H. Davenport.

fluid '(!*tra !*trmin intvar nestedsqrts);

exports bound!-torsion;

symbolic procedure bound!-torsion(divisor,dof1k);
% Version 1 (see Trinity Thesis for difference).
begin
  scalar field,prime1,prime2,prime3,minimum,places;
  scalar non!-p1,non!-p2,non!-p3,curve,curve2,nestedsqrts;
  places:=for each u in divisor
            collect car u;
  curve:=getsqrtsfromplaces places;
  if nestedsqrts
    then rerror(algint,3,"Not yet implemented")
    else curve2:=curve;
  for each u in places do begin
    u:=rfirstsubs u;
    if eqcar(u,'quotient) and cadr u = 1
      then return;
    u:=substitutesq(simp u,list(intvar . 0));
    field:=union(field,sqrtsinsq(u,nil));
    u:=list(intvar . prepsq u);
    for each v in curve2 do
      field:=union(field,sqrtsinsq(substitutesq(v,u),nil));
    end;
  prime1:=2;
  while null (non!-p1:=good!-reduction(curve,dof1k,field,prime1)) do
    prime1:=nextprime prime1;
  prime2:=nextprime prime1;
  while null (non!-p2:=good!-reduction(curve,dof1k,field,prime2)) do
    prime2:=nextprime prime2;
  prime3:=nextprime prime2;
  while null (non!-p3:=good!-reduction(curve,dof1k,field,prime3)) do
    prime3:=nextprime prime3;
  minimum:=fix sqrt float(non!-p1*non!-p2*non!-p3);
  minimum:=min(minimum,non!-p1*max!-power(prime1,min(non!-p2,non!-p3)));
  minimum:=min(minimum,non!-p2*max!-power(prime2,min(non!-p1,non!-p3)));
  minimum:=min(minimum,non!-p3*max!-power(prime3,min(non!-p2,non!-p1)));
  if !*tra or !*trmin then <<
    princ "Torsion is bounded by ";
    printc minimum >>;
  return minimum
  end;


symbolic procedure max!-power(p,n);
% Greatest power of p not greater than n.
begin scalar ans;
  ans:=1;
  while ans<=n do
    ans:=ans*p;
  ans:=ans/p;
  end;


symbolic procedure good!-reduction(curve,dof1k,field,prime);
begin
  scalar u;
  u:=algebraic!-factorise(prime,field);
  interr "Good reduction not finished";
  end;

endmodule;

end;
