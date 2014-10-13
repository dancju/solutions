program euler020;

type
   inttype = record
      n: array[1..255] of word;
      t: byte;
   end;

var
   f : inttype;
   m : byte;
   sum : word;

procedure multiply;
var
   i : byte;
begin
   for i:=1 to f.t do
      f.n[i]:=f.n[i]*m;
   for i:=1 to 255-1 do begin
      f.n[i+1]:=f.n[i+1]+f.n[i] div 10;
      f.n[i]:=f.n[i] mod 10;
   end;
   i:=255;
   while f.n[i] = 0 do
      i:=i-1;
   f.t:=i;
end;

begin
   f.t:=1;
   f.n[1]:=1;
   for m:=2 to 100 do
      multiply;
   sum:=0;
   for m:=f.t downto 1 do
      inc(sum,f.n[m]);
   writeln;
   writeln(sum);
   readln;
end.
