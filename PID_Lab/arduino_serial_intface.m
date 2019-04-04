%% Arduino Serial Example

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
fscanf(ardy)

fprintf(ardy, '*IDN?');
fscanf(ardy)
pause(1)

fclose(ardy);
delete(ardy);
clear ardy
pause(2)

%% Test Pulse Generator

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
fscanf(ardy);
pause(1)

fprintf(ardy, ':PUL:SET -5');
fscanf(ardy)
pause(1)

fprintf(ardy, ':PUL:ON');
fscanf(ardy)
pause(5)

fprintf(ardy, ':PUL:OFF');
fscanf(ardy)
pause(1)

fprintf(ardy, ':PUL:SET 50');
fscanf(ardy)
pause(1)

fprintf(ardy, ':PUL:ON');
fscanf(ardy)
pause(5)

fprintf(ardy, ':PUL:OFF');
fscanf(ardy)
pause(1)

fclose(ardy);
delete(ardy);
clear ardy

pause(2)

%% Test Ultrasonic Sensor

clc; clear; close all;

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
fscanf(ardy)
pause(1)


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

%% Test Joystick

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
fscanf(ardy)
pause(1)

fprintf(ardy, ':MAN:ON');
fscanf(ardy)
pause(10)

fprintf(ardy, ':MAN?');
fscanf(ardy)
pause(3)

fprintf(ardy, ':MAN:SET 10');
fscanf(ardy)
pause(3)

fprintf(ardy, ':MAN?');
fscanf(ardy)
pause(3)

fprintf(ardy, ':MAN:OFF');
fscanf(ardy)
pause(3)

fclose(ardy);
delete(ardy);
clear ardy
pause(2)

%% PID Control

ardy = serial('COM10','BaudRate',115200);
% ardy = serial('/dev/ttyACM0','BaudRate',115200);
fopen(ardy);
fscanf(ardy)
pause(1)

query(ardy, ":CON:SET:P 2.1")
query(ardy, ":CON:SET:Z 138")

pause(2)


for i = 1:1000
    query(ardy, ":CON:ON")
end

query(ardy, ":CON:OFF")

fprintf("END OF DEMO!\n")

fclose(ardy);
delete(ardy);
clear ardy
pause(2)
