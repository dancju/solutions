program euler014;

var
   n, maxn : int64;
   i, maxi : integer;

procedure find(n : int64; var step : integer);
begin
   if n = 1 then
      exit;
   if n mod 2 = 0 then begin
      n:=n div 2;
      inc(step);
      find(n,step);
   end else begin
      n:=(n*3+1) div 2;
      step:=step+2;
      find(n,step);
   end;
end;

begin
   maxi:=0;
   n:=1;
   while n<=1000000 do begin
      i:=0;
      find(n,i);
      if maxi<i then begin
         maxi:=i;
         maxn:=n;
      end;
      inc(n);
   end;
   writeln(maxn);
end.

