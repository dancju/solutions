program euler007;

var
   n :longint;
   i, j : integer;
   y : boolean;

begin
   n := 2;
   i := 0;
   while i<=9999 do begin
      j:=2;
      y:=true;
      while j<=sqrt(n)+1 do begin
         if n mod j = 0 then
            y := false;
         inc(j);
      end;
      if y then begin
         i := i+1;
	 write(n, ' ');
      end;
      n := n+1;
   end;
end.
