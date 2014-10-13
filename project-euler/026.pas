program euler026;

const
   max = 1000;

var
   r, n, maxrc, maxn : integer;

function rc(n : integer): integer;
var
   d : record
      n : array[1..max] of integer;
      t : integer;
   end;
   i, a : integer;
begin
   d.t:=0;
   for i:=1 to max do
      d.n[i]:=0;
   a:=1;
   repeat
      while a < n do
         a:=a*10;
      a:=a mod n;
      inc(d.t);
      d.n[d.t]:=a;
      if a = 0 then begin
         rc:=0;
         exit;
      end;
      for i:=1 to d.t-1 do
         if d.n[i] = d.n[d.t] then begin
            rc:=d.t-i;
            exit;
         end;
   until false;
end;

begin
   maxrc:=0;
   for n:=2 to 1000 do begin
      r:=rc(n);
      if r>maxrc then begin
         maxrc:=r;
         maxn:=n;
      end;
   end;
   writeln(maxn);
   readln;
end.
