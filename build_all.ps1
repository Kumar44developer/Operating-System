$files = Get-ChildItem -Filter "*.c"
Write-Host "Compiling $($files.Count) Operating System C programs..." -ForegroundColor Cyan

$success = 0
$failed = 0

if (!(Test-Path "bin")) {
    New-Item -ItemType Directory -Path "bin" | Out-Null
}

foreach ($file in $files) {
    $out = Join-Path "bin" ($file.BaseName + ".exe")
    & gcc -I. -o $out $file.FullName 2>&1 | Out-Null
    if ($LASTEXITCODE -eq 0) {
        Write-Host "  [OK] $($file.Name) -> $out" -ForegroundColor Green
        $success++
    } else {
        Write-Host "  [FAIL] $($file.Name)" -ForegroundColor Red
        $failed++
    }
}

Write-Host "`nCompilation Summary: $success succeeded, $failed failed." -ForegroundColor Yellow
