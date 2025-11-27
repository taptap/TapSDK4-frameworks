# Fastlane Configuration

这个目录包含 TapTap iOS SDK 的 Fastlane 自动化配置。

## 什么是 Fastlane？

[Fastlane](https://fastlane.tools/) 是 iOS 和 Android 开发中最流行的自动化工具，用于处理构建、测试、发布等重复性任务。

## 开发环境

- **Xcode**: 16.4+
- **Ruby**: 3.3
- **Fastlane**: 2.228.0+
- **CocoaPods**: 最新版本

## 文件说明

- **Fastfile**: 主配置文件，定义了所有的 lanes（自动化任务）

## 可用的 Lanes

### `fastlane validate`

验证 podspec 文件格式，不发布到 CocoaPods。

```bash
fastlane validate
```

**用途：**
- 本地开发时验证 podspec 是否正确
- 提交代码前的预检查

**输出：**
- 如果验证通过，显示成功信息
- 如果验证失败，显示详细的错误信息

---

### `fastlane release_to_cocoapods`

完整的 CocoaPods 发布流程：验证并发布 podspec。

```bash
fastlane release_to_cocoapods
```

**前置要求：**
- 需要配置 `COCOAPODS_TRUNK_TOKEN` 环境变量
- podspec 版本号已更新

**流程：**
1. 使用 `pod lib lint` 验证 podspec
2. 使用 `pod trunk push` 发布到 CocoaPods

---

### `fastlane release`

完整的发布流程，包含版本验证。

```bash
fastlane release version:4.7.4
```

**参数：**
- `version`: 必需，要发布的版本号（如 4.7.4）

**流程：**
1. 验证 podspec 中的版本号与参数是否匹配
2. 验证 podspec 格式
3. 发布到 CocoaPods

**示例：**
```bash
# 发布版本 4.7.4
fastlane release version:4.7.4

# 发布版本 5.0.0
fastlane release version:5.0.0
```

## 本地使用

### 安装依赖

本项目使用 **Bundler** 管理依赖，推荐使用这种方式：

```bash
# 安装 Bundler（如果还没安装）
gem install bundler

# 在项目根目录运行，安装所有依赖
bundle install
```

这会根据 `Gemfile` 安装指定版本的 Fastlane 和 CocoaPods。

### 配置环境变量

如果需要发布到 CocoaPods，需要配置 trunk token：

```bash
# 临时配置（当前终端会话）
export COCOAPODS_TRUNK_TOKEN="your_token_here"

# 或者永久配置（添加到 ~/.zshrc 或 ~/.bash_profile）
echo 'export COCOAPODS_TRUNK_TOKEN="your_token_here"' >> ~/.zshrc
source ~/.zshrc
```

### 运行验证

```bash
# 在项目根目录运行
bundle exec fastlane validate
```

### 测试发布（需要 token）

```bash
# 确保 podspec 版本号已更新为 4.7.4
bundle exec fastlane release version:4.7.4
```

**重要提示：** 始终使用 `bundle exec` 前缀，确保使用 Gemfile 中指定的依赖版本。

## CI/CD 集成

Fastlane lanes 在 GitHub Actions 中自动运行。

### Runner 配置

- **创建 GitHub Release**: `tapsdk-linux-x64-16c` (Linux runner)
- **发布到 CocoaPods**: `macos-15-xlarge` (macOS 15 runner)

### 自动化流程

GitHub Actions 会自动：
1. 在 macOS runner 上安装指定版本的 Ruby (3.3)
2. 使用 Bundler 安装 Gemfile 中的依赖
3. 运行 Fastlane 命令发布到 CocoaPods

```yaml
# .github/workflows/release.yml
jobs:
  publish-cocoapods:
    runs-on: macos-15-xlarge  # 自定义 macOS runner
    steps:
      - name: Set up Ruby and install dependencies
        uses: ruby/setup-ruby@v1
        with:
          ruby-version: '3.3'
          bundler-cache: true  # 自动运行 bundle install

      - name: Release to CocoaPods using Fastlane
        env:
          COCOAPODS_TRUNK_TOKEN: ${{ secrets.COCOAPODS_TRUNK_TOKEN }}
        run: |
          bundle exec fastlane release version:${{ steps.get_version.outputs.version }}
```

## 自定义配置

如需修改发布流程，编辑 `Fastfile`：

```ruby
# 示例：添加新的 lane
lane :custom_action do
  # 你的自定义逻辑
  UI.message("Running custom action...")
end
```

## 常见问题

### Q: 如何获取 CocoaPods Trunk Token？

```bash
# 查看 ~/.netrc 文件
cat ~/.netrc | grep -A 2 'trunk.cocoapods.org'

# 或使用 grep 提取 password
grep -A 2 'trunk.cocoapods.org' ~/.netrc | grep password | awk '{print $2}'
```

### Q: Fastlane 命令找不到？

确保 Ruby gems bin 目录在 PATH 中：

```bash
# 检查 Fastlane 安装
gem list fastlane

# 查看 gem bin 路径
gem environment | grep "EXECUTABLE DIRECTORY"

# 添加到 PATH（如果需要）
export PATH="$PATH:/usr/local/lib/ruby/gems/3.0.0/bin"
```

### Q: 验证失败怎么办？

查看详细错误信息：

```bash
# Fastlane 默认会显示详细日志
fastlane validate

# 或直接使用 CocoaPods 命令查看更多细节
pod spec lint PodSpecs/TapTapSDK.podspec --allow-warnings --verbose
```

## 相关文档

- [Fastlane 官方文档](https://docs.fastlane.tools/)
- [CocoaPods Guides](https://guides.cocoapods.org/)
- [完整发布指南](../.github/RELEASE_GUIDE.md)
