%% Arduino Serial Example

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
u = fscanf(ardy);
fprintf(u)
% fprintf(ardy, ':PUL?');
fprintf(ardy, '*IDN?');
out = fscanf(ardy, '%s');
fprintf(out)
fclose(ardy);
delete(ardy);
clear ardy
pause(2)

%% Test Pulse Generator

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
u = fscanf(ardy);

fprintf(ardy, ':PUL:SET -5');
fprintf(ardy, ':PUL:ON');
pause(0.5)
out = fscanf(ardy, '%s');
disp(out)
pause(5)
fprintf(ardy, ':PUL:OFF');
pause(0.5)
out = fscanf(ardy, '%s');
disp(out)

fprintf(ardy, ':PUL:SET 50');
fprintf(ardy, ':PUL:ON');
pause(0.5)
out = fscanf(ardy, '%s');
disp(out)
pause(5)
fprintf(ardy, ':PUL:OFF');
pause(0.5)
out = fscanf(ardy, '%s');
disp(out)

fclose(ardy);
delete(ardy);
clear ardy

pause(2)

%% Test Ultrasonic Sensor

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
u = fscanf(ardy);


N=1000;
times = zeros(1, N);
for i = 1:N
    out = query(ardy, ':ULT?');
    out = str2num(out);
    times(i) = out;
    disp(i)
end

fclose(ardy);
delete(ardy);
clear ardy

figure()
% plot(times)

pos = times*0.034/2;
plot(pos)