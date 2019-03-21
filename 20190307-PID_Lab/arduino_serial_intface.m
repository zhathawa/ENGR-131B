%% Arduino Serial Example

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
fopen(ardy);
u = fscanf(ardy);
fprintf(ardy, ':PUL?\n');
out = fscanf(ardy, '%s');
fclose(ardy);
delete(ardy);
clear ardy
