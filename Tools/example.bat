@echo off
goto check_Permissions

:check_Permissions
	echo Administrative permissions required. Detecting permissions...

	net session >nul 2>&1
	if %errorLevel% == 0 (
		echo Success: Administrative permissions confirmed.
		
		echo "Move to NSIS..."
		xcopy ..\ANSI\MySQL.dll "C:\Program Files (x86)\NSIS\Plugins\x86-ansi" /S /E /Y
		xcopy ..\Unicode\MySQL.dll "C:\Program Files (x86)\NSIS\Plugins\x86-unicode" /S /E /Y

		sleep 1
		"C:\Program Files (x86)\NSIS\Bin\makensis" ..\Example\Example.nsi
		start ..\Example\Example.exe
	) else (
		echo Failure: Current permissions inadequate. Please use CMD.exe and call the batch-file here!
		pause >nul
	)