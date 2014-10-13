program euler021;

var
   s, a, n : word;

function amicable(n: word): word;
var
   s, i : word;
begin
   s:=1;
   for i:=2 to n-1 do
      if n mod i = 0 then
         inc(s,i);
   exit(s);
end;

begin
   s:=0;
   for n:=1 to 10000 do begin
      a:=amicable(n);
      if (a<>n) and (a<=10000) and (amicable(amicable(n))=n) then
         inc(s,n);
   end;
   writeln(s);
   readln;
end.
