program euler004;

type
   stack = record
         d : array[1..999] of longint;
         t : byte;
      end; 

var
   a, b, i : integer;
   m : longint;
   s : stack;
	 
procedure push(var s: stack;d: longint);
begin
   if s.t=999 then begin
      writeln('overflow!');
      exit;
   end;
   s.t := s.t+1;
   s.d[s.t] := d;
end;

begin
   s.t := 0;
   for a:=100 to 999 do
      for b:=100 to 999 do begin
         m := a*b;
         if m<=900000 then continue;
         if (m div 100000 = m mod 10) and ((m div 10000) mod 10 = (m div 10) mod 10) and ((m div 1000) mod 10 = (m div 100) mod 10) then
            push(s,m);
   end;
   m := s.d[1];
   for i:=2 to s.t do
      if m<=s.d[i] then
         m := s.d[i];
   writeln(m);
end.
