@echo off

for %%f in (data\*.rxdata) do (
    echo %%~nf
    bin\Debug\MarshalToCpp.exe data\%%~nf.rxdata output\%%~nf.txt
)