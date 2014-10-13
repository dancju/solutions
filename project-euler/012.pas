program p12;

var
   n, i : longint;

function divisors(n: longint): word;
var
   i : longint;
   num : word;
begin
   num := 2;
   for i := 2 to round(sqrt(n)) do
      if n mod i = 0 then
         num := num+2;
   if sqr(round(sqrt(n))) = n then
      num := num-1;
   exit(num);
end;

begin
   i := 1;
   while true do
   begin
      n := i*(i+1) div 2;
      if divisors(n)>500 then
      begin
         writeln(n);
         readln;
         halt;
      end;
      inc(i);
   end;
end.
