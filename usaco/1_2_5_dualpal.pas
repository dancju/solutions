{
USER: danny_c1
PROG: dualpal
LANG: PASCAL
}

var
   n, counter, base: byte;
   s, b10: longword;
   num, temp: string;

function palindrome: boolean;
var
   i: byte;
begin
   for i:=1 to length(num) shr 1 do
      if num[i] <> num[length(num)+1-i] then
         exit(false);
   exit(true);
end;

begin
   assign(input, 'dualpal.in');
   reset(input);
   readln(n, s);
   close(input);
   assign(output, 'dualpal.out');
   rewrite(output);
   while n <> 0 do begin
      inc(s); counter:=0;
      str(s, num);
      if palindrome then
         inc(counter);
      for base:=9 downto 2 do begin
         b10:=s; num:='';
         while b10 <> 0 do begin
            str(b10 mod base, temp);
            num:=num + temp;
            b10:=b10 div base;
         end;
         if palindrome then
            inc(counter);
         if counter = 2 then
            break;
      end;
      if counter = 2 then begin
         writeln(s);
         dec(n);
      end;
   end;
   close(output);
end.
