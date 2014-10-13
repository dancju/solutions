program euler002;

var
   t0, t1, t2, sum : longint;

begin
   t0 := 1;
   t1 := 2;
   sum := 2;
   while t2<4e6 do begin
      t2 := t0+t1;
      if not odd(t2) then
         inc(sum+t2);
      t0 := t1;
      t1 := t2;
   end;
   writeln(sum);
end.
