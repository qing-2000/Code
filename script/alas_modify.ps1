<#
.SYNOPSIS
    Safe comment specific code blocks in Python files

.DESCRIPTION
    This script precisely matches and comments specific code block combinations
    File: alas_modify.ps1
#>

param(
    [string]$filePath = "F:\alas\AzurLaneAutoScript\module\os\operation_siren.py"
)

# Display script name
Write-Host "Executing script: alas_modify.ps1" -ForegroundColor Magenta
Write-Host "==================================================" -ForegroundColor Magenta

# Check if file exists
if (-not (Test-Path $filePath)) {
    Write-Error "File does not exist: $filePath"
    exit 1
}
try {
    # Read file content
    Write-Host "Reading file: $filePath" -ForegroundColor Green
    $content = Get-Content -Path $filePath -Raw
    
    # Backup original file
    $backupPath = $filePath + ".bak"
    Copy-Item -Path $filePath -Destination $backupPath -Force
    Write-Host "Backup created: $backupPath" -ForegroundColor Yellow
    
    # Save original content for comparison
    $originalContent = $content
    $modificationCount = 0
    
    Write-Host "Starting to match and comment specific code blocks..." -ForegroundColor Cyan
    
    # Pattern 1: Task enable check block (2 lines)
    $pattern1 = [regex]::new(@"
(?m)^(\s*)if not self\.config\.is_task_enabled\('OpsiMeowfficerFarming'\):\s*\r?\n^\s*self\.config\.cross_set\(keys='OpsiMeowfficerFarming\.Scheduler\.Enable', value=True\)
"@)
    
    if ($pattern1.IsMatch($content)) {
        Write-Host "Found pattern 1: Task enable check block" -ForegroundColor Green
        $content = $pattern1.Replace($content, {
            param($match)
            $indent = $match.Groups[1].Value
            "# ${indent}if not self.config.is_task_enabled('OpsiMeowfficerFarming'):`r`n# ${indent}    self.config.cross_set(keys='OpsiMeowfficerFarming.Scheduler.Enable', value=True)"
        })
        $modificationCount++
    }
    
    # Pattern 2: Exploration status check block (2 lines)  
    $pattern2 = [regex]::new(@"
(?m)^(\s*)if not self\.is_in_opsi_explore\(\):\s*\r?\n^\s*self\.config\.task_call\('OpsiMeowfficerFarming'\)
"@)
    
    if ($pattern2.IsMatch($content)) {
        Write-Host "Found pattern 2: Exploration status check block" -ForegroundColor Green
        $content = $pattern2.Replace($content, {
            param($match)
            $indent = $match.Groups[1].Value
            "# ${indent}if not self.is_in_opsi_explore():`r`n# ${indent}    self.config.task_call('OpsiMeowfficerFarming')"
        })
        $modificationCount++
    }
    
    # Pattern 3: Action point check complex block (6 lines)
    $pattern3 = [regex]::new(@"
(?m)^(\s*)if self\._action_point_total >= 3000:\s*\r?\n^\s*with self\.config\.multi_set\(\):\s*\r?\n^\s*self\.config\.task_delay\(server_update=True\)\s*\r?\n^\s*if not self\.is_in_opsi_explore\(\):\s*\r?\n^\s*self\.config\.task_call\('OpsiMeowfficerFarming'\)\s*\r?\n^\s*self\.config\.task_stop\(\)
"@)
    
    if ($pattern3.IsMatch($content)) {
        Write-Host "Found pattern 3: Action point check complex block" -ForegroundColor Green
        $content = $pattern3.Replace($content, {
            param($match)
            $indent = $match.Groups[1].Value
            @"
# ${indent}if self._action_point_total >= 3000:
# ${indent}    with self.config.multi_set():
# ${indent}        self.config.task_delay(server_update=True)
# ${indent}        if not self.is_in_opsi_explore():
# ${indent}            self.config.task_call('OpsiMeowfficerFarming')
# ${indent}    self.config.task_stop()
"@
        })
        $modificationCount++
    }
    
    # Check if any modifications were made
    if ($modificationCount -eq 0) {
        Write-Host "No specific code blocks found to comment" -ForegroundColor Yellow
        # Delete backup file (no modifications made)
        Remove-Item $backupPath -Force
        Write-Host "Backup file deleted" -ForegroundColor Yellow
        exit 0
    }
    
    # Write modified content back to original file
    Write-Host "Saving modified file..." -ForegroundColor Green
    $content | Set-Content -Path $filePath -Encoding UTF8
    
    Write-Host "Operation completed! Successfully commented $modificationCount specific code blocks" -ForegroundColor Green
    Write-Host "Original file backed up as: $backupPath" -ForegroundColor Yellow
    
    # Display modification statistics
    Write-Host "`nModification statistics:" -ForegroundColor Magenta
    Write-Host "- Pattern 1: Task enable check block" -ForegroundColor White
    Write-Host "- Pattern 2: Exploration status check block" -ForegroundColor White  
    Write-Host "- Pattern 3: Action point check complex block" -ForegroundColor White
    
} catch {
    Write-Error "Error processing file: $($_.Exception.Message)"
    if (Test-Path $backupPath) {
        Write-Host "Restoring backup file..." -ForegroundColor Red
        Copy-Item -Path $backupPath -Destination $filePath -Force
        Remove-Item $backupPath -Force
    }
    exit 1
}

# Optional: Simple comparison before and after
try {
    $originalLines = ($originalContent -split "`r`n|`n|`r").Count
    $newLines = ($content -split "`r`n|`n|`r").Count
    Write-Host "`nFile line statistics:" -ForegroundColor Cyan
    Write-Host "Before: $originalLines lines" -ForegroundColor Gray
    Write-Host "After: $newLines lines" -ForegroundColor Gray
    Write-Host "Commented $(($newLines - $originalLines)) lines of code" -ForegroundColor Gray
} catch {
    Write-Host "Unable to generate statistics" -ForegroundColor Yellow
}