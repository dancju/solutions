{
TASK:clocks
USER:danny_c1
LANG:PASCAL
}

var
   o1, o2, o3, o4, o5, o6, o7, o8, o9, I, top : byte;
   d : array[1..9] of byte;
   ans : array[1..256] of byte;

procedure insert(x: byte);
begin
   inc(top);
   ans[top]:=x;
end;

begin
   assign(input, 'clocks.in');
   reset(input);
   for i:=1 to 9 do begin
      read(d[i]);
      d[i]:=(d[i] div 3) mod 4;
   end;
   close(input);
   for o1:=0 to 3 do for o2:=0 to 3 do for o3:=0 to 3 do for o4:=0 to 3 do for o5:=0 to 3 do for o6:=0 to 3 do for o7:=0 to 3 do for o8:=0 to 3 do for o9:=0 to 3 do begin
      if (d[1]+o1+o2+o4) mod 4 <> 0 then
         continue;
      if (d[2]+o1+o2+o3+o5) mod 4 <> 0 then
         continue;
      if (d[3]+o2+o3+o6) mod 4 <> 0 then
         continue;
      if (d[4]+o1+o4+o5+o7) mod 4 <> 0 then
         continue;
      if (d[5]+o1+o3+o5+o7+o9) mod 4 <> 0 then
         continue;
      if (d[6]+o3+o5+o6+o9) mod 4 <> 0 then
         continue;
      if (d[7]+o4+o7+o8) mod 4 <> 0 then 
         continue;
      if (d[8]+o5+o7+o8+o9) mod 4 <> 0 then
         continue;
      if (d[9]+o6+o8+o9) mod 4 <> 0 then
         continue;
      top:=0;
      for i:=1 to o1 do
         insert(1);
      for i:=1 to o2 do
         insert(2);
      for i:=1 to o3 do
         insert(3);
      for i:=1 to o4 do
         insert(4);
      for i:=1 to o5 do
         insert(5);
      for i:=1 to o6 do
         insert(6);
      for i:=1 to o7 do
         insert(7);
      for i:=1 to o8 do
         insert(8);
      for i:=1 to o9 do
         insert(9);
      assign(output, 'clocks.out');
      rewrite(output);
      for i:=1 to top-1 do
         write(ans[i], ' ');
      writeln(ans[top]);
      close(output);
      exit;
   end;
end.
