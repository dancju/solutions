{
USER: danny_c1
PROG: beads
LANG: PASCAL
}


type t=0..351;

var
   r: array[1..350] of char;
   n, max: t;
   next, pre: array[1..350] of 1..350;

procedure print(x: t);
begin
   assign(output, 'beads.out');
   rewrite(output);
   writeln(x);
   close(output);
   halt;
end;

procedure check;
var
   i: t;
   c: char;
begin
   i:=1;
   while r[i] = 'w' do
      inc(i);
   c:=r[i];
   for i:=i+1 to n do
      if (r[i] <> 'w') and (r[i] <> c) then
         exit;
   print(n);
end;

procedure init;
var
   i: t;
begin
   assign(input, 'beads.in');
   reset(input);
   readln(n);
   for i:=1 to n do
      read(r[i]);
   close(input);
   check;
   max:=0;
   next[n]:=1;
   for i:=1 to n-1 do
      next[i]:=i+1;
   pre[1]:=n;
   for i:=2 to n do
      pre[i]:=i-1;
end;

procedure cut(x: t);
var
   i, sum, temp: t;
   c: char;
begin
   sum:=0;
   i:=pre[x];
   while r[i] = 'w' do begin
      i:=pre[i];
      inc(sum);
   end;
   c:=r[i];
   while (r[i] = 'w') or (r[i] = c) do begin
      i:=pre[i];
      inc(sum);
   end;
   temp:=i;
   i:=x;
   while r[i] = 'w' do begin
      i:=next[i];
      inc(sum);
      if i = temp then
         print(n);
   end;
   c:=r[i];
   while (r[i] = 'w') or (r[i] = c) do begin
      i:=next[i];
      inc(sum);
      if i = temp then
         print(n);
   end;
   if sum > max then
      max:=sum;
end;

var
   i: t;
begin
   init;
   for i:=1 to n do cut(i);
   print(max);
end.
