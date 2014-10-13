program euler027;

var
   a, b, maxa, maxb : integer;
   n, maxn : word;

function prime(n: integer): boolean;
var i : word;
begin
   if n < 0 then
      exit(false);
   for i:=2 to trunc(sqrt(n))+1 do
      if n mod i = 0 then
         exit(false);
   prime := true;
end;

function nop(a,b: integer): word;
var
   num : integer;
   n,i : word;
begin
   n:=0;
   num:=b;
   while prime(num) do begin
      inc(n);
      num:=n*n+a*n+b;
   end;
   nop := n;
end;

begin
   for a:=-999 to 999 do
      for b:=-999 to 999 do begin
         n:=nop(a,b);
         if maxn < n then begin
            maxn:=n;
            maxa:=a;
            maxb:=b;
         end;
      end;
   writeln(maxa*maxb);
   readln;
end.
