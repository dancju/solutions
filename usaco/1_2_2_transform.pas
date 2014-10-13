{
ID:danny_c1
PROG:transform
LANG:PASCAL
}
program usaco_transform;

type t = array[1..10,1..10] of boolean;
       
var
   origin, aim : t;
   n	       : 1..10;
   i, j	       : 1..10;
	       
procedure scan(var x : t);
var c : char;
begin 
   for i:=1 to n do begin
      for j:=1 to n do begin
	 read(c);
	 case c of
	   '@' : x[i,j]:=true;
	   '-' : x[i,j]:=false;
	 end;	 
      end;
      readln;
   end;
end;

function equal(x: t): boolean;
begin
   for i:=1 to n do for j:=1 to n do if x[i,j] <> aim[i,j] then exit(false);
   exit(true);
end;

function A1(x: t): boolean;
var temp : t;
begin	 
   for i:=1 to n do for j:=1 to n do temp[i,j]:=x[n+1-j,i];
   if equal(temp) then exit(true)
   else exit(false);
end;

function A2(x: t): boolean;
var temp : t;
begin	 
   for i:=1 to n do for j:=1 to n do temp[i,j]:=x[n+1-i,n+1-j];
   if equal(temp) then exit(true)
   else exit(false);
end;

function A3(x: t): boolean;
var temp : t;
begin	 
   for i:=1 to n do for j:=1 to n do temp[i,j]:=x[j,n+1-i];
   if equal(temp) then exit(true)
   else exit(false);
end;

procedure print(d: byte);
begin
   assign(output, 'transform.out'); rewrite(output);
   writeln(d);
   close(output);
   halt;
end;

var temp : t;
begin	 
   assign(input, 'transform.in'); reset(input);
   readln(n);
   scan(origin); scan(aim);
   close(input);
   if A1(origin) then print(1);
   if A2(origin) then print(2);
   if A3(origin) then print(3);
   for i:=1 to n do for j:=1 to n do temp[i,j]:=origin[i,n+1-j];
   if equal(temp) then print(4);
   if A1(temp) or A2(temp) or A3(temp) then print(5);
   if equal(origin) then print(6);
   print(7);
end.
