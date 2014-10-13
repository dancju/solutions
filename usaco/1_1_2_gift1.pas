{
USER: danny_c1
PROG: gift1
LANG: PASCAL
}

type
   t_n = 0..10;
   t_name = string[14];
   
var
   n    : t_n;
   data : array[t_n] of record
             name  : t_name;
             money : -20000..20000;
          end; 

function get_name: t_n;
var
   i	: t_n;
   temp	: string[14];
begin	
   readln(temp);
   for i:=1 to n do
      if temp = data[i].name then
         exit(i);
end;

procedure main;
var
   i, j, giver, receiver, num : t_n;
   money		      : 0..20000;
begin			      
   assign(input, 'gift1.in');
   reset(input);
   readln(n);
   for i:=1 to n do
      readln(data[i].name);
   for i:=1 to n do begin
      giver:=get_name;
      readln(money,num);
      if num <> 0 then
         dec(data[giver].money, (money div num)*num);
      for j:=1 to num do begin
         receiver:=get_name;
         inc(data[receiver].money, money div num);
      end;
   end;
   close(input);
end;

var
   i, j : t_n;
   
begin
   for i:=1 to n do
      data[i].money:=0;
   main;
   assign(output,'gift1.out');
   rewrite(output);
   for i:=1 to n do
      writeln(data[i].name, ' ', data[i].money);
   close(output);
end.
