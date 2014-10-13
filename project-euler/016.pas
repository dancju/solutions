program p16;

  type
    inttype=record
              n: array[1..400] of byte;
              p: word;
            end;

  var
    a: inttype;
    i,sum: integer;

  procedure multiply(var a: inttype;b: byte);

    var
      i: word;

    begin
      for i:=1 to a.p do
          a.n[i]:=a.n[i]*b;
      for i:=2 to a.p+1 do
      begin
        a.n[i]:=a.n[i]+a.n[i-1] div 10;
        a.n[i-1]:=a.n[i-1] mod 10;
      end;
      for i:=1 to 400 do
        if a.n[i] <> 0 then
          a.p:=i;
    end;

  begin
    a.n[1]:=1;
    a.p:=1;
    for i:=1 to 1000 do
      multiply(a,2);
    sum:=0;
    for i:=a.p downto 1 do
      sum:=sum+a.n[i];
    write(sum);
    readln;
  end.

The result is 1366;