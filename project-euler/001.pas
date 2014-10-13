program euler001;

var
   i, s : longword;

begin
   s := 0;
   for i:=3 to 999 do
      if (i mod 3 = 0) or (i mod 5 = 0) then
         inc(s, i);
   writeln(s);
end.
