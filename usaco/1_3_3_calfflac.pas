{
USER: danny_c1
PROB: calfflac
LANG: PASCAL
}
uses math;

var
   o, d: ansistring;
   p: array[1..20000] of word;
   top, ans, left, right: word;

procedure init;
var
   temp: char;
   i: word;
begin
   o:='';
   assign(input, 'calfflac.in');
   reset(input);
   while not eof do begin
      read(temp);
      o:=o + temp;
   end;
   close(input);
   d:='';
   top:=0;
   for i:=1 to length(o) do
      if o[i] in ['a'..'z', 'A'..'Z'] then begin
         d:=d + upcase(o[i]);
         inc(top);
         p[top]:=i;
      end;
end;

procedure dp(l, r: word);
begin
   if d[l] = d[r] then begin
      if ans <= r-l+1 then begin
         ans:=r-l+1;
         left:=l;
         right:=r;
      end;
      if (l>=2) and (r<=top-1) then
         dp(l-1, r+1);
   end;
end;

var
   i: word;
begin
   init;
   ans:=1;
   left:=1;
   right:=1;
   for i:=top-1 downto 2 do
      dp(i-1, i+1);
   for i:=top-1 downto 1 do
      dp(i+1, i);
   assign(output, 'calfflac.out');
   rewrite(output);
   writeln(ans);
   for i:=p[left] to p[right] do
      write(o[i]);
   writeln;
   close(output);
end.
