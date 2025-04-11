<#
.SYNOPSIS
使用 clang-format 格式化代码，从项目根目录递归处理，排除指定目录。

.DESCRIPTION
读取项目根目录下的 .clang-format-ignore 文件，递归格式化所有 C/C++ 文件，但跳过忽略目录中的文件。
#>

# 项目根目录（脚本所在目录的上一级）
$projectRoot = (Get-Item $PSScriptRoot).Parent.FullName

# C/C++ 文件扩展名列表
$cppExtensions = @('.c', '.h', '.cpp', '.hpp', '.cc', '.cxx', '.hxx', '.hh', '.ipp', '.tpp')

# 读取忽略文件（位于项目根目录）
$excludeFile = Join-Path $projectRoot '.clang-format-ignore'
$excludePaths = @()

if (Test-Path $excludeFile -PathType Leaf) {
    $excludePaths = Get-Content $excludeFile | 
        Where-Object { $_ -notmatch '^\s*#' -and $_ -notmatch '^\s*$' } | 
        ForEach-Object { 
            $path = Join-Path $projectRoot $_
            try {
                $resolvedPath = (Resolve-Path $path -ErrorAction Stop).Path
                # 确保路径以目录分隔符结尾，避免部分匹配（如 `build` 和 `build2`）
                if ($resolvedPath[-1] -ne [IO.Path]::DirectorySeparatorChar) {
                    $resolvedPath += [IO.Path]::DirectorySeparatorChar
                }
                $resolvedPath
            } catch {
                Write-Warning "忽略路径 '$path' 不存在，已跳过。"
                $null
            }
        } | Where-Object { $_ -ne $null }
} else {
    Write-Warning ".clang-format-ignore 文件未找到，所有目录将被处理。"
}

# 收集待处理的文件（从项目根目录递归）
$files = Get-ChildItem -Path $projectRoot -Recurse -File | 
    Where-Object { $cppExtensions -contains $_.Extension.ToLower() } | 
    Where-Object {
        $filePath = $_.FullName
        $exclude = $false
        foreach ($dir in $excludePaths) {
            # 检查文件路径是否以忽略路径开头（不区分大小写）
            if ($filePath.StartsWith($dir, [System.StringComparison]::OrdinalIgnoreCase)) {
                $exclude = $true
                break
            }
        }
        -not $exclude
    }

# 执行格式化
foreach ($file in $files) {
    Write-Host "格式化: $($file.FullName)"
    & clang-format -i $file.FullName
    if ($LASTEXITCODE -ne 0) {
        Write-Error "格式化失败: $($file.FullName)"
    }
}

Write-Host "格式化完成。"