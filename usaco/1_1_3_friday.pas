{
USER: danny_c1
PROG: friday
LANG: PASCAL
}
program friday;

type
   t_year = 1900..9999;
   t_month = 1..12;
   t_day = 1..31;

function dom(year: t_year; month: t_month): t_day;
begin
   case month of
   1, 3, 5, 7, 8, 10, 12:
      exit(31);
   4, 6, 9, 11:
      exit(30);
   2: begin
      if (year mod 400 = 0) or ((year mod 4 = 0) and (year mod 100 <> 0)) then
         exit(29)
      else
         exit(28);
      end;
   end;
end;

var
   year: t_year;
   month: 0..13;
   day: 0..6;
   days: array[0..6] of 0..8099*12;
   i: 0..6;
   n: 0..9999;
   
begin
   year:=1900;
   month:=1;
   day:=0;
   for i:=0 to 6 do
      days[i]:=0;
   assign(input, 'friday.in');
   reset(input);
   readln(n);
   close(input);
   repeat
      inc(days[day]);
      day:=(day+dom(year,month)) mod 7;
      inc(month);
      if month = 13 then begin
         inc(year);
         month:=1;
         dec(n);
      end;
   until n = 0;
   assign(output, 'friday.out');
   rewrite(output);
   for i:=0 to 5 do
      write(days[i],' ');
   writeln(days[6]);
   close(output);
end.
