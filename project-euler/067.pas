program euler067;

var
   t : array[1..100,1..100] of word;
   i, j	: byte;
	
begin
   assign(input, 'triangle.txt');
   reset(input);
   for i:=1 to 100 do begin
      for j:=1 to i do
         read(t[i,j]);
      readln();
   end;
   close(input);
   for i:=100 downto 2 do
      for j:=1 to i-1 do 
         if t[i,j]>=t[i,j+1] then
            inc(t[i-1,j],t[i,j])
         else
            inc(t[i-1,j],t[i,j+1]);
   writeln(t[1,1]);
end.
