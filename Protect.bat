@echo off
echo Compiling with VMProtect
"../VMProtect/VMProtect_Con.exe" ../Release/%1.dll -pf ../EngineX.vmp
exit