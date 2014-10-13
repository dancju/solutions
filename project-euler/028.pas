program euler028;

const
   nn = 500;

var
   form : array[-nn-1..nn+1,-nn-1..nn+1] of longword;
   up, down, left, right, i, j : integer;
   n, sum : longword;
			  
begin
   n:=2;
   up:=0;
   down:=0;
   left:=0;
   right:=0;
   i:=0;
   form[0,0]:=1;
   repeat
      inc(right);
      for j:=left+1 to right do begin
	 form[i,j]:=n;
	 inc(n);
      end;
      inc(down);
      for i:=up+1 to down do begin
	 form[i,j]:=n;
	 inc(n);
      end;
      dec(left);
      for j:=right-1 downto left do begin
	 form[i,j]:=n;
	 inc(n);
      end;
      dec(up);
      for i:=down-1 downto up do begin
	 form[i,j]:=n;
	 inc(n);
      end;
   until n>=sqr(nn*2+1);
   for i:=-nn to nn do
      for j:=-nn to nn do
         if (i = j) or (i = -j) then
            inc(sum,form[i,j]);
   writeln(sum);
   readln;
end.
