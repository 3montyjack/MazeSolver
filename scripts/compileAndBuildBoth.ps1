.\compileJava.ps1
.\compile.ps1
Write-Output "Running Java Project: "
.\runJava.ps1
Write-Output "Running C++ Project: "
Set-Location ..
.\MazeSolver.exe
Set-Location .\scripts
