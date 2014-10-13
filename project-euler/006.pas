program euler006;

var
   i, j : integer;
   s : longint;

begin
   s := 0;
   for i:=1 to 100 do
      for j:=1 to 100 do begin
	 if i= j then
	    continue;
	 s := s+i*j;
      end;
   writeln(s);
   readln;
end.
