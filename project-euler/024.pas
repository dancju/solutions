program p24;

  type
    digits=array[1..10] of 0..9;

  var
    d: digits;
    rank: longint;

  procedure count(d: digits; t: byte);

    var
      i: 0..9;
      j: 1..10;
      can: boolean;

    begin
      if t = 10 then
      begin
        inc(rank);
        if rank = 1000000 then
        begin
          for j:=1 to 10 do
            write(d[j]);
          readln;
          halt;
        end;
        exit;
      end;
      for i:=0 to 9 do
      begin
        can:=true;
        for j:=1 to t do
          if d[j] = i then
          begin
            can:=false;
            break;
          end;
        if can then
        begin
          d[t+1]:=i;
          count(d,t+1);
        end;
      end;
    end;

  begin
    rank:=0;
    count(d,0);
  end.
2783915460