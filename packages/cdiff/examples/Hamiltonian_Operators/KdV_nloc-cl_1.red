% Non-local Hamiltonian operators for KdV
% Computation of covering variables as non-local conservation laws
% Raffaele Vitolo, 30 May 2010
% In order to work with the examples, load first CDIFF with the command
% load_package cdiff;

super_vectorfield(ddx,{x,t,u,u1,u2,u3,u4,u5,u6,u7,
u8,u9,u10,u11,u12,u13,u14,u15,u16,u17},
{ext 1,ext 2,ext 3,ext 4,ext 5,ext 6,ext 7,ext 8,ext 9,ext 10,ext
11,ext 12,ext 13,ext 14,ext 15,ext 16,ext 17,ext 18,ext 19,ext 20,ext
21,ext 22,ext 23,ext 24,ext 25,ext 26,ext 27,ext 28,ext 29,ext 30,
ext 31,ext 32,ext 33,ext 34,ext 35,ext 36,ext 37,ext 38,ext 39,ext 40,
ext 41,ext 42,ext 43,ext 44,ext 45,ext 46,ext 47,ext 48,ext 49,ext 50,
ext 51,ext 52,ext 53,ext 54,ext 55,ext 56,ext 57,ext 58,ext 59,ext 60,
ext 61,ext 62,ext 63,ext 64,ext 65,ext 66,ext 67,ext 68,ext 69,ext 70,
ext 71,ext 72,ext 73,ext 74,ext 75,ext 76,ext 77,ext 78,ext 79,ext 80
});

super_vectorfield(ddt,{x,t,u,u1,u2,u3,u4,u5,u6,u7,
u8,u9,u10,u11,u12,u13,u14,u15,u16,u17},
{ext 1,ext 2,ext 3,ext 4,ext 5,ext 6,ext 7,ext 8,ext 9,ext 10,ext
11,ext 12,ext 13,ext 14,ext 15,ext 16,ext 17,ext 18,ext 19,ext 20,ext
21,ext 22,ext 23,ext 24,ext 25,ext 26,ext 27,ext 28,ext 29,ext 30,
ext 31,ext 32,ext 33,ext 34,ext 35,ext 36,ext 37,ext 38,ext 39,ext 40,
ext 41,ext 42,ext 43,ext 44,ext 45,ext 46,ext 47,ext 48,ext 49,ext 50,
ext 51,ext 52,ext 53,ext 54,ext 55,ext 56,ext 57,ext 58,ext 59,ext 60,
ext 61,ext 62,ext 63,ext 64,ext 65,ext 66,ext 67,ext 68,ext 69,ext 70,
ext 71,ext 72,ext 73,ext 74,ext 75,ext 76,ext 77,ext 78,ext 79,ext 80
});

%specification of the vectorfield ddx
%the even variables
ddx(0,1):=1$
ddx(0,2):=0$
ddx(0,3):=u1$
ddx(0,4):=u2$
ddx(0,5):=u3$
ddx(0,6):=u4$
ddx(0,7):=u5$
ddx(0,8):=u6$
ddx(0,9):=u7$
ddx(0,10):=u8$
ddx(0,11):=u9$
ddx(0,12):=u10$
ddx(0,13):=u11$
ddx(0,14):=u12$
ddx(0,15):=u13$
ddx(0,16):=u14$
ddx(0,17):=u15$
ddx(0,18):=u16$
ddx(0,19):=u17$
ddx(0,20):=letop$

%specification of the vectorfield ddt
%the even variables
ddt(0,1):=0$
ddt(0,2):=1$
ddt(0,3):=ut$
ddt(0,4):=ut1$
ddt(0,5):=ut2$
ddt(0,6):=ut3$
ddt(0,7):=ut4$
ddt(0,8):=ut5$
ddt(0,9):=ut6$
ddt(0,10):=ut7$
ddt(0,11):=ut8$
ddt(0,12):=ut9$
ddt(0,13):=ut10$
ddt(0,14):=ut11$
ddt(0,15):=ut12$
ddt(0,16):=ut13$
ddt(0,17):=ut14$
ddt(0,18):=letop$
ddt(0,19):=letop$
ddt(0,20):=letop$

% KdV equation

ut:=u*u1+u3;

ut1:=ddx ut;
ut2:=ddx ut1;
ut3:=ddx ut2;
ut4:=ddx ut3;
ut5:=ddx ut4;
ut6:=ddx ut5;
ut7:=ddx ut6;
ut8:=ddx ut7;
ut9:=ddx ut8;
ut10:=ddx ut9;
ut11:=ddx ut10;
ut12:=ddx ut11;
ut13:=ddx ut12;
ut14:=ddx ut13;

for i:=1:17 do write ev(0,i):=ddt(ddx(0,i))-ddx(ddt(0,i));

% we now introduce odd variables ext 1,....,ext 20, and associated relations

% Specification of odd variables in ddx. We look for conservation laws
% of the form
% fx= phi*ext 3
% ft= f1*ext3+f2*ext4+f3*ext5
%
% The ansatz is chosen because, first of all, ext 4 and ext 5
% can be removed from fx by adding a suitable total divergence;
% moreover it can be proved that phi is a symmetry of KdV.

ddx(1,1):=0$
ddx(1,2):=0$
ddx(1,3):=ext 4$
ddx(1,4):=ext 5$
ddx(1,5):=ext 6$
ddx(1,6):=ext 7$
ddx(1,7):=ext 8$
ddx(1,8):=ext 9$
ddx(1,9):=ext 10$
ddx(1,10):=ext 11$
ddx(1,11):=ext 12$
ddx(1,12):=ext 13$
ddx(1,13):=ext 14$
ddx(1,14):=ext 15$
ddx(1,15):=ext 16$
ddx(1,16):=ext 17$
ddx(1,17):=ext 18$
ddx(1,18):=ext 19$
ddx(1,19):=ext 20$
ddx(1,20):=letop$
ddx(1,50):=(t*u1+1)*ext 3$ % degree -2
ddx(1,51):=u1*ext 3$ % degree +1
ddx(1,52):=(u*u1+u3)*ext 3$ % degree +3

%Specification of odd variables in ddt
ddt(1,1):=0$
ddt(1,2):=0$
ddt(1,3):=ext 6 + u*ext 4$
ddt(1,4):=ddx(ddt(1,3))$
ddt(1,5):=ddx(ddt(1,4))$
ddt(1,6):=ddx(ddt(1,5))$
ddt(1,7):=ddx(ddt(1,6))$
ddt(1,8):=ddx(ddt(1,7))$
ddt(1,9):=ddx(ddt(1,8))$
ddt(1,10):=ddx(ddt(1,9))$
ddt(1,11):=ddx(ddt(1,10))$
ddt(1,12):=ddx(ddt(1,11))$
ddt(1,13):=ddx(ddt(1,12))$
ddt(1,14):=ddx(ddt(1,13))$
ddt(1,15):=ddx(ddt(1,14))$
ddt(1,16):=ddx(ddt(1,15))$
ddt(1,17):=ddx(ddt(1,16))$
ddt(1,18):=letop$
ddt(1,19):=letop$
ddt(1,20):=letop$
ddt(1,50):=f1*ext 3+f2*ext 4+f3*ext 5$
ddt(1,51):=f4*ext 3+f5*ext 4+f6*ext 5$
ddt(1,52):=f7*ext 3+f8*ext 4+f9*ext 5$

graadlijst:={{},{u},{u1},{u2},{u3},{u4},{u5},
{u6},{u7},{u8},{u9},{u10},{u11},{u12},{u13},{u14},{u15},{u16},{u17}};

grdm6:={0};
grdm5:={0};
grdm4:={0};
grdm3:={0};
grdm2:={0};
grdm1:={0};

grd0:={1};

grd1:= mkvarlist1(1,1)$
grd2:= mkvarlist1(2,2)$
grd3:= mkvarlist1(3,3)$
grd4:= mkvarlist1(4,4)$
grd5:= mkvarlist1(5,5)$
grd6:= mkvarlist1(6,6)$
grd7:= mkvarlist1(7,7)$
grd8:= mkvarlist1(8,8)$
grd9:= mkvarlist1(9,9)$
grd10:= mkvarlist1(10,10)$
grd11:= mkvarlist1(11,11)$
grd12:= mkvarlist1(12,12)$
grd13:= mkvarlist1(13,13)$
grd14:= mkvarlist1(14,14)$
grd15:= mkvarlist1(15,15)$
grd16:= mkvarlist1(16,16)$
grd17:= mkvarlist1(17,17)$
grd18:= mkvarlist1(18,18)$
grd19:= mkvarlist1(19,19)$

ctel:=0;

% Note that the equation equ 1 can be solved directly and produces
% what is below. It is more tricky to solve it automatically due
% to the presence of `t' in the generator of the symmetry f3=phi

f3:=t*u1+1$
f1:=u*f3+ddx(ddx(f3))$
f2:=-ddx(f3)$

% The following ansatz keep into account the grading of the starting
% symmetry in ddx(phi*ext 3).

f4:=
(for each el in grd5 sum (c(ctel:=ctel+1)*el))$
f5:=
(for each el in grd4 sum (c(ctel:=ctel+1)*el))$
f6:=
(for each el in grd3 sum (c(ctel:=ctel+1)*el))$

f7:=
(for each el in grd7 sum (c(ctel:=ctel+1)*el))$
f8:=
(for each el in grd6 sum (c(ctel:=ctel+1)*el))$
f9:=
(for each el in grd5 sum (c(ctel:=ctel+1)*el))$

% The first equation below is already solved `by hand'.

equ 1:=ddx(f1*ext 3+f2*ext 4+f3*ext 5)-ddt((t*u1+1)*ext 3);

equ 2:=ddx(ddt(1,51))-ddt(ddx(1,51));

equ 3:=ddx(ddt(1,52))-ddt(ddx(1,52));

pause;

vars:={x,t,u,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14,u15,u16,u17};

tel:=3;

procedure splitext i;
begin;
ll:=operator_coeff(equ i,ext);
equ(tel:=tel+1):=first ll;
ll:=rest ll;
for each el in ll do equ(tel:=tel+1):=second el;
end;

procedure splitvars i;
begin;
ll:=multi_coeff(equ i,vars);
equ(tel:=tel+1):=first ll;
ll:=rest ll;
for each el in ll do equ(tel:=tel+1):=second el;
end;

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

for i:=1:3 do splitext i;

tel1:=tel;

for i:=4:tel1 do begin splitvars i;equ i:=0;end;

pte tel;

end;

