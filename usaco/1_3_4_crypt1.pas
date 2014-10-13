{
USER: danny_c1
PROG: crypt1
LANG:PASCAL
}

var
   d : set of byte;
   a0, a1, a2, b0, b1 : byte;
   ans : word;

procedure init;
var
   n, temp : byte;
begin
   d := [];
   assign(input, 'crypt1.in');
   reset(input);
   readln(n);
   while n <> 0 do begin
      read(temp);
      d := d+[temp];
      dec(n);
   end;
   close(input);
end;

function check0(x: word): boolean;
begin
   if (x >= 1000) or (x <= 99) then
      exit(false);
   while x <> 0 do begin
      if not(x mod 10 in d) then
         exit(false);
      x := x div 10;
   end;
   exit(true);
end;

function check1(x: word): boolean;
begin
   if (x >= 10000) or (x <= 999) then
      exit(false);
   while x <> 0 do begin
      if not(x mod 10 in d) then
         exit(false);
      x := x div 10;
   end;
   exit(true);
end;

begin
   init;
   ans := 0;
   for a0:=1 to 9 do
      if a0 in d then
         for a1:=1 to 9 do
            if a1 in d then
               for a2:=1 to 9 do
                  if a2 in d then
                     for b0:=1 to 9 do
                        if b0 in d then
                           for b1:=1 to 9 do
                              if b1 in d then
                                 if check0(b1*(a0*100+a1*10+a2)) and check0(b0*(a0*100+a1*10+a2)) and check1(b1*(a0*100+a1*10+a2)+10*b0*(a0*100+a1*10+a2)) then
                                    inc(ans);
   assign(output, 'crypt1.out');
   rewrite(output);
   writeln(ans);
   close(output);
end.
