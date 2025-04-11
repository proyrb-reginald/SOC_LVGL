# SOC_LVGL

## 项目介绍

将 `LVGL` `v8.2.0` 裁剪移植到 `SOC` 系统板上。

### 项目结构

```plaintext
根目录/
  ├── Drivers/              # 底层驱动
  ├── GUI/                  # 图形用户界面
  ├── Headers/              # 头文件
  ├── Middlewares/          # 中间件
  ├── Scripts/              # 各平台格式化脚本
  ├── Startup/              # 启动文件
  ├── System/               # 用户级代码
  ├── .clang-format         # 格式化配置信息
  ├── .clang-format-ignore  # 格式化配置信息
  ├── .gitignore            # 格式化配置信息
  ├── LICENSE               # MIT开源协议
  ├── README.md             # 项目介绍
  ├── SOC_LVGL.uvoptx       # Keil uVision5 配置项
  ├── SOC_LVGL.uvprojx      # Keil uVision5 项目文件
  └── Templst.soclst        # SOC 烧录配置项
```

## 格式化项目代码

### 使用方法

1. **运行脚本**：

   ```powershell
   cd <项目根目录>
   Set-ExecutionPolicy Bypass -Scope Process -Force  # 临时允许脚本执行
   .\Scripts\format-code.ps1
   ```

2. **文件说明**：`.clang-format-ignore` 记录的内容会被格式化脚本 `format-code.ps1` 忽略。
