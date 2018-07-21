program effective;
var i,max,N,q,a: integer;
begin
     randomize;

     N := 1 + random(10); // случайное число от 1 до 10

     max := 0;

     q:= 1;
     for i:= 1 to N do
         begin
              a := random(11);
              write(a,' ');

              if a = max then
                 q := q+1;

              if a > max then
                 begin
                 max := a;
                 q:= 1;
                   end
           end;

     writeln();
     writeln(N);

     write(q);
     readln();

end.

