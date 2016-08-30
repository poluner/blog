@echo off
:loop
  rand.exe > rand.out
  my.exe < rand.out > my.out
  std.exe < rand.out > std.out
  fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop
