%% Arduino Serial Example

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
fopen(ardy);
fprintf(ardy, ":MAN:SET:ON");
ardy.BytesAvailable
out = fscanf(ardy)
fclose(ardy);
delete(ardy);
clear ardy
