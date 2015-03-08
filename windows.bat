:: -------------------------------------------------------------------
:: 
:: windows.bat -- Install gnuwin32 bin directory into PATH
::                whithin the cmd console of windows .
::
:: 2010.09.14 by alex.
:: -------------------------------------------------------------------
::

@echo off
setx PATH "%PATH%;%CD%\bin;%CD%\sbin"