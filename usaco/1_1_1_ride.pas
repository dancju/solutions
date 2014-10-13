{
ID:danny_c1
PROG:ride
LANG:PASCAL
}

procedure calculate(s: string; var v: byte);
var
   i : 1..6;
   m : 1..308915776;
begin
   m:=1;
   for i:=1 to length(s) do m:=m*(ord(s[i])-64);
   v:=m mod 47;
end;

var
   a, b	  : string[6];
   va, vb : byte;
	  
begin
   assign(input,'ride.in'); reset(input);
   readln(a); readln(b);
   close(input);
   calculate(a,va); calculate(b,vb);
   assign(output,'ride.out'); rewrite(output);
   if va = vb then writeln('GO')
   else writeln('STAY');
   close(output);
end.
