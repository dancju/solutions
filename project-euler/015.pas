program p15;

  const
    n=21;

  var
    grid: array[1..n,1..n] of qword;
    i,j: byte;

  begin
    for j:=1 to n do
      grid[1,j]:=1;
    for i:=1 to n do
      grid[i,1]:=1;
    for i:=2 to n do
      for j:=2 to n do
        grid[i,j]:=grid[i-1,j]+grid[i,j-1];
    writeln(grid[n,n]);
    readln;
  end.

The result is 137846528820.