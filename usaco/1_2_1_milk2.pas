{
ID:danny_c1
PROG:milk2
LANG:PASCAL
}

type
   t1 = 0..10000;
   t2 = record
	   time	: 0..1000000;
	   io	: boolean;
	end;	
      
var
   data	: array[t1] of t2;
   swap	: t2;
	
    procedure QSort(l, r: t1);
    var
       i, j : t1;
       m    : 0..1000000;
    begin   
       i:=l;
       j:=r;
       m:=data[(l+r) div 2].time;
       while i<=j do
       begin
	  while data[i].time < m do inc(i);
	  while m < Data[j].time do dec(j);
	  if i <= j then
	  begin
	     swap:=Data[i]; Data[i]:=Data[j]; Data[j]:=swap;
	     inc(i); dec(j);
	  end;
       end;
       if l < j then qsort(l, j);
       if i < r then qsort(i, r);
    end;

var
   n, i			  : t1;
   f			  : 0..5000;
   temp, last, max0, max1 : 0..1000000;
			  
begin
   assign(input, 'milk2.in'); reset(input);
   readln(n);
   for i:=1 to n do
    begin
       readln(data[2*i-1].time,data[2*i].time);
       data[2*i-1].io:=true;
       data[2*i].io:=false;
    end;
   close(input);
   n:=n*2;
   qsort(1,n);
   for i:=1 to n-1 do if (data[i].time = data[i+1].time) and data[i+1].io then
   begin swap:=Data[i]; Data[i]:=Data[i+1]; Data[i+1]:=swap; end;
   for i:=1 to n do writeln(data[i].io, ' ', data[i].time);
   f:=0; last:=data[1].time; max0:=0; max1:=0;
   for i:=1 to n do begin
      if data[i].io then begin
	 inc(f);
	 if f = 1 then begin
	    temp:=data[i].time-last;
	    if temp > max0 then max0:=temp;
	    last:=data[i].time;
	 end;
      end
      else begin
	 dec(f);
	 if f = 0 then begin
	    temp:=data[i].time-last;
	    if temp > max1 then max1:=temp;
	    last:=data[i].time;
	 end;
      end;
   end;
   assign(output, 'milk2.out'); rewrite(output);
   writeln(max1, ' ', max0);
   close(output);
end.