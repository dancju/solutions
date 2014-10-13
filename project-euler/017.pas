program p17;

const
   one : array[1..9] of byte =
      (3,3,5,4,4,3,5,5,4);
   ten : array[1..9] of byte =
      (3,6,6,5,5,5,7,6,6);
   tens: array[11..19] of byte =
      (6,6,8,8,7,7,9,8,8);

var
   n, sum: word;

function nod(n : word): byte;
var
   spell : byte;
begin
   if n>=100 then begin
      spell:=one[n div 100];
      inc(spell,10);
      if n mod 100 = 0 then
         spell:=spell-3;
      n:=n-(n div 100)*100;
   end else
      spell:=0;
   if (n<=19) and (n>=11) then
      exit(spell+tens[n]);
   if n div 10 <> 0 then
      inc(spell,ten[n div 10]);
   if n mod 10 <> 0 then
      inc(spell,one[n mod 10]);
   nod:=spell;
end;

begin
   sum:=11;
   for n:=1 to 999 do
      inc(sum,nod(n));
   writeln(sum);
end.
