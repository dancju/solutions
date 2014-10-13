program p22;

  var
    iniput: text;
    c: char;
    names: array[1..5200] of string;
    n,i,j: word;
    t: string;
    score,sum: int64;

  begin
    assign(iniput,'names.txt');
    reset(iniput);
    n:=1;
    repeat
      repeat
        read(iniput,c);
        if c<>' ' then
          names[n]:=names[n]+c;
      until c = ' ';
      inc(n);
    until eof(iniput);
    close(iniput);
    n:=n-1;
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if names[i]>names[j] then
        begin
          t:=names[i];
          names[i]:=names[j];
          names[j]:=t;
        end;
    for i:=1 to n do
    begin
      score:=0;
      for j:=1 to length(names[i]) do
        inc(score,ord(names[i][j])-64);
      score:=score*i;
      inc(sum,score);
    end;
    writeln(sum);
    readln;
  end.

871198282.