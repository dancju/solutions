{
USER: danny_c1
PROG: barn1
LANG: PASCAL
}
var
   m, n, ans: byte;
   blank: array[1..100] of byte;

procedure init;
var
   s, i, j: byte;
   temp: array[1..200] of boolean;
begin
   assign(input, 'barn1.in');
   reset(input);
   readln(m, s, i);
   fillchar(temp, sizeof(temp), false);
   while i <> 0 do begin
      readln(j);
      temp[j]:=true;
      dec(i);
   end;
   close(input);
   while not temp[s] do
      dec(s);
   i:=1;
   while not temp[i] do
      inc(i);
   ans:=s-i+1;
   n:=0;
   while true do begin
      while temp[i] and (i<=s) do
         inc(i);
      if i = s+1 then
         break;
      j:=i;
      while not temp[j] do
         inc(j);
      inc(n);
      blank[n]:=j-i;
      i:=j;
   end;
end;

procedure sort;
var
   i, j, swap: byte;
begin
   for i:=1 to n-1 do
      for j:=i+1 to n do
         if blank[i]<blank[j] then begin
            swap:=blank[i]; blank[i]:=blank[j]; blank[j]:=swap;
         end;
end;

procedure main;
var
   i: byte;
begin
   for i:=1 to m-1 do
      dec(ans, blank[i]);
end;

begin
   init;
   sort;
   main;
   assign(output, 'barn1.out');
   rewrite(output);
   writeln(ans);
   close(output);
end.
