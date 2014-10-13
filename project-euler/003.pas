program euler003;

var
   n, i : qword;

begin
   n := 600851475143;
   i := 2;
   while i<=600851475143 do begin
      if n mod i = 0 then begin
	 writeln(i);
	 n := n div i;
      end;
      if n mod i <> 0 then
         i:=i+1;
   end;
end.
