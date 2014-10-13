{
USER: danny_c1
PROG: packrec
LANG: PASCAL
}
uses math;

var
  a: array[1..4, 0..1] of byte;
  mins, top: word;
  ans: array[1..1920] of record
    x, y: byte;
    end;
  b1, b2, b3, b4, x, y: byte;

  procedure init;
  var i: byte;
  begin
    assign(input, 'packrec.in'); reset(input);
    for i:=1 to 4 do readln(a[i][0], a[i][1]);
  end;

  procedure swap(var a, b: byte);
  var t: byte;
  begin
    t:=a; a:=b; b:=t;
  end;

  procedure check;
  var i: word;
  begin
    if x>y then swap(x, y);
    if mins > x*y then begin
      mins:=x*y; top:=1;
      ans[1].x:=x; ans[1].y:=y;
    end
    else if mins = x*y then begin
      for i:=1 to top do if ans[i].x=x then exit;
      inc(top);
      ans[top].x:=x; ans[top].y:=y;
    end;
  end;

  procedure main;
  begin
    x:=a[b1][0]+a[b2][0]+a[b3][0]+a[b4][0]; y:=max(a[b1][1], max(a[b2][1], max(a[b3][1], a[b4][1])));
    check;
    x:=max(a[b1][0], a[b2][0]+a[b3][0]+a[b4][0]); y:=a[b1][1]+max(a[b2][1], max(a[b3][1], a[b4][1]));
    check;
    x:=a[b1][0]+max(a[b2][0], a[b3][0]+a[b4][0]); y:=max(a[b1][1], a[b2][1]+max(a[b3][1], a[b4][1]));
    check;
    x:=a[b1][0]+a[b2][0]+max(a[b3][0], a[b4][0]); y:=max(a[b1][1], max(a[b2][1], a[b3][1]+a[b4][1]));
    check;
    x:=a[b1][0]+a[b2][0]; 
    if a[b1][1]+a[b3][1]>=a[b2][1]+a[b4][1] then y:=a[b1][1]+a[b3][1]
    else  y:=a[b2][1]+a[b4][1];
    if a[b1][1]<a[b2][1] then x:=max(x, a[b3][0]+a[b2][0]);
    if a[b1][1]+a[b3][1]>a[b2][1] then x:=max(x, a[b3][0]+a[b4][0]);
    if a[b2][1]<a[b1][1] then x:=max(x, a[b1][0]+a[b4][0]);
    x:=max(x, a[b3][0]);
    x:=max(x, a[b4][0]);
    check;
  end;

  procedure print;
  var i, j: word;
  begin
    for i:=1 to top-1 do for j:=i+1 to top do if ans[i].x>ans[j].x then begin
      swap(ans[i].x, ans[j].x); swap(ans[i].y, ans[j].y);
    end;
    assign(output, 'packrec.out'); rewrite(output);
    writeln(mins);
    for i:=1 to top do begin
      writeln(ans[i].x, ' ', ans[i].y);
    end;
  end;

var c1, c2, c3, c4: byte;
begin
  init;
  mins:=65535; top:=0;
  for b1:=1 to 4 do for b2:=1 to 4 do if b1<>b2 then for b3:=1 to 4 do if (b3<>b1) and (b3<>b2) then begin
    b4:=10-b1-b2-b3;
    for c1:=0 to 1 do begin
      swap(a[1][0], a[1][1]);
      for c2:=0 to 1 do begin
        swap(a[2][0], a[2][1]);
        for c3:=0 to 1 do begin
          swap(a[3][0], a[3][1]);
          for c4:=0 to 1 do begin
            swap(a[4][0], a[4][1]);
            main;
          end;
        end;
      end;
    end;
  end;
  print;
end.
