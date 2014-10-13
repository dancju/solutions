program euler009;

var
   a, b, c: integer;

begin
   for a:=1 to 998 do
      for b:=a to 999-a do begin
         c:=1000-a-b;
         if sqr(a)+sqr(b)=sqr(c) then
            writeln(a*b*c);
      end;
end.
