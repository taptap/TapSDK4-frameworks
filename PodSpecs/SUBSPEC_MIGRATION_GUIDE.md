# TapTapSDK Subspec 使用指南

## 概述

TapTapSDK 现在支持两种接入方式，用户可以根据自己的情况选择：

1. **独立 Pod 方式**（推荐现有用户继续使用）
2. **Subspec 方式**（推荐新用户使用）

两种方式可以共存，现有项目无需立即迁移。

---

## 两种方式对比

### 方式一：独立 Pod（传统方式）

```ruby
# Podfile
pod 'TapTapCoreSDK', '~> 4.7.1'
pod 'TapTapLoginSDK', '~> 4.7.1'
pod 'TapTapAchievementSDK', '~> 4.7.1'
```

**优点：**
- 向后兼容，无需修改代码
- 每个模块版本可以独立管理

**适用场景：**
- 现有项目，已经在使用独立 Pod
- 需要保持稳定，不希望改动 Podfile

---

### 方式二：Subspec（新方式）

```ruby
# Podfile
pod 'TapTapSDK/Core', '~> 4.7.1'
pod 'TapTapSDK/Login', '~> 4.7.1'
pod 'TapTapSDK/Achievement', '~> 4.7.1'
```

**优点：**
- 统一的版本管理
- 更清晰的模块归属关系
- Podfile 更简洁

**适用场景：**
- 新项目接入
- 希望统一管理所有模块版本

---

## 可用的 Subspec 模块

| Subspec 名称 | 对应的独立 Pod | 功能说明 | 依赖关系 |
|------------|--------------|---------|---------|
| `Gid` | `TapTapGidSDK` | GID 功能 | 无 |
| `Core` | `TapTapCoreSDK` | 数据分析 | Gid |
| `Login` | `TapTapLoginSDK` | 用户登录 | Core |
| `Achievement` | `TapTapAchievementSDK` | 成就系统 | Login |
| `Moment` | `TapTapMomentSDK` | 内嵌动态 | Login |
| `Compliance` | `TapTapComplianceSDK` | 合规认证 | Login |
| `CloudSave` | `TapTapCloudSaveSDK` | 云存档 | Login |
| `Share` | `TapTapShareSDK` | 分享功能 | Core |
| `Profile` | `TapTapProfileSDK` | 用户资料 | Login, Kingfisher |
| `RelationLite` | `TapTapRelationLiteSDK` | 好友系统（轻量版） | Profile |
| `Relation` | `TapTapRelationSDK` | 好友系统（完整版） | Profile |
| `Leaderboard` | `TapTapLeaderboardSDK` | 排行榜 | Profile |

---

## 使用示例

### 示例 1：基础登录功能

**独立 Pod 方式：**
```ruby
pod 'TapTapCoreSDK', '~> 4.7.1'
pod 'TapTapLoginSDK', '~> 4.7.1'
```

**Subspec 方式：**
```ruby
pod 'TapTapSDK/Login', '~> 4.7.1'  # 自动包含 Core 和 Gid
```

---

### 示例 2：登录 + 成就 + 排行榜

**独立 Pod 方式：**
```ruby
pod 'TapTapCoreSDK', '~> 4.7.1'
pod 'TapTapLoginSDK', '~> 4.7.1'
pod 'TapTapAchievementSDK', '~> 4.7.1'
pod 'TapTapLeaderboardSDK', '~> 4.8.2-alpha.12'
pod 'TapTapProfileSDK', '~> 4.7.1'
pod 'Kingfisher', '~> 6.0'
```

**Subspec 方式：**
```ruby
pod 'TapTapSDK/Achievement', '~> 4.7.1'
pod 'TapTapSDK/Leaderboard', '~> 4.7.1'
# 自动包含 Login, Profile, Core, Gid 和 Kingfisher
```

---

### 示例 3：全功能接入

**独立 Pod 方式：**
```ruby
pod 'TapTapCoreSDK', '~> 4.7.1'
pod 'TapTapLoginSDK', '~> 4.7.1'
pod 'TapTapAchievementSDK', '~> 4.7.1'
pod 'TapTapMomentSDK', '~> 4.7.1'
pod 'TapTapComplianceSDK', '~> 4.7.1'
pod 'TapTapRelationSDK', '~> 4.7.1'
pod 'TapTapLeaderboardSDK', '~> 4.7.1'
pod 'TapTapProfileSDK', '~> 4.7.1'
pod 'Kingfisher', '~> 6.0'
```

**Subspec 方式：**
```ruby
pod 'TapTapSDK/Achievement', '~> 4.7.1'
pod 'TapTapSDK/Moment', '~> 4.7.1'
pod 'TapTapSDK/Compliance', '~> 4.7.1'
pod 'TapTapSDK/Relation', '~> 4.7.1'
pod 'TapTapSDK/Leaderboard', '~> 4.7.1'
```

---

## 迁移指南（可选）

如果你想从独立 Pod 迁移到 Subspec 方式：

### 步骤 1：备份 Podfile

```bash
cp Podfile Podfile.backup
```

### 步骤 2：修改 Podfile

**修改前：**
```ruby
pod 'TapTapCoreSDK', '~> 4.7.1'
pod 'TapTapLoginSDK', '~> 4.7.1'
pod 'TapTapAchievementSDK', '~> 4.7.1'
```

**修改后：**
```ruby
pod 'TapTapSDK/Achievement', '~> 4.7.1'
```

### 步骤 3：更新依赖

```bash
pod repo update
pod install
```

### 步骤 4：验证编译

```bash
# 清理构建产物
rm -rf Pods DerivedData
pod install

# 编译项目
xcodebuild -workspace YourProject.xcworkspace -scheme YourScheme clean build
```

### 步骤 5：测试功能

确保所有使用 TapTap SDK 的功能正常运行。

---

## 注意事项

### 1. 不要混用两种方式

**错误示例（不要这样做）：**
```ruby
pod 'TapTapLoginSDK', '~> 4.7.1'      # 独立 Pod
pod 'TapTapSDK/Achievement', '~> 4.7.1'  # Subspec
```

这会导致重复引入相同的模块，可能引发编译错误。

**正确做法：** 选择其中一种方式并保持一致。

---

### 2. 版本号注意事项

- 使用 Subspec 方式时，所有模块共享同一个版本号
- 例如：`pod 'TapTapSDK/Login', '~> 4.7.1'` 会安装 4.7.1 版本的所有依赖模块

---

### 3. 依赖自动管理

使用 Subspec 方式时，依赖会自动处理：

```ruby
# 只需声明最顶层的模块
pod 'TapTapSDK/Leaderboard', '~> 4.7.1'

# 自动包含：
# - TapTapSDK/Profile
# - TapTapSDK/Login
# - TapTapSDK/Core
# - TapTapSDK/Gid
# - Kingfisher
```

---

## 依赖关系图

```
Gid (基础)
  └─> Core (数据分析)
       ├─> Login (登录)
       │    ├─> Achievement (成就)
       │    ├─> Moment (动态)
       │    ├─> Compliance (合规)
       │    ├─> CloudSave (云存档)
       │    └─> Profile (用户资料)
       │         ├─> Relation (好友-完整版)
       │         ├─> RelationLite (好友-轻量版)
       │         └─> Leaderboard (排行榜)
       └─> Share (分享)
```

---

## FAQ

### Q1: 现有项目必须迁移到 Subspec 吗？

**A:** 不需要。独立 Pod 方式会继续维护和支持，现有项目可以继续使用。Subspec 方式主要是为了给用户提供更多选择。

---

### Q2: 两种方式在代码层面有区别吗？

**A:** 完全没有区别。两种方式只是依赖管理的不同，实际引入的 framework 和代码完全相同。

```swift
// 无论使用哪种方式，代码都是一样的
import TapTapLoginSDK

TapTapLogin.initialize()
```

---

### Q3: 如何验证使用的是哪种方式？

**A:** 查看你的 Podfile：

- 包含 `pod 'TapTapLoginSDK'` → 独立 Pod 方式
- 包含 `pod 'TapTapSDK/Login'` → Subspec 方式

---

### Q4: Subspec 方式的性能有影响吗？

**A:** 没有任何性能影响。两种方式最终引入的都是相同的二进制 framework。

---

### Q5: 可以只用 Subspec 方式引入某些模块，其他用独立 Pod 吗？

**A:** 不建议混用，这会导致重复引入相同的 framework。请选择其中一种方式并保持一致。

---

## 技术支持

如果在使用过程中遇到问题：

1. 查看 [TapTap 开发者文档](https://developer.taptap.cn)
2. 提交 Issue 到 [GitHub](https://github.com/taptap/TapSDK4-frameworks/issues)
3. 联系 TapTap 技术支持团队

---

## 更新日志

- **2025-10-17**: 新增 Subspec 支持，同时保持独立 Pod 方式
