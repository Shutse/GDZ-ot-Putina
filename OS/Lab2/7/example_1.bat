@echo off

echo file with extension "%2" in directory "%1":
for %%a in ("%1\*.%2") do echo %%a

pause