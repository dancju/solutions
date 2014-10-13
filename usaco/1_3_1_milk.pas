{
ID: danny_c1
PROG: milk
LANG: PASCAL
}

var
  n, a, cost: longword;
  m, p: longword;
  d: array[0..1000] of longword;

begin
  fillchar(d, sizeof(d), 0);
  assign(input, 'milk.in'); reset(input);
  readln(n, m);
  while m <> 0 do begin
    readln(p, a);
    inc(d[p], a);
    dec(m);
  end;
  close(input);
  cost:=0;
  for p:=0 to 1000 do if (d[p] <> 0) then begin
    if d[p]>n then begin
      inc(cost, n*p);
      break;
    end
    else begin
      inc(cost, d[p]*p);
      dec(n, d[p]);
    end;
  end;
  assign(output, 'milk.out'); rewrite(output);
  writeln(cost);
  close(output);
end.
