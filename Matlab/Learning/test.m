%a test M-Script-File

% Using echo on command to show these command
echo off
erasers = 4;
pads = 6;
tape = 2;
items = erasers + pads + tape;
cost = erasers * 2 + pads * 53 + tape * 99
average = cost / items;
disp(average);