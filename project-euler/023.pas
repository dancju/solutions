program p23;

  var
    ans: array[12..28123] of boolean;
    soans: array[1..28123] of boolean;
    i,j: word;
    sum: longint;


  function an(n: word): boolean;

    var
      i,sopd: word;

    begin
      sopd:=1;
      for i:=2 to n-1 do
        if n mod i = 0 then
        begin
          inc(sopd,i);
          if sopd > n then{ begin write(n,' ');    }
            exit(true);                  {   end;  }
        end;
      exit(false);
    end;

  begin
    for i:=1 to 28123 do
      soans[i]:=false;
    for i:=12 to 28123 do
      ans[i]:=an(i);
    for i:=12 to 28123 do
      for j:=12 to 28123 do
        if ans[i] and ans[j] and (i+j<=28123) then
          soans[i+j]:=true;
    sum:=0;
    for i:=1 to 28123 do
      if soans[i] = false then
        inc(sum,i);
    writeln(sum);
    readln;
  end.
4179871