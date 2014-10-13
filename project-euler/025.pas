program euler025;

type
   int = array[1..1000] of 0..18;

var
   a, b, c : int;
   i, n : word;

procedure plus;
var
   i : word;
begin
   for i:=1 to 1000 do
      c[i]:=a[i]+b[i];
   for i:=1 to 999 do
      if c[i] >= 10 then begin
         inc(c[i+1],c[i] div 10);
         c[i]:=c[i] mod 10;
      end;
end;

begin
   b[1]:=1;
   c[1]:=1;
   n:=2;
   repeat
      for i:=1 to 1000 do begin
         a[i]:=b[i];
         b[i]:=c[i];
      end;
      plus;
      inc(n);
   until c[1000] <> 0;
   writeln(n);
   readln;
end.
