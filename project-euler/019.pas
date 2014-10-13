program euler019;

var
   year, day : word;
   month, monday : byte;

begin
   year := 1900;
   month := 1;
   day := 1;
   monday := 0;
   repeat
      if (day mod 7 = 0) and (year >=1901) then
         inc(monday);
      if (month=1) or (month=3) or (month=5) or (month=7) or (month=8) or (month=10) then
         inc(day,31)
      else if month = 2 then begin
         if ((year mod 4 = 0) and (year mod 100 <> 0)) or (year mod 400 = 0) then
            inc(day,29)
         else
            inc(day,28);
      end else if month = 12 then begin
         month:=0;
         inc(year);
         inc(day,31);
      end else
         inc(day,30);
      inc(month);
   until (year = 2001) and (month = 1);
   writeln(monday);
end.
