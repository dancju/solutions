{
ID: danny_c1
PROG: namenum
LANG: PASCAL
}
program namenum;

  const key: array['2'..'9'] of set of 'A'..'Y'=(['A','B','C'],['D','E','F'],['G','H','I'],['J','K','L'],['M','N','O'],['P','R','S'],['T','U','V'],['W','X','Y']);

  var
    code, data: string;
    len, i: byte;
    found, b: boolean;

  begin
  assign(input, 'namenum.in'); reset(input); readln(code); close(input);
  len:=length(code);
  assign(input, 'dict.txt'); reset(input);
  assign(output, 'namenum.out'); rewrite(output);
  found:=false;
  while not eof(input) do
    begin
    readln(data);
    if length(data) <> len then continue;
    b:=true;
    for i:=1 to len do if (data[i] in ['Q','Z']) or (not (data[i] in key[code[i]])) then
      begin
      b:=false;
      break;
      end;
    if b then
      begin
      found:=true;
      writeln(data);
      end;
    end;
  close(input);
  if not found then writeln('NONE');
  close(output);
  end.