program euler010;

var
   sum : int64;
   i, j : longint;
   can : boolean;

begin
   sum:=0;
   for i:=2 to 2000000 do begin
      can:=true;
      for j:=2 to trunc(sqrt(i)) do
	 if i mod j=0 then begin
            can:=false;
	    break;
	 end;
      if can then
         sum := sum+i;
   end;
   writeln(sum);
end.

