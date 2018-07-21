program noteffective;
var a: array [1..1000]  of integer;
  i,max,N,q: integer;
begin
     randomize;
     N := 1 + random(10); // случайное число от 1 до 10

     for i:= 1 to N do
         a[i]:= random(11);

     for i:= 1 to N do
         write(a[i],' ');

     writeln();
     writeln(N);

     max := a[1];

     for i:= 2 to N do
         if a[i] > max then
            max := a[i];
      q := 0;
     for i:= 1 to N do
         if a[i] = max then
            q:=q+1;

     write(q);
     readln();

end.

